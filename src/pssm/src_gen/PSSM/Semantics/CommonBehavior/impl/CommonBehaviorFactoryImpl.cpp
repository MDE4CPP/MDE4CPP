#include "PSSM/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSSM/Semantics/CommonBehavior/impl/CallEventExecutionImpl.hpp"
#include "PSSM/Semantics/CommonBehavior/impl/CallEventOccurrenceImpl.hpp"
#include "PSSM/Semantics/CommonBehavior/impl/EventTriggeredExecutionImpl.hpp"
#include "PSSM/Semantics/CommonBehavior/impl/SM_ObjectActivationImpl.hpp"

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"


using namespace PSSM::Semantics::CommonBehavior;

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
	m_idMap.insert(std::make_pair("PSSM::Semantics::CommonBehavior::CallEventExecution", CommonBehaviorPackage::CALLEVENTEXECUTION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::CommonBehavior::CallEventOccurrence", CommonBehaviorPackage::CALLEVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::CommonBehavior::EventTriggeredExecution", CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::CommonBehavior::SM_ObjectActivation", CommonBehaviorPackage::SM_OBJECTACTIVATION_CLASS));
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
		case CommonBehaviorPackage::CALLEVENTEXECUTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallEventExecution(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventExecution>(this->createCallEventExecution_as_extensionalValues_in_Locus(castedContainer,metaElementID));
			}
			break;
		}
		case CommonBehaviorPackage::CALLEVENTOCCURRENCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallEventOccurrence(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrence>(this->createCallEventOccurrence_as_eventPool_in_ObjectActivation(castedContainer,metaElementID));
			}
			break;
		}
		case CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEventTriggeredExecution(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::CommonBehavior::EventTriggeredExecution>(this->createEventTriggeredExecution_as_extensionalValues_in_Locus(castedContainer,metaElementID));
			}
			break;
		}
		case CommonBehaviorPackage::SM_OBJECTACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSM_ObjectActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> castedContainer = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::CommonBehavior::SM_ObjectActivation>(this->createSM_ObjectActivation_as_objectActivation_in_FUML_Object(castedContainer,metaElementID));
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

std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventExecution> CommonBehaviorFactoryImpl::createCallEventExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventExecutionImpl> element(new PSSM::Semantics::CommonBehavior::CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallEventExecutionPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventExecution> CommonBehaviorFactoryImpl::createCallEventExecution_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventExecutionImpl> element(new PSSM::Semantics::CommonBehavior::CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	}
	
	element->setThisCallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrence> CommonBehaviorFactoryImpl::createCallEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrenceImpl> element(new PSSM::Semantics::CommonBehavior::CallEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrence> CommonBehaviorFactoryImpl::createCallEventOccurrence_as_eventPool_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrenceImpl> element(new PSSM::Semantics::CommonBehavior::CallEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectActivation)
	{
		par_ObjectActivation->getEventPool()->push_back(element);
	}
	
	element->setThisCallEventOccurrencePtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::CommonBehavior::EventTriggeredExecution> CommonBehaviorFactoryImpl::createEventTriggeredExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::CommonBehavior::EventTriggeredExecutionImpl> element(new PSSM::Semantics::CommonBehavior::EventTriggeredExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEventTriggeredExecutionPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::CommonBehavior::EventTriggeredExecution> CommonBehaviorFactoryImpl::createEventTriggeredExecution_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::CommonBehavior::EventTriggeredExecutionImpl> element(new PSSM::Semantics::CommonBehavior::EventTriggeredExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	}
	
	element->setThisEventTriggeredExecutionPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::CommonBehavior::SM_ObjectActivation> CommonBehaviorFactoryImpl::createSM_ObjectActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::CommonBehavior::SM_ObjectActivationImpl> element(new PSSM::Semantics::CommonBehavior::SM_ObjectActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSM_ObjectActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::CommonBehavior::SM_ObjectActivation> CommonBehaviorFactoryImpl::createSM_ObjectActivation_as_objectActivation_in_FUML_Object(std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> par_FUML_Object, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::CommonBehavior::SM_ObjectActivationImpl> element(new PSSM::Semantics::CommonBehavior::SM_ObjectActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FUML_Object)
	{
		par_FUML_Object->setObjectActivation(element);
	}
	
	element->setThisSM_ObjectActivationPtr(element);
	return element;
	
}

