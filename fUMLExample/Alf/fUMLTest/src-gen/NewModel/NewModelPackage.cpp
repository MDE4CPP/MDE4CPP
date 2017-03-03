

#include "NewModelPackage.hpp"
#include "impl/NewModelPackageImpl.hpp"


namespace NewModel
{



//static initialisation

const QString NewModelPackage::eNAME ="NewModel";
const QString NewModelPackage::eNS_URI ="";
const QString NewModelPackage::eNS_PREFIX ="invalid";

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


}

