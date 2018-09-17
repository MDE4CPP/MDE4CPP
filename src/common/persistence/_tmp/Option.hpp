/*
 * Option.hpp
 *
 *  Created on: 30.05.2017
 *      Author: Alexander
 */

#ifndef OPTION_HPP_
#define OPTION_HPP_

#include <string>
#include <set>

namespace persistence
{
	namespace base
	{
		class Option
		{

			public:
				/**
				 *
				 */
				static const std::string OPTION_SAVE_JSON;
				/**
				 *
				 */
				static const std::string OPTION_SAVE_XML;
				/**
				 *
				 */
				static const std::string OPTION_USE_ID__HASH;
				/**
				 *
				 */
				static const std::string OPTION_USE_ID__HASHTAG;
				/**
				 *
				 */
				static const std::string OPTION_USE_ID__AT;

				static std::set<std::string> get_DefaultOptions();
		};

	} /* namespace base */
} /* namespace persistence */

#endif /* OPTION_HPP_ */
