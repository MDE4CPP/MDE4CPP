#include "FeatureImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
FeatureImpl::FeatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
		/*Union*/
		m_featuringClassifier.reset(new Union<uml::Classifier>());
	
}

FeatureImpl::~FeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Feature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

FeatureImpl::FeatureImpl(const FeatureImpl & obj)
{
	//create copy of all Attributes
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

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

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
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  FeatureImpl::copy() const
{
	return new FeatureImpl(*this);
}

std::shared_ptr<ecore::EClass> FeatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getFeature();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void FeatureImpl::setIsStatic (bool _isStatic)
{
	m_isStatic = _isStatic;
} 

bool FeatureImpl::getIsStatic() const 
{
	return m_isStatic;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************



//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Classifier> > FeatureImpl::getFeaturingClassifier() const
{
	

	return m_featuringClassifier;
}
		std::shared_ptr<Union<uml::Element> > FeatureImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > FeatureImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any FeatureImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //494
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //490
		case UmlPackage::FEATURE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //4913
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //4910
		case UmlPackage::FEATURE_ISSTATIC:
			return getIsStatic(); //4914
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //495
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //496
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //497
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //491
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //492
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //493
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //498
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //4911
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //4912
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //499
	}
	return boost::any();
}
