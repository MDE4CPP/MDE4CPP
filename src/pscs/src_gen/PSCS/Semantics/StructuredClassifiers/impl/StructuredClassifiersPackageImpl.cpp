#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//Singleton implementation 
std::shared_ptr<StructuredClassifiersPackage> StructuredClassifiersPackage::eInstance()
{
	static std::shared_ptr<StructuredClassifiersPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StructuredClassifiersPackageImpl::create());
		std::dynamic_pointer_cast<StructuredClassifiersPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string StructuredClassifiersPackage::eNAME ="StructuredClassifiers";
const std::string StructuredClassifiersPackage::eNS_URI ="http:///PSCS_Semantics/Semantics/StructuredClassifiers.ecore";
const std::string StructuredClassifiersPackage::eNS_PREFIX ="PSCS_Semantics.Semantics.StructuredClassifiers";

bool StructuredClassifiersPackageImpl::isInited = false;

StructuredClassifiersPackageImpl::StructuredClassifiersPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( StructuredClassifiersFactory::eInstance()));
}

StructuredClassifiersPackageImpl::~StructuredClassifiersPackageImpl()
{
}

StructuredClassifiersPackage* StructuredClassifiersPackageImpl::create()
{
	if (isInited)
	{
		return StructuredClassifiersPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    StructuredClassifiersPackageImpl * metaModelPackage = new StructuredClassifiersPackageImpl();
    return metaModelPackage;
}

void StructuredClassifiersPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class CS_DefaultRequestPropagationStrategy
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_DefaultRequestPropagationStrategy_Class() const
{
	return m_cS_DefaultRequestPropagationStrategy_Class;
}




// End Class CS_DefaultRequestPropagationStrategy

// Begin Class CS_DispatchOperationOfInterfaceStrategy
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_DispatchOperationOfInterfaceStrategy_Class() const
{
	return m_cS_DispatchOperationOfInterfaceStrategy_Class;
}




// End Class CS_DispatchOperationOfInterfaceStrategy

// Begin Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class() const
{
	return m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class;
}




// End Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy

// Begin Class CS_RequestPropagationStrategy
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_RequestPropagationStrategy_Class() const
{
	return m_cS_RequestPropagationStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_RequestPropagationStrategy_Operation_getName() const
{
	return m_cS_RequestPropagationStrategy_Operation_getName;
}

// End Class CS_RequestPropagationStrategy

// Begin Class CS_StructuralFeatureOfInterfaceAccessStrategy
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_StructuralFeatureOfInterfaceAccessStrategy_Class() const
{
	return m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName() const
{
	return m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName;
}

// End Class CS_StructuralFeatureOfInterfaceAccessStrategy
const std::shared_ptr<ecore::EEnum>& PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getCS_LinkKind_Class() const
{
	return m_cS_LinkKind_Class;
}

