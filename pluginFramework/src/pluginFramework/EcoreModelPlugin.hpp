/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef PLUGINFRAMEWORK_ECOREMODELPLUGIN_HPP
#define PLUGINFRAMEWORK_ECOREMODELPLUGIN_HPP

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "ecore/EFactory.hpp"
#include "ecore/EPackage.hpp"

class EcoreModelPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~EcoreModelPlugin(){}

		virtual std::shared_ptr<ecore::EFactory> getFactory() = 0;
		virtual std::shared_ptr<ecore::EPackage> getPackage() = 0;
};

#endif
