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
	// Reference Members
	//*********************************
	if( m_contents == nullptr)
	{
		m_contents = new std::vector<ecore::EObject * >();
	}
	if( m_details == nullptr)
	{
		m_details = new std::vector<ecore::EStringToStringMapEntry * >();
	}
	
	if( m_references == nullptr)
	{
		m_references = new std::vector<ecore::EObject * >();
	}
}

EAnnotationImpl::~EAnnotationImpl()
{
	if(m_details!=nullptr)
	{
		for(auto c :*m_details)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_contents!=nullptr)
	{
		for(auto c :*m_contents)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_references!=nullptr)
	{
		delete(m_references);
	 	m_references = nullptr;
	}
	
}

EAnnotationImpl::EAnnotationImpl(const EAnnotationImpl & obj)
{
	//create copy of all Attributes
	m_source = obj.getSource();

	//copy references with now containment
	
	m_eModelElement  = obj.getEModelElement();

	std::vector<ecore::EObject * > *  _references = obj.getReferences();
	this->getReferences()->insert(this->getReferences()->end(), _references->begin(), _references->end());


	//clone containt lists
	for(ecore::EObject * 	_contents : *obj.getContents())
	{
		this->getContents()->push_back(dynamic_cast<ecore::EObject * >(_contents->copy()));
	}
	for(ecore::EStringToStringMapEntry * 	_details : *obj.getDetails())
	{
		this->getDetails()->push_back(dynamic_cast<ecore::EStringToStringMapEntry * >(_details->copy()));
	}
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
}

ecore::EObject *  EAnnotationImpl::copy() const
{
	return new EAnnotationImpl(*this);
}

EClass* EAnnotationImpl::eStaticClass() const
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
std::vector<ecore::EObject * > *  EAnnotationImpl::getContents() const
{
	
	return m_contents;
}


std::vector<ecore::EStringToStringMapEntry * > *  EAnnotationImpl::getDetails() const
{
	
	return m_details;
}


ecore::EModelElement *  EAnnotationImpl::getEModelElement() const
{
	
	return m_eModelElement;
}
void EAnnotationImpl::setEModelElement(ecore::EModelElement *  _eModelElement)
{
	m_eModelElement = _eModelElement;
}

std::vector<ecore::EObject * > *  EAnnotationImpl::getReferences() const
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
