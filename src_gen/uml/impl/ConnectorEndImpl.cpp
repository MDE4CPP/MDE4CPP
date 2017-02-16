#include "ConnectorEndImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectorEndImpl::ConnectorEndImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	
}

ConnectorEndImpl::~ConnectorEndImpl()
{
	
}

ConnectorEndImpl::ConnectorEndImpl(const ConnectorEndImpl & obj)
{
	//create copy of all Attributes
	m_isOrdered = obj.getIsOrdered();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_upper = obj.getUpper();

	//copy references with now containment
	
	m_definingEnd  = obj.getDefiningEnd();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_partWithPort  = obj.getPartWithPort();

	m_role  = obj.getRole();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = dynamic_cast<uml::ValueSpecification * >(obj.getLowerValue()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = dynamic_cast<uml::ValueSpecification * >(obj.getUpperValue()->copy());
	}
}

ecore::EObject *  ConnectorEndImpl::copy() const
{
	return new ConnectorEndImpl(*this);
}

ecore::EClass* ConnectorEndImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConnectorEnd();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************


bool ConnectorEndImpl::multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorEndImpl::part_with_port_empty(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorEndImpl::role_and_part_with_port(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorEndImpl::self_part_with_port(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Property *  ConnectorEndImpl::getDefiningEnd() const
{
	
	return m_definingEnd;
}


uml::Property *  ConnectorEndImpl::getPartWithPort() const
{
	
	return m_partWithPort;
}
void ConnectorEndImpl::setPartWithPort(uml::Property *  _partWithPort)
{
	m_partWithPort = _partWithPort;
}

uml::ConnectableElement *  ConnectorEndImpl::getRole() const
{
	//assert(m_role);
	return m_role;
}
void ConnectorEndImpl::setRole(uml::ConnectableElement *  _role)
{
	m_role = _role;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ConnectorEndImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getLowerValue());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getUpperValue());

	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ConnectorEndImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CONNECTOREND_DEFININGEND:
			return getDefiningEnd(); //3110
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //310
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //314
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //315
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //316
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //317
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //311
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //312
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //313
		case UmlPackage::CONNECTOREND_PARTWITHPORT:
			return getPartWithPort(); //3111
		case UmlPackage::CONNECTOREND_ROLE:
			return getRole(); //3112
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //318
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //319
	}
	return boost::any();
}
