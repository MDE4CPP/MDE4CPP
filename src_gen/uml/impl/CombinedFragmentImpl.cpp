#include "uml/impl/CombinedFragmentImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Gate.hpp"

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
CombinedFragmentImpl::CombinedFragmentImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_cfragmentGate.reset(new Subset<uml::Gate, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_cfragmentGate - Subset<uml::Gate, uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_operand.reset(new Subset<uml::InteractionOperand, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_operand - Subset<uml::InteractionOperand, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_cfragmentGate->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_cfragmentGate - Subset<uml::Gate, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_operand->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::InteractionOperand, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

CombinedFragmentImpl::~CombinedFragmentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CombinedFragment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:CombinedFragmentImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:CombinedFragmentImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
			}





//Additional constructor for the containments back reference
			CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:CombinedFragmentImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::Element > par_owner)
			:CombinedFragmentImpl()
			{
			    m_owner = par_owner;
			}






CombinedFragmentImpl::CombinedFragmentImpl(const CombinedFragmentImpl & obj):CombinedFragmentImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CombinedFragment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_interactionOperator = obj.getInteractionOperator();
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

	std::shared_ptr<Bag<uml::Gate>> _cfragmentGateList = obj.getCfragmentGate();
	for(std::shared_ptr<uml::Gate> _cfragmentGate : *_cfragmentGateList)
	{
		this->getCfragmentGate()->add(std::shared_ptr<uml::Gate>(std::dynamic_pointer_cast<uml::Gate>(_cfragmentGate->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_cfragmentGate" << std::endl;
	#endif
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
	std::shared_ptr<Bag<uml::InteractionOperand>> _operandList = obj.getOperand();
	for(std::shared_ptr<uml::InteractionOperand> _operand : *_operandList)
	{
		this->getOperand()->add(std::shared_ptr<uml::InteractionOperand>(std::dynamic_pointer_cast<uml::InteractionOperand>(_operand->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_operand" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

		/*Subset*/
		m_cfragmentGate->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_cfragmentGate - Subset<uml::Gate, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_operand->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::InteractionOperand, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  CombinedFragmentImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new CombinedFragmentImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> CombinedFragmentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getCombinedFragment_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void CombinedFragmentImpl::setInteractionOperator(InteractionOperatorKind _interactionOperator)
{
	m_interactionOperator = _interactionOperator;
} 

InteractionOperatorKind CombinedFragmentImpl::getInteractionOperator() const 
{
	return m_interactionOperator;
}

//*********************************
// Operations
//*********************************
bool CombinedFragmentImpl::break_(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CombinedFragmentImpl::consider_and_ignore(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CombinedFragmentImpl::opt_loop_break_neg(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Gate, uml::Element > > CombinedFragmentImpl::getCfragmentGate() const
{

    return m_cfragmentGate;
}


std::shared_ptr<Subset<uml::InteractionOperand, uml::Element > > CombinedFragmentImpl::getOperand() const
{
//assert(m_operand);
    return m_operand;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > CombinedFragmentImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > CombinedFragmentImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > CombinedFragmentImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> CombinedFragmentImpl::eContainer() const
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
boost::any CombinedFragmentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::COMBINEDFRAGMENT_EREFERENCE_CFRAGMENTGATE:
			return getCfragmentGate(); //22814
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //2284
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_COVERED:
			return getCovered(); //22810
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //2280
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //22812
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //22811
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_GENERALORDERING:
			return getGeneralOrdering(); //22813
		case UmlPackage::COMBINEDFRAGMENT_EATTRIBUTE_INTERACTIONOPERATOR:
			return getInteractionOperator(); //22815
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //2285
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //2286
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //2287
		case UmlPackage::COMBINEDFRAGMENT_EREFERENCE_OPERAND:
			return getOperand(); //22816
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //2281
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //2282
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //2283
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //2288
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //2289
	}
	return boost::any();
}

void CombinedFragmentImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _enclosingInteraction = boost::any_cast<std::shared_ptr<uml::Interaction>>(newValue);
			setEnclosingInteraction(_enclosingInteraction); //22812
			break;
		}
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
		{
			// BOOST CAST
			std::shared_ptr<uml::InteractionOperand> _enclosingOperand = boost::any_cast<std::shared_ptr<uml::InteractionOperand>>(newValue);
			setEnclosingOperand(_enclosingOperand); //22811
			break;
		}
		case UmlPackage::COMBINEDFRAGMENT_EATTRIBUTE_INTERACTIONOPERATOR:
		{
			// BOOST CAST
			InteractionOperatorKind _interactionOperator = boost::any_cast<InteractionOperatorKind>(newValue);
			setInteractionOperator(_interactionOperator); //22815
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2285
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2286
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2289
			break;
		}
	}
}
