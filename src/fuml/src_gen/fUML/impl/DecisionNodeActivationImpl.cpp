#include "fUML/impl/DecisionNodeActivationImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "fUML/Executor.hpp"
#include "fUML/ExecutionFactory.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Locus.hpp"
#include "fUML/ObjectToken.hpp"
#include "fUML/ParameterValue.hpp"
#include "fUML/Token.hpp"
#include "fUML/Value.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/Behavior.hpp"
#include "uml/DecisionNode.hpp"
#include "uml/ObjectFlow.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/ValueSpecification.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/ControlNodeActivation.hpp"

#include "fUML/Execution.hpp"

#include "fUML/Token.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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


//Additional constructor for the containments back reference
			DecisionNodeActivationImpl::DecisionNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:DecisionNodeActivationImpl()
			{
			    m_group = par_group;
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

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
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
	std::shared_ptr<DecisionNodeActivationImpl> element(new DecisionNodeActivationImpl(*this));
	element->setThisDecisionNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DecisionNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDecisionNodeActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> DecisionNodeActivationImpl::executeDecisionInputBehavior(std::shared_ptr<fUML::Value>  inputValue,std::shared_ptr<fUML::Value>  decisionInputValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (this->getDecisionInputExecution() != nullptr) {
        this->getDecisionInputExecution()->terminate();
    }

    ControlNodeActivationImpl::terminate();
	//end of body
}

bool DecisionNodeActivationImpl::test(std::shared_ptr<uml::ValueSpecification>  gaurd,std::shared_ptr<fUML::Value>  value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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


std::shared_ptr<DecisionNodeActivation> DecisionNodeActivationImpl::getThisDecisionNodeActivationPtr() const
{
	return m_thisDecisionNodeActivationPtr.lock();
}
void DecisionNodeActivationImpl::setThisDecisionNodeActivationPtr(std::weak_ptr<DecisionNodeActivation> thisDecisionNodeActivationPtr)
{
	m_thisDecisionNodeActivationPtr = thisDecisionNodeActivationPtr;
	setThisControlNodeActivationPtr(thisDecisionNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> DecisionNodeActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DecisionNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::DECISIONNODEACTIVATION_EREFERENCE_DECISIONINPUTEXECUTION:
			return eAny(getDecisionInputExecution()); //316
	}
	return ControlNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool DecisionNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::DECISIONNODEACTIVATION_EREFERENCE_DECISIONINPUTEXECUTION:
			return getDecisionInputExecution() != nullptr; //316
	}
	return ControlNodeActivationImpl::internalEIsSet(featureID);
}
bool DecisionNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::DECISIONNODEACTIVATION_EREFERENCE_DECISIONINPUTEXECUTION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Execution> _decisionInputExecution = newValue->get<std::shared_ptr<fUML::Execution>>();
			setDecisionInputExecution(_decisionInputExecution); //316
			return true;
		}
	}

	return ControlNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void DecisionNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void DecisionNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ControlNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void DecisionNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("decisionInputExecution") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<fUML::Execution> decisionInputExecution = std::dynamic_pointer_cast<fUML::Execution>(modelFactory->create(typeName));
			if (decisionInputExecution != nullptr)
			{
				this->setDecisionInputExecution(decisionInputExecution);
				loadHandler->handleChild(decisionInputExecution);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ControlNodeActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void DecisionNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ControlNodeActivationImpl::resolveReferences(featureID, references);
}

void DecisionNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ControlNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void DecisionNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'decisionInputExecution'
		std::shared_ptr<fUML::Execution > decisionInputExecution = this->getDecisionInputExecution();
		if (decisionInputExecution != nullptr)
		{
			saveHandler->addReference(decisionInputExecution, "decisionInputExecution", decisionInputExecution->eClass() != package->getExecution_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

