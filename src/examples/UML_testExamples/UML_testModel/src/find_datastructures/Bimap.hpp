/*
 * Bimap.hpp
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#ifndef SRC_FIND_DATASTRUCTURES_BIMAP_HPP_
#define SRC_FIND_DATASTRUCTURES_BIMAP_HPP_

#include <map>
#include "uml/Class.hpp"

class Bimap {
private:
	std::map<int, std::shared_ptr<uml::Class>> classes_index;
	std::map<std::shared_ptr<uml::Class>, int> classes_value;
public:
	Bimap( std::map<int, std::shared_ptr<uml::Class>> _classes_index, std::map<std::shared_ptr<uml::Class>, int> _classes_value );
	virtual ~Bimap();

	std::shared_ptr<uml::Class> at( int index );
	int indexOf( std::shared_ptr<uml::Class> aClass );
};

#endif /* SRC_FIND_DATASTRUCTURES_BIMAP_HPP_ */
