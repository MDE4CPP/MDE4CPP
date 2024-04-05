
#include "PSCS/MDE4CPP_Extensions/impl/PSCS_ObjectImpl.hpp"
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
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "uml/Comment.hpp"
#include "ecore/EAnnotation.hpp"
#include "uml/Element.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Link.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "uml/Port.hpp"
//Factories and Package includes
#include "PSCS/PSCSPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSCS/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::MDE4CPP_Extensions;

//*********************************
// Constructor / Destructor
//*********************************
PSCS_ObjectImpl::PSCS_ObjectImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PSCS_ObjectImpl::~PSCS_ObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PSCS_Object "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


PSCS_ObjectImpl::PSCS_ObjectImpl(const PSCS_ObjectImpl & obj): PSCS_ObjectImpl()
{
	*this = obj;
}

PSCS_ObjectImpl& PSCS_ObjectImpl::operator=(const PSCS_ObjectImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PSCS_Object 
	 * which is generated by the compiler (as PSCS_Object is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PSCS_Object::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PSCS_Object "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_definingPort  = obj.getDefiningPort();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PSCS_ObjectImpl::copy() const
{
	std::shared_ptr<PSCS_ObjectImpl> element(new PSCS_ObjectImpl());
	*element =(*this);
	element->setThisPSCS_ObjectPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool PSCS_ObjectImpl::isInteractionPoint()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (this->getDefiningPort() != nullptr);
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference definingPort */
const std::shared_ptr<uml::Port>& PSCS_ObjectImpl::getDefiningPort() const
{
    return m_definingPort;
}
void PSCS_ObjectImpl::setDefiningPort(const std::shared_ptr<uml::Port>& _definingPort)
{
    m_definingPort = _definingPort;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PSCS_ObjectImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void PSCS_ObjectImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void PSCS_ObjectImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::loadAttributes(loadHandler, attr_list);
}

void PSCS_ObjectImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::loadNode(nodeName, loadHandler);
}

void PSCS_ObjectImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::PSCS_OBJECT_ATTRIBUTE_DEFININGPORT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Port> _definingPort = std::dynamic_pointer_cast<uml::Port>( references.front() );
				setDefiningPort(_definingPort);
			}
			
			return;
		}
	}
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::resolveReferences(featureID, references);
}

void PSCS_ObjectImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::saveContent(saveHandler);
	
	uml::ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PSCS_ObjectImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage> package = PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getPSCS_Object_Attribute_definingPort()) )
	{
		saveHandler->addReference(this->getDefiningPort(), "definingPort", getDefiningPort()->eClass() != uml::umlPackage::eInstance()->getPort_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& PSCS_ObjectImpl::eStaticClass() const
{
	return PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSCS_Object_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PSCS_ObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::PSCS_OBJECT_ATTRIBUTE_DEFININGPORT:
			return eAny(getDefiningPort(),uml::umlPackage::PORT_CLASS,false); //317
	}
	return fUML::MDE4CPP_Extensions::FUML_ObjectImpl::eGet(featureID, resolve, coreType);
}

bool PSCS_ObjectImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::PSCS_OBJECT_ATTRIBUTE_DEFININGPORT:
			return getDefiningPort() != nullptr; //317
	}
	return fUML::MDE4CPP_Extensions::FUML_ObjectImpl::internalEIsSet(featureID);
}

bool PSCS_ObjectImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::PSCS_OBJECT_ATTRIBUTE_DEFININGPORT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Port> _definingPort = std::dynamic_pointer_cast<uml::Port>(eObject);
					if(_definingPort)
					{
						setDefiningPort(_definingPort); //317
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'definingPort'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'definingPort'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return fUML::MDE4CPP_Extensions::FUML_ObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> PSCS_ObjectImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSCS::MDE4CPP_Extensions::PSCS_Object::isInteractionPoint() : bool: 4059681913
		case MDE4CPP_ExtensionsPackage::PSCS_OBJECT_OPERATION_ISINTERACTIONPOINT:
		{
			result = eAny(this->isInteractionPoint(), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::MDE4CPP_Extensions::FUML_ObjectImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> PSCS_ObjectImpl::getThisPSCS_ObjectPtr() const
{
	return m_thisPSCS_ObjectPtr.lock();
}
void PSCS_ObjectImpl::setThisPSCS_ObjectPtr(std::weak_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> thisPSCS_ObjectPtr)
{
	m_thisPSCS_ObjectPtr = thisPSCS_ObjectPtr;
	setThisFUML_ObjectPtr(thisPSCS_ObjectPtr);
}


