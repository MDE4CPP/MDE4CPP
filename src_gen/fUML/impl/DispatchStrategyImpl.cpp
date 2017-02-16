#include "DispatchStrategyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
DispatchStrategyImpl::DispatchStrategyImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

DispatchStrategyImpl::~DispatchStrategyImpl()
{
	
}

DispatchStrategyImpl::DispatchStrategyImpl(const DispatchStrategyImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  DispatchStrategyImpl::copy() const
{
	return new DispatchStrategyImpl(*this);
}

ecore::EClass* DispatchStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDispatchStrategy();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::Execution *  DispatchStrategyImpl::dispatch(fUML::Object *  object,uml::Operation *  operation) 
{
	//generated from body annotation
	    return object->getLocus()->getFactory()->createExecution(this->retrieveMethod(object,operation),object);
}

uml::Behavior *  DispatchStrategyImpl::retrieveMethod(fUML::Object *  object,uml::Operation *  operation) 
{
	//generated from body annotation
	    return operation->getMethod()->front();
}

std::string DispatchStrategyImpl::retrieveName() 
{
	//generated from body annotation
	return "dispatch";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DispatchStrategyImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
