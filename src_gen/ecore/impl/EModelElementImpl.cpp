#include "EModelElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EModelElementImpl::EModelElementImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_eAnnotations == nullptr)
	{
		m_eAnnotations = new std::vector<ecore::EAnnotation * >();
	}
}

EModelElementImpl::~EModelElementImpl()
{
	if(m_eAnnotations!=nullptr)
	{
		for(auto c :*m_eAnnotations)
		{
			delete(c);
			c = 0;
		}
	}
	
}

EModelElementImpl::EModelElementImpl(const EModelElementImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
}

ecore::EObject *  EModelElementImpl::copy() const
{
	return new EModelElementImpl(*this);
}

EClass* EModelElementImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEModelElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
ecore::EAnnotation *  EModelElementImpl::getEAnnotation(std::string source) 
{
	//generated from body annotation
	for(EAnnotation * a : *m_eAnnotations)
{
	if(a->getSource()==source)
	{
		return a;
	}
}
return nullptr;
}

//*********************************
// References
//*********************************
std::vector<ecore::EAnnotation * > *  EModelElementImpl::getEAnnotations() const
{
	
	return m_eAnnotations;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EModelElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //80
	}
	return boost::any();
}
