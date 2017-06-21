#include "CoaIsOddExecution.hpp"
#include <iostream>
#include <memory>
#include <cassert>
#include "ParameterValue.hpp"


// PrimeChecker <- Class name
// isOdd <- Operation name
// fbIsOdd <- Method name
// Boolean is not a pointer
#include "BooleanValue.hpp"

#include "PrimeChecker.hpp"
#include "PrimeCheckerExecution.hpp"
 
using namespace CalcModel;

CoaIsOddExecution::CoaIsOddExecution()
{
}

CoaIsOddExecution::~CoaIsOddExecution()
{
}


CoaIsOddExecution::CoaIsOddExecution(CoaIsOddExecution &obj):
	OpaqueBehaviorExecutionImpl(obj)
{
}

ecore::EObject* CoaIsOddExecution::copy()
{
    return new CoaIsOddExecution(*this);
}

void CoaIsOddExecution::doBody(std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>> inputParameters, std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>> outputParameters)
{
    DEBUG_MESSAGE(std::cout<<"Printing from "<< this->getBehavior()->getName();)
    DEBUG_MESSAGE(std::cout<<"__________________________";)

   	bool isOdd;


	std::shared_ptr<CalcModel::PrimeChecker> target = std::dynamic_pointer_cast<PrimeCheckerExecution>(this->getContext())->getUmlValue();
    assert(target != nullptr);

    //call assigned operation
	 isOdd =   target->isOdd();
	
	
	//set out/result parameter
    std::shared_ptr<fUML::BooleanValue> isOddValue(fUML::FUMLFactory::eInstance()->createBooleanValue());
 	isOddValue->setValue(isOdd);
    outputParameters->at(0)->getValues()->push_back(isOddValue);
	
	//set InOut parameters
}
