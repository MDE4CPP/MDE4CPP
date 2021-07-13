
#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"
#include "UML4CPPProfile/impl/UML4CPPProfileFactoryImpl.hpp"

using namespace UML4CPPProfile;

//static initialisation
std::shared_ptr<UML4CPPProfileFactory> UML4CPPProfileFactory::instance;

std::shared_ptr<UML4CPPProfileFactory> UML4CPPProfileFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(UML4CPPProfileFactoryImpl::create());
	}	
	return instance;
}
