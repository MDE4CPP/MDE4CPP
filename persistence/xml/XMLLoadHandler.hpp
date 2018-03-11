/*
 * XMLLoadHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_XML_XMLLOADHANDLER_HPP
#define PERSISTENCE_XML_XMLLOADHANDLER_HPP

#include "persistence/base/LoadHandler.hpp"
#include "persistence/base/HandlerHelper.hpp"

#include <map>
#include <list>
#include <string>

#include "xercesc/dom/DOM.hpp"
XERCES_CPP_NAMESPACE_USE

namespace persistence
{
	namespace xml
	{
		class XMLLoadHandler: public persistence::base::LoadHandler
		{
			public:
				XMLLoadHandler();
				~XMLLoadHandler();

				DOMDocument* getDOMDocument();
				void setDOMDocument(DOMDocument* doc);

				unsigned int getNumOfChildNodes();
				std::string getNextNodeName();
				std::map<std::string, std::string> getAttributeList();
				virtual std::string getCurrentXSITypeName();
				virtual std::string getCurrentXMIID();
				virtual std::shared_ptr<ecore::EObject> checkNodeType(std::shared_ptr<ecore::EObject> object);
				virtual std::shared_ptr<std::string> getChildText();

			private:
				DOMDocument* m_doc;
				DOMElement* m_currentElement;
				std::list<DOMNode*> m_currentElements;
		};

	} /* namespace xml */
} /* namespace persistence */

#endif
