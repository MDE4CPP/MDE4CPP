#include "CalcModel/CalcModelPackage.hpp"
#include "CalcModel/impl/CalcModelPackageImpl.hpp"

using namespace CalcModel;

//static initialisation
const std::string CalcModelPackage::eNAME ="CalcModel";
const std::string CalcModelPackage::eNS_URI ="";
const std::string CalcModelPackage::eNS_PREFIX ="";

//Singleton 
std::shared_ptr<CalcModelPackage> CalcModelPackage::instance;

std::shared_ptr<CalcModelPackage> CalcModelPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(CalcModelPackageImpl::create());
		std::dynamic_pointer_cast<CalcModelPackageImpl>(instance)->init();
	}	
	return instance;
}
