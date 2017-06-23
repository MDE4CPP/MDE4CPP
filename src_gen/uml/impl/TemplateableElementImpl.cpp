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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
		/*Subset*/
		m_templateBinding.reset(new Subset<uml::TemplateBinding, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
}

TemplateableElementImpl::~TemplateableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TemplateableElementImpl::TemplateableElementImpl(const TemplateableElementImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature.reset(dynamic_cast<uml::TemplateSignature*>(obj.getOwnedTemplateSignature()->copy()));
	}
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(dynamic_cast<uml::TemplateBinding*>(_templateBinding->copy())));
	}
}

ecore::EObject *  TemplateableElementImpl::copy() const
{
	return new TemplateableElementImpl(*this);
}

std::shared_ptr<ecore::EClass> TemplateableElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateableElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 TemplateableElementImpl::isTemplate() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::ParameterableElement> >
 TemplateableElementImpl::parameterableElements() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::TemplateSignature > TemplateableElementImpl::getOwnedTemplateSignature() const
{

    return m_ownedTemplateSignature;
}
void TemplateableElementImpl::setOwnedTemplateSignature(std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature)
{
    m_ownedTemplateSignature = _ownedTemplateSignature;
}

		std::shared_ptr<Subset<uml::TemplateBinding, uml::Element > >
 TemplateableElementImpl::getTemplateBinding() const
{

    return m_templateBinding;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > TemplateableElementImpl::getOwnedElement() const
{
	

	return m_ownedElement;
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
