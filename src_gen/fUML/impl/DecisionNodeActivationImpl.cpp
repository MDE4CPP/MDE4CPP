#include "DecisionNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "DecisionNode.hpp"
#include "Behavior.hpp"
#include "Parameter.hpp"
#include "ParameterDirectionKind.hpp"
#include "UmlFactory.hpp"
#include "FUMLFactory.hpp"
#include "ParameterValue.hpp"
#include "Token.hpp"
#include "ObjectFlow.hpp"
#include "ActivityEdge.hpp"
#include "ValueSpecification.hpp"
#include "ObjectToken.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp"

#include "ActivityNode.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "ControlNodeActivation.hpp"

#include "Execution.hpp"

#include "Token.hpp"

#include "Value.hpp"

#include "ValueSpecification.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
DecisionNodeActivationImpl::DecisionNodeActivationImpl()
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

DecisionNodeActivationImpl::~DecisionNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DecisionNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




DecisionNodeActivationImpl::DecisionNodeActivationImpl(const DecisionNodeActivationImpl & obj):DecisionNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DecisionNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));


	//Clone references with containment (deep copy)

	if(obj.getDecisionInputExecution()!=nullptr)
	{
		m_decisionInputExecution = std::dynamic_pointer_cast<fUML::Execution>(obj.getDecisionInputExecution()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_decisionInputExecution" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

	
}

std::shared_ptr<ecore::EObject>  DecisionNodeActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new DecisionNodeActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> DecisionNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDecisionNodeActivation();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> DecisionNodeActivationImpl::executeDecisionInputBehavior(std::shared_ptr<fUML::Value>  inputValue,std::shared_ptr<fUML::Value>  decisionInputValue) 
{
	//generated from body annotation
		std::shared_ptr<uml::DecisionNode> decisionNode = std::dynamic_pointer_cast<uml::DecisionNode>(this->getNode());
	std::shared_ptr<uml::Behavior> decisionInputBehavior = nullptr;

    if(decisionNode != nullptr)
    {
        decisionInputBehavior = decisionNode->getDecisionInput();
    }

    std::shared_ptr<Value> decisionInputResult = nullptr;

    if (decisionInputBehavior == nullptr)
    {
        if (decisionInputValue != nullptr)
        {
            decisionInputResult = decisionInputValue;
        }
        else
        {
            decisionInputResult = inputValue;
        }
    }
    else
    {
        this->setDecisionInputExecution(this->getExecutionLocus()->getFactory()->createExecution(decisionInputBehavior,this->getExecutionContext()));

        unsigned int i = 0;
        unsigned int j = 0;
        while (((j == 0) || ((j == 1) && (decisionInputValue != nullptr)))
               && (i < decisionInputBehavior->getOwnedParameter()->size()))
        {
        	std::shared_ptr<uml::Parameter> parameter = decisionInputBehavior->getOwnedParameter()->at(i);
            if (parameter->getDirection() == uml::ParameterDirectionKind::IN
                    || parameter->getDirection() == uml::ParameterDirectionKind::INOUT)
            {
            	std::shared_ptr<ParameterValue> inputParameterValue(fUML::FUMLFactory::eInstance()->createParameterValue());
                inputParameterValue->setParameter(parameter);

                j = j + 1;
                if (j == 1 && inputValue != nullptr)
                {
                    inputParameterValue->getValues()->push_back(inputValue);
                }
                else
                {
                    inputParameterValue->getValues()->push_back(decisionInputValue);
                }

                this->getDecisionInputExecution()->setParameterValue(inputParameterValue);
            }
            i = i + 1;
        }
        this->getDecisionInputExecution()->execute();

        std::shared_ptr<Bag<ParameterValue> > outputParameterValues = this->getDecisionInputExecution()->getOutputParameterValues();
        this->getDecisionInputExecution()->destroy();

        decisionInputResult = outputParameterValues->at(0)->getValues()->at(0);
    }

    return decisionInputResult;
	//end of body
}

void DecisionNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
{
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[fire] Decision node " << this->getNode()->getName() << "..."<<std::endl;)

	std::shared_ptr<Bag<fUML::Token> > removedControlTokens = this->removeJoinedControlTokens(incomingTokens);
	std::shared_ptr<Bag<fUML::Value> > decisionValues = this->getDecisionValues(incomingTokens);
	std::shared_ptr<Bag<ActivityEdgeInstance> > outgoingEdges = this->getOutgoingEdges();

    for (unsigned int i = 0; i < outgoingEdges->size(); i++) 
    {
    	std::shared_ptr<ActivityEdgeInstance> edgeInstance = outgoingEdges->at(i);
    	std::shared_ptr<uml::ValueSpecification> guard = edgeInstance->getEdge()->getGuard();

    	std::shared_ptr<Bag<fUML::Token> > offeredTokens(new Bag<fUML::Token>());
        for (unsigned int j = 0; j < incomingTokens->size(); j++) 
        {
        	std::shared_ptr<Token> incomingToken = incomingTokens->at(j);
        	std::shared_ptr<Value> decisionValue = decisionValues->at(j);
            if (this->test(guard, decisionValue)) 
            {
                offeredTokens->push_back(incomingToken);
            }
        }

        if (offeredTokens->size() > 0) 
        {
            for (unsigned int j = 0; j < removedControlTokens->size(); j++) 
            {
            	std::shared_ptr<Token> removedControlToken = removedControlTokens->at(j);
                offeredTokens->push_back(removedControlToken);
            }
            edgeInstance->sendOffer(offeredTokens);
        }
    }
	//end of body
}

std::shared_ptr<fUML::ActivityEdgeInstance> DecisionNodeActivationImpl::getDecisionInputFlowInstance() 
{
	//generated from body annotation
		std::shared_ptr<uml::ActivityEdge>  decisionInputFlow = (std::dynamic_pointer_cast<uml::DecisionNode> (this->getNode()))->getDecisionInputFlow();

	std::shared_ptr<ActivityEdgeInstance> edgeInstance = nullptr;
    if (decisionInputFlow != nullptr) 
    {
        unsigned int i = 0;
        while ((edgeInstance == nullptr) && (i < this->getIncomingEdges()->size())) 
        {
        	std::shared_ptr<ActivityEdgeInstance> incomingEdge = this->getIncomingEdges()->at(i);
            if (incomingEdge->getEdge() == decisionInputFlow) 
            {
                edgeInstance = incomingEdge;
            }
            i = i + 1;
        }
    }

    return edgeInstance;
	//end of body
}

std::shared_ptr<fUML::Value> DecisionNodeActivationImpl::getDecisionInputFlowValue() 
{
	//generated from body annotation
	std::shared_ptr<ActivityEdgeInstance> decisionInputFlowInstance = this->getDecisionInputFlowInstance();

	std::shared_ptr<Value> value = nullptr;
    if (decisionInputFlowInstance != nullptr) 
    {
    	std::shared_ptr<Bag<Token> > tokens = decisionInputFlowInstance->takeOfferedTokens();
        if (tokens->size() > 0) 
        {
            value = tokens->at(0)->getValue();
        }
    }

    return value;
	//end of body
}

std::shared_ptr<Bag<fUML::Value> > DecisionNodeActivationImpl::getDecisionValues(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
{
	//generated from body annotation
	std::shared_ptr<Value> decisionInputValue = this->getDecisionInputFlowValue();

	std::shared_ptr<Bag<fUML::Value> > decisionValues(new Bag<fUML::Value>());

    for (unsigned int i = 0; i < incomingTokens->size(); i++) 
    {
    	std::shared_ptr<Token> incomingToken = incomingTokens->at(i);
    	std::shared_ptr<Value> value = this->executeDecisionInputBehavior(incomingToken->getValue(), decisionInputValue);
        decisionValues->push_back(value);
    }

    DEBUG_MESSAGE(
		for (unsigned int i = 0; i < decisionValues->size(); i++)
		{
			std::shared_ptr<Value> decisionValue = decisionValues->at(i);
			if (decisionValue)
			{
				std::cout<<"[getDecisionValues] decisionValues[" << i << "] = "
				   << decisionValue->toString()<<std::endl;
			}
			else
			{
				std::cout<<"[getDecisionValues] decisionValues[" << i << "] = nullptr" << std::endl;
			}
		}
    )

    return decisionValues;
	//end of body
}

bool DecisionNodeActivationImpl::hasObjectFlowInput() 
{
	//generated from body annotation
		std::shared_ptr<uml::ActivityEdge> decisionInputFlow = (std::dynamic_pointer_cast<uml::DecisionNode> (this->getNode()))->getDecisionInputFlow();

    bool isObjectFlow = false;
    unsigned int i = 0;
    while (!isObjectFlow && i < this->getIncomingEdges()->size()) 
    {
    	std::shared_ptr<uml::ActivityEdge> edge = this->getIncomingEdges()->at(i)->getEdge();
        isObjectFlow = (edge != decisionInputFlow) && (std::dynamic_pointer_cast<uml::ObjectFlow>(edge) != nullptr);
        i = i + 1;
    }
    return isObjectFlow;
	//end of body
}

bool DecisionNodeActivationImpl::isReady() 
{
	//generated from body annotation
	unsigned int i = 0;
    bool ready = true;
    DEBUG_MESSAGE(std::cout<< "INCOMING EDGE SIZE:"<< this->getIncomingEdges()->size()<<std::endl;)
    while (ready && (i < this->getIncomingEdges()->size())) {
        ready = this->getIncomingEdges()->at(i)->hasOffer();
        i = i + 1;
    }
    DEBUG_MESSAGE(std::cout<< "READY:"<< ready<<std::endl;)
    return ready;
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > DecisionNodeActivationImpl::removeJoinedControlTokens(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
{
	//generated from body annotation
		std::shared_ptr<Bag<fUML::Token> > removedControlTokens(new Bag<fUML::Token>());

    if (this->hasObjectFlowInput()) 
    {
        unsigned int i = 0;
        while (i < incomingTokens->size()) 
        {
        	std::shared_ptr<Token> token = incomingTokens->at(i);
            if (token->isControl()) 
            {
                removedControlTokens->push_back(token);
                incomingTokens->erase(incomingTokens->begin()+i);
                i = i - 1;
            }
            i = i + 1;
        }
    }

    return removedControlTokens;
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > DecisionNodeActivationImpl::takeOfferedTokens() 
{
	//generated from body annotation
	std::shared_ptr<uml::ObjectFlow> decisionInputFlow = (std::dynamic_pointer_cast<uml::DecisionNode> (this->getNode()))->getDecisionInputFlow();

	std::shared_ptr<Bag<fUML::Token> > allTokens(new Bag<fUML::Token>());
	std::shared_ptr<Bag<ActivityEdgeInstance> > incomingEdges = this->getIncomingEdges();
    for (unsigned int i = 0; i < incomingEdges->size(); i++) 
    {
    	std::shared_ptr<ActivityEdgeInstance> edgeInstance = incomingEdges->at(i);
        if (edgeInstance->getEdge() != decisionInputFlow) 
        {
        	std::shared_ptr<Bag<fUML::Token> > tokens = edgeInstance->takeOfferedTokens();
            for (unsigned int j = 0; j < tokens->size(); j++)
            {
                allTokens->push_back(tokens->at(j));
            }
        }
    }

    return allTokens;
	//end of body
}

void DecisionNodeActivationImpl::terminate() 
{
	//generated from body annotation
	    if (this->getDecisionInputExecution() != nullptr) {
        this->getDecisionInputExecution()->terminate();
    }

    ControlNodeActivationImpl::terminate();
	//end of body
}

bool DecisionNodeActivationImpl::test(std::shared_ptr<uml::ValueSpecification>  gaurd,std::shared_ptr<fUML::Value>  value) 
{
	//generated from body annotation
	bool guardResult = true;
    if (gaurd != nullptr) 
    {
    	std::shared_ptr<Value> guardValue = this->getExecutionLocus()->getExecutor()->evaluate(gaurd);
        guardResult = guardValue->equals(value);
    }
    return guardResult;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Execution > DecisionNodeActivationImpl::getDecisionInputExecution() const
{
//assert(m_decisionInputExecution);
    return m_decisionInputExecution;
}
void DecisionNodeActivationImpl::setDecisionInputExecution(std::shared_ptr<fUML::Execution> _decisionInputExecution)
{
    m_decisionInputExecution = _decisionInputExecution;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DecisionNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::DECISIONNODEACTIVATION_DECISIONINPUTEXECUTION:
			return getDecisionInputExecution(); //666
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //663
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //662
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //661
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //664
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //660
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //665
	}
	return boost::any();
}
