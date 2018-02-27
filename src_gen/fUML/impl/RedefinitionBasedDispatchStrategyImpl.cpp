#include "fUML/impl/RedefinitionBasedDispatchStrategyImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Class.hpp"
#include "uml/Operation.hpp"

//Forward declaration includes
#include "uml/Behavior.hpp"

#include "fUML/DispatchStrategy.hpp"

#include "fUML/Object.hpp"

#include "uml/Operation.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
RedefinitionBasedDispatchStrategyImpl::RedefinitionBasedDispatchStrategyImpl()
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

RedefinitionBasedDispatchStrategyImpl::~RedefinitionBasedDispatchStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RedefinitionBasedDispatchStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




RedefinitionBasedDispatchStrategyImpl::RedefinitionBasedDispatchStrategyImpl(const RedefinitionBasedDispatchStrategyImpl & obj):RedefinitionBasedDispatchStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RedefinitionBasedDispatchStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  RedefinitionBasedDispatchStrategyImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new RedefinitionBasedDispatchStrategyImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> RedefinitionBasedDispatchStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getRedefinitionBasedDispatchStrategy_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool RedefinitionBasedDispatchStrategyImpl::operationsMatch(std::shared_ptr<uml::Operation>  ownedOperation,std::shared_ptr<uml::Operation>  baseOperation) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		//#include "NamedElement.hpp"
	//#include "Class.hpp"
	//#include "Operation.hpp"
	//
	bool matches = false;
	if(ownedOperation == baseOperation)
	{
		matches = true;
	}
	else
    {
		unsigned int i = 0;
		while(!matches && i < ownedOperation->getRedefinedOperation()->size())
        {
			matches = this->operationsMatch(ownedOperation->getRedefinedOperation()->at(i), baseOperation);
			i = i + 1;
        }
    }
	return matches;
	//end of body
}

std::shared_ptr<uml::Behavior> RedefinitionBasedDispatchStrategyImpl::retrieveMethod(std::shared_ptr<fUML::Object>  object,std::shared_ptr<uml::Operation>  operation) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::Behavior> method = nullptr;
	unsigned int i = 0;
	while(method == nullptr && (i < object->getTypes()->size()))
	{
		std::shared_ptr<uml::Class> type = std::dynamic_pointer_cast<uml::Class>(object->getTypes()->at(i));
		std::shared_ptr<Bag<uml::NamedElement> > members = type->getMember();
		unsigned int j = 0;
		while(method == nullptr && (j < members->size()))
		{
			std::shared_ptr<uml::NamedElement> member = members->at(j);
			std::shared_ptr<uml::Operation> memberOperation = std::dynamic_pointer_cast<uml::Operation>(member);
			if(memberOperation != nullptr)
			{	
				if(this->operationsMatch(memberOperation, operation))
				{
					method = memberOperation->getMethod()->at(0);
				}
			}
			j = j + 1;
		}
		i = i + 1;
	}

	return method;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<RedefinitionBasedDispatchStrategy> RedefinitionBasedDispatchStrategyImpl::getThisRedefinitionBasedDispatchStrategyPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<RedefinitionBasedDispatchStrategy>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> RedefinitionBasedDispatchStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RedefinitionBasedDispatchStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

void RedefinitionBasedDispatchStrategyImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
