#include "TypesPackage.hpp"
#include "impl/TypesPackageImpl.hpp"

using namespace types;

//static initialisation
const std::string TypesPackage::eNAME ="types";
const std::string TypesPackage::eNS_URI ="http://www.eclipse.org/uml2/5.0.0/Types";
const std::string TypesPackage::eNS_PREFIX ="types";

//Singleton 
TypesPackage * TypesPackage::instance = nullptr;

TypesPackage * TypesPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Factoryimplementation
		instance = TypesPackageImpl::create();
		dynamic_cast<TypesPackageImpl * >(instance)->init();
	}	
	return instance;
}
