#include "uml/impl/SlotImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/InstanceSpecification.hpp"

#include "uml/StructuralFeature.hpp"

#include "uml/ValueSpecification.hpp"


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
	//References
	

	

		/*Subset*/
		m_value.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_value - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
	

	

		/*Subset*/
		m_value->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_value - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

SlotImpl::~SlotImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Slot "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			SlotImpl::SlotImpl(std::weak_ptr<uml::Element > par_owner)
			:SlotImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			SlotImpl::SlotImpl(std::weak_ptr<uml::InstanceSpecification > par_owningInstance)
			:SlotImpl()
			{
			    m_owningInstance = par_owningInstance;
			}






SlotImpl::SlotImpl(const SlotImpl & obj):SlotImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Slot "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_definingFeature  = obj.getDefiningFeature();

	m_owner  = obj.getOwner();

	m_owningInstance  = obj.getOwningInstance();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ValueSpecification>> _valueList = obj.getValue();
	for(std::shared_ptr<uml::ValueSpecification> _value : *_valueList)
	{
		this->getValue()->add(std::shared_ptr<uml::ValueSpecification>(std::dynamic_pointer_cast<uml::ValueSpecification>(_value->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_value" << std::endl;
	#endif

		/*Subset*/
		m_value->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_value - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  SlotImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new SlotImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> SlotImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getSlot();
}

//*********************************
// Attribute Setter Getter
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

std::weak_ptr<uml::InstanceSpecification > SlotImpl::getOwningInstance() const
{
//assert(m_owningInstance);
    return m_owningInstance;
}
void SlotImpl::setOwningInstance(std::shared_ptr<uml::InstanceSpecification> _owningInstance)
{
    m_owningInstance = _owningInstance;
}

std::shared_ptr<Subset<uml::ValueSpecification, uml::Element > > SlotImpl::getValue() const
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
std::weak_ptr<uml::Element > SlotImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> SlotImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningInstance.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any SlotImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void SlotImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::SLOT_DEFININGFEATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuralFeature> _definingFeature = boost::any_cast<std::shared_ptr<uml::StructuralFeature>>(newValue);
			setDefiningFeature(_definingFeature); //804
			break;
		}
		case UmlPackage::SLOT_OWNINGINSTANCE:
		{
			// BOOST CAST
			std::shared_ptr<uml::InstanceSpecification> _owningInstance = boost::any_cast<std::shared_ptr<uml::InstanceSpecification>>(newValue);
			setOwningInstance(_owningInstance); //806
			break;
		}
	}
}
