/*
 * Persistence.cpp
 *
 *  Created on: 16.05.2017
 *      Author: Alexander
 */

#include "persistence/base/Persistence.hpp"
#include "persistence/base/Load.hpp"
#include "persistence/base/Save.hpp"

using namespace std;

namespace persistence
{
namespace base
{

Persistence::Persistence ()
{
}

Persistence::~Persistence ()
{
}

bool Persistence::isValidFile ( const std::string& filename )
{
	//boost::filesystem::path file( filename );
	// TODO needs implementation
	MSG_WARNING(MSG_FLF << " is not implemented!");

	return true;
}

} /* namespace base */
} /* namespace persistence */
