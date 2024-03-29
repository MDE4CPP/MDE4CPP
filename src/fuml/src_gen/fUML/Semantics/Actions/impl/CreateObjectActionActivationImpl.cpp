
#include "fUML/Semantics/Actions/impl/CreateObjectActionActivationImpl.hpp"
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
#include "uml/CreateObjectAction.hpp"
#include "uml/Class.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
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
#include "uml/CreateObjectAction.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
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
CreateObjectActionActivationImpl::CreateObjectActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CreateObjectActionActivationImpl::~CreateObjectActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CreateObjectActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CreateObjectActionActivationImpl::CreateObjectActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CreateObjectActionActivationImpl()
{
	m_group = par_group;
}

CreateObjectActionActivationImpl::CreateObjectActionActivationImpl(const CreateObjectActionActivationImpl & obj): CreateObjectActionActivationImpl()
{
	*this = obj;
}

CreateObjectActionActivationImpl& CreateObjectActionActivationImpl::operator=(const CreateObjectActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CreateObjectActionActivation 
	 * which is generated by the compiler (as CreateObjectActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CreateObjectActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CreateObjectActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_createObjectAction  = obj.getCreateObjectAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CreateObjectActionActivationImpl::copy() const
{
	std::shared_ptr<CreateObjectActionActivationImpl> element(new CreateObjectActionActivationImpl());
	*element =(*this);
	element->setThisCreateObjectActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void CreateObjectActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create an object with the given classifier (which must be a class) as its type, at the same locus as the action activation.
// Place a reference to the object on the result pin of the action.

std::shared_ptr<uml::CreateObjectAction> action = this->getCreateObjectAction();
if(action)
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference= fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();
	std::shared_ptr<uml::Class> type= std::dynamic_pointer_cast<uml::Class> (action->getClassifier());
	if(type)
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> newObject=this->getExecutionLocus()->instantiate(type);
		if(newObject)
		{
			reference->setReferent(newObject);
			this->putToken(action->getResult(), reference);
		}
		else
		{
			throw "Can't instantiate object";
		}
	}
	else
	{
		throw "Unexpected invalid Classifier";
	}
}
else
{
	throw "Unexpected invalid CreateObjectAction";
}
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference createObjectAction */
std::shared_ptr<uml::CreateObjectAction> CreateObjectActionActivationImpl::getCreateObjectAction() const
{
    return m_createObjectAction;
}
void CreateObjectActionActivationImpl::setCreateObjectAction(std::shared_ptr<uml::CreateObjectAction> _createObjectAction)
{
    m_createObjectAction = _createObjectAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_createObjectAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void CreateObjectActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::CreateObjectAction> _createObjectAction = std::dynamic_pointer_cast<uml::CreateObjectAction>(_action);
	if(_createObjectAction)
	{
		m_createObjectAction = _createObjectAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_createObjectAction);
	}
	else
	{
		std::cerr<<"[CreateObjectActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::CreateObjectAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void CreateObjectActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::CreateObjectAction> _createObjectAction = std::dynamic_pointer_cast<uml::CreateObjectAction>(_node);
	if(_createObjectAction)
	{
		m_createObjectAction = _createObjectAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[CreateObjectActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::CreateObjectAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CreateObjectActionActivationImpl::getPinActivation() const
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
std::shared_ptr<ecore::EObject> CreateObjectActionActivationImpl::eContainer() const
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
void CreateObjectActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CreateObjectActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("createObjectAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("createObjectAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void CreateObjectActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CreateObjectActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CREATEOBJECTACTIONACTIVATION_ATTRIBUTE_CREATEOBJECTACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CreateObjectAction> _createObjectAction = std::dynamic_pointer_cast<uml::CreateObjectAction>( references.front() );
				setCreateObjectAction(_createObjectAction);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void CreateObjectActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CreateObjectActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getCreateObjectAction(), "createObjectAction", getCreateObjectAction()->eClass() != uml::umlPackage::eInstance()->getCreateObjectAction_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CreateObjectActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getCreateObjectActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CreateObjectActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CREATEOBJECTACTIONACTIVATION_ATTRIBUTE_CREATEOBJECTACTION:
			return eAny(getCreateObjectAction(),uml::umlPackage::CREATEOBJECTACTION_CLASS,false); //3411
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool CreateObjectActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CREATEOBJECTACTIONACTIVATION_ATTRIBUTE_CREATEOBJECTACTION:
			return getCreateObjectAction() != nullptr; //3411
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool CreateObjectActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CREATEOBJECTACTIONACTIVATION_ATTRIBUTE_CREATEOBJECTACTION:
		{
			// CAST Any to uml::CreateObjectAction
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::CreateObjectAction> _createObjectAction = std::dynamic_pointer_cast<uml::CreateObjectAction>(_temp);
			setCreateObjectAction(_createObjectAction); //3411
			return true;
		}
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CreateObjectActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::CreateObjectActionActivation::doAction(): 4275045489
		case ActionsPackage::CREATEOBJECTACTIONACTIVATION_OPERATION_DOACTION:
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

std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> CreateObjectActionActivationImpl::getThisCreateObjectActionActivationPtr() const
{
	return m_thisCreateObjectActionActivationPtr.lock();
}
void CreateObjectActionActivationImpl::setThisCreateObjectActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> thisCreateObjectActionActivationPtr)
{
	m_thisCreateObjectActionActivationPtr = thisCreateObjectActionActivationPtr;
	setThisActionActivationPtr(thisCreateObjectActionActivationPtr);
}


