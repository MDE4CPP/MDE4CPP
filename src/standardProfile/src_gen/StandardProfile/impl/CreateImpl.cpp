#include "StandardProfile/impl/CreateImpl.hpp"

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
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/StandardProfilePackage.hpp"

#include <exception> // used in Persistence

#include "uml/BehavioralFeature.hpp"

#include "uml/Usage.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "StandardProfile/StandardProfilePackage.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
CreateImpl::CreateImpl()
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

CreateImpl::~CreateImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Create "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CreateImpl::CreateImpl(const CreateImpl & obj):CreateImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Create "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_base_BehavioralFeature  = obj.getBase_BehavioralFeature();

	m_base_Usage  = obj.getBase_Usage();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CreateImpl::copy() const
{
	std::shared_ptr<CreateImpl> element(new CreateImpl(*this));
	element->setThisCreatePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CreateImpl::eStaticClass() const
{
	return StandardProfilePackageImpl::eInstance()->getCreate_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::BehavioralFeature > CreateImpl::getBase_BehavioralFeature() const
{
//assert(m_base_BehavioralFeature);
    return m_base_BehavioralFeature;
}
void CreateImpl::setBase_BehavioralFeature(std::shared_ptr<uml::BehavioralFeature> _base_BehavioralFeature)
{
    m_base_BehavioralFeature = _base_BehavioralFeature;
}

std::shared_ptr<uml::Usage > CreateImpl::getBase_Usage() const
{
//assert(m_base_Usage);
    return m_base_Usage;
}
void CreateImpl::setBase_Usage(std::shared_ptr<uml::Usage> _base_Usage)
{
    m_base_Usage = _base_Usage;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<Create> CreateImpl::getThisCreatePtr() const
{
	return m_thisCreatePtr.lock();
}
void CreateImpl::setThisCreatePtr(std::weak_ptr<Create> thisCreatePtr)
{
	m_thisCreatePtr = thisCreatePtr;
}
std::shared_ptr<ecore::EObject> CreateImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CreateImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case StandardProfilePackage::CREATE_ATTRIBUTE_BASE_BEHAVIORALFEATURE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getBase_BehavioralFeature())); //40
		case StandardProfilePackage::CREATE_ATTRIBUTE_BASE_USAGE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getBase_Usage())); //41
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool CreateImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case StandardProfilePackage::CREATE_ATTRIBUTE_BASE_BEHAVIORALFEATURE:
			return getBase_BehavioralFeature() != nullptr; //40
		case StandardProfilePackage::CREATE_ATTRIBUTE_BASE_USAGE:
			return getBase_Usage() != nullptr; //41
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool CreateImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case StandardProfilePackage::CREATE_ATTRIBUTE_BASE_BEHAVIORALFEATURE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::BehavioralFeature> _base_BehavioralFeature = std::dynamic_pointer_cast<uml::BehavioralFeature>(_temp);
			setBase_BehavioralFeature(_base_BehavioralFeature); //40
			return true;
		}
		case StandardProfilePackage::CREATE_ATTRIBUTE_BASE_USAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Usage> _base_Usage = std::dynamic_pointer_cast<uml::Usage>(_temp);
			setBase_Usage(_base_Usage); //41
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CreateImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get StandardProfileFactory
	std::shared_ptr<StandardProfile::StandardProfileFactory> modelFactory = StandardProfile::StandardProfileFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void CreateImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("base_BehavioralFeature");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("base_BehavioralFeature")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("base_Usage");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("base_Usage")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void CreateImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<StandardProfile::StandardProfileFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void CreateImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case StandardProfilePackage::CREATE_ATTRIBUTE_BASE_BEHAVIORALFEATURE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::BehavioralFeature> _base_BehavioralFeature = std::dynamic_pointer_cast<uml::BehavioralFeature>( references.front() );
				setBase_BehavioralFeature(_base_BehavioralFeature);
			}
			
			return;
		}

		case StandardProfilePackage::CREATE_ATTRIBUTE_BASE_USAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Usage> _base_Usage = std::dynamic_pointer_cast<uml::Usage>( references.front() );
				setBase_Usage(_base_Usage);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void CreateImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CreateImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<StandardProfile::StandardProfilePackage> package = StandardProfile::StandardProfilePackage::eInstance();

	

		// Add references
		saveHandler->addReference("base_BehavioralFeature", this->getBase_BehavioralFeature());
		saveHandler->addReference("base_Usage", this->getBase_Usage());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

