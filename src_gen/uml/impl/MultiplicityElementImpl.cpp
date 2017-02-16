#include "MultiplicityElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
MultiplicityElementImpl::MultiplicityElementImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

MultiplicityElementImpl::~MultiplicityElementImpl()
{
	if(m_lowerValue!=nullptr)
	{
		if(m_lowerValue)
		{
			delete(m_lowerValue);
			m_lowerValue = nullptr;
		}
	}
	if(m_upperValue!=nullptr)
	{
		if(m_upperValue)
		{
			delete(m_upperValue);
			m_upperValue = nullptr;
		}
	}
	
}

MultiplicityElementImpl::MultiplicityElementImpl(const MultiplicityElementImpl & obj)
{
	//create copy of all Attributes
	m_isOrdered = obj.getIsOrdered();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_upper = obj.getUpper();

	//copy references with now containment
	
	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = dynamic_cast<uml::ValueSpecification * >(obj.getLowerValue()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = dynamic_cast<uml::ValueSpecification * >(obj.getUpperValue()->copy());
	}
}

ecore::EObject *  MultiplicityElementImpl::copy() const
{
	return new MultiplicityElementImpl(*this);
}

ecore::EClass* MultiplicityElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getMultiplicityElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void MultiplicityElementImpl::setIsOrdered (bool _isOrdered)
{
	m_isOrdered = _isOrdered;
} 

bool MultiplicityElementImpl::getIsOrdered() const 
{
	return m_isOrdered;
}

void MultiplicityElementImpl::setIsUnique (bool _isUnique)
{
	m_isUnique = _isUnique;
} 

bool MultiplicityElementImpl::getIsUnique() const 
{
	return m_isUnique;
}

void MultiplicityElementImpl::setLower (int _lower)
{
	m_lower = _lower;
} 

int MultiplicityElementImpl::getLower() const 
{
	return m_lower;
}

void MultiplicityElementImpl::setUpper (int _upper)
{
	m_upper = _upper;
} 

int MultiplicityElementImpl::getUpper() const 
{
	return m_upper;
}

//*********************************
// Operations
//*********************************
bool MultiplicityElementImpl::compatibleWith(uml::MultiplicityElement *  other) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::includesMultiplicity(uml::MultiplicityElement *  M) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::is(int lowerbound,int upperbound) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::isMultivalued() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int MultiplicityElementImpl::lowerBound() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::lower_ge_0(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::lower_is_integer(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int MultiplicityElementImpl::upperBound() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::upper_ge_lower(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::upper_is_unlimitedNatural(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::value_specification_constant(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::value_specification_no_side_effects(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::ValueSpecification *  MultiplicityElementImpl::getLowerValue() const
{
	
	return m_lowerValue;
}
void MultiplicityElementImpl::setLowerValue(uml::ValueSpecification *  _lowerValue)
{
	m_lowerValue = _lowerValue;
}

uml::ValueSpecification *  MultiplicityElementImpl::getUpperValue() const
{
	
	return m_upperValue;
}
void MultiplicityElementImpl::setUpperValue(uml::ValueSpecification *  _upperValue)
{
	m_upperValue = _upperValue;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  MultiplicityElementImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getLowerValue());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getUpperValue());

	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any MultiplicityElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //320
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //324
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //325
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //326
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //327
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //321
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //322
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //323
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //328
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //329
	}
	return boost::any();
}
