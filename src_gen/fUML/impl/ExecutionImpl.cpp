#include "fUML/impl/ExecutionImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include <uml/Parameter.hpp>
#include <uml/ParameterDirectionKind.hpp>
#include <fuml/ParameterValue.hpp>
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "fuml/FUMLFactory.hpp"

#include "fuml/impl/ObjectImpl.hpp"


//Forward declaration includes
#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Object.hpp"

#include "fUML/ObjectActivation.hpp"

#include "uml/Parameter.hpp"

#include "fUML/ParameterValue.hpp"

#include "fUML/Value.hpp"


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
	//References
	

		m_parameterValues.reset(new Bag<fUML::ParameterValue>());
	
	

	//Init references
	

	
	
}

ExecutionImpl::~ExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Execution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ExecutionImpl::ExecutionImpl(const ExecutionImpl & obj):ExecutionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Execution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_context  = obj.getContext();

	m_locus  = obj.getLocus();

	std::shared_ptr< Bag<uml::Classifier> > _types = obj.getTypes();
	m_types.reset(new Bag<uml::Classifier>(*(obj.getTypes().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(std::dynamic_pointer_cast<fUML::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation = std::dynamic_pointer_cast<fUML::ObjectActivation>(obj.getObjectActivation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_objectActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ParameterValue>> _parameterValuesList = obj.getParameterValues();
	for(std::shared_ptr<fUML::ParameterValue> _parameterValues : *_parameterValuesList)
	{
		this->getParameterValues()->add(std::shared_ptr<fUML::ParameterValue>(std::dynamic_pointer_cast<fUML::ParameterValue>(_parameterValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_parameterValues" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  ExecutionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExecutionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecution();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ExecutionImpl::execute() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	//end of body
}

std::shared_ptr<uml::Behavior> ExecutionImpl::getBehavior() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::dynamic_pointer_cast<uml::Behavior>(this->getTypes()->front());
	//end of body
}

std::shared_ptr<Bag<fUML::ParameterValue> > ExecutionImpl::getOutputParameterValues() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<ParameterValue> > outputs(new Bag<ParameterValue>());

	std::shared_ptr<Bag<ParameterValue> > outputParameterValueList = this->getParameterValues();
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
	//end of body
}

std::shared_ptr<fUML::ParameterValue> ExecutionImpl::getParameterValue(std::shared_ptr<uml::Parameter>  parameter) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<ParameterValue> parameterValue = nullptr;

	std::shared_ptr<Bag<fUML::ParameterValue> > list = this->getParameterValues();
	std::vector<std::shared_ptr<fUML::ParameterValue>>::iterator it = std::find_if(list->begin(), list->end(), [parameter] (std::shared_ptr<ParameterValue> p) { return p->getParameter() == parameter; } );
    if(it!= this->getParameterValues()->end() )
    {
        parameterValue  = *it;
    }
    return parameterValue;
	//end of body
}

std::shared_ptr<fUML::Value> ExecutionImpl::new_() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExecutionImpl::setParameterValue(std::shared_ptr<fUML::ParameterValue>  parameterValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//end of body
}

void ExecutionImpl::terminate() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Object > ExecutionImpl::getContext() const
{
//assert(m_context);
    return m_context;
}
void ExecutionImpl::setContext(std::shared_ptr<fUML::Object> _context)
{
    m_context = _context;
}

std::shared_ptr< Bag<fUML::ParameterValue> > ExecutionImpl::getParameterValues() const
{

    return m_parameterValues;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> ExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void ExecutionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTION_CONTEXT:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Object> _context = boost::any_cast<std::shared_ptr<fUML::Object>>(newValue);
			setContext(_context); //384
			break;
		}
		case FUMLPackage::EXTENSIONALVALUE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //381
			break;
		}
		case FUMLPackage::OBJECT_OBJECTACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ObjectActivation> _objectActivation = boost::any_cast<std::shared_ptr<fUML::ObjectActivation>>(newValue);
			setObjectActivation(_objectActivation); //383
			break;
		}
	}
}
