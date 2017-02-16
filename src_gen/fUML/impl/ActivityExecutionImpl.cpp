#include "ActivityExecutionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

#include "Parameter.hpp"
#include <ParameterDirectionKind.hpp>
#include <ParameterValue.hpp>
#include "ForkedToken.hpp"
#include <Execution.hpp>
#include "FUMLFactory.hpp"
#include "Object.hpp"
#include "Execution.hpp"
#include "Activity.hpp"
#include "ActivityParameterNode.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ActivityExecutionImpl::ActivityExecutionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

ActivityExecutionImpl::~ActivityExecutionImpl()
{
	if(m_activationGroup!=nullptr)
	{
		if(m_activationGroup)
		{
			delete(m_activationGroup);
			m_activationGroup = nullptr;
		}
	}
	
}

ActivityExecutionImpl::ActivityExecutionImpl(const ActivityExecutionImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_context  = obj.getContext();

	m_locus  = obj.getLocus();

	std::vector<uml::Classifier * > *  _types = obj.getTypes();
	this->getTypes()->insert(this->getTypes()->end(), _types->begin(), _types->end());


	//clone containt lists
	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = dynamic_cast<fUML::ActivityNodeActivationGroup * >(obj.getActivationGroup()->copy());
	}
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

ecore::EObject *  ActivityExecutionImpl::copy() const
{
	return new ActivityExecutionImpl(*this);
}

ecore::EClass* ActivityExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityExecution();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ActivityExecutionImpl::execute() 
{
	//generated from body annotation
	uml::Activity * activity = dynamic_cast<uml::Activity*> (this->getTypes()->front());

    if(activity != nullptr)
    {
        DEBUG_MESSAGE(std::cout<<"[execute] Activity " << activity->getName()<< "..."<<std::endl;)
        DEBUG_MESSAGE(std::cout<<"[event] Execute activity=" + activity->getName()<<std::endl;)

        this->setActivationGroup(fUML::FUMLFactory::eInstance()->createActivityNodeActivationGroup());
        this->getActivationGroup()->setActivityExecution(this);
        this->getActivationGroup()->activate(activity->getNode(), activity->getEdge());

        DEBUG_MESSAGE(std::cout<<"[execute] Getting output parameter node activations..."<<std::endl;)

        for(ActivityParameterNodeActivation*  outputActivation : *this->getActivationGroup()->getOutputParameterNodeActivations() )
        {
            ParameterValue * parameterValue = fUML::FUMLFactory::eInstance()->createParameterValue();
            uml::ActivityParameterNode* activityParameterNode = dynamic_cast<uml::ActivityParameterNode*> (outputActivation->getNode());

            if(activityParameterNode != nullptr)
            {
                parameterValue->setParameter(activityParameterNode->getParameter());

                for(Token * token : *outputActivation->getTokens())
                {
                    Value * value = nullptr;
                    ObjectToken *obTok = dynamic_cast<ObjectToken*>(token);
                    if(obTok != nullptr){
                        DEBUG_MESSAGE(std::cout<<"Getting the value of a object token"<<std::endl;)
                        value = obTok->getValue();
                    }
                    else
                    {
                        ForkedToken *ft = dynamic_cast<ForkedToken*>(token);
                        if(ft != nullptr)
                        {
                            DEBUG_MESSAGE(std::cout<<"Getting the value of a forked token"<<std::endl;)
                            value = ft->getBaseToken()->getValue();
                        }
                        else
                        {
                            std::cerr<<"Unsupported token tpe."<<std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }

                    if (value != nullptr) {
                        parameterValue->getValues()->push_back(value);
                        DEBUG_MESSAGE(std::cout<<"[event] Output activity=" << activity->getName() << " parameter=" << parameterValue->getParameter()->getName() << " value=" << value->toString()<<std::endl;)
                    }
                }
                this->setParameterValue(parameterValue);

            }
        }

        DEBUG_MESSAGE(std::cout<<"[execute] Activity " << activity->getName()<< " completed."<<std::endl;)
    //TODO: which elements connected to the activity can be safely cleaned up here?
    }
}

fUML::Value *  ActivityExecutionImpl::new_() 
{
	//generated from body annotation
	    return fUML::FUMLFactory::eInstance()->createActivityExecution();
}

void ActivityExecutionImpl::terminate() 
{
	//generated from body annotation
	    this->getActivationGroup()->terminateAll();
}

//*********************************
// References
//*********************************
fUML::ActivityNodeActivationGroup *  ActivityExecutionImpl::getActivationGroup() const
{
	//assert(m_activationGroup);
	return m_activationGroup;
}
void ActivityExecutionImpl::setActivationGroup(fUML::ActivityNodeActivationGroup *  _activationGroup)
{
	m_activationGroup = _activationGroup;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityExecutionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYEXECUTION_ACTIVATIONGROUP:
			return getActivationGroup(); //576
		case FUMLPackage::EXECUTION_CONTEXT:
			return getContext(); //574
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //570
		case FUMLPackage::EXTENSIONALVALUE_LOCUS:
			return getLocus(); //571
		case FUMLPackage::OBJECT_OBJECTACTIVATION:
			return getObjectActivation(); //573
		case FUMLPackage::EXECUTION_PARAMETERVALUES:
			return getParameterValues(); //575
		case FUMLPackage::OBJECT_TYPES:
			return getTypes(); //572
	}
	return boost::any();
}
