#include "ExecutorImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "Object.hpp"
#include "FUMLFactory.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExecutorImpl::ExecutorImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

ExecutorImpl::~ExecutorImpl()
{
	
}

ExecutorImpl::ExecutorImpl(const ExecutorImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();


	//clone containt lists
}

ecore::EObject *  ExecutorImpl::copy() const
{
	return new ExecutorImpl(*this);
}

ecore::EClass* ExecutorImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutor();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::Value *  ExecutorImpl::evaluate(uml::ValueSpecification *  specification) 
{
	//generated from body annotation
	    return this->getLocus()->getFactory()->createEvaluation(specification)->evaluate();
}

std::vector<fUML::ParameterValue * > *  ExecutorImpl::execute(uml::Behavior *  behavior,fUML::Object *  context,std::vector<fUML::ParameterValue * > *  inputs) 
{
	//generated from body annotation
	Execution * execution = this->getLocus()->getFactory()->createExecution(behavior, context);

    for(fUML::ParameterValue * parameterValue : *inputs )
    {
        execution->setParameterValue(parameterValue);
    }

    execution->execute();
    std::vector<ParameterValue * > * outputValues = execution->getOutputParameterValues();
    execution->destroy();

    return outputValues;
}

fUML::Reference *  ExecutorImpl::start(uml::Class *  type,std::vector<fUML::ParameterValue * > *  inputs) 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[start] Starting " << typeid(type).name() <<"..."<<std::endl;)

    fUML::Object* object = this->getLocus()->instantiate(type);

    DEBUG_MESSAGE(std::cout<<"[start] Object = " << object<<std::endl;)
    object->startBehavior(type,inputs);

    Reference* reference = fUML::FUMLFactory::eInstance()->createReference();
    reference->setReferent(object);
    return reference;
}

//*********************************
// References
//*********************************
fUML::Locus *  ExecutorImpl::getLocus() const
{
	
	return m_locus;
}
void ExecutorImpl::setLocus(fUML::Locus *  _locus)
{
	m_locus = _locus;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExecutorImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTOR_LOCUS:
			return getLocus(); //20
	}
	return boost::any();
}
