#include "PSSM/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "PSSM/Semantics/Actions/ActionsFactory.hpp"

//depending model packages

using namespace PSSM::Semantics::Actions;

//Singleton implementation 
std::shared_ptr<ActionsPackage> ActionsPackage::eInstance()
{
	static std::shared_ptr<ActionsPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActionsPackageImpl::create());
		std::dynamic_pointer_cast<ActionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string ActionsPackage::eNAME ="Actions";
const std::string ActionsPackage::eNS_URI ="http:///PSSM/Semantics/Actions.ecore";
const std::string ActionsPackage::eNS_PREFIX ="PSSM.Semantics.Actions";

bool ActionsPackageImpl::isInited = false;

ActionsPackageImpl::ActionsPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( ActionsFactory::eInstance()));
}

ActionsPackageImpl::~ActionsPackageImpl()
{
}

ActionsPackage* ActionsPackageImpl::create()
{
	if (isInited)
	{
		return ActionsPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    ActionsPackageImpl * metaModelPackage = new ActionsPackageImpl();
    return metaModelPackage;
}

void ActionsPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class SM_ReadSelfActionActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::Actions::ActionsPackageImpl::getSM_ReadSelfActionActivation_Class() const
{
	return m_sM_ReadSelfActionActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::Actions::ActionsPackageImpl::getSM_ReadSelfActionActivation_Operation_getExecutionContext() const
{
	return m_sM_ReadSelfActionActivation_Operation_getExecutionContext;
}

// End Class SM_ReadSelfActionActivation

