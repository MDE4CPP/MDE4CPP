#include "cute.h"
#include "Calculators/Calculators_TestSuite.hpp"
//#include "Calculators/impl/CalculatorsPackageImpl.hpp"

//testCodeGen.includes




cute::suite make_suite_Calculators_TestSuite() {

	cute::suite s { };

	return s;
}

bool runCalculators_TestSuiteSubTests( cute::runner<cute::xml_listener<cute::ide_listener<cute::null_listener> > > runner ) {

	bool success = true;

	return success;
}
