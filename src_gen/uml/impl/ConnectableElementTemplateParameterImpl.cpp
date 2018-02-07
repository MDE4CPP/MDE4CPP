#include "uml/impl/ConnectableElementTemplateParameterImpl.hpp"
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

#include "uml/TemplateSignature.hpp"


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
	//References

	//Init references
}

ConnectableElementTemplateParameterImpl::~ConnectableElementTemplateParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConnectableElementTemplateParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ConnectableElementTemplateParameterImpl::ConnectableElementTemplateParameterImpl(std::weak_ptr<uml::Element > par_owner)
			:ConnectableElementTemplateParameterImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ConnectableElementTemplateParameterImpl::ConnectableElementTemplateParameterImpl(std::weak_ptr<uml::TemplateSignature > par_signature)
			:ConnectableElementTemplateParameterImpl()
			{
			    m_signature = par_signature;
			}






ConnectableElementTemplateParameterImpl::ConnectableElementTemplateParameterImpl(const ConnectableElementTemplateParameterImpl & obj):ConnectableElementTemplateParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConnectableElementTemplateParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  ConnectableElementTemplateParameterImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ConnectableElementTemplateParameterImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ConnectableElementTemplateParameterImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConnectableElementTemplateParameter();
}

//*********************************
// Attribute Setter Getter
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
std::weak_ptr<uml::Element > ConnectableElementTemplateParameterImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> ConnectableElementTemplateParameterImpl::eContainer() const
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
boost::any ConnectableElementTemplateParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void ConnectableElementTemplateParameterImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETER_DEFAULT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _default = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setDefault(_default); //344
			break;
		}
		case UmlPackage::TEMPLATEPARAMETER_OWNEDDEFAULT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _ownedDefault = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setOwnedDefault(_ownedDefault); //345
			break;
		}
		case UmlPackage::TEMPLATEPARAMETER_OWNEDPARAMETEREDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _ownedParameteredElement = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setOwnedParameteredElement(_ownedParameteredElement); //348
			break;
		}
		case UmlPackage::TEMPLATEPARAMETER_PARAMETEREDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _parameteredElement = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setParameteredElement(_parameteredElement); //346
			break;
		}
		case UmlPackage::TEMPLATEPARAMETER_SIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateSignature> _signature = boost::any_cast<std::shared_ptr<uml::TemplateSignature>>(newValue);
			setSignature(_signature); //347
			break;
		}
	}
}
