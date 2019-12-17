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
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

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

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

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
		m_activationGroups.reset(new Bag<fUML::Semantics::Activities::ExpansionActivationGroup>());
	
	

		m_inputExpansionTokens.reset(new Bag<fUML::Semantics::Activities::TokenSet>());
	
	

		m_inputTokens.reset(new Bag<fUML::Semantics::Activities::TokenSet>());
	
	

	//Init references
	
	

	
	

	
	
}

ExpansionRegionActivationImpl::~ExpansionRegionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionRegionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExpansionRegionActivationImpl::ExpansionRegionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
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
	
	std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionActivationGroup>> _activationGroups = obj.getActivationGroups();
	m_activationGroups.reset(new Bag<fUML::Semantics::Activities::ExpansionActivationGroup>(*(obj.getActivationGroups().get())));

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> _inputExpansionTokens = obj.getInputExpansionTokens();
	m_inputExpansionTokens.reset(new Bag<fUML::Semantics::Activities::TokenSet>(*(obj.getInputExpansionTokens().get())));

	std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> _inputTokens = obj.getInputTokens();
	m_inputTokens.reset(new Bag<fUML::Semantics::Activities::TokenSet>(*(obj.getInputTokens().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>(*(obj.getPinActivation().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Semantics::Activities::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Semantics::Activities::Token>(std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(_outputPinActivation->copy())));
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

std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> ExpansionRegionActivationImpl::getExpansionNodeActivation(std::shared_ptr<uml::ExpansionNode>  node)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int ExpansionRegionActivationImpl::numberOfValues()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExpansionRegionActivationImpl::runGroup(std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup>  activationGroup)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionActivationGroup>> ExpansionRegionActivationImpl::getActivationGroups() const
{

    return m_activationGroups;
}


std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> ExpansionRegionActivationImpl::getInputExpansionTokens() const
{
//assert(m_inputExpansionTokens);
    return m_inputExpansionTokens;
}


std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> ExpansionRegionActivationImpl::getInputTokens() const
{

    return m_inputTokens;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> ExpansionRegionActivationImpl::getPinActivation() const
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
		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::ExpansionActivationGroup>::iterator iter = m_activationGroups->begin();
			Bag<fUML::Semantics::Activities::ExpansionActivationGroup>::iterator end = m_activationGroups->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5412
		}
		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::TokenSet>::iterator iter = m_inputExpansionTokens->begin();
			Bag<fUML::Semantics::Activities::TokenSet>::iterator end = m_inputExpansionTokens->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5411
		}
		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::TokenSet>::iterator iter = m_inputTokens->begin();
			Bag<fUML::Semantics::Activities::TokenSet>::iterator end = m_inputTokens->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5410
		}
	}
	return fUML::Semantics::Actions::ActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool ExpansionRegionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS:
			return getActivationGroups() != nullptr; //5412
		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS:
			return getInputExpansionTokens() != nullptr; //5411
		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS:
			return getInputTokens() != nullptr; //5410
	}
	return fUML::Semantics::Actions::ActionActivationImpl::internalEIsSet(featureID);
}
bool ExpansionRegionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS:
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
		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS:
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
		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS:
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

	fUML::Semantics::Actions::ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ExpansionRegionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	fUML::Semantics::Actions::ActionActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExpansionRegionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionActivationGroup>> _activationGroups = getActivationGroups();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionActivationGroup>(ref);
				if (_r != nullptr)
				{
					_activationGroups->push_back(_r);
				}				
			}
			return;
		}

		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> _inputExpansionTokens = getInputExpansionTokens();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::TokenSet> _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::TokenSet>(ref);
				if (_r != nullptr)
				{
					_inputExpansionTokens->push_back(_r);
				}				
			}
			return;
		}

		case fUML::FUMLPackage::EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> _inputTokens = getInputTokens();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::TokenSet> _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::TokenSet>(ref);
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionActivationGroup>> activationGroups_list = this->getActivationGroups();
		for (std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup > object : *activationGroups_list)
		{ 
			saveHandler->addReferences("activationGroups", object);
		}
		std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> inputExpansionTokens_list = this->getInputExpansionTokens();
		for (std::shared_ptr<fUML::Semantics::Activities::TokenSet > object : *inputExpansionTokens_list)
		{ 
			saveHandler->addReferences("inputExpansionTokens", object);
		}
		std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> inputTokens_list = this->getInputTokens();
		for (std::shared_ptr<fUML::Semantics::Activities::TokenSet > object : *inputTokens_list)
		{ 
			saveHandler->addReferences("inputTokens", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

