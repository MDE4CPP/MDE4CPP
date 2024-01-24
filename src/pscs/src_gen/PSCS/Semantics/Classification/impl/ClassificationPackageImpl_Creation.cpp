#include "PSCS/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EGenericType.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"
//include subpackages 
 
using namespace PSCS::Semantics::Classification;

void ClassificationPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();


	createPackageEDataTypes(package, factory);

}


void ClassificationPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
