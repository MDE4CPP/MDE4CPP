#include "uml/impl/ControlFlowImpl.hpp"
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
ControlFlowImpl::ControlFlowImpl()
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

ControlFlowImpl::~ControlFlowImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ControlFlow "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ControlFlowImpl::ControlFlowImpl(std::weak_ptr<uml::Activity > par_activity)
			:ControlFlowImpl()
			{
			    m_activity = par_activity;
			}





//Additional constructor for the containments back reference
			ControlFlowImpl::ControlFlowImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:ControlFlowImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			ControlFlowImpl::ControlFlowImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ControlFlowImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ControlFlowImpl::ControlFlowImpl(std::weak_ptr<uml::Element > par_owner)
			:ControlFlowImpl()
			{
			    m_owner = par_owner;
			}






ControlFlowImpl::ControlFlowImpl(const ControlFlowImpl & obj):ControlFlowImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ControlFlow "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
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

	m_source  = obj.getSource();

	m_target  = obj.getTarget();


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

std::shared_ptr<ecore::EObject>  ControlFlowImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ControlFlowImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ControlFlowImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getControlFlow_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ControlFlowImpl::object_nodes(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
std::shared_ptr<Union<uml::ActivityGroup> > ControlFlowImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<Union<uml::Element> > ControlFlowImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ControlFlowImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > ControlFlowImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ecore::EObject> ControlFlowImpl::eContainer() const
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
boost::any ControlFlowImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_ACTIVITY:
			return getActivity(); //18513
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //1854
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //1850
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_GUARD:
			return getGuard(); //18514
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INGROUP:
			return getInGroup(); //18522
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INPARTITION:
			return getInPartition(); //18515
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //18517
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INTERRUPTS:
			return getInterrupts(); //18516
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //18510
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //1855
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //1856
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //1857
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //1851
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //1852
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //1853
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //1858
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_REDEFINEDEDGE:
			return getRedefinedEdge(); //18520
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //18511
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //18512
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_SOURCE:
			return getSource(); //18519
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_TARGET:
			return getTarget(); //18518
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //1859
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_WEIGHT:
			return getWeight(); //18521
	}
	return boost::any();
}

void ControlFlowImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _activity = boost::any_cast<std::shared_ptr<uml::Activity>>(newValue);
			setActivity(_activity); //18513
			break;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_GUARD:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _guard = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setGuard(_guard); //18514
			break;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = boost::any_cast<std::shared_ptr<uml::StructuredActivityNode>>(newValue);
			setInStructuredNode(_inStructuredNode); //18517
			break;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INTERRUPTS:
		{
			// BOOST CAST
			std::shared_ptr<uml::InterruptibleActivityRegion> _interrupts = boost::any_cast<std::shared_ptr<uml::InterruptibleActivityRegion>>(newValue);
			setInterrupts(_interrupts); //18516
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //18510
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1855
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1856
			break;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_SOURCE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _source = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setSource(_source); //18519
			break;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_TARGET:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _target = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setTarget(_target); //18518
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1859
			break;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_WEIGHT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _weight = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setWeight(_weight); //18521
			break;
		}
	}
}
