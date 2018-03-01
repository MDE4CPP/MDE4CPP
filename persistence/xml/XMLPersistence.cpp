/*
 * XMLPersistence.cpp
 *
 *  Created on: 25.01.2018
 *      Author: Alexander
 */

#include "XMLPersistence.hpp"
#include "Load.hpp"
#include "Save.hpp"
//#include "JSONSave.hpp"
#include "XMLSave.hpp"
#include "XMLLoad.hpp"

namespace persistence
{
namespace xml
{
XMLPersistence::XMLPersistence ()
{
}

XMLPersistence::~XMLPersistence ()
{
}

std::shared_ptr<ecore::EObject> XMLPersistence::load ( const std::string& filename )
{
	if ( isValidFile( filename ) == false )
	{
		MSG_ERROR( MSG_FLF << "Given filename: '" << filename << "' is not valid!" );
		return nullptr;
	}

	MSG_DEBUG( "Load from XML-File" );

	std::shared_ptr<persistence::xml::XMLLoad> xmlLoad( new persistence::xml::XMLLoad() );

	return xmlLoad->load( filename );
}

bool XMLPersistence::save ( const std::string& filename, std::shared_ptr<ecore::EObject> model, std::shared_ptr<ecore::EPackage> metaMetaPackage )
{
	if ( isValidFile( filename ) == false )
	{
		MSG_ERROR( MSG_FLF << "Given filename: '" << filename << "' is not valid!" );
		return false;
	}

	MSG_DEBUG( "Save as XML-File" );

	std::shared_ptr<persistence::xml::XMLSave> xmlSave( new persistence::xml::XMLSave() );

	return xmlSave->save( filename, model, metaMetaPackage );
}

} /* namespace xml */
} /* namespace persistence */
