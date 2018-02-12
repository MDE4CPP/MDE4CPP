#include "uml/impl/LinkEndDestructionDataImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/InputPin.hpp"

#include "uml/LinkEndData.hpp"

#include "uml/Property.hpp"

#include "uml/QualifierValue.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LinkEndDestructionDataImpl::LinkEndDestructionDataImpl()
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

LinkEndDestructionDataImpl::~LinkEndDestructionDataImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkEndDestructionData "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			LinkEndDestructionDataImpl::LinkEndDestructionDataImpl(std::weak_ptr<uml::Element > par_owner)
			:LinkEndDestructionDataImpl()
			{
			    m_owner = par_owner;
			}






LinkEndDestructionDataImpl::LinkEndDestructionDataImpl(const LinkEndDestructionDataImpl & obj):LinkEndDestructionDataImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkEndDestructionData "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isDestroyDuplicates = obj.getIsDestroyDuplicates();

	//copy references with no containment (soft copy)
	
	m_destroyAt  = obj.getDestroyAt();

	m_end  = obj.getEnd();

	m_owner  = obj.getOwner();

	m_value  = obj.getValue();


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
	std::shared_ptr<Bag<uml::QualifierValue>> _qualifierList = obj.getQualifier();
	for(std::shared_ptr<uml::QualifierValue> _qualifier : *_qualifierList)
	{
		this->getQualifier()->add(std::shared_ptr<uml::QualifierValue>(std::dynamic_pointer_cast<uml::QualifierValue>(_qualifier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_qualifier" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  LinkEndDestructionDataImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LinkEndDestructionDataImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LinkEndDestructionDataImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLinkEndDestructionData_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void LinkEndDestructionDataImpl::setIsDestroyDuplicates(bool _isDestroyDuplicates)
{
	m_isDestroyDuplicates = _isDestroyDuplicates;
} 

bool LinkEndDestructionDataImpl::getIsDestroyDuplicates() const 
{
	return m_isDestroyDuplicates;
}

//*********************************
// Operations
//*********************************
bool LinkEndDestructionDataImpl::destroyAt_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::InputPin > LinkEndDestructionDataImpl::getDestroyAt() const
{

    return m_destroyAt;
}
void LinkEndDestructionDataImpl::setDestroyAt(std::shared_ptr<uml::InputPin> _destroyAt)
{
    m_destroyAt = _destroyAt;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > LinkEndDestructionDataImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<ecore::EObject> LinkEndDestructionDataImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LinkEndDestructionDataImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDESTRUCTIONDATA_EREFERENCE_DESTROYAT:
			return getDestroyAt(); //1527
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //1520
		case UmlPackage::LINKENDDATA_EREFERENCE_END:
			return getEnd(); //1524
		case UmlPackage::LINKENDDESTRUCTIONDATA_EATTRIBUTE_ISDESTROYDUPLICATES:
			return getIsDestroyDuplicates(); //1528
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //1521
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //1522
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //1523
		case UmlPackage::LINKENDDATA_EREFERENCE_QUALIFIER:
			return getQualifier(); //1525
		case UmlPackage::LINKENDDATA_EREFERENCE_VALUE:
			return getValue(); //1526
	}
	return boost::any();
}

void LinkEndDestructionDataImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDESTRUCTIONDATA_EREFERENCE_DESTROYAT:
		{
			// BOOST CAST
			std::shared_ptr<uml::InputPin> _destroyAt = boost::any_cast<std::shared_ptr<uml::InputPin>>(newValue);
			setDestroyAt(_destroyAt); //1527
			break;
		}
		case UmlPackage::LINKENDDATA_EREFERENCE_END:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _end = boost::any_cast<std::shared_ptr<uml::Property>>(newValue);
			setEnd(_end); //1524
			break;
		}
		case UmlPackage::LINKENDDESTRUCTIONDATA_EATTRIBUTE_ISDESTROYDUPLICATES:
		{
			// BOOST CAST
			bool _isDestroyDuplicates = boost::any_cast<bool>(newValue);
			setIsDestroyDuplicates(_isDestroyDuplicates); //1528
			break;
		}
		case UmlPackage::LINKENDDATA_EREFERENCE_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::InputPin> _value = boost::any_cast<std::shared_ptr<uml::InputPin>>(newValue);
			setValue(_value); //1526
			break;
		}
	}
}
