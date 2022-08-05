#include "types/impl/typesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "types/typesFactory.hpp"
#include "types/typesPlugin.hpp"

//depending model packages

using namespace types;


std::shared_ptr<typesPackage> typesPackage::eInstance()
{
	std::shared_ptr<typesPlugin> plugin=typesPlugin::eInstance();
	return plugin->gettypesPackage();
}

//static initialisation
const std::string typesPackage::eNAME ="types";
const std::string typesPackage::eNS_URI ="http://www.eclipse.org/uml2/5.0.0/Types";
const std::string typesPackage::eNS_PREFIX ="types";

bool typesPackageImpl::isInited = false;

typesPackageImpl::typesPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( typesFactory::eInstance()));
}

typesPackageImpl::~typesPackageImpl()
{
}

typesPackage* typesPackageImpl::create()
{
	if (isInited)
	{
		return typesPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    typesPackageImpl * metaModelPackage = new typesPackageImpl();
    return metaModelPackage;
}

void typesPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



std::shared_ptr<ecore::EDataType> types::typesPackageImpl::getAny_Class() const
{
	return m_any_Class;
}
std::shared_ptr<ecore::EDataType> types::typesPackageImpl::getBoolean_Class() const
{
	return m_boolean_Class;
}
std::shared_ptr<ecore::EDataType> types::typesPackageImpl::getInteger_Class() const
{
	return m_integer_Class;
}
std::shared_ptr<ecore::EDataType> types::typesPackageImpl::getReal_Class() const
{
	return m_real_Class;
}
std::shared_ptr<ecore::EDataType> types::typesPackageImpl::getString_Class() const
{
	return m_string_Class;
}
std::shared_ptr<ecore::EDataType> types::typesPackageImpl::getUnlimitedNatural_Class() const
{
	return m_unlimitedNatural_Class;
}

