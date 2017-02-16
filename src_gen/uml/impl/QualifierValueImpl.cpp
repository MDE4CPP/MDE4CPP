#include "QualifierValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
QualifierValueImpl::QualifierValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

QualifierValueImpl::~QualifierValueImpl()
{
	
}

QualifierValueImpl::QualifierValueImpl(const QualifierValueImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_qualifier  = obj.getQualifier();

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
}

ecore::EObject *  QualifierValueImpl::copy() const
{
	return new QualifierValueImpl(*this);
}

ecore::EClass* QualifierValueImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getQualifierValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool QualifierValueImpl::multiplicity_of_qualifier(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool QualifierValueImpl::qualifier_attribute(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool QualifierValueImpl::type_of_qualifier(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Property *  QualifierValueImpl::getQualifier() const
{
	//assert(m_qualifier);
	return m_qualifier;
}
void QualifierValueImpl::setQualifier(uml::Property *  _qualifier)
{
	m_qualifier = _qualifier;
}

uml::InputPin *  QualifierValueImpl::getValue() const
{
	//assert(m_value);
	return m_value;
}
void QualifierValueImpl::setValue(uml::InputPin *  _value)
{
	m_value = _value;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  QualifierValueImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any QualifierValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1270
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1271
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1272
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1273
		case UmlPackage::QUALIFIERVALUE_QUALIFIER:
			return getQualifier(); //1274
		case UmlPackage::QUALIFIERVALUE_VALUE:
			return getValue(); //1275
	}
	return boost::any();
}
