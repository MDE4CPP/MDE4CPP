#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"

//metamodel factory
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

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
const std::string StructuredClassifiersPackage::eNS_URI ="http:///fUML_Semantics/Semantics/StructuredClassifiers.ecore";
const std::string StructuredClassifiersPackage::eNS_PREFIX ="fUML_Semantics.Semantics.StructuredClassifiers";

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



// Begin Class DispatchStrategy
const std::shared_ptr<ecore::EClass>& fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getDispatchStrategy_Class() const
{
	return m_dispatchStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getDispatchStrategy_Operation_dispatch_Element_Operation() const
{
	return m_dispatchStrategy_Operation_dispatch_Element_Operation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getDispatchStrategy_Operation_getName() const
{
	return m_dispatchStrategy_Operation_getName;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getDispatchStrategy_Operation_retrieveMethod_Element_Operation() const
{
	return m_dispatchStrategy_Operation_retrieveMethod_Element_Operation;
}

// End Class DispatchStrategy

// Begin Class RedefinitionBasedDispatchStrategy
const std::shared_ptr<ecore::EClass>& fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getRedefinitionBasedDispatchStrategy_Class() const
{
	return m_redefinitionBasedDispatchStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getRedefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation() const
{
	return m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackageImpl::getRedefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation() const
{
	return m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation;
}

// End Class RedefinitionBasedDispatchStrategy

