/**
 * @see alfmoduletest.h for class implementations that these defines use.
 */

#ifndef ALF_MODULE_TEST_DEFINES_H
#define ALF_MODULE_TEST_DEFINES_H


// Informs if module test hooks have been set on.
#include "alfmoduletestconf.h"


#ifndef USE_MODULE_TEST_HOOKS_FOR_ALF
    // Use empty defines if module test hook is not set.

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
    
    #define AMT_MAP_PTR_TO_KEY_CAST( keyPtr )
    #define AMT_MAP_CPTR_TO_KEY_CAST( keyCPtr )
    #define AMT_MAP_APPEND_IF(cond, memberMap, key, defaultValue, type)
    #define AMT_MAP_APPEND(memberMap, key, defaultValue, type)
    #define AMT_MAP_APPEND_LINK_IF(cond, memberMap, linkKey, targetKey, type)
    #define AMT_MAP_APPEND_LINK(memberMap, linkKey, targetKey, type)
    #define AMT_MAP_APPEND_AND_LINK_IF(cond, memberMap, linkKey, actualKey, defaultValue, type)
    #define AMT_MAP_APPEND_AND_LINK(memberMap, linkKey, actualKey, defaultValue, type)
    #define AMT_MAP_SET_VALUE_IF(cond, memberMap, key, value, type)
    #define AMT_MAP_INC_VALUE_IF(cond, memberMap, key, type)
    #define AMT_MAP_DEC_VALUE_IF(cond, memberMap, key, type)
    #define AMT_MAP_SET_VALUE(memberMap, key, value, type)
    #define AMT_MAP_INC_VALUE(memberMap, key, type)
    #define AMT_MAP_DEC_VALUE(memberMap, key, type)
    #define AMT_MAP_APPEND_ACCEPT_IF(cond, memberMap, testType)
    #define AMT_MAP_APPEND_ACCEPT(memberMap, testType)
    #define AMT_MAP_RESET_ITEMS(memberMap, defaultValue, type)
    #define AMT_MAP_RESET(memberMap)
    
    #define AMT_PRINT_STATE()

#else
    // Module test hook has been set.

    #ifndef AMT_CONTROL
        #error "Error: you need to define AMT_CONTROL macro in your code to be able to use ALF module test system!"
        // The user have to define AMT_CONTROL, e.g. like this:
        // #define AMT_CONTROL() static_cast<CAlfModuleTestDataControl*>(Dll::Tls())
        // or
        // #define AMT_CONTROL() iMyModuleTestDataControl
        // etc.
    #endif // AMT_CONTROL


    //  *** Use these macros to access global memory chunk
    
    
    // Note: If you read/write a large block of data members, it is advisable not use the AMT_FUNC_EXC() based macros below. 
    //       Use Lock() and Unlock() around the block explicitely, and use AMT_FUNC() macro.
    //       That is to avoid unnecessary nested lock-unlock sequences (even if nested locks are working ok).
    
    // Note: Be careful not to lock the the mutex for a long time as it will halt other processes if they are using the lock during that time!
    
    // Generic macros
    #define AMT_DATA()                              AMT_CONTROL()->iModuleTestData
    #define AMT_FUNC(func)                          if (AMT_DATA()->iIsEnabled) {func;}                                         
    #define AMT_FUNC_EXC(func)                      {AMT_CONTROL()->Lock(); if (AMT_DATA()->iIsEnabled) {func;} AMT_CONTROL()->Unlock();}
    #define AMT_FUNC_EXC_RET(ret, func)             {AMT_CONTROL()->Lock(); if (AMT_DATA()->iIsEnabled) {ret = func;} AMT_CONTROL()->Unlock();}
    #define AMT_FUNC_EXC_IF(cond, func)             {AMT_CONTROL()->Lock(); if (AMT_DATA()->iIsEnabled && (cond)) {func;} AMT_CONTROL()->Unlock();}        
    #define AMT_FUNC_EXC_IF_RET(cond, ret, func)    {AMT_CONTROL()->Lock(); if (AMT_DATA()->iIsEnabled && (cond)) {ret = func;} AMT_CONTROL()->Unlock();}
    
    // Single operation macros, that will do lock/unlock.
    #define AMT_INC_COUNTER(member)                 AMT_FUNC_EXC(AMT_DATA()->member++)
    #define AMT_DEC_COUNTER(member)                 AMT_FUNC_EXC(AMT_DATA()->member--)
    #define AMT_SET_VALUE(member, val)              AMT_FUNC_EXC(AMT_DATA()->member=(val))
    #define AMT_GET_VALUE(x, member)                AMT_FUNC_EXC((x) = AMT_DATA()->member)
    
    // Conditional single operation macros, that will do lock/unlock.
    #define AMT_INC_COUNTER_IF(cond, member)        AMT_FUNC_EXC_IF((cond), AMT_DATA()->member++)
    #define AMT_DEC_COUNTER_IF(cond, member)        AMT_FUNC_EXC_IF((cond), AMT_DATA()->member--)
    #define AMT_SET_VALUE_IF(cond, member, val)     AMT_FUNC_EXC_IF((cond), AMT_DATA()->member=(val))
    #define AMT_GET_VALUE_IF(cond, x, member)       AMT_FUNC_EXC_IF((cond), (x) = AMT_DATA()->member)
    
    // Map operation macros, that will do lock/unlock
    #define AMT_MAP_PTR_TO_KEY_CAST( keyPtr )                                                   reinterpret_cast< TInt >( keyPtr )
    #define AMT_MAP_CPTR_TO_KEY_CAST( keyCPtr )                                                 AMT_MAP_PTR_TO_KEY_CAST( static_cast< const CBase* >( keyCPtr ) )
    #define AMT_MAP_APPEND_IF(cond, memberMap, key, defaultValue, type)                         AMT_FUNC_EXC_IF((cond), AMT_DATA()->memberMap.Append(type, key, defaultValue))
    #define AMT_MAP_APPEND(memberMap, key, defaultValue, type)                                  AMT_MAP_APPEND_IF(ETrue, memberMap, key, defaultValue, type)
    #define AMT_MAP_APPEND_LINK_IF(cond, memberMap, linkKey, targetKey, type)                   AMT_FUNC_EXC_IF((cond), AMT_DATA()->memberMap.AppendLink(type, linkKey, targetKey))
    #define AMT_MAP_APPEND_LINK(memberMap, linkKey, targetKey, type)                            AMT_MAP_APPEND_LINK_IF(ETrue, memberMap, linkKey, targetKey, type)
    #define AMT_MAP_APPEND_AND_LINK_IF(cond, memberMap, linkKey, actualKey, defaultValue, type) AMT_MAP_APPEND_IF(cond, memberMap, actualKey, defaultValue, type ); AMT_MAP_APPEND_LINK_IF(cond, memberMap, linkKey, actualKey, type)
    #define AMT_MAP_APPEND_AND_LINK(memberMap, linkKey, actualKey, defaultValue, type)          AMT_MAP_APPEND_AND_LINK_IF(ETrue, memberMap, linkKey, actualKey, defaultValue, type)
    #define AMT_MAP_SET_VALUE_IF(cond, memberMap, key, value, type)                             AMT_FUNC_EXC_IF((cond), AMT_DATA()->memberMap.SetActualValue(type, key, value))
    #define AMT_MAP_INC_VALUE_IF(cond, memberMap, key, type)                                    AMT_FUNC_EXC_IF((cond && AMT_DATA()->memberMap.FindActual(type, key)), AMT_DATA()->memberMap.SetActualValue(type, key, AMT_DATA()->memberMap.FindActual(type, key)->Value() + 1))
    #define AMT_MAP_DEC_VALUE_IF(cond, memberMap, key, type)                                    AMT_FUNC_EXC_IF((cond && AMT_DATA()->memberMap.FindActual(type, key)), AMT_DATA()->memberMap.SetActualValue(type, key, AMT_DATA()->memberMap.FindActual(type, key)->Value() - 1))
    #define AMT_MAP_SET_VALUE(memberMap, key, value, type)                                      AMT_FUNC_EXC_IF(ETrue, AMT_DATA()->memberMap.SetActualValue(type, key, value))
    #define AMT_MAP_INC_VALUE(memberMap, key, type)                                             AMT_MAP_INC_VALUE_IF(ETrue, memberMap, key, type)              
    #define AMT_MAP_DEC_VALUE(memberMap, key, type)                                             AMT_MAP_DEC_VALUE_IF(ETrue, memberMap, key, type)
    #define AMT_MAP_APPEND_ACCEPT_IF(cond, memberMap, testType)                                 AMT_FUNC_EXC_IF((cond), AMT_DATA()->memberMap.AppendAccept(testType))
    #define AMT_MAP_APPEND_ACCEPT(memberMap, testType)                                          AMT_MAP_APPEND_ACCEPT_IF(ETrue, memberMap, testType)
    #define AMT_MAP_RESET_ITEMS(memberMap, defaultValue, type)                                  AMT_FUNC_EXC(AMT_DATA()->memberMap.ResetItems(type, defaultValue))
    #define AMT_MAP_RESET(memberMap)                                                            AMT_FUNC_EXC(AMT_DATA()->memberMap.Reset())
    
    #define AMT_PRINT_STATE()   AMT_FUNC_EXC(AMT_DATA()->PrintState())

#endif // USE_MODULE_TEST_HOOKS_FOR_ALF


// General defines
// Text cursor handle is defined as constant because correct handle is not provided
// from the window server for render stage.
#define AMT_MAP_TEXT_CURSOR_HANDLE 0


// Notice: 
// Defines below will be empty if module test hook is not set.
// If module test hook is set on, then these defines also use functionality defined above.  


// Render stage defines

#define AMT_MAP_RENDER_STAGE_NODE_CREATED() \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeClient == nodeType && aWindowTreeNode.Window() ), iIntMap, aWindowTreeNode.Window()->Handle(), 0, EAlfModuleTestTypeRenderStageCreateWindow ); \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeClient == nodeType && aWindowTreeNode.Window() ), iIntMap, aWindowTreeNode.Window()->Handle(), 0, EAlfModuleTestTypeRenderStageReleaseWindow ); \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeClient == nodeType && aWindowTreeNode.Window() ), iBoolMap, aWindowTreeNode.Window()->Handle(), EFalse, EAlfModuleTestTypeRenderStageActiveWindow ); \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeClient == nodeType && aWindowTreeNode.Window() ), iSizeMap, aWindowTreeNode.Window()->Handle(), TSize(), EAlfModuleTestTypeRenderStageChangeWindowSize ); \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeClient == nodeType && aWindowTreeNode.Window() ), iPositionMap, aWindowTreeNode.Window()->Handle(), TPoint(), EAlfModuleTestTypeRenderStageChangeWindowPosition ); \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeClient == nodeType && aWindowTreeNode.Window() ), iBoolMap, aWindowTreeNode.Window()->Handle(), EFalse, EAlfModuleTestTypeRenderStageChangeWindowVisibility ); \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeGroup == nodeType && aWindowTreeNode.WindowGroup() ), iIntMap, aWindowTreeNode.WindowGroup()->Identifier(), 0, EAlfModuleTestTypeRenderStageCreateWindowGroup ); \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeGroup == nodeType && aWindowTreeNode.WindowGroup() ), iIntMap, aWindowTreeNode.WindowGroup()->Identifier(), 0, EAlfModuleTestTypeRenderStageReleaseWindowGroup ); \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeStandardTextCursor == nodeType ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeRenderStageChangeTextCursorType ); \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeStandardTextCursor == nodeType ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeRenderStageChangeTextCursorClipRect ); \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeStandardTextCursor == nodeType ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeRenderStageChangeTextCursorFlag ); \
        AMT_MAP_APPEND_IF( ( MWsWindowTreeNode::EWinTreeNodeStandardTextCursor == nodeType ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeRenderStageChangeTextCursorColor ); \
        \
        AMT_MAP_INC_VALUE_IF( ( MWsWindowTreeNode::EWinTreeNodeClient == nodeType && aWindowTreeNode.Window() ), iIntMap, aWindowTreeNode.Window()->Handle(), EAlfModuleTestTypeRenderStageCreateWindow ); \
        AMT_MAP_INC_VALUE_IF( ( MWsWindowTreeNode::EWinTreeNodeGroup == nodeType && aWindowTreeNode.WindowGroup() ), iIntMap, aWindowTreeNode.WindowGroup()->Identifier(), EAlfModuleTestTypeRenderStageCreateWindowGroup )

#define AMT_MAP_RENDER_STAGE_TEXT_CURSOR_CHANGE() \
        AMT_MAP_INC_VALUE_IF( ( aWindowTreeNode.NodeType() == MWsWindowTreeNode::EWinTreeNodeStandardTextCursor && aAttribute == ECursorType ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeRenderStageChangeTextCursorType ); \
        AMT_MAP_INC_VALUE_IF( ( aWindowTreeNode.NodeType() == MWsWindowTreeNode::EWinTreeNodeStandardTextCursor && aAttribute == ECursorClipRect ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeRenderStageChangeTextCursorClipRect ); \
        AMT_MAP_INC_VALUE_IF( ( aWindowTreeNode.NodeType() == MWsWindowTreeNode::EWinTreeNodeStandardTextCursor && aAttribute == ECursorFlags ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeRenderStageChangeTextCursorFlag ); \
        AMT_MAP_INC_VALUE_IF( ( aWindowTreeNode.NodeType() == MWsWindowTreeNode::EWinTreeNodeStandardTextCursor && aAttribute == ECursorColor ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeRenderStageChangeTextCursorColor )


// Streamer defines
                          
#define AMT_MAP_STREAMER_NODE_WINDOW_CONSTRUCT() \
        AMT_MAP_APPEND_AND_LINK( iIntMap, iId, iNodeWindowConstructionStruct.iWindowHandle, 0, EAlfModuleTestTypeHierarchyModelCreateWindow ); \
        AMT_MAP_APPEND_AND_LINK( iIntMap, iId, iNodeWindowConstructionStruct.iWindowHandle, 0, EAlfModuleTestTypeHierarchyModelReleaseWindow ); \
        AMT_MAP_APPEND_AND_LINK( iBoolMap, iId, iNodeWindowConstructionStruct.iWindowHandle, EFalse, EAlfModuleTestTypeHierarchyModelActiveWindow ); \
        AMT_MAP_APPEND_AND_LINK( iSizeMap, iId, iNodeWindowConstructionStruct.iWindowHandle, TSize(), EAlfModuleTestTypeHierarchyModelChangeWindowSize ); \
        AMT_MAP_APPEND_AND_LINK( iPositionMap, iId, iNodeWindowConstructionStruct.iWindowHandle, TPoint(), EAlfModuleTestTypeHierarchyModelChangeWindowPosition ); \
        AMT_MAP_APPEND_AND_LINK( iBoolMap, iId, iNodeWindowConstructionStruct.iWindowHandle, EFalse, EAlfModuleTestTypeHierarchyModelChangeWindowVisibility )

#define AMT_MAP_STREAMER_NODE_GROUP_CONSTRUCT() \
        AMT_MAP_APPEND_AND_LINK( iIntMap, iId, clientHandle, 0, EAlfModuleTestTypeHierarchyModelCreateWindowGroup ); \
        AMT_MAP_APPEND_AND_LINK( iIntMap, iId, clientHandle, 0, EAlfModuleTestTypeHierarchyModelReleaseWindowGroup )

#define AMT_MAP_STREAMER_TEXT_CURSOR_CONSTRUCT() \
        AMT_MAP_APPEND( iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeHierarchyModelChangeTextCursorType ); \
        AMT_MAP_APPEND( iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeHierarchyModelChangeTextCursorClipRect ); \
        AMT_MAP_APPEND( iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeHierarchyModelChangeTextCursorFlag ); \
        AMT_MAP_APPEND( iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeHierarchyModelChangeTextCursorColor )

#define AMT_MAP_STREAMER_TEXT_CURSOR_CHANGE() \
        AMT_MAP_INC_VALUE_IF( ( attribute == MWsWindowTreeObserver::ECursorType ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeHierarchyModelChangeTextCursorType ); \
        AMT_MAP_INC_VALUE_IF( ( attribute == MWsWindowTreeObserver::ECursorClipRect ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeHierarchyModelChangeTextCursorClipRect ); \
        AMT_MAP_INC_VALUE_IF( ( attribute == MWsWindowTreeObserver::ECursorFlags ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeHierarchyModelChangeTextCursorFlag ); \
        AMT_MAP_INC_VALUE_IF( ( attribute == MWsWindowTreeObserver::ECursorColor ), iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeHierarchyModelChangeTextCursorColor )

                                 
// Alfserver defines

#define AMT_MAP_BRIDGE_ADD_VISUAL() \
        AMT_MAP_APPEND_AND_LINK( iIntMap, aWindowNodeId, aClientSideId, 0, EAlfModuleTestTypeBridgeCreateWindow ); \
        AMT_MAP_APPEND_AND_LINK( iIntMap, aWindowNodeId, aClientSideId, 0, EAlfModuleTestTypeBridgeReleaseWindow ); \
        AMT_MAP_APPEND_AND_LINK( iBoolMap, aWindowNodeId, aClientSideId, EFalse, EAlfModuleTestTypeBridgeActiveWindow ); \
        AMT_MAP_APPEND_AND_LINK( iSizeMap, aWindowNodeId, aClientSideId, TSize(), EAlfModuleTestTypeBridgeChangeWindowSize ); \
        AMT_MAP_APPEND_AND_LINK( iPositionMap, aWindowNodeId, aClientSideId, TPoint(), EAlfModuleTestTypeBridgeChangeWindowPosition ); \
        AMT_MAP_APPEND_AND_LINK( iBoolMap, aWindowNodeId, aClientSideId, EFalse, EAlfModuleTestTypeBridgeChangeWindowVisibility ); \
        \
        AMT_MAP_APPEND_AND_LINK_IF( aVisual, iIntMap, AMT_MAP_CPTR_TO_KEY_CAST( aVisual ), aClientSideId, 0, EAlfModuleTestTypeCoreToolkitDrawWindow ); \
        AMT_MAP_APPEND_AND_LINK_IF( aVisual, iIntMap, AMT_MAP_CPTR_TO_KEY_CAST( aVisual ), aClientSideId, 0, EAlfModuleTestTypeCoreToolkitDrawFromRenderBuffer ); \
        \
        AMT_MAP_INC_VALUE( iIntMap, aClientSideId, EAlfModuleTestTypeBridgeCreateWindow ); \
        \
        AMT_MAP_APPEND( iBoolMap, aClientSideId, ETrue, EAlfModuleTestTypeBridgeCreateWindow ); \
        AMT_MAP_APPEND( iBoolMap, aClientSideId, EFalse, EAlfModuleTestTypeBridgeVisualVisibility ); \
        AMT_MAP_APPEND_LINK_IF( aVisual, iBoolMap, AMT_MAP_CPTR_TO_KEY_CAST( aVisual ), aClientSideId, EAlfModuleTestTypeBridgeVisualVisibility ); \
        AMT_MAP_APPEND( iBoolMap, aClientSideId, EFalse, EAlfModuleTestTypeBridgeReleaseWindow ); \
        AMT_MAP_APPEND_LINK( iBoolMap, aWindowNodeId, aClientSideId, EAlfModuleTestTypeBridgeReleaseWindow )
        
#define AMT_MAP_BRIDGE_CREATE_CONTROL_GROUP() \
        AMT_MAP_APPEND_AND_LINK( iIntMap, aWindowGroupNodeId, aClientWindowGroupId, 0, EAlfModuleTestTypeBridgeCreateWindowGroup ); \
        AMT_MAP_APPEND_AND_LINK( iIntMap, aWindowGroupNodeId, aClientWindowGroupId, 0, EAlfModuleTestTypeBridgeReleaseWindowGroup ); \
        \
        AMT_MAP_INC_VALUE( iIntMap, aClientWindowGroupId, EAlfModuleTestTypeBridgeCreateWindowGroup )

#define AMT_MAP_BRIDGE_ADD_TEXT_CURSOR() \
        AMT_MAP_APPEND( iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeBridgeChangeTextCursorType ); \
        AMT_MAP_APPEND( iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeBridgeChangeTextCursorClipRect ); \
        AMT_MAP_APPEND( iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeBridgeChangeTextCursorFlag ); \
        AMT_MAP_APPEND( iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, 0, EAlfModuleTestTypeBridgeChangeTextCursorColor )

#define AMT_MAP_BRIDGE_TEXT_CURSOR_CHANGE() \
        AMT_MAP_INC_VALUE_IF( viz, iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeBridgeChangeTextCursorType ); \
        AMT_MAP_INC_VALUE_IF( viz, iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeBridgeChangeTextCursorClipRect ); \
        AMT_MAP_INC_VALUE_IF( viz, iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeBridgeChangeTextCursorFlag ); \
        AMT_MAP_INC_VALUE_IF( viz, iIntMap, AMT_MAP_TEXT_CURSOR_HANDLE, EAlfModuleTestTypeBridgeChangeTextCursorColor )

        
#endif // ALF_MODULE_TEST_DEFINES_H

// End of File
