#include "uml/impl/LinkEndDataImpl.hpp"
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

#include "uml/QualifierValue.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LinkEndDataImpl::LinkEndDataImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		/*Subset*/
		m_qualifier.reset(new Subset<uml::QualifierValue, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_qualifier - Subset<uml::QualifierValue, uml::Element >()" << std::endl;
		#endif
	
	

	

	//Init references
	

		/*Subset*/
		m_qualifier->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_qualifier - Subset<uml::QualifierValue, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

LinkEndDataImpl::~LinkEndDataImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkEndData "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			LinkEndDataImpl::LinkEndDataImpl(std::weak_ptr<uml::Element > par_owner)
			:LinkEndDataImpl()
			{
			    m_owner = par_owner;
			}






LinkEndDataImpl::LinkEndDataImpl(const LinkEndDataImpl & obj):LinkEndDataImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkEndData "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
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

		/*Subset*/
		m_qualifier->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_qualifier - Subset<uml::QualifierValue, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  LinkEndDataImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LinkEndDataImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LinkEndDataImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLinkEndData();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::InputPin> > LinkEndDataImpl::allPins() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::end_object_input_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::property_is_association_end(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::qualifiers(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::same_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Property > LinkEndDataImpl::getEnd() const
{
//assert(m_end);
    return m_end;
}
void LinkEndDataImpl::setEnd(std::shared_ptr<uml::Property> _end)
{
    m_end = _end;
}

std::shared_ptr<Subset<uml::QualifierValue, uml::Element > > LinkEndDataImpl::getQualifier() const
{

    return m_qualifier;
}


std::shared_ptr<uml::InputPin > LinkEndDataImpl::getValue() const
{

    return m_value;
}
void LinkEndDataImpl::setValue(std::shared_ptr<uml::InputPin> _value)
{
    m_value = _value;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > LinkEndDataImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<ecore::EObject> LinkEndDataImpl::eContainer() const
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
boost::any LinkEndDataImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void LinkEndDataImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDATA_END:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _end = boost::any_cast<std::shared_ptr<uml::Property>>(newValue);
			setEnd(_end); //1264
			break;
		}
		case UmlPackage::LINKENDDATA_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::InputPin> _value = boost::any_cast<std::shared_ptr<uml::InputPin>>(newValue);
			setValue(_value); //1266
			break;
		}
	}
}
