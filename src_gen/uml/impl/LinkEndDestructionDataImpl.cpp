#include "LinkEndDestructionDataImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "InputPin.hpp"

#include "LinkEndData.hpp"

#include "Property.hpp"

#include "QualifierValue.hpp"


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
	return UmlPackageImpl::eInstance()->getLinkEndDestructionData();
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LinkEndDestructionDataImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDESTRUCTIONDATA_DESTROYAT:
			return getDestroyAt(); //1527
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1520
		case UmlPackage::LINKENDDATA_END:
			return getEnd(); //1524
		case UmlPackage::LINKENDDESTRUCTIONDATA_ISDESTROYDUPLICATES:
			return getIsDestroyDuplicates(); //1528
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1521
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1522
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1523
		case UmlPackage::LINKENDDATA_QUALIFIER:
			return getQualifier(); //1525
		case UmlPackage::LINKENDDATA_VALUE:
			return getValue(); //1526
	}
	return boost::any();
}
