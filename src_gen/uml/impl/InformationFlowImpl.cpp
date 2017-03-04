#include "InformationFlowImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InformationFlowImpl::InformationFlowImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	m_conveyed.reset(new std::vector<std::shared_ptr<uml::Classifier>>());
	m_informationSource.reset(new std::vector<std::shared_ptr<uml::NamedElement>>());
	m_informationTarget.reset(new std::vector<std::shared_ptr<uml::NamedElement>>());
	m_realization.reset(new std::vector<std::shared_ptr<uml::Relationship>>());
	m_realizingActivityEdge.reset(new std::vector<std::shared_ptr<uml::ActivityEdge>>());
	m_realizingConnector.reset(new std::vector<std::shared_ptr<uml::Connector>>());
	m_realizingMessage.reset(new std::vector<std::shared_ptr<uml::Message>>());
}

InformationFlowImpl::~InformationFlowImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InformationFlow "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

InformationFlowImpl::InformationFlowImpl(const InformationFlowImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::Dependency>>> _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Classifier>>> _conveyed = obj.getConveyed();
	this->getConveyed()->insert(this->getConveyed()->end(), _conveyed->begin(), _conveyed->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> _informationSource = obj.getInformationSource();
	this->getInformationSource()->insert(this->getInformationSource()->end(), _informationSource->begin(), _informationSource->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> _informationTarget = obj.getInformationTarget();
	this->getInformationTarget()->insert(this->getInformationTarget()->end(), _informationTarget->begin(), _informationTarget->end());

	m_namespace  = obj.getNamespace();

	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<std::vector<std::shared_ptr<uml::Relationship>>> _realization = obj.getRealization();
	this->getRealization()->insert(this->getRealization()->end(), _realization->begin(), _realization->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityEdge>>> _realizingActivityEdge = obj.getRealizingActivityEdge();
	this->getRealizingActivityEdge()->insert(this->getRealizingActivityEdge()->end(), _realizingActivityEdge->begin(), _realizingActivityEdge->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Connector>>> _realizingConnector = obj.getRealizingConnector();
	this->getRealizingConnector()->insert(this->getRealizingConnector()->end(), _realizingConnector->begin(), _realizingConnector->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Message>>> _realizingMessage = obj.getRealizingMessage();
	this->getRealizingMessage()->insert(this->getRealizingMessage()->end(), _realizingMessage->begin(), _realizingMessage->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _relatedElement = obj.getRelatedElement();
	this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _source = obj.getSource();
	this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _target = obj.getTarget();
	this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAnnotation>>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->push_back(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  InformationFlowImpl::copy() const
{
	return new InformationFlowImpl(*this);
}

std::shared_ptr<ecore::EClass> InformationFlowImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInformationFlow();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool InformationFlowImpl::convey_classifiers(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InformationFlowImpl::must_conform(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InformationFlowImpl::sources_and_targets_kind(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<uml::Classifier>>> InformationFlowImpl::getConveyed() const
{
//assert(m_conveyed);
    return m_conveyed;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> InformationFlowImpl::getInformationSource() const
{
//assert(m_informationSource);
    return m_informationSource;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> InformationFlowImpl::getInformationTarget() const
{
//assert(m_informationTarget);
    return m_informationTarget;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::Relationship>>> InformationFlowImpl::getRealization() const
{

    return m_realization;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityEdge>>> InformationFlowImpl::getRealizingActivityEdge() const
{

    return m_realizingActivityEdge;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::Connector>>> InformationFlowImpl::getRealizingConnector() const
{

    return m_realizingConnector;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::Message>>> InformationFlowImpl::getRealizingMessage() const
{

    return m_realizingMessage;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element> InformationFlowImpl::getOwner() const
{
	std::shared_ptr<uml::Element> _owner = nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}
	if(getOwningTemplateParameter()!=nullptr)
	{
		_owner = getOwningTemplateParameter();
	}

	return _owner;
}
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> InformationFlowImpl::getOwnedElement() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement(new std::vector<std::shared_ptr<uml::Element>>()) ;
	
	_ownedElement->push_back(getNameExpression());
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> ownedComment = getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	return _ownedElement;
}
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> InformationFlowImpl::getRelatedElement() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _relatedElement(new std::vector<std::shared_ptr<uml::Element>>()) ;
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> source = getSource();
	_relatedElement->insert(_relatedElement->end(), source->begin(), source->end());
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> target = getTarget();
	_relatedElement->insert(_relatedElement->end(), target->begin(), target->end());

	return _relatedElement;
}
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> InformationFlowImpl::getSource() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _source(new std::vector<std::shared_ptr<uml::Element>>()) ;
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> informationSource = getInformationSource();
	_source->insert(_source->end(), informationSource->begin(), informationSource->end());

	return _source;
}
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> InformationFlowImpl::getTarget() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _target(new std::vector<std::shared_ptr<uml::Element>>()) ;
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> informationTarget = getInformationTarget();
	_target->insert(_target->end(), informationTarget->begin(), informationTarget->end());

	return _target;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InformationFlowImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2094
		case UmlPackage::INFORMATIONFLOW_CONVEYED:
			return getConveyed(); //20915
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2090
		case UmlPackage::INFORMATIONFLOW_INFORMATIONSOURCE:
			return getInformationSource(); //20916
		case UmlPackage::INFORMATIONFLOW_INFORMATIONTARGET:
			return getInformationTarget(); //20917
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2095
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2096
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2097
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2091
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2092
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2093
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2094
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2098
		case UmlPackage::INFORMATIONFLOW_REALIZATION:
			return getRealization(); //20918
		case UmlPackage::INFORMATIONFLOW_REALIZINGACTIVITYEDGE:
			return getRealizingActivityEdge(); //20919
		case UmlPackage::INFORMATIONFLOW_REALIZINGCONNECTOR:
			return getRealizingConnector(); //20920
		case UmlPackage::INFORMATIONFLOW_REALIZINGMESSAGE:
			return getRealizingMessage(); //20921
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //2094
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //2095
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //2096
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2095
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2099
	}
	return boost::any();
}
