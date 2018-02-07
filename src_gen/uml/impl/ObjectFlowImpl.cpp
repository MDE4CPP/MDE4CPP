#include "uml/impl/ObjectFlowImpl.hpp"
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

#include "uml/ActivityPartition.hpp"

#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/Namespace.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/ValueSpecification.hpp"


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
	//References
	

	

	//Init references
	

	
}

ObjectFlowImpl::~ObjectFlowImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectFlow "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::Activity > par_activity)
			:ObjectFlowImpl()
			{
			    m_activity = par_activity;
			}





//Additional constructor for the containments back reference
			ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:ObjectFlowImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ObjectFlowImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::Element > par_owner)
			:ObjectFlowImpl()
			{
			    m_owner = par_owner;
			}






ObjectFlowImpl::ObjectFlowImpl(const ObjectFlowImpl & obj):ObjectFlowImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectFlow "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isMulticast = obj.getIsMulticast();
	m_isMultireceive = obj.getIsMultireceive();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_activity  = obj.getActivity();

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::ActivityGroup> > _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

	m_inStructuredNode  = obj.getInStructuredNode();

	m_interrupts  = obj.getInterrupts();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_selection  = obj.getSelection();

	m_source  = obj.getSource();

	m_target  = obj.getTarget();

	m_transformation  = obj.getTransformation();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getGuard()!=nullptr)
	{
		m_guard = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getGuard()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_guard" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityPartition>> _inPartitionList = obj.getInPartition();
	for(std::shared_ptr<uml::ActivityPartition> _inPartition : *_inPartitionList)
	{
		this->getInPartition()->add(std::shared_ptr<uml::ActivityPartition>(std::dynamic_pointer_cast<uml::ActivityPartition>(_inPartition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inPartition" << std::endl;
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
	std::shared_ptr<Bag<uml::ActivityEdge>> _redefinedEdgeList = obj.getRedefinedEdge();
	for(std::shared_ptr<uml::ActivityEdge> _redefinedEdge : *_redefinedEdgeList)
	{
		this->getRedefinedEdge()->add(std::shared_ptr<uml::ActivityEdge>(std::dynamic_pointer_cast<uml::ActivityEdge>(_redefinedEdge->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedEdge" << std::endl;
	#endif
	if(obj.getWeight()!=nullptr)
	{
		m_weight = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getWeight()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_weight" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ObjectFlowImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ObjectFlowImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ObjectFlowImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getObjectFlow();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ObjectFlowImpl::setIsMulticast(bool _isMulticast)
{
	m_isMulticast = _isMulticast;
} 

bool ObjectFlowImpl::getIsMulticast() const 
{
	return m_isMulticast;
}

void ObjectFlowImpl::setIsMultireceive(bool _isMultireceive)
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
bool ObjectFlowImpl::compatible_types(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::input_and_output_parameter(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::is_multicast_or_is_multireceive(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::no_executable_nodes(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::same_upper_bounds(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::selection_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::target(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::transformation_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
std::shared_ptr<Union<uml::ActivityGroup> > ObjectFlowImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<Union<uml::Element> > ObjectFlowImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ObjectFlowImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > ObjectFlowImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ecore::EObject> ObjectFlowImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
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
boost::any ObjectFlowImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void ObjectFlowImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYEDGE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _activity = boost::any_cast<std::shared_ptr<uml::Activity>>(newValue);
			setActivity(_activity); //18813
			break;
		}
		case UmlPackage::ACTIVITYEDGE_GUARD:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _guard = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setGuard(_guard); //18814
			break;
		}
		case UmlPackage::ACTIVITYEDGE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = boost::any_cast<std::shared_ptr<uml::StructuredActivityNode>>(newValue);
			setInStructuredNode(_inStructuredNode); //18817
			break;
		}
		case UmlPackage::ACTIVITYEDGE_INTERRUPTS:
		{
			// BOOST CAST
			std::shared_ptr<uml::InterruptibleActivityRegion> _interrupts = boost::any_cast<std::shared_ptr<uml::InterruptibleActivityRegion>>(newValue);
			setInterrupts(_interrupts); //18816
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //18810
			break;
		}
		case UmlPackage::OBJECTFLOW_ISMULTICAST:
		{
			// BOOST CAST
			bool _isMulticast = boost::any_cast<bool>(newValue);
			setIsMulticast(_isMulticast); //18823
			break;
		}
		case UmlPackage::OBJECTFLOW_ISMULTIRECEIVE:
		{
			// BOOST CAST
			bool _isMultireceive = boost::any_cast<bool>(newValue);
			setIsMultireceive(_isMultireceive); //18824
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1885
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1886
			break;
		}
		case UmlPackage::OBJECTFLOW_SELECTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _selection = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setSelection(_selection); //18825
			break;
		}
		case UmlPackage::ACTIVITYEDGE_SOURCE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _source = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setSource(_source); //18819
			break;
		}
		case UmlPackage::ACTIVITYEDGE_TARGET:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _target = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setTarget(_target); //18818
			break;
		}
		case UmlPackage::OBJECTFLOW_TRANSFORMATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _transformation = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setTransformation(_transformation); //18826
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1889
			break;
		}
		case UmlPackage::ACTIVITYEDGE_WEIGHT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _weight = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setWeight(_weight); //18821
			break;
		}
	}
}
