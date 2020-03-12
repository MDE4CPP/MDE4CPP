#include "uml/impl/ImageImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Element.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ImageImpl::ImageImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

ImageImpl::~ImageImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Image "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ImageImpl::ImageImpl(std::weak_ptr<uml::Element > par_owner)
			:ImageImpl()
			{
			    m_owner = par_owner;
			}



ImageImpl::ImageImpl(const ImageImpl & obj):ImageImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Image "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_content = obj.getContent();
	m_format = obj.getFormat();
	m_location = obj.getLocation();

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ImageImpl::copy() const
{
	std::shared_ptr<ImageImpl> element(new ImageImpl(*this));
	element->setThisImagePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ImageImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getImage_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ImageImpl::setContent(std::string _content)
{
	m_content = _content;
} 

std::string ImageImpl::getContent() const 
{
	return m_content;
}

void ImageImpl::setFormat(std::string _format)
{
	m_format = _format;
} 

std::string ImageImpl::getFormat() const 
{
	return m_format;
}

void ImageImpl::setLocation(std::string _location)
{
	m_location = _location;
} 

std::string ImageImpl::getLocation() const 
{
	return m_location;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ImageImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<Image> ImageImpl::getThisImagePtr() const
{
	return m_thisImagePtr.lock();
}
void ImageImpl::setThisImagePtr(std::weak_ptr<Image> thisImagePtr)
{
	m_thisImagePtr = thisImagePtr;
	setThisElementPtr(thisImagePtr);
}
std::shared_ptr<ecore::EObject> ImageImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ImageImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::IMAGE_ATTRIBUTE_CONTENT:
			return eAny(getContent()); //1123
		case uml::UmlPackage::IMAGE_ATTRIBUTE_FORMAT:
			return eAny(getFormat()); //1124
		case uml::UmlPackage::IMAGE_ATTRIBUTE_LOCATION:
			return eAny(getLocation()); //1125
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool ImageImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::IMAGE_ATTRIBUTE_CONTENT:
			return getContent() != ""; //1123
		case uml::UmlPackage::IMAGE_ATTRIBUTE_FORMAT:
			return getFormat() != ""; //1124
		case uml::UmlPackage::IMAGE_ATTRIBUTE_LOCATION:
			return getLocation() != ""; //1125
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool ImageImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::IMAGE_ATTRIBUTE_CONTENT:
		{
			// BOOST CAST
			std::string _content = newValue->get<std::string>();
			setContent(_content); //1123
			return true;
		}
		case uml::UmlPackage::IMAGE_ATTRIBUTE_FORMAT:
		{
			// BOOST CAST
			std::string _format = newValue->get<std::string>();
			setFormat(_format); //1124
			return true;
		}
		case uml::UmlPackage::IMAGE_ATTRIBUTE_LOCATION:
		{
			// BOOST CAST
			std::string _location = newValue->get<std::string>();
			setLocation(_location); //1125
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ImageImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ImageImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("content");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setContent(value);
		}

		iter = attr_list.find("format");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setFormat(value);
		}

		iter = attr_list.find("location");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setLocation(value);
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void ImageImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	ElementImpl::loadNode(nodeName, loadHandler);
}

void ImageImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ElementImpl::resolveReferences(featureID, references);
}

void ImageImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ImageImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getImage_Attribute_content()) )
		{
			saveHandler->addAttribute("content", this->getContent());
		}

		if ( this->eIsSet(package->getImage_Attribute_format()) )
		{
			saveHandler->addAttribute("format", this->getFormat());
		}

		if ( this->eIsSet(package->getImage_Attribute_location()) )
		{
			saveHandler->addAttribute("location", this->getLocation());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

