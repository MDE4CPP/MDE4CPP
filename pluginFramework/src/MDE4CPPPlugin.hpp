/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef MDE4CPPPLUGIN_HPP_
#define MDE4CPPPLUGIN_HPP_

#include <string>

class MDE4CPPPlugin
{
	public:
		virtual ~MDE4CPPPlugin(){}

		virtual std::string eNAME() = 0;
		virtual std::string eNS_URI() = 0;
		virtual std::string eNS_PREFIX() = 0;
};

#endif
