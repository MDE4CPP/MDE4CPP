#include "uml/impl/QualifierValueImpl.hpp"
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

#include "uml/Property.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
QualifierValueImpl::QualifierValueImpl()
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

QualifierValueImpl::~QualifierValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete QualifierValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			QualifierValueImpl::QualifierValueImpl(std::weak_ptr<uml::Element > par_owner)
			:QualifierValueImpl()
			{
			    m_owner = par_owner;
			}






QualifierValueImpl::QualifierValueImpl(const QualifierValueImpl & obj):QualifierValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy QualifierValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();

	m_qualifier  = obj.getQualifier();

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

}

std::shared_ptr<ecore::EObject>  QualifierValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new QualifierValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> QualifierValueImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getQualifierValue();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool QualifierValueImpl::multiplicity_of_qualifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool QualifierValueImpl::qualifier_attribute(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool QualifierValueImpl::type_of_qualifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Property > QualifierValueImpl::getQualifier() const
{
//assert(m_qualifier);
    return m_qualifier;
}
void QualifierValueImpl::setQualifier(std::shared_ptr<uml::Property> _qualifier)
{
    m_qualifier = _qualifier;
}

std::shared_ptr<uml::InputPin > QualifierValueImpl::getValue() const
{
//assert(m_value);
    return m_value;
}
void QualifierValueImpl::setValue(std::shared_ptr<uml::InputPin> _value)
{
    m_value = _value;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > QualifierValueImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<ecore::EObject> QualifierValueImpl::eContainer() const
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
boost::any QualifierValueImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void QualifierValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::QUALIFIERVALUE_QUALIFIER:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _qualifier = boost::any_cast<std::shared_ptr<uml::Property>>(newValue);
			setQualifier(_qualifier); //1274
			break;
		}
		case UmlPackage::QUALIFIERVALUE_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::InputPin> _value = boost::any_cast<std::shared_ptr<uml::InputPin>>(newValue);
			setValue(_value); //1275
			break;
		}
	}
}
