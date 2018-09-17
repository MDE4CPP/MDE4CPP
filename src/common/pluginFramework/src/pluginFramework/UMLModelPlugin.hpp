/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef PLUGINFRAMEWORK_UMLMODELPLUGIN_HPP
#define PLUGINFRAMEWORK_UMLMODELPLUGIN_HPP

#include <memory>

#include "pluginFramework/MDE4CPPPlugin.hpp"

namespace uml
{
	class Factory;
	class Package;
}

class UMLModelPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~UMLModelPlugin(){}

		virtual std::shared_ptr<uml::Factory> getFactory() = 0;
		virtual std::shared_ptr<uml::Package> getPackage() = 0;
};

#endif
