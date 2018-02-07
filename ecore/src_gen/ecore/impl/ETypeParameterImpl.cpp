#include "ecore/impl/ETypeParameterImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/ENamedElement.hpp"


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
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EGenericType>> _eBoundsList = obj.getEBounds();
	for(std::shared_ptr<ecore::EGenericType> _eBounds : *_eBoundsList)
	{
		this->getEBounds()->add(std::shared_ptr<ecore::EGenericType>(std::dynamic_pointer_cast<ecore::EGenericType>(_eBounds->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eBounds" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  ETypeParameterImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ETypeParameterImpl(*this));
	return element;
}

std::shared_ptr<EClass> ETypeParameterImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getETypeParameter();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr< Bag<ecore::EGenericType> > ETypeParameterImpl::getEBounds() const
{

    return m_eBounds;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> ETypeParameterImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ETypeParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void ETypeParameterImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ENAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //511
			break;
		}
	}
}
