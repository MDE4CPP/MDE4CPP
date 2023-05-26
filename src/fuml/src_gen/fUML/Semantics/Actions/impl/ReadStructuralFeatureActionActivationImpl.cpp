
#include "fUML/Semantics/Actions/impl/ReadStructuralFeatureActionActivationImpl.hpp"
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
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
//#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
//#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"
//#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
//#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/UMLAny.hpp"
#include "uml/InputPin.hpp"
#include "uml/ReadStructuralFeatureAction.hpp"
#include "uml/Property.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/ReadStructuralFeatureAction.hpp"
#include "fUML/Semantics/Actions/StructuralFeatureActionActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
ReadStructuralFeatureActionActivationImpl::ReadStructuralFeatureActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReadStructuralFeatureActionActivationImpl::~ReadStructuralFeatureActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReadStructuralFeatureActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReadStructuralFeatureActionActivationImpl::ReadStructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ReadStructuralFeatureActionActivationImpl()
{
	m_group = par_group;
}

ReadStructuralFeatureActionActivationImpl::ReadStructuralFeatureActionActivationImpl(const ReadStructuralFeatureActionActivationImpl & obj): ReadStructuralFeatureActionActivationImpl()
{
	*this = obj;
}

ReadStructuralFeatureActionActivationImpl& ReadStructuralFeatureActionActivationImpl::operator=(const ReadStructuralFeatureActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuralFeatureActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ReadStructuralFeatureActionActivation 
	 * which is generated by the compiler (as ReadStructuralFeatureActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ReadStructuralFeatureActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReadStructuralFeatureActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_readStructuralFeatureAction  = obj.getReadStructuralFeatureAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ReadStructuralFeatureActionActivationImpl::copy() const
{
	std::shared_ptr<ReadStructuralFeatureActionActivationImpl> element(new ReadStructuralFeatureActionActivationImpl());
	*element =(*this);
	element->setThisReadStructuralFeatureActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ReadStructuralFeatureActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::ReadStructuralFeatureAction> action = this->getReadStructuralFeatureAction();
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();
	std::shared_ptr<uml::Property> property = std::dynamic_pointer_cast<uml::Property>(feature);

	if(!property)
	{
		return;
	}

	std::shared_ptr<Any> value = nullptr;
	
	/* MDE4CPP specific implementation for handling "self"-Pin */
	std::string objectPinName = action->getObject()->getName();
	if((objectPinName.empty()) || (objectPinName.find("self") == 0)){
		//value is set to the context of the current activity execution
		std::shared_ptr<uml::Element> context = this->getActivityExecution()->getContext();
	
		value = eUMLAny(context, context->getMetaElementID());
	}
	else{
		value = this->takeTokens(action->getObject())->at(0);
	}
	/*--------------------------------------------------------*/

	std::shared_ptr<uml::Element> structuredValue = nullptr;

	try
	{
		std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);

		structuredValue = umlAny->getAsElement();

		if (structuredValue)
		{
			std::shared_ptr<Any> values = structuredValue->get(property);
			putToken(action->getResult(), values);
		}
		else
			
		{
	
			DEBUG_ERROR("Context is nullptr! Failed to read feature!")
			
		}
	}
	catch(...)
	{
		DEBUG_ERROR("Provided context is not an instance of uml::Element! Failed to read feature!")
	}
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference readStructuralFeatureAction */
const std::shared_ptr<uml::ReadStructuralFeatureAction>& ReadStructuralFeatureActionActivationImpl::getReadStructuralFeatureAction() const
{
    return m_readStructuralFeatureAction;
}
void ReadStructuralFeatureActionActivationImpl::setReadStructuralFeatureAction(const std::shared_ptr<uml::ReadStructuralFeatureAction>& _readStructuralFeatureAction)
{
    m_readStructuralFeatureAction = _readStructuralFeatureAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_readStructuralFeatureAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void ReadStructuralFeatureActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>(_action);
	if(_readStructuralFeatureAction)
	{
		m_readStructuralFeatureAction = _readStructuralFeatureAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_readStructuralFeatureAction);
	}
	else
	{
		std::cerr<<"[ReadStructuralFeatureActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::ReadStructuralFeatureAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void ReadStructuralFeatureActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>(_node);
	if(_readStructuralFeatureAction)
	{
		m_readStructuralFeatureAction = _readStructuralFeatureAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[ReadStructuralFeatureActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::ReadStructuralFeatureAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ReadStructuralFeatureActionActivationImpl::eContainer() const
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
void ReadStructuralFeatureActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReadStructuralFeatureActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("readStructuralFeatureAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("readStructuralFeatureAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	StructuralFeatureActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ReadStructuralFeatureActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	StructuralFeatureActionActivationImpl::loadNode(nodeName, loadHandler);
}

void ReadStructuralFeatureActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>( references.front() );
				setReadStructuralFeatureAction(_readStructuralFeatureAction);
			}
			
			return;
		}
	}
	StructuralFeatureActionActivationImpl::resolveReferences(featureID, references);
}

void ReadStructuralFeatureActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ReadStructuralFeatureActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getReadStructuralFeatureAction(), "readStructuralFeatureAction", getReadStructuralFeatureAction()->eClass() != uml::umlPackage::eInstance()->getReadStructuralFeatureAction_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ReadStructuralFeatureActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getReadStructuralFeatureActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ReadStructuralFeatureActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
			return eAny(getReadStructuralFeatureAction(),uml::umlPackage::READSTRUCTURALFEATUREACTION_CLASS,false); //9311
	}
	return StructuralFeatureActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool ReadStructuralFeatureActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
			return getReadStructuralFeatureAction() != nullptr; //9311
	}
	return StructuralFeatureActionActivationImpl::internalEIsSet(featureID);
}

bool ReadStructuralFeatureActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>(eObject);
					if(_readStructuralFeatureAction)
					{
						setReadStructuralFeatureAction(_readStructuralFeatureAction); //9311
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'readStructuralFeatureAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'readStructuralFeatureAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return StructuralFeatureActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ReadStructuralFeatureActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::ReadStructuralFeatureActionActivation::doAction(): 2509578359
		case ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = StructuralFeatureActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> ReadStructuralFeatureActionActivationImpl::getThisReadStructuralFeatureActionActivationPtr() const
{
	return m_thisReadStructuralFeatureActionActivationPtr.lock();
}
void ReadStructuralFeatureActionActivationImpl::setThisReadStructuralFeatureActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> thisReadStructuralFeatureActionActivationPtr)
{
	m_thisReadStructuralFeatureActionActivationPtr = thisReadStructuralFeatureActionActivationPtr;
	setThisStructuralFeatureActionActivationPtr(thisReadStructuralFeatureActionActivationPtr);
}


