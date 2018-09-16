
#include "NewModelFactory.hpp"
#include "impl/NewModelFactoryImpl.hpp"

using namespace NewModel;

//static initialisation
NewModelFactory * NewModelFactory::instance = nullptr;

NewModelFactory * NewModelFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance = NewModelFactoryImpl::create();
		dynamic_cast<NewModelFactoryImpl * >(instance)->init();
	}	
	return instance;
}
