
#include "FoundationalModelLibrary/FoundationalModelLibraryPlugin.hpp"
#include "FoundationalModelLibrary/impl/FoundationalModelLibraryPluginImpl.hpp"

using namespace FoundationalModelLibrary;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> FoundationalModelLibraryPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> FoundationalModelLibraryPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new FoundationalModelLibraryPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return FoundationalModelLibraryPlugin::eInstance();
}
