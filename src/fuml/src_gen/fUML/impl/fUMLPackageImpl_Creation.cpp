#include "fUML/impl/fUMLPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"
 
using namespace fUML;

void fUMLPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();


	createPackageEDataTypes(package, factory);

	std::dynamic_pointer_cast<fUML::Semantics::SemanticsPackageImpl>(getSemantics_Package())->createPackageContents(getSemantics_Package());

}


void fUMLPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
