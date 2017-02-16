#include "FirstChoiceStrategyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
FirstChoiceStrategyImpl::FirstChoiceStrategyImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

FirstChoiceStrategyImpl::~FirstChoiceStrategyImpl()
{
	
}

FirstChoiceStrategyImpl::FirstChoiceStrategyImpl(const FirstChoiceStrategyImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  FirstChoiceStrategyImpl::copy() const
{
	return new FirstChoiceStrategyImpl(*this);
}

ecore::EClass* FirstChoiceStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getFirstChoiceStrategy();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
int FirstChoiceStrategyImpl::choose(int size) 
{
	//generated from body annotation
	return 1;
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
boost::any FirstChoiceStrategyImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
