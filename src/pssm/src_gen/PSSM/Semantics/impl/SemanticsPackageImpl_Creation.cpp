#include "PSSM/Semantics/impl/SemanticsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

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

//depending model packages
#include "PSSM/PSSMPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
#include "PSSM/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "PSSM/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "PSSM/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "PSSM/Semantics/StateMachines/impl/StateMachinesPackageImpl.hpp"

#include "PSSM/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "PSSM/Semantics/Values/impl/ValuesPackageImpl.hpp"
 
using namespace PSSM::Semantics;

void SemanticsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();


	createPackageEDataTypes(package, factory);

	std::dynamic_pointer_cast<PSSM::Semantics::Actions::ActionsPackageImpl>(getActions_Package())->createPackageContents(getActions_Package());

	std::dynamic_pointer_cast<PSSM::Semantics::CommonBehavior::CommonBehaviorPackageImpl>(getCommonBehavior_Package())->createPackageContents(getCommonBehavior_Package());

	std::dynamic_pointer_cast<PSSM::Semantics::Loci::LociPackageImpl>(getLoci_Package())->createPackageContents(getLoci_Package());

	std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateMachinesPackageImpl>(getStateMachines_Package())->createPackageContents(getStateMachines_Package());

	std::dynamic_pointer_cast<PSSM::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl>(getStructuredClassifiers_Package())->createPackageContents(getStructuredClassifiers_Package());

	std::dynamic_pointer_cast<PSSM::Semantics::Values::ValuesPackageImpl>(getValues_Package())->createPackageContents(getValues_Package());

}


void SemanticsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
