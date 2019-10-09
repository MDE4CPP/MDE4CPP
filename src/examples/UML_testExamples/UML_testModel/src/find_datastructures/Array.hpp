/*
 * Array.h
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#ifndef SRC_FIND_DATASTRUCTURES_ARRAY_HPP_
#define SRC_FIND_DATASTRUCTURES_ARRAY_HPP_

#include "uml/Class.hpp"

class Array {
private:
	std::shared_ptr<uml::Class>* classes;
public:
	Array( std::shared_ptr<uml::Class>* _classes );
	virtual ~Array();

	std::shared_ptr<uml::Class> at( int index );
	int indexOf( std::shared_ptr<uml::Class> aClass );
};

#endif /* SRC_FIND_DATASTRUCTURES_ARRAY_HPP_ */
