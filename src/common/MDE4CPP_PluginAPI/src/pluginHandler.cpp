#include "pluginHandler.hpp"
#include "abstractDataTypes/Bag.hpp"

//public functions
pluginHandler::pluginHandler()
{
    m_pluginFramework = PluginFramework::eInstance();
    mapPlugins(); //inital map of all plugins currently in the cwd
}

std::shared_ptr<MDE4CPPPlugin> pluginHandler::getPluginByName(std::string name){
	if(m_plugins.find(name) != m_plugins.end()){
		return m_plugins.find(name)->second; //plugin found
	}
	return nullptr; //plugin not found
}

std::vector<std::string> pluginHandler::getAllPluginNames(){
    std::vector<std::string> ret_vector;
    for(const std::pair<std::string,std::shared_ptr<MDE4CPPPlugin>> entry : m_plugins){
		   ret_vector.push_back(entry.first);
	}
    return ret_vector;
}

void pluginHandler::refreshPlugins(){
    mapPlugins();
}

//private functions

void pluginHandler::mapPlugins(){
	m_plugins.clear(); //clears map before inserting -> can be used for refreshing m_plugins without restarting application
    std::shared_ptr<Bag<MDE4CPPPlugin>> plugins = m_pluginFramework->getAllPlugins();
	for(std::shared_ptr<MDE4CPPPlugin>& plugin : *plugins){
		m_plugins.insert({plugin->eNAME(),plugin});
	}
}
