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
	// Reference Members
	//*********************************
	
	
}

ObjectFlowImpl::~ObjectFlowImpl()
{
	
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

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::ActivityGroup * > *  _inGroup = obj.getInGroup();
	this->getInGroup()->insert(this->getInGroup()->end(), _inGroup->begin(), _inGroup->end());
	delete(_inGroup);

	std::vector<uml::ActivityPartition * > *  _inPartition = obj.getInPartition();
	this->getInPartition()->insert(this->getInPartition()->end(), _inPartition->begin(), _inPartition->end());

	m_inStructuredNode  = obj.getInStructuredNode();

	m_interrupts  = obj.getInterrupts();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::ActivityEdge * > *  _redefinedEdge = obj.getRedefinedEdge();
	this->getRedefinedEdge()->insert(this->getRedefinedEdge()->end(), _redefinedEdge->begin(), _redefinedEdge->end());

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	m_selection  = obj.getSelection();

	m_source  = obj.getSource();

	m_target  = obj.getTarget();

	m_transformation  = obj.getTransformation();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getGuard()!=nullptr)
	{
		m_guard = dynamic_cast<uml::ValueSpecification * >(obj.getGuard()->copy());
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	if(obj.getWeight()!=nullptr)
	{
		m_weight = dynamic_cast<uml::ValueSpecification * >(obj.getWeight()->copy());
	}
}

ecore::EObject *  ObjectFlowImpl::copy() const
{
	return new ObjectFlowImpl(*this);
}

ecore::EClass* ObjectFlowImpl::eStaticClass() const
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
bool ObjectFlowImpl::compatible_types(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::input_and_output_parameter(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::is_multicast_or_is_multireceive(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::no_executable_nodes(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::same_upper_bounds(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::selection_behavior(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::target(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::transformation_behavior(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Behavior *  ObjectFlowImpl::getSelection() const
{
	
	return m_selection;
}
void ObjectFlowImpl::setSelection(uml::Behavior *  _selection)
{
	m_selection = _selection;
}

uml::Behavior *  ObjectFlowImpl::getTransformation() const
{
	
	return m_transformation;
}
void ObjectFlowImpl::setTransformation(uml::Behavior *  _transformation)
{
	m_transformation = _transformation;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  ObjectFlowImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getActivity()!=nullptr)
	{
		_owner = getActivity();
	}
	if(getInStructuredNode()!=nullptr)
	{
		_owner = getInStructuredNode();
	}
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::RedefinableElement * > *  ObjectFlowImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedEdge = (std::vector<uml::RedefinableElement * > * ) getRedefinedEdge();
	_redefinedElement->insert(_redefinedElement->end(), redefinedEdge->begin(), redefinedEdge->end());


	return _redefinedElement;
}
std::vector<uml::ActivityGroup * > *  ObjectFlowImpl::getInGroup() const
{
	std::vector<uml::ActivityGroup * > *  _inGroup =  new std::vector<uml::ActivityGroup * >() ;
	
	std::vector<uml::ActivityGroup * > *  inPartition = (std::vector<uml::ActivityGroup * > * ) getInPartition();
	_inGroup->insert(_inGroup->end(), inPartition->begin(), inPartition->end());

	_inGroup->push_back(getInStructuredNode());

	return _inGroup;
}
std::vector<uml::Element * > *  ObjectFlowImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getGuard());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getWeight());

	return _ownedElement;
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
