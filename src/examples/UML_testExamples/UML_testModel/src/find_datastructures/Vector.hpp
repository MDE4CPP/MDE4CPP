/*
 * Vector.hpp
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#ifndef SRC_FIND_DATASTRUCTURES_VECTOR_HPP_
#define SRC_FIND_DATASTRUCTURES_VECTOR_HPP_

#include "uml/Class.hpp"
#include <vector>

class Vector {
private:
	std::vector<std::shared_ptr<uml::Class>> classes;
public:
	Vector( std::vector<std::shared_ptr<uml::Class>> _classes );
	virtual ~Vector();

	std::shared_ptr<uml::Class> at( int index );
	int indexOf( std::shared_ptr<uml::Class> aClass );
};

#endif /* SRC_FIND_DATASTRUCTURES_VECTOR_HPP_ */
