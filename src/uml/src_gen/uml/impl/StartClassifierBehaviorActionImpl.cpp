#include "uml/impl/StartClassifierBehaviorActionImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

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
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StartClassifierBehaviorActionImpl::StartClassifierBehaviorActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StartClassifierBehaviorActionImpl::~StartClassifierBehaviorActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StartClassifierBehaviorAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StartClassifierBehaviorActionImpl::StartClassifierBehaviorActionImpl(std::weak_ptr<uml::Activity> par_activity)
:StartClassifierBehaviorActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
StartClassifierBehaviorActionImpl::StartClassifierBehaviorActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:StartClassifierBehaviorActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
StartClassifierBehaviorActionImpl::StartClassifierBehaviorActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StartClassifierBehaviorActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StartClassifierBehaviorActionImpl::StartClassifierBehaviorActionImpl(std::weak_ptr<uml::Element> par_owner)
:StartClassifierBehaviorActionImpl()
{
	m_owner = par_owner;
}

StartClassifierBehaviorActionImpl::StartClassifierBehaviorActionImpl(const StartClassifierBehaviorActionImpl & obj): StartClassifierBehaviorActionImpl()
{
	*this = obj;
}

StartClassifierBehaviorActionImpl& StartClassifierBehaviorActionImpl::operator=(const StartClassifierBehaviorActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	StartClassifierBehaviorAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StartClassifierBehaviorAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	if(obj.getObject()!=nullptr)
	{
		m_object = std::dynamic_pointer_cast<uml::InputPin>(obj.getObject()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> StartClassifierBehaviorActionImpl::copy() const
{
	std::shared_ptr<StartClassifierBehaviorActionImpl> element(new StartClassifierBehaviorActionImpl());
	*element =(*this);
	element->setThisStartClassifierBehaviorActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StartClassifierBehaviorActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStartClassifierBehaviorAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool StartClassifierBehaviorActionImpl::multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StartClassifierBehaviorActionImpl::type_has_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference object
*/
std::shared_ptr<uml::InputPin> StartClassifierBehaviorActionImpl::getObject() const
{
//assert(m_object);
    return m_object;
}
void StartClassifierBehaviorActionImpl::setObject(std::shared_ptr<uml::InputPin> _object)
{
    m_object = _object;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> StartClassifierBehaviorActionImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> StartClassifierBehaviorActionImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_input->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<Union<uml::Element>> StartClassifierBehaviorActionImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> StartClassifierBehaviorActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> StartClassifierBehaviorActionImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<StartClassifierBehaviorAction> StartClassifierBehaviorActionImpl::getThisStartClassifierBehaviorActionPtr() const
{
	return m_thisStartClassifierBehaviorActionPtr.lock();
}
void StartClassifierBehaviorActionImpl::setThisStartClassifierBehaviorActionPtr(std::weak_ptr<StartClassifierBehaviorAction> thisStartClassifierBehaviorActionPtr)
{
	m_thisStartClassifierBehaviorActionPtr = thisStartClassifierBehaviorActionPtr;
	setThisActionPtr(thisStartClassifierBehaviorActionPtr);
}
std::shared_ptr<ecore::EObject> StartClassifierBehaviorActionImpl::eContainer() const
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
// Structural Feature Getter/Setter
//*********************************
Any StartClassifierBehaviorActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STARTCLASSIFIERBEHAVIORACTION_ATTRIBUTE_OBJECT:
			return eAny(getObject()); //21827
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}
bool StartClassifierBehaviorActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STARTCLASSIFIERBEHAVIORACTION_ATTRIBUTE_OBJECT:
			return getObject() != nullptr; //21827
	}
	return ActionImpl::internalEIsSet(featureID);
}
bool StartClassifierBehaviorActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STARTCLASSIFIERBEHAVIORACTION_ATTRIBUTE_OBJECT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _object = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setObject(_object); //21827
			return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any StartClassifierBehaviorActionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 21894
		case umlPackage::STARTCLASSIFIERBEHAVIORACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->multiplicity(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 21895
		case umlPackage::STARTCLASSIFIERBEHAVIORACTION_OPERATION_TYPE_HAS_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->type_has_classifier(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = ActionImpl::eInvoke(operationID, arguments);
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
void StartClassifierBehaviorActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StartClassifierBehaviorActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActionImpl::loadAttributes(loadHandler, attr_list);
}

void StartClassifierBehaviorActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("object") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getObject()); 

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
	ActionImpl::loadNode(nodeName, loadHandler);
}

void StartClassifierBehaviorActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActionImpl::resolveReferences(featureID, references);
}

void StartClassifierBehaviorActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void StartClassifierBehaviorActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'object'
		std::shared_ptr<uml::InputPin> object = this->getObject();
		if (object != nullptr)
		{
			saveHandler->addReference(object, "object", object->eClass() != package->getInputPin_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

