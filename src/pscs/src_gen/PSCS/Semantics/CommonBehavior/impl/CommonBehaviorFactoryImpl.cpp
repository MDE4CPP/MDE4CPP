#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/Semantics/CommonBehavior/impl/CS_EventOccurrenceImpl.hpp"

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"


using namespace PSCS::Semantics::CommonBehavior;

std::shared_ptr<CommonBehaviorFactory> CommonBehaviorFactory::eInstance()
{
	static std::shared_ptr<CommonBehaviorFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(CommonBehaviorFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

CommonBehaviorFactoryImpl::CommonBehaviorFactoryImpl()
{
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
		case CommonBehaviorPackage::CS_EVENTOCCURRENCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_EventOccurrence(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrence>(this->createCS_EventOccurrence_as_eventPool_in_ObjectActivation(castedContainer,metaElementID));
			}
			break;
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

std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrence> CommonBehaviorFactoryImpl::createCS_EventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrenceImpl> element(new PSCS::Semantics::CommonBehavior::CS_EventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_EventOccurrencePtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrence> CommonBehaviorFactoryImpl::createCS_EventOccurrence_as_eventPool_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrenceImpl> element(new PSCS::Semantics::CommonBehavior::CS_EventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectActivation)
	{
		par_ObjectActivation->getEventPool()->push_back(element);
	}
	
	element->setThisCS_EventOccurrencePtr(element);
	return element;
	
}

