#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "fUML/Semantics/Values/ValuesFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Values;

//Singleton implementation 
std::shared_ptr<ValuesPackage> ValuesPackage::eInstance()
{
	static std::shared_ptr<ValuesPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ValuesPackageImpl::create());
		std::dynamic_pointer_cast<ValuesPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string ValuesPackage::eNAME ="Values";
const std::string ValuesPackage::eNS_URI ="http:///fUML_Semantics/Semantics/Values.ecore";
const std::string ValuesPackage::eNS_PREFIX ="fUML_Semantics.Semantics.Values";

bool ValuesPackageImpl::isInited = false;

ValuesPackageImpl::ValuesPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( ValuesFactory::eInstance()));
}

ValuesPackageImpl::~ValuesPackageImpl()
{
}

ValuesPackage* ValuesPackageImpl::create()
{
	if (isInited)
	{
		return ValuesPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    ValuesPackageImpl * metaModelPackage = new ValuesPackageImpl();
    return metaModelPackage;
}

void ValuesPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}




