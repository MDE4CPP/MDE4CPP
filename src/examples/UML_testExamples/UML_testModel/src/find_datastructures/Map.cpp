/*
 * Map.cpp
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#include "Map.hpp"

Map::Map( std::map<int, std::shared_ptr<uml::Class>> _classes ) {

	classes = _classes;
}

Map::~Map() {

	classes.clear();
}

std::shared_ptr<uml::Class> Map::at( int index ) {

	return classes.at( index );
}

int Map::indexOf( std::shared_ptr<uml::Class> aClass ) {

	int index = 0;

	for( auto it = classes.begin(); it != classes.end(); it++, index++ ) {
		if( it->second == aClass ) {
			return index;
		}
	}
	return -1;
}

