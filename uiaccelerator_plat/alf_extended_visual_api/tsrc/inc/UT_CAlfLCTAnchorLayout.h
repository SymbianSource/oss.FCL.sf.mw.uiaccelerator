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


#ifndef __UT_CAlfLCTAnchorLayout_H__
#define __UT_CAlfLCTAnchorLayout_H__

//  EXTERNAL INCLUDES
#include <CEUnitTestSuiteClass.h>

//  INTERNAL INCLUDES


//  FORWARD DECLARATIONS
class CAlfEnv;
class CAlfControl;
class CAlfLCTAnchorLayout;

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
NONSHARABLE_CLASS( UT_CAlfLCTAnchorLayout )
     : public CEUnitTestSuiteClass
    {
    public:     // Constructors and destructors

        /**
         * Two phase construction
         */
        static UT_CAlfLCTAnchorLayout* NewL();
        static UT_CAlfLCTAnchorLayout* NewLC();
        /**
         * Destructor
         */
        ~UT_CAlfLCTAnchorLayout();

    private:    // Constructors and destructors

        UT_CAlfLCTAnchorLayout();
        void ConstructL();

    private:    // New methods

         void SetupL();
         void Teardown();
         void UT_CAlfLCTAnchorLayout_CAlfLCTAnchorLayoutL();
         void UT_CAlfLCTAnchorLayout_ConstructLL();
         void UT_CAlfLCTAnchorLayout_RemoveAndDestroyAllDL();
         void UT_CAlfLCTAnchorLayout_SetAnchors();
 
    public:    // Data
    
        CAlfEnv* iEnv;
        CAlfControl* iControl;
        CAlfLCTAnchorLayout* iLayout;

        EUNIT_DECLARE_TEST_TABLE; 

    };

#endif      //  __UT_CAlfLCTAnchorLayout_H__

// End of file
