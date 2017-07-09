/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef UMLMODELPLUGIN_HPP_
#define UMLMODELPLUGIN_HPP_

#include "MDE4CPPPlugin.hpp"
#include "Factory.hpp"
#include "Package.hpp"

class UMLModelPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~UMLModelPlugin(){}

		virtual std::shared_ptr<uml::Factory> getFactory() = 0;
		virtual std::shared_ptr<uml::Package> getPackage() = 0;
};

#endif
