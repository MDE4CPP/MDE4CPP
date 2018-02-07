#include "uml/impl/RegionImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/Region.hpp"

#include "uml/State.hpp"

#include "uml/StateMachine.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Transition.hpp"

#include "uml/Vertex.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RegionImpl::RegionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	

		/*Subset*/
		m_subvertex.reset(new Subset<uml::Vertex, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_transition.reset(new Subset<uml::Transition, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >()" << std::endl;
		#endif
	
	

	//Init references
	

	

	

		/*Subset*/
		m_subvertex->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_transition->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

RegionImpl::~RegionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Region "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			RegionImpl::RegionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:RegionImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			RegionImpl::RegionImpl(std::weak_ptr<uml::Element > par_owner)
			:RegionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			RegionImpl::RegionImpl(std::weak_ptr<uml::State > par_state)
			:RegionImpl()
			{
			    m_state = par_state;
			}





//Additional constructor for the containments back reference
			RegionImpl::RegionImpl(std::weak_ptr<uml::StateMachine > par_stateMachine)
			:RegionImpl()
			{
			    m_stateMachine = par_stateMachine;
			}






RegionImpl::RegionImpl(const RegionImpl & obj):RegionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Region "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_state  = obj.getState();

	m_stateMachine  = obj.getStateMachine();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	if(obj.getExtendedRegion()!=nullptr)
	{
		m_extendedRegion = std::dynamic_pointer_cast<uml::Region>(obj.getExtendedRegion()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_extendedRegion" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
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
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Vertex>> _subvertexList = obj.getSubvertex();
	for(std::shared_ptr<uml::Vertex> _subvertex : *_subvertexList)
	{
		this->getSubvertex()->add(std::shared_ptr<uml::Vertex>(std::dynamic_pointer_cast<uml::Vertex>(_subvertex->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subvertex" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Transition>> _transitionList = obj.getTransition();
	for(std::shared_ptr<uml::Transition> _transition : *_transitionList)
	{
		this->getTransition()->add(std::shared_ptr<uml::Transition>(std::dynamic_pointer_cast<uml::Transition>(_transition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_transition" << std::endl;
	#endif

		/*Subset*/
		m_subvertex->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_transition->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  RegionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new RegionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> RegionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRegion();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool RegionImpl::belongsToPSM() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::StateMachine> RegionImpl::containingStateMachine() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::deep_history_vertex(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::initial_vertex(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::owned(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Classifier> RegionImpl::redefinitionContext() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::shallow_history_vertex(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Region > RegionImpl::getExtendedRegion() const
{

    return m_extendedRegion;
}
void RegionImpl::setExtendedRegion(std::shared_ptr<uml::Region> _extendedRegion)
{
    m_extendedRegion = _extendedRegion;
}

std::weak_ptr<uml::State > RegionImpl::getState() const
{

    return m_state;
}
void RegionImpl::setState(std::shared_ptr<uml::State> _state)
{
    m_state = _state;
}

std::weak_ptr<uml::StateMachine > RegionImpl::getStateMachine() const
{

    return m_stateMachine;
}
void RegionImpl::setStateMachine(std::shared_ptr<uml::StateMachine> _stateMachine)
{
    m_stateMachine = _stateMachine;
}

std::shared_ptr<Subset<uml::Vertex, uml::NamedElement > > RegionImpl::getSubvertex() const
{

    return m_subvertex;
}


std::shared_ptr<Subset<uml::Transition, uml::NamedElement > > RegionImpl::getTransition() const
{

    return m_transition;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement> > RegionImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > RegionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > RegionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > RegionImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > RegionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > RegionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ecore::EObject> RegionImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_state.lock())
	{
		return wp;
	}

	if(auto wp = m_stateMachine.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RegionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //624
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //620
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //6211
		case UmlPackage::REGION_EXTENDEDREGION:
			return getExtendedRegion(); //6219
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //6214
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //6210
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //6215
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //625
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //626
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //627
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //621
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //622
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //6213
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //6210
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //623
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //6212
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //628
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //6211
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //6212
		case UmlPackage::REGION_STATE:
			return getState(); //6220
		case UmlPackage::REGION_STATEMACHINE:
			return getStateMachine(); //6221
		case UmlPackage::REGION_SUBVERTEX:
			return getSubvertex(); //6223
		case UmlPackage::REGION_TRANSITION:
			return getTransition(); //6222
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //629
	}
	return boost::any();
}

void RegionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::REGION_EXTENDEDREGION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Region> _extendedRegion = boost::any_cast<std::shared_ptr<uml::Region>>(newValue);
			setExtendedRegion(_extendedRegion); //6219
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //6210
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //625
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //626
			break;
		}
		case UmlPackage::REGION_STATE:
		{
			// BOOST CAST
			std::shared_ptr<uml::State> _state = boost::any_cast<std::shared_ptr<uml::State>>(newValue);
			setState(_state); //6220
			break;
		}
		case UmlPackage::REGION_STATEMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StateMachine> _stateMachine = boost::any_cast<std::shared_ptr<uml::StateMachine>>(newValue);
			setStateMachine(_stateMachine); //6221
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //629
			break;
		}
	}
}
