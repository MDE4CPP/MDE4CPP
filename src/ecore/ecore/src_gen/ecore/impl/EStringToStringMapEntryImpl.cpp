#include "ecore/impl/EStringToStringMapEntryImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence


//Factories an Package includes
#include "ecore/impl/ecoreFactoryImpl.hpp"
#include "ecore/impl/ecorePackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EStringToStringMapEntryImpl::EStringToStringMapEntryImpl()
{	
}

EStringToStringMapEntryImpl::~EStringToStringMapEntryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EStringToStringMapEntry "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}



EStringToStringMapEntryImpl::EStringToStringMapEntryImpl(const EStringToStringMapEntryImpl & obj):EStringToStringMapEntryImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EStringToStringMapEntry "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_key = obj.getKey();
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  EStringToStringMapEntryImpl::copy() const
{
	std::shared_ptr<EStringToStringMapEntryImpl> element(new EStringToStringMapEntryImpl(*this));
	element->setThisEStringToStringMapEntryPtr(element);
	return element;
}

std::shared_ptr<EClass> EStringToStringMapEntryImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEStringToStringMapEntry_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute key
*/
std::string EStringToStringMapEntryImpl::getKey() const 
{
	return m_key;
}

void EStringToStringMapEntryImpl::setKey(std::string _key)
{
	m_key = _key;
} 



/*
Getter & Setter for attribute value
*/
std::string EStringToStringMapEntryImpl::getValue() const 
{
	return m_value;
}

void EStringToStringMapEntryImpl::setValue(std::string _value)
{
	m_value = _value;
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



std::shared_ptr<EStringToStringMapEntry> EStringToStringMapEntryImpl::getThisEStringToStringMapEntryPtr() const
{
	return m_thisEStringToStringMapEntryPtr.lock();
}
void EStringToStringMapEntryImpl::setThisEStringToStringMapEntryPtr(std::weak_ptr<EStringToStringMapEntry> thisEStringToStringMapEntryPtr)
{
	m_thisEStringToStringMapEntryPtr = thisEStringToStringMapEntryPtr;
}
std::shared_ptr<ecore::EObject> EStringToStringMapEntryImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EStringToStringMapEntryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ESTRINGTOSTRINGMAPENTRY_ATTRIBUTE_KEY:
			return eAny(getKey()); //490
		case ecore::ecorePackage::ESTRINGTOSTRINGMAPENTRY_ATTRIBUTE_VALUE:
			return eAny(getValue()); //491
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool EStringToStringMapEntryImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ESTRINGTOSTRINGMAPENTRY_ATTRIBUTE_KEY:
			return getKey() != ""; //490
		case ecore::ecorePackage::ESTRINGTOSTRINGMAPENTRY_ATTRIBUTE_VALUE:
			return getValue() != ""; //491
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool EStringToStringMapEntryImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::ESTRINGTOSTRINGMAPENTRY_ATTRIBUTE_KEY:
		{
			// BOOST CAST
			std::string _key = newValue->get<std::string>();
			setKey(_key); //490
			return true;
		}
		case ecore::ecorePackage::ESTRINGTOSTRINGMAPENTRY_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			std::string _value = newValue->get<std::string>();
			setValue(_value); //491
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EStringToStringMapEntryImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get ecoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EStringToStringMapEntryImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("key");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setKey(value);
		}

		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setValue(value);
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void EStringToStringMapEntryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<ecore::ecoreFactory> modelFactory=ecore::ecoreFactory::eInstance();

	//load BasePackage Nodes
}

void EStringToStringMapEntryImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void EStringToStringMapEntryImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void EStringToStringMapEntryImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getEStringToStringMapEntry_Attribute_key()) )
		{
			saveHandler->addAttribute("key", this->getKey());
		}

		if ( this->eIsSet(package->getEStringToStringMapEntry_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

