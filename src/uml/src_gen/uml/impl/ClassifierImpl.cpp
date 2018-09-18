#include "uml/impl/ClassifierImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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

#include "uml/Interface.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Operation.hpp"

#include "uml/Package.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Property.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuralFeature.hpp"

#include "uml/Substitution.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/TemplateableElement.hpp"

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
ClassifierImpl::ClassifierImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_collaborationUse.reset(new SubsetUnion<uml::CollaborationUse, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_collaborationUse - SubsetUnion<uml::CollaborationUse, uml::Element >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
	
	

		m_general.reset(new Bag<uml::Classifier>());
	
	

		/*Subset*/
		m_generalization.reset(new Subset<uml::Generalization, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_generalization - Subset<uml::Generalization, uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_inheritedMember.reset(new Subset<uml::NamedElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inheritedMember - Subset<uml::NamedElement, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedUseCase.reset(new Subset<uml::UseCase, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedUseCase - Subset<uml::UseCase, uml::NamedElement >()" << std::endl;
		#endif
	
	

		m_powertypeExtent.reset(new Bag<uml::GeneralizationSet>());
	
	

		/*SubsetUnion*/
		m_redefinedClassifier.reset(new SubsetUnion<uml::Classifier, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_redefinedClassifier - SubsetUnion<uml::Classifier, uml::RedefinableElement >()" << std::endl;
		#endif
	
	

	

		/*Subset*/
		m_substitution.reset(new Subset<uml::Substitution, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_substitution - Subset<uml::Substitution, uml::Element >()" << std::endl;
		#endif
	
	

		m_useCase.reset(new Bag<uml::UseCase>());
	
	

	//Init references
		/*SubsetUnion*/
		m_attribute->initSubsetUnion(m_feature);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(m_feature)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_collaborationUse->initSubsetUnion(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_collaborationUse - SubsetUnion<uml::CollaborationUse, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_feature->initSubsetUnion(m_member);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(m_member)" << std::endl;
		#endif
	
	

	
	

		/*Subset*/
		m_generalization->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalization - Subset<uml::Generalization, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_inheritedMember->initSubset(m_member);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inheritedMember - Subset<uml::NamedElement, uml::NamedElement >(m_member)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedUseCase->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedUseCase - Subset<uml::UseCase, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

	
	

		/*SubsetUnion*/
		m_redefinedClassifier->initSubsetUnion(m_redefinedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_redefinedClassifier - SubsetUnion<uml::Classifier, uml::RedefinableElement >(m_redefinedElement)" << std::endl;
		#endif
	
	

	

		/*Subset*/
		m_substitution->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_substitution - Subset<uml::Substitution, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
	
}

ClassifierImpl::~ClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Classifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ClassifierImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::Element > par_owner)
			:ClassifierImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
			:ClassifierImpl()
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
			ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ClassifierImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}





//Additional constructor for the containments back reference






ClassifierImpl::ClassifierImpl(const ClassifierImpl & obj):ClassifierImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Classifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
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

		/*SubsetUnion*/
		m_collaborationUse->initSubsetUnion(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_collaborationUse - SubsetUnion<uml::CollaborationUse, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_generalization->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalization - Subset<uml::Generalization, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedUseCase->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedUseCase - Subset<uml::UseCase, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_substitution->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_substitution - Subset<uml::Substitution, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ClassifierImpl::copy() const
{
	std::shared_ptr<ClassifierImpl> element(new ClassifierImpl(*this));
	element->setThisClassifierPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ClassifierImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getClassifier_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ClassifierImpl::setIsAbstract(bool _isAbstract)
{
	m_isAbstract = _isAbstract;
} 

bool ClassifierImpl::getIsAbstract() const 
{
	return m_isAbstract;
}

void ClassifierImpl::setIsFinalSpecialization(bool _isFinalSpecialization)
{
	m_isFinalSpecialization = _isFinalSpecialization;
} 

bool ClassifierImpl::getIsFinalSpecialization() const 
{
	return m_isFinalSpecialization;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Property> > ClassifierImpl::allAttributes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Feature> > ClassifierImpl::allFeatures()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> > ClassifierImpl::allParents()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::allRealizedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::StructuralFeature> > ClassifierImpl::allSlottableFeatures()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::allUsedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::directlyRealizedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::directlyUsedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Property> > ClassifierImpl::getAllAttributes()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<Bag<uml::Property>> eAllAttributes(new Bag<uml::Property>());

    std::shared_ptr<Bag<uml::Property>> attributeList = this->getAttribute();
    eAllAttributes->insert(eAllAttributes->end(), attributeList->begin(), attributeList->end());

    std::shared_ptr<Bag<Classifier> > classList = this->getGenerals();
    for (std::shared_ptr<Classifier> c : *classList)
    {
        std::shared_ptr<Bag<Property> > attributeList = c->getAllAttributes();
        eAllAttributes->insert(eAllAttributes->end(), attributeList->begin(), attributeList->end());
    }
    return eAllAttributes;
	//end of body
}

std::shared_ptr<Bag<uml::Operation> > ClassifierImpl::getAllOperations()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::getAllUsedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> > ClassifierImpl::getGenerals()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return parents();
	//end of body
}

std::shared_ptr<Bag<uml::NamedElement> > ClassifierImpl::getInheritedMembers()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> ClassifierImpl::getOperation(std::string name,std::shared_ptr<Bag<std::string> >  parameterNames,std::shared_ptr<Bag<uml::Type> >  parameterTypes)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> ClassifierImpl::getOperation(std::string name,std::shared_ptr<Bag<std::string> >  parameterNames,std::shared_ptr<Bag<uml::Type> >  parameterTypes,bool ignoreCase)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Operation> > ClassifierImpl::getOperations()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::getUsedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::hasVisibilityOf(std::shared_ptr<uml::NamedElement>  n)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::NamedElement> > ClassifierImpl::inherit(std::shared_ptr<Bag<uml::NamedElement> >  inhs)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::NamedElement> > ClassifierImpl::inheritableMembers(std::shared_ptr<uml::Classifier>  c)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::isSubstitutableFor(std::shared_ptr<uml::Classifier>  contract)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::maps_to_generalization_set(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::maySpecializeType(std::shared_ptr<uml::Classifier>  c)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::no_cycles_in_generalization(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::non_final_parents(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> > ClassifierImpl::parents()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr< Bag<uml::Classifier> > returnList(new Bag<uml::Classifier>());

	for(std::shared_ptr<Generalization> gen : *m_generalization)
	{
		returnList->push_back(gen->getGeneral());
	}

	return returnList;
	//end of body
}

bool ClassifierImpl::specialize_type(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************



std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element>> ClassifierImpl::getCollaborationUse() const
{

    return m_collaborationUse;
}





std::shared_ptr<Bag<uml::Classifier>> ClassifierImpl::getGeneral() const
{

    return m_general;
}


std::shared_ptr<Subset<uml::Generalization, uml::Element>> ClassifierImpl::getGeneralization() const
{

    return m_generalization;
}


std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement>> ClassifierImpl::getInheritedMember() const
{

    return m_inheritedMember;
}


std::shared_ptr<Subset<uml::UseCase, uml::NamedElement>> ClassifierImpl::getOwnedUseCase() const
{

    return m_ownedUseCase;
}


std::shared_ptr<Bag<uml::GeneralizationSet>> ClassifierImpl::getPowertypeExtent() const
{

    return m_powertypeExtent;
}


std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement>> ClassifierImpl::getRedefinedClassifier() const
{

    return m_redefinedClassifier;
}


std::shared_ptr<uml::CollaborationUse > ClassifierImpl::getRepresentation() const
{

    return m_representation;
}
void ClassifierImpl::setRepresentation(std::shared_ptr<uml::CollaborationUse> _representation)
{
    m_representation = _representation;
}

std::shared_ptr<Subset<uml::Substitution, uml::Element>> ClassifierImpl::getSubstitution() const
{

    return m_substitution;
}


std::shared_ptr<Bag<uml::UseCase>> ClassifierImpl::getUseCase() const
{

    return m_useCase;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> ClassifierImpl::getAttribute() const
{
	return m_attribute;
}
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> ClassifierImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<Union<uml::NamedElement>> ClassifierImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > ClassifierImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> ClassifierImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ClassifierImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > ClassifierImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> ClassifierImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<Classifier> ClassifierImpl::getThisClassifierPtr() const
{
	return m_thisClassifierPtr.lock();
}
void ClassifierImpl::setThisClassifierPtr(std::weak_ptr<Classifier> thisClassifierPtr)
{
	m_thisClassifierPtr = thisClassifierPtr;
	setThisNamespacePtr(thisClassifierPtr);
	setThisRedefinableElementPtr(thisClassifierPtr);
	setThisTemplateableElementPtr(thisClassifierPtr);
	setThisTypePtr(thisClassifierPtr);
}
std::shared_ptr<ecore::EObject> ClassifierImpl::eContainer() const
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
Any ClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_EREFERENCE_ATTRIBUTE:
			return eAny(getAttribute()); //526
		case UmlPackage::CLASSIFIER_EREFERENCE_COLLABORATIONUSE:
			return eAny(getCollaborationUse()); //527
		case UmlPackage::CLASSIFIER_EREFERENCE_FEATURE:
			return eAny(getFeature()); //525
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERAL:
			return eAny(getGeneral()); //528
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERALIZATION:
			return eAny(getGeneralization()); //529
		case UmlPackage::CLASSIFIER_EREFERENCE_INHERITEDMEMBER:
			return eAny(getInheritedMember()); //531
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISABSTRACT:
			return eAny(getIsAbstract()); //532
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION:
			return eAny(getIsFinalSpecialization()); //533
		case UmlPackage::CLASSIFIER_EREFERENCE_OWNEDUSECASE:
			return eAny(getOwnedUseCase()); //534
		case UmlPackage::CLASSIFIER_EREFERENCE_POWERTYPEEXTENT:
			return eAny(getPowertypeExtent()); //530
		case UmlPackage::CLASSIFIER_EREFERENCE_REDEFINEDCLASSIFIER:
			return eAny(getRedefinedClassifier()); //536
		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
			return eAny(getRepresentation()); //537
		case UmlPackage::CLASSIFIER_EREFERENCE_SUBSTITUTION:
			return eAny(getSubstitution()); //538
		case UmlPackage::CLASSIFIER_EREFERENCE_USECASE:
			return eAny(getUseCase()); //535
	}
	Any result;
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = RedefinableElementImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = TemplateableElementImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = TypeImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool ClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_EREFERENCE_ATTRIBUTE:
			return getAttribute() != nullptr; //526
		case UmlPackage::CLASSIFIER_EREFERENCE_COLLABORATIONUSE:
			return getCollaborationUse() != nullptr; //527
		case UmlPackage::CLASSIFIER_EREFERENCE_FEATURE:
			return getFeature() != nullptr; //525
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERAL:
			return getGeneral() != nullptr; //528
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERALIZATION:
			return getGeneralization() != nullptr; //529
		case UmlPackage::CLASSIFIER_EREFERENCE_INHERITEDMEMBER:
			return getInheritedMember() != nullptr; //531
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISABSTRACT:
			return getIsAbstract() != false; //532
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization() != false; //533
		case UmlPackage::CLASSIFIER_EREFERENCE_OWNEDUSECASE:
			return getOwnedUseCase() != nullptr; //534
		case UmlPackage::CLASSIFIER_EREFERENCE_POWERTYPEEXTENT:
			return getPowertypeExtent() != nullptr; //530
		case UmlPackage::CLASSIFIER_EREFERENCE_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier() != nullptr; //536
		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
			return getRepresentation() != nullptr; //537
		case UmlPackage::CLASSIFIER_EREFERENCE_SUBSTITUTION:
			return getSubstitution() != nullptr; //538
		case UmlPackage::CLASSIFIER_EREFERENCE_USECASE:
			return getUseCase() != nullptr; //535
	}
	bool result = false;
	result = NamespaceImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TypeImpl::internalEIsSet(featureID);
	return result;
}
bool ClassifierImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISABSTRACT:
		{
			// BOOST CAST
			bool _isAbstract = newValue->get<bool>();
			setIsAbstract(_isAbstract); //532
			return true;
		}
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION:
		{
			// BOOST CAST
			bool _isFinalSpecialization = newValue->get<bool>();
			setIsFinalSpecialization(_isFinalSpecialization); //533
			return true;
		}
		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::CollaborationUse> _representation = newValue->get<std::shared_ptr<uml::CollaborationUse>>();
			setRepresentation(_representation); //537
			return true;
		}
	}

	bool result = false;
	result = NamespaceImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TypeImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ClassifierImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClassifierImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isAbstract");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsAbstract(value);
		}

		iter = attr_list.find("isFinalSpecialization");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsFinalSpecialization(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("general");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("general")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("powertypeExtent");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("powertypeExtent")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("representation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("representation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("useCase");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("useCase")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamespaceImpl::loadAttributes(loadHandler, attr_list);
	RedefinableElementImpl::loadAttributes(loadHandler, attr_list);
	TemplateableElementImpl::loadAttributes(loadHandler, attr_list);
	TypeImpl::loadAttributes(loadHandler, attr_list);
}

void ClassifierImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("collaborationUse") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "CollaborationUse";
			}
			std::shared_ptr<uml::CollaborationUse> collaborationUse = std::dynamic_pointer_cast<uml::CollaborationUse>(modelFactory->create(typeName));
			if (collaborationUse != nullptr)
			{
				std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element>> list_collaborationUse = this->getCollaborationUse();
				list_collaborationUse->push_back(collaborationUse);
				loadHandler->handleChild(collaborationUse);
			}
			return;
		}

		if ( nodeName.compare("generalization") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Generalization";
			}
			std::shared_ptr<ecore::EObject> generalization = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::GENERALIZATION_EREFERENCE_SPECIFIC);
			if (generalization != nullptr)
			{
				loadHandler->handleChild(generalization);
			}
			return;
		}

		if ( nodeName.compare("ownedUseCase") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "UseCase";
			}
			std::shared_ptr<uml::UseCase> ownedUseCase = std::dynamic_pointer_cast<uml::UseCase>(modelFactory->create(typeName));
			if (ownedUseCase != nullptr)
			{
				std::shared_ptr<Subset<uml::UseCase, uml::NamedElement>> list_ownedUseCase = this->getOwnedUseCase();
				list_ownedUseCase->push_back(ownedUseCase);
				loadHandler->handleChild(ownedUseCase);
			}
			return;
		}

		if ( nodeName.compare("substitution") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Substitution";
			}
			std::shared_ptr<ecore::EObject> substitution = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::SUBSTITUTION_EREFERENCE_SUBSTITUTINGCLASSIFIER);
			if (substitution != nullptr)
			{
				loadHandler->handleChild(substitution);
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

	NamespaceImpl::loadNode(nodeName, loadHandler, modelFactory);
	RedefinableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
	TemplateableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
	TypeImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ClassifierImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERAL:
		{
			std::shared_ptr<Bag<uml::Classifier>> _general = getGeneral();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier> _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_general->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::CLASSIFIER_EREFERENCE_POWERTYPEEXTENT:
		{
			std::shared_ptr<Bag<uml::GeneralizationSet>> _powertypeExtent = getPowertypeExtent();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::GeneralizationSet> _r = std::dynamic_pointer_cast<uml::GeneralizationSet>(ref);
				if (_r != nullptr)
				{
					_powertypeExtent->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::CLASSIFIER_EREFERENCE_REDEFINEDCLASSIFIER:
		{
			std::shared_ptr<Bag<uml::Classifier>> _redefinedClassifier = getRedefinedClassifier();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier> _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_redefinedClassifier->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CollaborationUse> _representation = std::dynamic_pointer_cast<uml::CollaborationUse>( references.front() );
				setRepresentation(_representation);
			}
			
			return;
		}

		case UmlPackage::CLASSIFIER_EREFERENCE_USECASE:
		{
			std::shared_ptr<Bag<uml::UseCase>> _useCase = getUseCase();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::UseCase> _r = std::dynamic_pointer_cast<uml::UseCase>(ref);
				if (_r != nullptr)
				{
					_useCase->push_back(_r);
				}				
			}
			return;
		}
	}
	NamespaceImpl::resolveReferences(featureID, references);
	RedefinableElementImpl::resolveReferences(featureID, references);
	TemplateableElementImpl::resolveReferences(featureID, references);
	TypeImpl::resolveReferences(featureID, references);
}

void ClassifierImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void ClassifierImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'generalization'
		for (std::shared_ptr<uml::Generalization> generalization : *this->getGeneralization()) 
		{
			saveHandler->addReference(generalization, "generalization", generalization->eClass() != package->getGeneralization_EClass());
		}

		// Save 'ownedUseCase'
		for (std::shared_ptr<uml::UseCase> ownedUseCase : *this->getOwnedUseCase()) 
		{
			saveHandler->addReference(ownedUseCase, "ownedUseCase", ownedUseCase->eClass() != package->getUseCase_EClass());
		}

		// Save 'substitution'
		for (std::shared_ptr<uml::Substitution> substitution : *this->getSubstitution()) 
		{
			saveHandler->addReference(substitution, "substitution", substitution->eClass() != package->getSubstitution_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getClassifier_EAttribute_isAbstract()) )
		{
			saveHandler->addAttribute("isAbstract", this->getIsAbstract());
		}

		if ( this->eIsSet(package->getClassifier_EAttribute_isFinalSpecialization()) )
		{
			saveHandler->addAttribute("isFinalSpecialization", this->getIsFinalSpecialization());
		}

		// Add references
		std::shared_ptr<Bag<uml::Classifier>> general_list = this->getGeneral();
		for (std::shared_ptr<uml::Classifier > object : *general_list)
		{ 
			saveHandler->addReferences("general", object);
		}
		std::shared_ptr<Bag<uml::GeneralizationSet>> powertypeExtent_list = this->getPowertypeExtent();
		for (std::shared_ptr<uml::GeneralizationSet > object : *powertypeExtent_list)
		{ 
			saveHandler->addReferences("powertypeExtent", object);
		}
		std::shared_ptr<Bag<uml::Classifier>> redefinedClassifier_list = this->getRedefinedClassifier();
		for (std::shared_ptr<uml::Classifier > object : *redefinedClassifier_list)
		{ 
			saveHandler->addReferences("redefinedClassifier", object);
		}
		saveHandler->addReference("representation", this->getRepresentation());
		std::shared_ptr<Bag<uml::UseCase>> useCase_list = this->getUseCase();
		for (std::shared_ptr<uml::UseCase > object : *useCase_list)
		{ 
			saveHandler->addReferences("useCase", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'collaborationUse'
		std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element>> list_collaborationUse = this->getCollaborationUse();
		for (std::shared_ptr<uml::CollaborationUse> collaborationUse : *list_collaborationUse) 
		{
			saveHandler->addReference(collaborationUse, "collaborationUse", collaborationUse->eClass() != package->getCollaborationUse_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

