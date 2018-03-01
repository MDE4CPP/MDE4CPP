#include "libraryModel_ecore/LibraryModel_ecoreFactory.hpp"
#include "libraryModel_ecore/impl/LibraryModel_ecoreFactoryImpl.hpp"

using namespace libraryModel_ecore;

//static initialisation
std::shared_ptr<LibraryModel_ecoreFactory> LibraryModel_ecoreFactory::instance;

std::shared_ptr<LibraryModel_ecoreFactory>LibraryModel_ecoreFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(LibraryModel_ecoreFactoryImpl::create());
		std::dynamic_pointer_cast<LibraryModel_ecoreFactoryImpl>(instance)->init();
	}	
	return instance;
}
