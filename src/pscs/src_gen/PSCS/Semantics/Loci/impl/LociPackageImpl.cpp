#include "PSCS/Semantics/Loci/impl/LociPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"

//metamodel factory
#include "PSCS/Semantics/Loci/LociFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::Loci;

bool LociPackageImpl::isInited = false;

LociPackageImpl::LociPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( LociFactory::eInstance()));
}

LociPackageImpl::~LociPackageImpl()
{
}

LociPackage* LociPackageImpl::create()
{
	if (isInited)
	{
		return LociPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    LociPackageImpl * metaModelPackage = new LociPackageImpl();
    return metaModelPackage;
}

void LociPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class CS_ExecutionFactory
std::shared_ptr<ecore::EClass> PSCS::Semantics::Loci::LociPackageImpl::getCS_ExecutionFactory_Class() const
{
	return m_cS_ExecutionFactory_Class;
}


std::shared_ptr<ecore::EReference> PSCS::Semantics::Loci::LociPackageImpl::getCS_ExecutionFactory_Attribute_appliedProfiles() const
{
	return m_cS_ExecutionFactory_Attribute_appliedProfiles;
}

std::shared_ptr<ecore::EOperation> PSCS::Semantics::Loci::LociPackageImpl::getCS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element() const
{
	return m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::Loci::LociPackageImpl::getCS_ExecutionFactory_Operation_getStereotypeClass_EString_EString() const
{
	return m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString;
}
std::shared_ptr<ecore::EOperation> PSCS::Semantics::Loci::LociPackageImpl::getCS_ExecutionFactory_Operation_instantiateVisitor_Element() const
{
	return m_cS_ExecutionFactory_Operation_instantiateVisitor_Element;
}

// End Class CS_ExecutionFactory

// Begin Class CS_Executor
std::shared_ptr<ecore::EClass> PSCS::Semantics::Loci::LociPackageImpl::getCS_Executor_Class() const
{
	return m_cS_Executor_Class;
}



std::shared_ptr<ecore::EOperation> PSCS::Semantics::Loci::LociPackageImpl::getCS_Executor_Operation_start_Class_ParameterValue() const
{
	return m_cS_Executor_Operation_start_Class_ParameterValue;
}

// End Class CS_Executor

// Begin Class CS_Locus
std::shared_ptr<ecore::EClass> PSCS::Semantics::Loci::LociPackageImpl::getCS_Locus_Class() const
{
	return m_cS_Locus_Class;
}



std::shared_ptr<ecore::EOperation> PSCS::Semantics::Loci::LociPackageImpl::getCS_Locus_Operation_instantiate_Class() const
{
	return m_cS_Locus_Operation_instantiate_Class;
}

// End Class CS_Locus

