/*
 * XMLSaveHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_XML_XMLSAVEHANDLER_HPP
#define PERSISTENCE_XML_XMLSAVEHANDLER_HPP

#include "persistence/base/SaveHandler.hpp"
#include <list>
#include <string>

#include "xercesc/dom/DOM.hpp"
XERCES_CPP_NAMESPACE_USE

namespace ecore
{
	class EObject;
}

namespace persistence
{
	namespace xml
	{
		class XMLSaveHandler: public persistence::base::SaveHandler
		{
			public:
				XMLSaveHandler();
				~XMLSaveHandler();

				DOMDocument *getDOMDocument();

				bool createRootNode(const std::string& name, const std::string& ns_uri);
				bool createRootNode(const std::string& prefix, const std::string& name, const std::string& ns_uri);
				bool createRootNode(const std::string& name, const std::string& ns_uri, DOMDocumentType *doctype);
				bool createRootNode(const std::string& prefix, const std::string& name, const std::string& ns_uri, DOMDocumentType *doctype);

				bool createAndAddElement(const std::string& name);

				void addAttribute(const std::string &name, const std::string& value);

				void addReferences(const std::string &name, std::shared_ptr<ecore::EObject> object);

				void release();

			private:

				DOMDocument *m_doc;
				DOMElement *m_currentElement;

				void addChild(DOMElement *parent_elem, DOMElement *child_elem);
		};
	} /* namespace xml */
} /* namespace persistence */

#endif /* XMLSaveHandler_HPP_ */
