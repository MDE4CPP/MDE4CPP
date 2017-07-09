/*
 * MDE4CPPPlugin.hpp
 *
 *  Created on: 21.06.2017
 *      Author: Alexander Wichmann
 */

#ifndef ECOREMODELPLUGIN_HPP_
#define ECOREMODELPLUGIN_HPP_

#include "MDE4CPPPlugin.hpp"
#include "EFactory.hpp"
#include "EPackage.hpp"

class EcoreModelPlugin: public MDE4CPPPlugin
{
	public:
		virtual ~EcoreModelPlugin(){}

		virtual std::shared_ptr<ecore::EFactory> getFactory() = 0;
		virtual std::shared_ptr<ecore::EPackage> getPackage() = 0;
};

#endif
