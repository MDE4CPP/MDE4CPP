#include "ParameterableElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ParameterableElementImpl::ParameterableElementImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

ParameterableElementImpl::~ParameterableElementImpl()
{
	
}

ParameterableElementImpl::ParameterableElementImpl(const ParameterableElementImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  ParameterableElementImpl::copy() const
{
	return new ParameterableElementImpl(*this);
}

ecore::EClass* ParameterableElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getParameterableElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ParameterableElementImpl::isCompatibleWith(uml::ParameterableElement *  p) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterableElementImpl::isTemplateParameter() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::TemplateParameter *  ParameterableElementImpl::getOwningTemplateParameter() const
{
	
	return m_owningTemplateParameter;
}
void ParameterableElementImpl::setOwningTemplateParameter(uml::TemplateParameter *  _owningTemplateParameter)
{
	m_owningTemplateParameter = _owningTemplateParameter;
}

uml::TemplateParameter *  ParameterableElementImpl::getTemplateParameter() const
{
	
	return m_templateParameter;
}
void ParameterableElementImpl::setTemplateParameter(uml::TemplateParameter *  _templateParameter)
{
	m_templateParameter = _templateParameter;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ParameterableElementImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  ParameterableElementImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getOwningTemplateParameter()!=nullptr)
	{
		_owner = getOwningTemplateParameter();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ParameterableElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //150
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //151
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //152
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //153
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //154
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //155
	}
	return boost::any();
}
