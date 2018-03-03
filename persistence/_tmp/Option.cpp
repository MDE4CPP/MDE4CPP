/*
 * Option.cpp
 *
 *  Created on: 30.05.2017
 *      Author: Alexander
 */

#include "Option.hpp"

namespace persistence
{
	namespace base
	{

		const std::string Option::OPTION_SAVE_JSON = "OPTION_SAVE_JSON";

		const std::string Option::OPTION_SAVE_XML = "OPTION_SAVE_XML";

		const std::string Option::OPTION_USE_ID__HASH = "OPTION_USE_ID__HASH";

		const std::string Option::OPTION_USE_ID__HASHTAG = "OPTION_USE_ID__HASHTAG";

		const std::string Option::OPTION_USE_ID__AT = "OPTION_USE_ID__AT";

		std::set<std::string> Option::get_DefaultOptions()
		{
			std::set<std::string> default_options;

			default_options.insert(Option::OPTION_SAVE_XML);
			//default_options.insert( Option::OPTION_SAVE_JSON );
			//default_options.insert( Option::OPTION_USE_ID__HASH );
			//default_options.insert( Option::OPTION_USE_ID__HASHTAG );

			return default_options;
		}

	}/* namespace base */
}/* namespace persistence */
