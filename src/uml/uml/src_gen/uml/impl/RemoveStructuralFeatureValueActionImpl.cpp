
#include "uml/impl/RemoveStructuralFeatureValueActionImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
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
#include "uml/StructuralFeature.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/WriteStructuralFeatureAction.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

RemoveStructuralFeatureValueActionImpl::~RemoveStructuralFeatureValueActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RemoveStructuralFeatureValueAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::Activity> par_activity)
:RemoveStructuralFeatureValueActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:RemoveStructuralFeatureValueActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:RemoveStructuralFeatureValueActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::Element> par_owner)
:RemoveStructuralFeatureValueActionImpl()
{
	m_owner = par_owner;
}

RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(const RemoveStructuralFeatureValueActionImpl & obj): RemoveStructuralFeatureValueActionImpl()
{
	*this = obj;
}

RemoveStructuralFeatureValueActionImpl& RemoveStructuralFeatureValueActionImpl::operator=(const RemoveStructuralFeatureValueActionImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteStructuralFeatureActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of RemoveStructuralFeatureValueAction 
	 * which is generated by the compiler (as RemoveStructuralFeatureValueAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//RemoveStructuralFeatureValueAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RemoveStructuralFeatureValueAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isRemoveDuplicates = obj.getIsRemoveDuplicates();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'removeAt'
	if(obj.getRemoveAt()!=nullptr)
	{
		m_removeAt = std::dynamic_pointer_cast<uml::InputPin>(obj.getRemoveAt()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> RemoveStructuralFeatureValueActionImpl::copy() const
{
	std::shared_ptr<RemoveStructuralFeatureValueActionImpl> element(new RemoveStructuralFeatureValueActionImpl());
	*element =(*this);
	element->setThisRemoveStructuralFeatureValueActionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool RemoveStructuralFeatureValueActionImpl::removeAt_and_value(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isRemoveDuplicates */
bool RemoveStructuralFeatureValueActionImpl::getIsRemoveDuplicates() const 
{
	return m_isRemoveDuplicates;
}
void RemoveStructuralFeatureValueActionImpl::setIsRemoveDuplicates(bool _isRemoveDuplicates)
{
	m_isRemoveDuplicates = _isRemoveDuplicates;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference removeAt */
std::shared_ptr<uml::InputPin> RemoveStructuralFeatureValueActionImpl::getRemoveAt() const
{
    return m_removeAt;
}
void RemoveStructuralFeatureValueActionImpl::setRemoveAt(std::shared_ptr<uml::InputPin> _removeAt)
{
    m_removeAt = _removeAt;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> RemoveStructuralFeatureValueActionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> RemoveStructuralFeatureValueActionImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getInput()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> RemoveStructuralFeatureValueActionImpl::getOutput() const
{
	if(m_output == nullptr)
	{
		/*SubsetUnion*/
		m_output.reset(new SubsetUnion<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOutput()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

std::shared_ptr<Union<uml::Element>> RemoveStructuralFeatureValueActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> RemoveStructuralFeatureValueActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> RemoveStructuralFeatureValueActionImpl::getRedefinedElement() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> RemoveStructuralFeatureValueActionImpl::eContainer() const
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
// Persistence Functions
//*********************************
void RemoveStructuralFeatureValueActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void RemoveStructuralFeatureValueActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isRemoveDuplicates");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsRemoveDuplicates(value);
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

	WriteStructuralFeatureActionImpl::loadAttributes(loadHandler, attr_list);
}

void RemoveStructuralFeatureValueActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("removeAt") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getRemoveAt()); 

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
	WriteStructuralFeatureActionImpl::loadNode(nodeName, loadHandler);
}

void RemoveStructuralFeatureValueActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	WriteStructuralFeatureActionImpl::resolveReferences(featureID, references);
}

void RemoveStructuralFeatureValueActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteStructuralFeatureActionImpl::saveContent(saveHandler);
	
	StructuralFeatureActionImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void RemoveStructuralFeatureValueActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'removeAt'
		std::shared_ptr<uml::InputPin> removeAt = this->getRemoveAt();
		if (removeAt != nullptr)
		{
			saveHandler->addReference(removeAt, "removeAt", removeAt->eClass() != package->getInputPin_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getRemoveStructuralFeatureValueAction_Attribute_isRemoveDuplicates()) )
		{
			saveHandler->addAttribute("isRemoveDuplicates", this->getIsRemoveDuplicates());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> RemoveStructuralFeatureValueActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getRemoveStructuralFeatureValueAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any RemoveStructuralFeatureValueActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES:
			return eAny(getIsRemoveDuplicates(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //20931
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_REMOVEAT:
			return eAny(getRemoveAt(),uml::umlPackage::INPUTPIN_CLASS,false); //20932
	}
	return WriteStructuralFeatureActionImpl::eGet(featureID, resolve, coreType);
}

bool RemoveStructuralFeatureValueActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES:
			return getIsRemoveDuplicates() != false; //20931
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_REMOVEAT:
			return getRemoveAt() != nullptr; //20932
	}
	return WriteStructuralFeatureActionImpl::internalEIsSet(featureID);
}

bool RemoveStructuralFeatureValueActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES:
		{
			// CAST Any to bool
			bool _isRemoveDuplicates = newValue->get<bool>();
			setIsRemoveDuplicates(_isRemoveDuplicates); //20931
			return true;
		}
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_REMOVEAT:
		{
			// CAST Any to uml::InputPin
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _removeAt = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setRemoveAt(_removeAt); //20932
			return true;
		}
	}

	return WriteStructuralFeatureActionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any RemoveStructuralFeatureValueActionImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::RemoveStructuralFeatureValueAction::removeAt_and_value(Any, std::map) : bool: 3006271433
		case umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_OPERATION_REMOVEAT_AND_VALUE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->removeAt_and_value(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = WriteStructuralFeatureActionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::RemoveStructuralFeatureValueAction> RemoveStructuralFeatureValueActionImpl::getThisRemoveStructuralFeatureValueActionPtr() const
{
	return m_thisRemoveStructuralFeatureValueActionPtr.lock();
}
void RemoveStructuralFeatureValueActionImpl::setThisRemoveStructuralFeatureValueActionPtr(std::weak_ptr<uml::RemoveStructuralFeatureValueAction> thisRemoveStructuralFeatureValueActionPtr)
{
	m_thisRemoveStructuralFeatureValueActionPtr = thisRemoveStructuralFeatureValueActionPtr;
	setThisWriteStructuralFeatureActionPtr(thisRemoveStructuralFeatureValueActionPtr);
}


