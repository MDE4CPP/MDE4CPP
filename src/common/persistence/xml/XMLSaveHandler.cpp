/*
 * XMLSaveHandler.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/xml/XMLSaveHandler.hpp"

#ifdef NDEBUG
#define MSG_DEBUG(a) /**/
#else
#define MSG_DEBUG(a) std::cout << "| DEBUG    | " << a << std::endl
#endif
#define MSG_WARNING(a) std::cout << "| WARNING  | "<< a << std::endl
#define MSG_ERROR(a) std::cout << "| ERROR    | " << a << std::endl
#define MSG_FLF __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << "() "

#include <iostream>
#include <sstream> // used for addReferences()

#include "ecore/EObject.hpp"
#include "persistence/base/HandlerHelper.hpp"

#include "xerces/XStr.hpp"
#include "xerces/WStr.hpp"
#include "xercesc/dom/DOMException.hpp"
#include "xercesc/util/OutOfMemoryException.hpp"

#include "persistence/crossguid/guid.hpp"

using namespace persistence::xml;

XMLSaveHandler::XMLSaveHandler ()
{
	m_doc = nullptr;
	m_currentElement = nullptr;
}

XMLSaveHandler::~XMLSaveHandler ()
{
	if ( m_doc )
	{
		m_doc->release();
	}
}

/**/
DOMDocument *XMLSaveHandler::getDOMDocument ()
{
	return m_doc;
}

bool XMLSaveHandler::createRootNode ( const std::string& name, const std::string& ns_uri )
{
	return this->createRootNode( name, ns_uri, nullptr );
}

bool XMLSaveHandler::createRootNode ( const std::string& prefix, const std::string& name, const std::string& ns_uri )
{
	return this->createRootNode( prefix, name, ns_uri, nullptr );
}

bool XMLSaveHandler::createRootNode ( const std::string& prefix, const std::string& name, const std::string& ns_uri, DOMDocumentType *doctype )
{
	m_rootPrefix = prefix;
	return this->createRootNode( prefix + ":" + name, ns_uri, doctype );
}

bool XMLSaveHandler::createRootNode ( const std::string& name, const std::string& ns_uri, DOMDocumentType *doctype )
{
	DOMImplementation* impl = DOMImplementationRegistry::getDOMImplementation( X( "Core" ) );

	if ( impl != NULL )
	{
		try
		{
			m_doc = impl->createDocument( (ns_uri.empty()) ? 0 : X( ns_uri ), // root element namespace URI.
			X( name ),         					// root element name
			doctype ); 	                		// document type object (DTD).

			m_currentElement = m_doc->getDocumentElement(); // get root element
			m_currentElement->setAttribute(X("xmi:version"), X(getVersion()));
			m_currentElement->setAttribute(X("xmlns:xmi"), X(getXmlnsXMI()));
			m_currentElement->setAttribute(X("xmlns:xsi"), X("http://www.w3.org/2001/XMLSchema-instance"));

			if (!m_isXSIMode && m_rootObject != nullptr)
			{
				auto iter = m_refObjectName_map.find(m_rootObject);
				if (iter != m_refObjectName_map.end())
				{
					addAttribute("xmi:id", iter->second);
				}
				else
				{
					auto newGuid = xg::newGuid();
					addAttribute("xmi:id", newGuid .str() );
				}
			}
		}
		catch ( const OutOfMemoryException& )
		{
			MSG_ERROR( MSG_FLF << "OutOfMemoryException" );
			//errorCode = 5;
			return false;
		}
		catch ( const DOMException& e )
		{
			MSG_ERROR( MSG_FLF << "DOMException code is:  " << e.code << std::endl << W( e.getMessage() ) );
			//errorCode = 2;
			return false;
		}
		catch ( ... )
		{
			MSG_ERROR( MSG_FLF <<"An error occurred creating the document" );
			//errorCode = 3;
			return false;
		}
	}  // (impl != NULL)
	else
	{
		MSG_ERROR( MSG_FLF <<"Requested implementation is not supported" );
		//errorCode = 4;
		return false;
	}

	return true;
}

bool XMLSaveHandler::createAndAddElement ( const std::string& name )
{
	if ( m_doc == nullptr )
	{
		MSG_ERROR( MSG_FLF <<"No root-Element created first" );
		return false;
	}
	else
	{
		addChild( m_currentElement, m_doc->createElement( X( name ) ) );

		return true;
	}
}

void XMLSaveHandler::addChild ( DOMElement* parent_elem, DOMElement* child_elem )
{
	// Add child to parent Element, and set child as current Element.
	m_currentElement = (DOMElement *) parent_elem->appendChild( child_elem );
}

void XMLSaveHandler::addAttribute ( const std::string& name, const std::string& value )
{
	try
	{
		m_currentElement->setAttribute( X( name ), X( value ) );
	}
	catch ( const DOMException& e )
	{
		MSG_ERROR( MSG_FLF << "DOMException code is:  " << e.code << std::endl << W( e.getMessage() ) );
	}
	catch ( std::exception& e )
	{
		MSG_ERROR( MSG_FLF << "Exception code is:  " << e.what() );
	}
}

void XMLSaveHandler::addReferences ( const std::string &name, std::shared_ptr<ecore::EObject> object )
{
	if (object == nullptr)
	{
		std::cerr << "XMLSaveHandler::addReferences called with object == nullptr" << std::endl;
		return;
	}
	try
	{
		std::string ref = "";
		auto iter = m_refObjectName_map.find(object);
		if (iter != m_refObjectName_map.end())
		{
			ref = iter->second;

			std::stringstream ss;
			std::string tmpStr = W( m_currentElement->getAttribute(X( name )) );

			if ( !tmpStr.empty() )
			{
				ss << tmpStr << " ";
			}
			ss << ref;

			addAttribute( name, ss.str() );
		}
		else
		{
			//save reference later, after object is already saved using container
			std::shared_ptr<std::list<std::pair<DOMElement*, std::string> > > objList;
			auto objectReferenceListIter=m_unresolvedReferences.find(object);
			if(objectReferenceListIter==m_unresolvedReferences.end()) // first time object not found
			{
				objList.reset(new std::list<std::pair<DOMElement*, std::string> > ());
				m_unresolvedReferences.insert(std::pair< std::shared_ptr<ecore::EObject>, std::shared_ptr< std::list<std::pair<DOMElement*, std::string> > > > (object,  objList ) );
			}
			else
			{
				objList=objectReferenceListIter->second;
			}
			objList->push_back(std::pair <DOMElement*, std::string>(m_currentElement,name) );
		}
	}
	catch ( const DOMException& e )
	{
		MSG_ERROR( MSG_FLF << "DOMException code is:  " << e.code << std::endl << W( e.getMessage() ) );
	}
	catch ( std::exception& e )
	{
		MSG_ERROR( MSG_FLF << "Exception code is:  " << e.what() );
	}
}

void XMLSaveHandler::addReference(const std::string &name, std::shared_ptr<ecore::EObject> object)
{
	if (object == nullptr)
	{
		return;
	}

	if (object)
	{
		std::string ref = "";
		auto iter = m_refObjectName_map.find(object);
		if (iter != m_refObjectName_map.end())
		{
			ref = iter->second;
		}
		else
		{
			ref = persistence::base::HandlerHelper::extractReference(object, m_rootObject, m_rootPrefix, "");
			m_refObjectName_map.insert(std::pair<std::shared_ptr<ecore::EObject>, std::string>(object, ref));
		}

		if (!m_isXSIMode && name == "type")
		{
			unsigned index = ref.find(" ");
			if (index != std::string::npos)
			{
				std::string href = ref.substr(index+1, name.size()-index-1);
				std::string xmitype = ref.substr(0, index);
				addTypeReference(href, xmitype);
			}
			else
			{
				addAttribute(name, ref);
			}
		}
		else
		{
			addAttribute(name, ref);
		}
	}
}

void XMLSaveHandler::addReference(const std::shared_ptr<ecore::EObject> object, const std::string &tagName, const bool typeRequired)
{
	if (object == nullptr)
	{
		return;
	}

	if (m_savedObjects->find(object) != -1)
	{
		return;
	}

	m_savedObjects->push_back(object);

	// 1. Create and add Node-Element to model-tree
	createAndAddElement(tagName);

	// Add xmi-ID for every Reference
	auto iter = m_refObjectName_map.find(object);
	if (iter == m_refObjectName_map.end()) // store object information for future object references
	{
		auto myGuid = xg::newGuid();
		std::string objName = tagName+"."+myGuid.str() ;
		m_refObjectName_map.insert(std::pair<std::shared_ptr<ecore::EObject>, std::string>(object, objName ));
		addAttribute("xmi:id", objName);
	}
	else
	{
		addAttribute("xmi:id", iter->second);
	}

	if(typeRequired)
	{
		// 1.x Set Attribute "xsi:type" to the specific Class-Type
		if (m_isXSIMode)
		{
			addAttribute("xsi:type", extractType(object));
		}
		else
		{
			std::string fullType = extractType(object);
			unsigned int index = fullType.find(" ");
			std::string type = "";
			std::string ref = "";
			if (index != std::string::npos)
			{
				ref = fullType.substr(0, index-1);
				type = fullType.substr(index+1, fullType.size() - index -1);
				createAndAddElement(type);
				addAttribute("href", ref);
				addAttribute("xmi:type", type);
			}
			else
			{
				addAttribute("xmi:type", fullType);
			}
		}
	}

	// 2. Recursive call of save()
	object->save(m_thisPtr);

	// 3. Tell saveHandler for stepping to previous level
	release();
}


void XMLSaveHandler::release ()
{

	if ( m_currentElement == nullptr )
	{
		MSG_ERROR( MSG_FLF << "Current DOMElement m_currentElement is nullptr" );
	}
	else
	{
		// set m_currentElement's parent node as new m_currentElement (decrease depth)
		m_currentElement = (DOMElement*) m_currentElement->getParentNode();
	}
}

void XMLSaveHandler::finalize()
{
	release();

	//set unresolved References
	for(auto &unresolvedRef: m_unresolvedReferences)
	{
		int sizeObjRefList=unresolvedRef.second->size(); // size of list is used to avoid an infinite loop. If an object is not inside a model operation addReferences add unresolved object to m_unresolvedReferences
		auto objRefList =unresolvedRef.second->begin();
		for(int i=0; i< sizeObjRefList; i++)
		{
			m_currentElement=objRefList->first;
			addReferences(objRefList->second, unresolvedRef.first);
			objRefList++;
		}
		while(objRefList!=unresolvedRef.second->end()) // all objects after prior for loop are unresolved References, added in operation addReferences
		{
			MSG_ERROR( MSG_FLF << "Unresolved Reference to element: " << objRefList->second << ". Oject not included into main model element?");
			objRefList++;
		}
	}
}



void XMLSaveHandler::addTypeReference(const std::string& href, const std::string& xmitype)
{
	createAndAddElement("type");
	addAttribute("href", href);
	addAttribute("xmi:type", xmitype);
	release();
}


void XMLSaveHandler::addAttributeAsNode(const std::string& name, const std::string& value)
{
	createAndAddElement(name);
	m_currentElement->setTextContent(X(value));
	release();
}

std::string XMLSaveHandler::getVersion()
{
	if (m_isXSIMode)
	{
		return "2.0";
	}
	else
	{
		return "20131001";
	}
}

std::string XMLSaveHandler::getXmlnsXMI()
{
	if (m_isXSIMode)
	{
		return "http://www.omg.org/XMI";
	}
	else
	{
		return "http://www.omg.org/spec/XMI/20131001";
	}
}
