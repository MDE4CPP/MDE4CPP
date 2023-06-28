
#include "fUML/MDE4CPP_Extensions/impl/FUML_SignalInstanceImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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

#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "ecore/EAnnotation.hpp"
#include "uml/Element.hpp"
#include "uml/Signal.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::MDE4CPP_Extensions;

//*********************************
// Constructor / Destructor
//*********************************
FUML_SignalInstanceImpl::FUML_SignalInstanceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

FUML_SignalInstanceImpl::~FUML_SignalInstanceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FUML_SignalInstance "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


FUML_SignalInstanceImpl::FUML_SignalInstanceImpl(const FUML_SignalInstanceImpl & obj): FUML_SignalInstanceImpl()
{
	*this = obj;
}

FUML_SignalInstanceImpl& FUML_SignalInstanceImpl::operator=(const FUML_SignalInstanceImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::ElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of FUML_SignalInstance 
	 * which is generated by the compiler (as FUML_SignalInstance is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//FUML_SignalInstance::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FUML_SignalInstance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> FUML_SignalInstanceImpl::copy() const
{
	std::shared_ptr<FUML_SignalInstanceImpl> element(new FUML_SignalInstanceImpl());
	*element =(*this);
	element->setThisFUML_SignalInstancePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
const std::shared_ptr<uml::Signal>& FUML_SignalInstanceImpl::getType() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	static const std::shared_ptr<uml::Signal> nullPointer = nullptr;

return nullPointer;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> FUML_SignalInstanceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void FUML_SignalInstanceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void FUML_SignalInstanceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	uml::ElementImpl::loadAttributes(loadHandler, attr_list);
}

void FUML_SignalInstanceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	uml::ElementImpl::loadNode(nodeName, loadHandler);
}

void FUML_SignalInstanceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	uml::ElementImpl::resolveReferences(featureID, references);
}

void FUML_SignalInstanceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	uml::ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void FUML_SignalInstanceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage> package = fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> FUML_SignalInstanceImpl::eStaticClass() const
{
	return fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_SignalInstance_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> FUML_SignalInstanceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return uml::ElementImpl::eGet(featureID, resolve, coreType);
}

bool FUML_SignalInstanceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return uml::ElementImpl::internalEIsSet(featureID);
}

bool FUML_SignalInstanceImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return uml::ElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> FUML_SignalInstanceImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::MDE4CPP_Extensions::FUML_SignalInstance::getType() : uml::Signal {const}: 486596182
		case MDE4CPP_ExtensionsPackage::FUML_SIGNALINSTANCE_OPERATION_GETTYPE:
		{
			result = eEcoreAny(this->getType(), uml::umlPackage::SIGNAL_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = uml::ElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> FUML_SignalInstanceImpl::getThisFUML_SignalInstancePtr() const
{
	return m_thisFUML_SignalInstancePtr.lock();
}
void FUML_SignalInstanceImpl::setThisFUML_SignalInstancePtr(std::weak_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> thisFUML_SignalInstancePtr)
{
	m_thisFUML_SignalInstancePtr = thisFUML_SignalInstancePtr;
	setThisElementPtr(thisFUML_SignalInstancePtr);
}


