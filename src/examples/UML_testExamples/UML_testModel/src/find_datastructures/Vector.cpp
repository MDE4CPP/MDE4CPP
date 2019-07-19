/*
 * Vector.cpp
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#include "Vector.hpp"

Vector::Vector( std::vector<std::shared_ptr<uml::Class>> _classes ) {

	classes = _classes;
}

Vector::~Vector() {

	classes.clear();
}

std::shared_ptr<uml::Class> Vector::at( int index ) {

	return classes[index];
}

int Vector::indexOf( std::shared_ptr<uml::Class> aClass ) {

	int length = classes.size();

	for( int i = 0; i < length; i++ ) {
		if( classes[i] == aClass ) {
			return i;
		}
	}
	/*auto end = classes.end();
	int index = 0;

	for( auto it = classes.begin(); it != end; it++, index++ ) {
		if( (*it) == aClass ) {
			return index;
		}
	}*/
	return -1;
}

