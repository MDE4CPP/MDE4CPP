#include "uml/impl/EnumerationLiteralImpl.hpp"

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
#include "uml/UmlFactory.hpp"


#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Deployment.hpp"
#include "uml/Element.hpp"
#include "uml/Enumeration.hpp"
#include "uml/InstanceSpecification.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Slot.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
EnumerationLiteralImpl::EnumerationLiteralImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EnumerationLiteralImpl::~EnumerationLiteralImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EnumerationLiteral "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Enumeration> par_enumeration)
:EnumerationLiteralImpl()
{
	m_enumeration = par_enumeration;
	m_namespace = par_enumeration;
}

//Additional constructor for the containments back reference
EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Namespace> par_namespace)
:EnumerationLiteralImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Element> par_owner)
:EnumerationLiteralImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Package> par_owningPackage)
:EnumerationLiteralImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:EnumerationLiteralImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

EnumerationLiteralImpl::EnumerationLiteralImpl(const EnumerationLiteralImpl & obj): EnumerationLiteralImpl()
{
	*this = obj;
}

EnumerationLiteralImpl& EnumerationLiteralImpl::operator=(const EnumerationLiteralImpl & obj)
{
	//call overloaded =Operator for each base class
	InstanceSpecificationImpl::operator=(obj);
	EnumerationLiteral::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EnumerationLiteral "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_enumeration  = obj.getEnumeration();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EnumerationLiteralImpl::copy() const
{
	std::shared_ptr<EnumerationLiteralImpl> element(new EnumerationLiteralImpl());
	*element =(*this);
	element->setThisEnumerationLiteralPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> EnumerationLiteralImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getEnumerationLiteral_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************


std::shared_ptr<Bag<uml::Classifier> > EnumerationLiteralImpl::getClassifiers()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference enumeration
*/
std::weak_ptr<uml::Enumeration> EnumerationLiteralImpl::getEnumeration() const
{
//assert(m_enumeration);
    return m_enumeration;
}
void EnumerationLiteralImpl::setEnumeration(std::weak_ptr<uml::Enumeration> _enumeration)
{
    m_enumeration = _enumeration;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> EnumerationLiteralImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> EnumerationLiteralImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> EnumerationLiteralImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<EnumerationLiteral> EnumerationLiteralImpl::getThisEnumerationLiteralPtr() const
{
	return m_thisEnumerationLiteralPtr.lock();
}
void EnumerationLiteralImpl::setThisEnumerationLiteralPtr(std::weak_ptr<EnumerationLiteral> thisEnumerationLiteralPtr)
{
	m_thisEnumerationLiteralPtr = thisEnumerationLiteralPtr;
	setThisInstanceSpecificationPtr(thisEnumerationLiteralPtr);
}
std::shared_ptr<ecore::EObject> EnumerationLiteralImpl::eContainer() const
{
	if(auto wp = m_enumeration.lock())
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

	if(auto wp = m_owningPackage.lock())
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
Any EnumerationLiteralImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION:
			return eAny(getEnumeration().lock()); //8517
	}
	return InstanceSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool EnumerationLiteralImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION:
			return getEnumeration().lock() != nullptr; //8517
	}
	return InstanceSpecificationImpl::internalEIsSet(featureID);
}
bool EnumerationLiteralImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Enumeration> _enumeration = std::dynamic_pointer_cast<uml::Enumeration>(_temp);
			setEnumeration(_enumeration); //8517
			return true;
		}
	}

	return InstanceSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EnumerationLiteralImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EnumerationLiteralImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	InstanceSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void EnumerationLiteralImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	InstanceSpecificationImpl::loadNode(nodeName, loadHandler);
}

void EnumerationLiteralImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Enumeration> _enumeration = std::dynamic_pointer_cast<uml::Enumeration>( references.front() );
				setEnumeration(_enumeration);
			}
			
			return;
		}
	}
	InstanceSpecificationImpl::resolveReferences(featureID, references);
}

void EnumerationLiteralImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InstanceSpecificationImpl::saveContent(saveHandler);
	
	DeployedArtifactImpl::saveContent(saveHandler);
	DeploymentTargetImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void EnumerationLiteralImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

