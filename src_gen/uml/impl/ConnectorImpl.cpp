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
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
		m_contract.reset(new Bag<uml::Behavior>());
	
	
		/*Subset*/
		m_end.reset(new Subset<uml::ConnectorEnd, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
		/*Subset*/
		m_redefinedConnector.reset(new Subset<uml::Connector, uml::RedefinableElement >(m_redefinedElement));//(m_redefinedElement));
	
	
	
}

ConnectorImpl::~ConnectorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Connector "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
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
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

		std::shared_ptr< Bag<uml::Behavior> >
	 _contract = obj.getContract();
	m_contract.reset(new 	 Bag<uml::Behavior> 
	(*(obj.getContract().get())));// this->getContract()->insert(this->getContract()->end(), _contract->begin(), _contract->end());

			std::shared_ptr<Union<uml::Classifier> > _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new 		Union<uml::Classifier> (*(obj.getFeaturingClassifier().get())));// this->getFeaturingClassifier()->insert(this->getFeaturingClassifier()->end(), _featuringClassifier->begin(), _featuringClassifier->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

			std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement > >
	 _redefinedConnector = obj.getRedefinedConnector();
	m_redefinedConnector.reset(new 		Subset<uml::Connector, uml::RedefinableElement > 
	(*(obj.getRedefinedConnector().get())));// this->getRedefinedConnector()->insert(this->getRedefinedConnector()->end(), _redefinedConnector->begin(), _redefinedConnector->end());

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
	std::shared_ptr<Bag<uml::ConnectorEnd>> _endList = obj.getEnd();
	for(std::shared_ptr<uml::ConnectorEnd> _end : *_endList)
	{
		this->getEnd()->add(std::shared_ptr<uml::ConnectorEnd>(dynamic_cast<uml::ConnectorEnd*>(_end->copy())));
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

ecore::EObject *  ConnectorImpl::copy() const
{
	return new ConnectorImpl(*this);
}

std::shared_ptr<ecore::EClass> ConnectorImpl::eStaticClass() const
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
ConnectorKind
 ConnectorImpl::getKind() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ConnectorImpl::roles(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ConnectorImpl::types(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::Behavior> >
 ConnectorImpl::getContract() const
{

    return m_contract;
}


		std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element > >
 ConnectorImpl::getEnd() const
{
//assert(m_end);
    return m_end;
}


		std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement > >
 ConnectorImpl::getRedefinedConnector() const
{

    return m_redefinedConnector;
}


std::shared_ptr<uml::Association > ConnectorImpl::getType() const
{

    return m_type;
}
void ConnectorImpl::setType(std::shared_ptr<uml::Association> _type)
{
    m_type = _type;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > ConnectorImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > ConnectorImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ConnectorImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
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
