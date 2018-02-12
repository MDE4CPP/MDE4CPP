#include "ecore/impl/EFactoryImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EDataType.hpp"

#include "ecore/EModelElement.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EPackage.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EFactoryImpl::EFactoryImpl()
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

EFactoryImpl::~EFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




EFactoryImpl::EFactoryImpl(const EFactoryImpl & obj):EFactoryImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EFactory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_ePackage  = obj.getEPackage();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  EFactoryImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EFactoryImpl(*this));
	return element;
}

std::shared_ptr<EClass> EFactoryImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEFactory_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::string EFactoryImpl::convertToString(std::shared_ptr<ecore::EDataType>  eDataType,boost::any instanceValue)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EObject> EFactoryImpl::create(std::shared_ptr<ecore::EClass>  eClass,std::shared_ptr<ecore::EObject>  container)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

boost::any EFactoryImpl::createFromString(std::shared_ptr<ecore::EDataType>  eDataType,std::string literalValue)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<ecore::EPackage > EFactoryImpl::getEPackage() const
{
//assert(m_ePackage);
    return m_ePackage;
}
void EFactoryImpl::setEPackage(std::shared_ptr<ecore::EPackage> _ePackage)
{
    m_ePackage = _ePackage;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EFactoryImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EFactoryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //70
		case EcorePackage::EFACTORY_EREFERENCE_EPACKAGE:
			return getEPackage(); //71
	}
	return boost::any();
}

void EFactoryImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::EFACTORY_EREFERENCE_EPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EPackage> _ePackage = boost::any_cast<std::shared_ptr<ecore::EPackage>>(newValue);
			setEPackage(_ePackage); //71
			break;
		}
	}
}
