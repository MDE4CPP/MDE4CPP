
#include "PSCS/Semantics/Loci/impl/CS_LocusImpl.hpp"
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

#include "abstractDataTypes/Bag.hpp"


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
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "uml/Class.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Executor.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
//Factories and Package includes
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSCS/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
CS_LocusImpl::CS_LocusImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_LocusImpl::~CS_LocusImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_Locus "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CS_LocusImpl::CS_LocusImpl(const CS_LocusImpl & obj): CS_LocusImpl()
{
	*this = obj;
}

CS_LocusImpl& CS_LocusImpl::operator=(const CS_LocusImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Loci::LocusImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CS_Locus 
	 * which is generated by the compiler (as CS_Locus is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CS_Locus::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_Locus "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_LocusImpl::copy() const
{
	std::shared_ptr<CS_LocusImpl> element(new CS_LocusImpl());
	*element =(*this);
	element->setThisCS_LocusPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> CS_LocusImpl::instantiate(const std::shared_ptr<uml::Class>& type)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Extends fUML semantics by instantiating a CS_Object
	// in the case where type is not a Behavior.
	// Otherwise behaves like in fUML
	/*std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object = nullptr;
	if(std::dynamic_pointer_cast<uml::Behavior>(type) != nullptr) {
		object = fUML::Semantics::Loci::LocusImpl::instantiate(type);
	}
	else  {
		object = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Object();
		object->getTypes()->add(type);
		object->createFeatureValues();
		this->add(object);
	}
	return object;*/

/*
 * This method is implemented in every model-specific locus
 */

return nullptr;
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
std::shared_ptr<ecore::EObject> CS_LocusImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CS_LocusImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_LocusImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Loci::LocusImpl::loadAttributes(loadHandler, attr_list);
}

void CS_LocusImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Loci::LocusImpl::loadNode(nodeName, loadHandler);
}

void CS_LocusImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	fUML::Semantics::Loci::LocusImpl::resolveReferences(featureID, references);
}

void CS_LocusImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::LocusImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CS_LocusImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::Loci::LociPackage> package = PSCS::Semantics::Loci::LociPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& CS_LocusImpl::eStaticClass() const
{
	return PSCS::Semantics::Loci::LociPackage::eInstance()->getCS_Locus_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CS_LocusImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::LocusImpl::eGet(featureID, resolve, coreType);
}

bool CS_LocusImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::LocusImpl::internalEIsSet(featureID);
}

bool CS_LocusImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Loci::LocusImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> CS_LocusImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSCS::Semantics::Loci::CS_Locus::instantiate(uml::Class) : fUML::MDE4CPP_Extensions::FUML_Object: 3440468519
		case LociPackage::CS_LOCUS_OPERATION_INSTANTIATE_CLASS:
		{
			//Retrieve input parameter 'type'
			//parameter 0
			std::shared_ptr<uml::Class> incoming_param_type;
			Bag<Any>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_type_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_type = std::dynamic_pointer_cast<uml::Class>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'type'. Failed to invoke operation 'instantiate'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'type'. Failed to invoke operation 'instantiate'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->instantiate(incoming_param_type), fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::FUML_OBJECT_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Loci::LocusImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSCS::Semantics::Loci::CS_Locus> CS_LocusImpl::getThisCS_LocusPtr() const
{
	return m_thisCS_LocusPtr.lock();
}
void CS_LocusImpl::setThisCS_LocusPtr(std::weak_ptr<PSCS::Semantics::Loci::CS_Locus> thisCS_LocusPtr)
{
	m_thisCS_LocusPtr = thisCS_LocusPtr;
	setThisLocusPtr(thisCS_LocusPtr);
}


