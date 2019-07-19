/*
 * Array.cpp
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#include "Array.hpp"

Array::Array( std::shared_ptr<uml::Class>* _classes ) {

	classes = _classes;
}

Array::~Array() {

	classes->reset();
}

std::shared_ptr<uml::Class> Array::at( int index ) {

	return classes[index];
}

int Array::indexOf( std::shared_ptr<uml::Class> aClass ) {

	int length = sizeof(classes) / sizeof(*classes);

	for( int i = 0; i < length; i++ ) {
		if( classes[i] == aClass ) {
			return i;
		}
	}
	return -1;
}
