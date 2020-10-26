#include "fUML/Semantics/Actions/impl/AcceptEventActionEventAccepterImpl.hpp"

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

#include "fUML/Semantics/Actions/AcceptEventActionActivation.hpp"

#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"

//Factories an Package includes
#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
AcceptEventActionEventAccepterImpl::AcceptEventActionEventAccepterImpl()
{	
}

AcceptEventActionEventAccepterImpl::~AcceptEventActionEventAccepterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AcceptEventActionEventAccepter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}



AcceptEventActionEventAccepterImpl::AcceptEventActionEventAccepterImpl(const AcceptEventActionEventAccepterImpl & obj):AcceptEventActionEventAccepterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AcceptEventActionEventAccepter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_actionActivation  = obj.getActionActivation();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  AcceptEventActionEventAccepterImpl::copy() const
{
	std::shared_ptr<AcceptEventActionEventAccepterImpl> element(new AcceptEventActionEventAccepterImpl(*this));
	element->setThisAcceptEventActionEventAccepterPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> AcceptEventActionEventAccepterImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getAcceptEventActionEventAccepter_Class();
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
/*
Getter & Setter for reference actionActivation
*/
std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation > AcceptEventActionEventAccepterImpl::getActionActivation() const
{
//assert(m_actionActivation);
    return m_actionActivation;
}

void AcceptEventActionEventAccepterImpl::setActionActivation(std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> _actionActivation)
{
    m_actionActivation = _actionActivation;
}



//*********************************
// Union Getter
//*********************************



std::shared_ptr<AcceptEventActionEventAccepter> AcceptEventActionEventAccepterImpl::getThisAcceptEventActionEventAccepterPtr() const
{
	return m_thisAcceptEventActionEventAccepterPtr.lock();
}
void AcceptEventActionEventAccepterImpl::setThisAcceptEventActionEventAccepterPtr(std::weak_ptr<AcceptEventActionEventAccepter> thisAcceptEventActionEventAccepterPtr)
{
	m_thisAcceptEventActionEventAccepterPtr = thisAcceptEventActionEventAccepterPtr;
	setThisEventAccepterPtr(thisAcceptEventActionEventAccepterPtr);
}
std::shared_ptr<ecore::EObject> AcceptEventActionEventAccepterImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any AcceptEventActionEventAccepterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ATTRIBUTE_ACTIONACTIVATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getActionActivation())); //40
	}
	return fUML::Semantics::CommonBehavior::EventAccepterImpl::eGet(featureID, resolve, coreType);
}
bool AcceptEventActionEventAccepterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ATTRIBUTE_ACTIONACTIVATION:
			return getActionActivation() != nullptr; //40
	}
	return fUML::Semantics::CommonBehavior::EventAccepterImpl::internalEIsSet(featureID);
}
bool AcceptEventActionEventAccepterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ATTRIBUTE_ACTIONACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> _actionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::AcceptEventActionActivation>(_temp);
			setActionActivation(_actionActivation); //40
			return true;
		}
	}

	return fUML::Semantics::CommonBehavior::EventAccepterImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void AcceptEventActionEventAccepterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void AcceptEventActionEventAccepterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("actionActivation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("actionActivation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::CommonBehavior::EventAccepterImpl::loadAttributes(loadHandler, attr_list);
}

void AcceptEventActionEventAccepterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::EventAccepterImpl::loadNode(nodeName, loadHandler);
}

void AcceptEventActionEventAccepterImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ATTRIBUTE_ACTIONACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> _actionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::AcceptEventActionActivation>( references.front() );
				setActionActivation(_actionActivation);
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::EventAccepterImpl::resolveReferences(featureID, references);
}

void AcceptEventActionEventAccepterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::EventAccepterImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void AcceptEventActionEventAccepterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();

	

		// Add references
		saveHandler->addReference("actionActivation", this->getActionActivation());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

