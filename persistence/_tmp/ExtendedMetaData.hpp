/*
 * ExtendedMetaData.hpp
 *
 *  Created on: 16.05.2017
 *      Author: Alexander
 */

#ifndef EXTENDEDMETADATA_HPP_
#define EXTENDEDMETADATA_HPP_

#include <string>

namespace persistence {

class ExtendedMetaData {

public:
	/**
	 * The URI used as the annotation source: "http:///org/eclipse/emf/ecore/util/ExtendedMetaData".
	 */
	static const std::string ANNOTATION_URI;

	/**
	 * The namespace URI for XML namespaces: "http://www.w3.org/2000/xmlns/".
	 */
	static const std::string XMLNS_URI;

	/**
	 * The XML namespace URI: "http://www.w3.org/XML/1998/namespace".
	 */
	static const std::string XML_URI;

	/**
	 * The XML Schema instance namespace URI: "http://www.w3.org/2001/XMLSchema-instance".
	 */
	static const std::string XSI_URI;

	/**
	 * The XML Schema namespace URI: "http://www.w3.org/2001/XMLSchema".
	 */
	static const std::string XML_SCHEMA_URI;

	/**
	 * The XMI namespace URI: "http://www.omg.org/XMI".
	 */
	static const std::string XMI_URI;

	/**
	 * The prefix reserved for XML namespaces: "xmlns".
	 */
	static const std::string XMLNS_PREFIX;

	/**
	 * The prefix used for the XML Schema instance namespace.
	 */
	static const std::string XSI_PREFIX;

	/**
	 * The prefix used for the XML instance namespace.
	 */
	static const std::string XMI_PREFIX;

	/**
	 * The XML version: "1.0".
	 */
	static const std::string XML_VERSION;

	/**
	 * The XML encoding for ASCII: "ascii".
	 */
	static const std::string XML_ENCODING_ASCII;
	/**
	 * The XML encoding for UFT-8: "UFT-8".
	 */
	static const std::string XML_ENCODING_UFT8;
	/**
	 * The XML encoding: "1.0".
	 */
	static const std::string XML_ENCODING_DEFAULT;

};

} /* namespace persistence */

#endif /* EXTENDEDMETADATA_HPP_ */
