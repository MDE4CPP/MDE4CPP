#include "uml/impl/VertexImpl.hpp"
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

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Region.hpp"

#include "uml/State.hpp"

#include "uml/StateMachine.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Transition.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
VertexImpl::VertexImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_incoming.reset(new Bag<uml::Transition>());
	
	

		m_outgoing.reset(new Bag<uml::Transition>());
	
	

	//Init references
	

	
	

	
	
}

VertexImpl::~VertexImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Vertex "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			VertexImpl::VertexImpl(std::weak_ptr<uml::Region > par_container)
			:VertexImpl()
			{
			    m_container = par_container;
			}





//Additional constructor for the containments back reference
			VertexImpl::VertexImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:VertexImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			VertexImpl::VertexImpl(std::weak_ptr<uml::Element > par_owner)
			:VertexImpl()
			{
			    m_owner = par_owner;
			}






VertexImpl::VertexImpl(const VertexImpl & obj):VertexImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Vertex "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_container  = obj.getContainer();

	std::shared_ptr< Bag<uml::Transition> > _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::Transition>(*(obj.getIncoming().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr< Bag<uml::Transition> > _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::Transition>(*(obj.getOutgoing().get())));

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

std::shared_ptr<ecore::EObject>  VertexImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new VertexImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> VertexImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getVertex();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::StateMachine> VertexImpl::containingStateMachine() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Transition> > VertexImpl::getIncomings() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Transition> > VertexImpl::getOutgoings() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool VertexImpl::isContainedInRegion(std::shared_ptr<uml::Region>  r) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool VertexImpl::isContainedInState(std::shared_ptr<uml::State>  s) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::Region > VertexImpl::getContainer() const
{

    return m_container;
}
void VertexImpl::setContainer(std::shared_ptr<uml::Region> _container)
{
    m_container = _container;
}

std::shared_ptr< Bag<uml::Transition> > VertexImpl::getIncoming() const
{

    return m_incoming;
}


std::shared_ptr< Bag<uml::Transition> > VertexImpl::getOutgoing() const
{

    return m_outgoing;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > VertexImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > VertexImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > VertexImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> VertexImpl::eContainer() const
{
	if(auto wp = m_container.lock())
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
boost::any VertexImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //614
		case UmlPackage::VERTEX_CONTAINER:
			return getContainer(); //6110
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //610
		case UmlPackage::VERTEX_INCOMING:
			return getIncoming(); //6111
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //615
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //616
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //617
		case UmlPackage::VERTEX_OUTGOING:
			return getOutgoing(); //6112
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //611
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //612
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //613
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //618
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //619
	}
	return boost::any();
}

void VertexImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::VERTEX_CONTAINER:
		{
			// BOOST CAST
			std::shared_ptr<uml::Region> _container = boost::any_cast<std::shared_ptr<uml::Region>>(newValue);
			setContainer(_container); //6110
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //615
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //616
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //619
			break;
		}
	}
}
