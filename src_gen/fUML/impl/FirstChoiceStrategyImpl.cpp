#include "fUML/impl/FirstChoiceStrategyImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/ChoiceStrategy.hpp"


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

std::shared_ptr<ecore::EObject>  FirstChoiceStrategyImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new FirstChoiceStrategyImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> FirstChoiceStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getFirstChoiceStrategy_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
int FirstChoiceStrategyImpl::choose(int size) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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


std::shared_ptr<FirstChoiceStrategy> FirstChoiceStrategyImpl::getThisFirstChoiceStrategyPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<FirstChoiceStrategy>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> FirstChoiceStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any FirstChoiceStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

void FirstChoiceStrategyImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
