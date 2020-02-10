#include "StandardProfile/StandardProfilePackage.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"

using namespace StandardProfile;

//static initialisation
const std::string StandardProfilePackage::eNAME ="StandardProfile";
const std::string StandardProfilePackage::eNS_URI ="http://www.omg.org/spec/UML/20161101/StandardProfile";
const std::string StandardProfilePackage::eNS_PREFIX ="";

//Singleton 
std::shared_ptr<StandardProfilePackage> StandardProfilePackage::instance;

std::shared_ptr<StandardProfilePackage> StandardProfilePackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(StandardProfilePackageImpl::create());
		std::dynamic_pointer_cast<StandardProfilePackageImpl>(instance)->init(instance);
	}	
	return instance;
}
