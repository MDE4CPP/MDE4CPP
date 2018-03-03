/*
 * XStr.h
 *
 *  Created on: 28.06.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_XML_XERCES_XSTR_HPP
#define PERSISTENCE_XML_XERCES_XSTR_HPP

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/XMLString.hpp>
#include <string>

XERCES_CPP_NAMESPACE_USE

#define X(str) XStr(str).unicodeForm()

// ---------------------------------------------------------------------------
//  This is a simple class that lets us do easy (though not terribly efficient)
//  trancoding of char* data to XMLCh data.
// ---------------------------------------------------------------------------
class XStr
{
	public:
		// -----------------------------------------------------------------------
		//  Constructors and Destructor
		// -----------------------------------------------------------------------
		XStr(const char* const toTranscode);
		XStr(const std::string& str);
		~XStr();

		// -----------------------------------------------------------------------
		//  Getter methods
		// -----------------------------------------------------------------------
		const XMLCh* unicodeForm() const;

	private:
		// -----------------------------------------------------------------------
		//  Private data members
		//
		//  fUnicodeForm
		//      This is the Unicode XMLCh format of the string.
		// -----------------------------------------------------------------------
		XMLCh* fUnicodeForm;
};

#endif
