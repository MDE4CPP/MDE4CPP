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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

ExecutorImpl::~ExecutorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Executor "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
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

std::shared_ptr<ecore::EClass> ExecutorImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutor();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value>  ExecutorImpl::evaluate(std::shared_ptr<uml::ValueSpecification>  specification) 
{
	//generated from body annotation
	    return this->getLocus()->getFactory()->createEvaluation(specification)->evaluate();
}

std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>> ExecutorImpl::execute(std::shared_ptr<uml::Behavior>  behavior,std::shared_ptr<fUML::Object>  context,std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>>  inputs) 
{
	//generated from body annotation
	std::shared_ptr<Execution> execution = this->getLocus()->getFactory()->createExecution(behavior, context);

    for(std::shared_ptr<fUML::ParameterValue> parameterValue : *inputs )
    {
        execution->setParameterValue(parameterValue);
    }

    execution->execute();
    std::shared_ptr<std::vector<std::shared_ptr<ParameterValue>>> outputValues = execution->getOutputParameterValues();
    execution->destroy();

    return outputValues;
}

std::shared_ptr<fUML::Reference>  ExecutorImpl::start(std::shared_ptr<uml::Class>  type,std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>>  inputs) 
{
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[start] Starting " << typeid(type).name() <<"..."<<std::endl;)

	std::shared_ptr<fUML::Object> object = this->getLocus()->instantiate(type);

    DEBUG_MESSAGE(std::cout<<"[start] Object = " << object<<std::endl;)
    object->startBehavior(type,inputs);

    std::shared_ptr<Reference> reference(fUML::FUMLFactory::eInstance()->createReference());
    reference->setReferent(object);
    return reference;
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Locus> ExecutorImpl::getLocus() const
{

    return m_locus;
}
void ExecutorImpl::setLocus(std::shared_ptr<fUML::Locus> _locus)
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
