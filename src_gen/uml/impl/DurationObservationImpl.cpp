#include "DurationObservationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DurationObservationImpl::DurationObservationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_event == nullptr)
	{
		m_event = new std::vector<uml::NamedElement * >();
	}
}

DurationObservationImpl::~DurationObservationImpl()
{
	if(m_event!=nullptr)
	{
		delete(m_event);
	 	m_event = nullptr;
	}
	
}

DurationObservationImpl::DurationObservationImpl(const DurationObservationImpl & obj)
{
	//create copy of all Attributes
	m_firstEvent = obj.getFirstEvent();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::NamedElement * > *  _event = obj.getEvent();
	this->getEvent()->insert(this->getEvent()->end(), _event->begin(), _event->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

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

ecore::EObject *  DurationObservationImpl::copy() const
{
	return new DurationObservationImpl(*this);
}

ecore::EClass* DurationObservationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDurationObservation();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void DurationObservationImpl::setFirstEvent (std::vector<bool> *  _firstEvent)
{
	m_firstEvent = _firstEvent;
} 

std::vector<bool> *  DurationObservationImpl::getFirstEvent() const 
{
	return m_firstEvent;
}

//*********************************
// Operations
//*********************************
bool DurationObservationImpl::first_event_multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::NamedElement * > *  DurationObservationImpl::getEvent() const
{
	//assert(m_event);
	return m_event;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  DurationObservationImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  DurationObservationImpl::getOwner() const
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DurationObservationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2474
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2470
		case UmlPackage::DURATIONOBSERVATION_EVENT:
			return getEvent(); //24712
		case UmlPackage::DURATIONOBSERVATION_FIRSTEVENT:
			return getFirstEvent(); //24713
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2475
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2476
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2477
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2471
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2472
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2473
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2474
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2478
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2475
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2479
	}
	return boost::any();
}
