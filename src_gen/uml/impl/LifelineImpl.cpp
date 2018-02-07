#include "uml/impl/LifelineImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/ConnectableElement.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Interaction.hpp"

#include "uml/InteractionFragment.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/PartDecomposition.hpp"

#include "uml/StringExpression.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LifelineImpl::LifelineImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_coveredBy.reset(new Bag<uml::InteractionFragment>());
	
	

	

	

	

	

	//Init references
	
	

	

	

	

	
}

LifelineImpl::~LifelineImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Lifeline "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			LifelineImpl::LifelineImpl(std::weak_ptr<uml::Interaction > par_interaction)
			:LifelineImpl()
			{
			    m_interaction = par_interaction;
			}





//Additional constructor for the containments back reference
			LifelineImpl::LifelineImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:LifelineImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			LifelineImpl::LifelineImpl(std::weak_ptr<uml::Element > par_owner)
			:LifelineImpl()
			{
			    m_owner = par_owner;
			}






LifelineImpl::LifelineImpl(const LifelineImpl & obj):LifelineImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Lifeline "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::InteractionFragment> > _coveredBy = obj.getCoveredBy();
	m_coveredBy.reset(new Bag<uml::InteractionFragment>(*(obj.getCoveredBy().get())));

	m_decomposedAs  = obj.getDecomposedAs();

	m_interaction  = obj.getInteraction();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_represents  = obj.getRepresents();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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
	if(obj.getSelector()!=nullptr)
	{
		m_selector = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getSelector()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_selector" << std::endl;
	#endif

	
}

std::shared_ptr<ecore::EObject>  LifelineImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LifelineImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LifelineImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLifeline();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool LifelineImpl::interaction_uses_share_lifeline(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LifelineImpl::same_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LifelineImpl::selector_int_or_string(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LifelineImpl::selector_specified(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<uml::InteractionFragment> > LifelineImpl::getCoveredBy() const
{

    return m_coveredBy;
}


std::shared_ptr<uml::PartDecomposition > LifelineImpl::getDecomposedAs() const
{

    return m_decomposedAs;
}
void LifelineImpl::setDecomposedAs(std::shared_ptr<uml::PartDecomposition> _decomposedAs)
{
    m_decomposedAs = _decomposedAs;
}

std::weak_ptr<uml::Interaction > LifelineImpl::getInteraction() const
{
//assert(m_interaction);
    return m_interaction;
}
void LifelineImpl::setInteraction(std::shared_ptr<uml::Interaction> _interaction)
{
    m_interaction = _interaction;
}

std::shared_ptr<uml::ConnectableElement > LifelineImpl::getRepresents() const
{

    return m_represents;
}
void LifelineImpl::setRepresents(std::shared_ptr<uml::ConnectableElement> _represents)
{
    m_represents = _represents;
}

std::shared_ptr<uml::ValueSpecification > LifelineImpl::getSelector() const
{

    return m_selector;
}
void LifelineImpl::setSelector(std::shared_ptr<uml::ValueSpecification> _selector)
{
    m_selector = _selector;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > LifelineImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > LifelineImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > LifelineImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> LifelineImpl::eContainer() const
{
	if(auto wp = m_interaction.lock())
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
boost::any LifelineImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2134
		case UmlPackage::LIFELINE_COVEREDBY:
			return getCoveredBy(); //21314
		case UmlPackage::LIFELINE_DECOMPOSEDAS:
			return getDecomposedAs(); //21310
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2130
		case UmlPackage::LIFELINE_INTERACTION:
			return getInteraction(); //21311
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2135
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2136
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2137
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2131
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2132
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2133
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2138
		case UmlPackage::LIFELINE_REPRESENTS:
			return getRepresents(); //21312
		case UmlPackage::LIFELINE_SELECTOR:
			return getSelector(); //21313
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2139
	}
	return boost::any();
}

void LifelineImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::LIFELINE_DECOMPOSEDAS:
		{
			// BOOST CAST
			std::shared_ptr<uml::PartDecomposition> _decomposedAs = boost::any_cast<std::shared_ptr<uml::PartDecomposition>>(newValue);
			setDecomposedAs(_decomposedAs); //21310
			break;
		}
		case UmlPackage::LIFELINE_INTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _interaction = boost::any_cast<std::shared_ptr<uml::Interaction>>(newValue);
			setInteraction(_interaction); //21311
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2135
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2136
			break;
		}
		case UmlPackage::LIFELINE_REPRESENTS:
		{
			// BOOST CAST
			std::shared_ptr<uml::ConnectableElement> _represents = boost::any_cast<std::shared_ptr<uml::ConnectableElement>>(newValue);
			setRepresents(_represents); //21312
			break;
		}
		case UmlPackage::LIFELINE_SELECTOR:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _selector = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setSelector(_selector); //21313
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2139
			break;
		}
	}
}
