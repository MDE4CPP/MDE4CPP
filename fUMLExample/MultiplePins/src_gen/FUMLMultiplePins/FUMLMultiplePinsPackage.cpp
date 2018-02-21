#include "fUMLMultiplePins/FUMLMultiplePinsPackage.hpp"
#include "fUMLMultiplePins/impl/FUMLMultiplePinsPackageImpl.hpp"

using namespace fUMLMultiplePins;

//static initialisation
const std::string FUMLMultiplePinsPackage::eNAME ="fUMLMultiplePins";
const std::string FUMLMultiplePinsPackage::eNS_URI ="";
const std::string FUMLMultiplePinsPackage::eNS_PREFIX ="";

//Singleton 
std::shared_ptr<FUMLMultiplePinsPackage> FUMLMultiplePinsPackage::instance;

std::shared_ptr<FUMLMultiplePinsPackage> FUMLMultiplePinsPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(FUMLMultiplePinsPackageImpl::create());
		std::dynamic_pointer_cast<FUMLMultiplePinsPackageImpl>(instance)->init();
	}	
	return instance;
}
