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
	// Reference Members
	//*********************************
	if( m_ownedParameter == nullptr)
	{
		m_ownedParameter = new std::vector<uml::TemplateParameter * >();
	}
	if( m_parameter == nullptr)
	{
		m_parameter = new std::vector<uml::TemplateParameter * >();
	}
	
}

TemplateSignatureImpl::~TemplateSignatureImpl()
{
	if(m_parameter!=nullptr)
	{
		delete(m_parameter);
	 	m_parameter = nullptr;
	}
	if(m_ownedParameter!=nullptr)
	{
		for(auto c :*m_ownedParameter)
		{
			delete(c);
			c = 0;
		}
	}
	
}

TemplateSignatureImpl::TemplateSignatureImpl(const TemplateSignatureImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::TemplateParameter * > *  _parameter = obj.getParameter();
	this->getParameter()->insert(this->getParameter()->end(), _parameter->begin(), _parameter->end());

	m_template  = obj.getTemplate();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
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

ecore::EObject *  TemplateSignatureImpl::copy() const
{
	return new TemplateSignatureImpl(*this);
}

ecore::EClass* TemplateSignatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateSignature();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateSignatureImpl::own_elements(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TemplateSignatureImpl::unique_parameters(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::TemplateParameter * > *  TemplateSignatureImpl::getOwnedParameter() const
{
	
	return m_ownedParameter;
}


std::vector<uml::TemplateParameter * > *  TemplateSignatureImpl::getParameter() const
{
	//assert(m_parameter);
	return m_parameter;
}


uml::TemplateableElement *  TemplateSignatureImpl::getTemplate() const
{
	//assert(m_template);
	return m_template;
}
void TemplateSignatureImpl::setTemplate(uml::TemplateableElement *  _template)
{
	m_template = _template;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  TemplateSignatureImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedParameter = (std::vector<uml::Element * > * ) getOwnedParameter();
	_ownedElement->insert(_ownedElement->end(), ownedParameter->begin(), ownedParameter->end());


	return _ownedElement;
}
uml::Element *  TemplateSignatureImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getTemplate()!=nullptr)
	{
		_owner = getTemplate();
	}

	return _owner;
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
