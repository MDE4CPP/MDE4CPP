#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/AddStructuralFeatureValueActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallBehaviorActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallOperationActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ClearStructuralFeatureActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/CreateObjectActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/DestroyObjectActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ExpansionActivationGroupImpl.hpp"
#include "fUML/Semantics/Actions/impl/ExpansionNodeActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ExpansionRegionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/InputPinActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/InvocationActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/OutputPinActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/PinActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadIsClassifiedObjectActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadSelfActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ReadStructuralFeatureActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/RemoveStructuralFeatureValueActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/StructuralFeatureActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/StructuredActivityNodeActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ValueSpecificationActionActivationImpl.hpp"
#include "fUML/Semantics/Actions/impl/ValuesImpl.hpp"
#include "fUML/Semantics/Actions/impl/WriteStructuralFeatureActionActivationImpl.hpp"

#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"


using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************

ActionsFactoryImpl::ActionsFactoryImpl()
{
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation", ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::CallBehaviorActionActivation", ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::CallOperationActionActivation", ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ClearStructuralFeatureActionActivation", ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::CreateObjectActionActivation", ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::DestroyObjectActionActivation", ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ExpansionActivationGroup", ActionsPackage::EXPANSIONACTIVATIONGROUP_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ExpansionNodeActivation", ActionsPackage::EXPANSIONNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ExpansionRegionActivation", ActionsPackage::EXPANSIONREGIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::InputPinActivation", ActionsPackage::INPUTPINACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::OutputPinActivation", ActionsPackage::OUTPUTPINACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation", ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadSelfActionActivation", ActionsPackage::READSELFACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ReadStructuralFeatureActionActivation", ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivation", ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::StructuredActivityNodeActivation", ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::ValueSpecificationActionActivation", ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Actions::Values", ActionsPackage::VALUES_CLASS));
}

ActionsFactoryImpl::~ActionsFactoryImpl()
{
}

ActionsFactory* ActionsFactoryImpl::create()
{
	return new ActionsFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> ActionsFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAddStructuralFeatureValueActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation>(this->createAddStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallBehaviorActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation>(this->createCallBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallOperationActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation>(this->createCallOperationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClearStructuralFeatureActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation>(this->createClearStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCreateObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation>(this->createCreateObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDestroyObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation>(this->createDestroyObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::EXPANSIONACTIVATIONGROUP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionActivationGroup(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExpansionActivationGroup has activationGroup as a containment
					case  fUML::Semantics::Actions::ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_ATTRIBUTE_ACTIVATIONGROUP:	
					{
						std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::StructuredActivityNodeActivation> (container);
						return this->createExpansionActivationGroup_as_activationGroup_in_StructuredActivityNodeActivation(castedContainer,metaElementID);
					}
					//ExpansionActivationGroup has activationGroup as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVATIONGROUP:	
					{
						std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityExecution> (container);
						return this->createExpansionActivationGroup_as_activationGroup_in_ActivityExecution(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ActionsPackage::EXPANSIONNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivation>(this->createExpansionNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::EXPANSIONREGIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionRegionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation>(this->createExpansionRegionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::INPUTPINACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInputPinActivation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InputPinActivation has inputPinActivation as a containment
					case  fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION:	
					{
						std::shared_ptr<fUML::Semantics::Actions::ActionActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionActivation> (container);;
						return this->createInputPinActivation_as_inputPinActivation_in_ActionActivation(castedContainer,metaElementID);
					}
					//InputPinActivation has nodeActivations as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS:	
					{
						std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup> (container);
						return this->createInputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ActionsPackage::OUTPUTPINACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOutputPinActivation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OutputPinActivation has nodeActivations as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS:	
					{
						std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup> (container);
						return this->createOutputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID);
					}
					//OutputPinActivation has outputPinActivation as a containment
					case  fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION:	
					{
						std::shared_ptr<fUML::Semantics::Actions::ActionActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionActivation> (container);;
						return this->createOutputPinActivation_as_outputPinActivation_in_ActionActivation(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadIsClassifiedObjectActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation>(this->createReadIsClassifiedObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::READSELFACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadSelfActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation>(this->createReadSelfActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadStructuralFeatureActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation>(this->createReadStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRemoveStructuralFeatureValueActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivation>(this->createRemoveStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStructuredActivityNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation>(this->createStructuredActivityNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createValueSpecificationActionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation>(this->createValueSpecificationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActionsPackage::VALUES_CLASS:
		{
				return this->createValues(metaElementID);
			
			break;
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> ActionsFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> ActionsFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> ActionsFactoryImpl::createAddStructuralFeatureValueActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl> element(new fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAddStructuralFeatureValueActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> ActionsFactoryImpl::createAddStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl> element(new fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisAddStructuralFeatureValueActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> ActionsFactoryImpl::createCallBehaviorActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::CallBehaviorActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallBehaviorActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> ActionsFactoryImpl::createCallBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivationImpl> element(new fUML::Semantics::Actions::CallBehaviorActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisCallBehaviorActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> ActionsFactoryImpl::createCallOperationActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivationImpl> element(new fUML::Semantics::Actions::CallOperationActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallOperationActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> ActionsFactoryImpl::createCallOperationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivationImpl> element(new fUML::Semantics::Actions::CallOperationActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisCallOperationActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> ActionsFactoryImpl::createClearStructuralFeatureActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClearStructuralFeatureActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> ActionsFactoryImpl::createClearStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisClearStructuralFeatureActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> ActionsFactoryImpl::createCreateObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivationImpl> element(new fUML::Semantics::Actions::CreateObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCreateObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> ActionsFactoryImpl::createCreateObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivationImpl> element(new fUML::Semantics::Actions::CreateObjectActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisCreateObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> ActionsFactoryImpl::createDestroyObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivationImpl> element(new fUML::Semantics::Actions::DestroyObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDestroyObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> ActionsFactoryImpl::createDestroyObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivationImpl> element(new fUML::Semantics::Actions::DestroyObjectActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisDestroyObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroup> ActionsFactoryImpl::createExpansionActivationGroup(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroupImpl> element(new fUML::Semantics::Actions::ExpansionActivationGroupImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpansionActivationGroupPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroup> ActionsFactoryImpl::createExpansionActivationGroup_as_activationGroup_in_StructuredActivityNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> par_StructuredActivityNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroupImpl> element(new fUML::Semantics::Actions::ExpansionActivationGroupImpl(par_StructuredActivityNodeActivation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_StructuredActivityNodeActivation.lock())
	{
		wp->setActivationGroup(element);
	}
	
	element->setThisExpansionActivationGroupPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroup> ActionsFactoryImpl::createExpansionActivationGroup_as_activationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> par_ActivityExecution, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroupImpl> element(new fUML::Semantics::Actions::ExpansionActivationGroupImpl(par_ActivityExecution));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityExecution.lock())
	{
		wp->setActivationGroup(element);
	}
	
	element->setThisExpansionActivationGroupPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivation> ActionsFactoryImpl::createExpansionNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivationImpl> element(new fUML::Semantics::Actions::ExpansionNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpansionNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivation> ActionsFactoryImpl::createExpansionNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivationImpl> element(new fUML::Semantics::Actions::ExpansionNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisExpansionNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation> ActionsFactoryImpl::createExpansionRegionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivationImpl> element(new fUML::Semantics::Actions::ExpansionRegionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpansionRegionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation> ActionsFactoryImpl::createExpansionRegionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivationImpl> element(new fUML::Semantics::Actions::ExpansionRegionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisExpansionRegionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> ActionsFactoryImpl::createInputPinActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::InputPinActivationImpl> element(new fUML::Semantics::Actions::InputPinActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInputPinActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> ActionsFactoryImpl::createInputPinActivation_as_inputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::InputPinActivationImpl> element(new fUML::Semantics::Actions::InputPinActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ActionActivation)
	{
		par_ActionActivation->getInputPinActivation()->push_back(element);
	}
	
	element->setThisInputPinActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> ActionsFactoryImpl::createInputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::InputPinActivationImpl> element(new fUML::Semantics::Actions::InputPinActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisInputPinActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> ActionsFactoryImpl::createOutputPinActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::OutputPinActivationImpl> element(new fUML::Semantics::Actions::OutputPinActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOutputPinActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> ActionsFactoryImpl::createOutputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::OutputPinActivationImpl> element(new fUML::Semantics::Actions::OutputPinActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisOutputPinActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> ActionsFactoryImpl::createOutputPinActivation_as_outputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::OutputPinActivationImpl> element(new fUML::Semantics::Actions::OutputPinActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ActionActivation)
	{
		par_ActionActivation->getOutputPinActivation()->push_back(element);
	}
	
	element->setThisOutputPinActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> ActionsFactoryImpl::createReadIsClassifiedObjectActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadIsClassifiedObjectActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> ActionsFactoryImpl::createReadIsClassifiedObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl> element(new fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisReadIsClassifiedObjectActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> ActionsFactoryImpl::createReadSelfActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivationImpl> element(new fUML::Semantics::Actions::ReadSelfActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadSelfActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> ActionsFactoryImpl::createReadSelfActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivationImpl> element(new fUML::Semantics::Actions::ReadSelfActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisReadSelfActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> ActionsFactoryImpl::createReadStructuralFeatureActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadStructuralFeatureActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> ActionsFactoryImpl::createReadStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl> element(new fUML::Semantics::Actions::ReadStructuralFeatureActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisReadStructuralFeatureActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivation> ActionsFactoryImpl::createRemoveStructuralFeatureValueActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivationImpl> element(new fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRemoveStructuralFeatureValueActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivation> ActionsFactoryImpl::createRemoveStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivationImpl> element(new fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisRemoveStructuralFeatureValueActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> ActionsFactoryImpl::createStructuredActivityNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivationImpl> element(new fUML::Semantics::Actions::StructuredActivityNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStructuredActivityNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> ActionsFactoryImpl::createStructuredActivityNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivationImpl> element(new fUML::Semantics::Actions::StructuredActivityNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisStructuredActivityNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> ActionsFactoryImpl::createValueSpecificationActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivationImpl> element(new fUML::Semantics::Actions::ValueSpecificationActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisValueSpecificationActionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> ActionsFactoryImpl::createValueSpecificationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivationImpl> element(new fUML::Semantics::Actions::ValueSpecificationActionActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisValueSpecificationActionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Actions::Values> ActionsFactoryImpl::createValues(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Actions::ValuesImpl> element(new fUML::Semantics::Actions::ValuesImpl());
	element->setMetaElementID(metaElementID);
	element->setThisValuesPtr(element);
	return element;
}

