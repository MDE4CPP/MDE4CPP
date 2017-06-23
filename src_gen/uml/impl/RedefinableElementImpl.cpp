#include "RedefinableElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RedefinableElementImpl::RedefinableElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
	
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
	
}

RedefinableElementImpl::~RedefinableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RedefinableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

RedefinableElementImpl::RedefinableElementImpl(const RedefinableElementImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

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

ecore::EObject *  RedefinableElementImpl::copy() const
{
	return new RedefinableElementImpl(*this);
}

std::shared_ptr<ecore::EClass> RedefinableElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRedefinableElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void RedefinableElementImpl::setIsLeaf (bool _isLeaf)
{
	m_isLeaf = _isLeaf;
} 

bool RedefinableElementImpl::getIsLeaf() const 
{
	return m_isLeaf;
}

//*********************************
// Operations
//*********************************
bool
 RedefinableElementImpl::isConsistentWith(std::shared_ptr<uml::RedefinableElement>  redefiningElement) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 RedefinableElementImpl::isRedefinitionContextValid(std::shared_ptr<uml::RedefinableElement>  redefinedElement) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 RedefinableElementImpl::non_leaf_redefinition(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 RedefinableElementImpl::redefinition_consistent(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 RedefinableElementImpl::redefinition_context_valid(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************






//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > RedefinableElementImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::Classifier> > RedefinableElementImpl::getRedefinitionContext() const
{
	

	return m_redefinitionContext;
}
std::shared_ptr<uml::Element > RedefinableElementImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::RedefinableElement> > RedefinableElementImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RedefinableElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //504
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //500
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //5010
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //505
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //506
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //507
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //501
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //502
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //503
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //508
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //5011
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //5012
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //509
	}
	return boost::any();
}
