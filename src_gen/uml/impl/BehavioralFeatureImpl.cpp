#include "BehavioralFeatureImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
BehavioralFeatureImpl::BehavioralFeatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
		m_method.reset(new Bag<uml::Behavior>());
	
	
		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::Parameter, uml::NamedElement >(m_ownedMember));//(m_ownedMember));
	
	
		/*Subset*/
		m_ownedParameterSet.reset(new Subset<uml::ParameterSet, uml::NamedElement >(m_ownedMember));//(m_ownedMember));
	
	
		m_raisedException.reset(new Bag<uml::Type>());
	
	
}

BehavioralFeatureImpl::~BehavioralFeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BehavioralFeature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

BehavioralFeatureImpl::BehavioralFeatureImpl(const BehavioralFeatureImpl & obj)
{
	//create copy of all Attributes
	m_concurrency = obj.getConcurrency();
	m_isAbstract = obj.getIsAbstract();
	m_isLeaf = obj.getIsLeaf();
	m_isStatic = obj.getIsStatic();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

			std::shared_ptr<Union<uml::Classifier> > _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new 		Union<uml::Classifier> (*(obj.getFeaturingClassifier().get())));// this->getFeaturingClassifier()->insert(this->getFeaturingClassifier()->end(), _featuringClassifier->begin(), _featuringClassifier->end());

			std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement > >
	 _importedMember = obj.getImportedMember();
	m_importedMember.reset(new 		Subset<uml::PackageableElement, uml::NamedElement > 
	(*(obj.getImportedMember().get())));// this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

			std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new 		Union<uml::NamedElement> (*(obj.getMember().get())));// this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());

		std::shared_ptr< Bag<uml::Behavior> >
	 _method = obj.getMethod();
	m_method.reset(new 	 Bag<uml::Behavior> 
	(*(obj.getMethod().get())));// this->getMethod()->insert(this->getMethod()->end(), _method->begin(), _method->end());

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

		std::shared_ptr< Bag<uml::Type> >
	 _raisedException = obj.getRaisedException();
	m_raisedException.reset(new 	 Bag<uml::Type> 
	(*(obj.getRaisedException().get())));// this->getRaisedException()->insert(this->getRaisedException()->end(), _raisedException->begin(), _raisedException->end());

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));// this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));// this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());


	//clone containt lists
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
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<Bag<uml::Parameter>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::Parameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->add(std::shared_ptr<uml::Parameter>(dynamic_cast<uml::Parameter*>(_ownedParameter->copy())));
	}
	std::shared_ptr<Bag<uml::ParameterSet>> _ownedParameterSetList = obj.getOwnedParameterSet();
	for(std::shared_ptr<uml::ParameterSet> _ownedParameterSet : *_ownedParameterSetList)
	{
		this->getOwnedParameterSet()->add(std::shared_ptr<uml::ParameterSet>(dynamic_cast<uml::ParameterSet*>(_ownedParameterSet->copy())));
	}
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
}

ecore::EObject *  BehavioralFeatureImpl::copy() const
{
	return new BehavioralFeatureImpl(*this);
}

std::shared_ptr<ecore::EClass> BehavioralFeatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getBehavioralFeature();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void BehavioralFeatureImpl::setConcurrency (CallConcurrencyKind _concurrency)
{
	m_concurrency = _concurrency;
} 

CallConcurrencyKind BehavioralFeatureImpl::getConcurrency() const 
{
	return m_concurrency;
}

void BehavioralFeatureImpl::setIsAbstract (bool _isAbstract)
{
	m_isAbstract = _isAbstract;
} 

bool BehavioralFeatureImpl::getIsAbstract() const 
{
	return m_isAbstract;
}

//*********************************
// Operations
//*********************************
bool
 BehavioralFeatureImpl::abstract_no_method(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Parameter> 
 BehavioralFeatureImpl::createReturnResult(std::string name,std::shared_ptr<uml::Type>  type) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> >
 BehavioralFeatureImpl::inputParameters() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> >
 BehavioralFeatureImpl::outputParameters() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::Behavior> >
 BehavioralFeatureImpl::getMethod() const
{

    return m_method;
}


		std::shared_ptr<Subset<uml::Parameter, uml::NamedElement > >
 BehavioralFeatureImpl::getOwnedParameter() const
{

    return m_ownedParameter;
}


		std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement > >
 BehavioralFeatureImpl::getOwnedParameterSet() const
{

    return m_ownedParameterSet;
}


	std::shared_ptr< Bag<uml::Type> >
 BehavioralFeatureImpl::getRaisedException() const
{

    return m_raisedException;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 BehavioralFeatureImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}
		std::shared_ptr<Union<uml::NamedElement> > BehavioralFeatureImpl::getMember() const
{
	

	return m_member;
}
		std::shared_ptr<Union<uml::Element> > BehavioralFeatureImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > BehavioralFeatureImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any BehavioralFeatureImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //484
		case UmlPackage::BEHAVIORALFEATURE_CONCURRENCY:
			return getConcurrency(); //4821
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //480
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //4811
		case UmlPackage::FEATURE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //4813
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //4814
		case UmlPackage::BEHAVIORALFEATURE_ISABSTRACT:
			return getIsAbstract(); //4822
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //4810
		case UmlPackage::FEATURE_ISSTATIC:
			return getIsStatic(); //4814
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //4815
		case UmlPackage::BEHAVIORALFEATURE_METHOD:
			return getMethod(); //4823
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //485
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //486
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //487
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //481
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //482
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //4813
		case UmlPackage::BEHAVIORALFEATURE_OWNEDPARAMETER:
			return getOwnedParameter(); //4824
		case UmlPackage::BEHAVIORALFEATURE_OWNEDPARAMETERSET:
			return getOwnedParameterSet(); //4825
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //4810
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //483
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //4812
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //488
		case UmlPackage::BEHAVIORALFEATURE_RAISEDEXCEPTION:
			return getRaisedException(); //4826
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //4811
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //4812
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //489
	}
	return boost::any();
}
