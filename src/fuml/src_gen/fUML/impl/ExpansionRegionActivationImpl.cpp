#include "fUML/impl/ExpansionRegionActivationImpl.hpp"

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
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/ActionActivation.hpp"

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/ExpansionActivationGroup.hpp"

#include "uml/ExpansionNode.hpp"

#include "fUML/ExpansionNodeActivation.hpp"

#include "fUML/InputPinActivation.hpp"

#include "fUML/OutputPinActivation.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/Token.hpp"

#include "fUML/TokenSet.hpp"

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
ExpansionRegionActivationImpl::ExpansionRegionActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_activationGroups.reset(new Bag<fUML::ExpansionActivationGroup>());
	
	

		m_inputExpansionTokens.reset(new Bag<fUML::TokenSet>());
	
	

		m_inputTokens.reset(new Bag<fUML::TokenSet>());
	
	

	//Init references
	
	

	
	

	
	
}

ExpansionRegionActivationImpl::~ExpansionRegionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionRegionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExpansionRegionActivationImpl::ExpansionRegionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:ExpansionRegionActivationImpl()
			{
			    m_group = par_group;
			}






ExpansionRegionActivationImpl::ExpansionRegionActivationImpl(const ExpansionRegionActivationImpl & obj):ExpansionRegionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionRegionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<fUML::ExpansionActivationGroup>> _activationGroups = obj.getActivationGroups();
	m_activationGroups.reset(new Bag<fUML::ExpansionActivationGroup>(*(obj.getActivationGroups().get())));

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	std::shared_ptr<Bag<fUML::TokenSet>> _inputExpansionTokens = obj.getInputExpansionTokens();
	m_inputExpansionTokens.reset(new Bag<fUML::TokenSet>(*(obj.getInputExpansionTokens().get())));

	std::shared_ptr<Bag<fUML::TokenSet>> _inputTokens = obj.getInputTokens();
	m_inputTokens.reset(new Bag<fUML::TokenSet>(*(obj.getInputTokens().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::PinActivation>(*(obj.getPinActivation().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::InputPinActivation>(std::dynamic_pointer_cast<fUML::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::OutputPinActivation>(std::dynamic_pointer_cast<fUML::OutputPinActivation>(_outputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputPinActivation" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ExpansionRegionActivationImpl::copy() const
{
	std::shared_ptr<ExpansionRegionActivationImpl> element(new ExpansionRegionActivationImpl(*this));
	element->setThisExpansionRegionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExpansionRegionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExpansionRegionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ExpansionRegionActivationImpl::doStructuredActivity()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::ExpansionNodeActivation> ExpansionRegionActivationImpl::getExpansionNodeActivation(std::shared_ptr<uml::ExpansionNode>  node)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int ExpansionRegionActivationImpl::numberOfValues()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExpansionRegionActivationImpl::runGroup(std::shared_ptr<fUML::ExpansionActivationGroup>  activationGroup)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<fUML::ExpansionActivationGroup>> ExpansionRegionActivationImpl::getActivationGroups() const
{

    return m_activationGroups;
}


std::shared_ptr<Bag<fUML::TokenSet>> ExpansionRegionActivationImpl::getInputExpansionTokens() const
{
//assert(m_inputExpansionTokens);
    return m_inputExpansionTokens;
}


std::shared_ptr<Bag<fUML::TokenSet>> ExpansionRegionActivationImpl::getInputTokens() const
{

    return m_inputTokens;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::PinActivation>> ExpansionRegionActivationImpl::getPinActivation() const
{
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
		case FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS:
			return eAny(getActivationGroups()); //4812
		case FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS:
			return eAny(getInputExpansionTokens()); //4811
		case FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS:
			return eAny(getInputTokens()); //4810
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool ExpansionRegionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS:
			return getActivationGroups() != nullptr; //4812
		case FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS:
			return getInputExpansionTokens() != nullptr; //4811
		case FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS:
			return getInputTokens() != nullptr; //4810
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}
bool ExpansionRegionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ActionActivationImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void ExpansionRegionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
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

	ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ExpansionRegionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ActionActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExpansionRegionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS:
		{
			std::shared_ptr<Bag<fUML::ExpansionActivationGroup>> _activationGroups = getActivationGroups();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::ExpansionActivationGroup> _r = std::dynamic_pointer_cast<fUML::ExpansionActivationGroup>(ref);
				if (_r != nullptr)
				{
					_activationGroups->push_back(_r);
				}				
			}
			return;
		}

		case FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS:
		{
			std::shared_ptr<Bag<fUML::TokenSet>> _inputExpansionTokens = getInputExpansionTokens();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::TokenSet> _r = std::dynamic_pointer_cast<fUML::TokenSet>(ref);
				if (_r != nullptr)
				{
					_inputExpansionTokens->push_back(_r);
				}				
			}
			return;
		}

		case FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS:
		{
			std::shared_ptr<Bag<fUML::TokenSet>> _inputTokens = getInputTokens();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::TokenSet> _r = std::dynamic_pointer_cast<fUML::TokenSet>(ref);
				if (_r != nullptr)
				{
					_inputTokens->push_back(_r);
				}				
			}
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void ExpansionRegionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ExpansionRegionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<fUML::ExpansionActivationGroup>> activationGroups_list = this->getActivationGroups();
		for (std::shared_ptr<fUML::ExpansionActivationGroup > object : *activationGroups_list)
		{ 
			saveHandler->addReferences("activationGroups", object);
		}
		std::shared_ptr<Bag<fUML::TokenSet>> inputExpansionTokens_list = this->getInputExpansionTokens();
		for (std::shared_ptr<fUML::TokenSet > object : *inputExpansionTokens_list)
		{ 
			saveHandler->addReferences("inputExpansionTokens", object);
		}
		std::shared_ptr<Bag<fUML::TokenSet>> inputTokens_list = this->getInputTokens();
		for (std::shared_ptr<fUML::TokenSet > object : *inputTokens_list)
		{ 
			saveHandler->addReferences("inputTokens", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

