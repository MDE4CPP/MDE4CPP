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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	m_extendedSignature.reset(new std::vector<std::shared_ptr<uml::RedefinableTemplateSignature>>());
	m_inheritedParameter.reset(new std::vector<std::shared_ptr<uml::TemplateParameter>>());
}

RedefinableTemplateSignatureImpl::~RedefinableTemplateSignatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RedefinableTemplateSignature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
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

	std::shared_ptr<std::vector<std::shared_ptr<uml::Dependency>>> _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::RedefinableTemplateSignature>>> _extendedSignature = obj.getExtendedSignature();
	this->getExtendedSignature()->insert(this->getExtendedSignature()->end(), _extendedSignature->begin(), _extendedSignature->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::TemplateParameter>>> _inheritedParameter = obj.getInheritedParameter();
	this->getInheritedParameter()->insert(this->getInheritedParameter()->end(), _inheritedParameter->begin(), _inheritedParameter->end());

	m_namespace  = obj.getNamespace();

	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	std::shared_ptr<std::vector<std::shared_ptr<uml::TemplateParameter>>> _parameter = obj.getParameter();
	this->getParameter()->insert(this->getParameter()->end(), _parameter->begin(), _parameter->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::RedefinableElement>>> _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Classifier>>> _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

	m_template  = obj.getTemplate();


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAnnotation>>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->push_back(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::TemplateParameter>>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::TemplateParameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->push_back(std::shared_ptr<uml::TemplateParameter>(dynamic_cast<uml::TemplateParameter*>(_ownedParameter->copy())));
	}
}

ecore::EObject *  RedefinableTemplateSignatureImpl::copy() const
{
	return new RedefinableTemplateSignatureImpl(*this);
}

std::shared_ptr<ecore::EClass> RedefinableTemplateSignatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRedefinableTemplateSignature();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<uml::TemplateParameter>>> RedefinableTemplateSignatureImpl::getInheritedParameters() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableTemplateSignatureImpl::redefines_parents(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Classifier> RedefinableTemplateSignatureImpl::getClassifier() const
{
//assert(m_classifier);
    return m_classifier;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::RedefinableTemplateSignature>>> RedefinableTemplateSignatureImpl::getExtendedSignature() const
{

    return m_extendedSignature;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::TemplateParameter>>> RedefinableTemplateSignatureImpl::getInheritedParameter() const
{

    return m_inheritedParameter;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<uml::RedefinableElement>>> RedefinableTemplateSignatureImpl::getRedefinedElement() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::RedefinableElement>>> _redefinedElement(new std::vector<std::shared_ptr<uml::RedefinableElement>>()) ;
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::RedefinableTemplateSignature>>> extendedSignature = getExtendedSignature();
	_redefinedElement->insert(_redefinedElement->end(), extendedSignature->begin(), extendedSignature->end());

	return _redefinedElement;
}
std::shared_ptr<uml::Element> RedefinableTemplateSignatureImpl::getOwner() const
{
	std::shared_ptr<uml::Element> _owner = nullptr ;
	
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
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> RedefinableTemplateSignatureImpl::getOwnedElement() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement(new std::vector<std::shared_ptr<uml::Element>>()) ;
	
	_ownedElement->push_back(getNameExpression());
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> ownedComment = getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());
	std::shared_ptr<std::vector<std::shared_ptr<uml::TemplateParameter>>> ownedParameter = getOwnedParameter();
	_ownedElement->insert(_ownedElement->end(), ownedParameter->begin(), ownedParameter->end());

	return _ownedElement;
}
std::shared_ptr<std::vector<std::shared_ptr<uml::Classifier>>> RedefinableTemplateSignatureImpl::getRedefinitionContext() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Classifier>>> _redefinitionContext(new std::vector<std::shared_ptr<uml::Classifier>>()) ;
	
	_redefinitionContext->push_back(getClassifier());

	return _redefinitionContext;
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
