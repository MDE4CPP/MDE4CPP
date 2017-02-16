#include "SemanticStrategyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
SemanticStrategyImpl::SemanticStrategyImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

SemanticStrategyImpl::~SemanticStrategyImpl()
{
	
}

SemanticStrategyImpl::SemanticStrategyImpl(const SemanticStrategyImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  SemanticStrategyImpl::copy() const
{
	return new SemanticStrategyImpl(*this);
}

ecore::EClass* SemanticStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getSemanticStrategy();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::string SemanticStrategyImpl::retrieveName() 
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any SemanticStrategyImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
