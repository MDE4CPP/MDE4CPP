#include "OperationTemplateParameterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "ParameterableElement.hpp"

#include "TemplateParameter.hpp"

#include "TemplateSignature.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OperationTemplateParameterImpl::OperationTemplateParameterImpl()
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

OperationTemplateParameterImpl::~OperationTemplateParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OperationTemplateParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			OperationTemplateParameterImpl::OperationTemplateParameterImpl(std::weak_ptr<uml::Element > par_owner)
			:OperationTemplateParameterImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			OperationTemplateParameterImpl::OperationTemplateParameterImpl(std::weak_ptr<uml::TemplateSignature > par_signature)
			:OperationTemplateParameterImpl()
			{
			    m_signature = par_signature;
			}






OperationTemplateParameterImpl::OperationTemplateParameterImpl(const OperationTemplateParameterImpl & obj):OperationTemplateParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OperationTemplateParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  OperationTemplateParameterImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new OperationTemplateParameterImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> OperationTemplateParameterImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getOperationTemplateParameter();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool OperationTemplateParameterImpl::match_default_signature(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > OperationTemplateParameterImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > OperationTemplateParameterImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OperationTemplateParameterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETER_DEFAULT:
			return getDefault(); //724
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //720
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //721
		case UmlPackage::TEMPLATEPARAMETER_OWNEDDEFAULT:
			return getOwnedDefault(); //725
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //722
		case UmlPackage::TEMPLATEPARAMETER_OWNEDPARAMETEREDELEMENT:
			return getOwnedParameteredElement(); //728
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //723
		case UmlPackage::TEMPLATEPARAMETER_PARAMETEREDELEMENT:
			return getParameteredElement(); //726
		case UmlPackage::TEMPLATEPARAMETER_SIGNATURE:
			return getSignature(); //727
	}
	return boost::any();
}
