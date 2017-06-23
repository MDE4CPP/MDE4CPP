#include "ObjectFlowImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ObjectFlowImpl::ObjectFlowImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	
	
}

ObjectFlowImpl::~ObjectFlowImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectFlow "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ObjectFlowImpl::ObjectFlowImpl(const ObjectFlowImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isMulticast = obj.getIsMulticast();
	m_isMultireceive = obj.getIsMultireceive();
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

	m_selection  = obj.getSelection();

	m_source  = obj.getSource();

	m_target  = obj.getTarget();

	m_transformation  = obj.getTransformation();


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

ecore::EObject *  ObjectFlowImpl::copy() const
{
	return new ObjectFlowImpl(*this);
}

std::shared_ptr<ecore::EClass> ObjectFlowImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getObjectFlow();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ObjectFlowImpl::setIsMulticast (bool _isMulticast)
{
	m_isMulticast = _isMulticast;
} 

bool ObjectFlowImpl::getIsMulticast() const 
{
	return m_isMulticast;
}

void ObjectFlowImpl::setIsMultireceive (bool _isMultireceive)
{
	m_isMultireceive = _isMultireceive;
} 

bool ObjectFlowImpl::getIsMultireceive() const 
{
	return m_isMultireceive;
}

//*********************************
// Operations
//*********************************
bool
 ObjectFlowImpl::compatible_types(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ObjectFlowImpl::input_and_output_parameter(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ObjectFlowImpl::is_multicast_or_is_multireceive(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ObjectFlowImpl::no_executable_nodes(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ObjectFlowImpl::same_upper_bounds(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ObjectFlowImpl::selection_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ObjectFlowImpl::target(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ObjectFlowImpl::transformation_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Behavior > ObjectFlowImpl::getSelection() const
{

    return m_selection;
}
void ObjectFlowImpl::setSelection(std::shared_ptr<uml::Behavior> _selection)
{
    m_selection = _selection;
}

std::shared_ptr<uml::Behavior > ObjectFlowImpl::getTransformation() const
{

    return m_transformation;
}
void ObjectFlowImpl::setTransformation(std::shared_ptr<uml::Behavior> _transformation)
{
    m_transformation = _transformation;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > ObjectFlowImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ObjectFlowImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
		std::shared_ptr<Union<uml::Element> > ObjectFlowImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::ActivityGroup> > ObjectFlowImpl::getInGroup() const
{
	

	return m_inGroup;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ObjectFlowImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYEDGE_ACTIVITY:
			return getActivity(); //18813
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1884
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1880
		case UmlPackage::ACTIVITYEDGE_GUARD:
			return getGuard(); //18814
		case UmlPackage::ACTIVITYEDGE_INGROUP:
			return getInGroup(); //18822
		case UmlPackage::ACTIVITYEDGE_INPARTITION:
			return getInPartition(); //18815
		case UmlPackage::ACTIVITYEDGE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //18817
		case UmlPackage::ACTIVITYEDGE_INTERRUPTS:
			return getInterrupts(); //18816
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //18810
		case UmlPackage::OBJECTFLOW_ISMULTICAST:
			return getIsMulticast(); //18823
		case UmlPackage::OBJECTFLOW_ISMULTIRECEIVE:
			return getIsMultireceive(); //18824
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1885
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1886
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1887
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1881
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1882
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1883
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1888
		case UmlPackage::ACTIVITYEDGE_REDEFINEDEDGE:
			return getRedefinedEdge(); //18820
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //18811
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //18812
		case UmlPackage::OBJECTFLOW_SELECTION:
			return getSelection(); //18825
		case UmlPackage::ACTIVITYEDGE_SOURCE:
			return getSource(); //18819
		case UmlPackage::ACTIVITYEDGE_TARGET:
			return getTarget(); //18818
		case UmlPackage::OBJECTFLOW_TRANSFORMATION:
			return getTransformation(); //18826
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1889
		case UmlPackage::ACTIVITYEDGE_WEIGHT:
			return getWeight(); //18821
	}
	return boost::any();
}
