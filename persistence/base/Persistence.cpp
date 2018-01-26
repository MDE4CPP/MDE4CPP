/*
 * Persistence.cpp
 *
 *  Created on: 16.05.2017
 *      Author: Alexander
 */

#include "Persistence.hpp"
#include "Load.hpp"
#include "Save.hpp"

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
	// TODO Auto-generated destructor stub
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
