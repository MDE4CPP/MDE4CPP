#include "LinkEndCreationDataImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp";

#include "EAnnotation.hpp";

#include "Element.hpp";

#include "InputPin.hpp";

#include "LinkEndData.hpp";

#include "Property.hpp";

#include "QualifierValue.hpp";


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LinkEndCreationDataImpl::LinkEndCreationDataImpl()
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

LinkEndCreationDataImpl::~LinkEndCreationDataImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkEndCreationData "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LinkEndCreationDataImpl::LinkEndCreationDataImpl(const LinkEndCreationDataImpl & obj):LinkEndCreationDataImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkEndCreationData "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isReplaceAll = obj.getIsReplaceAll();

	//copy references with no containment (soft copy)
	
	m_end  = obj.getEnd();

	m_insertAt  = obj.getInsertAt();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();

	m_value  = obj.getValue();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::QualifierValue>> _qualifierList = obj.getQualifier();
	for(std::shared_ptr<uml::QualifierValue> _qualifier : *_qualifierList)
	{
		this->getQualifier()->add(std::shared_ptr<uml::QualifierValue>(dynamic_cast<uml::QualifierValue*>(_qualifier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_qualifier" << std::endl;
	#endif


}

ecore::EObject *  LinkEndCreationDataImpl::copy() const
{
	return new LinkEndCreationDataImpl(*this);
}

std::shared_ptr<ecore::EClass> LinkEndCreationDataImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLinkEndCreationData();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void LinkEndCreationDataImpl::setIsReplaceAll (bool _isReplaceAll)
{
	m_isReplaceAll = _isReplaceAll;
} 

bool LinkEndCreationDataImpl::getIsReplaceAll() const 
{
	return m_isReplaceAll;
}

//*********************************
// Operations
//*********************************
bool
 LinkEndCreationDataImpl::insertAt_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::InputPin > LinkEndCreationDataImpl::getInsertAt() const
{

    return m_insertAt;
}
void LinkEndCreationDataImpl::setInsertAt(std::shared_ptr<uml::InputPin> _insertAt)
{
    m_insertAt = _insertAt;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > LinkEndCreationDataImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LinkEndCreationDataImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1480
		case UmlPackage::LINKENDDATA_END:
			return getEnd(); //1484
		case UmlPackage::LINKENDCREATIONDATA_INSERTAT:
			return getInsertAt(); //1487
		case UmlPackage::LINKENDCREATIONDATA_ISREPLACEALL:
			return getIsReplaceAll(); //1488
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1481
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1482
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1483
		case UmlPackage::LINKENDDATA_QUALIFIER:
			return getQualifier(); //1485
		case UmlPackage::LINKENDDATA_VALUE:
			return getValue(); //1486
	}
	return boost::any();
}
