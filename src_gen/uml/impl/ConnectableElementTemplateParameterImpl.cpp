#include "ConnectableElementTemplateParameterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectableElementTemplateParameterImpl::ConnectableElementTemplateParameterImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

ConnectableElementTemplateParameterImpl::~ConnectableElementTemplateParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConnectableElementTemplateParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ConnectableElementTemplateParameterImpl::ConnectableElementTemplateParameterImpl(const ConnectableElementTemplateParameterImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_default  = obj.getDefault();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_parameteredElement  = obj.getParameteredElement();

	m_signature  = obj.getSignature();


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
	if(obj.getOwnedDefault()!=nullptr)
	{
		m_ownedDefault.reset(dynamic_cast<uml::ParameterableElement*>(obj.getOwnedDefault()->copy()));
	}
	if(obj.getOwnedParameteredElement()!=nullptr)
	{
		m_ownedParameteredElement.reset(dynamic_cast<uml::ParameterableElement*>(obj.getOwnedParameteredElement()->copy()));
	}
}

ecore::EObject *  ConnectableElementTemplateParameterImpl::copy() const
{
	return new ConnectableElementTemplateParameterImpl(*this);
}

std::shared_ptr<ecore::EClass> ConnectableElementTemplateParameterImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConnectableElementTemplateParameter();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ConnectableElementTemplateParameterImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > ConnectableElementTemplateParameterImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ConnectableElementTemplateParameterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETER_DEFAULT:
			return getDefault(); //344
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //340
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //341
		case UmlPackage::TEMPLATEPARAMETER_OWNEDDEFAULT:
			return getOwnedDefault(); //345
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //342
		case UmlPackage::TEMPLATEPARAMETER_OWNEDPARAMETEREDELEMENT:
			return getOwnedParameteredElement(); //348
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //343
		case UmlPackage::TEMPLATEPARAMETER_PARAMETEREDELEMENT:
			return getParameteredElement(); //346
		case UmlPackage::TEMPLATEPARAMETER_SIGNATURE:
			return getSignature(); //347
	}
	return boost::any();
}
