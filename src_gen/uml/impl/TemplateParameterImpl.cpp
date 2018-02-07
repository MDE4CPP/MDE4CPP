#include "uml/impl/TemplateParameterImpl.hpp"
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

#include "uml/TemplateSignature.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateParameterImpl::TemplateParameterImpl()
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

TemplateParameterImpl::~TemplateParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			TemplateParameterImpl::TemplateParameterImpl(std::weak_ptr<uml::Element > par_owner)
			:TemplateParameterImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TemplateParameterImpl::TemplateParameterImpl(std::weak_ptr<uml::TemplateSignature > par_signature)
			:TemplateParameterImpl()
			{
			    m_signature = par_signature;
			}






TemplateParameterImpl::TemplateParameterImpl(const TemplateParameterImpl & obj):TemplateParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_default  = obj.getDefault();

	m_owner  = obj.getOwner();

	m_parameteredElement  = obj.getParameteredElement();

	m_signature  = obj.getSignature();


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
	if(obj.getOwnedDefault()!=nullptr)
	{
		m_ownedDefault = std::dynamic_pointer_cast<uml::ParameterableElement>(obj.getOwnedDefault()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedDefault" << std::endl;
	#endif
	if(obj.getOwnedParameteredElement()!=nullptr)
	{
		m_ownedParameteredElement = std::dynamic_pointer_cast<uml::ParameterableElement>(obj.getOwnedParameteredElement()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameteredElement" << std::endl;
	#endif

	

	
}

std::shared_ptr<ecore::EObject>  TemplateParameterImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new TemplateParameterImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> TemplateParameterImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateParameter();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateParameterImpl::must_be_compatible(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ParameterableElement > TemplateParameterImpl::getDefault() const
{

    return m_default;
}
void TemplateParameterImpl::setDefault(std::shared_ptr<uml::ParameterableElement> _default)
{
    m_default = _default;
}

std::shared_ptr<uml::ParameterableElement > TemplateParameterImpl::getOwnedDefault() const
{

    return m_ownedDefault;
}
void TemplateParameterImpl::setOwnedDefault(std::shared_ptr<uml::ParameterableElement> _ownedDefault)
{
    m_ownedDefault = _ownedDefault;
}

std::shared_ptr<uml::ParameterableElement > TemplateParameterImpl::getOwnedParameteredElement() const
{

    return m_ownedParameteredElement;
}
void TemplateParameterImpl::setOwnedParameteredElement(std::shared_ptr<uml::ParameterableElement> _ownedParameteredElement)
{
    m_ownedParameteredElement = _ownedParameteredElement;
}

std::shared_ptr<uml::ParameterableElement > TemplateParameterImpl::getParameteredElement() const
{
//assert(m_parameteredElement);
    return m_parameteredElement;
}
void TemplateParameterImpl::setParameteredElement(std::shared_ptr<uml::ParameterableElement> _parameteredElement)
{
    m_parameteredElement = _parameteredElement;
}

std::weak_ptr<uml::TemplateSignature > TemplateParameterImpl::getSignature() const
{
//assert(m_signature);
    return m_signature;
}
void TemplateParameterImpl::setSignature(std::shared_ptr<uml::TemplateSignature> _signature)
{
    m_signature = _signature;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > TemplateParameterImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TemplateParameterImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> TemplateParameterImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_signature.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TemplateParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void TemplateParameterImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETER_DEFAULT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _default = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setDefault(_default); //164
			break;
		}
		case UmlPackage::TEMPLATEPARAMETER_OWNEDDEFAULT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _ownedDefault = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setOwnedDefault(_ownedDefault); //165
			break;
		}
		case UmlPackage::TEMPLATEPARAMETER_OWNEDPARAMETEREDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _ownedParameteredElement = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setOwnedParameteredElement(_ownedParameteredElement); //168
			break;
		}
		case UmlPackage::TEMPLATEPARAMETER_PARAMETEREDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _parameteredElement = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setParameteredElement(_parameteredElement); //166
			break;
		}
		case UmlPackage::TEMPLATEPARAMETER_SIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateSignature> _signature = boost::any_cast<std::shared_ptr<uml::TemplateSignature>>(newValue);
			setSignature(_signature); //167
			break;
		}
	}
}
