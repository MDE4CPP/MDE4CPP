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

	m_rootPrefix = "ecore"; // TODO get correct prefix from document

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

		if (aName == "xsi:type")
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

} /* namespace xml */
} /* namespace persistence */
