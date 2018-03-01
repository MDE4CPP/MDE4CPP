/*
 * XMLLoadHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef XMLLoadHandler_HPP_
#define XMLLoadHandler_HPP_

#include "LoadHandler.hpp"
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
#include "EStructuralFeature.hpp"

namespace persistence
{
namespace xml
{
class XMLLoadHandler : public persistence::base::LoadHandler
{
public:
	XMLLoadHandler ();
	~XMLLoadHandler ();

	DOMDocument *getDOMDocument ();
	void setDOMDocument ( DOMDocument * doc );

	unsigned int getNumOfChildNodes ();
	std::string getNextNodeName ();
	std::map<std::string, std::string> getAttributeList ();

private:
	DOMDocument *m_doc;
	DOMElement *m_currentElement;
	std::list<DOMNode *> m_currentElements;
};

} /* namespace xml */
} /* namespace persistence */

#endif /* XMLLoadHandler_HPP_ */
