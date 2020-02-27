#include "PSCS/impl/PSCSFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"

#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/Actions/impl/CS_AcceptCallActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_AcceptEventActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_AddStructuralFeatureValueActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_CallOperationActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_ClearStructuralFeatureActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_ConstructStrategyImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_CreateLinkActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_CreateObjectActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_DefaultConstructStrategyImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_ReadExtentActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_ReadSelfActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_RemoveStructuralFeatureValueActionActivationImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_SendSignalActionActivationImpl.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "PSCS/Semantics/Classification/impl/CS_InstanceValueEvaluationImpl.hpp"


#include "PSCS/Semantics/CommonBehavior/impl/CS_CallEventExecutionImpl.hpp"
#include "PSCS/Semantics/CommonBehavior/impl/CS_EventOccurrenceImpl.hpp"


#include "PSCS/Semantics/Loci/impl/CS_ExecutionFactoryImpl.hpp"
#include "PSCS/Semantics/Loci/impl/CS_ExecutorImpl.hpp"
#include "PSCS/Semantics/Loci/impl/CS_LocusImpl.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"

#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DefaultRequestPropagationStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DispatchOperationOfInterfaceStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_InteractionPointImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_LinkImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ObjectImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ReferenceImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_RequestPropagationStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"


#include "PSCS/Semantics/Values/impl/CS_OpaqueExpressionEvaluationImpl.hpp"







using namespace PSCS;

//*********************************
// Constructor / Destructor
//*********************************

PSCSFactoryImpl::PSCSFactoryImpl()
{
}

PSCSFactoryImpl::~PSCSFactoryImpl()
{
}

PSCSFactory* PSCSFactoryImpl::create()
{
	return new PSCSFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> PSCSFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> PSCSFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> PSCSFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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


std::shared_ptr<PSCSPackage> PSCSFactoryImpl::getPSCSPackage() const
{
	return PSCSPackage::eInstance();
}
