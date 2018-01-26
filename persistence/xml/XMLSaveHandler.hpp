/*
 * XMLSaveHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef XMLSaveHandler_HPP_
#define XMLSaveHandler_HPP_

#include "SaveHandler.hpp"
#include "HandlerHelper.hpp"

#include <map>
#include <list>
#include <string>
#include <set>
#include <exception>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMException.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>

#include "xerces/XStr.hpp"
#include "xerces/WStr.hpp"

#include "boost/exception/to_string.hpp"

#include "EObject.hpp"

namespace persistence
{
namespace xml
{
class XMLSaveHandler : public persistence::base::SaveHandler
{
public:
	XMLSaveHandler ();
	~XMLSaveHandler ();

	void setDOMDocument ( DOMDocument * doc );
	DOMDocument *getDOMDocument ();

	bool createRootNode ( const std::string& name, const std::string& ns_uri );
	bool createRootNode ( const std::string& prefix, const std::string& name, const std::string& ns_uri );
	bool createRootNode ( const std::string& name, const std::string& ns_uri, DOMDocumentType *doctype );
	bool createRootNode ( const std::string& prefix, const std::string& name, const std::string& ns_uri, DOMDocumentType *doctype );

	bool createAndAddElement ( const std::string& name );

	void addAttribute ( const std::string &name, const std::string& value );

	void addReferences ( const std::string &name, std::shared_ptr<ecore::EObject> object );

	void release ();

private:

	DOMDocument *m_doc;
	DOMElement *m_currentElement;
	std::list<DOMNode *> m_currentElements;

	void addChild ( DOMElement *parent_elem, DOMElement *child_elem );
};
} /* namespace xml */
} /* namespace persistence */

#endif /* XMLSaveHandler_HPP_ */
