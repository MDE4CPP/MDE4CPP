#include "PSCS/Semantics/Loci/impl/CS_ExecutionFactoryImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/impl/PSCSPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Class.hpp"

#include "uml/Element.hpp"

#include "uml/Package.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
CS_ExecutionFactoryImpl::CS_ExecutionFactoryImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_appliedProfiles.reset(new Bag<uml::Package>());
	
	

	//Init references
	
	
}

CS_ExecutionFactoryImpl::~CS_ExecutionFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_ExecutionFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_ExecutionFactoryImpl::CS_ExecutionFactoryImpl(const CS_ExecutionFactoryImpl & obj):CS_ExecutionFactoryImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_ExecutionFactory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Package>> _appliedProfiles = obj.getAppliedProfiles();
	m_appliedProfiles.reset(new Bag<uml::Package>(*(obj.getAppliedProfiles().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_ExecutionFactoryImpl::copy() const
{
	std::shared_ptr<CS_ExecutionFactoryImpl> element(new CS_ExecutionFactoryImpl(*this));
	element->setThisCS_ExecutionFactoryPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_ExecutionFactoryImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_ExecutionFactory_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
Any CS_ExecutionFactoryImpl::getStereotypeApplication(std::shared_ptr<uml::Class>  stereotype,std::shared_ptr<uml::Element>  element)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Class> CS_ExecutionFactoryImpl::getStereotypeClass(std::string profileName,std::string stereotypeName)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any CS_ExecutionFactoryImpl::instantiateVisitor(std::shared_ptr<uml::Element>  element)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::Package>> CS_ExecutionFactoryImpl::getAppliedProfiles() const
{

    return m_appliedProfiles;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<CS_ExecutionFactory> CS_ExecutionFactoryImpl::getThisCS_ExecutionFactoryPtr() const
{
	return m_thisCS_ExecutionFactoryPtr.lock();
}
void CS_ExecutionFactoryImpl::setThisCS_ExecutionFactoryPtr(std::weak_ptr<CS_ExecutionFactory> thisCS_ExecutionFactoryPtr)
{
	m_thisCS_ExecutionFactoryPtr = thisCS_ExecutionFactoryPtr;
}
std::shared_ptr<ecore::EObject> CS_ExecutionFactoryImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_ExecutionFactoryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Package>::iterator iter = m_appliedProfiles->begin();
			Bag<uml::Package>::iterator end = m_appliedProfiles->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //140
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool CS_ExecutionFactoryImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
			return getAppliedProfiles() != nullptr; //140
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool CS_ExecutionFactoryImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Package>> appliedProfilesList(new Bag<uml::Package>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				appliedProfilesList->add(std::dynamic_pointer_cast<uml::Package>(*iter));
				iter++;
			}
			
			Bag<uml::Package>::iterator iterAppliedProfiles = m_appliedProfiles->begin();
			Bag<uml::Package>::iterator endAppliedProfiles = m_appliedProfiles->end();
			while (iterAppliedProfiles != endAppliedProfiles)
			{
				if (appliedProfilesList->find(*iterAppliedProfiles) == -1)
				{
					m_appliedProfiles->erase(*iterAppliedProfiles);
				}
				iterAppliedProfiles++;
			}

			iterAppliedProfiles = appliedProfilesList->begin();
			endAppliedProfiles = appliedProfilesList->end();
			while (iterAppliedProfiles != endAppliedProfiles)
			{
				if (m_appliedProfiles->find(*iterAppliedProfiles) == -1)
				{
					m_appliedProfiles->add(*iterAppliedProfiles);
				}
				iterAppliedProfiles++;			
			}
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_ExecutionFactoryImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	std::shared_ptr<PSCS::PSCSFactory> modelFactory = PSCS::PSCSFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void CS_ExecutionFactoryImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("appliedProfiles");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("appliedProfiles")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void CS_ExecutionFactoryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void CS_ExecutionFactoryImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
		{
			std::shared_ptr<Bag<uml::Package>> _appliedProfiles = getAppliedProfiles();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Package> _r = std::dynamic_pointer_cast<uml::Package>(ref);
				if (_r != nullptr)
				{
					_appliedProfiles->push_back(_r);
				}				
			}
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void CS_ExecutionFactoryImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_ExecutionFactoryImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::PSCSPackage> package = PSCS::PSCSPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<uml::Package>> appliedProfiles_list = this->getAppliedProfiles();
		for (std::shared_ptr<uml::Package > object : *appliedProfiles_list)
		{ 
			saveHandler->addReferences("appliedProfiles", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

