#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/Semantics/CommonBehavior/impl/CS_CallEventExecutionImpl.hpp"
#include "PSCS/Semantics/CommonBehavior/impl/CS_EventOccurrenceImpl.hpp"

#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Actions/CallActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Activities/DecisionNodeActivation.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"


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
			if (nullptr == container)
			{
				return this->createCS_CallEventExecution(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CS_CallEventExecution has callExecutions as a containment
					case  fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLEXECUTIONS:	
					{
						std::shared_ptr<fUML::Semantics::Actions::CallActionActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::CallActionActivation> (container);;
						return this->createCS_CallEventExecution_as_callExecutions_in_CallActionActivation(castedContainer,metaElementID);
					}
					//CS_CallEventExecution has decisionInputExecution as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONINPUTEXECUTION:	
					{
						std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::DecisionNodeActivation> (container);;
						return this->createCS_CallEventExecution_as_decisionInputExecution_in_DecisionNodeActivation(castedContainer,metaElementID);
					}
					//CS_CallEventExecution has extensionalValues as a containment
					case  fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXTENSIONALVALUES:	
					{
						std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus> (container);;
						return this->createCS_CallEventExecution_as_extensionalValues_in_Locus(castedContainer,metaElementID);
					}
					//CS_CallEventExecution has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createCS_CallEventExecution_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//CS_CallEventExecution has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createCS_CallEventExecution_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//CS_CallEventExecution has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createCS_CallEventExecution_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case CommonBehaviorPackage::CS_EVENTOCCURRENCE_CLASS:
		{
				return this->createCS_EventOccurrence(metaElementID);
			
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

std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> CommonBehaviorFactoryImpl::createCS_CallEventExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl> element(new PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_CallEventExecutionPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> CommonBehaviorFactoryImpl::createCS_CallEventExecution_as_callExecutions_in_CallActionActivation(std::shared_ptr<fUML::Semantics::Actions::CallActionActivation> par_CallActionActivation, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl> element(new PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallActionActivation)
	{
		par_CallActionActivation->getCallExecutions()->push_back(element);
	}
	
	element->setThisCS_CallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> CommonBehaviorFactoryImpl::createCS_CallEventExecution_as_decisionInputExecution_in_DecisionNodeActivation(std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> par_DecisionNodeActivation, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl> element(new PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_DecisionNodeActivation)
	{
		par_DecisionNodeActivation->setDecisionInputExecution(element);
	}
	
	element->setThisCS_CallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> CommonBehaviorFactoryImpl::createCS_CallEventExecution_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl> element(new PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	}
	
	element->setThisCS_CallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> CommonBehaviorFactoryImpl::createCS_CallEventExecution_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl> element(new PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisCS_CallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> CommonBehaviorFactoryImpl::createCS_CallEventExecution_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl> element(new PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisCS_CallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> CommonBehaviorFactoryImpl::createCS_CallEventExecution_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl> element(new PSCS::Semantics::CommonBehavior::CS_CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
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

