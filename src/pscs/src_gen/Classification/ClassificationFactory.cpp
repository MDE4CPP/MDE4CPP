#include "Classification/ClassificationFactory.hpp"
#include "Classification/impl/ClassificationFactoryImpl.hpp"

using namespace Classification;

//static initialisation
std::shared_ptr<ClassificationFactory> ClassificationFactory::instance;

std::shared_ptr<ClassificationFactory>ClassificationFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ClassificationFactoryImpl::create());
	}	
	return instance;
}
