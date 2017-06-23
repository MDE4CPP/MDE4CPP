#include "ControlFlowImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ControlFlowImpl::ControlFlowImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

ControlFlowImpl::~ControlFlowImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ControlFlow "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ControlFlowImpl::ControlFlowImpl(const ControlFlowImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_activity  = obj.getActivity();

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

			std::shared_ptr<Union<uml::ActivityGroup> > _inGroup = obj.getInGroup();
	m_inGroup.reset(new 		Union<uml::ActivityGroup> (*(obj.getInGroup().get())));// this->getInGroup()->insert(this->getInGroup()->end(), _inGroup->begin(), _inGroup->end());

			std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup > >
	 _inPartition = obj.getInPartition();
	m_inPartition.reset(new 		Subset<uml::ActivityPartition, uml::ActivityGroup > 
	(*(obj.getInPartition().get())));// this->getInPartition()->insert(this->getInPartition()->end(), _inPartition->begin(), _inPartition->end());

	m_inStructuredNode  = obj.getInStructuredNode();

	m_interrupts  = obj.getInterrupts();

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

			std::shared_ptr<Subset<uml::ActivityEdge, uml::RedefinableElement > >
	 _redefinedEdge = obj.getRedefinedEdge();
	m_redefinedEdge.reset(new 		Subset<uml::ActivityEdge, uml::RedefinableElement > 
	(*(obj.getRedefinedEdge().get())));// this->getRedefinedEdge()->insert(this->getRedefinedEdge()->end(), _redefinedEdge->begin(), _redefinedEdge->end());

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));// this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));// this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

	m_source  = obj.getSource();

	m_target  = obj.getTarget();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getGuard()!=nullptr)
	{
		m_guard.reset(dynamic_cast<uml::ValueSpecification*>(obj.getGuard()->copy()));
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
	if(obj.getWeight()!=nullptr)
	{
		m_weight.reset(dynamic_cast<uml::ValueSpecification*>(obj.getWeight()->copy()));
	}
}

ecore::EObject *  ControlFlowImpl::copy() const
{
	return new ControlFlowImpl(*this);
}

std::shared_ptr<ecore::EClass> ControlFlowImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getControlFlow();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ControlFlowImpl::object_nodes(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
std::shared_ptr<uml::Element > ControlFlowImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ControlFlowImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
		std::shared_ptr<Union<uml::ActivityGroup> > ControlFlowImpl::getInGroup() const
{
	

	return m_inGroup;
}
		std::shared_ptr<Union<uml::Element> > ControlFlowImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ControlFlowImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYEDGE_ACTIVITY:
			return getActivity(); //18513
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1854
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1850
		case UmlPackage::ACTIVITYEDGE_GUARD:
			return getGuard(); //18514
		case UmlPackage::ACTIVITYEDGE_INGROUP:
			return getInGroup(); //18522
		case UmlPackage::ACTIVITYEDGE_INPARTITION:
			return getInPartition(); //18515
		case UmlPackage::ACTIVITYEDGE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //18517
		case UmlPackage::ACTIVITYEDGE_INTERRUPTS:
			return getInterrupts(); //18516
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //18510
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1855
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1856
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1857
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1851
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1852
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1853
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1858
		case UmlPackage::ACTIVITYEDGE_REDEFINEDEDGE:
			return getRedefinedEdge(); //18520
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //18511
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //18512
		case UmlPackage::ACTIVITYEDGE_SOURCE:
			return getSource(); //18519
		case UmlPackage::ACTIVITYEDGE_TARGET:
			return getTarget(); //18518
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1859
		case UmlPackage::ACTIVITYEDGE_WEIGHT:
			return getWeight(); //18521
	}
	return boost::any();
}
