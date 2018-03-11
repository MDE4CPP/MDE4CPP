/*
 * XMLLoadHandler.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/xml/XMLLoadHandler.hpp"

#include <sstream> // used for getLevel()
#include <boost/algorithm/string.hpp> // used for string splitting


#include "boost/exception/to_string.hpp"

#include "ecore/EObject.hpp"
#include "ecore/EStructuralFeature.hpp"

#include "xerces/XStr.hpp"
#include "xerces/WStr.hpp"
#include "xercesc/dom/DOMNamedNodeMap.hpp"

namespace persistence
{
namespace xml
{

XMLLoadHandler::XMLLoadHandler ()
{
	m_doc = nullptr;
	m_currentElement = nullptr;
}

XMLLoadHandler::~XMLLoadHandler ()
{
	if ( m_doc )
	{
		m_doc->release();
	}
}

/**/

DOMDocument *XMLLoadHandler::getDOMDocument ()
{
	return m_doc;
}

void XMLLoadHandler::setDOMDocument ( DOMDocument * doc )
{
	assert( doc );
	if ( doc == nullptr )
	{
		MSG_ERROR( MSG_FLF << " Current DOMDocument 'doc' is empty." );
		return;
	}
	m_doc = doc;
	m_rootObject = nullptr;
	m_currentElement = m_doc->getDocumentElement(); // get root element

	if ( !m_currentElement )
	{
		MSG_ERROR( MSG_FLF << " Current DOMElement (root) does not exist." );
		assert( m_currentElement );
	}

	std::string rootTagName = W(m_currentElement->getTagName());
	std::cout << "rootTagName:  " <<  rootTagName << std::endl;
	unsigned int index = rootTagName.find(':');
	if (index != std::string::npos)
	{
		m_rootPrefix = rootTagName.substr(0, index);
		m_rootName = rootTagName.substr(index+1, rootTagName.size()-index);

		std::string id = W(m_currentElement->getAttribute(X("xmi:id")));
		std::cout << "root has xmi:id " << id << std::endl;
		m_isXSIMode = id.empty();
	}
	else
	{
		MSG_ERROR(MSG_FLF << " root prefix could not be selected from root tag name '" << rootTagName << "'");
	}

	if ( m_currentElement->getNodeType() == DOMNode::ELEMENT_NODE )
	{
		m_currentElements.push_back( m_currentElement );
	}
	else
	{
		MSG_ERROR( MSG_FLF << " Current DOMElement (root) is not a DOMNode::ELEMENT_NODE." );
	}
}

unsigned int XMLLoadHandler::getNumOfChildNodes ()
{
	DOMNode *child;
	unsigned int count = 0;

	for ( child = m_currentElement->getLastChild(); child != 0; child = child->getPreviousSibling() )
	{
		if ( child->getNodeType() == DOMNode::ELEMENT_NODE )
		{
			++count;
		}
	}
	if ( count != m_currentElement->getChildElementCount() )
	{
		MSG_ERROR( MSG_FLF << "Different Number of Children" );
	}
	return count;
}

std::string XMLLoadHandler::getNextNodeName ()
{
	std::string nodeName;
	DOMNode *child;

	if ( m_currentElements.size() == 0 )
	{
		nodeName = "";
	}
	else
	{
		m_currentElement = (DOMElement*) m_currentElements.back();

		nodeName = W( m_currentElement->getNodeName() );

		m_currentElements.pop_back();

		for ( child = m_currentElement->getLastChild(); child != 0; child = child->getPreviousSibling() )
		{
			if ( child->getNodeType() == DOMNode::ELEMENT_NODE )
			{
				m_currentElements.push_back( child );
			}
		}

#if 0
		std::cout << "| DEBUG    | " << "Node-List: " << std::endl << "|          | ";
		for ( auto current_elem : m_currentElements )
		{
			std::cout << "<" << W( current_elem->getNodeName() ) << "> ";
		}
		std::cout << std::endl;
#endif
	}
	//MSG_DEBUG("NodeName: " << nodeName);

	return nodeName;
}

std::map<std::string, std::string> XMLLoadHandler::getAttributeList ()
{
	std::map<std::string, std::string> attributeList;

	DOMAttr *pAttributeNode;
	std::string aName;
	std::string aValue;

	DOMNamedNodeMap *pAttributes = m_currentElement->getAttributes();
	const XMLSize_t nSize = pAttributes->getLength();

	//MSG_DEBUG("\t" << "Attributes:");
	//MSG_DEBUG("\t" << "-----------");

	for ( XMLSize_t i = 0; i < nSize; ++i )
	{
		pAttributeNode = (DOMAttr*) pAttributes->item( i );
		// get attribute name
		aName = W( pAttributeNode->getName() );

		// get attribute type
		aValue = W( pAttributeNode->getValue() );

		// Print Attribute Name and Value
		//MSG_DEBUG"\t" << aName << "=" << aValue);

		attributeList.insert( std::pair<std::string, std::string>( aName, aValue ) );
	}

	return attributeList;
}

std::string XMLLoadHandler::getCurrentXSITypeName ()
{
	DOMAttr *pAttributeNode;
	std::string aName;

	DOMNamedNodeMap *pAttributes = m_currentElement->getAttributes();
	const XMLSize_t nSize = pAttributes->getLength();

	for ( XMLSize_t i = 0; i < nSize; ++i )
	{
		pAttributeNode = (DOMAttr*) pAttributes->item( i );
		// get attribute name
		aName = W( pAttributeNode->getName() );

		if (aName == "xsi:type" or aName == "xmi:type")
		{
			std::string _type = W(pAttributeNode->getValue());
			size_t const double_dot = _type.find(L':', 0);
			std::string _type_ns = _type.substr(0, double_dot); // TODO '_type_ns' is not used in this case
			std::string _type_name = _type.substr(double_dot + 1);
			return _type_name;
		}
	}

	return "";
}


std::string XMLLoadHandler::getCurrentXMIID()
{
	DOMAttr *pAttributeNode;
	std::string aName;

	DOMNamedNodeMap *pAttributes = m_currentElement->getAttributes();
	const XMLSize_t nSize = pAttributes->getLength();

	for ( XMLSize_t i = 0; i < nSize; ++i )
	{
		pAttributeNode = (DOMAttr*) pAttributes->item( i );
		// get attribute name
		aName = W( pAttributeNode->getName() );

		if (aName == "xmi:id")
		{
			std::string id = W(pAttributeNode->getValue());
			return id;
		}
	}

	return "";
}

std::shared_ptr<ecore::EObject> XMLLoadHandler::checkNodeType(std::shared_ptr<ecore::EObject> object)
{
	DOMNodeList* dom = m_currentElement->getChildNodes();
	const XMLSize_t size = dom->getLength();

	for (XMLSize_t i=0; i<size; i++)
	{
		DOMNode* node = dom->item(i);
		std::string nodeName = W(node->getNodeName());
		if (nodeName == "type")
		{
			std::string type = "";
			std::string href = "";
			DOMNamedNodeMap* attrListNode = node->getAttributes();
			const XMLSize_t sizeAttrList = attrListNode->getLength();

			for (XMLSize_t i = 0; i < sizeAttrList; ++i)
			{
				DOMAttr* attributeNode = (DOMAttr*) attrListNode->item( i );
				// get attribute name
				std::string aName = W( attributeNode->getName() );

				if (aName == "xmi:type")
				{
					type = W(attributeNode->getValue());
				}
				if (aName == "href")
				{
					href = W(attributeNode->getValue());
				}
			}

			type = type + " " + href;
			auto iter = m_refToObject_map.find(type);
			if (iter != m_refToObject_map.end())
			{
				return iter->second;
			}
			else
			{


				loadTypes(type);
				auto iter = m_refToObject_map.find(type);
				if (iter != m_refToObject_map.end())
				{
					return iter->second;
				}
			}
		}
	}
	return nullptr;
}

} /* namespace xml */
} /* namespace persistence */
