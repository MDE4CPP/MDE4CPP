#include "libraryModel_ecore/impl/NamedElementImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "libraryModel_ecore/impl/LibraryModel_ecorePackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "libraryModel_ecore/LibraryModel_ecoreFactory.hpp"
#include "libraryModel_ecore/LibraryModel_ecorePackage.hpp"
#include <exception> // used in Persistence


#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "libraryModel_ecore/LibraryModel_ecorePackage.hpp"
#include "libraryModel_ecore/LibraryModel_ecoreFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace libraryModel_ecore;

//*********************************
// Constructor / Destructor
//*********************************
NamedElementImpl::NamedElementImpl()
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

NamedElementImpl::~NamedElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete NamedElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




NamedElementImpl::NamedElementImpl(const NamedElementImpl & obj):NamedElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy NamedElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_Name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  NamedElementImpl::copy() const
{
	std::shared_ptr<NamedElementImpl> element(new NamedElementImpl(*this));
	element->setThisNamedElementPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> NamedElementImpl::eStaticClass() const
{
	return LibraryModel_ecorePackageImpl::eInstance()->getNamedElement_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void NamedElementImpl::setName(std::string _Name)
{
	m_Name = _Name;
} 

std::string NamedElementImpl::getName() const 
{
	return m_Name;
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


std::shared_ptr<NamedElement> NamedElementImpl::getThisNamedElementPtr()
{
	return m_thisNamedElementPtr.lock();
}
void NamedElementImpl::setThisNamedElementPtr(std::weak_ptr<NamedElement> thisNamedElementPtr)
{
	m_thisNamedElementPtr = thisNamedElementPtr;
}
std::shared_ptr<ecore::EObject> NamedElementImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any NamedElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //30
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool NamedElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName() != ""; //30
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool NamedElementImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case LibraryModel_ecorePackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _Name = boost::any_cast<std::string>(newValue);
			setName(_Name); //30
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void NamedElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get LibraryModel_ecoreFactory
	std::shared_ptr<libraryModel_ecore::LibraryModel_ecoreFactory> modelFactory = libraryModel_ecore::LibraryModel_ecoreFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void NamedElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("Name");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setName(value);
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

void NamedElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<libraryModel_ecore::LibraryModel_ecoreFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void NamedElementImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void NamedElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void NamedElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<libraryModel_ecore::LibraryModel_ecorePackage> package = libraryModel_ecore::LibraryModel_ecorePackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getNamedElement_EAttribute_name()) )
		{
			saveHandler->addAttribute("Name", this->getName());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

