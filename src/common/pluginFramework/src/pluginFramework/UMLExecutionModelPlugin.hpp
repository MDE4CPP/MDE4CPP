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
	class Behavior;
	class Class;
	class Element;
	class Signal;
	class ValueSpecification;
	class StateMachine;
}

namespace fUML
{
	namespace Semantics
	{
		namespace CommonBehavior
		{
			class ParameterValue;
		}
	}

	namespace MDE4CPP_Extensions
	{
		class FUML_Object;
		class FUML_SignalInstance;
	}
}

class UMLExecutionModelPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~UMLExecutionModelPlugin(){}

		virtual std::shared_ptr<Any> executeActivity(std::shared_ptr<uml::Activity>, std::shared_ptr<Bag<Any>>, std::shared_ptr<uml::Element> element = nullptr) = 0;
		virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> executeBehavior(std::shared_ptr<uml::Behavior>, std::shared_ptr<uml::Element>, std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>) = 0;
		virtual std::shared_ptr<Any> executeStateMachine(std::shared_ptr<uml::StateMachine>, std::shared_ptr<Bag<Any>>, std::shared_ptr<uml::Element> element = nullptr) = 0;
		virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> instantiateClass(std::shared_ptr<uml::Class>) = 0;
		virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> instantiateSignal(std::shared_ptr<uml::Signal>) = 0;
		virtual std::shared_ptr<Any> evaluateSpecification(std::shared_ptr<uml::ValueSpecification>) = 0;
};

#endif
