#include "e32base.h"
#include "e32debug.h"

#ifndef ALFMODULETEST_H
#define ALFMODULETEST_H

// Define this to build module testing enchanced version of ALF
//#define USE_MODULE_TEST_HOOKS_FOR_ALF 

#if !defined(USE_MODULE_TEST_HOOKS_FOR_ALF) || !defined(AMT_CONTROL)

#define AMT_DATA()
#define AMT_FUNC(func)                                
#define AMT_FUNC_EXC(func)
#define AMT_FUNC_EXC_RET(ret, func)
#define AMT_FUNC_EXC_IF(cond, func)
#define AMT_FUNC_EXC_IF_RET(cond, ret, func)
#define AMT_INC_COUNTER(member)
#define AMT_DEC_COUNTER(member)
#define AMT_SET_VALUE(member, val)
#define AMT_GET_VALUE(x, member)
#define AMT_INC_COUNTER_IF(cond, member)
#define AMT_DEC_COUNTER_IF(cond, member)
#define AMT_SET_VALUE_IF(cond, member, val)
#define AMT_GET_VALUE_IF(cond, x, member)

#define AMT_MAP_APPEND(memberMap, key, type, defaultValue)          
#define AMT_MAP_SET_VALUE_IF(cond, memberMap, key, value, type)     
#define AMT_MAP_INC_VALUE_IF(cond, memberMap, key, type)            
#define AMT_MAP_DEC_VALUE_IF(cond, memberMap, key, type)            
#define AMT_MAP_SET_VALUE(memberMap, key, value, type)              
#define AMT_MAP_INC_VALUE(memberMap, key, type)                              
#define AMT_MAP_DEC_VALUE(memberMap, key, type)                     
#define AMT_MAP_RESET(memberMap)                                    

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
#define AMT_FUNC_EXC_RET(ret, func) {AMT_CONTROL()->Lock(); if (AMT_DATA()->iIsEnabled) {ret = func;} AMT_CONTROL()->Unlock();}
#define AMT_FUNC_EXC_IF(cond, func) {AMT_CONTROL()->Lock(); if (AMT_DATA()->iIsEnabled && (cond)) {func;} AMT_CONTROL()->Unlock();}        
#define AMT_FUNC_EXC_IF_RET(cond, ret, func) {AMT_CONTROL()->Lock(); if (AMT_DATA()->iIsEnabled && (cond)) {ret = func;} AMT_CONTROL()->Unlock();}

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

// Map operation macros, that will do lock/unlock
#define AMT_MAP_APPEND(memberMap, key, type, defaultValue)          AMT_FUNC_EXC(AMT_DATA()->memberMap.Append(key, type, defaultValue))
#define AMT_MAP_SET_VALUE_IF(cond, memberMap, key, value, type)     AMT_FUNC_EXC_IF((cond), AMT_DATA()->memberMap.SetValue(key, value, type))
#define AMT_MAP_INC_VALUE_IF(cond, memberMap, key, type)            AMT_FUNC_EXC_IF((cond && AMT_DATA()->memberMap.Find(key, type)), AMT_DATA()->memberMap.SetValue(key, AMT_DATA()->memberMap.Find(key, type)->Value() + 1, type))
#define AMT_MAP_DEC_VALUE_IF(cond, memberMap, key, type)            AMT_FUNC_EXC_IF((cond && AMT_DATA()->memberMap.Find(key, type)), AMT_DATA()->memberMap.SetValue(key, AMT_DATA()->memberMap.Find(key, type)->Value() - 1, type))
#define AMT_MAP_SET_VALUE(memberMap, key, value, type)              AMT_FUNC_EXC_IF(ETrue, AMT_DATA()->memberMap.SetValue(key, value, type))
#define AMT_MAP_INC_VALUE(memberMap, key, type)                     AMT_MAP_INC_VALUE_IF(ETrue, memberMap, key, type)              
#define AMT_MAP_DEC_VALUE(memberMap, key, type)                     AMT_MAP_DEC_VALUE_IF(ETrue, memberMap, key, type)
#define AMT_MAP_RESET(memberMap)                                    AMT_FUNC_EXC(AMT_DATA()->memberMap.Reset())

// *** Global object names
_LIT(KAlfModuleTestChunkName, "ALF_MODULE_TEST_CHUNK");
_LIT(KAlfModuleTestMutexName, "ALF_MODULE_TEST_MUTEX");


/**
 * TAlfModuleTestType specifies recognized test types.
 */
enum TAlfModuleTestType
    {
    // Do not use this value when creating item.
    EAlfModuleTestTypeNone,
    
    // Render stage component specific tests
    EAlfModuleTestTypeRenderStageChangeSize,
    EAlfModuleTestTypeRenderStageChangePosition,
    EAlfModuleTestTypeRenderStageChangeFlag,
    
    // Streamer hierarchy model component specific tests
    EAlfModuleTestTypeHierarchyModelChangeSize,
    EAlfModuleTestTypeHierarchyModelChangePosition,
    EAlfModuleTestTypeHierarchyModelChangeFlag,    
    
    // Server bridge component specific tests
    EAlfModuleTestTypeBridgeChangeSize,
    EAlfModuleTestTypeBridgeChangePosition,
    EAlfModuleTestTypeBridgeChangeFlag,
    
    // Do not use this value when creating item.
    // This is just meant for Find operations when all tests are accepted.
    EAlfModuleTestTypeAll
    };


/**
 * CAlfModuleTestItem
 * 
 * Provides key-value pair that is used in TAlfModuleTestMap.
 */
template< class T >
NONSHARABLE_CLASS( TAlfModuleTestItem )
    {
    
public:

    /**
     * Constructor to initialize variables.
     * 
     * @param aKey Key that identifies the item.
     *             In test cases this could be for example handle.
     * @param aTestType Defines for what this test item is meant for.
     */
    TAlfModuleTestItem( TInt aKey, const TAlfModuleTestType& aTestType, const T& aDefaultValue ):
        iKey( aKey ),
        iTestType( aTestType ),
        iValue( aDefaultValue ),
        iValueSetCount( 0 )
        {
        }

    
    /**
     * @param aObject Value to be compared.
     * @return ETrue if given object equals the value of this item.
     *         Else EFalse.
     */
    TBool Equals( const T& aValue, const TAlfModuleTestType& aTestType ) const
        {
        // Also, check that value has been set. If it has not been set,
        // then think objects as unequals.
        return ( iValueSetCount > 0 
                 && iValue == aValue 
                 && TestTypeMatch( aTestType ) );
        }

    
    /**
     * @return TInt Key that should be set during creation of this object.
     */
    TInt Key() const
        {
        return iKey;
        }

    /**
     * @see ValueSet to check if the value has already been set.
     * 
     * @return const T& Value that corresonds the key.
     */
    const T& Value() const
        {
        return iValue;
        }
    
    
    /**
     * @param aValue Value to be set for the key
     */
    void SetValue( const T& aValue )
        {
        iValue = aValue;
        ++iValueSetCount;
        }

    
    /**
     * @return TInt Informs how many times the value has been set. 
     */
    TInt ValueSetCount() const
        {
        return iValueSetCount;
        }
    
    /**
     * @return const TAlfModuleTestType& Defines what the test is for
     */
    const TAlfModuleTestType& TestType() const
        {
        return iTestType;
        }

    
    /**
     * @param aTestType
     * @return TBool ETrue if flag matches this item. Else EFalse.
     */
    TBool TestTypeMatch( const TAlfModuleTestType& aTestType ) const
        {
        return ( EAlfModuleTestTypeAll == aTestType
                 || iTestType == aTestType );
        }

    
    /**
     * Resets the item info
     */
    void Reset()
        {
        iValueSetCount = 0;
        }

    
private: // data    
    
    TInt iKey;
    TAlfModuleTestType iTestType;    
    T iValue;
    TInt iValueSetCount;
    
    };


/**
 * Class CAlfModuleTestMap
 * 
 * Provides map functionality for the key-value-pairs.
 * In test cases, this should most likely be used so, that 
 * first test case classes create items with certain keys, for example with handle values.
 * Then, define hooks are used in the code to update values that corresond the correct handles.
 * In the end, test case classes can check that items have correct values set and if the test
 * is passed.
 */
template< class T >
NONSHARABLE_CLASS( TAlfModuleTestMap )
    {
public:

    // Maximum item count in the map
    static const TInt KMaxArrayCount = 50;

    
    /**
     * Constructor to initialize variables.
     */
    TAlfModuleTestMap():
        iCount( 0 ),
        iSetValueCallCount( 0 )
        {            
        }

    
    /**
     * @param aKey
     * @param aTestType Informs what type of test is accepted. Others are skipped.
     * @return T* Ownership is not transferred.
     *            NULL if item is not found.
     */
    TAlfModuleTestItem< T >* Find( TInt aKey, const TAlfModuleTestType& aTestType )
        {
        // Try to find the item corresponding the given key.
        for ( TInt i = 0; i < iCount; ++i )
            {
            TAlfModuleTestItem< T >& testItem( iArray[ i ] );
            if ( testItem.Key() == aKey
                 && testItem.TestTypeMatch( aTestType ) )
                {
                return &( testItem );
                }
            }
        // Item corresponding the given key was not found.
        return NULL;
        }    
    
    
    /**
     * Function to append new item into the map.
     * 
     * @param aKey
     * @param aTestType Describes for what case the appended test item is created for.
     * @return TInt System wide error code.
     */    
    TInt Append( TInt aKey, const TAlfModuleTestType& aTestType, const T& aDefaultValue )
        {
        if ( iCount == KMaxArrayCount )
            {
            // Array already full.
            return KErrOverflow;
            }
        else if ( Find( aKey, aTestType ) )
            {
            // Key has already been inserted.
            return KErrAlreadyExists;
            }
        
        // Append new key value set into the array.
        iArray[ iCount ] = TAlfModuleTestItem< T >( aKey, aTestType, aDefaultValue );
        ++iCount;
        return KErrNone;        
        }

    
    /**
     * Sets the value for the item.
     * Item itself should already exist in the array before
     * setting its value here. See, Append function.
     * 
     * @param aKey
     * @param aValue
     * @return TInt System wide error code.
     */
    TInt SetValue( TInt aKey, const T& aValue, const TAlfModuleTestType& aTestType )
        {
        // Increase counter, because this function is called.
        ++iSetValueCallCount;
        TAlfModuleTestItem< T >* item( Find( aKey, aTestType ) );        
        if ( !item )
            {
            // Item was not found from the array.        
            return KErrNotFound;
            }        
        // Item exists. So, set its values.
        item->SetValue( aValue );
        return KErrNone;
        }

    
    /**
     * Resets the map
     */
    void Reset()
        {
        // Just reset the counter.
        // We do not bother to reset map items, because when counter is reseted
        // already set items and their info is left out of the scope.
        iCount = 0;
        iSetValueCallCount = 0;
        }
    
    
    /**
     * Checks if all the values of items in the array match the given value.
     * 
     * @param aValue Reference to the value that items are compared to.
     * @param aTestType Informs the test type whose items should be compared.
     */
    TInt CountEquals( const T& aValue, const TAlfModuleTestType& aTestType ) const
        {
        TInt count( 0 );
        for ( TInt i = 0; i < iCount; ++i )
            {
            if ( iArray[ i ].Equals( aValue, aTestType ) )
                {
                // Item matches
                ++count;            
                }
            }
        return count;
        }


    /**
     * @return TInt Number of map items
     */
    TInt ItemCount() const
        {
        return iCount;
        }


    /**
     * @return const TAlfModuleTestItem< T >& Reference to the map item
     */
    const TAlfModuleTestItem< T >& Item( TInt aIndex ) const
        {
        return iArray[ aIndex ];
        }

    
    /**
     * @return TInt Number of times SetValue function has been called
     *              since last reset. This information can be used
     *              to check if hooks have been used correct times during
     *              a test case. Notice, that this informs the number of
     *              function calls, not the number of times a value has actually
     *              set for some item.
     */
    TInt SetValueCallCount() const
        {
        return iSetValueCallCount;
        }
    
    
private: // data
    
    TAlfModuleTestItem< T > iArray[ KMaxArrayCount ];
    // Informs number of array items
    TInt iCount;
    // Informs how many times SetItem has been called since last reset.
    // Notice, that this informs the number of function calls, not the number
    // of times a value has actually set for some item.
    TInt iSetValueCallCount;
    
    };

    
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
        RDebug::Print(_L("iSizeMap =>"));
        PrintSizeMapState( iSizeMap );
        RDebug::Print(_L("iPositionMap =>"));
        PrintPositionMapState( iPositionMap );        
        RDebug::Print(_L("*** ALF INTERNAL STATE ***"));
        }

    
    void PrintSizeMapState( TAlfModuleTestMap< TSize > aMap )
        {
        RDebug::Print(_L("*** ALF INTERNAL SIZE MAP STATE -->"));
        RDebug::Print(_L("Map item count=%d, SetValue call count=%d"), 
                         aMap.ItemCount(), aMap.SetValueCallCount());
        for ( TInt i = 0; i < aMap.ItemCount(); ++i )
            {
            const TAlfModuleTestItem< TSize >& item( aMap.Item( i ) );
            RDebug::Print(_L("Map item %d, iKey=%d, iTestType=%d, iValueSetCount=%d"),
                             i, item.Key(), item.TestType(), item.ValueSetCount());
            RDebug::Print(_L("Map item index=%d, width=%d, height=%d"),
                             i, item.Value().iWidth, item.Value().iHeight);
            }
        RDebug::Print(_L("<-- ALF INTERNAL SIZE MAP STATE ***"));
        }

    
    void PrintPositionMapState( TAlfModuleTestMap< TPoint > aMap )
        {
        RDebug::Print(_L("*** ALF INTERNAL POSITION MAP STATE -->"));
        RDebug::Print(_L("Map item count=%d, SetValue call count=%d"), 
                         aMap.ItemCount(), aMap.SetValueCallCount());
        for ( TInt i = 0; i < aMap.ItemCount(); ++i )
            {
            const TAlfModuleTestItem< TPoint >& item( aMap.Item( i ) );
            RDebug::Print(_L("Map item %d, iKey=%d, iTestType=%d, iValueSetCount=%d"),
                             i, item.Key(), item.TestType(), item.ValueSetCount());
            RDebug::Print(_L("Map item index=%d, x=%d, y=%d"),
                             i, item.Value().iX, item.Value().iY);
            }
        RDebug::Print(_L("<-- ALF INTERNAL POSITION MAP STATE ***"));
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

    // Map that contains integer items that can be specified for certain test cases.
    TAlfModuleTestMap< TInt > iIntMap;    
    // Map that contains size items that can be specified for certain test cases.
    TAlfModuleTestMap< TSize > iSizeMap;
    // Map that contains position items that can be specified for certain test cases.
    TAlfModuleTestMap< TPoint > iPositionMap;    

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
