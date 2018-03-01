/*
 * XMLLoad.hpp
 *
 *  Created on: 16.05.2017
 *      Author: Alexander
 */

#ifndef XMLLOAD_HPP_
#define XMLLOAD_HPP_

#include "persistence/base/Load.hpp"
#include "persistence/xml/XMLLoadHandler.hpp"

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>

#include "xerces/DOMTreeErrorReporter.hpp"
#include "xerces/WStr.hpp"

#include <exception>

namespace persistence
{
namespace xml
{
class XMLLoad : public persistence::base::Load
{
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
	bool m_DoNamespaces;
	bool m_DoSchema;
	bool m_SchemaFullChecking;
	bool m_DoCreate;

	XercesDOMParser::ValSchemes m_ValScheme;

	// Parser and Error	handler

	XercesDOMParser *m_parser;
	DOMTreeErrorReporter *m_errReporter;

public:
	XMLLoad ();
	~XMLLoad ();

private:
	bool read ( const std::string &filename );

};

} /* namespace xml */
} /* namespace persistence */

#endif /* XMLLOAD_HPP_ */
