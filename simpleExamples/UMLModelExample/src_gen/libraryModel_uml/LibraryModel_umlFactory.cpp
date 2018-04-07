
#include "LibraryModel_uml/LibraryModel_umlFactory.hpp"
#include "LibraryModel_uml/impl/LibraryModel_umlFactoryImpl.hpp"

using namespace LibraryModel_uml;

//static initialisation
std::shared_ptr<LibraryModel_umlFactory> LibraryModel_umlFactory::instance;

std::shared_ptr<LibraryModel_umlFactory> LibraryModel_umlFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(LibraryModel_umlFactoryImpl::create());
		std::dynamic_pointer_cast<LibraryModel_umlFactoryImpl>(instance)->init();
	}	
	return instance;
}
