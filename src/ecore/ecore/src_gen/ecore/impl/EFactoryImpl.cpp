#include "ecore/impl/EFactoryImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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

#include "abstractDataTypes/Any.hpp"
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

#include "ecore/EAnnotation.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EDataType.hpp"

#include "ecore/EModelElement.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EPackage.hpp"

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
EFactoryImpl::EFactoryImpl()
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

EFactoryImpl::~EFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




EFactoryImpl::EFactoryImpl(const EFactoryImpl & obj):EFactoryImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EFactory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_ePackage  = obj.getEPackage();


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

std::shared_ptr<ecore::EObject>  EFactoryImpl::copy() const
{
	std::shared_ptr<EFactoryImpl> element(new EFactoryImpl(*this));
	element->setThisEFactoryPtr(element);
	return element;
}

std::shared_ptr<EClass> EFactoryImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEFactory_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::string EFactoryImpl::convertToString(std::shared_ptr<ecore::EDataType>  eDataType,Any instanceValue) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EObject> EFactoryImpl::create(std::shared_ptr<ecore::EClass>  eClass) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any EFactoryImpl::createFromString(std::shared_ptr<ecore::EDataType>  eDataType,std::string literalValue) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<ecore::EPackage > EFactoryImpl::getEPackage() const
{
//assert(m_ePackage);
    return m_ePackage;
}
void EFactoryImpl::setEPackage(std::shared_ptr<ecore::EPackage> _ePackage)
{
    m_ePackage = _ePackage;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<EFactory> EFactoryImpl::getThisEFactoryPtr() const
{
	return m_thisEFactoryPtr.lock();
}
void EFactoryImpl::setThisEFactoryPtr(std::weak_ptr<EFactory> thisEFactoryPtr)
{
	m_thisEFactoryPtr = thisEFactoryPtr;
	setThisEModelElementPtr(thisEFactoryPtr);
}
std::shared_ptr<ecore::EObject> EFactoryImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EFactoryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EFACTORY_EREFERENCE_EPACKAGE:
			return eAny(getEPackage()); //71
	}
	return EModelElementImpl::eGet(featureID, resolve, coreType);
}
bool EFactoryImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::EFACTORY_EREFERENCE_EPACKAGE:
			return getEPackage() != nullptr; //71
	}
	return EModelElementImpl::internalEIsSet(featureID);
}
bool EFactoryImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case EcorePackage::EFACTORY_EREFERENCE_EPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EPackage> _ePackage = newValue->get<std::shared_ptr<ecore::EPackage>>();
			setEPackage(_ePackage); //71
			return true;
		}
	}

	return EModelElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EFactoryImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EFactoryImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("ePackage");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("ePackage")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void EFactoryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{


	EModelElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EFactoryImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case EcorePackage::EFACTORY_EREFERENCE_EPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EPackage> _ePackage = std::dynamic_pointer_cast<ecore::EPackage>( references.front() );
				setEPackage(_ePackage);
			}
			
			return;
		}
	}
	EModelElementImpl::resolveReferences(featureID, references);
}

void EFactoryImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void EFactoryImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	

		// Add references
		saveHandler->addReference("ePackage", this->getEPackage());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

