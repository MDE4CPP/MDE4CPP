/*
 * pointerdatastructure.h
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#ifndef SRC_SAVE_DATASTRUCTURES_POINTERDATASTRUCTURE_HPP_
#define SRC_SAVE_DATASTRUCTURES_POINTERDATASTRUCTURE_HPP_

namespace UML_testModel
{
	class PointerDatastructure {
		private:
			char* char_array;
		public:
			PointerDatastructure();
			virtual ~PointerDatastructure();

			void setCharArray( char* charArray );

			void setCharArraySave( char* charArray );
	};
}

#endif /* SRC_SAVE_DATASTRUCTURES_POINTERDATASTRUCTURE_HPP_ */
