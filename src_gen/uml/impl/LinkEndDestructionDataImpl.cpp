#include "LinkEndDestructionDataImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
	
}

LinkEndDestructionDataImpl::~LinkEndDestructionDataImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkEndDestructionData "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LinkEndDestructionDataImpl::LinkEndDestructionDataImpl(const LinkEndDestructionDataImpl & obj)
{
	//create copy of all Attributes
	m_isDestroyDuplicates = obj.getIsDestroyDuplicates();

	//copy references with now containment
	
	m_destroyAt  = obj.getDestroyAt();

	m_end  = obj.getEnd();

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

ecore::EObject *  LinkEndDestructionDataImpl::copy() const
{
	return new LinkEndDestructionDataImpl(*this);
}

std::shared_ptr<ecore::EClass> LinkEndDestructionDataImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLinkEndDestructionData();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void LinkEndDestructionDataImpl::setIsDestroyDuplicates (bool _isDestroyDuplicates)
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
std::shared_ptr<uml::InputPin> LinkEndDestructionDataImpl::getDestroyAt() const
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
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> LinkEndDestructionDataImpl::getOwnedElement() const
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
