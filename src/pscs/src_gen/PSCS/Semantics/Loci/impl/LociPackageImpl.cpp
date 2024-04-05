#include "PSCS/Semantics/Loci/impl/LociPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"

//metamodel factory
#include "PSCS/Semantics/Loci/LociFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::Loci;

//Singleton implementation 
std::shared_ptr<LociPackage> LociPackage::eInstance()
{
	static std::shared_ptr<LociPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(LociPackageImpl::create());
		std::dynamic_pointer_cast<LociPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string LociPackage::eNAME ="Loci";
const std::string LociPackage::eNS_URI ="http:///PSCS_Semantics/Semantics/Loci.ecore";
const std::string LociPackage::eNS_PREFIX ="PSCS_Semantics.Semantics.Loci";

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
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Loci::LociPackageImpl::getCS_ExecutionFactory_Class() const
{
	return m_cS_ExecutionFactory_Class;
}


const std::shared_ptr<ecore::EReference>& PSCS::Semantics::Loci::LociPackageImpl::getCS_ExecutionFactory_Attribute_appliedProfiles() const
{
	return m_cS_ExecutionFactory_Attribute_appliedProfiles;
}

const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Loci::LociPackageImpl::getCS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element() const
{
	return m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Loci::LociPackageImpl::getCS_ExecutionFactory_Operation_getStereotypeClass_EString_EString() const
{
	return m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString;
}
const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Loci::LociPackageImpl::getCS_ExecutionFactory_Operation_instantiateVisitor_Element() const
{
	return m_cS_ExecutionFactory_Operation_instantiateVisitor_Element;
}

// End Class CS_ExecutionFactory

// Begin Class CS_Executor
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Loci::LociPackageImpl::getCS_Executor_Class() const
{
	return m_cS_Executor_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Loci::LociPackageImpl::getCS_Executor_Operation_start_Class_ParameterValue() const
{
	return m_cS_Executor_Operation_start_Class_ParameterValue;
}

// End Class CS_Executor

// Begin Class CS_Locus
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::Loci::LociPackageImpl::getCS_Locus_Class() const
{
	return m_cS_Locus_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::Semantics::Loci::LociPackageImpl::getCS_Locus_Operation_instantiate_Class() const
{
	return m_cS_Locus_Operation_instantiate_Class;
}

// End Class CS_Locus

