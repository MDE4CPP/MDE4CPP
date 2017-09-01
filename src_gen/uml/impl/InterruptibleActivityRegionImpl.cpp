#include "InterruptibleActivityRegionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Activity.hpp"

#include "ActivityEdge.hpp"

#include "ActivityGroup.hpp"

#include "ActivityNode.hpp"

#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Namespace.hpp"

#include "StringExpression.hpp"


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
			InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::shared_ptr<uml::Activity > par_inActivity)
			:InterruptibleActivityRegionImpl()
			{
			    m_inActivity = par_inActivity;
			}





//Additional constructor for the containments back reference
			InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::shared_ptr<uml::ActivityGroup > par_superGroup)
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

	std::shared_ptr< Bag<uml::ActivityEdge> > _interruptingEdge = obj.getInterruptingEdge();
	m_interruptingEdge.reset(new Bag<uml::ActivityEdge>(*(obj.getInterruptingEdge().get())));

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
	if(obj.getInActivity()!=nullptr)
	{
		m_inActivity.reset(dynamic_cast<uml::Activity*>(obj.getInActivity()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inActivity" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityNode>> _nodeList = obj.getNode();
	for(std::shared_ptr<uml::ActivityNode> _node : *_nodeList)
	{
		this->getNode()->add(std::shared_ptr<uml::ActivityNode>(dynamic_cast<uml::ActivityNode*>(_node->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_node" << std::endl;
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

ecore::EObject *  InterruptibleActivityRegionImpl::copy() const
{
	return new InterruptibleActivityRegionImpl(*this);
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
std::weak_ptr<uml::Element > InterruptibleActivityRegionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > InterruptibleActivityRegionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<Union<uml::ActivityNode> > InterruptibleActivityRegionImpl::getContainedNode() const
{
	return m_containedNode;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InterruptibleActivityRegionImpl::eGet(int featureID,  bool resolve, bool coreType) const
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
