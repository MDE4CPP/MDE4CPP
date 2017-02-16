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
	// Reference Members
	//*********************************
	if( m_featuringClassifier == nullptr)
	{
		m_featuringClassifier = new std::vector<uml::Classifier * >();
	}
}

FeatureImpl::~FeatureImpl()
{
	if(m_featuringClassifier!=nullptr)
	{
		delete(m_featuringClassifier);
	 	m_featuringClassifier = nullptr;
	}
	
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
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::Classifier * > *  _featuringClassifier = obj.getFeaturingClassifier();
	this->getFeaturingClassifier()->insert(this->getFeaturingClassifier()->end(), _featuringClassifier->begin(), _featuringClassifier->end());
	delete(_featuringClassifier);

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  FeatureImpl::copy() const
{
	return new FeatureImpl(*this);
}

ecore::EClass* FeatureImpl::eStaticClass() const
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
std::vector<uml::Element * > *  FeatureImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
std::vector<uml::Classifier * > *  FeatureImpl::getFeaturingClassifier() const
{
	std::vector<uml::Classifier * > *  _featuringClassifier =  new std::vector<uml::Classifier * >() ;
	

	return _featuringClassifier;
}
uml::Element *  FeatureImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
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
