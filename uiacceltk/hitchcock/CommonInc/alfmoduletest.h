#include "e32base.h"
#include "e32debug.h"

#ifndef ALFMODULETEST_H
#define ALFMODULETEST_H

// Define this to build module testing enchanced version of ALF
// #define USE_MODULE_TEST_HOOKS_FOR_ALF 

#if !defined(USE_MODULE_TEST_HOOKS_FOR_ALF) || !defined(AMT_CONTROL)

#define AMT_FUNC(func)                                
#define AMT_FUNC_EXC(func)    
#define AMT_FUNC_EXC_IF(cond, func)    
#define AMT_INC_COUNTER(member)
#define AMT_DEC_COUNTER(member)
#define AMT_SET_VALUE(member, val)
#define AMT_GET_VALUE(x, member)
#define AMT_INC_COUNTER_IF(cond, member)
#define AMT_DEC_COUNTER_IF(cond, member)
#define AMT_SET_VALUE_IF(cond, member, val)
#define AMT_GET_VALUE_IF(cond, x, member)
#define AMT_PRINT_STATE()

#ifndef AMT_CONTROL
#error "Error: you need to define AMT_CONTROL macro in your code to be able to use ALF module test system!"
// The user have to define AMT_CONTROL, e.g. like this:
// #define AMT_CONTROL() static_cast<CAlfModuleTestDataControl*>(Dll::Tls())
// or
// #define AMT_CONTROL() iMyModuleTestDataControl
// etc.
#endif

#else


//  *** Use these macros to access global memory chunk


// Note: If you read/write a large block of data members, it is advisable not use the AMT_FUNC_EXC() based macros below. 
//       Use Lock() and Unlock() around the block explicitely, and use AMT_FUNC() macro.
//       That is to avoid unnecessary nested lock-unlock sequences (even if nested locks are working ok).

// Note: Be careful not to lock the the mutex for a long time as it will halt other processes if they are using the lock during that time!

// Generic macros
#define AMT_DATA()                  AMT_CONTROL()->iModuleTestData
#define AMT_FUNC(func)              if (AMT_DATA()->iIsEnabled) {func;}                                         
#define AMT_FUNC_EXC(func)          {AMT_CONTROL()->Lock(); if (AMT_DATA()->iIsEnabled) {func;} AMT_CONTROL()->Unlock();}        
#define AMT_FUNC_EXC_IF(cond, func) {AMT_CONTROL()->Lock(); if (AMT_DATA()->iIsEnabled && (cond)) {func;} AMT_CONTROL()->Unlock();}        

// Single operation macros, that will do lock/unlock.
#define AMT_INC_COUNTER(member)     AMT_FUNC_EXC(AMT_DATA()->member++)
#define AMT_DEC_COUNTER(member)     AMT_FUNC_EXC(AMT_DATA()->member--)
#define AMT_SET_VALUE(member, val)  AMT_FUNC_EXC(AMT_DATA()->member=(val))
#define AMT_GET_VALUE(x, member)    AMT_FUNC_EXC((x) = AMT_DATA()->member)
#define AMT_PRINT_STATE()           AMT_FUNC_EXC(AMT_DATA()->PrintState())

// Conditional single operation macros, that will do lock/unlock.
#define AMT_INC_COUNTER_IF(cond, member)    AMT_FUNC_EXC_IF((cond), AMT_DATA()->member++)
#define AMT_DEC_COUNTER_IF(cond, member)    AMT_FUNC_EXC_IF((cond), AMT_DATA()->member--)
#define AMT_SET_VALUE_IF(cond, member, val) AMT_FUNC_EXC_IF((cond), AMT_DATA()->member=(val))
#define AMT_GET_VALUE_IF(cond, x, member)   AMT_FUNC_EXC_IF((cond), (x) = AMT_DATA()->member)


// *** Global object names
_LIT(KAlfModuleTestChunkName, "ALF_MODULE_TEST_CHUNK");
_LIT(KAlfModuleTestMutexName, "ALF_MODULE_TEST_MUTEX");

/*
 *  Class CAlfModuleTestData
 */

NONSHARABLE_CLASS(CAlfModuleTestData) : public CBase
    {
public:
    void PrintState()
        {
        RDebug::Print(_L("*** ALF INTERNAL STATE ***"));
        RDebug::Print(_L("iTotalLayerCount[0]=%d"), iTotalLayerCount[0]);
        RDebug::Print(_L("iTotalLayerCount[1]=%d"), iTotalLayerCount[1]);
        RDebug::Print(_L("iCloneLayerCount=%d"), iCloneLayerCount);
        RDebug::Print(_L("iRsTotalNodeCount=%d"), iRsTotalNodeCount);
        RDebug::Print(_L("iRsWindowGroupNodeCount=%d"), iRsWindowGroupNodeCount);
        RDebug::Print(_L("iRsWindowNodeCount=%d"), iRsWindowNodeCount);
        RDebug::Print(_L("iRsAnimNodeCount=%d"), iRsAnimNodeCount);
        RDebug::Print(_L("iRsWindowNodeActivatedCount=%d"), iRsWindowNodeActivatedCount);
        RDebug::Print(_L("iRsNodeExtentChangedCount=%d"), iRsNodeExtentChangedCount);
        RDebug::Print(_L("iRsLatestNodeExtentRect= x:%d, y:%d, width=%d, height=%d"), 
                         iRsLatestNodeExtentRect.iTl.iX, iRsLatestNodeExtentRect.iTl.iY, 
                         iRsLatestNodeExtentRect.Width(), iRsLatestNodeExtentRect.Height());
        RDebug::Print(_L("iRsTotalNodeFlagChangedCount=%d"), iRsTotalNodeFlagChangedCount);
        RDebug::Print(_L("iRsTotalNodeAttributeChangedCount=%d"), iRsTotalNodeAttributeChangedCount);
        RDebug::Print(_L("iTotalNodeCount=%d"), iTotalNodeCount);
        RDebug::Print(_L("iWindowGroupNodeCount=%d"), iWindowGroupNodeCount);
        RDebug::Print(_L("iWindowNodeCount=%d"), iWindowNodeCount);
        RDebug::Print(_L("iAnimNodeCount=%d"), iAnimNodeCount);
        RDebug::Print(_L("iWindowNodeActivatedCount=%d"), iWindowNodeActivatedCount);
        RDebug::Print(_L("iNodeExtentChangedCount=%d"), iNodeExtentChangedCount);
        RDebug::Print(_L("iLatestNodeExtentRect= x:%d, y:%d, width=%d, height=%d"), 
                         iLatestNodeExtentRect.iTl.iX, iLatestNodeExtentRect.iTl.iY, 
                         iLatestNodeExtentRect.Width(), iLatestNodeExtentRect.Height());
        RDebug::Print(_L("iTotalNodeFlagChangedCount=%d"), iTotalNodeFlagChangedCount);
        RDebug::Print(_L("iTotalNodeAttributeChangedCount=%d"), iTotalNodeAttributeChangedCount);        
        RDebug::Print(_L("iTotalVisualCount=%d"), iTotalVisualCount);
        RDebug::Print(_L("iVisibleVisualCount=%d"), iVisibleVisualCount);
        RDebug::Print(_L("iActiveVisualCount=%d"), iActiveVisualCount);
        RDebug::Print(_L("iPassiveVisualCount=%d"), iPassiveVisualCount);
        RDebug::Print(_L("iTextureCount=%d"), iTextureCount);
        RDebug::Print(_L("iRenderBufferCount=%d"), iRenderBufferCount);
        RDebug::Print(_L("iTotalControlGroupCount=%d"), iTotalControlGroupCount);        
        RDebug::Print(_L("iVisualSizeChangedCount=%d"), iVisualSizeChangedCount);        
        RDebug::Print(_L("iVisualPositionChangedCount=%d"), iVisualPositionChangedCount);
        RDebug::Print(_L("iLatestVisualExtentRect= x:%d, y:%d, width=%d, height=%d"), 
                         iLatestVisualExtentRect.iTl.iX, iLatestVisualExtentRect.iTl.iY, 
                         iLatestVisualExtentRect.Width(), iLatestVisualExtentRect.Height());
        RDebug::Print(_L("iTotalVisualFlagChangedCount=%d"), iTotalVisualFlagChangedCount);
        RDebug::Print(_L("iTotalVisualAttributeChangedCount=%d"), iTotalVisualAttributeChangedCount);        
        RDebug::Print(_L("*** ALF INTERNAL STATE ***"));
        }
    
    
public:
    TBool iIsEnabled;           // *** not yet implemented. For run-time enabling/disabling of the test system.  
    
    // Alf Render Stage
    TInt iScreenCount;          // *** not yet implemented
    TInt iTotalLayerCount[10];  // For each screen
    TInt iCloneLayerCount;      // ** not yet implemented
    TInt iRsTotalNodeCount;
    TInt iRsWindowGroupNodeCount;
    TInt iRsWindowNodeCount;
    TInt iRsAnimNodeCount;
    TInt iRsWindowNodeActivatedCount;    
    TInt iRsNodeExtentChangedCount;
    TRect iRsLatestNodeExtentRect;
    TInt iRsTotalNodeFlagChangedCount;
    TInt iRsTotalNodeAttributeChangedCount;
    // These are temporary variables for Alf Render Stage thread internal use only!
    TInt iARS_Temp1;
    TInt iARS_Temp2;
    TInt iARS_Temp3;
    TInt iARS_Temp4;
   
    // Alf Streamer
    TInt iTotalNodeCount;
    TInt iWindowGroupNodeCount;
    TInt iWindowNodeCount;
    TInt iAnimNodeCount;
    TInt iWindowNodeActivatedCount;
    TInt iNodeExtentChangedCount;
    TRect iLatestNodeExtentRect;
    TInt iTotalNodeFlagChangedCount;
    TInt iTotalNodeAttributeChangedCount;
    // These are temporary variables for Alf Streamer thread internal use only!
    TInt iAST_Temp1;
    TInt iAST_Temp2;
    TInt iAST_Temp3;
    TInt iAST_Temp4;
   
    // Alf Server
    TInt iTotalVisualCount;
    TInt iVisibleVisualCount;
    TInt iActiveVisualCount;
    TInt iPassiveVisualCount;
    TInt iTextureCount;         // *** not yet implemented
    TInt iRenderBufferCount;    // *** not yet implemented
    TInt iTotalControlGroupCount;
    TInt iVisualSizeChangedCount;
    TInt iVisualPositionChangedCount;
    TRect iLatestVisualExtentRect;
    TInt iTotalVisualFlagChangedCount;
    TInt iTotalVisualAttributeChangedCount;
    TInt iOrdinalChange;
    // These are temporary variables for Alf Server thread internal use only!
    TInt iASE_Temp1;
    TInt iASE_Temp2;
    TInt iASE_Temp3;
    TInt iASE_Temp4;
    };


/*
 *  Class CAlfModuleTestDataControl
 */
NONSHARABLE_CLASS(CAlfModuleTestDataControl) : public CBase
    {
public:
    /*
     * Destructor
     */
    ~CAlfModuleTestDataControl()
        {
        iModuleTestMutex.Close();
        iModuleTestChunk.Close();
        }

    /*
     * Open global chunk and mutex created elsewhere
     */
    TInt OpenGlobalObjects()
        {
        RDebug::Print(_L("CAlfModuleTestDataControl::OpenGlobalObjects()."));
        // Open global module testing chunk
        TBool isReadOnly = EFalse;
        TInt err = iModuleTestChunk.OpenGlobal(KAlfModuleTestChunkName, isReadOnly);
        if (!err)
            {
            // Create global module testing mutex
            err = iModuleTestMutex.OpenGlobal(KAlfModuleTestMutexName);
            if (!err)
                {
                iModuleTestData = reinterpret_cast<CAlfModuleTestData*>(iModuleTestChunk.Base());
                }
            }
        RDebug::Print(_L("CAlfModuleTestDataControl::OpenGlobalObjects. ret=%d"), err);
        return err;
        }

    /*
     * Lock access to global memory
     */
    void Lock() {iModuleTestMutex.Wait();}
 
    /*
     * Unlock access to global memory
     */
    void Unlock() {iModuleTestMutex.Signal();}
    
public:
    RChunk iModuleTestChunk;
    RMutex iModuleTestMutex;
    CAlfModuleTestData* iModuleTestData; // Not owned
    };

#endif

#endif // ALFMODULETEST_H

// End of File
