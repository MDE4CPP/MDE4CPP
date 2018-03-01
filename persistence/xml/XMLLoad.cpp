/*
 * XMLLoad.cpp
 *
 *  Created on: 16.05.2017
 *      Author: Alexander
 */

#include "persistence/xml/XMLLoad.hpp"

namespace persistence
{
namespace xml
{

XMLLoad::XMLLoad ()
{
	m_handler.reset( new persistence::xml::XMLLoadHandler() );

	m_DoNamespaces = false;
	m_DoSchema = false;
	m_SchemaFullChecking = false;
	m_DoCreate = false;

	m_ValScheme = XercesDOMParser::Val_Auto;

	// Initialize the XML4C2 system
	try
	{
		XMLPlatformUtils::Initialize();
	}

	catch ( const XMLException &toCatch )
	{
		MSG_ERROR( MSG_FLF << "Error during Xerces-c Initialization.\n" << "  Exception message:" << W( toCatch.getMessage() ) );
		return;
	}

	//
	//  Create our parser, then attach an error handler to the parser.
	//  The parser will call back to methods of the ErrorHandler if it
	//  discovers errors during the course of parsing the XML document.
	//

	m_parser = new XercesDOMParser;
	m_parser->setValidationScheme( m_ValScheme );
	m_parser->setDoNamespaces( m_DoNamespaces );
	m_parser->setDoSchema( m_DoSchema );
	m_parser->setHandleMultipleImports( true );
	m_parser->setValidationSchemaFullChecking( m_SchemaFullChecking );
	m_parser->setCreateEntityReferenceNodes( m_DoCreate );

	m_errReporter = new DOMTreeErrorReporter();
	m_parser->setErrorHandler( m_errReporter );

}

XMLLoad::~XMLLoad ()
{
	if ( m_handler )
	{
		m_handler.reset();
	}
	XMLPlatformUtils::Terminate();
}

bool XMLLoad::read ( const std::string &filename )
{
	XERCES_CPP_NAMESPACE_USE

	//
	//  Parse the XML file, catching any XML exceptions that might propogate
	//  out of it.
	//
	std	::string _filename = filename;// TODO check if _filename is necessary, because of Error-Message "Multiple errors.." in var filename

	bool errorsOccured = false;

	try
	{
		m_parser->parse( _filename.c_str() );
	}
	catch ( const OutOfMemoryException& )
	{
		MSG_ERROR(MSG_FLF << "OutOfMemoryException");
		errorsOccured = true;
	}
	catch ( const XMLException& e )
	{
		MSG_ERROR(MSG_FLF << "An error occurred during parsing\n   Message: " << W( e.getMessage() ));
		errorsOccured = true;
	}

	catch ( const DOMException& e )
	{
		const unsigned int maxChars = 2047;
		XMLCh errText[maxChars + 1];

		MSG_ERROR(MSG_FLF << "DOM Error during parsing: '" << _filename.c_str() << "'\n" << "DOMException code is:  " << e.code);

		if ( DOMImplementation::loadDOMExceptionMsg( e.code, errText, maxChars ) )
		{
			MSG_ERROR(MSG_FLF << "Message is: " << W( errText ));
		}
		errorsOccured = true;
	}

	catch ( ... )
	{
		MSG_ERROR(MSG_FLF << "An error occurred during parsing\n ");
		errorsOccured = true;
	}

	std::shared_ptr<persistence::xml::XMLLoadHandler> handler = std::dynamic_pointer_cast<persistence::xml::XMLLoadHandler>(m_handler);
	if (handler)
	{
		handler->setDOMDocument( m_parser->getDocument() );
	}
	else
	{
		errorsOccured = true;
		MSG_ERROR(MSG_FLF << "LoadHandler is empty in XMLLoad::read()");
	}

	return ((errorsOccured == false) && (m_errReporter->getSawErrors() == false));
}
}
/* namespace xml */
} /* namespace persistence */
