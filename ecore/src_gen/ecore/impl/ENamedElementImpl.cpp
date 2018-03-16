#include "ecore/impl/ENamedElementImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"
#include <exception> // used in Persistence

#include "ecore/EAnnotation.hpp"

#include "ecore/EModelElement.hpp"

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
ENamedElementImpl::ENamedElementImpl()
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

ENamedElementImpl::~ENamedElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ENamedElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ENamedElementImpl::ENamedElementImpl(const ENamedElementImpl & obj):ENamedElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ENamedElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ENamedElementImpl::copy() const
{
	std::shared_ptr<ENamedElementImpl> element(new ENamedElementImpl(*this));
	element->setThisENamedElementPtr(element);
	return element;
}

std::shared_ptr<EClass> ENamedElementImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getENamedElement_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ENamedElementImpl::setName(std::string _name)
{
	m_name = _name;
} 

std::string ENamedElementImpl::getName() const 
{
	return m_name;
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


std::shared_ptr<ENamedElement> ENamedElementImpl::getThisENamedElementPtr()
{
	return m_thisENamedElementPtr.lock();
}
void ENamedElementImpl::setThisENamedElementPtr(std::weak_ptr<ENamedElement> thisENamedElementPtr)
{
	m_thisENamedElementPtr = thisENamedElementPtr;
	setThisEModelElementPtr(thisENamedElementPtr);
}
std::shared_ptr<ecore::EObject> ENamedElementImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ENamedElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //91
	}
	return EModelElementImpl::internalEIsSet(featureID);
}
bool ENamedElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
			return getName() != ""; //91
	}
	return EModelElementImpl::internalEIsSet(featureID);
}
bool ENamedElementImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //91
			return true;
		}
	}

	return EModelElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ENamedElementImpl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
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

void ENamedElementImpl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("name");
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

	EModelElementImpl::loadAttributes(loadHandler, attr_list);
}

void ENamedElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{


	EModelElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ENamedElementImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	EModelElementImpl::resolveReferences(featureID, references);
}

void ENamedElementImpl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ENamedElementImpl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getENamedElement_EAttribute_name()) )
		{
			saveHandler->addAttribute("name", this->getName());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

