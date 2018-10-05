/*
 * Save.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/base/Save.hpp"

#ifdef NDEBUG
#define MSG_DEBUG(a) /**/
#else
#define MSG_DEBUG(a) std::cout << "| DEBUG    | " << a << std::endl
#endif
#define MSG_WARNING(a) std::cout << "| WARNING  | "<< a << std::endl
#define MSG_ERROR(a) std::cout << "| ERROR    | " << a << std::endl
#define MSG_FLF __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << "() "

#include <iostream>

#include "ecore/EClass.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
#include "persistence/base/SaveHandler.hpp"

using namespace persistence::base;

Save::Save ()
{
}

Save::~Save ()
{
}

bool Save::save ( const std::string &filename, std::shared_ptr<ecore::EObject> model, std::shared_ptr<ecore::EPackage> metaMetaPackage, bool xsiMode)
{
	std::shared_ptr<ecore::EClass> metaClass = model->eClass();

	MSG_DEBUG( "metaClass: " << metaClass->getName() );
	MSG_DEBUG( "metaMetaPck-NS: " << metaMetaPackage->getNsPrefix() );
	MSG_DEBUG( "metaMetaPck-Uri: " << metaMetaPackage->getNsURI() );

	m_handler->setIsXSIMode(xsiMode);
	m_handler->setRootObject( model );
	m_handler->createRootNode( metaMetaPackage->getNsPrefix(), metaClass->getName(), metaMetaPackage->getNsURI() );

	MSG_DEBUG( m_handler->extractType( model ) );

	model->save( m_handler );
	m_handler->finalize();

	// Call write() method in corresponding derived class
	return write( filename );
}

void Save::setTypesMap(std::map<std::string, std::shared_ptr<ecore::EObject>> typesMap)
{
	m_handler->setTypesMap(typesMap);
}
