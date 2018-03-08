/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef PLUGINFRAMEWORK_ECOREMODELPLUGIN_HPP
#define PLUGINFRAMEWORK_ECOREMODELPLUGIN_HPP

#include <memory>

#include "pluginFramework/MDE4CPPPlugin.hpp"

namespace ecore
{
	class EFactory;
	class EPackage;
}

class EcoreModelPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~EcoreModelPlugin(){}

		virtual std::shared_ptr<ecore::EFactory> getEFactory() = 0;
};

#endif
