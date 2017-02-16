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
	// Reference Members
	//*********************************
	if( m_method == nullptr)
	{
		m_method = new std::vector<uml::Behavior * >();
	}
	if( m_ownedParameter == nullptr)
	{
		m_ownedParameter = new std::vector<uml::Parameter * >();
	}
	if( m_ownedParameterSet == nullptr)
	{
		m_ownedParameterSet = new std::vector<uml::ParameterSet * >();
	}
	if( m_raisedException == nullptr)
	{
		m_raisedException = new std::vector<uml::Type * >();
	}
}

BehavioralFeatureImpl::~BehavioralFeatureImpl()
{
	if(m_method!=nullptr)
	{
		delete(m_method);
	 	m_method = nullptr;
	}
	if(m_ownedParameter!=nullptr)
	{
		for(auto c :*m_ownedParameter)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_ownedParameterSet!=nullptr)
	{
		for(auto c :*m_ownedParameterSet)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_raisedException!=nullptr)
	{
		delete(m_raisedException);
	 	m_raisedException = nullptr;
	}
	
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
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::Classifier * > *  _featuringClassifier = obj.getFeaturingClassifier();
	this->getFeaturingClassifier()->insert(this->getFeaturingClassifier()->end(), _featuringClassifier->begin(), _featuringClassifier->end());
	delete(_featuringClassifier);

	std::vector<uml::PackageableElement * > *  _importedMember = obj.getImportedMember();
	this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	std::vector<uml::NamedElement * > *  _member = obj.getMember();
	this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());
	delete(_member);

	std::vector<uml::Behavior * > *  _method = obj.getMethod();
	this->getMethod()->insert(this->getMethod()->end(), _method->begin(), _method->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	std::vector<uml::NamedElement * > *  _ownedMember = obj.getOwnedMember();
	this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());
	delete(_ownedMember);

	m_owner  = obj.getOwner();

	std::vector<uml::Type * > *  _raisedException = obj.getRaisedException();
	this->getRaisedException()->insert(this->getRaisedException()->end(), _raisedException->begin(), _raisedException->end());

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
	for(uml::ElementImport * 	_elementImport : *obj.getElementImport())
	{
		this->getElementImport()->push_back(dynamic_cast<uml::ElementImport * >(_elementImport->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::Parameter * 	_ownedParameter : *obj.getOwnedParameter())
	{
		this->getOwnedParameter()->push_back(dynamic_cast<uml::Parameter * >(_ownedParameter->copy()));
	}
	for(uml::ParameterSet * 	_ownedParameterSet : *obj.getOwnedParameterSet())
	{
		this->getOwnedParameterSet()->push_back(dynamic_cast<uml::ParameterSet * >(_ownedParameterSet->copy()));
	}
	for(uml::Constraint * 	_ownedRule : *obj.getOwnedRule())
	{
		this->getOwnedRule()->push_back(dynamic_cast<uml::Constraint * >(_ownedRule->copy()));
	}
	for(uml::PackageImport * 	_packageImport : *obj.getPackageImport())
	{
		this->getPackageImport()->push_back(dynamic_cast<uml::PackageImport * >(_packageImport->copy()));
	}
}

ecore::EObject *  BehavioralFeatureImpl::copy() const
{
	return new BehavioralFeatureImpl(*this);
}

ecore::EClass* BehavioralFeatureImpl::eStaticClass() const
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
bool BehavioralFeatureImpl::abstract_no_method(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Parameter *  BehavioralFeatureImpl::createReturnResult(std::string name,uml::Type *  type) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Parameter * > *  BehavioralFeatureImpl::inputParameters() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Parameter * > *  BehavioralFeatureImpl::outputParameters() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Behavior * > *  BehavioralFeatureImpl::getMethod() const
{
	
	return m_method;
}


std::vector<uml::Parameter * > *  BehavioralFeatureImpl::getOwnedParameter() const
{
	
	return m_ownedParameter;
}


std::vector<uml::ParameterSet * > *  BehavioralFeatureImpl::getOwnedParameterSet() const
{
	
	return m_ownedParameterSet;
}


std::vector<uml::Type * > *  BehavioralFeatureImpl::getRaisedException() const
{
	
	return m_raisedException;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::NamedElement * > *  BehavioralFeatureImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
std::vector<uml::Element * > *  BehavioralFeatureImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedMember = (std::vector<uml::Element * > * ) getOwnedMember();
	_ownedElement->insert(_ownedElement->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);
	std::vector<uml::Element * > *  packageImport = (std::vector<uml::Element * > * ) getPackageImport();
	_ownedElement->insert(_ownedElement->end(), packageImport->begin(), packageImport->end());


	return _ownedElement;
}
uml::Element *  BehavioralFeatureImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::NamedElement * > *  BehavioralFeatureImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedParameter = (std::vector<uml::NamedElement * > * ) getOwnedParameter();
	_ownedMember->insert(_ownedMember->end(), ownedParameter->begin(), ownedParameter->end());

	std::vector<uml::NamedElement * > *  ownedParameterSet = (std::vector<uml::NamedElement * > * ) getOwnedParameterSet();
	_ownedMember->insert(_ownedMember->end(), ownedParameterSet->begin(), ownedParameterSet->end());

	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());


	return _ownedMember;
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
