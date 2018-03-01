/*
 * XMLSave.cpp
 *
 *  Created on: 16.05.2017
 *      Author: Alexander
 */

#include "XMLSave.hpp"
//#include "ExtendedMetaData.hpp"

namespace persistence
{
namespace xml
{
XMLSave::XMLSave ()
{
	m_handler.reset( new persistence::xml::XMLSaveHandler() );
	m_XPathExpression = 0;

	// options for DOMLSSerializer's features
	m_OutputEncoding = 0;

	m_SplitCdataSections = true;
	m_DiscardDefaultContent = true;
	m_UseFilter = false;
	m_FormatPrettyPrint = true;
	m_WriteBOM = false;

	//m_ValScheme = XercesDOMParser::Val_Auto;

	// Initialize the XML4C2 system
	try
	{
		XMLPlatformUtils::Initialize();
	}

	catch ( const XMLException &toCatch )
	{
		MSG_ERROR( MSG_FLF <<"Error during Xerces-c Initialization.\n" << "  Exception message:" << W( toCatch.getMessage() ) );
		return;
	}
}

XMLSave::~XMLSave ()
{
	if ( m_handler )
	{
		m_handler.reset();
	}
	XMLPlatformUtils::Terminate();
}

bool XMLSave::write ( const std::string &filename )
{

	char* outputfile = (char*) filename.c_str();

	std::shared_ptr<persistence::xml::XMLSaveHandler> handler = std::dynamic_pointer_cast<persistence::xml::XMLSaveHandler>( m_handler );
	if ( !handler )
	{
		MSG_ERROR( MSG_FLF <<"SaveHandler is empty" );
		return false;
	}
	// Get DOM Document from handler
	DOMDocument *doc = handler->getDOMDocument();

	DOMPrintFilter *myFilter = 0;

	try
	{
		// get a serializer, an instance of DOMLSSerializer
		XMLCh tempStr[3] =
		{ chLatin_L, chLatin_S, chNull };
		DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation( tempStr );
		DOMLSSerializer *theSerializer = ((DOMImplementationLS*) impl)->createLSSerializer();
		DOMLSOutput *theOutputDesc = ((DOMImplementationLS*) impl)->createLSOutput();

		// set user specified output encoding
		theOutputDesc->setEncoding( m_OutputEncoding );

		// plug in user's own filter
		if ( m_UseFilter )
		{
			// even we say to show attribute, but the DOMLSSerializer
			// will not show attribute nodes to the filter as
			// the specs explicitly says that DOMLSSerializer shall
			// NOT show attributes to DOMLSSerializerFilter.
			//
			// so DOMNodeFilter::SHOW_ATTRIBUTE has no effect.
			// same DOMNodeFilter::SHOW_DOCUMENT_TYPE, no effect.
			//
			myFilter = new DOMPrintFilter( DOMNodeFilter::SHOW_ELEMENT | DOMNodeFilter::SHOW_ATTRIBUTE | DOMNodeFilter::SHOW_DOCUMENT_TYPE );
			theSerializer->setFilter( myFilter );
		}

		// plug in user's own error handler
		DOMErrorHandler *myErrorHandler = new DOMPrintErrorHandler();
		DOMConfiguration* serializerConfig = theSerializer->getDomConfig();
		serializerConfig->setParameter( XMLUni::fgDOMErrorHandler, myErrorHandler );

		// set feature if the serializer supports the feature/mode
		if ( serializerConfig->canSetParameter( XMLUni::fgDOMWRTSplitCdataSections, m_SplitCdataSections ) )
		{
			serializerConfig->setParameter( XMLUni::fgDOMWRTSplitCdataSections, m_SplitCdataSections );
		}
		if ( serializerConfig->canSetParameter( XMLUni::fgDOMWRTDiscardDefaultContent, m_DiscardDefaultContent ) )
		{
			serializerConfig->setParameter( XMLUni::fgDOMWRTDiscardDefaultContent, m_DiscardDefaultContent );
		}
		if ( serializerConfig->canSetParameter( XMLUni::fgDOMWRTFormatPrettyPrint, m_FormatPrettyPrint ) )
		{
			serializerConfig->setParameter( XMLUni::fgDOMWRTFormatPrettyPrint, m_FormatPrettyPrint );
		}
		if ( serializerConfig->canSetParameter( XMLUni::fgDOMWRTBOM, m_WriteBOM ) )
		{
			serializerConfig->setParameter( XMLUni::fgDOMWRTBOM, m_WriteBOM );
		}
		//
		// Plug in a format target to receive the resultant
		// XML stream from the serializer.
		//
		// StdOutFormatTarget prints the resultant XML stream
		// to stdout once it receives any thing from the serializer.
		//
		XMLFormatTarget *myFormTarget;
		if ( outputfile )
		{
			myFormTarget = new LocalFileFormatTarget( outputfile );
		}
		else
		{
			myFormTarget = new StdOutFormatTarget();
		}
		theOutputDesc->setByteStream( myFormTarget );
		/*
		 // get the DOM representation
		 DOMDocument *doc = parser->getDocument();
		 */
		//
		// do the serialization through DOMLSSerializer::write();
		//
		if ( m_XPathExpression != NULL )
		{
			XMLCh* xpathStr = XMLString::transcode( m_XPathExpression );
			DOMElement* root = doc->getDocumentElement();
			try
			{
				DOMXPathNSResolver* resolver = doc->createNSResolver( root );
				DOMXPathResult* result = doc->evaluate( xpathStr, root, resolver, DOMXPathResult::ORDERED_NODE_SNAPSHOT_TYPE,
				NULL );

				XMLSize_t nLength = result->getSnapshotLength();
				for ( XMLSize_t i = 0; i < nLength; i++ )
				{
					result->snapshotItem( i );
					theSerializer->write( result->getNodeValue(), theOutputDesc );
				}

				result->release();
				resolver->release();
			}
			catch ( const DOMXPathException& e )
			{
				MSG_ERROR( MSG_FLF << "An error occurred during processing of the XPath expression. Msg is:" << std::endl << W( e.getMessage() ) );
				//retval = 4;
			}
			catch ( const DOMException& e )
			{
				MSG_ERROR( MSG_FLF <<"An error occurred during processing of the XPath expression. Msg is:" << std::endl << W( e.getMessage() ) );
				//retval = 4;
			}
			XMLString::release( &xpathStr );
		}
		else
		{
			// Default write
			theSerializer->write( doc, theOutputDesc );
		}
		theOutputDesc->release();
		theSerializer->release();

		//
		// Filter, formatTarget and error handler
		// are NOT owned by the serializer.
		//
		delete myFormTarget;
		delete myErrorHandler;

		if ( m_UseFilter )
		{
			delete myFilter;
		}
	}
	catch ( const OutOfMemoryException& )
	{
		MSG_ERROR( MSG_FLF << "OutOfMemoryException" );
		//retval = 5;
	}
	catch ( XMLException& e )
	{
		MSG_ERROR( MSG_FLF <<"An error occurred during creation of output transcoder. Msg is:" << std::endl << W( e.getMessage() ) );
		//retval = 4;
	}
	return true;
}

} /* namespace xml */
} /* namespace persistence */
