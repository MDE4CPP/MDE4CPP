#include "ExtensionPointImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExtensionPointImpl::ExtensionPointImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

ExtensionPointImpl::~ExtensionPointImpl()
{
	
}

ExtensionPointImpl::ExtensionPointImpl(const ExtensionPointImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

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

	m_useCase  = obj.getUseCase();


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

ecore::EObject *  ExtensionPointImpl::copy() const
{
	return new ExtensionPointImpl(*this);
}

ecore::EClass* ExtensionPointImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExtensionPoint();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ExtensionPointImpl::must_have_name(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::UseCase *  ExtensionPointImpl::getUseCase() const
{
	//assert(m_useCase);
	return m_useCase;
}
void ExtensionPointImpl::setUseCase(uml::UseCase *  _useCase)
{
	m_useCase = _useCase;
}

//*********************************
// Union Getter
//*********************************
uml::Namespace *  ExtensionPointImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getUseCase()!=nullptr)
	{
		_namespace = getUseCase();
	}

	return _namespace;
}
uml::Element *  ExtensionPointImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::Element * > *  ExtensionPointImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExtensionPointImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1004
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1000
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //10010
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1005
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1006
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1007
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1001
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1002
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1003
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1008
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //10011
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //10012
		case UmlPackage::EXTENSIONPOINT_USECASE:
			return getUseCase(); //10013
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1009
	}
	return boost::any();
}
