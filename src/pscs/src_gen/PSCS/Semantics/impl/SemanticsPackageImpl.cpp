#include "PSCS/Semantics/impl/SemanticsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

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

std::shared_ptr<Actions::ActionsPackage> SemanticsPackageImpl::getActions_Package() const
{
	return Actions::ActionsPackage::eInstance();
} 
std::shared_ptr<Classification::ClassificationPackage> SemanticsPackageImpl::getClassification_Package() const
{
	return Classification::ClassificationPackage::eInstance();
} 
std::shared_ptr<CommonBehavior::CommonBehaviorPackage> SemanticsPackageImpl::getCommonBehavior_Package() const
{
	return CommonBehavior::CommonBehaviorPackage::eInstance();
} 
std::shared_ptr<Loci::LociPackage> SemanticsPackageImpl::getLoci_Package() const
{
	return Loci::LociPackage::eInstance();
} 
std::shared_ptr<StructuredClassifiers::StructuredClassifiersPackage> SemanticsPackageImpl::getStructuredClassifiers_Package() const
{
	return StructuredClassifiers::StructuredClassifiersPackage::eInstance();
} 
std::shared_ptr<Values::ValuesPackage> SemanticsPackageImpl::getValues_Package() const
{
	return Values::ValuesPackage::eInstance();
} 



