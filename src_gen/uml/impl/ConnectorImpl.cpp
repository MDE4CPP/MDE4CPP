#include "ConnectorImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectorImpl::ConnectorImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_contract == nullptr)
	{
		m_contract = new std::vector<uml::Behavior * >();
	}
	if( m_end == nullptr)
	{
		m_end = new std::vector<uml::ConnectorEnd * >();
	}
	if( m_redefinedConnector == nullptr)
	{
		m_redefinedConnector = new std::vector<uml::Connector * >();
	}
	
}

ConnectorImpl::~ConnectorImpl()
{
	if(m_contract!=nullptr)
	{
		delete(m_contract);
	 	m_contract = nullptr;
	}
	if(m_end!=nullptr)
	{
		for(auto c :*m_end)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_redefinedConnector!=nullptr)
	{
		delete(m_redefinedConnector);
	 	m_redefinedConnector = nullptr;
	}
	
}

ConnectorImpl::ConnectorImpl(const ConnectorImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isStatic = obj.getIsStatic();
	m_kind = obj.getKind();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::Behavior * > *  _contract = obj.getContract();
	this->getContract()->insert(this->getContract()->end(), _contract->begin(), _contract->end());

	std::vector<uml::Classifier * > *  _featuringClassifier = obj.getFeaturingClassifier();
	this->getFeaturingClassifier()->insert(this->getFeaturingClassifier()->end(), _featuringClassifier->begin(), _featuringClassifier->end());
	delete(_featuringClassifier);

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::Connector * > *  _redefinedConnector = obj.getRedefinedConnector();
	this->getRedefinedConnector()->insert(this->getRedefinedConnector()->end(), _redefinedConnector->begin(), _redefinedConnector->end());

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	m_type  = obj.getType();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::ConnectorEnd * 	_end : *obj.getEnd())
	{
		this->getEnd()->push_back(dynamic_cast<uml::ConnectorEnd * >(_end->copy()));
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

ecore::EObject *  ConnectorImpl::copy() const
{
	return new ConnectorImpl(*this);
}

ecore::EClass* ConnectorImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConnector();
}

//*********************************
// Attribute Setter Gettter
//*********************************


ConnectorKind ConnectorImpl::getKind() const 
{
	return m_kind;
}

//*********************************
// Operations
//*********************************
ConnectorKind ConnectorImpl::getKind() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorImpl::roles(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorImpl::types(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Behavior * > *  ConnectorImpl::getContract() const
{
	
	return m_contract;
}


std::vector<uml::ConnectorEnd * > *  ConnectorImpl::getEnd() const
{
	//assert(m_end);
	return m_end;
}


std::vector<uml::Connector * > *  ConnectorImpl::getRedefinedConnector() const
{
	
	return m_redefinedConnector;
}


uml::Association *  ConnectorImpl::getType() const
{
	
	return m_type;
}
void ConnectorImpl::setType(uml::Association *  _type)
{
	m_type = _type;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  ConnectorImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::RedefinableElement * > *  ConnectorImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedConnector = (std::vector<uml::RedefinableElement * > * ) getRedefinedConnector();
	_redefinedElement->insert(_redefinedElement->end(), redefinedConnector->begin(), redefinedConnector->end());


	return _redefinedElement;
}
std::vector<uml::Element * > *  ConnectorImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  end = (std::vector<uml::Element * > * ) getEnd();
	_ownedElement->insert(_ownedElement->end(), end->begin(), end->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ConnectorImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //934
		case UmlPackage::CONNECTOR_CONTRACT:
			return getContract(); //9315
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //930
		case UmlPackage::CONNECTOR_END:
			return getEnd(); //9316
		case UmlPackage::FEATURE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //9313
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //9310
		case UmlPackage::FEATURE_ISSTATIC:
			return getIsStatic(); //9314
		case UmlPackage::CONNECTOR_KIND:
			return getKind(); //9317
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //935
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //936
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //937
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //931
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //932
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //933
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //938
		case UmlPackage::CONNECTOR_REDEFINEDCONNECTOR:
			return getRedefinedConnector(); //9318
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //9311
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //9312
		case UmlPackage::CONNECTOR_TYPE:
			return getType(); //9319
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //939
	}
	return boost::any();
}
