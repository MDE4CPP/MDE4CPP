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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
		/*Subset*/
		m_value.reset(new Subset<uml::ValueSpecification, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
}

SlotImpl::~SlotImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Slot "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

SlotImpl::SlotImpl(const SlotImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_definingFeature  = obj.getDefiningFeature();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_owningInstance  = obj.getOwningInstance();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<Bag<uml::ValueSpecification>> _valueList = obj.getValue();
	for(std::shared_ptr<uml::ValueSpecification> _value : *_valueList)
	{
		this->getValue()->add(std::shared_ptr<uml::ValueSpecification>(dynamic_cast<uml::ValueSpecification*>(_value->copy())));
	}
}

ecore::EObject *  SlotImpl::copy() const
{
	return new SlotImpl(*this);
}

std::shared_ptr<ecore::EClass> SlotImpl::eStaticClass() const
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
std::shared_ptr<uml::StructuralFeature > SlotImpl::getDefiningFeature() const
{
//assert(m_definingFeature);
    return m_definingFeature;
}
void SlotImpl::setDefiningFeature(std::shared_ptr<uml::StructuralFeature> _definingFeature)
{
    m_definingFeature = _definingFeature;
}

std::shared_ptr<uml::InstanceSpecification > SlotImpl::getOwningInstance() const
{
//assert(m_owningInstance);
    return m_owningInstance;
}
void SlotImpl::setOwningInstance(std::shared_ptr<uml::InstanceSpecification> _owningInstance)
{
    m_owningInstance = _owningInstance;
}

		std::shared_ptr<Subset<uml::ValueSpecification, uml::Element > >
 SlotImpl::getValue() const
{

    return m_value;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > SlotImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > SlotImpl::getOwner() const
{
	

	return m_owner;
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
