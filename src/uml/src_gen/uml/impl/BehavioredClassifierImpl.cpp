#include "uml/impl/BehavioredClassifierImpl.hpp"

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

#include "uml/Interface.hpp"

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
BehavioredClassifierImpl::BehavioredClassifierImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		/*Subset*/
		m_interfaceRealization.reset(new Subset<uml::InterfaceRealization, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_interfaceRealization - Subset<uml::InterfaceRealization, uml::Element >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedBehavior.reset(new SubsetUnion<uml::Behavior, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedBehavior - SubsetUnion<uml::Behavior, uml::NamedElement >()" << std::endl;
		#endif
	
	

	//Init references
	

		/*Subset*/
		m_interfaceRealization->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_interfaceRealization - Subset<uml::InterfaceRealization, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedBehavior->initSubsetUnion(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedBehavior - SubsetUnion<uml::Behavior, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

BehavioredClassifierImpl::~BehavioredClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BehavioredClassifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			BehavioredClassifierImpl::BehavioredClassifierImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:BehavioredClassifierImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			BehavioredClassifierImpl::BehavioredClassifierImpl(std::weak_ptr<uml::Element > par_owner)
			:BehavioredClassifierImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
BehavioredClassifierImpl::BehavioredClassifierImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
:BehavioredClassifierImpl()
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
			BehavioredClassifierImpl::BehavioredClassifierImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:BehavioredClassifierImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}





//Additional constructor for the containments back reference






BehavioredClassifierImpl::BehavioredClassifierImpl(const BehavioredClassifierImpl & obj):BehavioredClassifierImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BehavioredClassifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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
		m_interfaceRealization->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_interfaceRealization - Subset<uml::InterfaceRealization, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedBehavior->initSubsetUnion(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedBehavior - SubsetUnion<uml::Behavior, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  BehavioredClassifierImpl::copy() const
{
	std::shared_ptr<BehavioredClassifierImpl> element(new BehavioredClassifierImpl(*this));
	element->setThisBehavioredClassifierPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> BehavioredClassifierImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getBehavioredClassifier_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool BehavioredClassifierImpl::class_behavior(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > BehavioredClassifierImpl::getAllImplementedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > BehavioredClassifierImpl::getImplementedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Behavior > BehavioredClassifierImpl::getClassifierBehavior() const
{

    return m_classifierBehavior;
}
void BehavioredClassifierImpl::setClassifierBehavior(std::shared_ptr<uml::Behavior> _classifierBehavior)
{
    m_classifierBehavior = _classifierBehavior;
}

std::shared_ptr<Subset<uml::InterfaceRealization, uml::Element>> BehavioredClassifierImpl::getInterfaceRealization() const
{

    return m_interfaceRealization;
}


std::shared_ptr<SubsetUnion<uml::Behavior, uml::NamedElement>> BehavioredClassifierImpl::getOwnedBehavior() const
{

    return m_ownedBehavior;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> BehavioredClassifierImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<Union<uml::NamedElement>> BehavioredClassifierImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > BehavioredClassifierImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> BehavioredClassifierImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> BehavioredClassifierImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > BehavioredClassifierImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> BehavioredClassifierImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<BehavioredClassifier> BehavioredClassifierImpl::getThisBehavioredClassifierPtr() const
{
	return m_thisBehavioredClassifierPtr.lock();
}
void BehavioredClassifierImpl::setThisBehavioredClassifierPtr(std::weak_ptr<BehavioredClassifier> thisBehavioredClassifierPtr)
{
	m_thisBehavioredClassifierPtr = thisBehavioredClassifierPtr;
	setThisClassifierPtr(thisBehavioredClassifierPtr);
}
std::shared_ptr<ecore::EObject> BehavioredClassifierImpl::eContainer() const
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
Any BehavioredClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_CLASSIFIERBEHAVIOR:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getClassifierBehavior())); //2738
		case UmlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_INTERFACEREALIZATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InterfaceRealization>::iterator iter = m_interfaceRealization->begin();
			Bag<uml::InterfaceRealization>::iterator end = m_interfaceRealization->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2739
		}
		case UmlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_OWNEDBEHAVIOR:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Behavior>::iterator iter = m_ownedBehavior->begin();
			Bag<uml::Behavior>::iterator end = m_ownedBehavior->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2740
		}
	}
	return ClassifierImpl::eGet(featureID, resolve, coreType);
}
bool BehavioredClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_CLASSIFIERBEHAVIOR:
			return getClassifierBehavior() != nullptr; //2738
		case UmlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_INTERFACEREALIZATION:
			return getInterfaceRealization() != nullptr; //2739
		case UmlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_OWNEDBEHAVIOR:
			return getOwnedBehavior() != nullptr; //2740
	}
	return ClassifierImpl::internalEIsSet(featureID);
}
bool BehavioredClassifierImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_CLASSIFIERBEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _classifierBehavior = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setClassifierBehavior(_classifierBehavior); //2738
			return true;
		}
		case UmlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_INTERFACEREALIZATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InterfaceRealization>> interfaceRealizationList(new Bag<uml::InterfaceRealization>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				interfaceRealizationList->add(std::dynamic_pointer_cast<uml::InterfaceRealization>(*iter));
				iter++;
			}
			
			Bag<uml::InterfaceRealization>::iterator iterInterfaceRealization = m_interfaceRealization->begin();
			Bag<uml::InterfaceRealization>::iterator endInterfaceRealization = m_interfaceRealization->end();
			while (iterInterfaceRealization != endInterfaceRealization)
			{
				if (interfaceRealizationList->find(*iterInterfaceRealization) == -1)
				{
					m_interfaceRealization->erase(*iterInterfaceRealization);
				}
				iterInterfaceRealization++;
			}

			iterInterfaceRealization = interfaceRealizationList->begin();
			endInterfaceRealization = interfaceRealizationList->end();
			while (iterInterfaceRealization != endInterfaceRealization)
			{
				if (m_interfaceRealization->find(*iterInterfaceRealization) == -1)
				{
					m_interfaceRealization->add(*iterInterfaceRealization);
				}
				iterInterfaceRealization++;			
			}
			return true;
		}
		case UmlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_OWNEDBEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Behavior>> ownedBehaviorList(new Bag<uml::Behavior>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedBehaviorList->add(std::dynamic_pointer_cast<uml::Behavior>(*iter));
				iter++;
			}
			
			Bag<uml::Behavior>::iterator iterOwnedBehavior = m_ownedBehavior->begin();
			Bag<uml::Behavior>::iterator endOwnedBehavior = m_ownedBehavior->end();
			while (iterOwnedBehavior != endOwnedBehavior)
			{
				if (ownedBehaviorList->find(*iterOwnedBehavior) == -1)
				{
					m_ownedBehavior->erase(*iterOwnedBehavior);
				}
				iterOwnedBehavior++;
			}

			iterOwnedBehavior = ownedBehaviorList->begin();
			endOwnedBehavior = ownedBehaviorList->end();
			while (iterOwnedBehavior != endOwnedBehavior)
			{
				if (m_ownedBehavior->find(*iterOwnedBehavior) == -1)
				{
					m_ownedBehavior->add(*iterOwnedBehavior);
				}
				iterOwnedBehavior++;			
			}
			return true;
		}
	}

	return ClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void BehavioredClassifierImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void BehavioredClassifierImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("classifierBehavior");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("classifierBehavior")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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
}

void BehavioredClassifierImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("interfaceRealization") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InterfaceRealization";
			}
			std::shared_ptr<ecore::EObject> interfaceRealization = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER);
			if (interfaceRealization != nullptr)
			{
				loadHandler->handleChild(interfaceRealization);
			}
			return;
		}

		if ( nodeName.compare("ownedBehavior") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> ownedBehavior = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER);
			if (ownedBehavior != nullptr)
			{
				loadHandler->handleChild(ownedBehavior);
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
}

void BehavioredClassifierImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_CLASSIFIERBEHAVIOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _classifierBehavior = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setClassifierBehavior(_classifierBehavior);
			}
			
			return;
		}
	}
	ClassifierImpl::resolveReferences(featureID, references);
}

void BehavioredClassifierImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void BehavioredClassifierImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'interfaceRealization'
		for (std::shared_ptr<uml::InterfaceRealization> interfaceRealization : *this->getInterfaceRealization()) 
		{
			saveHandler->addReference(interfaceRealization, "interfaceRealization", interfaceRealization->eClass() != package->getInterfaceRealization_Class());
		}
	

		// Add references
		saveHandler->addReference("classifierBehavior", this->getClassifierBehavior());


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'ownedBehavior'
		std::shared_ptr<SubsetUnion<uml::Behavior, uml::NamedElement>> list_ownedBehavior = this->getOwnedBehavior();
		for (std::shared_ptr<uml::Behavior> ownedBehavior : *list_ownedBehavior) 
		{
			saveHandler->addReference(ownedBehavior, "ownedBehavior", ownedBehavior->eClass() != package->getBehavior_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

