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
	// Reference Members
	//*********************************
	
}

LinkEndDestructionDataImpl::~LinkEndDestructionDataImpl()
{
	
}

LinkEndDestructionDataImpl::LinkEndDestructionDataImpl(const LinkEndDestructionDataImpl & obj)
{
	//create copy of all Attributes
	m_isDestroyDuplicates = obj.getIsDestroyDuplicates();

	//copy references with now containment
	
	m_destroyAt  = obj.getDestroyAt();

	m_end  = obj.getEnd();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_value  = obj.getValue();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::QualifierValue * 	_qualifier : *obj.getQualifier())
	{
		this->getQualifier()->push_back(dynamic_cast<uml::QualifierValue * >(_qualifier->copy()));
	}
}

ecore::EObject *  LinkEndDestructionDataImpl::copy() const
{
	return new LinkEndDestructionDataImpl(*this);
}

ecore::EClass* LinkEndDestructionDataImpl::eStaticClass() const
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
bool LinkEndDestructionDataImpl::destroyAt_pin(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::InputPin *  LinkEndDestructionDataImpl::getDestroyAt() const
{
	
	return m_destroyAt;
}
void LinkEndDestructionDataImpl::setDestroyAt(uml::InputPin *  _destroyAt)
{
	m_destroyAt = _destroyAt;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  LinkEndDestructionDataImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  qualifier = (std::vector<uml::Element * > * ) getQualifier();
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
