
#include "fUML/Semantics/Actions/impl/RemoveStructuralFeatureValueActivationImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/InputPin.hpp"
#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "uml/StructuralFeature.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Actions/WriteStructuralFeatureActionActivation.hpp"
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
RemoveStructuralFeatureValueActivationImpl::RemoveStructuralFeatureValueActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

RemoveStructuralFeatureValueActivationImpl::~RemoveStructuralFeatureValueActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RemoveStructuralFeatureValueActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
RemoveStructuralFeatureValueActivationImpl::RemoveStructuralFeatureValueActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:RemoveStructuralFeatureValueActivationImpl()
{
	m_group = par_group;
}

RemoveStructuralFeatureValueActivationImpl::RemoveStructuralFeatureValueActivationImpl(const RemoveStructuralFeatureValueActivationImpl & obj): RemoveStructuralFeatureValueActivationImpl()
{
	*this = obj;
}

RemoveStructuralFeatureValueActivationImpl& RemoveStructuralFeatureValueActivationImpl::operator=(const RemoveStructuralFeatureValueActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteStructuralFeatureActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of RemoveStructuralFeatureValueActivation 
	 * which is generated by the compiler (as RemoveStructuralFeatureValueActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//RemoveStructuralFeatureValueActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RemoveStructuralFeatureValueActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_removeStructuralFeatureValueAction  = obj.getRemoveStructuralFeatureValueAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> RemoveStructuralFeatureValueActivationImpl::copy() const
{
	std::shared_ptr<RemoveStructuralFeatureValueActivationImpl> element(new RemoveStructuralFeatureValueActivationImpl());
	*element =(*this);
	element->setThisRemoveStructuralFeatureValueActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void RemoveStructuralFeatureValueActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::RemoveStructuralFeatureValueAction> action = this->getRemoveStructuralFeatureValueAction();
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();

	std::shared_ptr<fUML::Semantics::Values::Value> objectValue = nullptr;
	
	/* MDE4CPP specific implementation for handling "self"-Pin */
	std::string objectPinName = action->getObject()->getName();
	if((objectPinName.empty()) || (objectPinName.find("self") == 0)){
		//objectValue is set to the context of the current activity execution
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> contextReference = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> context = this->getActivityExecution()->getContext();
		contextReference->setReferent(context);
			
		objectValue = contextReference;
	}
	else{
		objectValue = this->takeTokens(action->getObject())->at(0);
	}
	/*--------------------------------------------------------*/

	std::shared_ptr<fUML::Semantics::Values::Value> inputValue = takeTokens(action->getValue())->at(0);
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue> structuredValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(objectValue);
	if (structuredValue)
	{
		structuredValue->removeValue(feature, inputValue);
	}
	else
	{
		throw "unhandled fUML::Value instance";
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
/* Getter & Setter for reference removeStructuralFeatureValueAction */
std::shared_ptr<uml::RemoveStructuralFeatureValueAction> RemoveStructuralFeatureValueActivationImpl::getRemoveStructuralFeatureValueAction() const
{
    return m_removeStructuralFeatureValueAction;
}
void RemoveStructuralFeatureValueActivationImpl::setRemoveStructuralFeatureValueAction(std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction)
{
    m_removeStructuralFeatureValueAction = _removeStructuralFeatureValueAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_removeStructuralFeatureValueAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void RemoveStructuralFeatureValueActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>(_action);
	if(_removeStructuralFeatureValueAction)
	{
		m_removeStructuralFeatureValueAction = _removeStructuralFeatureValueAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_removeStructuralFeatureValueAction);
	}
	else
	{
		std::cerr<<"[RemoveStructuralFeatureValueActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::RemoveStructuralFeatureValueAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void RemoveStructuralFeatureValueActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>(_node);
	if(_removeStructuralFeatureValueAction)
	{
		m_removeStructuralFeatureValueAction = _removeStructuralFeatureValueAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[RemoveStructuralFeatureValueActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::RemoveStructuralFeatureValueAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> RemoveStructuralFeatureValueActivationImpl::getPinActivation() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> RemoveStructuralFeatureValueActivationImpl::eContainer() const
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
void RemoveStructuralFeatureValueActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void RemoveStructuralFeatureValueActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("removeStructuralFeatureValueAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("removeStructuralFeatureValueAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	WriteStructuralFeatureActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void RemoveStructuralFeatureValueActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	WriteStructuralFeatureActionActivationImpl::loadNode(nodeName, loadHandler);
}

void RemoveStructuralFeatureValueActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>( references.front() );
				setRemoveStructuralFeatureValueAction(_removeStructuralFeatureValueAction);
			}
			
			return;
		}
	}
	WriteStructuralFeatureActionActivationImpl::resolveReferences(featureID, references);
}

void RemoveStructuralFeatureValueActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteStructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void RemoveStructuralFeatureValueActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getRemoveStructuralFeatureValueAction(), "removeStructuralFeatureValueAction", getRemoveStructuralFeatureValueAction()->eClass() != uml::umlPackage::eInstance()->getRemoveStructuralFeatureValueAction_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> RemoveStructuralFeatureValueActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getRemoveStructuralFeatureValueActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any RemoveStructuralFeatureValueActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
			return eAny(getRemoveStructuralFeatureValueAction(),uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_CLASS,false); //10011
	}
	return WriteStructuralFeatureActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool RemoveStructuralFeatureValueActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
			return getRemoveStructuralFeatureValueAction() != nullptr; //10011
	}
	return WriteStructuralFeatureActionActivationImpl::internalEIsSet(featureID);
}

bool RemoveStructuralFeatureValueActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			// CAST Any to uml::RemoveStructuralFeatureValueAction
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>(_temp);
			setRemoveStructuralFeatureValueAction(_removeStructuralFeatureValueAction); //10011
			return true;
		}
	}

	return WriteStructuralFeatureActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any RemoveStructuralFeatureValueActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation::doAction(): 1011652404
		case ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = WriteStructuralFeatureActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> RemoveStructuralFeatureValueActivationImpl::getThisRemoveStructuralFeatureValueActivationPtr() const
{
	return m_thisRemoveStructuralFeatureValueActivationPtr.lock();
}
void RemoveStructuralFeatureValueActivationImpl::setThisRemoveStructuralFeatureValueActivationPtr(std::weak_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> thisRemoveStructuralFeatureValueActivationPtr)
{
	m_thisRemoveStructuralFeatureValueActivationPtr = thisRemoveStructuralFeatureValueActivationPtr;
	setThisWriteStructuralFeatureActionActivationPtr(thisRemoveStructuralFeatureValueActivationPtr);
}


