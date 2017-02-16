#include "OccurrenceSpecificationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_toAfter == nullptr)
	{
		m_toAfter = new std::vector<uml::GeneralOrdering * >();
	}
	if( m_toBefore == nullptr)
	{
		m_toBefore = new std::vector<uml::GeneralOrdering * >();
	}
}

OccurrenceSpecificationImpl::~OccurrenceSpecificationImpl()
{
	if(m_toAfter!=nullptr)
	{
		delete(m_toAfter);
	 	m_toAfter = nullptr;
	}
	if(m_toBefore!=nullptr)
	{
		delete(m_toBefore);
	 	m_toBefore = nullptr;
	}
	
}

OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(const OccurrenceSpecificationImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::Lifeline * > *  _covered = obj.getCovered();
	this->getCovered()->insert(this->getCovered()->end(), _covered->begin(), _covered->end());

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::GeneralOrdering * > *  _toAfter = obj.getToAfter();
	this->getToAfter()->insert(this->getToAfter()->end(), _toAfter->begin(), _toAfter->end());

	std::vector<uml::GeneralOrdering * > *  _toBefore = obj.getToBefore();
	this->getToBefore()->insert(this->getToBefore()->end(), _toBefore->begin(), _toBefore->end());


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::GeneralOrdering * 	_generalOrdering : *obj.getGeneralOrdering())
	{
		this->getGeneralOrdering()->push_back(dynamic_cast<uml::GeneralOrdering * >(_generalOrdering->copy()));
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

ecore::EObject *  OccurrenceSpecificationImpl::copy() const
{
	return new OccurrenceSpecificationImpl(*this);
}

ecore::EClass* OccurrenceSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getOccurrenceSpecification();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************


void OccurrenceSpecificationImpl::setCovered(uml::Lifeline *  value) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::GeneralOrdering * > *  OccurrenceSpecificationImpl::getToAfter() const
{
	
	return m_toAfter;
}


std::vector<uml::GeneralOrdering * > *  OccurrenceSpecificationImpl::getToBefore() const
{
	
	return m_toBefore;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  OccurrenceSpecificationImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  generalOrdering = (std::vector<uml::Element * > * ) getGeneralOrdering();
	_ownedElement->insert(_ownedElement->end(), generalOrdering->begin(), generalOrdering->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Namespace *  OccurrenceSpecificationImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getEnclosingInteraction()!=nullptr)
	{
		_namespace = getEnclosingInteraction();
	}
	if(getEnclosingOperand()!=nullptr)
	{
		_namespace = getEnclosingOperand();
	}

	return _namespace;
}
uml::Element *  OccurrenceSpecificationImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OccurrenceSpecificationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2214
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //22110
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2210
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //22112
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //22111
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //22113
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2215
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2216
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2217
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2211
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2212
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2213
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2218
		case UmlPackage::OCCURRENCESPECIFICATION_TOAFTER:
			return getToAfter(); //22114
		case UmlPackage::OCCURRENCESPECIFICATION_TOBEFORE:
			return getToBefore(); //22115
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2219
	}
	return boost::any();
}
