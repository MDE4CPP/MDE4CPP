/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef PLUGINFRAMEWORK_UMLEXECUTIONMODELPLUGIN_HPP
#define PLUGINFRAMEWORK_UMLEXECUTIONMODELPLUGIN_HPP

#include <memory>
#include <vector>

#include "boost/any.hpp"
#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "uml/Element.hpp"

class UMLExecutionModelPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~UMLExecutionModelPlugin(){}

		virtual boost::any executeActivity(std::string activityName, std::shared_ptr<std::vector<boost::any>> parameterList, std::shared_ptr<uml::Element> element = nullptr) = 0;
};

#endif
