#include "ENamedElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "EcorePackageImpl.hpp"

//Forward declaration includes
#include "EAnnotation.hpp"

#include "EModelElement.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
ENamedElementImpl::ENamedElementImpl()
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

ENamedElementImpl::~ENamedElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ENamedElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ENamedElementImpl::ENamedElementImpl(const ENamedElementImpl & obj):ENamedElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ENamedElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif


}

ecore::EObject *  ENamedElementImpl::copy() const
{
	return new ENamedElementImpl(*this);
}

std::shared_ptr<EClass> ENamedElementImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getENamedElement();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ENamedElementImpl::setName(std::string _name)
{
	m_name = _name;
} 

std::string ENamedElementImpl::getName() const 
{
	return m_name;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ENamedElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //90
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //91
	}
	return boost::any();
}
