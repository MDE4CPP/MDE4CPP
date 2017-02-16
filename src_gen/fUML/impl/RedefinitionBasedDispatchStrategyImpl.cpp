#include "RedefinitionBasedDispatchStrategyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "NamedElement.hpp"
#include "Class.hpp"
#include "Operation.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
RedefinitionBasedDispatchStrategyImpl::RedefinitionBasedDispatchStrategyImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

RedefinitionBasedDispatchStrategyImpl::~RedefinitionBasedDispatchStrategyImpl()
{
	
}

RedefinitionBasedDispatchStrategyImpl::RedefinitionBasedDispatchStrategyImpl(const RedefinitionBasedDispatchStrategyImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  RedefinitionBasedDispatchStrategyImpl::copy() const
{
	return new RedefinitionBasedDispatchStrategyImpl(*this);
}

ecore::EClass* RedefinitionBasedDispatchStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getRedefinitionBasedDispatchStrategy();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool RedefinitionBasedDispatchStrategyImpl::operationsMatch(uml::Operation *  ownedOperation,uml::Operation *  baseOperation) 
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
    int i = 1;
    while(!matches && i <= ownedOperation->getRedefinedOperation()->size())
        {
        matches = this->operationsMatch(ownedOperation->getRedefinedOperation()->at(i - 1), baseOperation);
        i = i + 1;
        }
    }

return matches;

}

uml::Behavior *  RedefinitionBasedDispatchStrategyImpl::retrieveMethod(fUML::Object *  object,uml::Operation *  operation) 
{
	//generated from body annotation
	uml::Behavior * method = nullptr;
        int i = 1;
        while(method == nullptr && (i <= object->getTypes()->size()))
            {
            uml::Class * type = dynamic_cast <uml::Class * > (object->getTypes()->at(i - 1));
            std::vector<uml::NamedElement *> * members = type->getMember();
            int j = 1;
            while(method == nullptr && (j <= members->size()))
                {
                uml::NamedElement * member = members->at(j - 1);
                if(dynamic_cast<uml::Operation * >(member) != nullptr)
                    {
                    uml::Operation * memberOperation = dynamic_cast<uml::Operation *>(member);
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
