#include "fUML/impl/fUMLPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"

//metamodel factory
#include "fUML/fUMLFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"

using namespace fUML;

//Singleton implementation 
std::shared_ptr<fUMLPackage> fUMLPackage::eInstance()
{
	static std::shared_ptr<fUMLPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(fUMLPackageImpl::create());
		std::dynamic_pointer_cast<fUMLPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string fUMLPackage::eNAME ="fUML";
const std::string fUMLPackage::eNS_URI ="http://www.omg.org/spec/FUML/20180501";
const std::string fUMLPackage::eNS_PREFIX ="fUML_Semantics";

bool fUMLPackageImpl::isInited = false;

fUMLPackageImpl::fUMLPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( fUMLFactory::eInstance()));
}

fUMLPackageImpl::~fUMLPackageImpl()
{
}

fUMLPackage* fUMLPackageImpl::create()
{
	if (isInited)
	{
		return fUMLPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    fUMLPackageImpl * metaModelPackage = new fUMLPackageImpl();
    return metaModelPackage;
}

void fUMLPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

std::shared_ptr<fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage> fUML::fUMLPackageImpl::getMDE4CPP_Extensions_Package() const
{
	return fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance();
} 
std::shared_ptr<fUML::Semantics::SemanticsPackage> fUML::fUMLPackageImpl::getSemantics_Package() const
{
	return fUML::Semantics::SemanticsPackage::eInstance();
} 



