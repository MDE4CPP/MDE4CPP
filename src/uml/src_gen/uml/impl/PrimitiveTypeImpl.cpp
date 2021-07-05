#include "uml/impl/PrimitiveTypeImpl.hpp"

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


#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/DataType.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/UseCase.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PrimitiveTypeImpl::PrimitiveTypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PrimitiveTypeImpl::~PrimitiveTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PrimitiveType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PrimitiveTypeImpl::PrimitiveTypeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:PrimitiveTypeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
PrimitiveTypeImpl::PrimitiveTypeImpl(std::weak_ptr<uml::Element> par_owner)
:PrimitiveTypeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
PrimitiveTypeImpl::PrimitiveTypeImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:PrimitiveTypeImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
PrimitiveTypeImpl::PrimitiveTypeImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:PrimitiveTypeImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


PrimitiveTypeImpl::PrimitiveTypeImpl(const PrimitiveTypeImpl & obj): PrimitiveTypeImpl()
{
	*this = obj;
}

PrimitiveTypeImpl& PrimitiveTypeImpl::operator=(const PrimitiveTypeImpl & obj)
{
	//call overloaded =Operator for each base class
	DataTypeImpl::operator=(obj);
	PrimitiveType::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PrimitiveType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PrimitiveTypeImpl::copy() const
{
	std::shared_ptr<PrimitiveTypeImpl> element(new PrimitiveTypeImpl());
	*element =(*this);
	element->setThisPrimitiveTypePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PrimitiveTypeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getPrimitiveType_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> PrimitiveTypeImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_attribute->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> PrimitiveTypeImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_feature->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

std::shared_ptr<Union<uml::NamedElement>> PrimitiveTypeImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> PrimitiveTypeImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> PrimitiveTypeImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> PrimitiveTypeImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> PrimitiveTypeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> PrimitiveTypeImpl::getRedefinedElement() const
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




std::shared_ptr<PrimitiveType> PrimitiveTypeImpl::getThisPrimitiveTypePtr() const
{
	return m_thisPrimitiveTypePtr.lock();
}
void PrimitiveTypeImpl::setThisPrimitiveTypePtr(std::weak_ptr<PrimitiveType> thisPrimitiveTypePtr)
{
	m_thisPrimitiveTypePtr = thisPrimitiveTypePtr;
	setThisDataTypePtr(thisPrimitiveTypePtr);
}
std::shared_ptr<ecore::EObject> PrimitiveTypeImpl::eContainer() const
{
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
	if(auto wp = m_package.lock())
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
Any PrimitiveTypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return DataTypeImpl::eGet(featureID, resolve, coreType);
}
bool PrimitiveTypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return DataTypeImpl::internalEIsSet(featureID);
}
bool PrimitiveTypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return DataTypeImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any PrimitiveTypeImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DataTypeImpl::eInvoke(operationID, arguments);
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
void PrimitiveTypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PrimitiveTypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	DataTypeImpl::loadAttributes(loadHandler, attr_list);
}

void PrimitiveTypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DataTypeImpl::loadNode(nodeName, loadHandler);
}

void PrimitiveTypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	DataTypeImpl::resolveReferences(featureID, references);
}

void PrimitiveTypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DataTypeImpl::saveContent(saveHandler);
	
	ClassifierImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void PrimitiveTypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

