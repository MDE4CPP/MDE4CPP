#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/Semantics/CommonBehavior/impl/CS_CallEventExecutionImpl.hpp"
#include "PSCS/Semantics/CommonBehavior/impl/CS_EventOccurrenceImpl.hpp"



using namespace PSCS::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************

CommonBehaviorFactoryImpl::CommonBehaviorFactoryImpl()
{
	m_idMap.insert(std::make_pair("PSCS::Semantics::CommonBehavior::CS_CallEventExecution", CommonBehaviorPackage::CS_CALLEVENTEXECUTION_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::CommonBehavior::CS_EventOccurrence", CommonBehaviorPackage::CS_EVENTOCCURRENCE_CLASS));
}

CommonBehaviorFactoryImpl::~CommonBehaviorFactoryImpl()
{
}

CommonBehaviorFactory* CommonBehaviorFactoryImpl::create()
{
	return new CommonBehaviorFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> CommonBehaviorFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case CommonBehaviorPackage::CS_CALLEVENTEXECUTION_CLASS:
		{
				return this->createCS_CallEventExecution(metaElementID);
			
		}
		case CommonBehaviorPackage::CS_EVENTOCCURRENCE_CLASS:
		{
				return this->createCS_EventOccurrence(metaElementID);
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> CommonBehaviorFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> CommonBehaviorFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}

std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> CommonBehaviorFactoryImpl::createCS_CallEventExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl> element(new PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_CallEventExecutionPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrence> CommonBehaviorFactoryImpl::createCS_EventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrenceImpl> element(new PSCS::Semantics::CommonBehavior::CS_EventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_EventOccurrencePtr(element);
	return element;
}

