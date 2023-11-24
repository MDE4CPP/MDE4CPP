#include "PSSM/Semantics/Loci/impl/LociPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "PSSM/Semantics/Loci/LociFactory.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::Loci;

//Singleton implementation 
std::shared_ptr<LociPackage> LociPackage::eInstance()
{
	static std::shared_ptr<LociPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(LociPackageImpl::create());
		std::dynamic_pointer_cast<LociPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string LociPackage::eNAME ="Loci";
const std::string LociPackage::eNS_URI ="http:///PSSM/Semantics/Loci.ecore";
const std::string LociPackage::eNS_PREFIX ="PSSM.Semantics.Loci";

bool LociPackageImpl::isInited = false;

LociPackageImpl::LociPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( LociFactory::eInstance()));
}

LociPackageImpl::~LociPackageImpl()
{
}

LociPackage* LociPackageImpl::create()
{
	if (isInited)
	{
		return LociPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    LociPackageImpl * metaModelPackage = new LociPackageImpl();
    return metaModelPackage;
}

void LociPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class SM_ExecutionFactory
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::Loci::LociPackageImpl::getSM_ExecutionFactory_Class() const
{
	return m_sM_ExecutionFactory_Class;
}



const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::Loci::LociPackageImpl::getSM_ExecutionFactory_Operation_instantiateVisitor_Element() const
{
	return m_sM_ExecutionFactory_Operation_instantiateVisitor_Element;
}

// End Class SM_ExecutionFactory

// Begin Class SM_Locus
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::Loci::LociPackageImpl::getSM_Locus_Class() const
{
	return m_sM_Locus_Class;
}



const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::Loci::LociPackageImpl::getSM_Locus_Operation_instantiate_Class() const
{
	return m_sM_Locus_Operation_instantiate_Class;
}

// End Class SM_Locus

