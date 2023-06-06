#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ClassifierBehaviorExecutionImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventAccepterImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventOccurrenceImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ExecutionImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ObjectActivationImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ParameterValueImpl.hpp"

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
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
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution", CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::EventOccurrence", CommonBehaviorPackage::EVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::ObjectActivation", CommonBehaviorPackage::OBJECTACTIVATION_CLASS));
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
		case CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClassifierBehaviorExecution(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>(this->createClassifierBehaviorExecution_as_classifierBehaviorExecutions_in_ObjectActivation(castedContainer,metaElementID));
			}
			break;
		}
		case CommonBehaviorPackage::EVENTOCCURRENCE_CLASS:
		{
				return this->createEventOccurrence(metaElementID);
			
			break;
		}
		case CommonBehaviorPackage::OBJECTACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createObjectActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> castedContainer = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation>(this->createObjectActivation_as_objectActivation_in_FUML_Object(castedContainer,metaElementID));
			}
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

std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> CommonBehaviorFactoryImpl::createClassifierBehaviorExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecutionImpl> element(new fUML::Semantics::CommonBehavior::ClassifierBehaviorExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClassifierBehaviorExecutionPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> CommonBehaviorFactoryImpl::createClassifierBehaviorExecution_as_classifierBehaviorExecutions_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecutionImpl> element(new fUML::Semantics::CommonBehavior::ClassifierBehaviorExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectActivation)
	{
		par_ObjectActivation->getClassifierBehaviorExecutions()->push_back(element);
	}
	
	element->setThisClassifierBehaviorExecutionPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> CommonBehaviorFactoryImpl::createEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrenceImpl> element(new fUML::Semantics::CommonBehavior::EventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> CommonBehaviorFactoryImpl::createObjectActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivationImpl> element(new fUML::Semantics::CommonBehavior::ObjectActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisObjectActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> CommonBehaviorFactoryImpl::createObjectActivation_as_objectActivation_in_FUML_Object(std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> par_FUML_Object, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivationImpl> element(new fUML::Semantics::CommonBehavior::ObjectActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FUML_Object)
	{
		par_FUML_Object->setObjectActivation(element);
	}
	
	element->setThisObjectActivationPtr(element);
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

