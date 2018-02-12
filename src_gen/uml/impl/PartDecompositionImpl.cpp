#include "uml/impl/PartDecompositionImpl.hpp"
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

#include "uml/InteractionOperand.hpp"

#include "uml/InteractionUse.hpp"

#include "uml/Lifeline.hpp"

#include "uml/Namespace.hpp"

#include "uml/Property.hpp"

#include "uml/StringExpression.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PartDecompositionImpl::PartDecompositionImpl()
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

PartDecompositionImpl::~PartDecompositionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PartDecomposition "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			PartDecompositionImpl::PartDecompositionImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:PartDecompositionImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			PartDecompositionImpl::PartDecompositionImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:PartDecompositionImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
			}





//Additional constructor for the containments back reference
			PartDecompositionImpl::PartDecompositionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:PartDecompositionImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			PartDecompositionImpl::PartDecompositionImpl(std::weak_ptr<uml::Element > par_owner)
			:PartDecompositionImpl()
			{
			    m_owner = par_owner;
			}






PartDecompositionImpl::PartDecompositionImpl(const PartDecompositionImpl & obj):PartDecompositionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PartDecomposition "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

}

std::shared_ptr<ecore::EObject>  PartDecompositionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new PartDecompositionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> PartDecompositionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPartDecomposition_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool PartDecompositionImpl::assume(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PartDecompositionImpl::commutativity_of_decomposition(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PartDecompositionImpl::parts_of_internal_structures(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
std::weak_ptr<uml::Namespace > PartDecompositionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > PartDecompositionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > PartDecompositionImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> PartDecompositionImpl::eContainer() const
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
boost::any PartDecompositionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONUSE_EREFERENCE_ACTUALGATE:
			return getActualGate(); //21414
		case UmlPackage::INTERACTIONUSE_EREFERENCE_ARGUMENT:
			return getArgument(); //21415
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //2144
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_COVERED:
			return getCovered(); //21410
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //2140
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //21412
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //21411
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_GENERALORDERING:
			return getGeneralOrdering(); //21413
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //2145
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //2146
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //2147
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //2141
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //2142
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //2143
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //2148
		case UmlPackage::INTERACTIONUSE_EREFERENCE_REFERSTO:
			return getRefersTo(); //21416
		case UmlPackage::INTERACTIONUSE_EREFERENCE_RETURNVALUE:
			return getReturnValue(); //21417
		case UmlPackage::INTERACTIONUSE_EREFERENCE_RETURNVALUERECIPIENT:
			return getReturnValueRecipient(); //21418
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //2149
	}
	return boost::any();
}

void PartDecompositionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _enclosingInteraction = boost::any_cast<std::shared_ptr<uml::Interaction>>(newValue);
			setEnclosingInteraction(_enclosingInteraction); //21412
			break;
		}
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
		{
			// BOOST CAST
			std::shared_ptr<uml::InteractionOperand> _enclosingOperand = boost::any_cast<std::shared_ptr<uml::InteractionOperand>>(newValue);
			setEnclosingOperand(_enclosingOperand); //21411
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2145
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2146
			break;
		}
		case UmlPackage::INTERACTIONUSE_EREFERENCE_REFERSTO:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _refersTo = boost::any_cast<std::shared_ptr<uml::Interaction>>(newValue);
			setRefersTo(_refersTo); //21416
			break;
		}
		case UmlPackage::INTERACTIONUSE_EREFERENCE_RETURNVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _returnValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setReturnValue(_returnValue); //21417
			break;
		}
		case UmlPackage::INTERACTIONUSE_EREFERENCE_RETURNVALUERECIPIENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _returnValueRecipient = boost::any_cast<std::shared_ptr<uml::Property>>(newValue);
			setReturnValueRecipient(_returnValueRecipient); //21418
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2149
			break;
		}
	}
}
