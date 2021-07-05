#include "uml/impl/CreateLinkActionImpl.hpp"

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
#include "uml/LinkEndData.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/WriteLinkAction.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
CreateLinkActionImpl::CreateLinkActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CreateLinkActionImpl::~CreateLinkActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CreateLinkAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CreateLinkActionImpl::CreateLinkActionImpl(std::weak_ptr<uml::Activity> par_activity)
:CreateLinkActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
CreateLinkActionImpl::CreateLinkActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:CreateLinkActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
CreateLinkActionImpl::CreateLinkActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:CreateLinkActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
CreateLinkActionImpl::CreateLinkActionImpl(std::weak_ptr<uml::Element> par_owner)
:CreateLinkActionImpl()
{
	m_owner = par_owner;
}

CreateLinkActionImpl::CreateLinkActionImpl(const CreateLinkActionImpl & obj): CreateLinkActionImpl()
{
	*this = obj;
}

CreateLinkActionImpl& CreateLinkActionImpl::operator=(const CreateLinkActionImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteLinkActionImpl::operator=(obj);
	CreateLinkAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CreateLinkAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CreateLinkActionImpl::copy() const
{
	std::shared_ptr<CreateLinkActionImpl> element(new CreateLinkActionImpl());
	*element =(*this);
	element->setThisCreateLinkActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CreateLinkActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getCreateLinkAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool CreateLinkActionImpl::association_not_abstract(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> CreateLinkActionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> CreateLinkActionImpl::getInput() const
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

std::shared_ptr<Union<uml::Element>> CreateLinkActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> CreateLinkActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> CreateLinkActionImpl::getRedefinedElement() const
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




std::shared_ptr<CreateLinkAction> CreateLinkActionImpl::getThisCreateLinkActionPtr() const
{
	return m_thisCreateLinkActionPtr.lock();
}
void CreateLinkActionImpl::setThisCreateLinkActionPtr(std::weak_ptr<CreateLinkAction> thisCreateLinkActionPtr)
{
	m_thisCreateLinkActionPtr = thisCreateLinkActionPtr;
	setThisWriteLinkActionPtr(thisCreateLinkActionPtr);
}
std::shared_ptr<ecore::EObject> CreateLinkActionImpl::eContainer() const
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
Any CreateLinkActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return WriteLinkActionImpl::eGet(featureID, resolve, coreType);
}
bool CreateLinkActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return WriteLinkActionImpl::internalEIsSet(featureID);
}
bool CreateLinkActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return WriteLinkActionImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CreateLinkActionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 6200
		case umlPackage::CREATELINKACTION_OPERATION_ASSOCIATION_NOT_ABSTRACT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->association_not_abstract(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = WriteLinkActionImpl::eInvoke(operationID, arguments);
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
void CreateLinkActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CreateLinkActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	WriteLinkActionImpl::loadAttributes(loadHandler, attr_list);
}

void CreateLinkActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	WriteLinkActionImpl::loadNode(nodeName, loadHandler);
}

void CreateLinkActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	WriteLinkActionImpl::resolveReferences(featureID, references);
}

void CreateLinkActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteLinkActionImpl::saveContent(saveHandler);
	
	LinkActionImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
	
	
}

void CreateLinkActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

