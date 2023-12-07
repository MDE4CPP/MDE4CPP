#include "PSSM/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"

//metamodel factory
#include "PSSM/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::StructuredClassifiers;

//Singleton implementation 
std::shared_ptr<StructuredClassifiersPackage> StructuredClassifiersPackage::eInstance()
{
	static std::shared_ptr<StructuredClassifiersPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StructuredClassifiersPackageImpl::create());
		std::dynamic_pointer_cast<StructuredClassifiersPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string StructuredClassifiersPackage::eNAME ="StructuredClassifiers";
const std::string StructuredClassifiersPackage::eNS_URI ="http:///PSSM/Semantics/StructuredClassifiers.ecore";
const std::string StructuredClassifiersPackage::eNS_PREFIX ="PSSM.Semantics.StructuredClassifiers";

bool StructuredClassifiersPackageImpl::isInited = false;

StructuredClassifiersPackageImpl::StructuredClassifiersPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( StructuredClassifiersFactory::eInstance()));
}

StructuredClassifiersPackageImpl::~StructuredClassifiersPackageImpl()
{
}

StructuredClassifiersPackage* StructuredClassifiersPackageImpl::create()
{
	if (isInited)
	{
		return StructuredClassifiersPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    StructuredClassifiersPackageImpl * metaModelPackage = new StructuredClassifiersPackageImpl();
    return metaModelPackage;
}

void StructuredClassifiersPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class SM_RedefinitionBasedDispatchStrategy
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getSM_RedefinitionBasedDispatchStrategy_Class() const
{
	return m_sM_RedefinitionBasedDispatchStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getSM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation() const
{
	return m_sM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getSM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation() const
{
	return m_sM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation;
}

// End Class SM_RedefinitionBasedDispatchStrategy

