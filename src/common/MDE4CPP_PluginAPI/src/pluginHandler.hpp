#ifndef PLUGIN_HANDLER_HPP
#define PLUGIN_HANDLER_HPP

#include <map>
#include <vector>

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "pluginFramework/PluginFramework.hpp"

class pluginHandler{
    public:
        pluginHandler();

        /**
         * retrieves a pointer to a MDE4CPP-Plugin by its name 
         * @param name : name of the plugin
         * @return shared_ptr<MDE4CPPPlugin> : nullptr if plugin with name was not found 
        */
        std::shared_ptr<MDE4CPPPlugin> getPluginByName(std::string name);

        /**
         * returns a list of all plugins
         * @return vector of all pluginNames as strings
        */
        std::vector<std::string> getAllPluginNames();

        /**
         * rescans the current directory for Plugins and adds them to the m_plugins map
        */
        void refreshPlugins();

    private:
        /**
         * populates the m_plugins variable with pointers to all plugins found in the current directory 
        */
        void mapPlugins();

        std::shared_ptr<PluginFramework> m_pluginFramework; //instance of the pluginFramework

        std::map<std::string,std::shared_ptr<MDE4CPPPlugin>> m_plugins{}; //map of all plugins currently detected


};


#endif /*PLUGIN_HANDLER_HPP*/