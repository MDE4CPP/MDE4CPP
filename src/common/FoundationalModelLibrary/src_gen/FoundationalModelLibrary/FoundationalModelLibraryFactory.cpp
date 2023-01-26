
#include "FoundationalModelLibrary/FoundationalModelLibraryFactory.hpp"
#include "FoundationalModelLibrary/impl/FoundationalModelLibraryFactoryImpl.hpp"

using namespace FoundationalModelLibrary;

//static initialisation
std::shared_ptr<FoundationalModelLibraryFactory> FoundationalModelLibraryFactory::instance;

std::shared_ptr<FoundationalModelLibraryFactory> FoundationalModelLibraryFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(FoundationalModelLibraryFactoryImpl::create());
	}	
	return instance;
}
