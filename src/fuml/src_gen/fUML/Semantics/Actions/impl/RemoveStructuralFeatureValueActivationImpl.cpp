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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

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
#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Actions/WriteStructuralFeatureActionActivation.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	RemoveStructuralFeatureValueActivation::operator=(obj);

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

std::shared_ptr<ecore::EClass> RemoveStructuralFeatureValueActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getRemoveStructuralFeatureValueActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

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
// References
//*********************************
/*
Getter & Setter for reference removeStructuralFeatureValueAction
*/
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




std::shared_ptr<RemoveStructuralFeatureValueActivation> RemoveStructuralFeatureValueActivationImpl::getThisRemoveStructuralFeatureValueActivationPtr() const
{
	return m_thisRemoveStructuralFeatureValueActivationPtr.lock();
}
void RemoveStructuralFeatureValueActivationImpl::setThisRemoveStructuralFeatureValueActivationPtr(std::weak_ptr<RemoveStructuralFeatureValueActivation> thisRemoveStructuralFeatureValueActivationPtr)
{
	m_thisRemoveStructuralFeatureValueActivationPtr = thisRemoveStructuralFeatureValueActivationPtr;
	setThisWriteStructuralFeatureActionActivationPtr(thisRemoveStructuralFeatureValueActivationPtr);
}
std::shared_ptr<ecore::EObject> RemoveStructuralFeatureValueActivationImpl::eContainer() const
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
Any RemoveStructuralFeatureValueActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
			{
				std::shared_ptr<ecore::EObject> returnValue=getRemoveStructuralFeatureValueAction();
				return eAny(returnValue); //10011
			}
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
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>(_temp);
			setRemoveStructuralFeatureValueAction(_removeStructuralFeatureValueAction); //10011
			return true;
		}
	}

	return WriteStructuralFeatureActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any RemoveStructuralFeatureValueActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 10064
		case ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = WriteStructuralFeatureActionActivationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
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

