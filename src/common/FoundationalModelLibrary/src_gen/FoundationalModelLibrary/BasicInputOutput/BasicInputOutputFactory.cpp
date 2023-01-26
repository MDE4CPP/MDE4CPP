
#include "FoundationalModelLibrary/BasicInputOutput/BasicInputOutputFactory.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/BasicInputOutputFactoryImpl.hpp"

using namespace FoundationalModelLibrary::BasicInputOutput;

//static initialisation
std::shared_ptr<BasicInputOutputFactory> BasicInputOutputFactory::instance;

std::shared_ptr<BasicInputOutputFactory> BasicInputOutputFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(BasicInputOutputFactoryImpl::create());
	}	
	return instance;
}
