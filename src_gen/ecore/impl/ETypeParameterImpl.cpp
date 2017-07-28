#include "ETypeParameterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

//Forward declaration includes
#include "EAnnotation.hpp";

#include "EGenericType.hpp";

#include "ENamedElement.hpp";


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
ETypeParameterImpl::ETypeParameterImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_eBounds.reset(new Bag<ecore::EGenericType>());
	
	

	//Init references
	
	
}

ETypeParameterImpl::~ETypeParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ETypeParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ETypeParameterImpl::ETypeParameterImpl(const ETypeParameterImpl & obj):ETypeParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ETypeParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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
	std::shared_ptr<Bag<ecore::EGenericType>> _eBoundsList = obj.getEBounds();
	for(std::shared_ptr<ecore::EGenericType> _eBounds : *_eBoundsList)
	{
		this->getEBounds()->add(std::shared_ptr<ecore::EGenericType>(dynamic_cast<ecore::EGenericType*>(_eBounds->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eBounds" << std::endl;
	#endif

	
	

}

ecore::EObject *  ETypeParameterImpl::copy() const
{
	return new ETypeParameterImpl(*this);
}

std::shared_ptr<EClass> ETypeParameterImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getETypeParameter();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<ecore::EGenericType> >
 ETypeParameterImpl::getEBounds() const
{

    return m_eBounds;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ETypeParameterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //510
		case EcorePackage::ETYPEPARAMETER_EBOUNDS:
			return getEBounds(); //512
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //511
	}
	return boost::any();
}
