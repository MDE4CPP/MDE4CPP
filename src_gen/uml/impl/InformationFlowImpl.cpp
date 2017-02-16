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
	// Reference Members
	//*********************************
	if( m_conveyed == nullptr)
	{
		m_conveyed = new std::vector<uml::Classifier * >();
	}
	if( m_informationSource == nullptr)
	{
		m_informationSource = new std::vector<uml::NamedElement * >();
	}
	if( m_informationTarget == nullptr)
	{
		m_informationTarget = new std::vector<uml::NamedElement * >();
	}
	if( m_realization == nullptr)
	{
		m_realization = new std::vector<uml::Relationship * >();
	}
	if( m_realizingActivityEdge == nullptr)
	{
		m_realizingActivityEdge = new std::vector<uml::ActivityEdge * >();
	}
	if( m_realizingConnector == nullptr)
	{
		m_realizingConnector = new std::vector<uml::Connector * >();
	}
	if( m_realizingMessage == nullptr)
	{
		m_realizingMessage = new std::vector<uml::Message * >();
	}
}

InformationFlowImpl::~InformationFlowImpl()
{
	if(m_conveyed!=nullptr)
	{
		delete(m_conveyed);
	 	m_conveyed = nullptr;
	}
	if(m_informationSource!=nullptr)
	{
		delete(m_informationSource);
	 	m_informationSource = nullptr;
	}
	if(m_informationTarget!=nullptr)
	{
		delete(m_informationTarget);
	 	m_informationTarget = nullptr;
	}
	if(m_realization!=nullptr)
	{
		delete(m_realization);
	 	m_realization = nullptr;
	}
	if(m_realizingActivityEdge!=nullptr)
	{
		delete(m_realizingActivityEdge);
	 	m_realizingActivityEdge = nullptr;
	}
	if(m_realizingConnector!=nullptr)
	{
		delete(m_realizingConnector);
	 	m_realizingConnector = nullptr;
	}
	if(m_realizingMessage!=nullptr)
	{
		delete(m_realizingMessage);
	 	m_realizingMessage = nullptr;
	}
	
}

InformationFlowImpl::InformationFlowImpl(const InformationFlowImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::Classifier * > *  _conveyed = obj.getConveyed();
	this->getConveyed()->insert(this->getConveyed()->end(), _conveyed->begin(), _conveyed->end());

	std::vector<uml::NamedElement * > *  _informationSource = obj.getInformationSource();
	this->getInformationSource()->insert(this->getInformationSource()->end(), _informationSource->begin(), _informationSource->end());

	std::vector<uml::NamedElement * > *  _informationTarget = obj.getInformationTarget();
	this->getInformationTarget()->insert(this->getInformationTarget()->end(), _informationTarget->begin(), _informationTarget->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::vector<uml::Relationship * > *  _realization = obj.getRealization();
	this->getRealization()->insert(this->getRealization()->end(), _realization->begin(), _realization->end());

	std::vector<uml::ActivityEdge * > *  _realizingActivityEdge = obj.getRealizingActivityEdge();
	this->getRealizingActivityEdge()->insert(this->getRealizingActivityEdge()->end(), _realizingActivityEdge->begin(), _realizingActivityEdge->end());

	std::vector<uml::Connector * > *  _realizingConnector = obj.getRealizingConnector();
	this->getRealizingConnector()->insert(this->getRealizingConnector()->end(), _realizingConnector->begin(), _realizingConnector->end());

	std::vector<uml::Message * > *  _realizingMessage = obj.getRealizingMessage();
	this->getRealizingMessage()->insert(this->getRealizingMessage()->end(), _realizingMessage->begin(), _realizingMessage->end());

	std::vector<uml::Element * > *  _relatedElement = obj.getRelatedElement();
	this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());
	delete(_relatedElement);

	std::vector<uml::Element * > *  _source = obj.getSource();
	this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());
	delete(_source);

	std::vector<uml::Element * > *  _target = obj.getTarget();
	this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());
	delete(_target);

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  InformationFlowImpl::copy() const
{
	return new InformationFlowImpl(*this);
}

ecore::EClass* InformationFlowImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInformationFlow();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool InformationFlowImpl::convey_classifiers(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InformationFlowImpl::must_conform(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InformationFlowImpl::sources_and_targets_kind(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Classifier * > *  InformationFlowImpl::getConveyed() const
{
	//assert(m_conveyed);
	return m_conveyed;
}


std::vector<uml::NamedElement * > *  InformationFlowImpl::getInformationSource() const
{
	//assert(m_informationSource);
	return m_informationSource;
}


std::vector<uml::NamedElement * > *  InformationFlowImpl::getInformationTarget() const
{
	//assert(m_informationTarget);
	return m_informationTarget;
}


std::vector<uml::Relationship * > *  InformationFlowImpl::getRealization() const
{
	
	return m_realization;
}


std::vector<uml::ActivityEdge * > *  InformationFlowImpl::getRealizingActivityEdge() const
{
	
	return m_realizingActivityEdge;
}


std::vector<uml::Connector * > *  InformationFlowImpl::getRealizingConnector() const
{
	
	return m_realizingConnector;
}


std::vector<uml::Message * > *  InformationFlowImpl::getRealizingMessage() const
{
	
	return m_realizingMessage;
}


//*********************************
// Union Getter
//*********************************
uml::Element *  InformationFlowImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
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
std::vector<uml::Element * > *  InformationFlowImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  informationSource = (std::vector<uml::Element * > * ) getInformationSource();
	_source->insert(_source->end(), informationSource->begin(), informationSource->end());


	return _source;
}
std::vector<uml::Element * > *  InformationFlowImpl::getRelatedElement() const
{
	std::vector<uml::Element * > *  _relatedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  source = (std::vector<uml::Element * > * ) getSource();
	_relatedElement->insert(_relatedElement->end(), source->begin(), source->end());

	delete(source);
	std::vector<uml::Element * > *  target = (std::vector<uml::Element * > * ) getTarget();
	_relatedElement->insert(_relatedElement->end(), target->begin(), target->end());

	delete(target);

	return _relatedElement;
}
std::vector<uml::Element * > *  InformationFlowImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  informationTarget = (std::vector<uml::Element * > * ) getInformationTarget();
	_target->insert(_target->end(), informationTarget->begin(), informationTarget->end());


	return _target;
}
std::vector<uml::Element * > *  InformationFlowImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
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
