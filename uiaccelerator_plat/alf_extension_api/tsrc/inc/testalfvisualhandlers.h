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


#ifndef C_TESTALFVISUALHANDLERS_H
#define C_TESTALFVISUALHANDLERS_H

// INCLUDE FILES
#include <alf/alfvisualhandlers.h>

/*This class test protected functions of CAlfVisualHandler*/
class CTestCAlfVisualHandler: public CAlfVisualHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfVisualHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfVisualHandler();
    /**
     * TestProtected test protected functions of CAlfVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtected( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfTextVisualHandler*/
class CTestCAlfTextVisualHandler: public CAlfTextVisualHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfTextVisualHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfTextVisualHandler();
    /**
     * TestProtected test protected functions of CAlfTextVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtected( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfLCTTextVisualHandler*/
class CTestCAlfLCTTextVisualHandler: public CAlfLCTTextVisualHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfLCTTextVisualHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfLCTTextVisualHandler();
    /**
     * TestProtected test protected functions of CAlfLCTTextVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtected( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfImageVisualHandler*/
class CTestCAlfImageVisualHandler: public CAlfImageVisualHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfImageVisualHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfImageVisualHandler();
    /**
     * TestProtected test protected functions of CAlfImageVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtected( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfLineVisualHandler*/
class CTestCAlfLineVisualHandler: public CAlfLineVisualHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfLineVisualHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfLineVisualHandler();
    /**
     * TestProtected test protected functions of CAlfLineVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtected( CStifItemParser& aItem );
    };

/*This class test protected functions of CAlfMeshVisualHandler*/
class CTestCAlfMeshVisualHandler: public CAlfMeshVisualHandler
    {
public:
    /*
     * Constructor
     * */
    CTestCAlfMeshVisualHandler( MAlfInterfaceProvider& aResolver );
    
    /*
     * DeConstructor
     * */
    ~CTestCAlfMeshVisualHandler();
    /**
     * TestProtected test protected functions of CAlfMeshVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestProtected( CStifItemParser& aItem );
    };

#endif  // C_TESTALFVISUALHANDLERS_H

