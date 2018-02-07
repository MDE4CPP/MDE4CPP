#include "ecore/impl/EAnnotationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/EModelElement.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EStringToStringMapEntry.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EAnnotationImpl::EAnnotationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_contents.reset(new Bag<ecore::EObject>());
	
	

		m_details.reset(new Bag<ecore::EStringToStringMapEntry>());
	
	

	

		m_references.reset(new Bag<ecore::EObject>());
	
	

	//Init references
	
	

	
	

	

	
	
}

EAnnotationImpl::~EAnnotationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EAnnotation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			EAnnotationImpl::EAnnotationImpl(std::weak_ptr<ecore::EModelElement > par_eModelElement)
			:EAnnotationImpl()
			{
			    m_eModelElement = par_eModelElement;
			}






EAnnotationImpl::EAnnotationImpl(const EAnnotationImpl & obj):EAnnotationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EAnnotation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_source = obj.getSource();

	//copy references with no containment (soft copy)
	
	m_eModelElement  = obj.getEModelElement();

	std::shared_ptr< Bag<ecore::EObject> > _references = obj.getReferences();
	m_references.reset(new Bag<ecore::EObject>(*(obj.getReferences().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EObject>> _contentsList = obj.getContents();
	for(std::shared_ptr<ecore::EObject> _contents : *_contentsList)
	{
		this->getContents()->add(std::shared_ptr<ecore::EObject>(std::dynamic_pointer_cast<ecore::EObject>(_contents->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_contents" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EStringToStringMapEntry>> _detailsList = obj.getDetails();
	for(std::shared_ptr<ecore::EStringToStringMapEntry> _details : *_detailsList)
	{
		this->getDetails()->add(std::shared_ptr<ecore::EStringToStringMapEntry>(std::dynamic_pointer_cast<ecore::EStringToStringMapEntry>(_details->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_details" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif

	
	

	
	
}

std::shared_ptr<ecore::EObject>  EAnnotationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EAnnotationImpl(*this));
	return element;
}

std::shared_ptr<EClass> EAnnotationImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEAnnotation();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EAnnotationImpl::setSource(std::string _source)
{
	m_source = _source;
} 

std::string EAnnotationImpl::getSource() const 
{
	return m_source;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr< Bag<ecore::EObject> > EAnnotationImpl::getContents() const
{

    return m_contents;
}


std::shared_ptr< Bag<ecore::EStringToStringMapEntry> > EAnnotationImpl::getDetails() const
{

    return m_details;
}


std::weak_ptr<ecore::EModelElement > EAnnotationImpl::getEModelElement() const
{

    return m_eModelElement;
}
void EAnnotationImpl::setEModelElement(std::shared_ptr<ecore::EModelElement> _eModelElement)
{
    m_eModelElement = _eModelElement;
}

std::shared_ptr< Bag<ecore::EObject> > EAnnotationImpl::getReferences() const
{

    return m_references;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EAnnotationImpl::eContainer() const
{
	if(auto wp = m_eModelElement.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EAnnotationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EANNOTATION_CONTENTS:
			return getContents(); //14
		case EcorePackage::EANNOTATION_DETAILS:
			return getDetails(); //12
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //10
		case EcorePackage::EANNOTATION_EMODELELEMENT:
			return getEModelElement(); //13
		case EcorePackage::EANNOTATION_REFERENCES:
			return getReferences(); //15
		case EcorePackage::EANNOTATION_SOURCE:
			return getSource(); //11
	}
	return boost::any();
}

void EAnnotationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::EANNOTATION_EMODELELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EModelElement> _eModelElement = boost::any_cast<std::shared_ptr<ecore::EModelElement>>(newValue);
			setEModelElement(_eModelElement); //13
			break;
		}
		case EcorePackage::EANNOTATION_SOURCE:
		{
			// BOOST CAST
			std::string _source = boost::any_cast<std::string>(newValue);
			setSource(_source); //11
			break;
		}
	}
}
