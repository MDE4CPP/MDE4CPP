#include "EObjectImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

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
	
}

EObjectImpl::~EObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EObject "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

EObjectImpl::EObjectImpl(const EObjectImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_eContainer  = obj.eContainer();


	//clone containt lists
}

ecore::EObject *  EObjectImpl::copy() const
{
	return new EObjectImpl(*this);
}

std::shared_ptr<EClass> EObjectImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEObject();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::vector <   ecore::EObject > 
 EObjectImpl::eAllContents()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EClass> 
 EObjectImpl::eClass()  const 
{
	//generated from body annotation
	return this->eStaticClass();
}

std::shared_ptr<ecore::EStructuralFeature> 
 EObjectImpl::eContainingFeature()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EReference> 
 EObjectImpl::eContainmentFeature()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector <   ecore::EObject > 
 EObjectImpl::eContents()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector <   ecore::EObject > 
 EObjectImpl::eCrossReferences()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

boost::any
 EObjectImpl::eGet(std::shared_ptr<ecore::EStructuralFeature>  feature)  const 
{
	//generated from body annotation
	return this->eGet(feature,false);
}

boost::any
 EObjectImpl::eGet(std::shared_ptr<ecore::EStructuralFeature>  feature,bool resolve)  const 
{
	//generated from body annotation
	return this->eGet(feature->getFeatureID(),resolve,false);
}

boost::any
 EObjectImpl::eInvoke(std::shared_ptr<ecore::EOperation>  operation,std::vector <   boost::any >  arguments)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 EObjectImpl::eIsProxy()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 EObjectImpl::eIsSet(std::shared_ptr<ecore::EStructuralFeature>  feature)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int
 EObjectImpl::eResource()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void
 EObjectImpl::eSet(std::shared_ptr<ecore::EStructuralFeature>  feature,boost::any newValue)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void
 EObjectImpl::eUnset(std::shared_ptr<ecore::EStructuralFeature>  feature)  const 
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
void EObjectImpl::setContainer(std::shared_ptr<ecore::EObject> _eContainer)
{
    m_eContainer = _eContainer;
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
