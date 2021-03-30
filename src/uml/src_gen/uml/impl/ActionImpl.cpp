#include "uml/impl/ActionImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


#include "uml/Action.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/ExecutableNode.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActionImpl::ActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActionImpl::~ActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Action "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActionImpl::ActionImpl(std::weak_ptr<uml::Activity> par_activity)
:ActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ActionImpl::ActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ActionImpl::ActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ActionImpl::ActionImpl(std::weak_ptr<uml::Element> par_owner)
:ActionImpl()
{
	m_owner = par_owner;
}

ActionImpl::ActionImpl(const ActionImpl & obj): ActionImpl()
{
	*this = obj;
}

ActionImpl& ActionImpl::operator=(const ActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ExecutableNodeImpl::operator=(obj);
	Action::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Action "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isLocallyReentrant = obj.getIsLocallyReentrant();

	//copy references with no containment (soft copy)
	m_context  = obj.getContext();
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Constraint, uml::Element>> localPostconditionContainer = getLocalPostcondition();
	if(nullptr != localPostconditionContainer )
	{
		int size = localPostconditionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _localPostcondition=(*localPostconditionContainer)[i];
			if(nullptr != _localPostcondition)
			{
				localPostconditionContainer->push_back(std::dynamic_pointer_cast<uml::Constraint>(_localPostcondition->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container localPostcondition."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr localPostcondition."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Constraint, uml::Element>> localPreconditionContainer = getLocalPrecondition();
	if(nullptr != localPreconditionContainer )
	{
		int size = localPreconditionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _localPrecondition=(*localPreconditionContainer)[i];
			if(nullptr != _localPrecondition)
			{
				localPreconditionContainer->push_back(std::dynamic_pointer_cast<uml::Constraint>(_localPrecondition->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container localPrecondition."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr localPrecondition."<< std::endl;)
	}
	/*Subset*/
	m_localPostcondition->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_localPostcondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_localPrecondition->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_localPrecondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ActionImpl::copy() const
{
	std::shared_ptr<ActionImpl> element(new ActionImpl());
	*element =(*this);
	element->setThisActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isLocallyReentrant
*/
bool ActionImpl::getIsLocallyReentrant() const 
{
	return m_isLocallyReentrant;
}
void ActionImpl::setIsLocallyReentrant(bool _isLocallyReentrant)
{
	m_isLocallyReentrant = _isLocallyReentrant;
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Action> > ActionImpl::allActions()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::ActivityNode> > ActionImpl::allOwnedNodes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Behavior> ActionImpl::containingBehavior()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



//*********************************
// References
//*********************************
/*
Getter & Setter for reference context
*/
std::shared_ptr<uml::Classifier> ActionImpl::getContext() const
{

    return m_context;
}



/*
Getter & Setter for reference input
*/




/*
Getter & Setter for reference localPostcondition
*/
std::shared_ptr<Subset<uml::Constraint, uml::Element>> ActionImpl::getLocalPostcondition() const
{
	if(m_localPostcondition == nullptr)
	{
		/*Subset*/
		m_localPostcondition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_localPostcondition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_localPostcondition->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_localPostcondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_localPostcondition;
}



/*
Getter & Setter for reference localPrecondition
*/
std::shared_ptr<Subset<uml::Constraint, uml::Element>> ActionImpl::getLocalPrecondition() const
{
	if(m_localPrecondition == nullptr)
	{
		/*Subset*/
		m_localPrecondition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_localPrecondition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_localPrecondition->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_localPrecondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_localPrecondition;
}



/*
Getter & Setter for reference output
*/




//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ActionImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> ActionImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_input->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> ActionImpl::getOutput() const
{
	if(m_output == nullptr)
	{
		/*SubsetUnion*/
		m_output.reset(new SubsetUnion<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_output->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

std::shared_ptr<Union<uml::Element>> ActionImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> ActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ActionImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<Action> ActionImpl::getThisActionPtr() const
{
	return m_thisActionPtr.lock();
}
void ActionImpl::setThisActionPtr(std::weak_ptr<Action> thisActionPtr)
{
	m_thisActionPtr = thisActionPtr;
	setThisExecutableNodePtr(thisActionPtr);
}
std::shared_ptr<ecore::EObject> ActionImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTION_ATTRIBUTE_CONTEXT:
			return eAny(getContext()); //421
		case uml::umlPackage::ACTION_ATTRIBUTE_INPUT:
		{
			return eAny(getInput()); //422			
		}
		case uml::umlPackage::ACTION_ATTRIBUTE_ISLOCALLYREENTRANT:
			return eAny(getIsLocallyReentrant()); //423
		case uml::umlPackage::ACTION_ATTRIBUTE_LOCALPOSTCONDITION:
		{
			return eAny(getLocalPostcondition()); //424			
		}
		case uml::umlPackage::ACTION_ATTRIBUTE_LOCALPRECONDITION:
		{
			return eAny(getLocalPrecondition()); //425			
		}
		case uml::umlPackage::ACTION_ATTRIBUTE_OUTPUT:
		{
			return eAny(getOutput()); //426			
		}
	}
	return ExecutableNodeImpl::eGet(featureID, resolve, coreType);
}
bool ActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTION_ATTRIBUTE_CONTEXT:
			return getContext() != nullptr; //421
		case uml::umlPackage::ACTION_ATTRIBUTE_INPUT:
			return getInput() != nullptr; //422
		case uml::umlPackage::ACTION_ATTRIBUTE_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant() != false; //423
		case uml::umlPackage::ACTION_ATTRIBUTE_LOCALPOSTCONDITION:
			return getLocalPostcondition() != nullptr; //424
		case uml::umlPackage::ACTION_ATTRIBUTE_LOCALPRECONDITION:
			return getLocalPrecondition() != nullptr; //425
		case uml::umlPackage::ACTION_ATTRIBUTE_OUTPUT:
			return getOutput() != nullptr; //426
	}
	return ExecutableNodeImpl::internalEIsSet(featureID);
}
bool ActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTION_ATTRIBUTE_ISLOCALLYREENTRANT:
		{
			// BOOST CAST
			bool _isLocallyReentrant = newValue->get<bool>();
			setIsLocallyReentrant(_isLocallyReentrant); //423
			return true;
		}
		case uml::umlPackage::ACTION_ATTRIBUTE_LOCALPOSTCONDITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> localPostconditionList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				localPostconditionList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterLocalPostcondition = m_localPostcondition->begin();
			Bag<uml::Constraint>::iterator endLocalPostcondition = m_localPostcondition->end();
			while (iterLocalPostcondition != endLocalPostcondition)
			{
				if (localPostconditionList->find(*iterLocalPostcondition) == -1)
				{
					m_localPostcondition->erase(*iterLocalPostcondition);
				}
				iterLocalPostcondition++;
			}
 
			iterLocalPostcondition = localPostconditionList->begin();
			endLocalPostcondition = localPostconditionList->end();
			while (iterLocalPostcondition != endLocalPostcondition)
			{
				if (m_localPostcondition->find(*iterLocalPostcondition) == -1)
				{
					m_localPostcondition->add(*iterLocalPostcondition);
				}
				iterLocalPostcondition++;			
			}
			return true;
		}
		case uml::umlPackage::ACTION_ATTRIBUTE_LOCALPRECONDITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> localPreconditionList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				localPreconditionList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterLocalPrecondition = m_localPrecondition->begin();
			Bag<uml::Constraint>::iterator endLocalPrecondition = m_localPrecondition->end();
			while (iterLocalPrecondition != endLocalPrecondition)
			{
				if (localPreconditionList->find(*iterLocalPrecondition) == -1)
				{
					m_localPrecondition->erase(*iterLocalPrecondition);
				}
				iterLocalPrecondition++;
			}
 
			iterLocalPrecondition = localPreconditionList->begin();
			endLocalPrecondition = localPreconditionList->end();
			while (iterLocalPrecondition != endLocalPrecondition)
			{
				if (m_localPrecondition->find(*iterLocalPrecondition) == -1)
				{
					m_localPrecondition->add(*iterLocalPrecondition);
				}
				iterLocalPrecondition++;			
			}
			return true;
		}
	}

	return ExecutableNodeImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isLocallyReentrant");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsLocallyReentrant(value);
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

	ExecutableNodeImpl::loadAttributes(loadHandler, attr_list);
}

void ActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("input") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChildContainer<uml::InputPin>(this->getInput());  

			return; 
		}

		if ( nodeName.compare("localPostcondition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			loadHandler->handleChildContainer<uml::Constraint>(this->getLocalPostcondition());  

			return; 
		}

		if ( nodeName.compare("localPrecondition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			loadHandler->handleChildContainer<uml::Constraint>(this->getLocalPrecondition());  

			return; 
		}

		if ( nodeName.compare("output") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			loadHandler->handleChildContainer<uml::OutputPin>(this->getOutput());  

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
	ExecutableNodeImpl::loadNode(nodeName, loadHandler);
}

void ActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ExecutableNodeImpl::resolveReferences(featureID, references);
}

void ActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void ActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'localPostcondition'
		for (std::shared_ptr<uml::Constraint> localPostcondition : *this->getLocalPostcondition()) 
		{
			saveHandler->addReference(localPostcondition, "localPostcondition", localPostcondition->eClass() != package->getConstraint_Class());
		}

		// Save 'localPrecondition'
		for (std::shared_ptr<uml::Constraint> localPrecondition : *this->getLocalPrecondition()) 
		{
			saveHandler->addReference(localPrecondition, "localPrecondition", localPrecondition->eClass() != package->getConstraint_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getAction_Attribute_isLocallyReentrant()) )
		{
			saveHandler->addAttribute("isLocallyReentrant", this->getIsLocallyReentrant());
		}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'input'

		saveHandler->addReferences<uml::InputPin>("input", this->getInput());

		// Save 'output'

		saveHandler->addReferences<uml::OutputPin>("output", this->getOutput());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

