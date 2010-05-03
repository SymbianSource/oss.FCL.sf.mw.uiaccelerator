/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
*
*/
/**
 * @note Contents of this file are provided only if module test hooks are set on.
 */

#include "alfmoduletestconf.h"
#ifdef USE_MODULE_TEST_HOOKS_FOR_ALF

#ifndef ALFMODULETESTTYPE_H
#define ALFMODULETESTTYPE_H

/**
 * TAlfModuleTestType specifies recognized test types.
 */
enum TAlfModuleTestType
    {
    // Do not use this value when creating item.
    EAlfModuleTestTypeNone,
    
    // Render stage component specific tests
    EAlfModuleTestTypeRenderStageCreateLayer,
    EAlfModuleTestTypeRenderStageReleaseLayer,
    EAlfModuleTestTypeRenderStageCreateWindow,
    EAlfModuleTestTypeRenderStageReleaseWindow,    
    EAlfModuleTestTypeRenderStageCreateWindowGroup,
    EAlfModuleTestTypeRenderStageReleaseWindowGroup,
    EAlfModuleTestTypeRenderStageActiveWindow,
    EAlfModuleTestTypeRenderStageChangeWindowSize,
    EAlfModuleTestTypeRenderStageChangeWindowPosition,
    EAlfModuleTestTypeRenderStageChangeWindowVisibility,
    EAlfModuleTestTypeRenderStageChangeTextCursorType,
    EAlfModuleTestTypeRenderStageChangeTextCursorClipRect,
    EAlfModuleTestTypeRenderStageChangeTextCursorFlag,
    EAlfModuleTestTypeRenderStageChangeTextCursorColor,
    
    // Streamer hierarchy model component specific tests
    EAlfModuleTestTypeHierarchyModelCreateLayer,
    EAlfModuleTestTypeHierarchyModelReleaseLayer,
    EAlfModuleTestTypeHierarchyModelCreateWindow,
    EAlfModuleTestTypeHierarchyModelReleaseWindow,    
    EAlfModuleTestTypeHierarchyModelCreateWindowGroup,
    EAlfModuleTestTypeHierarchyModelReleaseWindowGroup,
    EAlfModuleTestTypeHierarchyModelActiveWindow,
    EAlfModuleTestTypeHierarchyModelChangeWindowSize,
    EAlfModuleTestTypeHierarchyModelChangeWindowPosition,
    EAlfModuleTestTypeHierarchyModelChangeWindowVisibility,
    EAlfModuleTestTypeHierarchyModelChangeTextCursorType,
    EAlfModuleTestTypeHierarchyModelChangeTextCursorClipRect,
    EAlfModuleTestTypeHierarchyModelChangeTextCursorFlag,
    EAlfModuleTestTypeHierarchyModelChangeTextCursorColor,
    
    // Server bridge component specific tests
    EAlfModuleTestTypeBridgeCreateLayer,
    EAlfModuleTestTypeBridgeReleaseLayer,
    EAlfModuleTestTypeBridgeCreateWindow,
    EAlfModuleTestTypeBridgeReleaseWindow,    
    EAlfModuleTestTypeBridgeCreateWindowGroup,
    EAlfModuleTestTypeBridgeReleaseWindowGroup,
    EAlfModuleTestTypeBridgeActiveWindow,
    EAlfModuleTestTypeBridgeChangeWindowSize,
    EAlfModuleTestTypeBridgeChangeWindowPosition,
    EAlfModuleTestTypeBridgeChangeWindowVisibility,
    EAlfModuleTestTypeBridgeChangeTextCursorType,
    EAlfModuleTestTypeBridgeChangeTextCursorClipRect,
    EAlfModuleTestTypeBridgeChangeTextCursorFlag,
    EAlfModuleTestTypeBridgeChangeTextCursorColor,
    EAlfModuleTestTypeBridgeVisualVisibility,
    
    // Core toolkit component specific tests
    EAlfModuleTestTypeCoreToolkitDrawWindow,
    EAlfModuleTestTypeCoreToolkitDrawFromRenderBuffer,
    
    // Do not use this value when creating item.
    // This is just meant for Find operations when all tests are accepted.
    EAlfModuleTestTypeAll
    };

#endif // ALFMODULETESTTYPE_H

#endif // USE_MODULE_TEST_HOOKS_FOR_ALF

// End of File
