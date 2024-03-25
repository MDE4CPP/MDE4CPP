
#include "fUML/Semantics/Actions/impl/DestroyObjectActionActivationImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


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
//Includes from codegen annotation
#include "uml/Property.hpp"
#include "uml/DestroyObjectAction.hpp"
//#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
//#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/DestroyObjectAction.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
DestroyObjectActionActivationImpl::DestroyObjectActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DestroyObjectActionActivationImpl::~DestroyObjectActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DestroyObjectActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DestroyObjectActionActivationImpl::DestroyObjectActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:DestroyObjectActionActivationImpl()
{
	m_group = par_group;
}

DestroyObjectActionActivationImpl::DestroyObjectActionActivationImpl(const DestroyObjectActionActivationImpl & obj): DestroyObjectActionActivationImpl()
{
	*this = obj;
}

DestroyObjectActionActivationImpl& DestroyObjectActionActivationImpl::operator=(const DestroyObjectActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DestroyObjectActionActivation 
	 * which is generated by the compiler (as DestroyObjectActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DestroyObjectActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DestroyObjectActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_destroyObjectAction  = obj.getDestroyObjectAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DestroyObjectActionActivationImpl::copy() const
{
	std::shared_ptr<DestroyObjectActionActivationImpl> element(new DestroyObjectActionActivationImpl());
	*element =(*this);
	element->setThisDestroyObjectActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void DestroyObjectActionActivationImpl::destroyObject(const std::shared_ptr<Any>& value, bool isDestroyLinks, bool isDestroyOwnedObjects)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// If the given value contains an uml::Element, then destroy the contained object, per the given destroy action attribute values.

	try
	{
		std::shared_ptr<uml::Element> object = value->get<std::shared_ptr<uml::Element>>();

		if (isDestroyLinks || isDestroyOwnedObjects)
		{	
			/*Currently not supported
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extensionalValues = this->getExecutionLocus()->getExtensionalValues();
			for(const std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue>& extensionalValue : *extensionalValues)
			{
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link> (extensionalValue);
				if (link)
				{
					if (this->valueParticipatesInLink(reference, link))
					{
						if (isDestroyLinks | this->objectIsComposite(reference, link))
						{
							link->destroy();
						}
					}
				}
			}
			*/
		}
		if (isDestroyOwnedObjects)
		{	
			/*Currently not supported
			std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> objectFeatureValues = reference->retrieveFeatureValues();
			for(const std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue>& featureValue : *objectFeatureValues)
			{
				std::shared_ptr<uml::Property> property = std::dynamic_pointer_cast<uml::Property> (featureValue->getFeature());
				if(property)
				{
					if (property->getAggregation() == uml::AggregationKind::COMPOSITE)
					{
						std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = featureValue->getValues();
						for(const std::shared_ptr<fUML::Semantics::Values::Value>& ownedValue : *values)
						{
							this->destroyObject(ownedValue, isDestroyLinks, isDestroyOwnedObjects);

						}
					}
				}
			}
			*/
		}
		object->destroy();
	}
	catch(...)
	{
		DEBUG_ERROR("Provided object is not an instance of uml::Element! Failed to destroy object!")
	}
	//end of body
}

void DestroyObjectActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Get the value on the target input pin.
	// If the value is not a reference, then the action has no effect. Otherwise, do the following.
	// If isDestroyLinks is true, destroy all links in which the referent participates.
	// If isDestroyOwnedObjects is true, destroy all objects owned by the referent via composition links.
	// Destroy the referent object.

	const std::shared_ptr<uml::DestroyObjectAction>& action = this->getDestroyObjectAction();
	if(action)
	{
		const std::shared_ptr<uml::InputPin>& destroyTarget=action->getTarget();
		if(destroyTarget)
		{
			std::shared_ptr<Bag<Any>> tokens = this->takeTokens(destroyTarget);
			for(const std::shared_ptr<Any>& value : *tokens)
			{
				this->destroyObject(value, action->getIsDestroyLinks(), action->getIsDestroyOwnedObjects());
			}
		}
		else
		{
			throw "invalid target pin";
		}
	}
	//end of body
}

bool DestroyObjectActionActivationImpl::objectIsComposite(const std::shared_ptr<uml::Element>& reference, const std::shared_ptr<uml::Element>& link)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Test whether the given reference participates in the given link as a composite.
	/*Currently not supported
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> linkFeatureValues = link->getFeatureValues();
	for(const std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue>& featureValue : *linkFeatureValues)
	{
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values= featureValue->getValues();
		for(&std::shared_ptr<fUML::Semantics::Values::Value>& value : *values)
		{
			value->equals(reference);

			if(!(value->equals(reference)))
			{

				std::shared_ptr<uml::Property> property = std::dynamic_pointer_cast<uml::Property> (featureValue->getFeature());
				if(property)
				{
					if (property->getAggregation() == uml::AggregationKind::COMPOSITE)
					{
						return true;
					}
				}
			}
		}
	}
	*/
	return false;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference destroyObjectAction */
const std::shared_ptr<uml::DestroyObjectAction>& DestroyObjectActionActivationImpl::getDestroyObjectAction() const
{
    return m_destroyObjectAction;
}
void DestroyObjectActionActivationImpl::setDestroyObjectAction(const std::shared_ptr<uml::DestroyObjectAction>& _destroyObjectAction)
{
    m_destroyObjectAction = _destroyObjectAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_destroyObjectAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void DestroyObjectActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>(_action);
	if(_destroyObjectAction)
	{
		m_destroyObjectAction = _destroyObjectAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_destroyObjectAction);
	}
	else
	{
		std::cerr<<"[DestroyObjectActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::DestroyObjectAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void DestroyObjectActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>(_node);
	if(_destroyObjectAction)
	{
		m_destroyObjectAction = _destroyObjectAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[DestroyObjectActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::DestroyObjectAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DestroyObjectActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void DestroyObjectActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DestroyObjectActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("destroyObjectAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("destroyObjectAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void DestroyObjectActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void DestroyObjectActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYOBJECTACTIONACTIVATION_ATTRIBUTE_DESTROYOBJECTACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>( references.front() );
				setDestroyObjectAction(_destroyObjectAction);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void DestroyObjectActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DestroyObjectActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getDestroyObjectActionActivation_Attribute_destroyObjectAction()) )
	{
		saveHandler->addReference(this->getDestroyObjectAction(), "destroyObjectAction", getDestroyObjectAction()->eClass() != uml::umlPackage::eInstance()->getDestroyObjectAction_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& DestroyObjectActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getDestroyObjectActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> DestroyObjectActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYOBJECTACTIONACTIVATION_ATTRIBUTE_DESTROYOBJECTACTION:
			return eAny(getDestroyObjectAction(),uml::umlPackage::DESTROYOBJECTACTION_CLASS,false); //3911
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool DestroyObjectActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYOBJECTACTIONACTIVATION_ATTRIBUTE_DESTROYOBJECTACTION:
			return getDestroyObjectAction() != nullptr; //3911
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool DestroyObjectActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYOBJECTACTIONACTIVATION_ATTRIBUTE_DESTROYOBJECTACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>(eObject);
					if(_destroyObjectAction)
					{
						setDestroyObjectAction(_destroyObjectAction); //3911
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'destroyObjectAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'destroyObjectAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> DestroyObjectActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::DestroyObjectActionActivation::destroyObject(Any, bool, bool): 3697661383
		case ActionsPackage::DESTROYOBJECTACTIONACTIVATION_OPERATION_DESTROYOBJECT_EJAVAOBJECT_EBOOLEAN:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::shared_ptr<Any> incoming_param_value;
			Bag<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'value'. Failed to invoke operation 'destroyObject'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'isDestroyLinks'
			//parameter 1
			bool incoming_param_isDestroyLinks;
			Bag<Any>::const_iterator incoming_param_isDestroyLinks_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_isDestroyLinks = (*incoming_param_isDestroyLinks_arguments_citer)->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'isDestroyLinks'. Failed to invoke operation 'destroyObject'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'isDestroyOwnedObjects'
			//parameter 2
			bool incoming_param_isDestroyOwnedObjects;
			Bag<Any>::const_iterator incoming_param_isDestroyOwnedObjects_arguments_citer = std::next(arguments->begin(), 2);
			try
			{
				incoming_param_isDestroyOwnedObjects = (*incoming_param_isDestroyOwnedObjects_arguments_citer)->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'isDestroyOwnedObjects'. Failed to invoke operation 'destroyObject'!")
				return nullptr;
			}
		
			this->destroyObject(incoming_param_value,incoming_param_isDestroyLinks,incoming_param_isDestroyOwnedObjects);
			break;
		}
		// fUML::Semantics::Actions::DestroyObjectActionActivation::doAction(): 393014891
		case ActionsPackage::DESTROYOBJECTACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}
		// fUML::Semantics::Actions::DestroyObjectActionActivation::objectIsComposite(uml::Element, uml::Element) : bool: 4059157106
		case ActionsPackage::DESTROYOBJECTACTIONACTIVATION_OPERATION_OBJECTISCOMPOSITE_ELEMENT_ELEMENT:
		{
			//Retrieve input parameter 'reference'
			//parameter 0
			std::shared_ptr<uml::Element> incoming_param_reference;
			Bag<Any>::const_iterator incoming_param_reference_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_reference_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_reference = std::dynamic_pointer_cast<uml::Element>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'reference'. Failed to invoke operation 'objectIsComposite'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'reference'. Failed to invoke operation 'objectIsComposite'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'link'
			//parameter 1
			std::shared_ptr<uml::Element> incoming_param_link;
			Bag<Any>::const_iterator incoming_param_link_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_link_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_link = std::dynamic_pointer_cast<uml::Element>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'link'. Failed to invoke operation 'objectIsComposite'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'link'. Failed to invoke operation 'objectIsComposite'!")
					return nullptr;
				}
			}
		
			result = eAny(this->objectIsComposite(incoming_param_reference,incoming_param_link), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = ActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> DestroyObjectActionActivationImpl::getThisDestroyObjectActionActivationPtr() const
{
	return m_thisDestroyObjectActionActivationPtr.lock();
}
void DestroyObjectActionActivationImpl::setThisDestroyObjectActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> thisDestroyObjectActionActivationPtr)
{
	m_thisDestroyObjectActionActivationPtr = thisDestroyObjectActionActivationPtr;
	setThisActionActivationPtr(thisDestroyObjectActionActivationPtr);
}


