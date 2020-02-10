#include "StandardProfile/impl/ResponsibilityImpl.hpp"

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
ResponsibilityImpl::ResponsibilityImpl()
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

ResponsibilityImpl::~ResponsibilityImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Responsibility "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ResponsibilityImpl::ResponsibilityImpl(const ResponsibilityImpl & obj):ResponsibilityImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Responsibility "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_base_Usage  = obj.getBase_Usage();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ResponsibilityImpl::copy() const
{
	std::shared_ptr<ResponsibilityImpl> element(new ResponsibilityImpl(*this));
	element->setThisResponsibilityPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ResponsibilityImpl::eStaticClass() const
{
	return StandardProfilePackageImpl::eInstance()->getResponsibility_Class();
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
std::shared_ptr<uml::Usage > ResponsibilityImpl::getBase_Usage() const
{
//assert(m_base_Usage);
    return m_base_Usage;
}
void ResponsibilityImpl::setBase_Usage(std::shared_ptr<uml::Usage> _base_Usage)
{
    m_base_Usage = _base_Usage;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<Responsibility> ResponsibilityImpl::getThisResponsibilityPtr() const
{
	return m_thisResponsibilityPtr.lock();
}
void ResponsibilityImpl::setThisResponsibilityPtr(std::weak_ptr<Responsibility> thisResponsibilityPtr)
{
	m_thisResponsibilityPtr = thisResponsibilityPtr;
}
std::shared_ptr<ecore::EObject> ResponsibilityImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ResponsibilityImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case StandardProfilePackage::RESPONSIBILITY_ATTRIBUTE_BASE_USAGE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getBase_Usage())); //230
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ResponsibilityImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case StandardProfilePackage::RESPONSIBILITY_ATTRIBUTE_BASE_USAGE:
			return getBase_Usage() != nullptr; //230
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ResponsibilityImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case StandardProfilePackage::RESPONSIBILITY_ATTRIBUTE_BASE_USAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Usage> _base_Usage = std::dynamic_pointer_cast<uml::Usage>(_temp);
			setBase_Usage(_base_Usage); //230
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ResponsibilityImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ResponsibilityImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
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

void ResponsibilityImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<StandardProfile::StandardProfileFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void ResponsibilityImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case StandardProfilePackage::RESPONSIBILITY_ATTRIBUTE_BASE_USAGE:
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

void ResponsibilityImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ResponsibilityImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<StandardProfile::StandardProfilePackage> package = StandardProfile::StandardProfilePackage::eInstance();

	

		// Add references
		saveHandler->addReference("base_Usage", this->getBase_Usage());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

