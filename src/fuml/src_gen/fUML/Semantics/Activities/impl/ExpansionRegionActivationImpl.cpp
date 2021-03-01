#include "fUML/Semantics/Activities/impl/ExpansionRegionActivationImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "uml/Action.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ExpansionRegion.hpp"
#include "uml/InputPin.hpp"
#include "uml/OutputPin.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ExpansionActivationGroup.hpp"
#include "uml/ExpansionNode.hpp"
#include "fUML/Semantics/Activities/ExpansionNodeActivation.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Activities/TokenSet.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionRegionActivationImpl::ExpansionRegionActivationImpl()
{	
}

ExpansionRegionActivationImpl::~ExpansionRegionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionRegionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExpansionRegionActivationImpl::ExpansionRegionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ExpansionRegionActivationImpl()
{
	m_group = par_group;
}

ExpansionRegionActivationImpl::ExpansionRegionActivationImpl(const ExpansionRegionActivationImpl & obj): ExpansionRegionActivationImpl()
{
	*this = obj;
}

ExpansionRegionActivationImpl& ExpansionRegionActivationImpl::operator=(const ExpansionRegionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Actions::ActionActivationImpl::operator=(obj);
	ExpansionRegionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionRegionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_next = obj.getNext();

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionActivationGroup>> _activationGroups = obj.getActivationGroups();
	m_activationGroups.reset(new Bag<fUML::Semantics::Activities::ExpansionActivationGroup>(*(obj.getActivationGroups().get())));
	std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> _inputExpansionTokens = obj.getInputExpansionTokens();
	m_inputExpansionTokens.reset(new Bag<fUML::Semantics::Activities::TokenSet>(*(obj.getInputExpansionTokens().get())));
	std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> _inputTokens = obj.getInputTokens();
	m_inputTokens.reset(new Bag<fUML::Semantics::Activities::TokenSet>(*(obj.getInputTokens().get())));

	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExpansionRegionActivationImpl::copy() const
{
	std::shared_ptr<ExpansionRegionActivationImpl> element(new ExpansionRegionActivationImpl());
	*element =(*this);
	element->setThisExpansionRegionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExpansionRegionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getExpansionRegionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute next
*/
int ExpansionRegionActivationImpl::getNext() const 
{
	return m_next;
}
void ExpansionRegionActivationImpl::setNext(int _next)
{
	m_next = _next;
} 


//*********************************
// Operations
//*********************************
void ExpansionRegionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::StructuredActivityNode> node = std::dynamic_pointer_cast<uml::StructuredActivityNode>(m_node);
	if (node->getMustIsolate())
	{
		_beginIsolation();
		doStructuredActivity();
		_endIsolation();
	}
	else
	{
		doStructuredActivity();
	}
	//end of body
}

void ExpansionRegionActivationImpl::doOutput()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::ExpansionRegion> region = std::dynamic_pointer_cast<uml::ExpansionRegion>(m_node);
	std::shared_ptr<Bag<uml::ExpansionNode>> outputElements = region->getOutputElement();
	if (!isSuspended())
	{
		unsigned int activationGroupsSize = m_activationGroups->size();
		for (unsigned int i=0; i<activationGroupsSize; i++)
		{
			std::shared_ptr<ExpansionActivationGroup> activationGroup = m_activationGroups->at(i);
			std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> groupOutputs = activationGroup->getGroupOutputs();
			unsigned int groupOutputsSize = groupOutputs->size();
			for (unsigned j=0; j<groupOutputsSize; j++)
			{
				std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> groupOutput = groupOutputs->at(j);
				std::shared_ptr<uml::ExpansionNode> outputElement = outputElements->at(j);
				std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> activation = getExpansionNodeActivation(outputElement);
				if (activation == nullptr)
				{
			        DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << ": unknown activation" << std::endl;)
					throw "unknown group";
				}
				activation->addTokens(groupOutput->takeTokens());
			}
		}
	}
	//end of body
}

void ExpansionRegionActivationImpl::doStructuredActivity()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::ExpansionRegion> region = std::dynamic_pointer_cast<uml::ExpansionRegion>(m_node);
	std::shared_ptr<Bag<uml::InputPin>> inputPins = region->getInput();
	std::shared_ptr<Bag<uml::ExpansionNode>> inputElements = region->getInputElement();
	std::shared_ptr<Bag<uml::ExpansionNode>> outputElements = region->getOutputElement();
	std::shared_ptr<fUML::Semantics::Activities::ActivitiesFactory> activitiesFactory = fUML::Semantics::Activities::ActivitiesFactory::eInstance();
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> actionsFactory = fUML::Semantics::Actions::ActionsFactory::eInstance();
	std::shared_ptr<fUML::Semantics::Activities::ActivitiesFactory> activityFactory = fUML::Semantics::Activities::ActivitiesFactory::eInstance();

	getActivationGroups()->clear();

	int n = m_inputExpansionTokens->at(0)->getTokens()->size();
	int k = 0;
	while (k < n)
	{
		std::shared_ptr<ExpansionActivationGroup> activationGroup = activitiesFactory->createExpansionActivationGroup();
		activationGroup->setRegionActivation(getThisExpansionRegionActivationPtr());
		activationGroup->setIndex(k);

		std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> regionInputList = activationGroup->getRegionInputs();
		std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> groupInputsList = activationGroup->getGroupInputs();
		std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> groupOutputsList = activationGroup->getGroupOutputs();

		Bag<uml::InputPin>::iterator inputPinsIter = inputPins->begin();
		Bag<uml::InputPin>::iterator inputPinsEnd = inputPins->end();
		while (inputPinsIter != inputPinsEnd)
		{
			std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> regionInput = actionsFactory->createOutputPinActivation();
			regionInput->setNode(*inputPinsIter);
			regionInput->run();
			regionInputList->push_back(regionInput);
			inputPinsIter++;
		}

		Bag<uml::ExpansionNode>::iterator inputElementsIter = inputElements->begin();
		Bag<uml::ExpansionNode>::iterator intputElementsEnd = inputElements->end();
		while (inputElementsIter != intputElementsEnd)
		{
			std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> groupInput = activityFactory->createExpansionNodeActivation();
			groupInput->setNode(*inputElementsIter);
			groupInput->setGroup(activationGroup);
			groupInput->run();
			groupInputsList->push_back(groupInput);
			inputElementsIter++;
		}

		Bag<uml::ExpansionNode>::iterator outputElementsIter = outputElements->begin();
		Bag<uml::ExpansionNode>::iterator outputElementsEnd = outputElements->end();
		while (outputElementsIter != outputElementsEnd)
		{
			std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> groupOutput = activityFactory->createExpansionNodeActivation();
			groupOutput->setNode(*outputElementsIter);
			groupOutput->setGroup(getGroup().lock());
			groupOutput->run();
			groupOutputsList->push_back(groupOutput);
			outputElementsIter++;
		}

		activationGroup->createNodeActivations(region->getNode());
		activationGroup->createEdgeInstance(region->getEdge());
		m_activationGroups->push_back(activationGroup);

		k = k + 1;
	}

	if (region->getMode() == uml::ExpansionKind::ITERATIVE)
	{
		m_next = 0;
		runIterative();
	}
	else if (region->getMode() == uml::ExpansionKind::PARALLEL)
	{
		runParallel();
	}

	doOutput();
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> ExpansionRegionActivationImpl::getExpansionNodeActivation(std::shared_ptr<uml::ExpansionNode> node)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	auto group = m_group.lock();
	if (group != nullptr)
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> nodeActivation = group->getNodeActivation(node);
		return std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionNodeActivation>(nodeActivation);
	}
	return nullptr;
	//end of body
}

bool ExpansionRegionActivationImpl::isSuspended()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	bool suspended = false;
	Bag<ExpansionActivationGroup>::iterator iter = m_activationGroups->begin();
	Bag<ExpansionActivationGroup>::iterator end = m_activationGroups->end();
	while (!suspended and iter != end)
	{
		suspended = (*iter)->isSuspended();
		iter++;
	}
	return suspended;
	//end of body
}

int ExpansionRegionActivationImpl::numberOfValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::ExpansionRegion> region = std::dynamic_pointer_cast<uml::ExpansionRegion>(m_node);
	std::shared_ptr<Bag<uml::ExpansionNode>> inputElements = region->getInputElement();
	int n = 0;
	Bag<uml::ExpansionNode>::iterator iter = inputElements->begin();
	Bag<uml::ExpansionNode>::iterator end = inputElements->end();
	while (iter != end)
	{
		std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> activation = getExpansionNodeActivation(*iter);
		if (activation == nullptr)
		{
	        DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << ": unknown activation" << std::endl;)
			throw "unknown group";
		}
		int count = activation->countOfferedValues();
		if (count > n)
		{
			n = count;
		}

		iter++;
	}
	return n;
	//end of body
}

void ExpansionRegionActivationImpl::resume(std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> activationGroup)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::ExpansionRegion> region = std::dynamic_pointer_cast<uml::ExpansionRegion>(m_node);

	ActivityNodeActivationImpl::resume();
	terminateGroup(activationGroup);
	if (region->getMode() == uml::ExpansionKind::ITERATIVE)
	{
		runIterative();
	}

	doOutput();
	//end of body
}

void ExpansionRegionActivationImpl::runGroup(std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> activationGroup)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (isRunning())
	{
		unsigned int size = m_inputTokens->size();
		for (unsigned int i=0; i<size; i++)
		{
			std::shared_ptr<TokenSet> tokenSet = m_inputTokens->at(i);
			std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> regionInput = activationGroup->getRegionInputs()->at(i);
			regionInput->clearTokens();
			regionInput->addTokens(tokenSet->getTokens());
			regionInput->sendUnofferedTokens();
		}

		size = m_inputExpansionTokens->size();
		for (unsigned int i=0; i<size; i++)
		{
			std::shared_ptr<TokenSet> tokenSet = m_inputExpansionTokens->at(i);
			std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> groupInput = activationGroup->getGroupInputs()->at(i);
			groupInput->clearTokens();
			unsigned int index = activationGroup->getIndex();
			if (tokenSet->getTokens()->size() > index)
			{
				groupInput->addToken(tokenSet->getTokens()->at(index));
			}
			groupInput->sendUnofferedTokens();
		}

		activationGroup->run(activationGroup->getNodeActivations());

		terminateGroup(activationGroup);
	}
	//end of body
}

void ExpansionRegionActivationImpl::runIterative()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	int size = m_activationGroups->size();
	while (m_next < size and !isSuspended())
	{
		std::shared_ptr<ExpansionActivationGroup> activationGroup = m_activationGroups->at(m_next);
		runGroup(activationGroup);
		m_next++;
	}
	//end of body
}

void ExpansionRegionActivationImpl::runParallel()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	Bag<ExpansionActivationGroup>::iterator iter = m_activationGroups->begin();
	Bag<ExpansionActivationGroup>::iterator end = m_activationGroups->end();
	while (iter != end)
	{
		runGroup(*iter);
		iter++;
	}
	//end of body
}

void ExpansionRegionActivationImpl::sendOffers()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::ExpansionRegion> region = std::dynamic_pointer_cast<uml::ExpansionRegion>(m_node);
	std::shared_ptr<Bag<uml::ExpansionNode>> outputElement = region->getOutputElement();

	Bag<uml::ExpansionNode>::iterator iter = outputElement->begin();
	Bag<uml::ExpansionNode>::iterator end = outputElement->end();

	while (iter != end)
	{
		std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> activation = getExpansionNodeActivation(*iter);
		if (activation == nullptr)
		{
			DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << ": unknown activation" << std::endl;)
			throw "unknown group";
		}
		activation->sendUnofferedTokens();
		iter++;
	}

	ActionActivationImpl::sendOffers();
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > ExpansionRegionActivationImpl::takeOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	ActionActivationImpl::takeOfferedTokens();

	std::shared_ptr<uml::ExpansionRegion> region = std::dynamic_pointer_cast<uml::ExpansionRegion>(m_node);
	std::shared_ptr<Bag<uml::InputPin>> inputPinList = region->getInput();
	std::shared_ptr<Bag<uml::ExpansionNode>> inputElementList = region->getInputElement();

	getInputTokens()->clear();
	getInputExpansionTokens()->clear();

	Bag<uml::InputPin>::iterator inputPinIter = inputPinList->begin();
	Bag<uml::InputPin>::iterator inputPinEnd = inputPinList->end();
	while (inputPinIter != inputPinEnd)
	{
		std::shared_ptr<uml::InputPin> inputPin = *inputPinIter;
		std::shared_ptr<TokenSet> tokenSet = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createTokenSet();
		std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = getNodeActivation(inputPin);
		if (activation == nullptr)
		{
			DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << ": unknown activation" << std::endl;)
			throw "unknown group";
		}
		tokenSet->getTokens()->insert(*(activation->takeTokens()));
		m_inputTokens->push_back(tokenSet);

		inputPinIter++;
	}

	int n = numberOfValues();

	Bag<uml::ExpansionNode>::iterator inputElementIter = inputElementList->begin();
	Bag<uml::ExpansionNode>::iterator inputElementEnd = inputElementList->end();
	while (inputElementIter != inputElementEnd)
	{
		std::shared_ptr<uml::ExpansionNode> inputElement = *inputElementIter;

		std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> expansionNodeActivation = getExpansionNodeActivation(inputElement);
		if (expansionNodeActivation == nullptr)
		{
			DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << ": unknown activation" << std::endl;)
			throw "unknown group";
		}
		expansionNodeActivation->fire(expansionNodeActivation->takeOfferedTokens());
		std::shared_ptr<Bag<Token>> tokens = expansionNodeActivation->takeTokens();
		std::shared_ptr<TokenSet> tokenSet = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createTokenSet();
		int j = 0;
		std::shared_ptr<Bag<Token>> tokenSetTokens = tokenSet->getTokens();
		while (j < n)
		{
			tokenSetTokens->push_back(tokens->at(j));
			j++;
		}
		m_inputExpansionTokens->push_back(tokenSet);

		inputElementIter++;
	}

	std::shared_ptr<Bag<Token>> offeredTokens(new Bag<Token>());
	return offeredTokens;
	//end of body
}

void ExpansionRegionActivationImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	Bag<ExpansionActivationGroup>::iterator iter = getActivationGroups()->begin();
	Bag<ExpansionActivationGroup>::iterator end = getActivationGroups()->end();

	while (iter != end)
	{
		std::shared_ptr<ExpansionActivationGroup> activationGroup = *iter;
		std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> groupOutputs = activationGroup->getGroupOutputs();
		_beginIsolation();

		Bag<fUML::Semantics::Activities::ExpansionNodeActivation>::iterator outputIter = groupOutputs->begin();
		Bag<fUML::Semantics::Activities::ExpansionNodeActivation>::iterator outputEnd = groupOutputs->end();
		while(outputIter != outputEnd)
		{
			std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> output = *outputIter;
			output->fire(output->takeOfferedTokens());
			outputIter++;
		}

		activationGroup->terminateAll();
		_endIsolation();
		iter++;
	}

	ActionActivationImpl::terminate();
	//end of body
}

void ExpansionRegionActivationImpl::terminateGroup(std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> activationGroup)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (isRunning() and !isSuspended())
	{
		std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> groupOutputs = activationGroup->getGroupOutputs();
		Bag<fUML::Semantics::Activities::ExpansionNodeActivation>::iterator outputIter = groupOutputs->begin();
		Bag<fUML::Semantics::Activities::ExpansionNodeActivation>::iterator outputEnd = groupOutputs->end();
		while(outputIter != outputEnd)
		{
			std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> output = *outputIter;
			output->fire(output->takeOfferedTokens());
			outputIter++;
		}

		activationGroup->terminateAll();
	}
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference activationGroups
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionActivationGroup>> ExpansionRegionActivationImpl::getActivationGroups() const
{
	if(m_activationGroups == nullptr)
	{
		m_activationGroups.reset(new Bag<fUML::Semantics::Activities::ExpansionActivationGroup>());
		
		
	}

    return m_activationGroups;
}



/*
Getter & Setter for reference inputExpansionTokens
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> ExpansionRegionActivationImpl::getInputExpansionTokens() const
{
	if(m_inputExpansionTokens == nullptr)
	{
		m_inputExpansionTokens.reset(new Bag<fUML::Semantics::Activities::TokenSet>());
		
		
	}
//assert(m_inputExpansionTokens);
    return m_inputExpansionTokens;
}



/*
Getter & Setter for reference inputTokens
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> ExpansionRegionActivationImpl::getInputTokens() const
{
	if(m_inputTokens == nullptr)
	{
		m_inputTokens.reset(new Bag<fUML::Semantics::Activities::TokenSet>());
		
		
	}

    return m_inputTokens;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> ExpansionRegionActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
	return m_pinActivation;
}




std::shared_ptr<ExpansionRegionActivation> ExpansionRegionActivationImpl::getThisExpansionRegionActivationPtr() const
{
	return m_thisExpansionRegionActivationPtr.lock();
}
void ExpansionRegionActivationImpl::setThisExpansionRegionActivationPtr(std::weak_ptr<ExpansionRegionActivation> thisExpansionRegionActivationPtr)
{
	m_thisExpansionRegionActivationPtr = thisExpansionRegionActivationPtr;
	setThisActionActivationPtr(thisExpansionRegionActivationPtr);
}
std::shared_ptr<ecore::EObject> ExpansionRegionActivationImpl::eContainer() const
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
Any ExpansionRegionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS:
		{
			return eAny(getActivationGroups()); //5113			
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS:
		{
			return eAny(getInputExpansionTokens()); //5112			
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS:
		{
			return eAny(getInputTokens()); //5111			
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_NEXT:
			return eAny(getNext()); //5114
	}
	return fUML::Semantics::Actions::ActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool ExpansionRegionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS:
			return getActivationGroups() != nullptr; //5113
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS:
			return getInputExpansionTokens() != nullptr; //5112
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS:
			return getInputTokens() != nullptr; //5111
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_NEXT:
			return getNext() != 0; //5114
	}
	return fUML::Semantics::Actions::ActionActivationImpl::internalEIsSet(featureID);
}
bool ExpansionRegionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionActivationGroup>> activationGroupsList(new Bag<fUML::Semantics::Activities::ExpansionActivationGroup>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				activationGroupsList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionActivationGroup>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::ExpansionActivationGroup>::iterator iterActivationGroups = m_activationGroups->begin();
			Bag<fUML::Semantics::Activities::ExpansionActivationGroup>::iterator endActivationGroups = m_activationGroups->end();
			while (iterActivationGroups != endActivationGroups)
			{
				if (activationGroupsList->find(*iterActivationGroups) == -1)
				{
					m_activationGroups->erase(*iterActivationGroups);
				}
				iterActivationGroups++;
			}
 
			iterActivationGroups = activationGroupsList->begin();
			endActivationGroups = activationGroupsList->end();
			while (iterActivationGroups != endActivationGroups)
			{
				if (m_activationGroups->find(*iterActivationGroups) == -1)
				{
					m_activationGroups->add(*iterActivationGroups);
				}
				iterActivationGroups++;			
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> inputExpansionTokensList(new Bag<fUML::Semantics::Activities::TokenSet>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inputExpansionTokensList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::TokenSet>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::TokenSet>::iterator iterInputExpansionTokens = m_inputExpansionTokens->begin();
			Bag<fUML::Semantics::Activities::TokenSet>::iterator endInputExpansionTokens = m_inputExpansionTokens->end();
			while (iterInputExpansionTokens != endInputExpansionTokens)
			{
				if (inputExpansionTokensList->find(*iterInputExpansionTokens) == -1)
				{
					m_inputExpansionTokens->erase(*iterInputExpansionTokens);
				}
				iterInputExpansionTokens++;
			}
 
			iterInputExpansionTokens = inputExpansionTokensList->begin();
			endInputExpansionTokens = inputExpansionTokensList->end();
			while (iterInputExpansionTokens != endInputExpansionTokens)
			{
				if (m_inputExpansionTokens->find(*iterInputExpansionTokens) == -1)
				{
					m_inputExpansionTokens->add(*iterInputExpansionTokens);
				}
				iterInputExpansionTokens++;			
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> inputTokensList(new Bag<fUML::Semantics::Activities::TokenSet>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inputTokensList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::TokenSet>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::TokenSet>::iterator iterInputTokens = m_inputTokens->begin();
			Bag<fUML::Semantics::Activities::TokenSet>::iterator endInputTokens = m_inputTokens->end();
			while (iterInputTokens != endInputTokens)
			{
				if (inputTokensList->find(*iterInputTokens) == -1)
				{
					m_inputTokens->erase(*iterInputTokens);
				}
				iterInputTokens++;
			}
 
			iterInputTokens = inputTokensList->begin();
			endInputTokens = inputTokensList->end();
			while (iterInputTokens != endInputTokens)
			{
				if (m_inputTokens->find(*iterInputTokens) == -1)
				{
					m_inputTokens->add(*iterInputTokens);
				}
				iterInputTokens++;			
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_NEXT:
		{
			// BOOST CAST
			int _next = newValue->get<int>();
			setNext(_next); //5114
			return true;
		}
	}

	return fUML::Semantics::Actions::ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExpansionRegionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ExpansionRegionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("next");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream ( iter->second ) >> value;
			this->setNext(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("activationGroups");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("activationGroups")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("inputExpansionTokens");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inputExpansionTokens")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("inputTokens");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inputTokens")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Actions::ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ExpansionRegionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Actions::ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void ExpansionRegionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionActivationGroup>> _activationGroups = getActivationGroups();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup>  _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionActivationGroup>(ref);
				if (_r != nullptr)
				{
					_activationGroups->push_back(_r);
				}
			}
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> _inputExpansionTokens = getInputExpansionTokens();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::TokenSet>  _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::TokenSet>(ref);
				if (_r != nullptr)
				{
					_inputExpansionTokens->push_back(_r);
				}
			}
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> _inputTokens = getInputTokens();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::TokenSet>  _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::TokenSet>(ref);
				if (_r != nullptr)
				{
					_inputTokens->push_back(_r);
				}
			}
			return;
		}
	}
	fUML::Semantics::Actions::ActionActivationImpl::resolveReferences(featureID, references);
}

void ExpansionRegionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ExpansionRegionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getExpansionRegionActivation_Attribute_next()) )
		{
			saveHandler->addAttribute("next", this->getNext());
		}
	// Add references
		saveHandler->addReferences<fUML::Semantics::Activities::ExpansionActivationGroup>("activationGroups", this->getActivationGroups());
		saveHandler->addReferences<fUML::Semantics::Activities::TokenSet>("inputExpansionTokens", this->getInputExpansionTokens());
		saveHandler->addReferences<fUML::Semantics::Activities::TokenSet>("inputTokens", this->getInputTokens());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

