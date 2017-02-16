#include "TemplateParameterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateParameterImpl::TemplateParameterImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	
	
	
}

TemplateParameterImpl::~TemplateParameterImpl()
{
	if(m_ownedDefault!=nullptr)
	{
		if(m_ownedDefault)
		{
			delete(m_ownedDefault);
			m_ownedDefault = nullptr;
		}
	}
	if(m_ownedParameteredElement!=nullptr)
	{
		if(m_ownedParameteredElement)
		{
			delete(m_ownedParameteredElement);
			m_ownedParameteredElement = nullptr;
		}
	}
	
}

TemplateParameterImpl::TemplateParameterImpl(const TemplateParameterImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_default  = obj.getDefault();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_parameteredElement  = obj.getParameteredElement();

	m_signature  = obj.getSignature();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	if(obj.getOwnedDefault()!=nullptr)
	{
		m_ownedDefault = dynamic_cast<uml::ParameterableElement * >(obj.getOwnedDefault()->copy());
	}
	if(obj.getOwnedParameteredElement()!=nullptr)
	{
		m_ownedParameteredElement = dynamic_cast<uml::ParameterableElement * >(obj.getOwnedParameteredElement()->copy());
	}
}

ecore::EObject *  TemplateParameterImpl::copy() const
{
	return new TemplateParameterImpl(*this);
}

ecore::EClass* TemplateParameterImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateParameter();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateParameterImpl::must_be_compatible(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::ParameterableElement *  TemplateParameterImpl::getDefault() const
{
	
	return m_default;
}
void TemplateParameterImpl::setDefault(uml::ParameterableElement *  _default)
{
	m_default = _default;
}

uml::ParameterableElement *  TemplateParameterImpl::getOwnedDefault() const
{
	
	return m_ownedDefault;
}
void TemplateParameterImpl::setOwnedDefault(uml::ParameterableElement *  _ownedDefault)
{
	m_ownedDefault = _ownedDefault;
}

uml::ParameterableElement *  TemplateParameterImpl::getOwnedParameteredElement() const
{
	
	return m_ownedParameteredElement;
}
void TemplateParameterImpl::setOwnedParameteredElement(uml::ParameterableElement *  _ownedParameteredElement)
{
	m_ownedParameteredElement = _ownedParameteredElement;
}

uml::ParameterableElement *  TemplateParameterImpl::getParameteredElement() const
{
	//assert(m_parameteredElement);
	return m_parameteredElement;
}
void TemplateParameterImpl::setParameteredElement(uml::ParameterableElement *  _parameteredElement)
{
	m_parameteredElement = _parameteredElement;
}

uml::TemplateSignature *  TemplateParameterImpl::getSignature() const
{
	//assert(m_signature);
	return m_signature;
}
void TemplateParameterImpl::setSignature(uml::TemplateSignature *  _signature)
{
	m_signature = _signature;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  TemplateParameterImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getSignature()!=nullptr)
	{
		_owner = getSignature();
	}

	return _owner;
}
std::vector<uml::Element * > *  TemplateParameterImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getOwnedDefault());
	_ownedElement->push_back(getOwnedParameteredElement());

	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TemplateParameterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETER_DEFAULT:
			return getDefault(); //164
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //160
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //161
		case UmlPackage::TEMPLATEPARAMETER_OWNEDDEFAULT:
			return getOwnedDefault(); //165
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //162
		case UmlPackage::TEMPLATEPARAMETER_OWNEDPARAMETEREDELEMENT:
			return getOwnedParameteredElement(); //168
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //163
		case UmlPackage::TEMPLATEPARAMETER_PARAMETEREDELEMENT:
			return getParameteredElement(); //166
		case UmlPackage::TEMPLATEPARAMETER_SIGNATURE:
			return getSignature(); //167
	}
	return boost::any();
}
