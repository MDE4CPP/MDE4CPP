/*
 * XMLSaveHandler.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/xml/XMLSaveHandler.hpp"

#include <sstream> // used for addReferences()
#include <boost/algorithm/string.hpp> // used for string splitting

namespace persistence
{
namespace xml
{
XMLSaveHandler::XMLSaveHandler ()
{
	m_doc = nullptr;
	m_currentElement = nullptr;
}

XMLSaveHandler::~XMLSaveHandler ()
{
	if ( m_doc )
	{
		m_doc->release();
	}
}

/**/
DOMDocument *XMLSaveHandler::getDOMDocument ()
{
	return m_doc;
}

bool XMLSaveHandler::createRootNode ( const std::string& name, const std::string& ns_uri )
{
	return this->createRootNode( name, ns_uri, nullptr );
}

bool XMLSaveHandler::createRootNode ( const std::string& prefix, const std::string& name, const std::string& ns_uri )
{
	return this->createRootNode( prefix, name, ns_uri, nullptr );
}

bool XMLSaveHandler::createRootNode ( const std::string& prefix, const std::string& name, const std::string& ns_uri, DOMDocumentType *doctype )
{
	m_rootPrefix = prefix;
	return this->createRootNode( prefix + ":" + name, ns_uri, doctype );
}

bool XMLSaveHandler::createRootNode ( const std::string& name, const std::string& ns_uri, DOMDocumentType *doctype )
{
	DOMImplementation* impl = DOMImplementationRegistry::getDOMImplementation( X( "Core" ) );

	if ( impl != NULL )
	{
		try
		{
			m_doc = impl->createDocument( (ns_uri.empty()) ? 0 : X( ns_uri ), // root element namespace URI.
			X( name ),         					// root element name
			doctype ); 	                		// document type object (DTD).

			m_currentElement = m_doc->getDocumentElement(); // get root element
		}
		catch ( const OutOfMemoryException& )
		{
			MSG_ERROR( MSG_FLF << "OutOfMemoryException" );
			//errorCode = 5;
			return false;
		}
		catch ( const DOMException& e )
		{
			MSG_ERROR( MSG_FLF << "DOMException code is:  " << e.code << std::endl << W( e.getMessage() ) );
			//errorCode = 2;
			return false;
		}
		catch ( ... )
		{
			MSG_ERROR( MSG_FLF <<"An error occurred creating the document" );
			//errorCode = 3;
			return false;
		}
	}  // (impl != NULL)
	else
	{
		MSG_ERROR( MSG_FLF <<"Requested implementation is not supported" );
		//errorCode = 4;
		return false;
	}

	return true;
}

bool XMLSaveHandler::createAndAddElement ( const std::string& name )
{
	if ( m_doc == nullptr )
	{
		MSG_ERROR( MSG_FLF <<"No root-Element created first" );
		return false;
	}
	else
	{
		addChild( m_currentElement, m_doc->createElement( X( name ) ) );

		return true;
	}
}

void XMLSaveHandler::addChild ( DOMElement* parent_elem, DOMElement* child_elem )
{
	// Add child to parent Element, and set child as current Element.
	m_currentElement = (DOMElement *) parent_elem->appendChild( child_elem );
}

void XMLSaveHandler::addAttribute ( const std::string& name, const std::string& value )
{
	try
	{
		m_currentElement->setAttribute( X( name ), X( value ) );
	}
	catch ( const DOMException& e )
	{
		MSG_ERROR( MSG_FLF << "DOMException code is:  " << e.code << std::endl << W( e.getMessage() ) );
	}
	catch ( std::exception& e )
	{
		MSG_ERROR( MSG_FLF << "Exception code is:  " << e.what() );
	}
}

void XMLSaveHandler::addReferences ( const std::string &name, std::shared_ptr<ecore::EObject> object )
{
	try
	{
		std::string ref = persistence::base::HandlerHelper::extractReference( object, m_rootObject, m_rootPrefix );

		std::stringstream ss;
		std::string tmpStr = W( m_currentElement->getAttribute(X( name )) );

		if ( !tmpStr.empty() )
		{
			ss << tmpStr << " ";
		}
		ss << ref;

		addAttribute( name, ss.str() );
	}
	catch ( const DOMException& e )
	{
		MSG_ERROR( MSG_FLF << "DOMException code is:  " << e.code << std::endl << W( e.getMessage() ) );
	}
	catch ( std::exception& e )
	{
		MSG_ERROR( MSG_FLF << "Exception code is:  " << e.what() );
	}
}

void XMLSaveHandler::release ()
{
	if ( m_currentElement == nullptr )
	{
		MSG_ERROR( MSG_FLF << "Current DOMElement m_currentElement is nullptr" );
	}
	else
	{
		// set m_currentElement's parent node as new m_currentElement (decrease depth)
		m_currentElement = (DOMElement*) m_currentElement->getParentNode();
	}
}

} /* namespace xml */
} /* namespace persistence */

