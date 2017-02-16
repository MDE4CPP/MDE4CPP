#include "RedefinableTemplateSignatureImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_extendedSignature == nullptr)
	{
		m_extendedSignature = new std::vector<uml::RedefinableTemplateSignature * >();
	}
	if( m_inheritedParameter == nullptr)
	{
		m_inheritedParameter = new std::vector<uml::TemplateParameter * >();
	}
}

RedefinableTemplateSignatureImpl::~RedefinableTemplateSignatureImpl()
{
	if(m_extendedSignature!=nullptr)
	{
		delete(m_extendedSignature);
	 	m_extendedSignature = nullptr;
	}
	if(m_inheritedParameter!=nullptr)
	{
		delete(m_inheritedParameter);
	 	m_inheritedParameter = nullptr;
	}
	
}

RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(const RedefinableTemplateSignatureImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_classifier  = obj.getClassifier();

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::RedefinableTemplateSignature * > *  _extendedSignature = obj.getExtendedSignature();
	this->getExtendedSignature()->insert(this->getExtendedSignature()->end(), _extendedSignature->begin(), _extendedSignature->end());

	std::vector<uml::TemplateParameter * > *  _inheritedParameter = obj.getInheritedParameter();
	this->getInheritedParameter()->insert(this->getInheritedParameter()->end(), _inheritedParameter->begin(), _inheritedParameter->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::TemplateParameter * > *  _parameter = obj.getParameter();
	this->getParameter()->insert(this->getParameter()->end(), _parameter->begin(), _parameter->end());

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	m_template  = obj.getTemplate();


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
	for(uml::TemplateParameter * 	_ownedParameter : *obj.getOwnedParameter())
	{
		this->getOwnedParameter()->push_back(dynamic_cast<uml::TemplateParameter * >(_ownedParameter->copy()));
	}
}

ecore::EObject *  RedefinableTemplateSignatureImpl::copy() const
{
	return new RedefinableTemplateSignatureImpl(*this);
}

ecore::EClass* RedefinableTemplateSignatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRedefinableTemplateSignature();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::vector<uml::TemplateParameter * > *  RedefinableTemplateSignatureImpl::getInheritedParameters() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableTemplateSignatureImpl::redefines_parents(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Classifier *  RedefinableTemplateSignatureImpl::getClassifier() const
{
	//assert(m_classifier);
	return m_classifier;
}


std::vector<uml::RedefinableTemplateSignature * > *  RedefinableTemplateSignatureImpl::getExtendedSignature() const
{
	
	return m_extendedSignature;
}


std::vector<uml::TemplateParameter * > *  RedefinableTemplateSignatureImpl::getInheritedParameter() const
{
	
	return m_inheritedParameter;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::RedefinableElement * > *  RedefinableTemplateSignatureImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  extendedSignature = (std::vector<uml::RedefinableElement * > * ) getExtendedSignature();
	_redefinedElement->insert(_redefinedElement->end(), extendedSignature->begin(), extendedSignature->end());


	return _redefinedElement;
}
std::vector<uml::Classifier * > *  RedefinableTemplateSignatureImpl::getRedefinitionContext() const
{
	std::vector<uml::Classifier * > *  _redefinitionContext =  new std::vector<uml::Classifier * >() ;
	
	_redefinitionContext->push_back(getClassifier());

	return _redefinitionContext;
}
std::vector<uml::Element * > *  RedefinableTemplateSignatureImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedParameter = (std::vector<uml::Element * > * ) getOwnedParameter();
	_ownedElement->insert(_ownedElement->end(), ownedParameter->begin(), ownedParameter->end());


	return _ownedElement;
}
uml::Element *  RedefinableTemplateSignatureImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}
	if(getTemplate()!=nullptr)
	{
		_owner = getTemplate();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RedefinableTemplateSignatureImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_CLASSIFIER:
			return getClassifier(); //9718
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //974
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //970
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_EXTENDEDSIGNATURE:
			return getExtendedSignature(); //9716
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_INHERITEDPARAMETER:
			return getInheritedParameter(); //9717
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //9710
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //975
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //976
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //977
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //971
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //972
		case UmlPackage::TEMPLATESIGNATURE_OWNEDPARAMETER:
			return getOwnedParameter(); //976
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //973
		case UmlPackage::TEMPLATESIGNATURE_PARAMETER:
			return getParameter(); //974
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //978
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //9711
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //9712
		case UmlPackage::TEMPLATESIGNATURE_TEMPLATE:
			return getTemplate(); //975
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //979
	}
	return boost::any();
}
