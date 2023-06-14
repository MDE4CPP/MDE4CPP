
#include "fUML/Semantics/Actions/impl/ReadIsClassifiedObjectActionActivationImpl.hpp"
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
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "uml/Class.hpp"
#include "uml/OutputPin.hpp"
#include "uml/UMLAny.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/ReadIsClassifiedObjectAction.hpp"
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
ReadIsClassifiedObjectActionActivationImpl::ReadIsClassifiedObjectActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReadIsClassifiedObjectActionActivationImpl::~ReadIsClassifiedObjectActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReadIsClassifiedObjectActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReadIsClassifiedObjectActionActivationImpl::ReadIsClassifiedObjectActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ReadIsClassifiedObjectActionActivationImpl()
{
	m_group = par_group;
}

ReadIsClassifiedObjectActionActivationImpl::ReadIsClassifiedObjectActionActivationImpl(const ReadIsClassifiedObjectActionActivationImpl & obj): ReadIsClassifiedObjectActionActivationImpl()
{
	*this = obj;
}

ReadIsClassifiedObjectActionActivationImpl& ReadIsClassifiedObjectActionActivationImpl::operator=(const ReadIsClassifiedObjectActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ReadIsClassifiedObjectActionActivation 
	 * which is generated by the compiler (as ReadIsClassifiedObjectActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ReadIsClassifiedObjectActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReadIsClassifiedObjectActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_readIsClassifiedObjectAction  = obj.getReadIsClassifiedObjectAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ReadIsClassifiedObjectActionActivationImpl::copy() const
{
	std::shared_ptr<ReadIsClassifiedObjectActionActivationImpl> element(new ReadIsClassifiedObjectActionActivationImpl());
	*element =(*this);
	element->setThisReadIsClassifiedObjectActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ReadIsClassifiedObjectActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Get the value on the object input pin and determine if it is classified by the classifier specified in the action.
// If the isDirect attribute of the action is false, then place true on the result output pin if the input object has the specified classifier or of one its (direct or indirect) descendants as a type.
	// If the isDirect attribute of the action is true, then place true on the result output pin if the input object has the specified classifier as a type.
	// Otherwise place false on the result output pin.

	std::shared_ptr<uml::ReadIsClassifiedObjectAction> readIsClassifiedObjectAction = this->getReadIsClassifiedObjectAction();
	std::shared_ptr<uml::Classifier> classifier = readIsClassifiedObjectAction->getClassifier();
	bool isDirect = readIsClassifiedObjectAction->getIsDirect();
	bool result = false;

	std::shared_ptr<Any> inputAsAny = this->takeTokens(readIsClassifiedObjectAction->getObject())->at(0);

	if(inputAsAny)
	{
		try
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(inputAsAny);
			std::shared_ptr<uml::Element> input = umlAny->getAsElement();

			std::shared_ptr<uml::Classifier> typeOfInput = input->getMetaClass();

			result = (classifier == typeOfInput);

			if(!isDirect && !result)
			{

				std::shared_ptr<Bag<uml::Classifier>> superTypesOfInput = typeOfInput->allParents();

				for(std::shared_ptr<uml::Classifier> superType : *superTypesOfInput)
				{
					result = (classifier == superType);
			
					if(result)
					{
						break;
					}
				}
			}
		}
		catch(...)
		{
			DEBUG_ERROR("Provided input is not an instance of uml::Element. Failed read is classified!")
		}

		std::shared_ptr<Any> resultValue = eAny(result, 0, false);

		if(readIsClassifiedObjectAction->getResult())
		{
			this->putToken(readIsClassifiedObjectAction->getResult(), resultValue);
		}
	}
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference readIsClassifiedObjectAction */
const std::shared_ptr<uml::ReadIsClassifiedObjectAction>& ReadIsClassifiedObjectActionActivationImpl::getReadIsClassifiedObjectAction() const
{
    return m_readIsClassifiedObjectAction;
}
void ReadIsClassifiedObjectActionActivationImpl::setReadIsClassifiedObjectAction(const std::shared_ptr<uml::ReadIsClassifiedObjectAction>& _readIsClassifiedObjectAction)
{
    m_readIsClassifiedObjectAction = _readIsClassifiedObjectAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_readIsClassifiedObjectAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void ReadIsClassifiedObjectActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::ReadIsClassifiedObjectAction> _readIsClassifiedObjectAction = std::dynamic_pointer_cast<uml::ReadIsClassifiedObjectAction>(_action);
	if(_readIsClassifiedObjectAction)
	{
		m_readIsClassifiedObjectAction = _readIsClassifiedObjectAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_readIsClassifiedObjectAction);
	}
	else
	{
		std::cerr<<"[ReadIsClassifiedObjectActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::ReadIsClassifiedObjectAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void ReadIsClassifiedObjectActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::ReadIsClassifiedObjectAction> _readIsClassifiedObjectAction = std::dynamic_pointer_cast<uml::ReadIsClassifiedObjectAction>(_node);
	if(_readIsClassifiedObjectAction)
	{
		m_readIsClassifiedObjectAction = _readIsClassifiedObjectAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[ReadIsClassifiedObjectActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::ReadIsClassifiedObjectAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ReadIsClassifiedObjectActionActivationImpl::eContainer() const
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
void ReadIsClassifiedObjectActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReadIsClassifiedObjectActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("readIsClassifiedObjectAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("readIsClassifiedObjectAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ReadIsClassifiedObjectActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void ReadIsClassifiedObjectActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_ATTRIBUTE_READISCLASSIFIEDOBJECTACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ReadIsClassifiedObjectAction> _readIsClassifiedObjectAction = std::dynamic_pointer_cast<uml::ReadIsClassifiedObjectAction>( references.front() );
				setReadIsClassifiedObjectAction(_readIsClassifiedObjectAction);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void ReadIsClassifiedObjectActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ReadIsClassifiedObjectActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getReadIsClassifiedObjectAction(), "readIsClassifiedObjectAction", getReadIsClassifiedObjectAction()->eClass() != uml::umlPackage::eInstance()->getReadIsClassifiedObjectAction_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ReadIsClassifiedObjectActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getReadIsClassifiedObjectActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ReadIsClassifiedObjectActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_ATTRIBUTE_READISCLASSIFIEDOBJECTACTION:
			return eAny(getReadIsClassifiedObjectAction(),uml::umlPackage::READISCLASSIFIEDOBJECTACTION_CLASS,false); //9211
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool ReadIsClassifiedObjectActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_ATTRIBUTE_READISCLASSIFIEDOBJECTACTION:
			return getReadIsClassifiedObjectAction() != nullptr; //9211
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool ReadIsClassifiedObjectActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_ATTRIBUTE_READISCLASSIFIEDOBJECTACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ReadIsClassifiedObjectAction> _readIsClassifiedObjectAction = std::dynamic_pointer_cast<uml::ReadIsClassifiedObjectAction>(eObject);
					if(_readIsClassifiedObjectAction)
					{
						setReadIsClassifiedObjectAction(_readIsClassifiedObjectAction); //9211
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'readIsClassifiedObjectAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'readIsClassifiedObjectAction'. Failed to set feature!")
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
std::shared_ptr<Any> ReadIsClassifiedObjectActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation::doAction(): 2223647656
		case ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_OPERATION_DOACTION:
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

std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> ReadIsClassifiedObjectActionActivationImpl::getThisReadIsClassifiedObjectActionActivationPtr() const
{
	return m_thisReadIsClassifiedObjectActionActivationPtr.lock();
}
void ReadIsClassifiedObjectActionActivationImpl::setThisReadIsClassifiedObjectActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> thisReadIsClassifiedObjectActionActivationPtr)
{
	m_thisReadIsClassifiedObjectActionActivationPtr = thisReadIsClassifiedObjectActionActivationPtr;
	setThisActionActivationPtr(thisReadIsClassifiedObjectActionActivationPtr);
}


