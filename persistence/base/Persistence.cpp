/*
 * Persistence.cpp
 *
 *  Created on: 16.05.2017
 *      Author: Alexander
 */

#include "persistence/base/Persistence.hpp"

#define MSG_WARNING(a) std::cout << "| WARNING  | "<< a << std::endl
#define MSG_FLF __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << "() "

#include <iostream>

using namespace persistence::base;

Persistence::Persistence()
{
}

Persistence::~Persistence()
{
}

bool Persistence::isValidFile(const std::string& filename)
{
	//boost::filesystem::path file( filename );
	// TODO needs implementation
	MSG_WARNING(MSG_FLF << " is not implemented!");

	return true;
}

