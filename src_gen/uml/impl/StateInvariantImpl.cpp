#include "uml/impl/StateInvariantImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/GeneralOrdering.hpp"

#include "uml/Interaction.hpp"

#include "uml/InteractionFragment.hpp"

#include "uml/InteractionOperand.hpp"

#include "uml/Lifeline.hpp"

#include "uml/Namespace.hpp"

#include "uml/StringExpression.hpp"


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





//Additional constructor for the containments back reference
			StateInvariantImpl::StateInvariantImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:StateInvariantImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			StateInvariantImpl::StateInvariantImpl(std::weak_ptr<uml::Element > par_owner)
			:StateInvariantImpl()
			{
			    m_owner = par_owner;
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

	m_namespace  = obj.getNamespace();

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
	std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrderingList = obj.getGeneralOrdering();
	for(std::shared_ptr<uml::GeneralOrdering> _generalOrdering : *_generalOrderingList)
	{
		this->getGeneralOrdering()->add(std::shared_ptr<uml::GeneralOrdering>(std::dynamic_pointer_cast<uml::GeneralOrdering>(_generalOrdering->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalOrdering" << std::endl;
	#endif
	if(obj.getInvariant()!=nullptr)
	{
		m_invariant = std::dynamic_pointer_cast<uml::Constraint>(obj.getInvariant()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_invariant" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
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

std::shared_ptr<ecore::EObject>  StateInvariantImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new StateInvariantImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> StateInvariantImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getStateInvariant_EClass();
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
std::weak_ptr<uml::Namespace > StateInvariantImpl::getNamespace() const
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


std::shared_ptr<ecore::EObject> StateInvariantImpl::eContainer() const
{
	if(auto wp = m_enclosingInteraction.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingOperand.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any StateInvariantImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //2354
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_COVERED:
			return getCovered(); //23510
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //2350
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //23512
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //23511
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_GENERALORDERING:
			return getGeneralOrdering(); //23513
		case UmlPackage::STATEINVARIANT_EREFERENCE_INVARIANT:
			return getInvariant(); //23514
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //2355
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //2356
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //2357
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //2351
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //2352
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //2353
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //2358
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //2359
	}
	return boost::any();
}

void StateInvariantImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _enclosingInteraction = boost::any_cast<std::shared_ptr<uml::Interaction>>(newValue);
			setEnclosingInteraction(_enclosingInteraction); //23512
			break;
		}
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
		{
			// BOOST CAST
			std::shared_ptr<uml::InteractionOperand> _enclosingOperand = boost::any_cast<std::shared_ptr<uml::InteractionOperand>>(newValue);
			setEnclosingOperand(_enclosingOperand); //23511
			break;
		}
		case UmlPackage::STATEINVARIANT_EREFERENCE_INVARIANT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Constraint> _invariant = boost::any_cast<std::shared_ptr<uml::Constraint>>(newValue);
			setInvariant(_invariant); //23514
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2355
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2356
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2359
			break;
		}
	}
}
