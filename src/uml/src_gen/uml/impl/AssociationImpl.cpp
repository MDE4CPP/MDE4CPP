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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Classifier.hpp"

#include "uml/CollaborationUse.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

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

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AssociationImpl::AssociationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_endType.reset(new Subset<uml::Type, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_endType - Subset<uml::Type, uml::Element >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_memberEnd.reset(new SubsetUnion<uml::Property, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_memberEnd - SubsetUnion<uml::Property, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_navigableOwnedEnd.reset(new Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_navigableOwnedEnd - Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedEnd.reset(new SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedEnd - SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_endType->initSubset(m_relatedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_endType - Subset<uml::Type, uml::Element >(m_relatedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_memberEnd->initSubsetUnion(m_member);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_memberEnd - SubsetUnion<uml::Property, uml::NamedElement >(m_member)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_navigableOwnedEnd->initSubset(m_ownedEnd);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_navigableOwnedEnd - Subset<uml::Property, uml::Property /*Subset does not reference a union*/ >(m_ownedEnd)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedEnd->initSubsetUnion(m_memberEnd,m_feature,m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedEnd - SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement >(m_memberEnd,m_feature,m_ownedMember)" << std::endl;
		#endif
	
	
}

AssociationImpl::~AssociationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Association "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			AssociationImpl::AssociationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:AssociationImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			AssociationImpl::AssociationImpl(std::weak_ptr<uml::Element > par_owner)
			:AssociationImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			AssociationImpl::AssociationImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
			:AssociationImpl()
			{
				switch(reference_id)
				{	
				case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
					m_owningPackage = par_Package;
					m_namespace = par_Package;
					 return;
				case UmlPackage::TYPE_EREFERENCE_PACKAGE:
					m_package = par_Package;
					m_namespace = par_Package;
					 return;
				default:
				std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
				}
			   
			}





//Additional constructor for the containments back reference
			AssociationImpl::AssociationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:AssociationImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}





//Additional constructor for the containments back reference






AssociationImpl::AssociationImpl(const AssociationImpl & obj):AssociationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Association "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isAbstract = obj.getIsAbstract();
	m_isDerived = obj.getIsDerived();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::Classifier>> _general = obj.getGeneral();
	m_general.reset(new Bag<uml::Classifier>(*(obj.getGeneral().get())));

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_package  = obj.getPackage();

	std::shared_ptr<Bag<uml::GeneralizationSet>> _powertypeExtent = obj.getPowertypeExtent();
	m_powertypeExtent.reset(new Bag<uml::GeneralizationSet>(*(obj.getPowertypeExtent().get())));

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	std::shared_ptr<Union<uml::Element>> _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_templateParameter  = obj.getTemplateParameter();

	std::shared_ptr<Bag<uml::UseCase>> _useCase = obj.getUseCase();
	m_useCase.reset(new Bag<uml::UseCase>(*(obj.getUseCase().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::CollaborationUse>> _collaborationUseList = obj.getCollaborationUse();
	for(std::shared_ptr<uml::CollaborationUse> _collaborationUse : *_collaborationUseList)
	{
		this->getCollaborationUse()->add(std::shared_ptr<uml::CollaborationUse>(std::dynamic_pointer_cast<uml::CollaborationUse>(_collaborationUse->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_collaborationUse" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Type>> _endTypeList = obj.getEndType();
	for(std::shared_ptr<uml::Type> _endType : *_endTypeList)
	{
		this->getEndType()->add(std::shared_ptr<uml::Type>(std::dynamic_pointer_cast<uml::Type>(_endType->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_endType" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Generalization>> _generalizationList = obj.getGeneralization();
	for(std::shared_ptr<uml::Generalization> _generalization : *_generalizationList)
	{
		this->getGeneralization()->add(std::shared_ptr<uml::Generalization>(std::dynamic_pointer_cast<uml::Generalization>(_generalization->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalization" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::NamedElement>> _inheritedMemberList = obj.getInheritedMember();
	for(std::shared_ptr<uml::NamedElement> _inheritedMember : *_inheritedMemberList)
	{
		this->getInheritedMember()->add(std::shared_ptr<uml::NamedElement>(std::dynamic_pointer_cast<uml::NamedElement>(_inheritedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inheritedMember" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Property>> _memberEndList = obj.getMemberEnd();
	for(std::shared_ptr<uml::Property> _memberEnd : *_memberEndList)
	{
		this->getMemberEnd()->add(std::shared_ptr<uml::Property>(std::dynamic_pointer_cast<uml::Property>(_memberEnd->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_memberEnd" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Property>> _navigableOwnedEndList = obj.getNavigableOwnedEnd();
	for(std::shared_ptr<uml::Property> _navigableOwnedEnd : *_navigableOwnedEndList)
	{
		this->getNavigableOwnedEnd()->add(std::shared_ptr<uml::Property>(std::dynamic_pointer_cast<uml::Property>(_navigableOwnedEnd->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_navigableOwnedEnd" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Property>> _ownedEndList = obj.getOwnedEnd();
	for(std::shared_ptr<uml::Property> _ownedEnd : *_ownedEndList)
	{
		this->getOwnedEnd()->add(std::shared_ptr<uml::Property>(std::dynamic_pointer_cast<uml::Property>(_ownedEnd->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedEnd" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getOwnedTemplateSignature()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedTemplateSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::UseCase>> _ownedUseCaseList = obj.getOwnedUseCase();
	for(std::shared_ptr<uml::UseCase> _ownedUseCase : *_ownedUseCaseList)
	{
		this->getOwnedUseCase()->add(std::shared_ptr<uml::UseCase>(std::dynamic_pointer_cast<uml::UseCase>(_ownedUseCase->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedUseCase" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Classifier>> _redefinedClassifierList = obj.getRedefinedClassifier();
	for(std::shared_ptr<uml::Classifier> _redefinedClassifier : *_redefinedClassifierList)
	{
		this->getRedefinedClassifier()->add(std::shared_ptr<uml::Classifier>(std::dynamic_pointer_cast<uml::Classifier>(_redefinedClassifier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedClassifier" << std::endl;
	#endif
	if(obj.getRepresentation()!=nullptr)
	{
		m_representation = std::dynamic_pointer_cast<uml::CollaborationUse>(obj.getRepresentation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_representation" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Substitution>> _substitutionList = obj.getSubstitution();
	for(std::shared_ptr<uml::Substitution> _substitution : *_substitutionList)
	{
		this->getSubstitution()->add(std::shared_ptr<uml::Substitution>(std::dynamic_pointer_cast<uml::Substitution>(_substitution->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_substitution" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(std::dynamic_pointer_cast<uml::TemplateBinding>(_templateBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_templateBinding" << std::endl;
	#endif

		/*SubsetUnion*/
		m_ownedEnd->initSubsetUnion(m_memberEnd,m_feature,m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedEnd - SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement >(m_memberEnd,m_feature,m_ownedMember)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  AssociationImpl::copy() const
{
	std::shared_ptr<AssociationImpl> element(new AssociationImpl(*this));
	element->setThisAssociationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> AssociationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getAssociation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void AssociationImpl::setIsDerived(bool _isDerived)
{
	m_isDerived = _isDerived;
} 

bool AssociationImpl::getIsDerived() const 
{
	return m_isDerived;
}

//*********************************
// Operations
//*********************************
bool AssociationImpl::association_ends(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AssociationImpl::binary_associations(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AssociationImpl::ends_must_be_typed(Any diagnostics,std::map <   Any, Any >  context)
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

bool AssociationImpl::specialized_end_number(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AssociationImpl::specialized_end_types(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Type, uml::Element>> AssociationImpl::getEndType() const
{
//assert(m_endType);
    return m_endType;
}


std::shared_ptr<SubsetUnion<uml::Property, uml::NamedElement>> AssociationImpl::getMemberEnd() const
{
//assert(m_memberEnd);
    return m_memberEnd;
}


std::shared_ptr<Subset<uml::Property, uml::Property /*Subset does not reference a union*/>> AssociationImpl::getNavigableOwnedEnd() const
{

    return m_navigableOwnedEnd;
}


std::shared_ptr<SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement>> AssociationImpl::getOwnedEnd() const
{

    return m_ownedEnd;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> AssociationImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<Union<uml::NamedElement>> AssociationImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > AssociationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> AssociationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> AssociationImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > AssociationImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> AssociationImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Element>> AssociationImpl::getRelatedElement() const
{
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
		case UmlPackage::ASSOCIATION_EREFERENCE_ENDTYPE:
			return eAny(getEndType()); //2140
		case UmlPackage::ASSOCIATION_EATTRIBUTE_ISDERIVED:
			return eAny(getIsDerived()); //2141
		case UmlPackage::ASSOCIATION_EREFERENCE_MEMBEREND:
			return eAny(getMemberEnd()); //2142
		case UmlPackage::ASSOCIATION_EREFERENCE_NAVIGABLEOWNEDEND:
			return eAny(getNavigableOwnedEnd()); //2144
		case UmlPackage::ASSOCIATION_EREFERENCE_OWNEDEND:
			return eAny(getOwnedEnd()); //2143
	}
	Any result;
	result = ClassifierImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
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
		case UmlPackage::ASSOCIATION_EREFERENCE_ENDTYPE:
			return getEndType() != nullptr; //2140
		case UmlPackage::ASSOCIATION_EATTRIBUTE_ISDERIVED:
			return getIsDerived() != false; //2141
		case UmlPackage::ASSOCIATION_EREFERENCE_MEMBEREND:
			return getMemberEnd() != nullptr; //2142
		case UmlPackage::ASSOCIATION_EREFERENCE_NAVIGABLEOWNEDEND:
			return getNavigableOwnedEnd() != nullptr; //2144
		case UmlPackage::ASSOCIATION_EREFERENCE_OWNEDEND:
			return getOwnedEnd() != nullptr; //2143
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
		case UmlPackage::ASSOCIATION_EATTRIBUTE_ISDERIVED:
		{
			// BOOST CAST
			bool _isDerived = newValue->get<bool>();
			setIsDerived(_isDerived); //2141
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
// Persistence Functions
//*********************************
void AssociationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void AssociationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
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
			std::shared_ptr<ecore::EObject> ownedEnd = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PROPERTY_EREFERENCE_OWNINGASSOCIATION);
			if (ownedEnd != nullptr)
			{
				loadHandler->handleChild(ownedEnd);
			}
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

	ClassifierImpl::loadNode(nodeName, loadHandler, modelFactory);
	RelationshipImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void AssociationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::ASSOCIATION_EREFERENCE_MEMBEREND:
		{
			std::shared_ptr<Bag<uml::Property>> _memberEnd = getMemberEnd();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Property> _r = std::dynamic_pointer_cast<uml::Property>(ref);
				if (_r != nullptr)
				{
					_memberEnd->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::ASSOCIATION_EREFERENCE_NAVIGABLEOWNEDEND:
		{
			std::shared_ptr<Bag<uml::Property>> _navigableOwnedEnd = getNavigableOwnedEnd();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Property> _r = std::dynamic_pointer_cast<uml::Property>(ref);
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
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void AssociationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getAssociation_EAttribute_isDerived()) )
		{
			saveHandler->addAttribute("isDerived", this->getIsDerived());
		}

		// Add references
		std::shared_ptr<Bag<uml::Property>> memberEnd_list = this->getMemberEnd();
		for (std::shared_ptr<uml::Property > object : *memberEnd_list)
		{ 
			saveHandler->addReferences("memberEnd", object);
		}
		std::shared_ptr<Bag<uml::Property>> navigableOwnedEnd_list = this->getNavigableOwnedEnd();
		for (std::shared_ptr<uml::Property > object : *navigableOwnedEnd_list)
		{ 
			saveHandler->addReferences("navigableOwnedEnd", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'ownedEnd'
		std::shared_ptr<SubsetUnion<uml::Property, uml::Property /*Subset does not reference a union*/,uml::Feature,uml::NamedElement>> list_ownedEnd = this->getOwnedEnd();
		for (std::shared_ptr<uml::Property> ownedEnd : *list_ownedEnd) 
		{
			saveHandler->addReference(ownedEnd, "ownedEnd", ownedEnd->eClass() != package->getProperty_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

