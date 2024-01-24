
#include "fUML/Semantics/Actions/impl/ReadExtentActionActivationImpl.hpp"
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
#include "uml/Classifier.hpp"
#include "uml/UMLAny.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/ReadExtentAction.hpp"
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
ReadExtentActionActivationImpl::ReadExtentActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReadExtentActionActivationImpl::~ReadExtentActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReadExtentActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReadExtentActionActivationImpl::ReadExtentActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ReadExtentActionActivationImpl()
{
	m_group = par_group;
}

ReadExtentActionActivationImpl::ReadExtentActionActivationImpl(const ReadExtentActionActivationImpl & obj): ReadExtentActionActivationImpl()
{
	*this = obj;
}

ReadExtentActionActivationImpl& ReadExtentActionActivationImpl::operator=(const ReadExtentActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ReadExtentActionActivation 
	 * which is generated by the compiler (as ReadExtentActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ReadExtentActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReadExtentActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_readExtentAction  = obj.getReadExtentAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ReadExtentActionActivationImpl::copy() const
{
	std::shared_ptr<ReadExtentActionActivationImpl> element(new ReadExtentActionActivationImpl());
	*element =(*this);
	element->setThisReadExtentActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ReadExtentActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the extent, at the current execution locus, of the classifier (which must be a class) identified in the action.
// Place references to the resulting set of objects on the result pin.

const std::shared_ptr<uml::ReadExtentAction>& action = this->getReadExtentAction();

std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Object>> objects = this->getExecutionLocus()->retrieveExtent(action->getClassifier());
std::shared_ptr<Bag<Any>> values(new Bag<Any>());

const unsigned long classifierID = action->getClassifier()->_getID();

for(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& object : *objects)
{
	values->add(eUMLAny(object, classifierID));
}

this->putTokens(action->getResult(), values);
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference readExtentAction */
const std::shared_ptr<uml::ReadExtentAction>& ReadExtentActionActivationImpl::getReadExtentAction() const
{
    return m_readExtentAction;
}
void ReadExtentActionActivationImpl::setReadExtentAction(const std::shared_ptr<uml::ReadExtentAction>& _readExtentAction)
{
    m_readExtentAction = _readExtentAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_readExtentAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void ReadExtentActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::ReadExtentAction> _readExtentAction = std::dynamic_pointer_cast<uml::ReadExtentAction>(_action);
	if(_readExtentAction)
	{
		m_readExtentAction = _readExtentAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_readExtentAction);
	}
	else
	{
		std::cerr<<"[ReadExtentActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::ReadExtentAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void ReadExtentActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::ReadExtentAction> _readExtentAction = std::dynamic_pointer_cast<uml::ReadExtentAction>(_node);
	if(_readExtentAction)
	{
		m_readExtentAction = _readExtentAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[ReadExtentActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::ReadExtentAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ReadExtentActionActivationImpl::eContainer() const
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
void ReadExtentActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReadExtentActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("readExtentAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("readExtentAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ReadExtentActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void ReadExtentActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READEXTENTACTIONACTIVATION_ATTRIBUTE_READEXTENTACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ReadExtentAction> _readExtentAction = std::dynamic_pointer_cast<uml::ReadExtentAction>( references.front() );
				setReadExtentAction(_readExtentAction);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void ReadExtentActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ReadExtentActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getReadExtentActionActivation_Attribute_readExtentAction()) )
	{
		saveHandler->addReference(this->getReadExtentAction(), "readExtentAction", getReadExtentAction()->eClass() != uml::umlPackage::eInstance()->getReadExtentAction_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ReadExtentActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getReadExtentActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ReadExtentActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READEXTENTACTIONACTIVATION_ATTRIBUTE_READEXTENTACTION:
			return eAny(getReadExtentAction(),uml::umlPackage::READEXTENTACTION_CLASS,false); //9111
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool ReadExtentActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READEXTENTACTIONACTIVATION_ATTRIBUTE_READEXTENTACTION:
			return getReadExtentAction() != nullptr; //9111
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool ReadExtentActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READEXTENTACTIONACTIVATION_ATTRIBUTE_READEXTENTACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ReadExtentAction> _readExtentAction = std::dynamic_pointer_cast<uml::ReadExtentAction>(eObject);
					if(_readExtentAction)
					{
						setReadExtentAction(_readExtentAction); //9111
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'readExtentAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'readExtentAction'. Failed to set feature!")
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
std::shared_ptr<Any> ReadExtentActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::ReadExtentActionActivation::doAction(): 2912116878
		case ActionsPackage::READEXTENTACTIONACTIVATION_OPERATION_DOACTION:
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

std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> ReadExtentActionActivationImpl::getThisReadExtentActionActivationPtr() const
{
	return m_thisReadExtentActionActivationPtr.lock();
}
void ReadExtentActionActivationImpl::setThisReadExtentActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> thisReadExtentActionActivationPtr)
{
	m_thisReadExtentActionActivationPtr = thisReadExtentActionActivationPtr;
	setThisActionActivationPtr(thisReadExtentActionActivationPtr);
}


