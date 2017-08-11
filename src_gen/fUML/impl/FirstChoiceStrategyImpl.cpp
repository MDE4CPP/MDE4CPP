#include "FirstChoiceStrategyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "ChoiceStrategy.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
FirstChoiceStrategyImpl::FirstChoiceStrategyImpl()
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

FirstChoiceStrategyImpl::~FirstChoiceStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FirstChoiceStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

FirstChoiceStrategyImpl::FirstChoiceStrategyImpl(const FirstChoiceStrategyImpl & obj):FirstChoiceStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FirstChoiceStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

    
	//Clone references with containment (deep copy)



}

ecore::EObject *  FirstChoiceStrategyImpl::copy() const
{
	return new FirstChoiceStrategyImpl(*this);
}

std::shared_ptr<ecore::EClass> FirstChoiceStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getFirstChoiceStrategy();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
int FirstChoiceStrategyImpl::choose(int size) 
{
	//generated from body annotation
	return 1;
	//end of body
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
