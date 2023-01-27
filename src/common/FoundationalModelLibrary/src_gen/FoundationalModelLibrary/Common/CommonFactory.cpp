
#include "FoundationalModelLibrary/Common/CommonFactory.hpp"
#include "FoundationalModelLibrary/Common/impl/CommonFactoryImpl.hpp"

using namespace FoundationalModelLibrary::Common;

//static initialisation
std::shared_ptr<CommonFactory> CommonFactory::instance;

std::shared_ptr<CommonFactory> CommonFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(CommonFactoryImpl::create());
	}	
	return instance;
}
