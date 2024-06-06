#include "PSSM/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "PSSM/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::MDE4CPP_Extensions;

//Singleton implementation 
std::shared_ptr<MDE4CPP_ExtensionsPackage> MDE4CPP_ExtensionsPackage::eInstance()
{
	static std::shared_ptr<MDE4CPP_ExtensionsPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(MDE4CPP_ExtensionsPackageImpl::create());
		std::dynamic_pointer_cast<MDE4CPP_ExtensionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string MDE4CPP_ExtensionsPackage::eNAME ="MDE4CPP_Extensions";
const std::string MDE4CPP_ExtensionsPackage::eNS_URI ="";
const std::string MDE4CPP_ExtensionsPackage::eNS_PREFIX ="PSSM_Semantics.Semantics.MDE4CPP_Extensions";

bool MDE4CPP_ExtensionsPackageImpl::isInited = false;

MDE4CPP_ExtensionsPackageImpl::MDE4CPP_ExtensionsPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( MDE4CPP_ExtensionsFactory::eInstance()));
}

MDE4CPP_ExtensionsPackageImpl::~MDE4CPP_ExtensionsPackageImpl()
{
}

MDE4CPP_ExtensionsPackage* MDE4CPP_ExtensionsPackageImpl::create()
{
	if (isInited)
	{
		return MDE4CPP_ExtensionsPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    MDE4CPP_ExtensionsPackageImpl * metaModelPackage = new MDE4CPP_ExtensionsPackageImpl();
    return metaModelPackage;
}

void MDE4CPP_ExtensionsPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class PSSM_Object
const std::shared_ptr<ecore::EClass>& PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSSM_Object_Class() const
{
	return m_pSSM_Object_Class;
}



const std::shared_ptr<ecore::EOperation>& PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSSM_Object_Operation_destroy() const
{
	return m_pSSM_Object_Operation_destroy;
}
const std::shared_ptr<ecore::EOperation>& PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSSM_Object_Operation_startBehavior_Class_ParameterValue() const
{
	return m_pSSM_Object_Operation_startBehavior_Class_ParameterValue;
}

// End Class PSSM_Object

