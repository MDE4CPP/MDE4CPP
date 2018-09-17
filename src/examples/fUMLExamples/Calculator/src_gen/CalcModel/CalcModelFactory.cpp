
#include "CalcModel/CalcModelFactory.hpp"
#include "CalcModel/impl/CalcModelFactoryImpl.hpp"

using namespace CalcModel;

//static initialisation
std::shared_ptr<CalcModelFactory> CalcModelFactory::instance;

std::shared_ptr<CalcModelFactory> CalcModelFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(CalcModelFactoryImpl::create());
	}	
	return instance;
}
