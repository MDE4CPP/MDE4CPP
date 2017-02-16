#include "OpaqueBehaviorExecutionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ParameterValue.hpp"
#include "Behavior.hpp"
#include "Parameter.hpp"
#include "ParameterDirectionKind.hpp"
#include "FUMLFactory.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueBehaviorExecutionImpl::OpaqueBehaviorExecutionImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

OpaqueBehaviorExecutionImpl::~OpaqueBehaviorExecutionImpl()
{
	
}

OpaqueBehaviorExecutionImpl::OpaqueBehaviorExecutionImpl(const OpaqueBehaviorExecutionImpl & obj)
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

ecore::EObject *  OpaqueBehaviorExecutionImpl::copy() const
{
	return new OpaqueBehaviorExecutionImpl(*this);
}

ecore::EClass* OpaqueBehaviorExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getOpaqueBehaviorExecution();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void OpaqueBehaviorExecutionImpl::doBody(std::vector<fUML::ParameterValue * > *  inputParameters,std::vector<fUML::ParameterValue * > *  outputParameters) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OpaqueBehaviorExecutionImpl::execute() 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[execute] Opaque behavior " << this->getBehavior()->getName() << "..."<<std::endl;)

    std::vector<ParameterValue*>* inputs = new std::vector<ParameterValue*>();
    std::vector<ParameterValue*>* outputs = new std::vector<ParameterValue*>();

    for(uml::Parameter * parameter : *this->getBehavior()->getOwnedParameter()) {


        DEBUG_MESSAGE(std::cout<<parameter->getName()<< " Parameter Direction: " << parameter->getDirection()<<std::endl;)
        if ((parameter->getDirection() == uml::ParameterDirectionKind::IN)
                || (parameter->getDirection() == uml::ParameterDirectionKind::INOUT)) {
            inputs->push_back(this->getParameterValue(parameter));
        }

        if ((parameter->getDirection() == uml::ParameterDirectionKind::INOUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::OUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::RETURN)) {
            ParameterValue * parameterValue = fUML::FUMLFactory::eInstance()->createParameterValue();
            parameterValue->setParameter(parameter);

            if(parameter->getDirection() != uml::ParameterDirectionKind::INOUT){
                //Otherwise the input parameter is removed (memory leak).
                this->setParameterValue(parameterValue);
            }

            outputs->push_back(parameterValue);
        }
    }

    this->doBody(inputs, outputs);
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OpaqueBehaviorExecutionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTION_CONTEXT:
			return getContext(); //404
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //400
		case FUMLPackage::EXTENSIONALVALUE_LOCUS:
			return getLocus(); //401
		case FUMLPackage::OBJECT_OBJECTACTIVATION:
			return getObjectActivation(); //403
		case FUMLPackage::EXECUTION_PARAMETERVALUES:
			return getParameterValues(); //405
		case FUMLPackage::OBJECT_TYPES:
			return getTypes(); //402
	}
	return boost::any();
}
