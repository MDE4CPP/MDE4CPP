#include "DecisionNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
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

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
DecisionNodeActivationImpl::DecisionNodeActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

DecisionNodeActivationImpl::~DecisionNodeActivationImpl()
{
	if(m_decisionInputExecution!=nullptr)
	{
		if(m_decisionInputExecution)
		{
			delete(m_decisionInputExecution);
			m_decisionInputExecution = nullptr;
		}
	}
	
}

DecisionNodeActivationImpl::DecisionNodeActivationImpl(const DecisionNodeActivationImpl & obj)
{
	//create copy of all Attributes
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_group  = obj.getGroup();

	std::vector<fUML::ActivityEdgeInstance * > *  _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::vector<fUML::ActivityEdgeInstance * > *  _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());


	//clone containt lists
	if(obj.getDecisionInputExecution()!=nullptr)
	{
		m_decisionInputExecution = dynamic_cast<fUML::Execution * >(obj.getDecisionInputExecution()->copy());
	}
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  DecisionNodeActivationImpl::copy() const
{
	return new DecisionNodeActivationImpl(*this);
}

ecore::EClass* DecisionNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDecisionNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::Value *  DecisionNodeActivationImpl::executeDecisionInputBehavior(fUML::Value *  inputValue,fUML::Value *  decisionInputValue) 
{
	//generated from body annotation
	    uml::DecisionNode * decisionNode = dynamic_cast<uml::DecisionNode*> (this->getNode());
    uml::Behavior* decisionInputBehavior = nullptr;

    if(decisionNode != nullptr)
    {
        decisionInputBehavior = decisionNode->getDecisionInput();
    }

    Value * decisionInputResult = nullptr;

    if (decisionInputBehavior == nullptr) {

        if (decisionInputValue != nullptr) {
            decisionInputResult = decisionInputValue;
        } else {
            decisionInputResult = inputValue;
        }

    } else {

        this->setDecisionInputExecution(this->getExecutionLocus()->getFactory()->createExecution(decisionInputBehavior,this->getExecutionContext()));

        unsigned int i = 1;
        int j = 0;
        while (((j == 0) || ((j == 1) && (decisionInputValue != nullptr)))
               && (i <= decisionInputBehavior->getOwnedParameter()->size())) {
            uml::Parameter * parameter = decisionInputBehavior->getOwnedParameter()->at(i - 1);
            if (parameter->getDirection() == uml::ParameterDirectionKind::IN
                    || parameter->getDirection() == uml::ParameterDirectionKind::INOUT) {
                ParameterValue * inputParameterValue = fUML::FUMLFactory::eInstance()->createParameterValue();
                inputParameterValue->setParameter(parameter);

                j = j + 1;
                if (j == 1 && inputValue != nullptr) {
                    inputParameterValue->getValues()->push_back(inputValue);
                } else {
                    inputParameterValue->getValues()->push_back(decisionInputValue);
                }

                this->getDecisionInputExecution()->setParameterValue(inputParameterValue);

            }
            i = i + 1;
        }
        this->getDecisionInputExecution()->execute();

        std::vector<ParameterValue*>* outputParameterValues = this->getDecisionInputExecution()->getOutputParameterValues();
        this->getDecisionInputExecution()->destroy();

        decisionInputResult = outputParameterValues->at(0)->getValues()->at(0);

    }

    return decisionInputResult;
}

void DecisionNodeActivationImpl::fire(std::vector<fUML::Token * > *  incomingTokens) 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[fire] Decision node " << this->getNode()->getName() << "..."<<std::endl;)

    std::vector<fUML::Token * > * removedControlTokens = this->removeJoinedControlTokens(incomingTokens);
    std::vector<fUML::Value * > * decisionValues = this->getDecisionValues(incomingTokens);

    std::vector<ActivityEdgeInstance*>* outgoingEdges = this->getOutgoingEdges();

    for (unsigned int i = 0; i < outgoingEdges->size(); i++) {
        ActivityEdgeInstance * edgeInstance = outgoingEdges->at(i);
        uml::ValueSpecification * guard = edgeInstance->getEdge()->getGuard();

        std::vector<fUML::Token * > * offeredTokens = new std::vector<fUML::Token * > ();
        for (unsigned int j = 0; j < incomingTokens->size(); j++) {
            Token * incomingToken = incomingTokens->at(j);
            Value * decisionValue = decisionValues->at(j);
            if (this->test(guard, decisionValue)) {
                offeredTokens->push_back(incomingToken);
            }
        }

        if (offeredTokens->size() > 0) {
            for (unsigned int j = 0; j < removedControlTokens->size(); j++) {
                Token * removedControlToken = removedControlTokens->at(j);
                offeredTokens->push_back(removedControlToken);
            }
            edgeInstance->sendOffer(offeredTokens);
        }
    }
}

fUML::ActivityEdgeInstance *  DecisionNodeActivationImpl::getDecisionInputFlowInstance() 
{
	//generated from body annotation
	    uml::ActivityEdge*  decisionInputFlow = (dynamic_cast<uml::DecisionNode*> (this->getNode()))->getDecisionInputFlow();

    ActivityEdgeInstance * edgeInstance = nullptr;
    if (decisionInputFlow != nullptr) {
        unsigned int i = 1;
        while ((edgeInstance == nullptr) && (i <= this->getIncomingEdges()->size())) {
            ActivityEdgeInstance * incomingEdge = this->getIncomingEdges()->at(i - 1);
            if (incomingEdge->getEdge() == decisionInputFlow) {
                edgeInstance = incomingEdge;
            }
            i = i + 1;
        }
    }


    return edgeInstance;
}

fUML::Value *  DecisionNodeActivationImpl::getDecisionInputFlowValue() 
{
	//generated from body annotation
	    ActivityEdgeInstance * decisionInputFlowInstance = this->getDecisionInputFlowInstance();

    Value * value = nullptr;
    if (decisionInputFlowInstance != nullptr) {
        std::vector<Token*>* tokens = decisionInputFlowInstance->takeOfferedTokens();

        if (tokens->size() > 0) {
            value = tokens->at(0)->getValue();
        }
    }

    return value;
}

std::vector<fUML::Value * > *  DecisionNodeActivationImpl::getDecisionValues(std::vector<fUML::Token * > *  incomingTokens) 
{
	//generated from body annotation
	Value * decisionInputValue = this->getDecisionInputFlowValue();

    std::vector<fUML::Value * > * decisionValues = new std::vector<fUML::Value * >();

    for (unsigned int i = 0; i < incomingTokens->size(); i++) {
        Token * incomingToken = incomingTokens->at(i);


        Value * value = this->executeDecisionInputBehavior(incomingToken->getValue(), decisionInputValue);
        decisionValues->push_back(value);
    }

    for (unsigned int i = 0; i < decisionValues->size(); i++) {
        Value * decisionValue = decisionValues->at(i);
        DEBUG_MESSAGE(std::cout<<"[getDecisionValues] decisionValues[" << i << "] = "
               << decisionValue->toString()<<std::endl;)
    }

    return decisionValues;
}

bool DecisionNodeActivationImpl::hasObjectFlowInput() 
{
	//generated from body annotation
	    uml::ActivityEdge * decisionInputFlow = (dynamic_cast<uml::DecisionNode*> (this->getNode()))->getDecisionInputFlow();

    bool isObjectFlow = false;
    unsigned int i = 1;
    while (!isObjectFlow && i <= this->getIncomingEdges()->size()) {
        uml::ActivityEdge * edge = this->getIncomingEdges()->at(i - 1)->getEdge();
        isObjectFlow = (edge != decisionInputFlow) && (dynamic_cast<uml::ObjectFlow*>(edge) != nullptr);
        i = i + 1;
    }
    return isObjectFlow;
}

bool DecisionNodeActivationImpl::isReady() 
{
	//generated from body annotation
	    int i = 1;
    bool ready = true;
    DEBUG_MESSAGE(std::cout<< "INCOMING EDGE SIZE:"<< this->getIncomingEdges()->size()<<std::endl;)
    while (ready && (i <= this->getIncomingEdges()->size())) {
        ready = this->getIncomingEdges()->at(i - 1)->hasOffer();
        i = i + 1;
    }
    DEBUG_MESSAGE(std::cout<< "READY:"<< ready<<std::endl;)
    return ready;
}

std::vector<fUML::Token * > *  DecisionNodeActivationImpl::removeJoinedControlTokens(std::vector<fUML::Token * > *  incomingTokens) 
{
	//generated from body annotation
	    std::vector<fUML::Token * > * removedControlTokens = new std::vector<fUML::Token * >();

    if (this->hasObjectFlowInput()) {
        unsigned int i = 1;
        while (i <= incomingTokens->size()) {
            Token * token = incomingTokens->at(i - 1);
            if (token->isControl()) {
                removedControlTokens->push_back(token);
                incomingTokens->erase(incomingTokens->begin()+i - 1);
                i = i - 1;
            }
            i = i + 1;
        }
    }

    return removedControlTokens;
}

std::vector<fUML::Token * > *  DecisionNodeActivationImpl::takeOfferedTokens() 
{
	//generated from body annotation
	    uml::ObjectFlow * decisionInputFlow = (dynamic_cast<uml::DecisionNode*> (this->getNode()))->getDecisionInputFlow();

    std::vector<fUML::Token * > * allTokens = new std::vector<fUML::Token * >();
    std::vector<ActivityEdgeInstance*>* incomingEdges = this->getIncomingEdges();
    for (unsigned int i = 0; i < incomingEdges->size(); i++) {
        ActivityEdgeInstance * edgeInstance = incomingEdges->at(i);
        if (edgeInstance->getEdge() != decisionInputFlow) {
            std::vector<fUML::Token * > * tokens = edgeInstance->takeOfferedTokens();
            for (unsigned int j = 0; j < tokens->size(); j++) {
                allTokens->push_back(tokens->at(j));
            }
        }
    }

    return allTokens;
}

void DecisionNodeActivationImpl::terminate() 
{
	//generated from body annotation
	    if (this->getDecisionInputExecution() != nullptr) {
        this->getDecisionInputExecution()->terminate();
    }

    ControlNodeActivationImpl::terminate();
}

bool DecisionNodeActivationImpl::test(uml::ValueSpecification *  gaurd,fUML::Value *  value) 
{
	//generated from body annotation
	    bool guardResult = true;
    if (gaurd != nullptr) {
        Value * guardValue = this->getExecutionLocus()->getExecutor()->evaluate(gaurd);
        guardResult = guardValue->equals(value);

    }
    return guardResult;
}

//*********************************
// References
//*********************************
fUML::Execution *  DecisionNodeActivationImpl::getDecisionInputExecution() const
{
	//assert(m_decisionInputExecution);
	return m_decisionInputExecution;
}
void DecisionNodeActivationImpl::setDecisionInputExecution(fUML::Execution *  _decisionInputExecution)
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
