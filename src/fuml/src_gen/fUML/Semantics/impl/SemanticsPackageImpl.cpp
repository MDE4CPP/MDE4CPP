#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "fUML/Semantics/SemanticsFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
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

std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> fUML::Semantics::SemanticsPackageImpl::getActions_Package() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance();
} 
std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> fUML::Semantics::SemanticsPackageImpl::getActivities_Package() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance();
} 
std::shared_ptr<fUML::Semantics::Classification::ClassificationPackage> fUML::Semantics::SemanticsPackageImpl::getClassification_Package() const
{
	return fUML::Semantics::Classification::ClassificationPackage::eInstance();
} 
std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> fUML::Semantics::SemanticsPackageImpl::getCommonBehavior_Package() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
} 
std::shared_ptr<fUML::Semantics::Loci::LociPackage> fUML::Semantics::SemanticsPackageImpl::getLoci_Package() const
{
	return fUML::Semantics::Loci::LociPackage::eInstance();
} 
std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> fUML::Semantics::SemanticsPackageImpl::getSimpleClassifiers_Package() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();
} 
std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage> fUML::Semantics::SemanticsPackageImpl::getStructuredClassifiers_Package() const
{
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
} 
std::shared_ptr<fUML::Semantics::Values::ValuesPackage> fUML::Semantics::SemanticsPackageImpl::getValues_Package() const
{
	return fUML::Semantics::Values::ValuesPackage::eInstance();
} 



