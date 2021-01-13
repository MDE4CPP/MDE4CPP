#include "fUML/Semantics/Actions/impl/ConditionalNodeActivationImpl.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/Clause.hpp"

#include "fUML/Semantics/Actions/ClauseActivation.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
ConditionalNodeActivationImpl::ConditionalNodeActivationImpl()
{	
}

ConditionalNodeActivationImpl::~ConditionalNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConditionalNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConditionalNodeActivationImpl::ConditionalNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
:ConditionalNodeActivationImpl()
{
	m_group = par_group;
}


ConditionalNodeActivationImpl::ConditionalNodeActivationImpl(const ConditionalNodeActivationImpl & obj):ConditionalNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConditionalNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_action  = obj.getAction();

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>(*(obj.getPinActivation().get())));

	std::shared_ptr<Bag<uml::Clause>> _selectedClauses = obj.getSelectedClauses();
	m_selectedClauses.reset(new Bag<uml::Clause>(*(obj.getSelectedClauses().get())));


	//Clone references with containment (deep copy)

	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(obj.getActivationGroup()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_activationGroup" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::ClauseActivation>> _clauseActivationsList = obj.getClauseActivations();
	for(std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> _clauseActivations : *_clauseActivationsList)
	{
		this->getClauseActivations()->add(std::shared_ptr<fUML::Semantics::Actions::ClauseActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::ClauseActivation>(_clauseActivations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_clauseActivations" << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  ConditionalNodeActivationImpl::copy() const
{
	std::shared_ptr<ConditionalNodeActivationImpl> element(new ConditionalNodeActivationImpl(*this));
	element->setThisConditionalNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConditionalNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getConditionalNodeActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> ConditionalNodeActivationImpl::getClauseActivation(std::shared_ptr<uml::Clause>  clause)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ConditionalNodeActivationImpl::runTest(std::shared_ptr<uml::Clause>  clause)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ConditionalNodeActivationImpl::selectBody(std::shared_ptr<uml::Clause>  clause)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference clauseActivations
*/
std::shared_ptr<Bag<fUML::Semantics::Actions::ClauseActivation>> ConditionalNodeActivationImpl::getClauseActivations() const
{
	if(m_clauseActivations == nullptr)
	{
		m_clauseActivations.reset(new Bag<fUML::Semantics::Actions::ClauseActivation>());
		
		
	}

    return m_clauseActivations;
}





/*
Getter & Setter for reference selectedClauses
*/
std::shared_ptr<Bag<uml::Clause>> ConditionalNodeActivationImpl::getSelectedClauses() const
{
	if(m_selectedClauses == nullptr)
	{
		m_selectedClauses.reset(new Bag<uml::Clause>());
		
		
	}

    return m_selectedClauses;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> ConditionalNodeActivationImpl::getPinActivation() const
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




std::shared_ptr<ConditionalNodeActivation> ConditionalNodeActivationImpl::getThisConditionalNodeActivationPtr() const
{
	return m_thisConditionalNodeActivationPtr.lock();
}
void ConditionalNodeActivationImpl::setThisConditionalNodeActivationPtr(std::weak_ptr<ConditionalNodeActivation> thisConditionalNodeActivationPtr)
{
	m_thisConditionalNodeActivationPtr = thisConditionalNodeActivationPtr;
	setThisStructuredActivityNodeActivationPtr(thisConditionalNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> ConditionalNodeActivationImpl::eContainer() const
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
Any ConditionalNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CONDITIONALNODEACTIVATION_ATTRIBUTE_CLAUSEACTIVATIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Actions::ClauseActivation>::iterator iter = m_clauseActivations->begin();
			Bag<fUML::Semantics::Actions::ClauseActivation>::iterator end = m_clauseActivations->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3012
		}
		case fUML::Semantics::Actions::ActionsPackage::CONDITIONALNODEACTIVATION_ATTRIBUTE_SELECTEDCLAUSES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Clause>::iterator iter = m_selectedClauses->begin();
			Bag<uml::Clause>::iterator end = m_selectedClauses->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3013
		}
	}
	return StructuredActivityNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool ConditionalNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CONDITIONALNODEACTIVATION_ATTRIBUTE_CLAUSEACTIVATIONS:
			return getClauseActivations() != nullptr; //3012
		case fUML::Semantics::Actions::ActionsPackage::CONDITIONALNODEACTIVATION_ATTRIBUTE_SELECTEDCLAUSES:
			return getSelectedClauses() != nullptr; //3013
	}
	return StructuredActivityNodeActivationImpl::internalEIsSet(featureID);
}
bool ConditionalNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CONDITIONALNODEACTIVATION_ATTRIBUTE_CLAUSEACTIVATIONS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Actions::ClauseActivation>> clauseActivationsList(new Bag<fUML::Semantics::Actions::ClauseActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				clauseActivationsList->add(std::dynamic_pointer_cast<fUML::Semantics::Actions::ClauseActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Actions::ClauseActivation>::iterator iterClauseActivations = m_clauseActivations->begin();
			Bag<fUML::Semantics::Actions::ClauseActivation>::iterator endClauseActivations = m_clauseActivations->end();
			while (iterClauseActivations != endClauseActivations)
			{
				if (clauseActivationsList->find(*iterClauseActivations) == -1)
				{
					m_clauseActivations->erase(*iterClauseActivations);
				}
				iterClauseActivations++;
			}

			iterClauseActivations = clauseActivationsList->begin();
			endClauseActivations = clauseActivationsList->end();
			while (iterClauseActivations != endClauseActivations)
			{
				if (m_clauseActivations->find(*iterClauseActivations) == -1)
				{
					m_clauseActivations->add(*iterClauseActivations);
				}
				iterClauseActivations++;			
			}
			return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::CONDITIONALNODEACTIVATION_ATTRIBUTE_SELECTEDCLAUSES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Clause>> selectedClausesList(new Bag<uml::Clause>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				selectedClausesList->add(std::dynamic_pointer_cast<uml::Clause>(*iter));
				iter++;
			}
			
			Bag<uml::Clause>::iterator iterSelectedClauses = m_selectedClauses->begin();
			Bag<uml::Clause>::iterator endSelectedClauses = m_selectedClauses->end();
			while (iterSelectedClauses != endSelectedClauses)
			{
				if (selectedClausesList->find(*iterSelectedClauses) == -1)
				{
					m_selectedClauses->erase(*iterSelectedClauses);
				}
				iterSelectedClauses++;
			}

			iterSelectedClauses = selectedClausesList->begin();
			endSelectedClauses = selectedClausesList->end();
			while (iterSelectedClauses != endSelectedClauses)
			{
				if (m_selectedClauses->find(*iterSelectedClauses) == -1)
				{
					m_selectedClauses->add(*iterSelectedClauses);
				}
				iterSelectedClauses++;			
			}
			return true;
		}
	}

	return StructuredActivityNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ConditionalNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConditionalNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("selectedClauses");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("selectedClauses")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	StructuredActivityNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ConditionalNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

	try
	{
		if ( nodeName.compare("clauseActivations") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ClauseActivation";
			}
			std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> clauseActivations = std::dynamic_pointer_cast<fUML::Semantics::Actions::ClauseActivation>(modelFactory->create(typeName));
			if (clauseActivations != nullptr)
			{
				std::shared_ptr<Bag<fUML::Semantics::Actions::ClauseActivation>> list_clauseActivations = this->getClauseActivations();
				list_clauseActivations->push_back(clauseActivations);
				loadHandler->handleChild(clauseActivations);
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
	//load BasePackage Nodes
	StructuredActivityNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void ConditionalNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CONDITIONALNODEACTIVATION_ATTRIBUTE_SELECTEDCLAUSES:
		{
			std::shared_ptr<Bag<uml::Clause>> _selectedClauses = getSelectedClauses();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Clause> _r = std::dynamic_pointer_cast<uml::Clause>(ref);
				if (_r != nullptr)
				{
					_selectedClauses->push_back(_r);
				}				
			}
			return;
		}
	}
	StructuredActivityNodeActivationImpl::resolveReferences(featureID, references);
}

void ConditionalNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredActivityNodeActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ConditionalNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<uml::Clause>> selectedClauses_list = this->getSelectedClauses();
		for (std::shared_ptr<uml::Clause > object : *selectedClauses_list)
		{ 
			saveHandler->addReferences("selectedClauses", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'clauseActivations'
		std::shared_ptr<Bag<fUML::Semantics::Actions::ClauseActivation>> list_clauseActivations = this->getClauseActivations();
		for (std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> clauseActivations : *list_clauseActivations) 
		{
			saveHandler->addReference(clauseActivations, "clauseActivations", clauseActivations->eClass() !=fUML::Semantics::Actions::ActionsPackage::eInstance()->getClauseActivation_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

