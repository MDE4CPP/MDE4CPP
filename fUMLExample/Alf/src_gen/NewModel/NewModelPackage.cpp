#include "NewModelPackage.hpp"
#include "impl/NewModelPackageImpl.hpp"

using namespace NewModel;

//static initialisation
const std::string NewModelPackage::eNAME ="NewModel";
const std::string NewModelPackage::eNS_URI ="";
const std::string NewModelPackage::eNS_PREFIX ="invalid";

//Singleton 
NewModelPackage * NewModelPackage::instance = nullptr;

NewModelPackage * NewModelPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance = NewModelPackageImpl::create();
		dynamic_cast<NewModelPackageImpl * >(instance)->init();
	}	
	return instance;
}
