/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef UMLPLUGIN_HPP_
#define UMLPLUGIN_HPP_

#include "MDE4CPPPlugin.hpp"
#include "Factory.hpp"
#include "Package.hpp"

class UMLPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~UMLPlugin(){}

		virtual std::shared_ptr<uml::Factory> getFactory() = 0;
		virtual std::shared_ptr<uml::Package> getPackage() = 0;
};

#endif
