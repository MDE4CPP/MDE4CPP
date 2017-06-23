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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

ActivityExecutionImpl::~ActivityExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ActivityExecutionImpl::ActivityExecutionImpl(const ActivityExecutionImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_context  = obj.getContext();

	m_locus  = obj.getLocus();

		std::shared_ptr< Bag<uml::Classifier> >
	 _types = obj.getTypes();
	m_types.reset(new 	 Bag<uml::Classifier> 
	(*(obj.getTypes().get())));// this->getTypes()->insert(this->getTypes()->end(), _types->begin(), _types->end());


	//clone containt lists
	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup.reset(dynamic_cast<fUML::ActivityNodeActivationGroup*>(obj.getActivationGroup()->copy()));
	}
	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(dynamic_cast<fUML::FeatureValue*>(_featureValues->copy())));
	}
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation.reset(dynamic_cast<fUML::ObjectActivation*>(obj.getObjectActivation()->copy()));
	}
	std::shared_ptr<Bag<fUML::ParameterValue>> _parameterValuesList = obj.getParameterValues();
	for(std::shared_ptr<fUML::ParameterValue> _parameterValues : *_parameterValuesList)
	{
		this->getParameterValues()->add(std::shared_ptr<fUML::ParameterValue>(dynamic_cast<fUML::ParameterValue*>(_parameterValues->copy())));
	}
}

ecore::EObject *  ActivityExecutionImpl::copy() const
{
	return new ActivityExecutionImpl(*this);
}

std::shared_ptr<ecore::EClass> ActivityExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityExecution();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void
 ActivityExecutionImpl::execute() 
{
	//generated from body annotation
	std::shared_ptr<uml::Activity> activity = std::dynamic_pointer_cast<uml::Activity> (this->getTypes()->front());

    if(activity != nullptr)
    {
        DEBUG_MESSAGE(std::cout<<"[execute] Activity " << activity->getName()<< "..."<<std::endl;)
        DEBUG_MESSAGE(std::cout<<"[event] Execute activity=" + activity->getName()<<std::endl;)

        this->setActivationGroup(std::shared_ptr<ActivityNodeActivationGroup>(fUML::FUMLFactory::eInstance()->createActivityNodeActivationGroup()));
        struct null_deleter{void operator()(void const *) const { } };
        this->getActivationGroup()->setActivityExecution(std::shared_ptr<ActivityExecution>(this, null_deleter()));
        std::shared_ptr<Bag<uml::ActivityNode> > nodes = activity->getNode();
		std::shared_ptr<Bag<uml::ActivityEdge> > edges = activity->getEdge();
        this->getActivationGroup()->activate(nodes, edges);

        DEBUG_MESSAGE(std::cout<<"[execute] Getting output parameter node activations..."<<std::endl;)

        std::shared_ptr<Bag<ActivityParameterNodeActivation> > outputActivationList = this->getActivationGroup()->getOutputParameterNodeActivations();
        for(std::shared_ptr<ActivityParameterNodeActivation> outputActivation : *outputActivationList)
        {
        	std::shared_ptr<ParameterValue> parameterValue(fUML::FUMLFactory::eInstance()->createParameterValue());
        	std::shared_ptr<uml::ActivityParameterNode> activityParameterNode = std::dynamic_pointer_cast<uml::ActivityParameterNode> (outputActivation->getNode());

            if(activityParameterNode != nullptr)
            {
                parameterValue->setParameter(activityParameterNode->getParameter());

                std::shared_ptr<Bag<Token> > tokenList = outputActivation->getTokens();
                for(std::shared_ptr<Token> token : *tokenList)
                {
                	std::shared_ptr<Value> value = nullptr;
                	std::shared_ptr<ObjectToken> obTok = std::dynamic_pointer_cast<ObjectToken>(token);
                    if(obTok != nullptr){
                        DEBUG_MESSAGE(std::cout<<"Getting the value of a object token"<<std::endl;)
                        value = obTok->getValue();
                    }
                    else
                    {
                    	std::shared_ptr<ForkedToken> ft = std::dynamic_pointer_cast<ForkedToken>(token);
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

std::shared_ptr<fUML::Value> 
 ActivityExecutionImpl::new_() 
{
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(fUML::FUMLFactory::eInstance()->createActivityExecution());
}

void
 ActivityExecutionImpl::terminate() 
{
	//generated from body annotation
	    this->getActivationGroup()->terminateAll();
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::ActivityNodeActivationGroup > ActivityExecutionImpl::getActivationGroup() const
{
//assert(m_activationGroup);
    return m_activationGroup;
}
void ActivityExecutionImpl::setActivationGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup> _activationGroup)
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
