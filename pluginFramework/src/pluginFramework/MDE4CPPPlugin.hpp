/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef PLUGINFRAMEWORK_MDE4CPPPLUGIN_HPP
#define PLUGINFRAMEWORK_MDE4CPPPLUGIN_HPP

#include <memory>
#include <string>

namespace ecore
{
	class EObject;
	class EPackage;
}

class MDE4CPPPlugin
{
	public:
		virtual ~MDE4CPPPlugin(){}

		virtual std::string eNAME() = 0;
		virtual std::string eNS_URI() = 0;
		virtual std::string eNS_PREFIX() = 0;

		virtual std::shared_ptr<ecore::EObject> create(const std::string& name) = 0;
		virtual std::shared_ptr<ecore::EPackage> getEPackage() = 0;
};

#endif
