#include "LinkEndDataImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LinkEndDataImpl::LinkEndDataImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_qualifier == nullptr)
	{
		m_qualifier = new std::vector<uml::QualifierValue * >();
	}
	
}

LinkEndDataImpl::~LinkEndDataImpl()
{
	if(m_qualifier!=nullptr)
	{
		for(auto c :*m_qualifier)
		{
			delete(c);
			c = 0;
		}
	}
	
}

LinkEndDataImpl::LinkEndDataImpl(const LinkEndDataImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
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

ecore::EObject *  LinkEndDataImpl::copy() const
{
	return new LinkEndDataImpl(*this);
}

ecore::EClass* LinkEndDataImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLinkEndData();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::vector<uml::InputPin * > *  LinkEndDataImpl::allPins() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::end_object_input_pin(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::property_is_association_end(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::qualifiers(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::same_type(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Property *  LinkEndDataImpl::getEnd() const
{
	//assert(m_end);
	return m_end;
}
void LinkEndDataImpl::setEnd(uml::Property *  _end)
{
	m_end = _end;
}

std::vector<uml::QualifierValue * > *  LinkEndDataImpl::getQualifier() const
{
	
	return m_qualifier;
}


uml::InputPin *  LinkEndDataImpl::getValue() const
{
	
	return m_value;
}
void LinkEndDataImpl::setValue(uml::InputPin *  _value)
{
	m_value = _value;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  LinkEndDataImpl::getOwnedElement() const
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
boost::any LinkEndDataImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1260
		case UmlPackage::LINKENDDATA_END:
			return getEnd(); //1264
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1261
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1262
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1263
		case UmlPackage::LINKENDDATA_QUALIFIER:
			return getQualifier(); //1265
		case UmlPackage::LINKENDDATA_VALUE:
			return getValue(); //1266
	}
	return boost::any();
}
