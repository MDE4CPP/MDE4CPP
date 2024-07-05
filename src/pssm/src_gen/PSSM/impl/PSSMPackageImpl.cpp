#include "PSSM/impl/PSSMPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EGenericType.hpp"

//metamodel factory
#include "PSSM/PSSMFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "PSSM/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include "PSSM/Semantics/impl/SemanticsPackageImpl.hpp"

using namespace PSSM;

//Singleton implementation 
std::shared_ptr<PSSMPackage> PSSMPackage::eInstance()
{
	static std::shared_ptr<PSSMPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(PSSMPackageImpl::create());
		std::dynamic_pointer_cast<PSSMPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string PSSMPackage::eNAME ="PSSM";
const std::string PSSMPackage::eNS_URI ="http://www.omg.org/spec/PSSM/20161101";
const std::string PSSMPackage::eNS_PREFIX ="PSSM";

bool PSSMPackageImpl::isInited = false;

PSSMPackageImpl::PSSMPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( PSSMFactory::eInstance()));
}

PSSMPackageImpl::~PSSMPackageImpl()
{
}

PSSMPackage* PSSMPackageImpl::create()
{
	if (isInited)
	{
		return PSSMPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    PSSMPackageImpl * metaModelPackage = new PSSMPackageImpl();
    return metaModelPackage;
}

void PSSMPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

std::shared_ptr<PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage> PSSM::PSSMPackageImpl::getMDE4CPP_Extensions_Package() const
{
	return PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance();
} 
std::shared_ptr<PSSM::Semantics::SemanticsPackage> PSSM::PSSMPackageImpl::getSemantics_Package() const
{
	return PSSM::Semantics::SemanticsPackage::eInstance();
} 



