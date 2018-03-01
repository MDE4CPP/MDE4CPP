/*
 * persistence::xml.hpp
 *
 *  Created on: 25.01.2018
 *      Author: Alexander
 */

#ifndef XMLPersistence_HPP_
#define XMLPersistence_HPP_

#include "persistence/base/Persistence.hpp"

#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"

//#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations
#include <string>
#include <iostream>

namespace persistence
{
namespace xml
{

class XMLPersistence : persistence::base::Persistence
{
public:
	XMLPersistence ();
	virtual ~XMLPersistence ();

	std::shared_ptr<ecore::EObject> load ( const std::string &filename );
	bool save ( const std::string &filename, std::shared_ptr<ecore::EObject> model, std::shared_ptr<ecore::EPackage> metaMetaPackage );

private:

};
} /* namespace xml */
} /* namespace persistence */

#endif /* XMLPersistence_HPP_ */
