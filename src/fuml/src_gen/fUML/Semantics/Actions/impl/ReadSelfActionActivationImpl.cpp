
#include "fUML/Semantics/Actions/impl/ReadSelfActionActivationImpl.hpp"
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
#include "uml/UMLAny.hpp"
#include "uml/ReadSelfAction.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/ReadSelfAction.hpp"
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
ReadSelfActionActivationImpl::ReadSelfActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReadSelfActionActivationImpl::~ReadSelfActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReadSelfActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReadSelfActionActivationImpl::ReadSelfActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ReadSelfActionActivationImpl()
{
	m_group = par_group;
}

ReadSelfActionActivationImpl::ReadSelfActionActivationImpl(const ReadSelfActionActivationImpl & obj): ReadSelfActionActivationImpl()
{
	*this = obj;
}

ReadSelfActionActivationImpl& ReadSelfActionActivationImpl::operator=(const ReadSelfActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ReadSelfActionActivation 
	 * which is generated by the compiler (as ReadSelfActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ReadSelfActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReadSelfActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_readSelfAction  = obj.getReadSelfAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ReadSelfActionActivationImpl::copy() const
{
	std::shared_ptr<ReadSelfActionActivationImpl> element(new ReadSelfActionActivationImpl());
	*element =(*this);
	element->setThisReadSelfActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ReadSelfActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the context object of the activity execution containing this action activation and place a reference to it on the result output pin.
	std::shared_ptr<uml::ReadSelfAction> action = this->getReadSelfAction();

	std::shared_ptr<uml::Element> context=this->getExecutionContext();	
	if(context)
	{
		std::shared_ptr<Any> value = eUMLAny(context, context->getMetaElementID());
		std::shared_ptr<uml::OutputPin> resultPin = action->getResult();
		if(resultPin)
		{
			this->putToken(resultPin, value);
		}
		else
		{
			DEBUG_ERROR("Result pin is nullptr! Failed to read self!")
		}
	}
	else
	{
		DEBUG_ERROR("Context nullptr! Failed to read self!")
	}
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference readSelfAction */
std::shared_ptr<uml::ReadSelfAction> ReadSelfActionActivationImpl::getReadSelfAction() const
{
    return m_readSelfAction;
}
void ReadSelfActionActivationImpl::setReadSelfAction(std::shared_ptr<uml::ReadSelfAction> _readSelfAction)
{
    m_readSelfAction = _readSelfAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_readSelfAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void ReadSelfActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::ReadSelfAction> _readSelfAction = std::dynamic_pointer_cast<uml::ReadSelfAction>(_action);
	if(_readSelfAction)
	{
		m_readSelfAction = _readSelfAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_readSelfAction);
	}
	else
	{
		std::cerr<<"[ReadSelfActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::ReadSelfAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void ReadSelfActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::ReadSelfAction> _readSelfAction = std::dynamic_pointer_cast<uml::ReadSelfAction>(_node);
	if(_readSelfAction)
	{
		m_readSelfAction = _readSelfAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[ReadSelfActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::ReadSelfAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ReadSelfActionActivationImpl::eContainer() const
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
void ReadSelfActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReadSelfActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("readSelfAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("readSelfAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ReadSelfActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void ReadSelfActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSELFACTIONACTIVATION_ATTRIBUTE_READSELFACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ReadSelfAction> _readSelfAction = std::dynamic_pointer_cast<uml::ReadSelfAction>( references.front() );
				setReadSelfAction(_readSelfAction);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void ReadSelfActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ReadSelfActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getReadSelfAction(), "readSelfAction", getReadSelfAction()->eClass() != uml::umlPackage::eInstance()->getReadSelfAction_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ReadSelfActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getReadSelfActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ReadSelfActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSELFACTIONACTIVATION_ATTRIBUTE_READSELFACTION:
			return eAny(getReadSelfAction(),uml::umlPackage::READSELFACTION_CLASS,false); //9211
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool ReadSelfActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSELFACTIONACTIVATION_ATTRIBUTE_READSELFACTION:
			return getReadSelfAction() != nullptr; //9211
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool ReadSelfActionActivationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSELFACTIONACTIVATION_ATTRIBUTE_READSELFACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ReadSelfAction> _readSelfAction = std::dynamic_pointer_cast<uml::ReadSelfAction>(eObject);
					if(_readSelfAction)
					{
						setReadSelfAction(_readSelfAction); //9211
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'readSelfAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'readSelfAction'. Failed to set feature!")
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
std::shared_ptr<Any> ReadSelfActionActivationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::ReadSelfActionActivation::doAction(): 2282322208
		case ActionsPackage::READSELFACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
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

std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> ReadSelfActionActivationImpl::getThisReadSelfActionActivationPtr() const
{
	return m_thisReadSelfActionActivationPtr.lock();
}
void ReadSelfActionActivationImpl::setThisReadSelfActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> thisReadSelfActionActivationPtr)
{
	m_thisReadSelfActionActivationPtr = thisReadSelfActionActivationPtr;
	setThisActionActivationPtr(thisReadSelfActionActivationPtr);
}


