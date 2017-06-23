#include "StructuralFeatureImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StructuralFeatureImpl::StructuralFeatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************

}

StructuralFeatureImpl::~StructuralFeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuralFeature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

StructuralFeatureImpl::StructuralFeatureImpl(const StructuralFeatureImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isOrdered = obj.getIsOrdered();
	m_isReadOnly = obj.getIsReadOnly();
	m_isStatic = obj.getIsStatic();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_upper = obj.getUpper();
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

	m_type  = obj.getType();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getLowerValue()->copy()));
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
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getUpperValue()->copy()));
	}
}

ecore::EObject *  StructuralFeatureImpl::copy() const
{
	return new StructuralFeatureImpl(*this);
}

std::shared_ptr<ecore::EClass> StructuralFeatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getStructuralFeature();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void StructuralFeatureImpl::setIsReadOnly (bool _isReadOnly)
{
	m_isReadOnly = _isReadOnly;
} 

bool StructuralFeatureImpl::getIsReadOnly() const 
{
	return m_isReadOnly;
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
		std::shared_ptr<Union<uml::Element> > StructuralFeatureImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > StructuralFeatureImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any StructuralFeatureImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //734
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //730
		case UmlPackage::FEATURE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //7313
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //7310
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //734
		case UmlPackage::STRUCTURALFEATURE_ISREADONLY:
			return getIsReadOnly(); //7322
		case UmlPackage::FEATURE_ISSTATIC:
			return getIsStatic(); //7314
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //735
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //736
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //737
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //735
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //736
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //737
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //731
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //732
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //733
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //738
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //7311
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //7312
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //7310
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //738
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //739
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //739
	}
	return boost::any();
}
