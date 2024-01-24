
#include "uml/impl/ActionImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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
#include <stdexcept>
#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
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
//Factories and Package includes
#include "uml/umlPackage.hpp"

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
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Action 
	 * which is generated by the compiler (as Action is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Action::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Action "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isLocallyReentrant = obj.getIsLocallyReentrant();

	//copy references with no containment (soft copy)
	m_context  = obj.getContext();
	//Clone references with containment (deep copy)
	//clone reference 'localPostcondition'
	const std::shared_ptr<Subset<uml::Constraint, uml::Element>>& localPostconditionList = obj.getLocalPostcondition();
	if(localPostconditionList)
	{
		/*Subset*/
		m_localPostcondition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_localPostcondition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getLocalPostcondition()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_localPostcondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Constraint>& localPostconditionindexElem: *localPostconditionList) 
		{
			const std::shared_ptr<uml::Constraint>& temp = std::dynamic_pointer_cast<uml::Constraint>((localPostconditionindexElem)->copy());
			m_localPostcondition->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for localPostcondition.")
	}

	//clone reference 'localPrecondition'
	const std::shared_ptr<Subset<uml::Constraint, uml::Element>>& localPreconditionList = obj.getLocalPrecondition();
	if(localPreconditionList)
	{
		/*Subset*/
		m_localPrecondition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_localPrecondition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getLocalPrecondition()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_localPrecondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Constraint>& localPreconditionindexElem: *localPreconditionList) 
		{
			const std::shared_ptr<uml::Constraint>& temp = std::dynamic_pointer_cast<uml::Constraint>((localPreconditionindexElem)->copy());
			m_localPrecondition->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for localPrecondition.")
	}
	/*Subset*/
	getLocalPostcondition()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_localPostcondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	getLocalPrecondition()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_localPrecondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Action>> ActionImpl::allActions()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::ActivityNode>> ActionImpl::allOwnedNodes()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Behavior> ActionImpl::containingBehavior()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}



//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isLocallyReentrant */
bool ActionImpl::getIsLocallyReentrant() const 
{
	return m_isLocallyReentrant;
}
void ActionImpl::setIsLocallyReentrant(bool _isLocallyReentrant)
{
	m_isLocallyReentrant = _isLocallyReentrant;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference context */
const std::shared_ptr<uml::Classifier>& ActionImpl::getContext() const
{
    return m_context;
}

/* Getter & Setter for reference input */

/* Getter & Setter for reference localPostcondition */
const std::shared_ptr<Subset<uml::Constraint, uml::Element>>& ActionImpl::getLocalPostcondition() const
{
	if(m_localPostcondition == nullptr)
	{
		/*Subset*/
		m_localPostcondition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_localPostcondition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getLocalPostcondition()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_localPostcondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_localPostcondition;
}

/* Getter & Setter for reference localPrecondition */
const std::shared_ptr<Subset<uml::Constraint, uml::Element>>& ActionImpl::getLocalPrecondition() const
{
	if(m_localPrecondition == nullptr)
	{
		/*Subset*/
		m_localPrecondition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_localPrecondition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getLocalPrecondition()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_localPrecondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_localPrecondition;
}

/* Getter & Setter for reference output */

//*********************************
// Union Getter
//*********************************
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
		getInput()->initSubsetUnion(getOwnedElement());
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
		getOutput()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

//*********************************
// Container Getter
//*********************************
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
				typeName = "uml::InputPin";
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::InputPin> new_input = std::dynamic_pointer_cast<uml::InputPin>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::ACTION_ATTRIBUTE_INPUT));
			if(new_input)
			{
				loadHandler->handleChild(new_input);
				getInput()->push_back(new_input);
			} 

			return; 
		}

		if ( nodeName.compare("localPostcondition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "uml::Constraint";
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::Constraint> new_localPostcondition = std::dynamic_pointer_cast<uml::Constraint>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::ACTION_ATTRIBUTE_LOCALPOSTCONDITION));
			if(new_localPostcondition)
			{
				loadHandler->handleChild(new_localPostcondition);
				getLocalPostcondition()->push_back(new_localPostcondition);
			} 

			return; 
		}

		if ( nodeName.compare("localPrecondition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "uml::Constraint";
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::Constraint> new_localPrecondition = std::dynamic_pointer_cast<uml::Constraint>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::ACTION_ATTRIBUTE_LOCALPRECONDITION));
			if(new_localPrecondition)
			{
				loadHandler->handleChild(new_localPrecondition);
				getLocalPrecondition()->push_back(new_localPrecondition);
			} 

			return; 
		}

		if ( nodeName.compare("output") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "uml::OutputPin";
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::OutputPin> new_output = std::dynamic_pointer_cast<uml::OutputPin>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::ACTION_ATTRIBUTE_OUTPUT));
			if(new_output)
			{
				loadHandler->handleChild(new_output);
				getOutput()->push_back(new_output);
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
	ExecutableNodeImpl::loadNode(nodeName, loadHandler);
}

void ActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
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
		for (const std::shared_ptr<uml::Constraint>& localPostcondition : *this->getLocalPostcondition()) 
		{
			saveHandler->addReference(localPostcondition, "localPostcondition", localPostcondition->eClass() != package->getConstraint_Class());
		}

		// Save 'localPrecondition'
		for (const std::shared_ptr<uml::Constraint>& localPrecondition : *this->getLocalPrecondition()) 
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
	    if ( this->eIsSet(package->getAction_Attribute_input()) )
	    {
		saveHandler->addReferences<uml::InputPin>("input", this->getInput());
	    }

		// Save 'output'
	    if ( this->eIsSet(package->getAction_Attribute_output()) )
	    {
		saveHandler->addReferences<uml::OutputPin>("output", this->getOutput());
	    }
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTION_ATTRIBUTE_CONTEXT:
			return eAny(getContext(),uml::umlPackage::CLASSIFIER_CLASS,false); //421
		case uml::umlPackage::ACTION_ATTRIBUTE_INPUT:
			return eEcoreContainerAny(getInput(),uml::umlPackage::INPUTPIN_CLASS); //422
		case uml::umlPackage::ACTION_ATTRIBUTE_ISLOCALLYREENTRANT:
			return eAny(getIsLocallyReentrant(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //423
		case uml::umlPackage::ACTION_ATTRIBUTE_LOCALPOSTCONDITION:
			return eEcoreContainerAny(getLocalPostcondition(),uml::umlPackage::CONSTRAINT_CLASS); //424
		case uml::umlPackage::ACTION_ATTRIBUTE_LOCALPRECONDITION:
			return eEcoreContainerAny(getLocalPrecondition(),uml::umlPackage::CONSTRAINT_CLASS); //425
		case uml::umlPackage::ACTION_ATTRIBUTE_OUTPUT:
			return eEcoreContainerAny(getOutput(),uml::umlPackage::OUTPUTPIN_CLASS); //426
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

bool ActionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTION_ATTRIBUTE_ISLOCALLYREENTRANT:
		{
			try
			{
				bool _isLocallyReentrant = newValue->get<bool>();
				setIsLocallyReentrant(_isLocallyReentrant); //423
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isLocallyReentrant'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTION_ATTRIBUTE_LOCALPOSTCONDITION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Constraint>>& _localPostcondition = getLocalPostcondition();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Constraint> valueToAdd = std::dynamic_pointer_cast<uml::Constraint>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_localPostcondition->includes(valueToAdd)))
								{
									_localPostcondition->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'localPostcondition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'localPostcondition'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTION_ATTRIBUTE_LOCALPRECONDITION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Constraint>>& _localPrecondition = getLocalPrecondition();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Constraint> valueToAdd = std::dynamic_pointer_cast<uml::Constraint>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_localPrecondition->includes(valueToAdd)))
								{
									_localPrecondition->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'localPrecondition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'localPrecondition'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ExecutableNodeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ActionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Action::allActions() : uml::Action[*]: 666610799
		case umlPackage::ACTION_OPERATION_ALLACTIONS:
		{
			std::shared_ptr<Bag<uml::Action>> resultList = this->allActions();
			return eEcoreContainerAny(resultList,uml::umlPackage::ACTION_CLASS);
			break;
		}
		// uml::Action::allOwnedNodes() : uml::ActivityNode[*]: 1529799585
		case umlPackage::ACTION_OPERATION_ALLOWNEDNODES:
		{
			std::shared_ptr<Bag<uml::ActivityNode>> resultList = this->allOwnedNodes();
			return eEcoreContainerAny(resultList,uml::umlPackage::ACTIVITYNODE_CLASS);
			break;
		}
		// uml::Action::containingBehavior() : uml::Behavior: 3666051963
		case umlPackage::ACTION_OPERATION_CONTAININGBEHAVIOR:
		{
			result = eEcoreAny(this->containingBehavior(), uml::umlPackage::BEHAVIOR_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ExecutableNodeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Action> ActionImpl::getThisActionPtr() const
{
	return m_thisActionPtr.lock();
}
void ActionImpl::setThisActionPtr(std::weak_ptr<uml::Action> thisActionPtr)
{
	m_thisActionPtr = thisActionPtr;
	setThisExecutableNodePtr(thisActionPtr);
}


