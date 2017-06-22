/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef FUMLPLUGIN_HPP_
#define FUMLPLUGIN_HPP_

#include "MDE4CPPPlugin.hpp"
#include "ActivityExecution.hpp"

class FUMLPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~FUMLPlugin(){}

		virtual std::shared_ptr<fUML::ActivityExecution> getMainActivityExecution() = 0;
};

#endif
