#include "fUML/impl/ExecutorImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/Object.hpp"
#include "fuml/FUMLFactory.hpp"

//Forward declaration includes
#include "uml/Behavior.hpp"

#include "uml/Class.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Object.hpp"

#include "fUML/ParameterValue.hpp"

#include "fUML/Reference.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"


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
	//References
	

	//Init references
	
}

ExecutorImpl::~ExecutorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Executor "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ExecutorImpl::ExecutorImpl(const ExecutorImpl & obj):ExecutorImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Executor "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ExecutorImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExecutorImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExecutorImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutor();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> ExecutorImpl::evaluate(std::shared_ptr<uml::ValueSpecification>  specification) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return this->getLocus()->getFactory()->createEvaluation(specification)->evaluate();
	//end of body
}

std::shared_ptr<Bag<fUML::ParameterValue> > ExecutorImpl::execute(std::shared_ptr<uml::Behavior>  behavior,std::shared_ptr<fUML::Object>  context,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Execution> execution = this->getLocus()->getFactory()->createExecution(behavior, context);

    if(nullptr == execution)
    {
        std::cerr << "[execute] Execution is null" << std::endl;
        return nullptr;
    }

    for(std::shared_ptr<fUML::ParameterValue> parameterValue : *inputs )
    {
        execution->setParameterValue(parameterValue);
    }

    execution->execute();
    std::shared_ptr<Bag<ParameterValue> > outputValues = execution->getOutputParameterValues();
    execution->destroy();

    return outputValues;
	//end of body
}

std::shared_ptr<fUML::Reference> ExecutorImpl::start(std::shared_ptr<uml::Class>  type,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[start] Starting " << typeid(type).name() <<"..."<<std::endl;)

	std::shared_ptr<fUML::Object> object = this->getLocus()->instantiate(type);

    DEBUG_MESSAGE(std::cout<<"[start] Object = " << object<<std::endl;)
    object->startBehavior(type,inputs);

    std::shared_ptr<Reference> reference(fUML::FUMLFactory::eInstance()->createReference());
    reference->setReferent(object);
    return reference;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Locus > ExecutorImpl::getLocus() const
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


std::shared_ptr<ecore::EObject> ExecutorImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExecutorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTOR_LOCUS:
			return getLocus(); //20
	}
	return boost::any();
}

void ExecutorImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTOR_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //20
			break;
		}
	}
}
