#include "uml/impl/ParameterableElementImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ParameterableElement.hpp"

#include "uml/TemplateParameter.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ParameterableElementImpl::ParameterableElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	//Init references
	

	
}

ParameterableElementImpl::~ParameterableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ParameterableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ParameterableElementImpl::ParameterableElementImpl(std::weak_ptr<uml::Element > par_owner)
			:ParameterableElementImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ParameterableElementImpl::ParameterableElementImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ParameterableElementImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






ParameterableElementImpl::ParameterableElementImpl(const ParameterableElementImpl & obj):ParameterableElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ParameterableElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ParameterableElementImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ParameterableElementImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ParameterableElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getParameterableElement_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ParameterableElementImpl::isCompatibleWith(std::shared_ptr<uml::ParameterableElement>  p) 
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
std::weak_ptr<uml::TemplateParameter > ParameterableElementImpl::getOwningTemplateParameter() const
{

    return m_owningTemplateParameter;
}
void ParameterableElementImpl::setOwningTemplateParameter(std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter)
{
    m_owningTemplateParameter = _owningTemplateParameter;
}

std::shared_ptr<uml::TemplateParameter > ParameterableElementImpl::getTemplateParameter() const
{

    return m_templateParameter;
}
void ParameterableElementImpl::setTemplateParameter(std::shared_ptr<uml::TemplateParameter> _templateParameter)
{
    m_templateParameter = _templateParameter;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > ParameterableElementImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ParameterableElementImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> ParameterableElementImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ParameterableElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //150
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //151
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //152
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //153
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //154
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //155
	}
	return boost::any();
}

void ParameterableElementImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //154
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //155
			break;
		}
	}
}
