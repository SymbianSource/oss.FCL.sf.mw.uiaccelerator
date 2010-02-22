#include "e32base.h"
#include "e32debug.h"

#ifndef ALFMODULETEST_H
#define ALFMODULETEST_H

// Define this to build module testing enchanced version of ALF
//#define USE_MODULE_TEST_HOOKS_FOR_ALF

#if !defined(USE_MODULE_TEST_HOOKS_FOR_ALF) || !defined(AMT_CONTROL)

#define AMT_FUNC(func)                                
#define AMT_FUNC_EXC(func)    
#define AMT_INC_COUNTER(member)
#define AMT_DEC_COUNTER(member)
#define AMT_SET_VALUE(member, val)
#define AMT_GET_VALUE(x, member)
#define AMT_PRINT_STATE()

#ifndef AMT_CONTROL
#error "Error: you need to define AMT_CONTROL macro in your code to be able to use ALF module test system!"
// The user have to define AMT_CONTROL, e.g. like this:
// #define AMT_CONTROL()                static_cast<CAlfModuleTestDataControl*>(Dll::Tls())
// or
// #define AMT_CONTROL()                iMyModuleTestDataControl
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

// Single operation macros, that will do lock/unlock.
#define AMT_INC_COUNTER(member)     AMT_FUNC_EXC(AMT_DATA()->member++)
#define AMT_DEC_COUNTER(member)     AMT_FUNC_EXC(AMT_DATA()->member--)
#define AMT_SET_VALUE(member, val)  AMT_FUNC_EXC(AMT_DATA()->member=(val))
#define AMT_GET_VALUE(x, member)    AMT_FUNC_EXC((x) = AMT_DATA()->member)
#define AMT_PRINT_STATE()           AMT_FUNC_EXC(AMT_DATA()->PrintState())

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
        RDebug::Print(_L("iTotalNodeCount=%d"), iTotalNodeCount);
        RDebug::Print(_L("iWindowGroupNodeCount=%d"), iWindowGroupNodeCount);
        RDebug::Print(_L("iWindowNodeCount=%d"), iWindowNodeCount);
        RDebug::Print(_L("iAnimNodeCount=%d"), iAnimNodeCount);
        RDebug::Print(_L("iTotalVisualCount=%d"), iTotalVisualCount);
        RDebug::Print(_L("iVisibleVisualCount=%d"), iVisibleVisualCount);
        RDebug::Print(_L("iActiveVisualCount=%d"), iActiveVisualCount);
        RDebug::Print(_L("iPassiveVisualCount=%d"), iPassiveVisualCount);
        RDebug::Print(_L("iTextureCount=%d"), iTextureCount);
        RDebug::Print(_L("iRenderBufferCount=%d"), iRenderBufferCount);
        RDebug::Print(_L("*** ALF INTERNAL STATE ***"));
        }
    
    
public:
    TBool iIsEnabled;           // *** not yet implemented. For run-time enabling/disabling of the test system.  
    
    // Alf Render Stage
    TInt iScreenCount;          // *** not yet implemented
    TInt iTotalLayerCount[10];  // For each screen
    TInt iCloneLayerCount;      // ** not yet implemented
    
    // Alf Streamer
    TInt iTotalNodeCount;       // *** not yet implemented
    TInt iWindowGroupNodeCount; // *** not yet implemented
    TInt iWindowNodeCount;      // *** not yet implemented
    TInt iAnimNodeCount;        // *** not yet implemented
    
    // Alf Server
    TInt iTotalVisualCount;     // *** not yet implemented
    TInt iVisibleVisualCount;   // *** not yet implemented
    TInt iActiveVisualCount;    // Active visual count
    TInt iPassiveVisualCount;   // Passive visual count
    TInt iTextureCount;         // *** not yet implemented
    TInt iRenderBufferCount;    // *** not yet implemented
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
        RDebug::Print(_L("CAlfModuleTestDataControl::OpenGlobalObjects. err=%d"), err);
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
