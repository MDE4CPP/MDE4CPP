#include "uml/impl/InterruptibleActivityRegionImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Activity.hpp"

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/StringExpression.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_interruptingEdge.reset(new Bag<uml::ActivityEdge>());
	
	

		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >()" << std::endl;
		#endif
	
	

	//Init references
	
	

		/*Subset*/
		m_node->initSubset(m_containedNode);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >(m_containedNode)" << std::endl;
		#endif
	
	
}

InterruptibleActivityRegionImpl::~InterruptibleActivityRegionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InterruptibleActivityRegion "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::Activity > par_inActivity)
			:InterruptibleActivityRegionImpl()
			{
			    m_inActivity = par_inActivity;
			}





//Additional constructor for the containments back reference
			InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InterruptibleActivityRegionImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::Element > par_owner)
			:InterruptibleActivityRegionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup)
			:InterruptibleActivityRegionImpl()
			{
			    m_superGroup = par_superGroup;
			}






InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(const InterruptibleActivityRegionImpl & obj):InterruptibleActivityRegionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InterruptibleActivityRegion "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::ActivityEdge> > _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new Union<uml::ActivityEdge>(*(obj.getContainedEdge().get())));

	std::shared_ptr<Union<uml::ActivityNode> > _containedNode = obj.getContainedNode();
	m_containedNode.reset(new Union<uml::ActivityNode>(*(obj.getContainedNode().get())));

	m_inActivity  = obj.getInActivity();

	std::shared_ptr< Bag<uml::ActivityEdge> > _interruptingEdge = obj.getInterruptingEdge();
	m_interruptingEdge.reset(new Bag<uml::ActivityEdge>(*(obj.getInterruptingEdge().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_superGroup  = obj.getSuperGroup();


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
	std::shared_ptr<Bag<uml::ActivityNode>> _nodeList = obj.getNode();
	for(std::shared_ptr<uml::ActivityNode> _node : *_nodeList)
	{
		this->getNode()->add(std::shared_ptr<uml::ActivityNode>(std::dynamic_pointer_cast<uml::ActivityNode>(_node->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_node" << std::endl;
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

std::shared_ptr<ecore::EObject>  InterruptibleActivityRegionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new InterruptibleActivityRegionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> InterruptibleActivityRegionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInterruptibleActivityRegion();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InterruptibleActivityRegionImpl::interrupting_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<uml::ActivityEdge> > InterruptibleActivityRegionImpl::getInterruptingEdge() const
{

    return m_interruptingEdge;
}


std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode > > InterruptibleActivityRegionImpl::getNode() const
{

    return m_node;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityNode> > InterruptibleActivityRegionImpl::getContainedNode() const
{
	return m_containedNode;
}
std::shared_ptr<Union<uml::Element> > InterruptibleActivityRegionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InterruptibleActivityRegionImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> InterruptibleActivityRegionImpl::eContainer() const
{
	if(auto wp = m_inActivity.lock())
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

	if(auto wp = m_superGroup.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InterruptibleActivityRegionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1114
		case UmlPackage::ACTIVITYGROUP_CONTAINEDEDGE:
			return getContainedEdge(); //11110
		case UmlPackage::ACTIVITYGROUP_CONTAINEDNODE:
			return getContainedNode(); //11111
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1110
		case UmlPackage::ACTIVITYGROUP_INACTIVITY:
			return getInActivity(); //11112
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_INTERRUPTINGEDGE:
			return getInterruptingEdge(); //11115
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1115
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1116
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1117
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_NODE:
			return getNode(); //11116
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1111
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1112
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1113
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1118
		case UmlPackage::ACTIVITYGROUP_SUBGROUP:
			return getSubgroup(); //11113
		case UmlPackage::ACTIVITYGROUP_SUPERGROUP:
			return getSuperGroup(); //11114
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1119
	}
	return boost::any();
}

void InterruptibleActivityRegionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYGROUP_INACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _inActivity = boost::any_cast<std::shared_ptr<uml::Activity>>(newValue);
			setInActivity(_inActivity); //11112
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1115
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1116
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1119
			break;
		}
	}
}
