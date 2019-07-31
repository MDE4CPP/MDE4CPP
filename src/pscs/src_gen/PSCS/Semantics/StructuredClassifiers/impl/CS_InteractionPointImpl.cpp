#include "PSCS/Semantics/StructuredClassifiers/impl/CS_InteractionPointImpl.hpp"

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

#include "abstractDataTypes/Any.hpp"
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

#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "uml/Operation.hpp"

#include "uml/Port.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CS_InteractionPointImpl::CS_InteractionPointImpl()
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

CS_InteractionPointImpl::~CS_InteractionPointImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_InteractionPoint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_InteractionPointImpl::CS_InteractionPointImpl(const CS_InteractionPointImpl & obj):CS_InteractionPointImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_InteractionPoint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_definingPort  = obj.getDefiningPort();

	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_InteractionPointImpl::copy() const
{
	std::shared_ptr<CS_InteractionPointImpl> element(new CS_InteractionPointImpl(*this));
	element->setThisCS_InteractionPointPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_InteractionPointImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_InteractionPoint_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool CS_InteractionPointImpl::checkAllParents(std::shared_ptr<uml::Classifier>  type,std::shared_ptr<uml::Classifier>  classifier)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any CS_InteractionPointImpl::dispatch(std::shared_ptr<uml::Operation>  operation)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void CS_InteractionPointImpl::send(Any eventOccurrence)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void CS_InteractionPointImpl::startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<Any> >  inputs)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Port > CS_InteractionPointImpl::getDefiningPort() const
{
//assert(m_definingPort);
    return m_definingPort;
}
void CS_InteractionPointImpl::setDefiningPort(std::shared_ptr<uml::Port> _definingPort)
{
    m_definingPort = _definingPort;
}

std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference > CS_InteractionPointImpl::getOwner() const
{
//assert(m_owner);
    return m_owner;
}
void CS_InteractionPointImpl::setOwner(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> _owner)
{
    m_owner = _owner;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<CS_InteractionPoint> CS_InteractionPointImpl::getThisCS_InteractionPointPtr() const
{
	return m_thisCS_InteractionPointPtr.lock();
}
void CS_InteractionPointImpl::setThisCS_InteractionPointPtr(std::weak_ptr<CS_InteractionPoint> thisCS_InteractionPointPtr)
{
	m_thisCS_InteractionPointPtr = thisCS_InteractionPointPtr;
}
std::shared_ptr<ecore::EObject> CS_InteractionPointImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_InteractionPointImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_INTERACTIONPOINT_ATTRIBUTE_DEFININGPORT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getDefiningPort())); //171
		case PSCS::PSCSPackage::CS_INTERACTIONPOINT_ATTRIBUTE_OWNER:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getOwner())); //170
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool CS_InteractionPointImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_INTERACTIONPOINT_ATTRIBUTE_DEFININGPORT:
			return getDefiningPort() != nullptr; //171
		case PSCS::PSCSPackage::CS_INTERACTIONPOINT_ATTRIBUTE_OWNER:
			return getOwner() != nullptr; //170
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool CS_InteractionPointImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_INTERACTIONPOINT_ATTRIBUTE_DEFININGPORT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Port> _definingPort = std::dynamic_pointer_cast<uml::Port>(_temp);
			setDefiningPort(_definingPort); //171
			return true;
		}
		case PSCS::PSCSPackage::CS_INTERACTIONPOINT_ATTRIBUTE_OWNER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> _owner = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(_temp);
			setOwner(_owner); //170
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_InteractionPointImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_InteractionPointImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("definingPort");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("definingPort")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("owner");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("owner")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void CS_InteractionPointImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void CS_InteractionPointImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_INTERACTIONPOINT_ATTRIBUTE_DEFININGPORT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Port> _definingPort = std::dynamic_pointer_cast<uml::Port>( references.front() );
				setDefiningPort(_definingPort);
			}
			
			return;
		}

		case PSCS::PSCSPackage::CS_INTERACTIONPOINT_ATTRIBUTE_OWNER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> _owner = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>( references.front() );
				setOwner(_owner);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void CS_InteractionPointImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_InteractionPointImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::PSCSPackage> package = PSCS::PSCSPackage::eInstance();

	

		// Add references
		saveHandler->addReference("definingPort", this->getDefiningPort());
		saveHandler->addReference("owner", this->getOwner());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

