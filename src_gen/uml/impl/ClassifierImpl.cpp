#include "ClassifierImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >(m_feature));// feature));
	
	
		/*SubsetUnion*/
		m_collaborationUse.reset(new SubsetUnion<uml::CollaborationUse, uml::Element >(m_ownedElement));// ownedElement));
	
	
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >(m_member));// member));
	
	
		m_general.reset(new Bag<uml::Classifier>());
	
	
		/*Subset*/
		m_generalization.reset(new Subset<uml::Generalization, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
		/*Subset*/
		m_inheritedMember.reset(new Subset<uml::NamedElement, uml::NamedElement >(m_member));//(m_member));
	
	
		/*Subset*/
		m_ownedUseCase.reset(new Subset<uml::UseCase, uml::NamedElement >(m_ownedMember));//(m_ownedMember));
	
	
		m_powertypeExtent.reset(new Bag<uml::GeneralizationSet>());
	
	
		/*SubsetUnion*/
		m_redefinedClassifier.reset(new SubsetUnion<uml::Classifier, uml::RedefinableElement >(m_redefinedElement));// redefinedElement));
	
	
	
		/*Subset*/
		m_substitution.reset(new Subset<uml::Substitution, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
		m_useCase.reset(new Bag<uml::UseCase>());
	
	
}

ClassifierImpl::~ClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Classifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ClassifierImpl::ClassifierImpl(const ClassifierImpl & obj)
{
	//create copy of all Attributes
	m_isAbstract = obj.getIsAbstract();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
			std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > >
	 _attribute = obj.getAttribute();
	m_attribute.reset(new 		SubsetUnion<uml::Property, uml::Feature > 
	(*(obj.getAttribute().get())));// this->getAttribute()->insert(this->getAttribute()->end(), _attribute->begin(), _attribute->end());

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

			std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > >
	 _feature = obj.getFeature();
	m_feature.reset(new 		SubsetUnion<uml::Feature, uml::NamedElement > 
	(*(obj.getFeature().get())));// this->getFeature()->insert(this->getFeature()->end(), _feature->begin(), _feature->end());

		std::shared_ptr< Bag<uml::Classifier> >
	 _general = obj.getGeneral();
	m_general.reset(new 	 Bag<uml::Classifier> 
	(*(obj.getGeneral().get())));// this->getGeneral()->insert(this->getGeneral()->end(), _general->begin(), _general->end());

			std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement > >
	 _importedMember = obj.getImportedMember();
	m_importedMember.reset(new 		Subset<uml::PackageableElement, uml::NamedElement > 
	(*(obj.getImportedMember().get())));// this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

			std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement > >
	 _inheritedMember = obj.getInheritedMember();
	m_inheritedMember.reset(new 		Subset<uml::NamedElement, uml::NamedElement > 
	(*(obj.getInheritedMember().get())));// this->getInheritedMember()->insert(this->getInheritedMember()->end(), _inheritedMember->begin(), _inheritedMember->end());

			std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new 		Union<uml::NamedElement> (*(obj.getMember().get())));// this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > >
	 _ownedMember = obj.getOwnedMember();
	m_ownedMember.reset(new 		SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > 
	(*(obj.getOwnedMember().get())));// this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_package  = obj.getPackage();

		std::shared_ptr< Bag<uml::GeneralizationSet> >
	 _powertypeExtent = obj.getPowertypeExtent();
	m_powertypeExtent.reset(new 	 Bag<uml::GeneralizationSet> 
	(*(obj.getPowertypeExtent().get())));// this->getPowertypeExtent()->insert(this->getPowertypeExtent()->end(), _powertypeExtent->begin(), _powertypeExtent->end());

			std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement > >
	 _redefinedClassifier = obj.getRedefinedClassifier();
	m_redefinedClassifier.reset(new 		SubsetUnion<uml::Classifier, uml::RedefinableElement > 
	(*(obj.getRedefinedClassifier().get())));// this->getRedefinedClassifier()->insert(this->getRedefinedClassifier()->end(), _redefinedClassifier->begin(), _redefinedClassifier->end());

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));// this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));// this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

	m_representation  = obj.getRepresentation();

	m_templateParameter  = obj.getTemplateParameter();

		std::shared_ptr< Bag<uml::UseCase> >
	 _useCase = obj.getUseCase();
	m_useCase.reset(new 	 Bag<uml::UseCase> 
	(*(obj.getUseCase().get())));// this->getUseCase()->insert(this->getUseCase()->end(), _useCase->begin(), _useCase->end());


	//clone containt lists
	std::shared_ptr<Bag<uml::CollaborationUse>> _collaborationUseList = obj.getCollaborationUse();
	for(std::shared_ptr<uml::CollaborationUse> _collaborationUse : *_collaborationUseList)
	{
		this->getCollaborationUse()->add(std::shared_ptr<uml::CollaborationUse>(dynamic_cast<uml::CollaborationUse*>(_collaborationUse->copy())));
	}
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
	}
	std::shared_ptr<Bag<uml::Generalization>> _generalizationList = obj.getGeneralization();
	for(std::shared_ptr<uml::Generalization> _generalization : *_generalizationList)
	{
		this->getGeneralization()->add(std::shared_ptr<uml::Generalization>(dynamic_cast<uml::Generalization*>(_generalization->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature.reset(dynamic_cast<uml::TemplateSignature*>(obj.getOwnedTemplateSignature()->copy()));
	}
	std::shared_ptr<Bag<uml::UseCase>> _ownedUseCaseList = obj.getOwnedUseCase();
	for(std::shared_ptr<uml::UseCase> _ownedUseCase : *_ownedUseCaseList)
	{
		this->getOwnedUseCase()->add(std::shared_ptr<uml::UseCase>(dynamic_cast<uml::UseCase*>(_ownedUseCase->copy())));
	}
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
	std::shared_ptr<Bag<uml::Substitution>> _substitutionList = obj.getSubstitution();
	for(std::shared_ptr<uml::Substitution> _substitution : *_substitutionList)
	{
		this->getSubstitution()->add(std::shared_ptr<uml::Substitution>(dynamic_cast<uml::Substitution*>(_substitution->copy())));
	}
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(dynamic_cast<uml::TemplateBinding*>(_templateBinding->copy())));
	}
}

ecore::EObject *  ClassifierImpl::copy() const
{
	return new ClassifierImpl(*this);
}

std::shared_ptr<ecore::EClass> ClassifierImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getClassifier();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ClassifierImpl::setIsAbstract (bool _isAbstract)
{
	m_isAbstract = _isAbstract;
} 

bool ClassifierImpl::getIsAbstract() const 
{
	return m_isAbstract;
}

void ClassifierImpl::setIsFinalSpecialization (bool _isFinalSpecialization)
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
std::shared_ptr<Bag<uml::Property> >
 ClassifierImpl::allAttributes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Feature> >
 ClassifierImpl::allFeatures() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> >
 ClassifierImpl::allParents() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> >
 ClassifierImpl::allRealizedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::StructuralFeature> >
 ClassifierImpl::allSlottableFeatures() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> >
 ClassifierImpl::allUsedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> >
 ClassifierImpl::directlyRealizedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> >
 ClassifierImpl::directlyUsedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Property> >
 ClassifierImpl::getAllAttributes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Operation> >
 ClassifierImpl::getAllOperations() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> >
 ClassifierImpl::getAllUsedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> >
 ClassifierImpl::getGenerals() 
{
	//generated from body annotation
	return parents();
}

std::shared_ptr<Bag<uml::NamedElement> >
 ClassifierImpl::getInheritedMembers() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> 
 ClassifierImpl::getOperation(std::string name,std::shared_ptr<Bag<std::string> >  parameterNames,std::shared_ptr<Bag<uml::Type> >  parameterTypes) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> 
 ClassifierImpl::getOperation(std::string name,std::shared_ptr<Bag<std::string> >  parameterNames,std::shared_ptr<Bag<uml::Type> >  parameterTypes,bool ignoreCase) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Operation> >
 ClassifierImpl::getOperations() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> >
 ClassifierImpl::getUsedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClassifierImpl::hasVisibilityOf(std::shared_ptr<uml::NamedElement>  n) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::NamedElement> >
 ClassifierImpl::inherit(std::shared_ptr<Bag<uml::NamedElement> >  inhs) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::NamedElement> >
 ClassifierImpl::inheritableMembers(std::shared_ptr<uml::Classifier>  c) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClassifierImpl::isSubstitutableFor(std::shared_ptr<uml::Classifier>  contract) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClassifierImpl::maps_to_generalization_set(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClassifierImpl::maySpecializeType(std::shared_ptr<uml::Classifier>  c) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClassifierImpl::no_cycles_in_generalization(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClassifierImpl::non_final_parents(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> >
 ClassifierImpl::parents() 
{
	//generated from body annotation
	std::shared_ptr< Bag<uml::Classifier> > returnList(new Bag<uml::Classifier>());

	for(std::shared_ptr<Generalization> gen : *m_generalization)
	{
		returnList->push_back(gen->getGeneral());
	}

	return returnList;
}

bool
 ClassifierImpl::specialize_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************



		std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element > >
 ClassifierImpl::getCollaborationUse() const
{

    return m_collaborationUse;
}





	std::shared_ptr< Bag<uml::Classifier> >
 ClassifierImpl::getGeneral() const
{

    return m_general;
}


		std::shared_ptr<Subset<uml::Generalization, uml::Element > >
 ClassifierImpl::getGeneralization() const
{

    return m_generalization;
}


		std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement > >
 ClassifierImpl::getInheritedMember() const
{

    return m_inheritedMember;
}


		std::shared_ptr<Subset<uml::UseCase, uml::NamedElement > >
 ClassifierImpl::getOwnedUseCase() const
{

    return m_ownedUseCase;
}


	std::shared_ptr< Bag<uml::GeneralizationSet> >
 ClassifierImpl::getPowertypeExtent() const
{

    return m_powertypeExtent;
}


		std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement > >
 ClassifierImpl::getRedefinedClassifier() const
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

		std::shared_ptr<Subset<uml::Substitution, uml::Element > >
 ClassifierImpl::getSubstitution() const
{

    return m_substitution;
}


	std::shared_ptr< Bag<uml::UseCase> >
 ClassifierImpl::getUseCase() const
{

    return m_useCase;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > >
 ClassifierImpl::getFeature() const
{
	

	return m_feature;
}
		std::shared_ptr<Union<uml::NamedElement> > ClassifierImpl::getMember() const
{
	

	return m_member;
}
std::shared_ptr<uml::Namespace > ClassifierImpl::getNamespace() const
{
	

	return m_namespace;
}
		std::shared_ptr<Union<uml::Element> > ClassifierImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ClassifierImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 ClassifierImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}
		std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > >
 ClassifierImpl::getAttribute() const
{
	

	return m_attribute;
}
std::shared_ptr<uml::Element > ClassifierImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ClassifierImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_ATTRIBUTE:
			return getAttribute(); //525
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //54
		case UmlPackage::CLASSIFIER_COLLABORATIONUSE:
			return getCollaborationUse(); //526
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //50
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //511
		case UmlPackage::CLASSIFIER_FEATURE:
			return getFeature(); //524
		case UmlPackage::CLASSIFIER_GENERAL:
			return getGeneral(); //527
		case UmlPackage::CLASSIFIER_GENERALIZATION:
			return getGeneralization(); //528
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //514
		case UmlPackage::CLASSIFIER_INHERITEDMEMBER:
			return getInheritedMember(); //530
		case UmlPackage::CLASSIFIER_ISABSTRACT:
			return getIsAbstract(); //531
		case UmlPackage::CLASSIFIER_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //532
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //510
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //515
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //55
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //56
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //57
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //51
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //52
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //513
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //510
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //55
		case UmlPackage::CLASSIFIER_OWNEDUSECASE:
			return getOwnedUseCase(); //533
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //53
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //54
		case UmlPackage::TYPE_PACKAGE:
			return getPackage(); //512
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //512
		case UmlPackage::CLASSIFIER_POWERTYPEEXTENT:
			return getPowertypeExtent(); //529
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //58
		case UmlPackage::CLASSIFIER_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //535
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //511
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //512
		case UmlPackage::CLASSIFIER_REPRESENTATION:
			return getRepresentation(); //536
		case UmlPackage::CLASSIFIER_SUBSTITUTION:
			return getSubstitution(); //537
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //54
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //55
		case UmlPackage::CLASSIFIER_USECASE:
			return getUseCase(); //534
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //59
	}
	return boost::any();
}
