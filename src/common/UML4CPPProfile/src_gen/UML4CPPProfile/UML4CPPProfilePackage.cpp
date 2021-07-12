#include "UML4CPPProfile/UML4CPPProfilePackage.hpp"
#include "UML4CPPProfile/impl/UML4CPPProfilePackageImpl.hpp"

using namespace UML4CPPProfile;

//static initialisation
const std::string UML4CPPProfilePackage::eNAME ="UML4CPPProfile";
const std::string UML4CPPProfilePackage::eNS_URI ="http://www.tu-ilmenau.de/sse/UML4CPPProfile";
const std::string UML4CPPProfilePackage::eNS_PREFIX ="";

//Singleton 
std::shared_ptr<UML4CPPProfilePackage> UML4CPPProfilePackage::instance;

std::shared_ptr<UML4CPPProfilePackage> UML4CPPProfilePackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(UML4CPPProfilePackageImpl::create());
		std::dynamic_pointer_cast<UML4CPPProfilePackageImpl>(instance)->init(instance);
	}	
	return instance;
}
