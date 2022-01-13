#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EGenericType.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

#include "fUML/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "fUML/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersPackageImpl.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"
 
using namespace fUML::Semantics;

void SemanticsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();


	createPackageEDataTypes(package, factory);

	std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionsPackageImpl>(getActions_Package())->createPackageContents(getActions_Package());

	std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivitiesPackageImpl>(getActivities_Package())->createPackageContents(getActivities_Package());

	std::dynamic_pointer_cast<fUML::Semantics::Classification::ClassificationPackageImpl>(getClassification_Package())->createPackageContents(getClassification_Package());

	std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl>(getCommonBehavior_Package())->createPackageContents(getCommonBehavior_Package());

	std::dynamic_pointer_cast<fUML::Semantics::Loci::LociPackageImpl>(getLoci_Package())->createPackageContents(getLoci_Package());

	std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackageImpl>(getSimpleClassifiers_Package())->createPackageContents(getSimpleClassifiers_Package());

	std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl>(getStructuredClassifiers_Package())->createPackageContents(getStructuredClassifiers_Package());

	std::dynamic_pointer_cast<fUML::Semantics::Values::ValuesPackageImpl>(getValues_Package())->createPackageContents(getValues_Package());

}


void SemanticsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
