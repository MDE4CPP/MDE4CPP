#include "EObjectImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "EcorePackageImpl.hpp"

//Forward declaration includes
#include "EClass.hpp"

#include "EObject.hpp"

#include "EOperation.hpp"

#include "EReference.hpp"

#include "EStructuralFeature.hpp"


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
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int EObjectImpl::eResource()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void EObjectImpl::eSet(std::shared_ptr<ecore::EStructuralFeature>  feature,boost::any newValue)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void EObjectImpl::eUnset(std::shared_ptr<ecore::EStructuralFeature>  feature)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<ecore::EObject > EObjectImpl::eContainer() const
{

    return m_eContainer;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EObjectImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EOBJECT_ECONTAINER:
			return eContainer(); //100
	}
	return boost::any();
}
