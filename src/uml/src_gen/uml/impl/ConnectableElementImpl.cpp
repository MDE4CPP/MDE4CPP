#include "uml/impl/ConnectableElementImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/ConnectorEnd.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/ParameterableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"
#include "uml/TypedElement.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectableElementImpl::ConnectableElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ConnectableElementImpl::~ConnectableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConnectableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConnectableElementImpl::ConnectableElementImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ConnectableElementImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ConnectableElementImpl::ConnectableElementImpl(std::weak_ptr<uml::Element> par_owner)
:ConnectableElementImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ConnectableElementImpl::ConnectableElementImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ConnectableElementImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

ConnectableElementImpl::ConnectableElementImpl(const ConnectableElementImpl & obj): ConnectableElementImpl()
{
	*this = obj;
}

ConnectableElementImpl& ConnectableElementImpl::operator=(const ConnectableElementImpl & obj)
{
	//call overloaded =Operator for each base class
	TypedElementImpl::operator=(obj);
	ParameterableElementImpl::operator=(obj);
	ConnectableElement::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConnectableElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::ConnectorEnd>> _end = obj.getEnd();
	m_end.reset(new Bag<uml::ConnectorEnd>(*(obj.getEnd().get())));
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ConnectableElementImpl::copy() const
{
	std::shared_ptr<ConnectableElementImpl> element(new ConnectableElementImpl());
	*element =(*this);
	element->setThisConnectableElementPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConnectableElementImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getConnectableElement_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::ConnectorEnd> > ConnectableElementImpl::getEnds()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference end
*/
std::shared_ptr<Bag<uml::ConnectorEnd>> ConnectableElementImpl::getEnd() const
{
	if(m_end == nullptr)
	{
		m_end.reset(new Bag<uml::ConnectorEnd>());
		
		
	}

    return m_end;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ConnectableElementImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ConnectableElementImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<ConnectableElement> ConnectableElementImpl::getThisConnectableElementPtr() const
{
	return m_thisConnectableElementPtr.lock();
}
void ConnectableElementImpl::setThisConnectableElementPtr(std::weak_ptr<ConnectableElement> thisConnectableElementPtr)
{
	m_thisConnectableElementPtr = thisConnectableElementPtr;
	setThisParameterableElementPtr(thisConnectableElementPtr);
	setThisTypedElementPtr(thisConnectableElementPtr);
}
std::shared_ptr<ecore::EObject> ConnectableElementImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ConnectableElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTABLEELEMENT_ATTRIBUTE_END:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ConnectorEnd>::iterator iter = m_end->begin();
			Bag<uml::ConnectorEnd>::iterator end = m_end->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5012			
		}
	}
	Any result;
	result = ParameterableElementImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = TypedElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool ConnectableElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTABLEELEMENT_ATTRIBUTE_END:
			return getEnd() != nullptr; //5012
	}
	bool result = false;
	result = ParameterableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TypedElementImpl::internalEIsSet(featureID);
	return result;
}
bool ConnectableElementImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	bool result = false;
	result = ParameterableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TypedElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any ConnectableElementImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 5071
		case umlPackage::CONNECTABLEELEMENT_OPERATION_GETENDS:
		{
			result = eAny(this->getEnds());
			break;
		}

		default:
		{
			// call superTypes
			result = ParameterableElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = TypedElementImpl::eInvoke(operationID, arguments);
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
void ConnectableElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConnectableElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ParameterableElementImpl::loadAttributes(loadHandler, attr_list);
	TypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ConnectableElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ParameterableElementImpl::loadNode(nodeName, loadHandler);
	TypedElementImpl::loadNode(nodeName, loadHandler);
}

void ConnectableElementImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ParameterableElementImpl::resolveReferences(featureID, references);
	TypedElementImpl::resolveReferences(featureID, references);
}

void ConnectableElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ParameterableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ConnectableElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

