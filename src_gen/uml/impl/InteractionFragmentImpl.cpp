#include "InteractionFragmentImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "GeneralOrdering.hpp"

#include "Interaction.hpp"

#include "InteractionOperand.hpp"

#include "Lifeline.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "StringExpression.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionFragmentImpl::InteractionFragmentImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_covered.reset(new Bag<uml::Lifeline>());
	
	

	

	

		/*Subset*/
		m_generalOrdering.reset(new Subset<uml::GeneralOrdering, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
	
	

	

	

		/*Subset*/
		m_generalOrdering->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

InteractionFragmentImpl::~InteractionFragmentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionFragment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:InteractionFragmentImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:InteractionFragmentImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
			}






InteractionFragmentImpl::InteractionFragmentImpl(const InteractionFragmentImpl & obj):InteractionFragmentImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionFragment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::Lifeline> > _covered = obj.getCovered();
	m_covered.reset(new Bag<uml::Lifeline>(*(obj.getCovered().get())));

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	m_owner  = obj.getOwner();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrderingList = obj.getGeneralOrdering();
	for(std::shared_ptr<uml::GeneralOrdering> _generalOrdering : *_generalOrderingList)
	{
		this->getGeneralOrdering()->add(std::shared_ptr<uml::GeneralOrdering>(dynamic_cast<uml::GeneralOrdering*>(_generalOrdering->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalOrdering" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

		/*Subset*/
		m_generalOrdering->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

}

ecore::EObject *  InteractionFragmentImpl::copy() const
{
	return new InteractionFragmentImpl(*this);
}

std::shared_ptr<ecore::EClass> InteractionFragmentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionFragment();
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
std::shared_ptr< Bag<uml::Lifeline> > InteractionFragmentImpl::getCovered() const
{

    return m_covered;
}


std::weak_ptr<uml::Interaction > InteractionFragmentImpl::getEnclosingInteraction() const
{

    return m_enclosingInteraction;
}
void InteractionFragmentImpl::setEnclosingInteraction(std::shared_ptr<uml::Interaction> _enclosingInteraction)
{
    m_enclosingInteraction = _enclosingInteraction;
}

std::weak_ptr<uml::InteractionOperand > InteractionFragmentImpl::getEnclosingOperand() const
{

    return m_enclosingOperand;
}
void InteractionFragmentImpl::setEnclosingOperand(std::shared_ptr<uml::InteractionOperand> _enclosingOperand)
{
    m_enclosingOperand = _enclosingOperand;
}

std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element > > InteractionFragmentImpl::getGeneralOrdering() const
{

    return m_generalOrdering;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Namespace > InteractionFragmentImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > InteractionFragmentImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InteractionFragmentImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InteractionFragmentImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2124
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //21210
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2120
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //21212
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //21211
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //21213
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2125
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2126
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2127
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2121
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2122
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2123
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2128
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2129
	}
	return boost::any();
}
