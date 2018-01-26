/*
 * JSONSave.cpp
 *
 *  Created on: 30.05.2017
 *      Author: Alexander
 */

#include "JSONSave.hpp"

namespace persistence
{
namespace json
{
JSONSave::~JSONSave ()
{
	// TODO Auto-generated destructor stub
}

JSONSave::JSONSave ()
{
	// TODO Auto-generated constructor stub

}

bool JSONSave::write ( const std::string &filename )
{
	//boost::property_tree::write_json( filename, m_tree, std::locale(), true );

	return true;
}

} /* namespace json */
} /* namespace persistence */
