#include "EFactoryImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

//Forward declaration includes
#include "EAnnotation.hpp"

#include "EClass.hpp"

#include "EDataType.hpp"

#include "EModelElement.hpp"

#include "EObject.hpp"

#include "EPackage.hpp"


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
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif


}

ecore::EObject *  EFactoryImpl::copy() const
{
	return new EFactoryImpl(*this);
}

std::shared_ptr<EClass> EFactoryImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEFactory();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::string
 EFactoryImpl::convertToString(std::shared_ptr<ecore::EDataType>  eDataType,boost::any instanceValue)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EObject> 
 EFactoryImpl::create(std::shared_ptr<ecore::EClass>  eClass)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

boost::any
 EFactoryImpl::createFromString(std::shared_ptr<ecore::EDataType>  eDataType,std::string literalValue)  const 
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EFactoryImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //70
		case EcorePackage::EFACTORY_EPACKAGE:
			return getEPackage(); //71
	}
	return boost::any();
}
