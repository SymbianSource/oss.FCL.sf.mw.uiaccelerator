/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies).
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


#ifndef __UT_CAlfLCTGridLayout_H__
#define __UT_CAlfLCTGridLayout_H__

//  EXTERNAL INCLUDES
#include <CEUnitTestSuiteClass.h>

//  INTERNAL INCLUDES


//  FORWARD DECLARATIONS
class CAlfEnv;
class CAlfControl;
class CAlfLCTGridLayout;

#include <e32def.h>
#ifndef NONSHARABLE_CLASS
    #define NONSHARABLE_CLASS(x) class x
#endif

//  CLASS DEFINITION
/**
 *
 * EUnitWizard generated test class. 
 *
 */
NONSHARABLE_CLASS( UT_CAlfLCTGridLayout )
     : public CEUnitTestSuiteClass
    {
    public:     // Constructors and destructors

        /**
         * Two phase construction
         */
        static UT_CAlfLCTGridLayout* NewL();
        static UT_CAlfLCTGridLayout* NewLC();
        /**
         * Destructor
         */
        ~UT_CAlfLCTGridLayout();

    private:    // Constructors and destructors

        UT_CAlfLCTGridLayout();
        void ConstructL();

    private:    // New methods

         void SetupL();
         void Teardown();
         void UT_CAlfLCTGridLayout_CAlfLCTGridLayoutL();
         void UT_CAlfLCTGridLayout_ConstructLL();
         void UT_CAlfLCTGridLayout_RemoveAndDestroyAllDL();
         void UT_CAlfLCTGridLayout_SetColsAndRows();
 
    public:    // Data
    
        CAlfEnv* iEnv;
        CAlfControl* iControl;
        CAlfLCTGridLayout* iLayout;

        EUNIT_DECLARE_TEST_TABLE; 

    };

#endif      //  __UT_CAlfLCTGridLayout_H__

// End of file
