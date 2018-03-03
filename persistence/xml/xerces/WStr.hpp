/*
 * WStr.h
 *
 *  Created on: 28.06.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_XML_XERCES_WSTR_HPP
#define PERSISTENCE_XML_XERCES_WSTR_HPP

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/XMLString.hpp>
#include <string>

XERCES_CPP_NAMESPACE_USE

#define W(str) WStr(str).unicodeForm()

// ---------------------------------------------------------------------------
//  This is a simple class that lets us do easy (though not terribly efficient)
//  trancoding of char* data to XMLCh data.
// ---------------------------------------------------------------------------
class WStr
{
	public:
		// -----------------------------------------------------------------------
		//  Constructors and Destructor
		// -----------------------------------------------------------------------
		WStr(const XMLCh* const toTranscode);
		WStr(const WStr& other);
		~WStr();

		// -----------------------------------------------------------------------
		//  Getter methods
		// -----------------------------------------------------------------------
		const std::string unicodeForm() const;

	private:
		// -----------------------------------------------------------------------
		//  Private data members
		//
		//  m_local
		//      This is the string of the Unicode XMLCh format.
		// -----------------------------------------------------------------------
		char* m_local;
};

#endif /* WSTR_HPP_ */
