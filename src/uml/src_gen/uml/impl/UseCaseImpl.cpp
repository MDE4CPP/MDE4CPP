#include "uml/impl/UseCaseImpl.hpp"

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
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Behavior.hpp"

#include "uml/BehavioredClassifier.hpp"

#include "uml/Classifier.hpp"

#include "uml/CollaborationUse.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/Extend.hpp"

#include "uml/ExtensionPoint.hpp"

#include "uml/Feature.hpp"

#include "uml/Generalization.hpp"

#include "uml/GeneralizationSet.hpp"

#include "uml/Include.hpp"

#include "uml/InterfaceRealization.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

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
UseCaseImpl::UseCaseImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_extend.reset(new Subset<uml::Extend, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extend - Subset<uml::Extend, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_extensionPoint.reset(new Subset<uml::ExtensionPoint, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extensionPoint - Subset<uml::ExtensionPoint, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_include.reset(new Subset<uml::Include, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_include - Subset<uml::Include, uml::NamedElement >()" << std::endl;
		#endif
	
	

		m_subject.reset(new Bag<uml::Classifier>());
	
	

	//Init references
		/*Subset*/
		m_extend->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extend - Subset<uml::Extend, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_extensionPoint->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extensionPoint - Subset<uml::ExtensionPoint, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_include->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_include - Subset<uml::Include, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

	
	
}

UseCaseImpl::~UseCaseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UseCase "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:UseCaseImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::Element > par_owner)
			:UseCaseImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
:UseCaseImpl()
{
	switch(reference_id)
	{	
	case UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}





//Additional constructor for the containments back reference
			UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:UseCaseImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}





//Additional constructor for the containments back reference






UseCaseImpl::UseCaseImpl(const UseCaseImpl & obj):UseCaseImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UseCase "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isAbstract = obj.getIsAbstract();
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

	std::shared_ptr<Bag<uml::Classifier>> _subject = obj.getSubject();
	m_subject.reset(new Bag<uml::Classifier>(*(obj.getSubject().get())));

	m_templateParameter  = obj.getTemplateParameter();

	std::shared_ptr<Bag<uml::UseCase>> _useCase = obj.getUseCase();
	m_useCase.reset(new Bag<uml::UseCase>(*(obj.getUseCase().get())));


	//Clone references with containment (deep copy)

	if(obj.getClassifierBehavior()!=nullptr)
	{
		m_classifierBehavior = std::dynamic_pointer_cast<uml::Behavior>(obj.getClassifierBehavior()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_classifierBehavior" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::CollaborationUse>> _collaborationUseList = obj.getCollaborationUse();
	for(std::shared_ptr<uml::CollaborationUse> _collaborationUse : *_collaborationUseList)
	{
		this->getCollaborationUse()->add(std::shared_ptr<uml::CollaborationUse>(std::dynamic_pointer_cast<uml::CollaborationUse>(_collaborationUse->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_collaborationUse" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Extend>> _extendList = obj.getExtend();
	for(std::shared_ptr<uml::Extend> _extend : *_extendList)
	{
		this->getExtend()->add(std::shared_ptr<uml::Extend>(std::dynamic_pointer_cast<uml::Extend>(_extend->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_extend" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ExtensionPoint>> _extensionPointList = obj.getExtensionPoint();
	for(std::shared_ptr<uml::ExtensionPoint> _extensionPoint : *_extensionPointList)
	{
		this->getExtensionPoint()->add(std::shared_ptr<uml::ExtensionPoint>(std::dynamic_pointer_cast<uml::ExtensionPoint>(_extensionPoint->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_extensionPoint" << std::endl;
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
	std::shared_ptr<Bag<uml::Include>> _includeList = obj.getInclude();
	for(std::shared_ptr<uml::Include> _include : *_includeList)
	{
		this->getInclude()->add(std::shared_ptr<uml::Include>(std::dynamic_pointer_cast<uml::Include>(_include->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_include" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::NamedElement>> _inheritedMemberList = obj.getInheritedMember();
	for(std::shared_ptr<uml::NamedElement> _inheritedMember : *_inheritedMemberList)
	{
		this->getInheritedMember()->add(std::shared_ptr<uml::NamedElement>(std::dynamic_pointer_cast<uml::NamedElement>(_inheritedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inheritedMember" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InterfaceRealization>> _interfaceRealizationList = obj.getInterfaceRealization();
	for(std::shared_ptr<uml::InterfaceRealization> _interfaceRealization : *_interfaceRealizationList)
	{
		this->getInterfaceRealization()->add(std::shared_ptr<uml::InterfaceRealization>(std::dynamic_pointer_cast<uml::InterfaceRealization>(_interfaceRealization->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_interfaceRealization" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Behavior>> _ownedBehaviorList = obj.getOwnedBehavior();
	for(std::shared_ptr<uml::Behavior> _ownedBehavior : *_ownedBehaviorList)
	{
		this->getOwnedBehavior()->add(std::shared_ptr<uml::Behavior>(std::dynamic_pointer_cast<uml::Behavior>(_ownedBehavior->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedBehavior" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
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

		/*Subset*/
		m_extend->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extend - Subset<uml::Extend, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_extensionPoint->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extensionPoint - Subset<uml::ExtensionPoint, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_include->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_include - Subset<uml::Include, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  UseCaseImpl::copy() const
{
	std::shared_ptr<UseCaseImpl> element(new UseCaseImpl(*this));
	element->setThisUseCasePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> UseCaseImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getUseCase_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::UseCase> > UseCaseImpl::allIncludedUseCases()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UseCaseImpl::binary_associations(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UseCaseImpl::cannot_include_self(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UseCaseImpl::must_have_name(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UseCaseImpl::no_association_to_use_case(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Extend, uml::NamedElement>> UseCaseImpl::getExtend() const
{

    return m_extend;
}


std::shared_ptr<Subset<uml::ExtensionPoint, uml::NamedElement>> UseCaseImpl::getExtensionPoint() const
{

    return m_extensionPoint;
}


std::shared_ptr<Subset<uml::Include, uml::NamedElement>> UseCaseImpl::getInclude() const
{

    return m_include;
}


std::shared_ptr<Bag<uml::Classifier>> UseCaseImpl::getSubject() const
{

    return m_subject;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> UseCaseImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<Union<uml::NamedElement>> UseCaseImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > UseCaseImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> UseCaseImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> UseCaseImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > UseCaseImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> UseCaseImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<UseCase> UseCaseImpl::getThisUseCasePtr() const
{
	return m_thisUseCasePtr.lock();
}
void UseCaseImpl::setThisUseCasePtr(std::weak_ptr<UseCase> thisUseCasePtr)
{
	m_thisUseCasePtr = thisUseCasePtr;
	setThisBehavioredClassifierPtr(thisUseCasePtr);
}
std::shared_ptr<ecore::EObject> UseCaseImpl::eContainer() const
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
Any UseCaseImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::USECASE_ATTRIBUTE_EXTEND:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Extend>::iterator iter = m_extend->begin();
			Bag<uml::Extend>::iterator end = m_extend->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //24941
		}
		case UmlPackage::USECASE_ATTRIBUTE_EXTENSIONPOINT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ExtensionPoint>::iterator iter = m_extensionPoint->begin();
			Bag<uml::ExtensionPoint>::iterator end = m_extensionPoint->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //24942
		}
		case UmlPackage::USECASE_ATTRIBUTE_INCLUDE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Include>::iterator iter = m_include->begin();
			Bag<uml::Include>::iterator end = m_include->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //24943
		}
		case UmlPackage::USECASE_ATTRIBUTE_SUBJECT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Classifier>::iterator iter = m_subject->begin();
			Bag<uml::Classifier>::iterator end = m_subject->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //24944
		}
	}
	return BehavioredClassifierImpl::eGet(featureID, resolve, coreType);
}
bool UseCaseImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::USECASE_ATTRIBUTE_EXTEND:
			return getExtend() != nullptr; //24941
		case UmlPackage::USECASE_ATTRIBUTE_EXTENSIONPOINT:
			return getExtensionPoint() != nullptr; //24942
		case UmlPackage::USECASE_ATTRIBUTE_INCLUDE:
			return getInclude() != nullptr; //24943
		case UmlPackage::USECASE_ATTRIBUTE_SUBJECT:
			return getSubject() != nullptr; //24944
	}
	return BehavioredClassifierImpl::internalEIsSet(featureID);
}
bool UseCaseImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::USECASE_ATTRIBUTE_EXTEND:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Extend>> extendList(new Bag<uml::Extend>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				extendList->add(std::dynamic_pointer_cast<uml::Extend>(*iter));
				iter++;
			}
			
			Bag<uml::Extend>::iterator iterExtend = m_extend->begin();
			Bag<uml::Extend>::iterator endExtend = m_extend->end();
			while (iterExtend != endExtend)
			{
				if (extendList->find(*iterExtend) == -1)
				{
					m_extend->erase(*iterExtend);
				}
				iterExtend++;
			}

			iterExtend = extendList->begin();
			endExtend = extendList->end();
			while (iterExtend != endExtend)
			{
				if (m_extend->find(*iterExtend) == -1)
				{
					m_extend->add(*iterExtend);
				}
				iterExtend++;			
			}
			return true;
		}
		case UmlPackage::USECASE_ATTRIBUTE_EXTENSIONPOINT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ExtensionPoint>> extensionPointList(new Bag<uml::ExtensionPoint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				extensionPointList->add(std::dynamic_pointer_cast<uml::ExtensionPoint>(*iter));
				iter++;
			}
			
			Bag<uml::ExtensionPoint>::iterator iterExtensionPoint = m_extensionPoint->begin();
			Bag<uml::ExtensionPoint>::iterator endExtensionPoint = m_extensionPoint->end();
			while (iterExtensionPoint != endExtensionPoint)
			{
				if (extensionPointList->find(*iterExtensionPoint) == -1)
				{
					m_extensionPoint->erase(*iterExtensionPoint);
				}
				iterExtensionPoint++;
			}

			iterExtensionPoint = extensionPointList->begin();
			endExtensionPoint = extensionPointList->end();
			while (iterExtensionPoint != endExtensionPoint)
			{
				if (m_extensionPoint->find(*iterExtensionPoint) == -1)
				{
					m_extensionPoint->add(*iterExtensionPoint);
				}
				iterExtensionPoint++;			
			}
			return true;
		}
		case UmlPackage::USECASE_ATTRIBUTE_INCLUDE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Include>> includeList(new Bag<uml::Include>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				includeList->add(std::dynamic_pointer_cast<uml::Include>(*iter));
				iter++;
			}
			
			Bag<uml::Include>::iterator iterInclude = m_include->begin();
			Bag<uml::Include>::iterator endInclude = m_include->end();
			while (iterInclude != endInclude)
			{
				if (includeList->find(*iterInclude) == -1)
				{
					m_include->erase(*iterInclude);
				}
				iterInclude++;
			}

			iterInclude = includeList->begin();
			endInclude = includeList->end();
			while (iterInclude != endInclude)
			{
				if (m_include->find(*iterInclude) == -1)
				{
					m_include->add(*iterInclude);
				}
				iterInclude++;			
			}
			return true;
		}
		case UmlPackage::USECASE_ATTRIBUTE_SUBJECT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> subjectList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				subjectList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterSubject = m_subject->begin();
			Bag<uml::Classifier>::iterator endSubject = m_subject->end();
			while (iterSubject != endSubject)
			{
				if (subjectList->find(*iterSubject) == -1)
				{
					m_subject->erase(*iterSubject);
				}
				iterSubject++;
			}

			iterSubject = subjectList->begin();
			endSubject = subjectList->end();
			while (iterSubject != endSubject)
			{
				if (m_subject->find(*iterSubject) == -1)
				{
					m_subject->add(*iterSubject);
				}
				iterSubject++;			
			}
			return true;
		}
	}

	return BehavioredClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void UseCaseImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void UseCaseImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("subject");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("subject")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	BehavioredClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void UseCaseImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("extend") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Extend";
			}
			std::shared_ptr<ecore::EObject> extend = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::EXTEND_ATTRIBUTE_EXTENSION);
			if (extend != nullptr)
			{
				loadHandler->handleChild(extend);
			}
			return;
		}

		if ( nodeName.compare("extensionPoint") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ExtensionPoint";
			}
			std::shared_ptr<ecore::EObject> extensionPoint = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::EXTENSIONPOINT_ATTRIBUTE_USECASE);
			if (extensionPoint != nullptr)
			{
				loadHandler->handleChild(extensionPoint);
			}
			return;
		}

		if ( nodeName.compare("include") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Include";
			}
			std::shared_ptr<ecore::EObject> include = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::INCLUDE_ATTRIBUTE_INCLUDINGCASE);
			if (include != nullptr)
			{
				loadHandler->handleChild(include);
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

	BehavioredClassifierImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void UseCaseImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::USECASE_ATTRIBUTE_SUBJECT:
		{
			std::shared_ptr<Bag<uml::Classifier>> _subject = getSubject();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier> _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_subject->push_back(_r);
				}				
			}
			return;
		}
	}
	BehavioredClassifierImpl::resolveReferences(featureID, references);
}

void UseCaseImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehavioredClassifierImpl::saveContent(saveHandler);
	
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

void UseCaseImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'extend'
		for (std::shared_ptr<uml::Extend> extend : *this->getExtend()) 
		{
			saveHandler->addReference(extend, "extend", extend->eClass() != package->getExtend_Class());
		}

		// Save 'extensionPoint'
		for (std::shared_ptr<uml::ExtensionPoint> extensionPoint : *this->getExtensionPoint()) 
		{
			saveHandler->addReference(extensionPoint, "extensionPoint", extensionPoint->eClass() != package->getExtensionPoint_Class());
		}

		// Save 'include'
		for (std::shared_ptr<uml::Include> include : *this->getInclude()) 
		{
			saveHandler->addReference(include, "include", include->eClass() != package->getInclude_Class());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::Classifier>> subject_list = this->getSubject();
		for (std::shared_ptr<uml::Classifier > object : *subject_list)
		{ 
			saveHandler->addReferences("subject", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

