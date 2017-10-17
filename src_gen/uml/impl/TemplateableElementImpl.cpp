#include "TemplateableElementImpl.hpp"
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

#include "TemplateBinding.hpp"

#include "TemplateSignature.hpp"


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
	//References
	

		/*Subset*/
		m_templateBinding.reset(new Subset<uml::TemplateBinding, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
	

		/*Subset*/
		m_templateBinding->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

TemplateableElementImpl::~TemplateableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			TemplateableElementImpl::TemplateableElementImpl(std::weak_ptr<uml::Element > par_owner)
			:TemplateableElementImpl()
			{
			    m_owner = par_owner;
			}






TemplateableElementImpl::TemplateableElementImpl(const TemplateableElementImpl & obj):TemplateableElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateableElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();


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
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getOwnedTemplateSignature()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedTemplateSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(std::dynamic_pointer_cast<uml::TemplateBinding>(_templateBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_templateBinding" << std::endl;
	#endif

	

		/*Subset*/
		m_templateBinding->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  TemplateableElementImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new TemplateableElementImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> TemplateableElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateableElement();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateableElementImpl::isTemplate() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::ParameterableElement> > TemplateableElementImpl::parameterableElements() 
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

std::shared_ptr<Subset<uml::TemplateBinding, uml::Element > > TemplateableElementImpl::getTemplateBinding() const
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
