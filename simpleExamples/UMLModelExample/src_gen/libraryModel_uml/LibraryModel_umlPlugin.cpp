
#include "LibraryModel_uml/LibraryModel_umlPlugin.hpp"
#include "LibraryModel_uml/impl/LibraryModel_umlPluginImpl.hpp"

using namespace LibraryModel_uml;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> LibraryModel_umlPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> LibraryModel_umlPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new LibraryModel_umlPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return LibraryModel_umlPlugin::eInstance();
}
