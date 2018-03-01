#include "fUMLMultiplePinsExec/IstEndeExecution.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <cassert>
#include <iostream>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp" 
#include "fUML/ParameterValue.hpp"



#include "fUML/IntegerValue.hpp"
#include "fUML/BooleanValue.hpp"

using namespace fUMLMultiplePins;

IstEndeExecution::IstEndeExecution()
{
}

IstEndeExecution::~IstEndeExecution()
{
}

IstEndeExecution::IstEndeExecution(const IstEndeExecution &obj)
:OpaqueBehaviorExecutionImpl(obj)
{
}

std::shared_ptr<ecore::EObject> IstEndeExecution::copy() const
{
	std::shared_ptr<ecore::EObject> element(new IstEndeExecution(*this));
	return element;
}

void IstEndeExecution::doBody(std::shared_ptr<Bag<fUML::ParameterValue> > inputParameters, std::shared_ptr<Bag<fUML::ParameterValue> > outputParameters)
{
    DEBUG_MESSAGE(std::cout << "Printing from "<< this->getBehavior()->getName() << std::endl;)
    DEBUG_MESSAGE(std::cout << "__________________________" << std::endl;)

   	int inParam;
   	bool outParam;

    std::shared_ptr<fUML::IntegerValue> inParamValue = std::dynamic_pointer_cast<fUML::IntegerValue>(inputParameters->at(0)->getValues()->front());

	inParam = inParamValue->getValue();


    //Body of the Opaquebehavior
    //Start ---------------------------
		//Function Behaviour from a Call Behavior Action
   		if(inParam>100000)
{
	outParam=true;
}
else
{
	outParam=false;
}
    //End -----------------------------

	//set return / out parameters
    std::shared_ptr<fUML::BooleanValue> outParamValue(fUML::FUMLFactory::eInstance()->createBooleanValue());
 	outParamValue->setValue(outParam);
    outputParameters->at(0)->getValues()->push_back(outParamValue);

	//set InOut parameters
	DEBUG_MESSAGE(std::cout<< "^^^^^ FB istEnde ends its execution ^^^^^" << std::endl;)
}
