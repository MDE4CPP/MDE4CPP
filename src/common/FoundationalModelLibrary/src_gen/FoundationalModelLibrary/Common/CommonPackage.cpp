#include "FoundationalModelLibrary/Common/CommonPackage.hpp"
#include "FoundationalModelLibrary/Common/impl/CommonPackageImpl.hpp"

using namespace FoundationalModelLibrary::Common;

//static initialisation
const std::string CommonPackage::eNAME ="Common";
const std::string CommonPackage::eNS_URI ="";
const std::string CommonPackage::eNS_PREFIX ="FoundationalModelLibrary";

//Singleton 
std::shared_ptr<CommonPackage> CommonPackage::instance;

std::shared_ptr<CommonPackage> CommonPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(CommonPackageImpl::create());
		std::dynamic_pointer_cast<CommonPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
