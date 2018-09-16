
#include "libraryModel_ecore/LibraryModel_ecorePlugin.hpp"
#include "libraryModel_ecore/impl/LibraryModel_ecorePluginImpl.hpp"

using namespace libraryModel_ecore;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> LibraryModel_ecorePlugin::instance;

std::shared_ptr<MDE4CPPPlugin> LibraryModel_ecorePlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new LibraryModel_ecorePluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return LibraryModel_ecorePlugin::eInstance();
}
