#include "InterruptibleActivityRegionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
		m_interruptingEdge.reset(new Bag<uml::ActivityEdge>());
	
	
		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode >(m_containedNode));//(m_containedNode));
	
	
}

InterruptibleActivityRegionImpl::~InterruptibleActivityRegionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InterruptibleActivityRegion "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(const InterruptibleActivityRegionImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

			std::shared_ptr<Union<uml::ActivityEdge> > _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new 		Union<uml::ActivityEdge> (*(obj.getContainedEdge().get())));// this->getContainedEdge()->insert(this->getContainedEdge()->end(), _containedEdge->begin(), _containedEdge->end());

			std::shared_ptr<Union<uml::ActivityNode> > _containedNode = obj.getContainedNode();
	m_containedNode.reset(new 		Union<uml::ActivityNode> (*(obj.getContainedNode().get())));// this->getContainedNode()->insert(this->getContainedNode()->end(), _containedNode->begin(), _containedNode->end());

	m_inActivity  = obj.getInActivity();

		std::shared_ptr< Bag<uml::ActivityEdge> >
	 _interruptingEdge = obj.getInterruptingEdge();
	m_interruptingEdge.reset(new 	 Bag<uml::ActivityEdge> 
	(*(obj.getInterruptingEdge().get())));// this->getInterruptingEdge()->insert(this->getInterruptingEdge()->end(), _interruptingEdge->begin(), _interruptingEdge->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode > >
	 _node = obj.getNode();
	m_node.reset(new 		Subset<uml::ActivityNode, uml::ActivityNode > 
	(*(obj.getNode().get())));// this->getNode()->insert(this->getNode()->end(), _node->begin(), _node->end());

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

			std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element > >
	 _subgroup = obj.getSubgroup();
	m_subgroup.reset(new 		SubsetUnion<uml::ActivityGroup, uml::Element > 
	(*(obj.getSubgroup().get())));// this->getSubgroup()->insert(this->getSubgroup()->end(), _subgroup->begin(), _subgroup->end());

	m_superGroup  = obj.getSuperGroup();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
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
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 InterruptibleActivityRegionImpl::interrupting_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::ActivityEdge> >
 InterruptibleActivityRegionImpl::getInterruptingEdge() const
{

    return m_interruptingEdge;
}


		std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode > >
 InterruptibleActivityRegionImpl::getNode() const
{

    return m_node;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > InterruptibleActivityRegionImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > InterruptibleActivityRegionImpl::getOwner() const
{
	

	return m_owner;
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
