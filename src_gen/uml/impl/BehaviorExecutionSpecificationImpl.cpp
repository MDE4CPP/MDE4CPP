#include "uml/impl/BehaviorExecutionSpecificationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Behavior.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ExecutionSpecification.hpp"

#include "uml/GeneralOrdering.hpp"

#include "uml/Interaction.hpp"

#include "uml/InteractionOperand.hpp"

#include "uml/Lifeline.hpp"

#include "uml/Namespace.hpp"

#include "uml/OccurrenceSpecification.hpp"

#include "uml/StringExpression.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl()
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

BehaviorExecutionSpecificationImpl::~BehaviorExecutionSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BehaviorExecutionSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:BehaviorExecutionSpecificationImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:BehaviorExecutionSpecificationImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
			}





//Additional constructor for the containments back reference
			BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:BehaviorExecutionSpecificationImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::Element > par_owner)
			:BehaviorExecutionSpecificationImpl()
			{
			    m_owner = par_owner;
			}






BehaviorExecutionSpecificationImpl::BehaviorExecutionSpecificationImpl(const BehaviorExecutionSpecificationImpl & obj):BehaviorExecutionSpecificationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BehaviorExecutionSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_behavior  = obj.getBehavior();

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::Lifeline> > _covered = obj.getCovered();
	m_covered.reset(new Bag<uml::Lifeline>(*(obj.getCovered().get())));

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	m_finish  = obj.getFinish();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_start  = obj.getStart();


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

std::shared_ptr<ecore::EObject>  BehaviorExecutionSpecificationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new BehaviorExecutionSpecificationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> BehaviorExecutionSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getBehaviorExecutionSpecification();
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
std::shared_ptr<uml::Behavior > BehaviorExecutionSpecificationImpl::getBehavior() const
{

    return m_behavior;
}
void BehaviorExecutionSpecificationImpl::setBehavior(std::shared_ptr<uml::Behavior> _behavior)
{
    m_behavior = _behavior;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > BehaviorExecutionSpecificationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > BehaviorExecutionSpecificationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > BehaviorExecutionSpecificationImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> BehaviorExecutionSpecificationImpl::eContainer() const
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
boost::any BehaviorExecutionSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIOREXECUTIONSPECIFICATION_BEHAVIOR:
			return getBehavior(); //22716
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2274
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //22710
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2270
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //22712
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //22711
		case UmlPackage::EXECUTIONSPECIFICATION_FINISH:
			return getFinish(); //22714
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //22713
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2275
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2276
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2277
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2271
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2272
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2273
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2278
		case UmlPackage::EXECUTIONSPECIFICATION_START:
			return getStart(); //22715
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2279
	}
	return boost::any();
}

void BehaviorExecutionSpecificationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIOREXECUTIONSPECIFICATION_BEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _behavior = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setBehavior(_behavior); //22716
			break;
		}
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _enclosingInteraction = boost::any_cast<std::shared_ptr<uml::Interaction>>(newValue);
			setEnclosingInteraction(_enclosingInteraction); //22712
			break;
		}
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
		{
			// BOOST CAST
			std::shared_ptr<uml::InteractionOperand> _enclosingOperand = boost::any_cast<std::shared_ptr<uml::InteractionOperand>>(newValue);
			setEnclosingOperand(_enclosingOperand); //22711
			break;
		}
		case UmlPackage::EXECUTIONSPECIFICATION_FINISH:
		{
			// BOOST CAST
			std::shared_ptr<uml::OccurrenceSpecification> _finish = boost::any_cast<std::shared_ptr<uml::OccurrenceSpecification>>(newValue);
			setFinish(_finish); //22714
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2275
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2276
			break;
		}
		case UmlPackage::EXECUTIONSPECIFICATION_START:
		{
			// BOOST CAST
			std::shared_ptr<uml::OccurrenceSpecification> _start = boost::any_cast<std::shared_ptr<uml::OccurrenceSpecification>>(newValue);
			setStart(_start); //22715
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2279
			break;
		}
	}
}
