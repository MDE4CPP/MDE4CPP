/*
 * pointerdatastructure.cpp
 *
 *  Created on: 15.07.2019
 *      Author: mbranz
 */

#include "PointerDatastructure.hpp"

using namespace UML_testModel;

PointerDatastructure::PointerDatastructure() {

	char_array = nullptr;

}

PointerDatastructure::~PointerDatastructure() {

	delete char_array;
}

void PointerDatastructure::setCharArray( char* charArray ) {

	char_array = charArray;
}

void PointerDatastructure::setCharArraySave( char* charArray ) {

	delete char_array;
	char_array = charArray;
}

