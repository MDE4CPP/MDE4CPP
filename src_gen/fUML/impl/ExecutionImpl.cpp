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
	// Reference Members
	//*********************************
	
	if( m_parameterValues == nullptr)
	{
		m_parameterValues = new std::vector<fUML::ParameterValue * >();
	}
}

ExecutionImpl::~ExecutionImpl()
{
	if(m_parameterValues!=nullptr)
	{
		for(auto c :*m_parameterValues)
		{
			delete(c);
			c = 0;
		}
	}
	
}

ExecutionImpl::ExecutionImpl(const ExecutionImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_context  = obj.getContext();

	m_locus  = obj.getLocus();

	std::vector<uml::Classifier * > *  _types = obj.getTypes();
	this->getTypes()->insert(this->getTypes()->end(), _types->begin(), _types->end());


	//clone containt lists
	for(fUML::FeatureValue * 	_featureValues : *obj.getFeatureValues())
	{
		this->getFeatureValues()->push_back(dynamic_cast<fUML::FeatureValue * >(_featureValues->copy()));
	}
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation = dynamic_cast<fUML::ObjectActivation * >(obj.getObjectActivation()->copy());
	}
	for(fUML::ParameterValue * 	_parameterValues : *obj.getParameterValues())
	{
		this->getParameterValues()->push_back(dynamic_cast<fUML::ParameterValue * >(_parameterValues->copy()));
	}
}

ecore::EObject *  ExecutionImpl::copy() const
{
	return new ExecutionImpl(*this);
}

ecore::EClass* ExecutionImpl::eStaticClass() const
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

uml::Behavior *  ExecutionImpl::getBehavior() 
{
	//generated from body annotation
	return dynamic_cast<uml::Behavior * >(this->getTypes()->front());
}

std::vector<fUML::ParameterValue * > *  ExecutionImpl::getOutputParameterValues() 
{
	//generated from body annotation
	 std::vector<ParameterValue* > * outputs = new std::vector<ParameterValue* >();

    for (ParameterValue* parameterValue : * this->getParameterValues() )
    {

        uml::Parameter * parameter = parameterValue->getParameter();
        if((parameter->getDirection() == uml::ParameterDirectionKind::INOUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::OUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::RETURN))
        {
            outputs->push_back(parameterValue);
        }
    }

    return outputs;
}

fUML::ParameterValue *  ExecutionImpl::getParameterValue(uml::Parameter *  parameter) 
{
	//generated from body annotation
	    ParameterValue * parameterValue = nullptr;

    std::vector<fUML::ParameterValue*>* list = this->getParameterValues();
    std::vector<fUML::ParameterValue *>::iterator it = std::find_if(list->begin(), list->end(), [parameter] (ParameterValue * p) { return p->getParameter() == parameter; } );
    if(it!= this->getParameterValues()->end() )
    {
        parameterValue  = *it;
    }
    return parameterValue;
}

fUML::Value *  ExecutionImpl::new_() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExecutionImpl::setParameterValue(fUML::ParameterValue *  parameterValue) 
{
	//generated from body annotation
	ParameterValue * existingParameterValue = this->getParameterValue(parameterValue->getParameter());

if (existingParameterValue == nullptr)
{
	this->getParameterValues()->push_back(parameterValue);
}
else
{
    for ( auto p : *existingParameterValue->getValues()){
        delete p;
    }
    //existingParameterValue->getValues()->clear(); // memory Leak
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
fUML::Object *  ExecutionImpl::getContext() const
{
	//assert(m_context);
	return m_context;
}
void ExecutionImpl::setContext(fUML::Object *  _context)
{
	m_context = _context;
}

std::vector<fUML::ParameterValue * > *  ExecutionImpl::getParameterValues() const
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
