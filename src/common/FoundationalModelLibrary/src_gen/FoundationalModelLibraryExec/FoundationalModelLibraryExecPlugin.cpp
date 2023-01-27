
#include "FoundationalModelLibraryExec/FoundationalModelLibraryExecPlugin.hpp"
#include "FoundationalModelLibraryExec/impl/FoundationalModelLibraryExecPluginImpl.hpp"

using namespace FoundationalModelLibrary;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> FoundationalModelLibraryExecPlugin::instance;

std::shared_ptr<MDE4CPPPlugin> FoundationalModelLibraryExecPlugin::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new FoundationalModelLibraryExecPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return FoundationalModelLibraryExecPlugin::eInstance();
}
