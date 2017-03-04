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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	m_eAnnotations.reset(new std::vector<std::shared_ptr<ecore::EAnnotation>>());
}

EModelElementImpl::~EModelElementImpl()
{
	
}

EModelElementImpl::EModelElementImpl(const EModelElementImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
}

ecore::EObject *  EModelElementImpl::copy() const
{
	return new EModelElementImpl(*this);
}

std::shared_ptr<EClass> EModelElementImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEModelElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EAnnotation>  EModelElementImpl::getEAnnotation(std::string source) 
{
	//generated from body annotation
	    for(std::shared_ptr<EAnnotation> a : *m_eAnnotations)
    {
	    if(a->getSource()==source)
	    {
		    return a;
	    }
    }
    return std::shared_ptr<ecore::EAnnotation>();
}

//*********************************
// References
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<ecore::EAnnotation>>> EModelElementImpl::getEAnnotations() const
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
