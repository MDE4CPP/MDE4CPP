#include "uml/impl/AssociationImpl.hpp"

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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	Association::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Association "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isDerived = obj.getIsDerived();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Type, uml::Element>> endTypeContainer = getEndType();
	if(nullptr != endTypeContainer )
	{
		int size = endTypeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _endType=(*endTypeContainer)[i];
			if(nullptr != _endType)
			{
				endTypeContainer->push_back(std::dynamic_pointer_cast<uml::Type>(_endType->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container endType."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr endType."<< std::endl;)
	}
	std::shared_ptr<SubsetUnion<uml::Property, uml::NamedElement>> memberEndContainer = getMemberEnd();
	if(nullptr != memberEndContainer )
	{
		int size = memberEndContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _memberEnd=(*memberEndContainer)[i];
			if(nullptr != _memberEnd)
			{
				memberEndContainer->push_back(std::dynamic_pointer_cast<uml::Property>(_memberEnd->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container memberEnd."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr memberEnd."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Property, uml::Property /*Subset does not reference a union*/>> navigableOwnedEndContainer = getNavigableOwnedEnd();
	if(nullptr != navigableOwnedEndContainer )
	{
		int size = navigableOwnedEndContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _navigableOwnedEnd=(*navigableOwnedEndContainer)[i];
			if(nullptr != _navigableOwnedEnd)
			{
				navigableOwnedEndContainer->push_back(std::dynamic_pointer_cast<uml::Property>(_navigableOwnedEnd->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container navigableOwnedEnd."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr navigableOwnedEnd."<< std::endl;)
	}
	std::shared_ptr<SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement>> ownedEndContainer = getOwnedEnd();
	if(nullptr != ownedEndContainer )
	{
		int size = ownedEndContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedEnd=(*ownedEndContainer)[i];
			if(nullptr != _ownedEnd)
			{
				ownedEndContainer->push_back(std::dynamic_pointer_cast<uml::Property>(_ownedEnd->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedEnd."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedEnd."<< std::endl;)
	}
	/*SubsetUnion*/
	m_ownedEnd->initSubsetUnion(getMemberEnd(),getFeature(),getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_ownedEnd - SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement >(getMemberEnd(),getFeature(),getOwnedMember())" << std::endl;
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

std::shared_ptr<ecore::EClass> AssociationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getAssociation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isDerived
*/
bool AssociationImpl::getIsDerived() const 
{
	return m_isDerived;
}
void AssociationImpl::setIsDerived(bool _isDerived)
{
	m_isDerived = _isDerived;
} 


//*********************************
// Operations
//*********************************
bool AssociationImpl::association_ends(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AssociationImpl::binary_associations(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AssociationImpl::ends_must_be_typed(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Type> > AssociationImpl::getEndTypes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AssociationImpl::isBinary()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AssociationImpl::specialized_end_number(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AssociationImpl::specialized_end_types(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference endType
*/
std::shared_ptr<Subset<uml::Type, uml::Element>> AssociationImpl::getEndType() const
{
	if(m_endType == nullptr)
	{
		/*Subset*/
		m_endType.reset(new Subset<uml::Type, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_endType - Subset<uml::Type, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_endType->initSubset(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_endType - Subset<uml::Type, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
//assert(m_endType);
    return m_endType;
}



/*
Getter & Setter for reference memberEnd
*/
std::shared_ptr<SubsetUnion<uml::Property, uml::NamedElement>> AssociationImpl::getMemberEnd() const
{
	if(m_memberEnd == nullptr)
	{
		/*SubsetUnion*/
		m_memberEnd.reset(new SubsetUnion<uml::Property, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_memberEnd - SubsetUnion<uml::Property, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_memberEnd->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_memberEnd - SubsetUnion<uml::Property, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
//assert(m_memberEnd);
    return m_memberEnd;
}



/*
Getter & Setter for reference navigableOwnedEnd
*/
std::shared_ptr<Subset<uml::Property, uml::Property /*Subset does not reference a union*/>> AssociationImpl::getNavigableOwnedEnd() const
{
	if(m_navigableOwnedEnd == nullptr)
	{
		/*Subset*/
		m_navigableOwnedEnd.reset(new Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_navigableOwnedEnd - Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_navigableOwnedEnd->initSubset(getOwnedEnd());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_navigableOwnedEnd - Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >(getOwnedEnd())" << std::endl;
		#endif
		
	}

    return m_navigableOwnedEnd;
}



/*
Getter & Setter for reference ownedEnd
*/
std::shared_ptr<SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement>> AssociationImpl::getOwnedEnd() const
{
	if(m_ownedEnd == nullptr)
	{
		/*SubsetUnion*/
		m_ownedEnd.reset(new SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedEnd - SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedEnd->initSubsetUnion(getMemberEnd(),getFeature(),getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedEnd - SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement >(getMemberEnd(),getFeature(),getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedEnd;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> AssociationImpl::getFeature() const
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

std::shared_ptr<Union<uml::NamedElement>> AssociationImpl::getMember() const
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

std::weak_ptr<uml::Namespace> AssociationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> AssociationImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> AssociationImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> AssociationImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> AssociationImpl::getRedefinedElement() const
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

std::shared_ptr<Union<uml::Element>> AssociationImpl::getRelatedElement() const
{
	if(m_relatedElement == nullptr)
	{
		/*Union*/
		m_relatedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_relatedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_relatedElement;
}




std::shared_ptr<Association> AssociationImpl::getThisAssociationPtr() const
{
	return m_thisAssociationPtr.lock();
}
void AssociationImpl::setThisAssociationPtr(std::weak_ptr<Association> thisAssociationPtr)
{
	m_thisAssociationPtr = thisAssociationPtr;
	setThisClassifierPtr(thisAssociationPtr);
	setThisRelationshipPtr(thisAssociationPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any AssociationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_ENDTYPE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Type>::iterator iter = m_endType->begin();
			Bag<uml::Type>::iterator end = m_endType->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2139			
		}
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_ISDERIVED:
			return eAny(getIsDerived()); //2140
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_MEMBEREND:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Property>::iterator iter = m_memberEnd->begin();
			Bag<uml::Property>::iterator end = m_memberEnd->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2141			
		}
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_NAVIGABLEOWNEDEND:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Property>::iterator iter = m_navigableOwnedEnd->begin();
			Bag<uml::Property>::iterator end = m_navigableOwnedEnd->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2143			
		}
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_OWNEDEND:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Property>::iterator iter = m_ownedEnd->begin();
			Bag<uml::Property>::iterator end = m_ownedEnd->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2142			
		}
	}
	Any result;
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
bool AssociationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_ISDERIVED:
		{
			// BOOST CAST
			bool _isDerived = newValue->get<bool>();
			setIsDerived(_isDerived); //2140
			return true;
		}
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_MEMBEREND:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Property>> memberEndList(new Bag<uml::Property>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				memberEndList->add(std::dynamic_pointer_cast<uml::Property>(*iter));
				iter++;
			}
			
			Bag<uml::Property>::iterator iterMemberEnd = m_memberEnd->begin();
			Bag<uml::Property>::iterator endMemberEnd = m_memberEnd->end();
			while (iterMemberEnd != endMemberEnd)
			{
				if (memberEndList->find(*iterMemberEnd) == -1)
				{
					m_memberEnd->erase(*iterMemberEnd);
				}
				iterMemberEnd++;
			}
 
			iterMemberEnd = memberEndList->begin();
			endMemberEnd = memberEndList->end();
			while (iterMemberEnd != endMemberEnd)
			{
				if (m_memberEnd->find(*iterMemberEnd) == -1)
				{
					m_memberEnd->add(*iterMemberEnd);
				}
				iterMemberEnd++;			
			}
			return true;
		}
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_NAVIGABLEOWNEDEND:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Property>> navigableOwnedEndList(new Bag<uml::Property>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				navigableOwnedEndList->add(std::dynamic_pointer_cast<uml::Property>(*iter));
				iter++;
			}
			
			Bag<uml::Property>::iterator iterNavigableOwnedEnd = m_navigableOwnedEnd->begin();
			Bag<uml::Property>::iterator endNavigableOwnedEnd = m_navigableOwnedEnd->end();
			while (iterNavigableOwnedEnd != endNavigableOwnedEnd)
			{
				if (navigableOwnedEndList->find(*iterNavigableOwnedEnd) == -1)
				{
					m_navigableOwnedEnd->erase(*iterNavigableOwnedEnd);
				}
				iterNavigableOwnedEnd++;
			}
 
			iterNavigableOwnedEnd = navigableOwnedEndList->begin();
			endNavigableOwnedEnd = navigableOwnedEndList->end();
			while (iterNavigableOwnedEnd != endNavigableOwnedEnd)
			{
				if (m_navigableOwnedEnd->find(*iterNavigableOwnedEnd) == -1)
				{
					m_navigableOwnedEnd->add(*iterNavigableOwnedEnd);
				}
				iterNavigableOwnedEnd++;			
			}
			return true;
		}
		case uml::umlPackage::ASSOCIATION_ATTRIBUTE_OWNEDEND:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Property>> ownedEndList(new Bag<uml::Property>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedEndList->add(std::dynamic_pointer_cast<uml::Property>(*iter));
				iter++;
			}
			
			Bag<uml::Property>::iterator iterOwnedEnd = m_ownedEnd->begin();
			Bag<uml::Property>::iterator endOwnedEnd = m_ownedEnd->end();
			while (iterOwnedEnd != endOwnedEnd)
			{
				if (ownedEndList->find(*iterOwnedEnd) == -1)
				{
					m_ownedEnd->erase(*iterOwnedEnd);
				}
				iterOwnedEnd++;
			}
 
			iterOwnedEnd = ownedEndList->begin();
			endOwnedEnd = ownedEndList->end();
			while (iterOwnedEnd != endOwnedEnd)
			{
				if (m_ownedEnd->find(*iterOwnedEnd) == -1)
				{
					m_ownedEnd->add(*iterOwnedEnd);
				}
				iterOwnedEnd++;			
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
// Behavioral Feature
//*********************************
Any AssociationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 2257
		case umlPackage::ASSOCIATION_OPERATION_ASSOCIATION_ENDS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->association_ends(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 2256
		case umlPackage::ASSOCIATION_OPERATION_BINARY_ASSOCIATIONS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->binary_associations(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 2258
		case umlPackage::ASSOCIATION_OPERATION_ENDS_MUST_BE_TYPED_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->ends_must_be_typed(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 2260
		case umlPackage::ASSOCIATION_OPERATION_GETENDTYPES:
		{
			result = eAny(this->getEndTypes());
			break;
		}
		
		// 2259
		case umlPackage::ASSOCIATION_OPERATION_ISBINARY:
		{
			result = eAny(this->isBinary());
			break;
		}
		
		// 2254
		case umlPackage::ASSOCIATION_OPERATION_SPECIALIZED_END_NUMBER_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->specialized_end_number(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 2255
		case umlPackage::ASSOCIATION_OPERATION_SPECIALIZED_END_TYPES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->specialized_end_types(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = RelationshipImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = ClassifierImpl::eInvoke(operationID, arguments);
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
			std::shared_ptr<SubsetUnion<uml::Property, uml::NamedElement>> _memberEnd = getMemberEnd();
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
			std::shared_ptr<Subset<uml::Property, uml::Property /*Subset does not reference a union*/>> _navigableOwnedEnd = getNavigableOwnedEnd();
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

