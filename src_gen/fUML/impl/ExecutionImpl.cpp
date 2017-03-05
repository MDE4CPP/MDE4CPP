#include "ExecutionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include <Parameter.hpp>
#include <ParameterDirectionKind.hpp>
#include <ParameterValue.hpp>
#include "Behavior.hpp"
#include "Classifier.hpp"
#include "FUMLFactory.hpp"

#include "../fUML/impl/ObjectImpl.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionImpl::ExecutionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	m_parameterValues.reset(new std::vector<std::shared_ptr<fUML::ParameterValue>>());
}

ExecutionImpl::~ExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Execution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExecutionImpl::ExecutionImpl(const ExecutionImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_context  = obj.getContext();

	m_locus  = obj.getLocus();

	std::shared_ptr<std::vector<std::shared_ptr<uml::Classifier>>> _types = obj.getTypes();
	this->getTypes()->insert(this->getTypes()->end(), _types->begin(), _types->end());


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<fUML::FeatureValue>>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->push_back(std::shared_ptr<fUML::FeatureValue>(dynamic_cast<fUML::FeatureValue*>(_featureValues->copy())));
	}
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation.reset(dynamic_cast<fUML::ObjectActivation*>(obj.getObjectActivation()->copy()));
	}
	std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>> _parameterValuesList = obj.getParameterValues();
	for(std::shared_ptr<fUML::ParameterValue> _parameterValues : *_parameterValuesList)
	{
		this->getParameterValues()->push_back(std::shared_ptr<fUML::ParameterValue>(dynamic_cast<fUML::ParameterValue*>(_parameterValues->copy())));
	}
}

ecore::EObject *  ExecutionImpl::copy() const
{
	return new ExecutionImpl(*this);
}

std::shared_ptr<ecore::EClass> ExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecution();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ExecutionImpl::execute() 
{
	//generated from body annotation
	
}

std::shared_ptr<uml::Behavior>  ExecutionImpl::getBehavior() 
{
	//generated from body annotation
	return std::dynamic_pointer_cast<uml::Behavior>(this->getTypes()->front());
}

std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>> ExecutionImpl::getOutputParameterValues() 
{
	//generated from body annotation
	std::shared_ptr<std::vector<std::shared_ptr<ParameterValue>>> outputs(new std::vector<std::shared_ptr<ParameterValue>>());

	std::shared_ptr<std::vector<std::shared_ptr<ParameterValue>>> outputParameterValueList = this->getParameterValues();
    for (std::shared_ptr<ParameterValue> parameterValue : *outputParameterValueList)
    {
    	std::shared_ptr<uml::Parameter> parameter = parameterValue->getParameter();
        if((parameter->getDirection() == uml::ParameterDirectionKind::INOUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::OUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::RETURN))
        {
            outputs->push_back(parameterValue);
        }
    }

    return outputs;
}

std::shared_ptr<fUML::ParameterValue>  ExecutionImpl::getParameterValue(std::shared_ptr<uml::Parameter>  parameter) 
{
	//generated from body annotation
	std::shared_ptr<ParameterValue> parameterValue = nullptr;

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>> list = this->getParameterValues();
	std::vector<std::shared_ptr<fUML::ParameterValue>>::iterator it = std::find_if(list->begin(), list->end(), [parameter] (std::shared_ptr<ParameterValue> p) { return p->getParameter() == parameter; } );
    if(it!= this->getParameterValues()->end() )
    {
        parameterValue  = *it;
    }
    return parameterValue;
}

std::shared_ptr<fUML::Value>  ExecutionImpl::new_() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExecutionImpl::setParameterValue(std::shared_ptr<fUML::ParameterValue>  parameterValue) 
{
	//generated from body annotation
	std::shared_ptr<ParameterValue> existingParameterValue = this->getParameterValue(parameterValue->getParameter());

	if (existingParameterValue == nullptr)
	{
		this->getParameterValues()->push_back(parameterValue);
	}
	else
	{
		existingParameterValue->getValues()->clear(); // memory Leak
		auto vec = parameterValue->getValues();
		existingParameterValue->getValues()->insert(existingParameterValue->getValues()->end(),vec->begin(),vec->end());
	}
}

void ExecutionImpl::terminate() 
{
	//generated from body annotation
	return;
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Object> ExecutionImpl::getContext() const
{
//assert(m_context);
    return m_context;
}
void ExecutionImpl::setContext(std::shared_ptr<fUML::Object> _context)
{
    m_context = _context;
}

std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>> ExecutionImpl::getParameterValues() const
{

    return m_parameterValues;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExecutionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTION_CONTEXT:
			return getContext(); //384
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //380
		case FUMLPackage::EXTENSIONALVALUE_LOCUS:
			return getLocus(); //381
		case FUMLPackage::OBJECT_OBJECTACTIVATION:
			return getObjectActivation(); //383
		case FUMLPackage::EXECUTION_PARAMETERVALUES:
			return getParameterValues(); //385
		case FUMLPackage::OBJECT_TYPES:
			return getTypes(); //382
	}
	return boost::any();
}
