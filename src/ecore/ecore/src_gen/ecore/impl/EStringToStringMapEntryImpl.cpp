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
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"

#include <exception> // used in Persistence


#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EStringToStringMapEntryImpl::EStringToStringMapEntryImpl()
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
	return EcorePackageImpl::eInstance()->getEStringToStringMapEntry_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EStringToStringMapEntryImpl::setKey(std::string _key)
{
	m_key = _key;
} 

std::string EStringToStringMapEntryImpl::getKey() const 
{
	return m_key;
}

void EStringToStringMapEntryImpl::setValue(std::string _value)
{
	m_value = _value;
} 

std::string EStringToStringMapEntryImpl::getValue() const 
{
	return m_value;
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
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_EATTRIBUTE_KEY:
			return eAny(getKey()); //490
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_EATTRIBUTE_VALUE:
			return eAny(getValue()); //491
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool EStringToStringMapEntryImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_EATTRIBUTE_KEY:
			return getKey() != ""; //490
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_EATTRIBUTE_VALUE:
			return getValue() != ""; //491
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool EStringToStringMapEntryImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_EATTRIBUTE_KEY:
		{
			// BOOST CAST
			std::string _key = newValue->get<std::string>();
			setKey(_key); //490
			return true;
		}
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_EATTRIBUTE_VALUE:
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
	// get EcoreFactory
	std::shared_ptr<ecore::EcoreFactory> modelFactory = ecore::EcoreFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void EStringToStringMapEntryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void EStringToStringMapEntryImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
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
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getEStringToStringMapEntry_EAttribute_key()) )
		{
			saveHandler->addAttribute("key", this->getKey());
		}

		if ( this->eIsSet(package->getEStringToStringMapEntry_EAttribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

