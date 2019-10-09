/*
 * pointerdatastructure.h
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#ifndef SRC_SAVE_DATASTRUCTURES_POINTERDATASTRUCTURE_HPP_
#define SRC_SAVE_DATASTRUCTURES_POINTERDATASTRUCTURE_HPP_

#include <memory>

namespace UML_testModel
{
	class SharedPointerDatastructure {
		private:
			std::shared_ptr<char> char_array;
		public:
			SharedPointerDatastructure();
			virtual ~SharedPointerDatastructure();

			void setCharArray( std::shared_ptr<char> charArray );

			void setCharArraySave( std::shared_ptr<char> charArray );
	};
}

#endif /* SRC_SAVE_DATASTRUCTURES_POINTERDATASTRUCTURE_HPP_ */
