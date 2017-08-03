#include "ActivityPartitionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Activity.hpp"

#include "ActivityEdge.hpp"

#include "ActivityGroup.hpp"

#include "ActivityNode.hpp"

#include "ActivityPartition.hpp"

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
ActivityPartitionImpl::ActivityPartitionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::ActivityEdge >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >()" << std::endl;
		#endif
	
	

	

		/*Subset*/
		m_subpartition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subpartition - Subset<uml::ActivityPartition, uml::ActivityGroup >()" << std::endl;
		#endif
	
	

	

	//Init references
		/*Subset*/
		m_edge->initSubset(m_containedEdge);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge >(m_containedEdge)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_node->initSubset(m_containedNode);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >(m_containedNode)" << std::endl;
		#endif
	
	

	

		/*Subset*/
		m_subpartition->initSubset(m_subgroup);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subpartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(m_subgroup)" << std::endl;
		#endif
	
	

	
}

ActivityPartitionImpl::~ActivityPartitionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityPartition "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ActivityPartitionImpl::ActivityPartitionImpl(const ActivityPartitionImpl & obj):ActivityPartitionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityPartition "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isDimension = obj.getIsDimension();
	m_isExternal = obj.getIsExternal();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));

			std::shared_ptr<Union<uml::ActivityEdge> > _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new 		Union<uml::ActivityEdge> (*(obj.getContainedEdge().get())));

			std::shared_ptr<Union<uml::ActivityNode> > _containedNode = obj.getContainedNode();
	m_containedNode.reset(new 		Union<uml::ActivityNode> (*(obj.getContainedNode().get())));

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();

	m_represents  = obj.getRepresents();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityEdge>> _edgeList = obj.getEdge();
	for(std::shared_ptr<uml::ActivityEdge> _edge : *_edgeList)
	{
		this->getEdge()->add(std::shared_ptr<uml::ActivityEdge>(dynamic_cast<uml::ActivityEdge*>(_edge->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_edge" << std::endl;
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
	std::shared_ptr<Bag<uml::ActivityPartition>> _subpartitionList = obj.getSubpartition();
	for(std::shared_ptr<uml::ActivityPartition> _subpartition : *_subpartitionList)
	{
		this->getSubpartition()->add(std::shared_ptr<uml::ActivityPartition>(dynamic_cast<uml::ActivityPartition*>(_subpartition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subpartition" << std::endl;
	#endif
	if(obj.getSuperPartition()!=nullptr)
	{
		m_superPartition.reset(dynamic_cast<uml::ActivityPartition*>(obj.getSuperPartition()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_superPartition" << std::endl;
	#endif

		/*Subset*/
		m_subpartition->initSubset(m_subgroup);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subpartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(m_subgroup)" << std::endl;
		#endif
	
	

}

ecore::EObject *  ActivityPartitionImpl::copy() const
{
	return new ActivityPartitionImpl(*this);
}

std::shared_ptr<ecore::EClass> ActivityPartitionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActivityPartition();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ActivityPartitionImpl::setIsDimension (bool _isDimension)
{
	m_isDimension = _isDimension;
} 

bool ActivityPartitionImpl::getIsDimension() const 
{
	return m_isDimension;
}

void ActivityPartitionImpl::setIsExternal (bool _isExternal)
{
	m_isExternal = _isExternal;
} 

bool ActivityPartitionImpl::getIsExternal() const 
{
	return m_isExternal;
}

//*********************************
// Operations
//*********************************
bool
 ActivityPartitionImpl::dimension_not_contained(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ActivityPartitionImpl::represents_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ActivityPartitionImpl::represents_property(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ActivityPartitionImpl::represents_property_and_is_contained(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
		std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge > >
 ActivityPartitionImpl::getEdge() const
{

    return m_edge;
}


		std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode > >
 ActivityPartitionImpl::getNode() const
{

    return m_node;
}


std::shared_ptr<uml::Element > ActivityPartitionImpl::getRepresents() const
{

    return m_represents;
}
void ActivityPartitionImpl::setRepresents(std::shared_ptr<uml::Element> _represents)
{
    m_represents = _represents;
}

		std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup > >
 ActivityPartitionImpl::getSubpartition() const
{

    return m_subpartition;
}


std::shared_ptr<uml::ActivityPartition > ActivityPartitionImpl::getSuperPartition() const
{

    return m_superPartition;
}
void ActivityPartitionImpl::setSuperPartition(std::shared_ptr<uml::ActivityPartition> _superPartition)
{
    m_superPartition = _superPartition;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > ActivityPartitionImpl::getOwner() const
{
	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > ActivityPartitionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
		std::shared_ptr<Union<uml::ActivityNode> > ActivityPartitionImpl::getContainedNode() const
{
	return m_containedNode;
}
std::shared_ptr<uml::ActivityGroup > ActivityPartitionImpl::getSuperGroup() const
{
	return m_superGroup;
}
		std::shared_ptr<Union<uml::ActivityEdge> > ActivityPartitionImpl::getContainedEdge() const
{
	return m_containedEdge;
}
		std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element > >
 ActivityPartitionImpl::getSubgroup() const
{
	return m_subgroup;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityPartitionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1094
		case UmlPackage::ACTIVITYGROUP_CONTAINEDEDGE:
			return getContainedEdge(); //10910
		case UmlPackage::ACTIVITYGROUP_CONTAINEDNODE:
			return getContainedNode(); //10911
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1090
		case UmlPackage::ACTIVITYPARTITION_EDGE:
			return getEdge(); //10921
		case UmlPackage::ACTIVITYGROUP_INACTIVITY:
			return getInActivity(); //10912
		case UmlPackage::ACTIVITYPARTITION_ISDIMENSION:
			return getIsDimension(); //10915
		case UmlPackage::ACTIVITYPARTITION_ISEXTERNAL:
			return getIsExternal(); //10916
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1095
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1096
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1097
		case UmlPackage::ACTIVITYPARTITION_NODE:
			return getNode(); //10917
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1091
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1092
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1093
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1098
		case UmlPackage::ACTIVITYPARTITION_REPRESENTS:
			return getRepresents(); //10918
		case UmlPackage::ACTIVITYGROUP_SUBGROUP:
			return getSubgroup(); //10913
		case UmlPackage::ACTIVITYPARTITION_SUBPARTITION:
			return getSubpartition(); //10919
		case UmlPackage::ACTIVITYGROUP_SUPERGROUP:
			return getSuperGroup(); //10914
		case UmlPackage::ACTIVITYPARTITION_SUPERPARTITION:
			return getSuperPartition(); //10920
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1099
	}
	return boost::any();
}
