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

				virtual bool createRootNode(const std::string& name, const std::string& ns_uri);
				virtual bool createRootNode(const std::string& prefix, const std::string& name, const std::string& ns_uri);
				virtual bool createRootNode(const std::string& name, const std::string& ns_uri, DOMDocumentType *doctype);
				virtual bool createRootNode(const std::string& prefix, const std::string& name, const std::string& ns_uri, DOMDocumentType *doctype);

				virtual bool createAndAddElement(const std::string& name);

				virtual void addAttribute(const std::string &name, const std::string& value);

				virtual void addReferences(const std::string &name, std::shared_ptr<ecore::EObject> object);
				virtual void addReference(const std::string &name, std::shared_ptr<ecore::EObject> object);
				virtual void addReference(const std::shared_ptr<ecore::EObject> object, const std::string &tagName, const bool typeRequired);

				virtual void release();
				virtual void finalize();
				virtual void addTypeReference(const std::string& href, const std::string& xmitype);

				virtual void addAttributeAsNode(const std::string& name, const std::string& value);

			private:

				DOMDocument *m_doc;
				DOMElement *m_currentElement;

				std::map<std::shared_ptr<ecore::EObject>, std::shared_ptr< std::list<std::pair<DOMElement*, std::string> > > > m_unresolvedReferences;

				void addChild(DOMElement *parent_elem, DOMElement *child_elem);

				virtual std::string getVersion();
				virtual std::string getXmlnsXMI();
		};
	} /* namespace xml */
} /* namespace persistence */

#endif /* XMLSaveHandler_HPP_ */
