/*
 * XMLSave.hpp
 *
 *  Created on: 16.05.2017
 *      Author: Alexander
 */

#ifndef XMLSAVE_HPP_
#define XMLSAVE_HPP_

#include "Save.hpp"
#include "XMLSaveHandler.hpp"

#include <string>

#include <xercesc/util/OutOfMemoryException.hpp>
#include <xercesc/dom/DOMException.hpp>
#include <xercesc/dom/DOM.hpp>
//#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

#include "xerces/XStr.hpp"
#include "xerces/DOMTreeErrorReporter.hpp"
#include "xerces/DOMPrintFilter.hpp"
#include "xerces/DOMPrintErrorHandler.hpp"

namespace persistence
{
namespace xml
{

class XMLSave : public persistence::base::Save
{
public:
	XMLSave ();
	~XMLSave ();

private:
	// ---------------------------------------------------------------------------
	//  Local data
	//
	//  gXmlFile
	//      The path to the file to parser. Set via command line.
	//
	//  gDoNamespaces
	//      Indicates whether namespace processing should be done.
	//
	//  gDoSchema
	//      Indicates whether schema processing should be done.
	//
	//  gSchemaFullChecking
	//      Indicates whether full schema constraint checking should be done.
	//
	//  gDoCreate
	//      Indicates whether entity reference nodes needs to be created or not
	//      Defaults to false
	//
	//  gOutputEncoding
	//      The encoding we are to output in. If not set on the command line,
	//      then it is defaults to the encoding of the input XML file.
	//
	//  gSplitCdataSections
	//      Indicates whether split-cdata-sections is to be enabled or not.
	//
	//  gDiscardDefaultContent
	//      Indicates whether default content is discarded or not.
	//
	//  gUseFilter
	//      Indicates if user wants to plug in the DOMPrintFilter.
	//
	//  gValScheme
	//      Indicates what validation scheme to use. It defaults to 'auto', but
	//      can be set via the -v= command.
	//
	// ---------------------------------------------------------------------------
	char* m_XPathExpression;

	// options for DOMLSSerializer's features
	XMLCh* m_OutputEncoding;

	bool m_SplitCdataSections;
	bool m_DiscardDefaultContent;
	bool m_UseFilter;
	bool m_FormatPrettyPrint;
	bool m_WriteBOM;

	bool write ( const std::string &filename );

};
} /* namespace xml */
} /* namespace persistence */

#endif /* XMLSAVE_HPP_ */
