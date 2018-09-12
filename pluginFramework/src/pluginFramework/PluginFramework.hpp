/*
 * PluginFramework.hpp
 *
 *  Created on: 21.06.2017
 *      Author: alwi0251
 */

#ifndef PLUGINFRAMEWORK_PLUGINFRAMEWORK_HPP
#define PLUGINFRAMEWORK_PLUGINFRAMEWORK_HPP

#include <memory>

template<class T> class Bag;
class MDE4CPPPlugin;

class PluginFramework
{
	private:
		PluginFramework(PluginFramework const&) = delete;
		PluginFramework& operator=(PluginFramework const&) = delete;

	protected:
		PluginFramework(){};

	public:
		static std::shared_ptr<PluginFramework> eInstance();

		virtual ~PluginFramework(){};
		virtual void clear() = 0;
		virtual std::shared_ptr<MDE4CPPPlugin> findPluginByName(const std::string name) const = 0;
		virtual std::shared_ptr<MDE4CPPPlugin> findPluginByUri(const std::string uri) const = 0;
		virtual std::shared_ptr<Bag<MDE4CPPPlugin>> getAllPlugins() const = 0;

	private:
		static std::shared_ptr<PluginFramework> instance;
};

#endif
