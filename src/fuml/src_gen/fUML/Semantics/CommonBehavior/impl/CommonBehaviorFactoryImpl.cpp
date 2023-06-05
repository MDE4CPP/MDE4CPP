#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventAccepterImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventOccurrenceImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ExecutionImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ParameterValueImpl.hpp"

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/umlPackage.hpp"
#include "uml/DirectedRelationship.hpp"


using namespace fUML::Semantics::CommonBehavior;

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
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::EventOccurrence", CommonBehaviorPackage::EVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::ParameterValue", CommonBehaviorPackage::PARAMETERVALUE_CLASS));
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
		case CommonBehaviorPackage::EVENTOCCURRENCE_CLASS:
		{
				return this->createEventOccurrence(metaElementID);
			
			break;
		}
		case CommonBehaviorPackage::PARAMETERVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createParameterValue(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>(this->createParameterValue_as_parameterValues_in_Execution(castedContainer,metaElementID));
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

std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> CommonBehaviorFactoryImpl::createEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrenceImpl> element(new fUML::Semantics::CommonBehavior::EventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> CommonBehaviorFactoryImpl::createParameterValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValueImpl> element(new fUML::Semantics::CommonBehavior::ParameterValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisParameterValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> CommonBehaviorFactoryImpl::createParameterValue_as_parameterValues_in_Execution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> par_Execution, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValueImpl> element(new fUML::Semantics::CommonBehavior::ParameterValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Execution)
	{
		par_Execution->getParameterValues()->push_back(element);
	}
	
	element->setThisParameterValuePtr(element);
	return element;
	
}

