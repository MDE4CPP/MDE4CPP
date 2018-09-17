/*
 * JSONSave.hpp
 *
 *  Created on: 30.05.2017
 *      Author: Alexander
 */

#ifndef JSONSAVE_HPP_
#define JSONSAVE_HPP_

#include "Save.hpp"

namespace persistence
{
	namespace json
	{
		class JSONSave: public persistence::base::Save
		{
			public:
				virtual ~JSONSave();
				JSONSave();

			private:
				bool write(const std::string &filename);
		};
	} /* base */
} /* namespace persistence */

#endif /* JSONSAVE_HPP_ */
