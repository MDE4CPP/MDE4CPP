/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef PLUGINFRAMEWORK_UMLEXECUTIONMODELPLUGIN_HPP
#define PLUGINFRAMEWORK_UMLEXECUTIONMODELPLUGIN_HPP

#include <memory>

#include "pluginFramework/MDE4CPPPlugin.hpp"

class Any;

template <class T>
class Bag;

namespace uml
{
	class Activity;
	class Element;
}

class UMLExecutionModelPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~UMLExecutionModelPlugin(){}

		virtual std::shared_ptr<Any> executeActivity(std::shared_ptr<uml::Activity> activity, std::shared_ptr<Bag<Any>> parameterList, std::shared_ptr<uml::Element> element = nullptr) = 0;
};

#endif
