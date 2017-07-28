#include "RedefinitionBasedDispatchStrategyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "NamedElement.hpp"
#include "Class.hpp"
#include "Operation.hpp"


//Forward declaration includes
#include "Behavior.hpp";

#include "DispatchStrategy.hpp";

#include "Object.hpp";

#include "Operation.hpp";


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

ecore::EObject *  RedefinitionBasedDispatchStrategyImpl::copy() const
{
	return new RedefinitionBasedDispatchStrategyImpl(*this);
}

std::shared_ptr<ecore::EClass> RedefinitionBasedDispatchStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getRedefinitionBasedDispatchStrategy();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 RedefinitionBasedDispatchStrategyImpl::operationsMatch(std::shared_ptr<uml::Operation>  ownedOperation,std::shared_ptr<uml::Operation>  baseOperation) 
{
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
}

std::shared_ptr<uml::Behavior> 
 RedefinitionBasedDispatchStrategyImpl::retrieveMethod(std::shared_ptr<fUML::Object>  object,std::shared_ptr<uml::Operation>  operation) 
{
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
boost::any RedefinitionBasedDispatchStrategyImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
