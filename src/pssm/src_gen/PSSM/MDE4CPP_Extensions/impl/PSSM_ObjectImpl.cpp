
#include "PSSM/MDE4CPP_Extensions/impl/PSSM_ObjectImpl.hpp"
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
//Includes from codegen annotation
#include "fUML/FUMLFactory.hpp"
#include "PSSM/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "PSSM/Semantics/CommonBehavior/SM_ObjectActivation.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Comment.hpp"
#include "ecore/EAnnotation.hpp"
#include "uml/Element.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
//Factories and Package includes
#include "PSSM/PSSMPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSSM/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::MDE4CPP_Extensions;

//*********************************
// Constructor / Destructor
//*********************************
PSSM_ObjectImpl::PSSM_ObjectImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PSSM_ObjectImpl::~PSSM_ObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PSSM_Object "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


PSSM_ObjectImpl::PSSM_ObjectImpl(const PSSM_ObjectImpl & obj): PSSM_ObjectImpl()
{
	*this = obj;
}

PSSM_ObjectImpl& PSSM_ObjectImpl::operator=(const PSSM_ObjectImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PSSM_Object 
	 * which is generated by the compiler (as PSSM_Object is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PSSM_Object::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PSSM_Object "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
void PSSM_ObjectImpl::destroy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// In addition to realize the normal process of stopping the object activation
// as well as removing the current object from the locus, this destruction phase
// also implies removal of all events remaining in the pool. This prevents the
// dispatch loop to actually get the next event (even if at this step there is no
// chance to match an accepter) whereas the current object is not anymore registered.
// in the Locus.
if(this->getObjectActivation() != nullptr)
    {
    	this->getObjectActivation()->stop();
    	this->getObjectActivation()->getEventPool()->clear();
    	this->setObjectActivation(nullptr);
    }

    this->getTypes()->clear();
    //ExtensionalValueImpl::destroy();
	//end of body
}

void PSSM_ObjectImpl::startBehavior(const std::shared_ptr<uml::Class>& classifier, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// This Operation is identical to FUML_Object::startBehavior() with the exception that 
	// here, a SM_ObjectActivation is created and initialized instead of an ObjectActivation.
	// This specialized kind of ObjectActivation allows the registering of CompletionEventOccurrences.
	if(this->getObjectActivation() == nullptr)
	{
		this->setObjectActivation(std::dynamic_pointer_cast<PSSM::Semantics::CommonBehavior::SM_ObjectActivation>(PSSM::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createSM_ObjectActivation()));
		this->getObjectActivation()->setObject(this->getThisFUML_ObjectPtr());
	}
	this->getObjectActivation()->startBehavior(classifier, inputs);
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
std::shared_ptr<ecore::EObject> PSSM_ObjectImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void PSSM_ObjectImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSSMFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void PSSM_ObjectImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::loadAttributes(loadHandler, attr_list);
}

void PSSM_ObjectImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::loadNode(nodeName, loadHandler);
}

void PSSM_ObjectImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::resolveReferences(featureID, references);
}

void PSSM_ObjectImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::saveContent(saveHandler);
	
	uml::ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PSSM_ObjectImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage> package = PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& PSSM_ObjectImpl::eStaticClass() const
{
	return PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSSM_Object_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PSSM_ObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::MDE4CPP_Extensions::FUML_ObjectImpl::eGet(featureID, resolve, coreType);
}

bool PSSM_ObjectImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::MDE4CPP_Extensions::FUML_ObjectImpl::internalEIsSet(featureID);
}

bool PSSM_ObjectImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return fUML::MDE4CPP_Extensions::FUML_ObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> PSSM_ObjectImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::MDE4CPP_Extensions::PSSM_Object::destroy(): 959255311
		case MDE4CPP_ExtensionsPackage::PSSM_OBJECT_OPERATION_DESTROY:
		{
			this->destroy();
			break;
		}
		// PSSM::MDE4CPP_Extensions::PSSM_Object::startBehavior(uml::Class, fUML::Semantics::CommonBehavior::ParameterValue[*]): 1856772191
		case MDE4CPP_ExtensionsPackage::PSSM_OBJECT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE:
		{
			//Retrieve input parameter 'classifier'
			//parameter 0
			std::shared_ptr<uml::Class> incoming_param_classifier;
			Bag<Any>::const_iterator incoming_param_classifier_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_classifier_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_classifier = std::dynamic_pointer_cast<uml::Class>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'classifier'. Failed to invoke operation 'startBehavior'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'classifier'. Failed to invoke operation 'startBehavior'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'inputs'
			//parameter 1
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> incoming_param_inputs;
			Bag<Any>::const_iterator incoming_param_inputs_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_inputs_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_inputs.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> _temp = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(anEObject);
								incoming_param_inputs->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'inputs'. Failed to invoke operation 'startBehavior'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'inputs'. Failed to invoke operation 'startBehavior'!")
					return nullptr;
				}
			}
		
			this->startBehavior(incoming_param_classifier,incoming_param_inputs);
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

std::shared_ptr<PSSM::MDE4CPP_Extensions::PSSM_Object> PSSM_ObjectImpl::getThisPSSM_ObjectPtr() const
{
	return m_thisPSSM_ObjectPtr.lock();
}
void PSSM_ObjectImpl::setThisPSSM_ObjectPtr(std::weak_ptr<PSSM::MDE4CPP_Extensions::PSSM_Object> thisPSSM_ObjectPtr)
{
	m_thisPSSM_ObjectPtr = thisPSSM_ObjectPtr;
	setThisFUML_ObjectPtr(thisPSSM_ObjectPtr);
}

