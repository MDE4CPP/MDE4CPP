#include "SlotImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
SlotImpl::SlotImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	if( m_value == nullptr)
	{
		m_value = new std::vector<uml::ValueSpecification * >();
	}
}

SlotImpl::~SlotImpl()
{
	if(m_value!=nullptr)
	{
		for(auto c :*m_value)
		{
			delete(c);
			c = 0;
		}
	}
	
}

SlotImpl::SlotImpl(const SlotImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_definingFeature  = obj.getDefiningFeature();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningInstance  = obj.getOwningInstance();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::ValueSpecification * 	_value : *obj.getValue())
	{
		this->getValue()->push_back(dynamic_cast<uml::ValueSpecification * >(_value->copy()));
	}
}

ecore::EObject *  SlotImpl::copy() const
{
	return new SlotImpl(*this);
}

ecore::EClass* SlotImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getSlot();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
uml::StructuralFeature *  SlotImpl::getDefiningFeature() const
{
	//assert(m_definingFeature);
	return m_definingFeature;
}
void SlotImpl::setDefiningFeature(uml::StructuralFeature *  _definingFeature)
{
	m_definingFeature = _definingFeature;
}

uml::InstanceSpecification *  SlotImpl::getOwningInstance() const
{
	//assert(m_owningInstance);
	return m_owningInstance;
}
void SlotImpl::setOwningInstance(uml::InstanceSpecification *  _owningInstance)
{
	m_owningInstance = _owningInstance;
}

std::vector<uml::ValueSpecification * > *  SlotImpl::getValue() const
{
	
	return m_value;
}


//*********************************
// Union Getter
//*********************************
uml::Element *  SlotImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getOwningInstance()!=nullptr)
	{
		_owner = getOwningInstance();
	}

	return _owner;
}
std::vector<uml::Element * > *  SlotImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  value = (std::vector<uml::Element * > * ) getValue();
	_ownedElement->insert(_ownedElement->end(), value->begin(), value->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any SlotImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::SLOT_DEFININGFEATURE:
			return getDefiningFeature(); //804
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //800
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //801
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //802
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //803
		case UmlPackage::SLOT_OWNINGINSTANCE:
			return getOwningInstance(); //806
		case UmlPackage::SLOT_VALUE:
			return getValue(); //805
	}
	return boost::any();
}
