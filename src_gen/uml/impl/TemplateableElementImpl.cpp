#include "TemplateableElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateableElementImpl::TemplateableElementImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_templateBinding == nullptr)
	{
		m_templateBinding = new std::vector<uml::TemplateBinding * >();
	}
}

TemplateableElementImpl::~TemplateableElementImpl()
{
	if(m_templateBinding!=nullptr)
	{
		for(auto c :*m_templateBinding)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_ownedTemplateSignature!=nullptr)
	{
		if(m_ownedTemplateSignature)
		{
			delete(m_ownedTemplateSignature);
			m_ownedTemplateSignature = nullptr;
		}
	}
	
}

TemplateableElementImpl::TemplateableElementImpl(const TemplateableElementImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = dynamic_cast<uml::TemplateSignature * >(obj.getOwnedTemplateSignature()->copy());
	}
	for(uml::TemplateBinding * 	_templateBinding : *obj.getTemplateBinding())
	{
		this->getTemplateBinding()->push_back(dynamic_cast<uml::TemplateBinding * >(_templateBinding->copy()));
	}
}

ecore::EObject *  TemplateableElementImpl::copy() const
{
	return new TemplateableElementImpl(*this);
}

ecore::EClass* TemplateableElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateableElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateableElementImpl::isTemplate() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::ParameterableElement * > *  TemplateableElementImpl::parameterableElements() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::TemplateSignature *  TemplateableElementImpl::getOwnedTemplateSignature() const
{
	
	return m_ownedTemplateSignature;
}
void TemplateableElementImpl::setOwnedTemplateSignature(uml::TemplateSignature *  _ownedTemplateSignature)
{
	m_ownedTemplateSignature = _ownedTemplateSignature;
}

std::vector<uml::TemplateBinding * > *  TemplateableElementImpl::getTemplateBinding() const
{
	
	return m_templateBinding;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  TemplateableElementImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getOwnedTemplateSignature());
	std::vector<uml::Element * > *  templateBinding = (std::vector<uml::Element * > * ) getTemplateBinding();
	_ownedElement->insert(_ownedElement->end(), templateBinding->begin(), templateBinding->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TemplateableElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //180
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //181
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //182
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //185
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //183
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //184
	}
	return boost::any();
}
