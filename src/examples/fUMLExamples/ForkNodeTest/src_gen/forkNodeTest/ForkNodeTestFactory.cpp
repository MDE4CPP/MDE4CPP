
#include "forkNodeTest/ForkNodeTestFactory.hpp"
#include "forkNodeTest/impl/ForkNodeTestFactoryImpl.hpp"

using namespace forkNodeTest;

//static initialisation
std::shared_ptr<ForkNodeTestFactory> ForkNodeTestFactory::instance;

std::shared_ptr<ForkNodeTestFactory> ForkNodeTestFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(ForkNodeTestFactoryImpl::create());
	}	
	return instance;
}
