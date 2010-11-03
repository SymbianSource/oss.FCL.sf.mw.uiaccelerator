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


#ifndef C_TESTALFLAYOUTHANDLERS_H
#define C_TESTALFLAYOUTHANDLERS_H

// INCLUDE FILES
#include <alf/alflayouthandlers.h>


/*This class test protected functions of CAlfLayoutHandler*/
class CTestCAlfLayoutHandler: public CAlfLayoutHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfLayoutHandler( MAlfInterfaceProvider& aResolver );
    /*
     * DeConstructor
     * */
    ~CTestCAlfLayoutHandler();
    /**
     * TestProtect test protected function
     * of CAlfLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtect( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfAnchorLayoutHandler*/
class CTestCAlfAnchorLayoutHandler: public CAlfAnchorLayoutHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfAnchorLayoutHandler( MAlfInterfaceProvider& aResolver );
    /*
     * DeConstructor
     * */
    ~CTestCAlfAnchorLayoutHandler();
    /**
     * TestProtect test protected function
     * of CAlfLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtect( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfLCTAnchorLayoutHandler*/
class CTestCAlfLCTAnchorLayoutHandler: public CAlfLCTAnchorLayoutHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfLCTAnchorLayoutHandler( MAlfInterfaceProvider& aResolver );
    /*
     * DeConstructor
     * */
    ~CTestCAlfLCTAnchorLayoutHandler();
    /**
     * TestProtect test protected function
     * of CAlfLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtect( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfGridLayoutHandler*/
class CTestCAlfGridLayoutHandler: public CAlfGridLayoutHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfGridLayoutHandler( MAlfInterfaceProvider& aResolver );
    /*
     * DeConstructor
     * */
    ~CTestCAlfGridLayoutHandler();
    /**
     * TestProtect test protected function
     * of CAlfLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtect( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfLCTGridLayoutHandler*/
class CTestCAlfLCTGridLayoutHandler: public CAlfLCTGridLayoutHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfLCTGridLayoutHandler( MAlfInterfaceProvider& aResolver );
    /*
     * DeConstructor
     * */
    ~CTestCAlfLCTGridLayoutHandler();
    /**
     * TestProtect test protected function
     * of CAlfLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtect( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfDeckLayoutHandler*/
class CTestCAlfDeckLayoutHandler: public CAlfDeckLayoutHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfDeckLayoutHandler( MAlfInterfaceProvider& aResolver );
    /*
     * DeConstructor
     * */
    ~CTestCAlfDeckLayoutHandler();
    /**
     * TestProtect test protected function
     * of CAlfLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtect( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfFlowLayoutHandler*/
class CTestCAlfFlowLayoutHandler: public CAlfFlowLayoutHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfFlowLayoutHandler( MAlfInterfaceProvider& aResolver );
    /*
     * DeConstructor
     * */
    ~CTestCAlfFlowLayoutHandler();
    /**
     * TestProtect test protected function
     * of CAlfLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtect( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfCurvePathLayoutHandler*/
class CTestCAlfCurvePathLayoutHandler: public CAlfCurvePathLayoutHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfCurvePathLayoutHandler( MAlfInterfaceProvider& aResolver );
    /*
     * DeConstructor
     * */
    ~CTestCAlfCurvePathLayoutHandler();
    /**
     * TestProtect test protected function
     * of CAlfLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtect( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfViewportLayoutHandler*/
class CTestCAlfViewportLayoutHandler: public CAlfViewportLayoutHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfViewportLayoutHandler( MAlfInterfaceProvider& aResolver );
    /*
     * DeConstructor
     * */
    ~CTestCAlfViewportLayoutHandler();
    /**
     * TestProtect test protected function
     * of CAlfLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtect( CStifItemParser& aItem );
    };

#endif  // C_TESTALFLAYOUTHANDLERS_H

