#include "fUML/impl/DispatchStrategyImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "uml/Behavior.hpp"

#include "fUML/Execution.hpp"

#include "fUML/Object.hpp"

#include "uml/Operation.hpp"

#include "fUML/SemanticStrategy.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
DispatchStrategyImpl::DispatchStrategyImpl()
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

DispatchStrategyImpl::~DispatchStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DispatchStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




DispatchStrategyImpl::DispatchStrategyImpl(const DispatchStrategyImpl & obj):DispatchStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DispatchStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  DispatchStrategyImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new DispatchStrategyImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> DispatchStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDispatchStrategy();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Execution> DispatchStrategyImpl::dispatch(std::shared_ptr<fUML::Object>  object,std::shared_ptr<uml::Operation>  operation) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return object->getLocus()->getFactory()->createExecution(this->retrieveMethod(object,operation),object);
	//end of body
}

std::shared_ptr<uml::Behavior> DispatchStrategyImpl::retrieveMethod(std::shared_ptr<fUML::Object>  object,std::shared_ptr<uml::Operation>  operation) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return operation->getMethod()->front();
	//end of body
}

std::string DispatchStrategyImpl::retrieveName() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "dispatch";
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> DispatchStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DispatchStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

void DispatchStrategyImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
