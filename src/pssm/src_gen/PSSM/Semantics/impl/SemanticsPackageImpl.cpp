#include "PSSM/Semantics/impl/SemanticsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EEnum.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "PSSM/Semantics/SemanticsFactory.hpp"

//depending model packages
#include "PSSM/PSSMPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "PSSM/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "PSSM/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "PSSM/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "PSSM/Semantics/StateMachines/impl/StateMachinesPackageImpl.hpp"

#include "PSSM/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "PSSM/Semantics/Values/impl/ValuesPackageImpl.hpp"

using namespace PSSM::Semantics;

//Singleton implementation 
std::shared_ptr<SemanticsPackage> SemanticsPackage::eInstance()
{
	static std::shared_ptr<SemanticsPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SemanticsPackageImpl::create());
		std::dynamic_pointer_cast<SemanticsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string SemanticsPackage::eNAME ="Semantics";
const std::string SemanticsPackage::eNS_URI ="http:///PSSM/Semantics.ecore";
const std::string SemanticsPackage::eNS_PREFIX ="PSSM.Semantics";

bool SemanticsPackageImpl::isInited = false;

SemanticsPackageImpl::SemanticsPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( SemanticsFactory::eInstance()));
}

SemanticsPackageImpl::~SemanticsPackageImpl()
{
}

SemanticsPackage* SemanticsPackageImpl::create()
{
	if (isInited)
	{
		return SemanticsPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    SemanticsPackageImpl * metaModelPackage = new SemanticsPackageImpl();
    return metaModelPackage;
}

void SemanticsPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

std::shared_ptr<PSSM::Semantics::Actions::ActionsPackage> PSSM::Semantics::SemanticsPackageImpl::getActions_Package() const
{
	return PSSM::Semantics::Actions::ActionsPackage::eInstance();
} 
std::shared_ptr<PSSM::Semantics::CommonBehavior::CommonBehaviorPackage> PSSM::Semantics::SemanticsPackageImpl::getCommonBehavior_Package() const
{
	return PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
} 
std::shared_ptr<PSSM::Semantics::Loci::LociPackage> PSSM::Semantics::SemanticsPackageImpl::getLoci_Package() const
{
	return PSSM::Semantics::Loci::LociPackage::eInstance();
} 
std::shared_ptr<PSSM::Semantics::StateMachines::StateMachinesPackage> PSSM::Semantics::SemanticsPackageImpl::getStateMachines_Package() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance();
} 
std::shared_ptr<PSSM::Semantics::StructuredClassifiers::StructuredClassifiersPackage> PSSM::Semantics::SemanticsPackageImpl::getStructuredClassifiers_Package() const
{
	return PSSM::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
} 
std::shared_ptr<PSSM::Semantics::Values::ValuesPackage> PSSM::Semantics::SemanticsPackageImpl::getValues_Package() const
{
	return PSSM::Semantics::Values::ValuesPackage::eInstance();
} 



