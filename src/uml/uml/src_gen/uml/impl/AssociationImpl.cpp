
#include "uml/impl/AssociationImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
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
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/Relationship.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/Type.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AssociationImpl::AssociationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AssociationImpl::~AssociationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Association "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
AssociationImpl::AssociationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:AssociationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
AssociationImpl::AssociationImpl(std::weak_ptr<uml::Element> par_owner)
:AssociationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
AssociationImpl::AssociationImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:AssociationImpl()
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
AssociationImpl::AssociationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:AssociationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


AssociationImpl::AssociationImpl(const AssociationImpl & obj): AssociationImpl()
{
	*this = obj;
}

AssociationImpl& AssociationImpl::operator=(const AssociationImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassifierImpl::operator=(obj);
	RelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Association 
	 * which is generated by the compiler (as Association is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Association::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Association "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isDerived = obj.getIsDerived();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'endType'
	std::shared_ptr<Subset<uml::Type, uml::Element>> endTypeList = obj.getEndType();
	if(endTypeList)
	{
		/*Subset*/
		m_endType.reset(new Subset<uml::Type, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_endType - Subset<uml::Type, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEndType()->initSubset(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_endType - Subset<uml::Type, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Type>& endTypeindexElem: *endTypeList) 
		{
			std::shared_ptr<uml::Type> temp = std::dynamic_pointer_cast<uml::Type>((endTypeindexElem)->copy());
			m_endType->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for endType.")
	}

	//clone reference 'memberEnd'
	std::shared_ptr<SubsetUnion<uml::Property, uml::NamedElement>> memberEndList = obj.getMemberEnd();
	if(memberEndList)
	{
		/*SubsetUnion*/
		m_memberEnd.reset(new SubsetUnion<uml::Property, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_memberEnd - SubsetUnion<uml::Property, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getMemberEnd()->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_memberEnd - SubsetUnion<uml::Property, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Property>& memberEndindexElem: *memberEndList) 
		{
			std::shared_ptr<uml::Property> temp = std::dynamic_pointer_cast<uml::Property>((memberEndindexElem)->copy());
			m_memberEnd->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for memberEnd.")
	}

	//clone reference 'navigableOwnedEnd'
	std::shared_ptr<Subset<uml::Property, uml::Property /*Subset does not reference a union*/>> navigableOwnedEndList = obj.getNavigableOwnedEnd();
	if(navigableOwnedEndList)
	{
		/*Subset*/
		m_navigableOwnedEnd.reset(new Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_navigableOwnedEnd - Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getNavigableOwnedEnd()->initSubset(getOwnedEnd());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_navigableOwnedEnd - Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >(getOwnedEnd())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Property>& navigableOwnedEndindexElem: *navigableOwnedEndList) 
		{
			std::shared_ptr<uml::Property> temp = std::dynamic_pointer_cast<uml::Property>((navigableOwnedEndindexElem)->copy());
			m_navigableOwnedEnd->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for navigableOwnedEnd.")
	}

	//clone reference 'ownedEnd'
	std::shared_ptr<SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/>> ownedEndList = obj.getOwnedEnd();
	if(ownedEndList)
	{
		/*SubsetUnion*/
		m_ownedEnd.reset(new SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedEnd - SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedEnd()->initSubsetUnion(getFeature(), getOwnedMember(), getMemberEnd());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedEnd - SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/ >(getFeature(), getOwnedMember(), getMemberEnd())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Property>& ownedEndindexElem: *ownedEndList) 
		{
			std::shared_ptr<uml::Property> temp = std::dynamic_pointer_cast<uml::Property>((ownedEndindexElem)->copy());
			m_ownedEnd->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedEnd.")
	}
	/*SubsetUnion*/
	getOwnedEnd()->initSubsetUnion(getFeature(), getOwnedMember(), getMemberEnd());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_ownedEnd - SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/ >(getFeature(), getOwnedMember(), getMemberEnd())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> AssociationImpl::copy() const
{
	std::shared_ptr<AssociationImpl> element(new AssociationImpl());
	*element =(*this);
	element->setThisAssociationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Type>> AssociationImpl::getEndTypes()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool AssociationImpl::isBinary()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isDerived */
bool AssociationImpl::getIsDerived() const 
{
	return m_isDerived;
}
void AssociationImpl::setIsDerived(bool _isDerived)
{
	m_isDerived = _isDerived;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference endType */
const std::shared_ptr<Subset<uml::Type, uml::Element>>& AssociationImpl::getEndType() const
{
	if(m_endType == nullptr)
	{
		/*Subset*/
		m_endType.reset(new Subset<uml::Type, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_endType - Subset<uml::Type, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEndType()->initSubset(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_endType - Subset<uml::Type, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
    return m_endType;
}

/* Getter & Setter for reference memberEnd */
const std::shared_ptr<SubsetUnion<uml::Property, uml::NamedElement>>& AssociationImpl::getMemberEnd() const
{
	if(m_memberEnd == nullptr)
	{
		/*SubsetUnion*/
		m_memberEnd.reset(new SubsetUnion<uml::Property, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_memberEnd - SubsetUnion<uml::Property, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getMemberEnd()->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_memberEnd - SubsetUnion<uml::Property, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
    return m_memberEnd;
}

/* Getter & Setter for reference navigableOwnedEnd */
const std::shared_ptr<Subset<uml::Property, uml::Property /*Subset does not reference a union*/>>& AssociationImpl::getNavigableOwnedEnd() const
{
	if(m_navigableOwnedEnd == nullptr)
	{
		/*Subset*/
		m_navigableOwnedEnd.reset(new Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_navigableOwnedEnd - Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getNavigableOwnedEnd()->initSubset(getOwnedEnd());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_navigableOwnedEnd - Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >(getOwnedEnd())" << std::endl;
		#endif
		
	}
    return m_navigableOwnedEnd;
}

/* Getter & Setter for reference ownedEnd */
const std::shared_ptr<SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/>>& AssociationImpl::getOwnedEnd() const
{
	if(m_ownedEnd == nullptr)
	{
		/*SubsetUnion*/
		m_ownedEnd.reset(new SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedEnd - SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedEnd()->initSubsetUnion(getFeature(), getOwnedMember(), getMemberEnd());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedEnd - SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/ >(getFeature(), getOwnedMember(), getMemberEnd())" << std::endl;
		#endif
		
	}
    return m_ownedEnd;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> AssociationImpl::eContainer() const
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
// Persistence Functions
//*********************************
void AssociationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AssociationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isDerived");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsDerived(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("memberEnd");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("memberEnd")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("navigableOwnedEnd");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("navigableOwnedEnd")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ClassifierImpl::loadAttributes(loadHandler, attr_list);
	RelationshipImpl::loadAttributes(loadHandler, attr_list);
}

void AssociationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedEnd") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Property";
			}
			loadHandler->handleChildContainer<uml::Property>(this->getOwnedEnd());  

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
	ClassifierImpl::loadNode(nodeName, loadHandler);
	RelationshipImpl::loadNode(nodeName, loadHandler);
}

void AssociationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_MEMBEREND:
		{
			const std::shared_ptr<SubsetUnion<uml::Property, uml::NamedElement>>& _memberEnd = getMemberEnd();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Property>  _r = std::dynamic_pointer_cast<uml::Property>(ref);
				if (_r != nullptr)
				{
					_memberEnd->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_NAVIGABLEOWNEDEND:
		{
			const std::shared_ptr<Subset<uml::Property, uml::Property /*Subset does not reference a union*/>>& _navigableOwnedEnd = getNavigableOwnedEnd();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Property>  _r = std::dynamic_pointer_cast<uml::Property>(ref);
				if (_r != nullptr)
				{
					_navigableOwnedEnd->push_back(_r);
				}
			}
			return;
		}
	}
	ClassifierImpl::resolveReferences(featureID, references);
	RelationshipImpl::resolveReferences(featureID, references);
}

void AssociationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ClassifierImpl::saveContent(saveHandler);
	RelationshipImpl::saveContent(saveHandler);
	
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

void AssociationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getAssociation_Attribute_isDerived()) )
		{
			saveHandler->addAttribute("isDerived", this->getIsDerived());
		}
	// Add references
		saveHandler->addReferences<uml::Property>("memberEnd", this->getMemberEnd());
		saveHandler->addReferences<uml::Property>("navigableOwnedEnd", this->getNavigableOwnedEnd());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'ownedEnd'

		saveHandler->addReferences<uml::Property>("ownedEnd", this->getOwnedEnd());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& AssociationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getAssociation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> AssociationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_ENDTYPE:
			return eEcoreContainerAny(getEndType(),uml::umlPackage::TYPE_CLASS); //2139
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_ISDERIVED:
			return eAny(getIsDerived(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //2140
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_MEMBEREND:
			return eEcoreContainerAny(getMemberEnd(),uml::umlPackage::PROPERTY_CLASS); //2141
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_NAVIGABLEOWNEDEND:
			return eEcoreContainerAny(getNavigableOwnedEnd(),uml::umlPackage::PROPERTY_CLASS); //2143
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_OWNEDEND:
			return eEcoreContainerAny(getOwnedEnd(),uml::umlPackage::PROPERTY_CLASS); //2142
	}
	std::shared_ptr<Any> result;
	result = ClassifierImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = RelationshipImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool AssociationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_ENDTYPE:
			return getEndType() != nullptr; //2139
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_ISDERIVED:
			return getIsDerived() != false; //2140
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_MEMBEREND:
			return getMemberEnd() != nullptr; //2141
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_NAVIGABLEOWNEDEND:
			return getNavigableOwnedEnd() != nullptr; //2143
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_OWNEDEND:
			return getOwnedEnd() != nullptr; //2142
	}
	bool result = false;
	result = ClassifierImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = RelationshipImpl::internalEIsSet(featureID);
	return result;
}

bool AssociationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_ISDERIVED:
		{
			try
			{
				bool _isDerived = newValue->get<bool>();
				setIsDerived(_isDerived); //2140
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isDerived'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_MEMBEREND:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Property>>& _memberEnd = getMemberEnd();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Property> valueToAdd = std::dynamic_pointer_cast<uml::Property>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_memberEnd->includes(valueToAdd)))
								{
									_memberEnd->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'memberEnd'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'memberEnd'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_NAVIGABLEOWNEDEND:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Property>>& _navigableOwnedEnd = getNavigableOwnedEnd();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Property> valueToAdd = std::dynamic_pointer_cast<uml::Property>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_navigableOwnedEnd->includes(valueToAdd)))
								{
									_navigableOwnedEnd->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'navigableOwnedEnd'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'navigableOwnedEnd'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_OWNEDEND:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Property>>& _ownedEnd = getOwnedEnd();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Property> valueToAdd = std::dynamic_pointer_cast<uml::Property>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_ownedEnd->includes(valueToAdd)))
								{
									_ownedEnd->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedEnd'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedEnd'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = ClassifierImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = RelationshipImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> AssociationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Association::getEndTypes() : uml::Type[*]: 2690402644
		case umlPackage::ASSOCIATION_OPERATION_GETENDTYPES:
		{
			std::shared_ptr<Bag<uml::Type>> resultList = this->getEndTypes();
			return eEcoreContainerAny(resultList,uml::umlPackage::TYPE_CLASS);
			break;
		}
		// uml::Association::isBinary() : bool: 1073463579
		case umlPackage::ASSOCIATION_OPERATION_ISBINARY:
		{
			result = eAny(this->isBinary(), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = RelationshipImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = ClassifierImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Association> AssociationImpl::getThisAssociationPtr() const
{
	return m_thisAssociationPtr.lock();
}
void AssociationImpl::setThisAssociationPtr(std::weak_ptr<uml::Association> thisAssociationPtr)
{
	m_thisAssociationPtr = thisAssociationPtr;
	setThisClassifierPtr(thisAssociationPtr);
	setThisRelationshipPtr(thisAssociationPtr);
}


