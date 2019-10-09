/*
 * Map.hpp
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#ifndef SRC_FIND_DATASTRUCTURES_MAP_HPP_
#define SRC_FIND_DATASTRUCTURES_MAP_HPP_

#include <map>
#include "uml/Class.hpp"

class Map {
private:
	std::map<int, std::shared_ptr<uml::Class>> classes;
public:
	Map( std::map<int, std::shared_ptr<uml::Class>> _classes );
	virtual ~Map();

	std::shared_ptr<uml::Class> at( int index );
	int indexOf( std::shared_ptr<uml::Class> aClass );
};

#endif /* SRC_FIND_DATASTRUCTURES_MAP_HPP_ */
