/*
 * Bimap.cpp
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#include "Bimap.hpp"

Bimap::Bimap( std::map<int, std::shared_ptr<uml::Class>> _classes_index, std::map<std::shared_ptr<uml::Class>, int> _classes_value ) {

	classes_index = _classes_index;
	classes_value = _classes_value;
}

Bimap::~Bimap() {

	classes_index.clear();
	classes_value.clear();
}

std::shared_ptr<uml::Class> Bimap::at( int index ) {

	return classes_index.at( index );
}

int Bimap::indexOf( std::shared_ptr<uml::Class> aClass ) {

	return classes_value.at( aClass );
}
