#include "PSCS/Semantics/impl/SemanticsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EPackage.hpp"

//metamodel factory
#include "PSCS/Semantics/SemanticsFactory.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "PSCS/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "PSCS/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "PSCS/Semantics/Values/impl/ValuesPackageImpl.hpp"

using namespace PSCS::Semantics;

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

std::shared_ptr<PSCS::Semantics::Actions::ActionsPackage> PSCS::Semantics::SemanticsPackageImpl::getActions_Package() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance();
} 
std::shared_ptr<PSCS::Semantics::Classification::ClassificationPackage> PSCS::Semantics::SemanticsPackageImpl::getClassification_Package() const
{
	return PSCS::Semantics::Classification::ClassificationPackage::eInstance();
} 
std::shared_ptr<PSCS::Semantics::CommonBehavior::CommonBehaviorPackage> PSCS::Semantics::SemanticsPackageImpl::getCommonBehavior_Package() const
{
	return PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
} 
std::shared_ptr<PSCS::Semantics::Loci::LociPackage> PSCS::Semantics::SemanticsPackageImpl::getLoci_Package() const
{
	return PSCS::Semantics::Loci::LociPackage::eInstance();
} 
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage> PSCS::Semantics::SemanticsPackageImpl::getStructuredClassifiers_Package() const
{
	return PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
} 
std::shared_ptr<PSCS::Semantics::Values::ValuesPackage> PSCS::Semantics::SemanticsPackageImpl::getValues_Package() const
{
	return PSCS::Semantics::Values::ValuesPackage::eInstance();
} 



