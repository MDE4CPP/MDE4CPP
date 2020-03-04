#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "fUML/Semantics/SemanticsFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "types/TypesPackage.hpp"
#include "uml/UmlPackage.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

#include "fUML/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "fUML/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersPackageImpl.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"

using namespace fUML::Semantics;

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
std::shared_ptr<Activities::ActivitiesPackage> SemanticsPackageImpl::getActivities_Package() const
{
	return Activities::ActivitiesPackage::eInstance();
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
std::shared_ptr<SimpleClassifiers::SimpleClassifiersPackage> SemanticsPackageImpl::getSimpleClassifiers_Package() const
{
	return SimpleClassifiers::SimpleClassifiersPackage::eInstance();
} 
std::shared_ptr<StructuredClassifiers::StructuredClassifiersPackage> SemanticsPackageImpl::getStructuredClassifiers_Package() const
{
	return StructuredClassifiers::StructuredClassifiersPackage::eInstance();
} 
std::shared_ptr<Values::ValuesPackage> SemanticsPackageImpl::getValues_Package() const
{
	return Values::ValuesPackage::eInstance();
} 



