#include "TemplateSignatureImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "TemplateParameter.hpp"

#include "TemplateableElement.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateSignatureImpl::TemplateSignatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >()" << std::endl;
		#endif
	
	

		/*Union*/
		m_parameter.reset(new Union<uml::TemplateParameter>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_parameter - Union<uml::TemplateParameter>()" << std::endl;
		#endif
	
	

	

	//Init references
		/*Subset*/
		m_ownedParameter->initSubset(m_ownedElement,m_parameter);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >(m_ownedElement,m_parameter)" << std::endl;
		#endif
	
	

	
	

	
}

TemplateSignatureImpl::~TemplateSignatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateSignature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TemplateSignatureImpl::TemplateSignatureImpl(const TemplateSignatureImpl & obj):TemplateSignatureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateSignature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::TemplateParameter> > _parameter = obj.getParameter();
	m_parameter.reset(new 		Union<uml::TemplateParameter> (*(obj.getParameter().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateParameter>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::TemplateParameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->add(std::shared_ptr<uml::TemplateParameter>(dynamic_cast<uml::TemplateParameter*>(_ownedParameter->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameter" << std::endl;
	#endif
	if(obj.getTemplate()!=nullptr)
	{
		m_template.reset(dynamic_cast<uml::TemplateableElement*>(obj.getTemplate()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_template" << std::endl;
	#endif

		/*Subset*/
		m_ownedParameter->initSubset(m_ownedElement,m_parameter);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >(m_ownedElement,m_parameter)" << std::endl;
		#endif
	
	

}

ecore::EObject *  TemplateSignatureImpl::copy() const
{
	return new TemplateSignatureImpl(*this);
}

std::shared_ptr<ecore::EClass> TemplateSignatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateSignature();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 TemplateSignatureImpl::own_elements(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TemplateSignatureImpl::unique_parameters(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
		std::shared_ptr<Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter > >
 TemplateSignatureImpl::getOwnedParameter() const
{

    return m_ownedParameter;
}





std::shared_ptr<uml::TemplateableElement > TemplateSignatureImpl::getTemplate() const
{
//assert(m_template);
    return m_template;
}
void TemplateSignatureImpl::setTemplate(std::shared_ptr<uml::TemplateableElement> _template)
{
    m_template = _template;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > TemplateSignatureImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<uml::Element > TemplateSignatureImpl::getOwner() const
{
	return m_owner;
}
		std::shared_ptr<Union<uml::TemplateParameter> > TemplateSignatureImpl::getParameter() const
{
	return m_parameter;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TemplateSignatureImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //170
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //171
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //172
		case UmlPackage::TEMPLATESIGNATURE_OWNEDPARAMETER:
			return getOwnedParameter(); //176
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //173
		case UmlPackage::TEMPLATESIGNATURE_PARAMETER:
			return getParameter(); //174
		case UmlPackage::TEMPLATESIGNATURE_TEMPLATE:
			return getTemplate(); //175
	}
	return boost::any();
}
