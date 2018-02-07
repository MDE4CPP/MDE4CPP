#include "uml/impl/InteractionUseImpl.hpp"
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

#include "uml/Property.hpp"

#include "uml/StringExpression.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionUseImpl::InteractionUseImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_actualGate.reset(new Subset<uml::Gate, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_actualGate - Subset<uml::Gate, uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_argument.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
	
	

	

	

	

	//Init references
		/*Subset*/
		m_actualGate->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_actualGate - Subset<uml::Gate, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_argument->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	

	

	
}

InteractionUseImpl::~InteractionUseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionUse "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:InteractionUseImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:InteractionUseImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
			}





//Additional constructor for the containments back reference
			InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InteractionUseImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::Element > par_owner)
			:InteractionUseImpl()
			{
			    m_owner = par_owner;
			}






InteractionUseImpl::InteractionUseImpl(const InteractionUseImpl & obj):InteractionUseImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionUse "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	m_refersTo  = obj.getRefersTo();

	m_returnValueRecipient  = obj.getReturnValueRecipient();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Gate>> _actualGateList = obj.getActualGate();
	for(std::shared_ptr<uml::Gate> _actualGate : *_actualGateList)
	{
		this->getActualGate()->add(std::shared_ptr<uml::Gate>(std::dynamic_pointer_cast<uml::Gate>(_actualGate->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_actualGate" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ValueSpecification>> _argumentList = obj.getArgument();
	for(std::shared_ptr<uml::ValueSpecification> _argument : *_argumentList)
	{
		this->getArgument()->add(std::shared_ptr<uml::ValueSpecification>(std::dynamic_pointer_cast<uml::ValueSpecification>(_argument->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_argument" << std::endl;
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
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getReturnValue()!=nullptr)
	{
		m_returnValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getReturnValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_returnValue" << std::endl;
	#endif

		/*Subset*/
		m_actualGate->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_actualGate - Subset<uml::Gate, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_argument->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

std::shared_ptr<ecore::EObject>  InteractionUseImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new InteractionUseImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> InteractionUseImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionUse();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionUseImpl::all_lifelines(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::arguments_are_constants(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::arguments_correspond_to_parameters(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::gates_match(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::returnValueRecipient_coverage(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::returnValue_type_recipient_correspondence(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Gate, uml::Element > > InteractionUseImpl::getActualGate() const
{

    return m_actualGate;
}


std::shared_ptr<Subset<uml::ValueSpecification, uml::Element > > InteractionUseImpl::getArgument() const
{

    return m_argument;
}


std::shared_ptr<uml::Interaction > InteractionUseImpl::getRefersTo() const
{
//assert(m_refersTo);
    return m_refersTo;
}
void InteractionUseImpl::setRefersTo(std::shared_ptr<uml::Interaction> _refersTo)
{
    m_refersTo = _refersTo;
}

std::shared_ptr<uml::ValueSpecification > InteractionUseImpl::getReturnValue() const
{

    return m_returnValue;
}
void InteractionUseImpl::setReturnValue(std::shared_ptr<uml::ValueSpecification> _returnValue)
{
    m_returnValue = _returnValue;
}

std::shared_ptr<uml::Property > InteractionUseImpl::getReturnValueRecipient() const
{

    return m_returnValueRecipient;
}
void InteractionUseImpl::setReturnValueRecipient(std::shared_ptr<uml::Property> _returnValueRecipient)
{
    m_returnValueRecipient = _returnValueRecipient;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > InteractionUseImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > InteractionUseImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InteractionUseImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> InteractionUseImpl::eContainer() const
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
boost::any InteractionUseImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONUSE_ACTUALGATE:
			return getActualGate(); //21514
		case UmlPackage::INTERACTIONUSE_ARGUMENT:
			return getArgument(); //21515
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2154
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //21510
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2150
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //21512
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //21511
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //21513
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2155
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2156
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2157
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2151
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2152
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2153
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2158
		case UmlPackage::INTERACTIONUSE_REFERSTO:
			return getRefersTo(); //21516
		case UmlPackage::INTERACTIONUSE_RETURNVALUE:
			return getReturnValue(); //21517
		case UmlPackage::INTERACTIONUSE_RETURNVALUERECIPIENT:
			return getReturnValueRecipient(); //21518
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2159
	}
	return boost::any();
}

void InteractionUseImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _enclosingInteraction = boost::any_cast<std::shared_ptr<uml::Interaction>>(newValue);
			setEnclosingInteraction(_enclosingInteraction); //21512
			break;
		}
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
		{
			// BOOST CAST
			std::shared_ptr<uml::InteractionOperand> _enclosingOperand = boost::any_cast<std::shared_ptr<uml::InteractionOperand>>(newValue);
			setEnclosingOperand(_enclosingOperand); //21511
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2155
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2156
			break;
		}
		case UmlPackage::INTERACTIONUSE_REFERSTO:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _refersTo = boost::any_cast<std::shared_ptr<uml::Interaction>>(newValue);
			setRefersTo(_refersTo); //21516
			break;
		}
		case UmlPackage::INTERACTIONUSE_RETURNVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _returnValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setReturnValue(_returnValue); //21517
			break;
		}
		case UmlPackage::INTERACTIONUSE_RETURNVALUERECIPIENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _returnValueRecipient = boost::any_cast<std::shared_ptr<uml::Property>>(newValue);
			setReturnValueRecipient(_returnValueRecipient); //21518
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2159
			break;
		}
	}
}
