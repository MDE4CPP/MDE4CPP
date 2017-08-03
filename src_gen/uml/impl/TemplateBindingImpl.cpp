#include "TemplateBindingImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "DirectedRelationship.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "TemplateParameterSubstitution.hpp"

#include "TemplateSignature.hpp"

#include "TemplateableElement.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateBindingImpl::TemplateBindingImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		/*Subset*/
		m_parameterSubstitution.reset(new Subset<uml::TemplateParameterSubstitution, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >()" << std::endl;
		#endif
	
	

	

	//Init references
	

		/*Subset*/
		m_parameterSubstitution->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

TemplateBindingImpl::~TemplateBindingImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateBinding "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TemplateBindingImpl::TemplateBindingImpl(const TemplateBindingImpl & obj):TemplateBindingImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateBinding "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new 		Union<uml::Element> (*(obj.getRelatedElement().get())));


    
	//Clone references with containment (deep copy)

	if(obj.getBoundElement()!=nullptr)
	{
		m_boundElement.reset(dynamic_cast<uml::TemplateableElement*>(obj.getBoundElement()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_boundElement" << std::endl;
	#endif
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
	std::shared_ptr<Bag<uml::TemplateParameterSubstitution>> _parameterSubstitutionList = obj.getParameterSubstitution();
	for(std::shared_ptr<uml::TemplateParameterSubstitution> _parameterSubstitution : *_parameterSubstitutionList)
	{
		this->getParameterSubstitution()->add(std::shared_ptr<uml::TemplateParameterSubstitution>(dynamic_cast<uml::TemplateParameterSubstitution*>(_parameterSubstitution->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_parameterSubstitution" << std::endl;
	#endif
	if(obj.getSignature()!=nullptr)
	{
		m_signature.reset(dynamic_cast<uml::TemplateSignature*>(obj.getSignature()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_signature" << std::endl;
	#endif

		/*Subset*/
		m_parameterSubstitution->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

}

ecore::EObject *  TemplateBindingImpl::copy() const
{
	return new TemplateBindingImpl(*this);
}

std::shared_ptr<ecore::EClass> TemplateBindingImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateBinding();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 TemplateBindingImpl::one_parameter_substitution(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TemplateBindingImpl::parameter_substitution_formal(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::TemplateableElement > TemplateBindingImpl::getBoundElement() const
{
//assert(m_boundElement);
    return m_boundElement;
}
void TemplateBindingImpl::setBoundElement(std::shared_ptr<uml::TemplateableElement> _boundElement)
{
    m_boundElement = _boundElement;
}

		std::shared_ptr<Subset<uml::TemplateParameterSubstitution, uml::Element > >
 TemplateBindingImpl::getParameterSubstitution() const
{

    return m_parameterSubstitution;
}


std::shared_ptr<uml::TemplateSignature > TemplateBindingImpl::getSignature() const
{
//assert(m_signature);
    return m_signature;
}
void TemplateBindingImpl::setSignature(std::shared_ptr<uml::TemplateSignature> _signature)
{
    m_signature = _signature;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 TemplateBindingImpl::getSource() const
{
	return m_source;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 TemplateBindingImpl::getTarget() const
{
	return m_target;
}
		std::shared_ptr<Union<uml::Element> > TemplateBindingImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<uml::Element > TemplateBindingImpl::getOwner() const
{
	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > TemplateBindingImpl::getRelatedElement() const
{
	return m_relatedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TemplateBindingImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEBINDING_BOUNDELEMENT:
			return getBoundElement(); //199
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //190
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //191
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //192
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //193
		case UmlPackage::TEMPLATEBINDING_PARAMETERSUBSTITUTION:
			return getParameterSubstitution(); //197
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //194
		case UmlPackage::TEMPLATEBINDING_SIGNATURE:
			return getSignature(); //198
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //195
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //196
	}
	return boost::any();
}
