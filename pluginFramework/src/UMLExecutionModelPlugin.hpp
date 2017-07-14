/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef UMLEXECUTIONMODELPLUGIN_HPP_
#define UMLEXECUTIONMODELPLUGIN_HPP_

#include "MDE4CPPPlugin.hpp"
#include <memory>
#include <boost/any.hpp>
#include "Bag.hpp"

class UMLExecutionModelPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~UMLExecutionModelPlugin(){}

		virtual boost::any executeActivity(std::string activityName, std::shared_ptr<std::vector<boost::any>> parameterList) = 0;
		virtual boost::any getBehaviorExecutions() = 0;
};

#endif
