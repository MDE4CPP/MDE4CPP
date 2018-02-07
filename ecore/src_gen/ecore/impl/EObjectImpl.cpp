#include "ecore/impl/EObjectImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EClass.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EOperation.hpp"

#include "ecore/EReference.hpp"

#include "ecore/EStructuralFeature.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EObjectImpl::EObjectImpl()
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

EObjectImpl::~EObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EObject "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




EObjectImpl::EObjectImpl(const EObjectImpl & obj):EObjectImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EObject "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_eContainer  = obj.eContainer();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  EObjectImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EObjectImpl(*this));
	return element;
}

std::shared_ptr<EClass> EObjectImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEObject();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::vector <   ecore::EObject > EObjectImpl::eAllContents()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EClass> EObjectImpl::eClass()  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eStaticClass();
	//end of body
}

std::shared_ptr<ecore::EStructuralFeature> EObjectImpl::eContainingFeature()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EReference> EObjectImpl::eContainmentFeature()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector <   ecore::EObject > EObjectImpl::eContents()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector <   ecore::EObject > EObjectImpl::eCrossReferences()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

boost::any EObjectImpl::eGet(std::shared_ptr<ecore::EStructuralFeature>  feature)  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eGet(feature,false);
	//end of body
}

boost::any EObjectImpl::eGet(std::shared_ptr<ecore::EStructuralFeature>  feature,bool resolve)  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eGet(feature->getFeatureID(),resolve,false);
	//end of body
}

boost::any EObjectImpl::eInvoke(std::shared_ptr<ecore::EOperation>  operation,std::vector <   boost::any >  arguments)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EObjectImpl::eIsProxy()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EObjectImpl::eIsSet(std::shared_ptr<ecore::EStructuralFeature>  feature)  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return true;
	//end of body
}

int EObjectImpl::eResource()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void EObjectImpl::eSet(std::shared_ptr<ecore::EStructuralFeature>  feature,boost::any newValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->eSet(feature->getFeatureID(), newValue);
	//end of body
}

void EObjectImpl::eUnset(std::shared_ptr<ecore::EStructuralFeature>  feature)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************



//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EObjectImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EOBJECT_ECONTAINER:
			return eContainer(); //100
	}
	return boost::any();
}

void EObjectImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
