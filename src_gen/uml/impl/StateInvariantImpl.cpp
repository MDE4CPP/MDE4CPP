#include "StateInvariantImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Constraint.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "GeneralOrdering.hpp"

#include "Interaction.hpp"

#include "InteractionFragment.hpp"

#include "InteractionOperand.hpp"

#include "Lifeline.hpp"

#include "Namespace.hpp"

#include "StringExpression.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StateInvariantImpl::StateInvariantImpl()
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

StateInvariantImpl::~StateInvariantImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StateInvariant "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			StateInvariantImpl::StateInvariantImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:StateInvariantImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			StateInvariantImpl::StateInvariantImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:StateInvariantImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
			}






StateInvariantImpl::StateInvariantImpl(const StateInvariantImpl & obj):StateInvariantImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StateInvariant "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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
	if(obj.getInvariant()!=nullptr)
	{
		m_invariant.reset(dynamic_cast<uml::Constraint*>(obj.getInvariant()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_invariant" << std::endl;
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

	

}

ecore::EObject *  StateInvariantImpl::copy() const
{
	return new StateInvariantImpl(*this);
}

std::shared_ptr<ecore::EClass> StateInvariantImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getStateInvariant();
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
std::shared_ptr<uml::Constraint > StateInvariantImpl::getInvariant() const
{
//assert(m_invariant);
    return m_invariant;
}
void StateInvariantImpl::setInvariant(std::shared_ptr<uml::Constraint> _invariant)
{
    m_invariant = _invariant;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Namespace > StateInvariantImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > StateInvariantImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > StateInvariantImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any StateInvariantImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2354
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //23510
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2350
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //23512
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //23511
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //23513
		case UmlPackage::STATEINVARIANT_INVARIANT:
			return getInvariant(); //23514
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2355
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2356
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2357
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2351
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2352
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2353
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2358
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2359
	}
	return boost::any();
}
