#include "TemplateSignatureImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateSignatureImpl::TemplateSignatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	m_ownedParameter.reset(new std::vector<std::shared_ptr<uml::TemplateParameter>>());
	m_parameter.reset(new std::vector<std::shared_ptr<uml::TemplateParameter>>());
	
}

TemplateSignatureImpl::~TemplateSignatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateSignature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TemplateSignatureImpl::TemplateSignatureImpl(const TemplateSignatureImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	std::shared_ptr<std::vector<std::shared_ptr<uml::TemplateParameter>>> _parameter = obj.getParameter();
	this->getParameter()->insert(this->getParameter()->end(), _parameter->begin(), _parameter->end());

	m_template  = obj.getTemplate();


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAnnotation>>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
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

ecore::EObject *  TemplateSignatureImpl::copy() const
{
	return new TemplateSignatureImpl(*this);
}

std::shared_ptr<ecore::EClass> TemplateSignatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateSignature();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateSignatureImpl::own_elements(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TemplateSignatureImpl::unique_parameters(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<uml::TemplateParameter>>> TemplateSignatureImpl::getOwnedParameter() const
{

    return m_ownedParameter;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::TemplateParameter>>> TemplateSignatureImpl::getParameter() const
{
//assert(m_parameter);
    return m_parameter;
}


std::shared_ptr<uml::TemplateableElement> TemplateSignatureImpl::getTemplate() const
{
//assert(m_template);
    return m_template;
}
void TemplateSignatureImpl::setTemplate(std::shared_ptr<uml::TemplateableElement> _template)
{
    m_template = _template;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element> TemplateSignatureImpl::getOwner() const
{
	std::shared_ptr<uml::Element> _owner = nullptr ;
	
	if(getTemplate()!=nullptr)
	{
		_owner = getTemplate();
	}

	return _owner;
}
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> TemplateSignatureImpl::getOwnedElement() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement(new std::vector<std::shared_ptr<uml::Element>>()) ;
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> ownedComment = getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());
	std::shared_ptr<std::vector<std::shared_ptr<uml::TemplateParameter>>> ownedParameter = getOwnedParameter();
	_ownedElement->insert(_ownedElement->end(), ownedParameter->begin(), ownedParameter->end());

	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TemplateSignatureImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //170
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //171
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //172
		case UmlPackage::TEMPLATESIGNATURE_OWNEDPARAMETER:
			return getOwnedParameter(); //176
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //173
		case UmlPackage::TEMPLATESIGNATURE_PARAMETER:
			return getParameter(); //174
		case UmlPackage::TEMPLATESIGNATURE_TEMPLATE:
			return getTemplate(); //175
	}
	return boost::any();
}
