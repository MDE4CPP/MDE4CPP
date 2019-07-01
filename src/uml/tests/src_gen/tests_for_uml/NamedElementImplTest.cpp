#include "tests_for_uml/NamedElementImplTest.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>

#include "cute.h"
#include "helper/TestSuiteCountHelper.hpp"
#include "helper/TestSuiteMainHelper.hpp"
#include "helper/TestSuiteMemoryHelper.hpp"
#include "helper/TestSuiteTimeHelper.hpp"

//Included from operation "separatorTest"
#include "uml/UmlFactory.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Class.hpp"
#include "uml/Model.hpp"

//*********************************
// Tests
//*********************************

void NamedElementImplTest__allNamespacesTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		ASSERTM( "Test not implemented", false );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void NamedElementImplTest__getQualifiedNameTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		ASSERTM( "Test not implemented", false );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

void NamedElementImplTest__separatorTest() {

	TestSuiteMainHelper::CollectTestStartStatistics();
	{
		// Implemented as Function behaviour separatorTestFB

        /*std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
        std::shared_ptr<uml::Class> aClass = factory->createClass();
        aClass->setName( "test" );*/
		std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();
		    //std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		    std::shared_ptr<uml::Model> p = factory->createModel();
		    p->setName("Model");

		    std::shared_ptr<uml::Class> c = factory->createClass_in_Package(p);
		    c->setName("Class1");
        //std::shared_ptr<uml::NamedElement> namedElement = std::dynamic_pointer_cast<uml::NamedElement>( aClass );


        ASSERT_EQUALM( "seperator ist not ::", c->separator(), "::" );

        //std::shared_ptr<uml::NamedElement> named_element = std:shared_polymorphic_downcast<uml::NamedElement>( factory->createClass() );

        //ASSERT_EQUALM( "seperator ist not ::", named_element->separator(), "::" );
	}
	TestSuiteMainHelper::CollectTestEndStatistics();
	TestSuiteMainHelper::PrintTestsStatistics();
	TestSuiteCountHelper::IncNumOfPassedTests();
}

//*********************************
// Make Class Test Suite
//*********************************

cute::suite make_suite_NamedElementImplTest() {

	cute::suite s { };

	s += CUTE( NamedElementImplTest__allNamespacesTest );
	s += CUTE( NamedElementImplTest__getQualifiedNameTest );
	s += CUTE( NamedElementImplTest__separatorTest );
	return s;
}

