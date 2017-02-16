#include "EFactoryImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EFactoryImpl::EFactoryImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

EFactoryImpl::~EFactoryImpl()
{
	
}

EFactoryImpl::EFactoryImpl(const EFactoryImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_ePackage  = obj.getEPackage();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
}

ecore::EObject *  EFactoryImpl::copy() const
{
	return new EFactoryImpl(*this);
}

EClass* EFactoryImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEFactory();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::string EFactoryImpl::convertToString(ecore::EDataType *  eDataType,boost::any instanceValue)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

ecore::EObject *  EFactoryImpl::create(ecore::EClass *  eClass)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

boost::any EFactoryImpl::createFromString(ecore::EDataType *  eDataType,std::string literalValue)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
ecore::EPackage *  EFactoryImpl::getEPackage() const
{
	//assert(m_ePackage);
	return m_ePackage;
}
void EFactoryImpl::setEPackage(ecore::EPackage *  _ePackage)
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
