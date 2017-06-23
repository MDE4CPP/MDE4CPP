/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef FUMLPLUGIN_HPP_
#define FUMLPLUGIN_HPP_

#include "MDE4CPPPlugin.hpp"
#include <memory>
#include <boost/any.hpp>

class FUMLPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~FUMLPlugin(){}

		virtual boost::any executeActivity(std::string activityName, std::shared_ptr<std::vector<boost::any>> parameterList) = 0;
};

#endif
