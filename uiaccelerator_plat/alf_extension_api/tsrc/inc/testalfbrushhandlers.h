/*
* Copyright (c) 2002 - 2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  this project test api in alf_extension_api
 *
*/


#ifndef C_TESTALFBRUSHHANDLERS_H
#define C_TESTALFBRUSHHANDLERS_H

// INCLUDE FILES
#include <alf/alfbrushhandlers.h>
#include <testscripterinternal.h>

/*This class test protected functions of CAlfBrushHandler*/
class CTestCAlfBrushHandler: public CAlfBrushHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfBrushHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfBrushHandler();
    /*
     * 2rd-Constructor
     * */
    void ConstructL();
    /**
     * TestBrushHandlerForMAlfExtensionL test functions from  MAlfExtension
     * of CAlfBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestBrushHandlerForMAlfExtensionL( CStifItemParser& aItem );
    /**
     * TestBrushHandlerForOthers test other functions of CAlfBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestBrushHandlerForOthers( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfBorderBrushHandler*/
class CTestCAlfBorderBrushHandler: public CAlfBorderBrushHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfBorderBrushHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfBorderBrushHandler();
    /**
     * TestProtectedL test protected functions
     * of CAlfBorderBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    TInt TestProtectedL( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfImageBrushHandler*/
class CTestCAlfImageBrushHandler: public CAlfImageBrushHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfImageBrushHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfImageBrushHandler();
    /**
     * TestProtectedL test protected functions
     * of CAlfImageBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    TInt TestProtectedL( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfShadowBorderBrushHandler*/
class CTestCAlfShadowBorderBrushHandler: public CAlfShadowBorderBrushHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfShadowBorderBrushHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfShadowBorderBrushHandler();
    /**
     * TestProtectedL test protected functions
     * of CAlfShadowBorderBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    TInt TestProtectedL( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfDropShadowBrushHandler*/
class CTestCAlfDropShadowBrushHandler: public CAlfDropShadowBrushHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfDropShadowBrushHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfDropShadowBrushHandler();
    /**
     * TestProtectedL test protected functions
     * of CAlfDropShadowBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    TInt TestProtectedL( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfGradientBrushHandler*/
class CTestCAlfGradientBrushHandler: public CAlfGradientBrushHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfGradientBrushHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfGradientBrushHandler();
    /**
     * TestProtectedL test protected functions
     * of CAlfGradientBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    TInt TestProtectedL( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfFrameBrushHandler*/
class CTestCAlfFrameBrushHandler: public CAlfFrameBrushHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfFrameBrushHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfFrameBrushHandler();
    /**
     * TestProtectedL test protected functions
     * of CAlfFrameBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    TInt TestProtectedL( CStifItemParser& aItem );
    };

#endif  // C_TESTALFBRUSHHANDLERS_H

