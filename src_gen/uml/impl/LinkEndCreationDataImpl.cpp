#include "LinkEndCreationDataImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
	
}

LinkEndCreationDataImpl::~LinkEndCreationDataImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkEndCreationData "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LinkEndCreationDataImpl::LinkEndCreationDataImpl(const LinkEndCreationDataImpl & obj)
{
	//create copy of all Attributes
	m_isReplaceAll = obj.getIsReplaceAll();

	//copy references with now containment
	
	m_end  = obj.getEnd();

	m_insertAt  = obj.getInsertAt();

	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_value  = obj.getValue();


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAnnotation>>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->push_back(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::QualifierValue>>> _qualifierList = obj.getQualifier();
	for(std::shared_ptr<uml::QualifierValue> _qualifier : *_qualifierList)
	{
		this->getQualifier()->push_back(std::shared_ptr<uml::QualifierValue>(dynamic_cast<uml::QualifierValue*>(_qualifier->copy())));
	}
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
bool LinkEndCreationDataImpl::insertAt_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::InputPin> LinkEndCreationDataImpl::getInsertAt() const
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
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> LinkEndCreationDataImpl::getOwnedElement() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement(new std::vector<std::shared_ptr<uml::Element>>()) ;
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> ownedComment = getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());
	std::shared_ptr<std::vector<std::shared_ptr<uml::QualifierValue>>> qualifier = getQualifier();
	_ownedElement->insert(_ownedElement->end(), qualifier->begin(), qualifier->end());

	return _ownedElement;
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
