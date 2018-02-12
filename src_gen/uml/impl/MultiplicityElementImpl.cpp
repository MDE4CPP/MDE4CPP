#include "uml/impl/MultiplicityElementImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/MultiplicityElement.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
MultiplicityElementImpl::MultiplicityElementImpl()
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

MultiplicityElementImpl::~MultiplicityElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete MultiplicityElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			MultiplicityElementImpl::MultiplicityElementImpl(std::weak_ptr<uml::Element > par_owner)
			:MultiplicityElementImpl()
			{
			    m_owner = par_owner;
			}






MultiplicityElementImpl::MultiplicityElementImpl(const MultiplicityElementImpl & obj):MultiplicityElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MultiplicityElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isOrdered = obj.getIsOrdered();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_upper = obj.getUpper();

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getLowerValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_lowerValue" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_upperValue" << std::endl;
	#endif

	

	
}

std::shared_ptr<ecore::EObject>  MultiplicityElementImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new MultiplicityElementImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> MultiplicityElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getMultiplicityElement_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void MultiplicityElementImpl::setIsOrdered(bool _isOrdered)
{
	m_isOrdered = _isOrdered;
} 

bool MultiplicityElementImpl::getIsOrdered() const 
{
	return m_isOrdered;
}

void MultiplicityElementImpl::setIsUnique(bool _isUnique)
{
	m_isUnique = _isUnique;
} 

bool MultiplicityElementImpl::getIsUnique() const 
{
	return m_isUnique;
}

void MultiplicityElementImpl::setLower(int _lower)
{
	m_lower = _lower;
} 

int MultiplicityElementImpl::getLower() const 
{
	return m_lower;
}

void MultiplicityElementImpl::setUpper(int _upper)
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
bool MultiplicityElementImpl::compatibleWith(std::shared_ptr<uml::MultiplicityElement>  other) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::includesMultiplicity(std::shared_ptr<uml::MultiplicityElement>  M) 
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

bool MultiplicityElementImpl::lower_ge_0(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::lower_is_integer(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int MultiplicityElementImpl::upperBound() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::upper_ge_lower(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::upper_is_unlimitedNatural(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::value_specification_constant(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::value_specification_no_side_effects(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ValueSpecification > MultiplicityElementImpl::getLowerValue() const
{

    return m_lowerValue;
}
void MultiplicityElementImpl::setLowerValue(std::shared_ptr<uml::ValueSpecification> _lowerValue)
{
    m_lowerValue = _lowerValue;
}

std::shared_ptr<uml::ValueSpecification > MultiplicityElementImpl::getUpperValue() const
{

    return m_upperValue;
}
void MultiplicityElementImpl::setUpperValue(std::shared_ptr<uml::ValueSpecification> _upperValue)
{
    m_upperValue = _upperValue;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > MultiplicityElementImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<ecore::EObject> MultiplicityElementImpl::eContainer() const
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
boost::any MultiplicityElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //320
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISORDERED:
			return getIsOrdered(); //324
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISUNIQUE:
			return getIsUnique(); //325
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_LOWER:
			return getLower(); //326
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_LOWERVALUE:
			return getLowerValue(); //327
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //321
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //322
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //323
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_UPPER:
			return getUpper(); //328
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_UPPERVALUE:
			return getUpperValue(); //329
	}
	return boost::any();
}

void MultiplicityElementImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISORDERED:
		{
			// BOOST CAST
			bool _isOrdered = boost::any_cast<bool>(newValue);
			setIsOrdered(_isOrdered); //324
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISUNIQUE:
		{
			// BOOST CAST
			bool _isUnique = boost::any_cast<bool>(newValue);
			setIsUnique(_isUnique); //325
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_LOWER:
		{
			// BOOST CAST
			int _lower = boost::any_cast<int>(newValue);
			setLower(_lower); //326
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_LOWERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _lowerValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setLowerValue(_lowerValue); //327
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_UPPER:
		{
			// BOOST CAST
			int _upper = boost::any_cast<int>(newValue);
			setUpper(_upper); //328
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_UPPERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _upperValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setUpperValue(_upperValue); //329
			break;
		}
	}
}
