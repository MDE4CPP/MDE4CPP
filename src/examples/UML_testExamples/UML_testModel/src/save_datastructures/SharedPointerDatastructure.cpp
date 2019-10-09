/*
 * pointerdatastructure.cpp
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#include "SharedPointerDatastructure.hpp"

using namespace UML_testModel;

SharedPointerDatastructure::SharedPointerDatastructure() {

	char_array = nullptr;

}

SharedPointerDatastructure::~SharedPointerDatastructure() {

	char_array.reset();
}

void SharedPointerDatastructure::setCharArray( std::shared_ptr<char> charArray ) {

	char_array = charArray;
}

void SharedPointerDatastructure::setCharArraySave( std::shared_ptr<char> charArray ) {

	char_array.reset();
	char_array = charArray;
}

