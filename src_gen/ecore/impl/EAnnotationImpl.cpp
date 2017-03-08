#include "EAnnotationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

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
	m_contents.reset(new std::vector<std::shared_ptr<ecore::EObject>>());
	m_details.reset(new std::vector<std::shared_ptr<ecore::EStringToStringMapEntry>>());
	
	m_references.reset(new std::vector<std::shared_ptr<ecore::EObject>>());
}

EAnnotationImpl::~EAnnotationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EAnnotation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

EAnnotationImpl::EAnnotationImpl(const EAnnotationImpl & obj)
{
	//create copy of all Attributes
	m_source = obj.getSource();

	//copy references with now containment
	
	m_eModelElement  = obj.getEModelElement();

	std::shared_ptr<std::vector<std::shared_ptr<ecore::EObject>>> _references = obj.getReferences();
	this->getReferences()->insert(this->getReferences()->end(), _references->begin(), _references->end());


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EObject>>> _contentsList = obj.getContents();
	for(std::shared_ptr<ecore::EObject> _contents : *_contentsList)
	{
		this->getContents()->push_back(std::shared_ptr<ecore::EObject>(dynamic_cast<ecore::EObject*>(_contents->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EStringToStringMapEntry>>> _detailsList = obj.getDetails();
	for(std::shared_ptr<ecore::EStringToStringMapEntry> _details : *_detailsList)
	{
		this->getDetails()->push_back(std::shared_ptr<ecore::EStringToStringMapEntry>(dynamic_cast<ecore::EStringToStringMapEntry*>(_details->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAnnotation>>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
}

ecore::EObject *  EAnnotationImpl::copy() const
{
	return new EAnnotationImpl(*this);
}

std::shared_ptr<EClass> EAnnotationImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEAnnotation();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void EAnnotationImpl::setSource (std::string _source)
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
std::shared_ptr<std::vector<std::shared_ptr<ecore::EObject>>> EAnnotationImpl::getContents() const
{

    return m_contents;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EStringToStringMapEntry>>> EAnnotationImpl::getDetails() const
{

    return m_details;
}


std::shared_ptr<ecore::EModelElement> EAnnotationImpl::getEModelElement() const
{

    return m_eModelElement;
}
void EAnnotationImpl::setEModelElement(std::shared_ptr<ecore::EModelElement> _eModelElement)
{
    m_eModelElement = _eModelElement;
}

std::shared_ptr<std::vector<std::shared_ptr<ecore::EObject>>> EAnnotationImpl::getReferences() const
{

    return m_references;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EAnnotationImpl::eGet(int featureID,  bool resolve, bool coreType) const
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
