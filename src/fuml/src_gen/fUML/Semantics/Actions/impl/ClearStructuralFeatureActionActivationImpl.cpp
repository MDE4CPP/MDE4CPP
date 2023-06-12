
#include "fUML/Semantics/Actions/impl/ClearStructuralFeatureActionActivationImpl.hpp"
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
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "uml/UMLAny.hpp"
#include "uml/InputPin.hpp"
#include "uml/ClearStructuralFeatureAction.hpp"
#include "uml/Property.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/ClearStructuralFeatureAction.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
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
ClearStructuralFeatureActionActivationImpl::ClearStructuralFeatureActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ClearStructuralFeatureActionActivationImpl::~ClearStructuralFeatureActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClearStructuralFeatureActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ClearStructuralFeatureActionActivationImpl::ClearStructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ClearStructuralFeatureActionActivationImpl()
{
	m_group = par_group;
}

ClearStructuralFeatureActionActivationImpl::ClearStructuralFeatureActionActivationImpl(const ClearStructuralFeatureActionActivationImpl & obj): ClearStructuralFeatureActionActivationImpl()
{
	*this = obj;
}

ClearStructuralFeatureActionActivationImpl& ClearStructuralFeatureActionActivationImpl::operator=(const ClearStructuralFeatureActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuralFeatureActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ClearStructuralFeatureActionActivation 
	 * which is generated by the compiler (as ClearStructuralFeatureActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ClearStructuralFeatureActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ClearStructuralFeatureActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_clearStructuralFeatureAction  = obj.getClearStructuralFeatureAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ClearStructuralFeatureActionActivationImpl::copy() const
{
	std::shared_ptr<ClearStructuralFeatureActionActivationImpl> element(new ClearStructuralFeatureActionActivationImpl());
	*element =(*this);
	element->setThisClearStructuralFeatureActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ClearStructuralFeatureActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::ClearStructuralFeatureAction> action = this->getClearStructuralFeatureAction();
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();
	std::shared_ptr<uml::Property> property = std::dynamic_pointer_cast<uml::Property>(feature);

	if(!property)
	{
		return;
	}

	std::shared_ptr<Any> objectValue = nullptr;
	
	/* MDE4CPP specific implementation for handling "self"-Pin */
	std::string objectPinName = action->getObject()->getName();
	if((objectPinName.empty()) || (objectPinName.find("self") == 0)){
		//objectValue is set to the context of the current activity execution
		std::shared_ptr<uml::Element> context = this->getActivityExecution()->getContext();
			
		objectValue = eUMLAny(context, context->getMetaElementID());
	}
	else{
		objectValue = this->takeTokens(action->getObject())->at(0);
	}
	/*--------------------------------------------------------*/

	std::shared_ptr<uml::Element> structuredValue = nullptr;

	try
	{
		std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(objectValue);

		structuredValue = umlAny->getAsElement();

		if (structuredValue)
		{
			structuredValue->unset(property);
		}
		else
		{
			DEBUG_ERROR("Context is nullptr! Failed to clear feature!")
		}
	}
	catch(...)
	{
		DEBUG_ERROR("Provided context is not an instance of uml::Element! Failed to clear feature!")
	}

	putToken(action->getResult(), objectValue);
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference clearStructuralFeatureAction */
const std::shared_ptr<uml::ClearStructuralFeatureAction>& ClearStructuralFeatureActionActivationImpl::getClearStructuralFeatureAction() const
{
    return m_clearStructuralFeatureAction;
}
void ClearStructuralFeatureActionActivationImpl::setClearStructuralFeatureAction(const std::shared_ptr<uml::ClearStructuralFeatureAction>& _clearStructuralFeatureAction)
{
    m_clearStructuralFeatureAction = _clearStructuralFeatureAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_clearStructuralFeatureAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void ClearStructuralFeatureActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::ClearStructuralFeatureAction> _clearStructuralFeatureAction = std::dynamic_pointer_cast<uml::ClearStructuralFeatureAction>(_action);
	if(_clearStructuralFeatureAction)
	{
		m_clearStructuralFeatureAction = _clearStructuralFeatureAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_clearStructuralFeatureAction);
	}
	else
	{
		std::cerr<<"[ClearStructuralFeatureActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::ClearStructuralFeatureAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void ClearStructuralFeatureActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::ClearStructuralFeatureAction> _clearStructuralFeatureAction = std::dynamic_pointer_cast<uml::ClearStructuralFeatureAction>(_node);
	if(_clearStructuralFeatureAction)
	{
		m_clearStructuralFeatureAction = _clearStructuralFeatureAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[ClearStructuralFeatureActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::ClearStructuralFeatureAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ClearStructuralFeatureActionActivationImpl::eContainer() const
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
void ClearStructuralFeatureActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClearStructuralFeatureActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("clearStructuralFeatureAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("clearStructuralFeatureAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ClearStructuralFeatureActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	StructuralFeatureActionActivationImpl::loadNode(nodeName, loadHandler);
}

void ClearStructuralFeatureActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ClearStructuralFeatureAction> _clearStructuralFeatureAction = std::dynamic_pointer_cast<uml::ClearStructuralFeatureAction>( references.front() );
				setClearStructuralFeatureAction(_clearStructuralFeatureAction);
			}
			
			return;
		}
	}
	StructuralFeatureActionActivationImpl::resolveReferences(featureID, references);
}

void ClearStructuralFeatureActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ClearStructuralFeatureActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getClearStructuralFeatureAction(), "clearStructuralFeatureAction", getClearStructuralFeatureAction()->eClass() != uml::umlPackage::eInstance()->getClearStructuralFeatureAction_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ClearStructuralFeatureActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getClearStructuralFeatureActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ClearStructuralFeatureActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
			return eAny(getClearStructuralFeatureAction(),uml::umlPackage::CLEARSTRUCTURALFEATUREACTION_CLASS,false); //2811
	}
	return StructuralFeatureActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool ClearStructuralFeatureActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
			return getClearStructuralFeatureAction() != nullptr; //2811
	}
	return StructuralFeatureActionActivationImpl::internalEIsSet(featureID);
}

bool ClearStructuralFeatureActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ClearStructuralFeatureAction> _clearStructuralFeatureAction = std::dynamic_pointer_cast<uml::ClearStructuralFeatureAction>(eObject);
					if(_clearStructuralFeatureAction)
					{
						setClearStructuralFeatureAction(_clearStructuralFeatureAction); //2811
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'clearStructuralFeatureAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'clearStructuralFeatureAction'. Failed to set feature!")
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
std::shared_ptr<Any> ClearStructuralFeatureActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::ClearStructuralFeatureActionActivation::doAction(): 673492974
		case ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION:
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

std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> ClearStructuralFeatureActionActivationImpl::getThisClearStructuralFeatureActionActivationPtr() const
{
	return m_thisClearStructuralFeatureActionActivationPtr.lock();
}
void ClearStructuralFeatureActionActivationImpl::setThisClearStructuralFeatureActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> thisClearStructuralFeatureActionActivationPtr)
{
	m_thisClearStructuralFeatureActionActivationPtr = thisClearStructuralFeatureActionActivationPtr;
	setThisStructuralFeatureActionActivationPtr(thisClearStructuralFeatureActionActivationPtr);
}


