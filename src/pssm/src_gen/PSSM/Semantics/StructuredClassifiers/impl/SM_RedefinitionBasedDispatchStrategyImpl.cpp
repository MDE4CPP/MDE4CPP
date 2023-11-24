
#include "PSSM/Semantics/StructuredClassifiers/impl/SM_RedefinitionBasedDispatchStrategyImpl.hpp"
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



#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/Behavior.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "uml/Operation.hpp"
//Factories and Package includes
#include "PSSM/PSSMPackage.hpp"
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSSM/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
SM_RedefinitionBasedDispatchStrategyImpl::SM_RedefinitionBasedDispatchStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SM_RedefinitionBasedDispatchStrategyImpl::~SM_RedefinitionBasedDispatchStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SM_RedefinitionBasedDispatchStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


SM_RedefinitionBasedDispatchStrategyImpl::SM_RedefinitionBasedDispatchStrategyImpl(const SM_RedefinitionBasedDispatchStrategyImpl & obj): SM_RedefinitionBasedDispatchStrategyImpl()
{
	*this = obj;
}

SM_RedefinitionBasedDispatchStrategyImpl& SM_RedefinitionBasedDispatchStrategyImpl::operator=(const SM_RedefinitionBasedDispatchStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of SM_RedefinitionBasedDispatchStrategy 
	 * which is generated by the compiler (as SM_RedefinitionBasedDispatchStrategy is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//SM_RedefinitionBasedDispatchStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SM_RedefinitionBasedDispatchStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> SM_RedefinitionBasedDispatchStrategyImpl::copy() const
{
	std::shared_ptr<SM_RedefinitionBasedDispatchStrategyImpl> element(new SM_RedefinitionBasedDispatchStrategyImpl());
	*element =(*this);
	element->setThisSM_RedefinitionBasedDispatchStrategyPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> SM_RedefinitionBasedDispatchStrategyImpl::dispatch(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& object, const std::shared_ptr<uml::Operation>& operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Try to dispatch the operation has specified in fUML. If no method is defined
	// for the dispatched operation then null is returned. In this situation, the
	// dispatching of the operation is computed as being by with using the
	// call event semantics.
	auto method = this->getMethod(object, operation);
	if (method != nullptr)
	{
		auto execution = object->getLocus()->getFactory()->createExecution(method, object);
		return execution;
	}
	else
	{
		/*auto execution = std::make_shared<PSSM::Semantics::CommonBehavior::CallEventExecution>();
		execution->setContext(object);
		execution->setOperation(operation);
		return execution;*/
		return nullptr;
	}

	/*Execution execution = null;
	Behavior method = this.getMethod(object, operation);
	if(method == null){
		execution = new CallEventExecution();
		execution.context = object;
		((CallEventExecution)execution).operation = operation;
	}else{
		execution = object.locus.factory.createExecution(method, object);
	}
	return execution;*/
	//end of body
}

std::shared_ptr<uml::Behavior> SM_RedefinitionBasedDispatchStrategyImpl::getMethod(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& object, const std::shared_ptr<uml::Operation>& operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Behaves as in fUML and PSCS except that if no method is declared
	// for the operation then null is returned.
	/*auto method = std::make_shared<uml::Behavior>();
	for (auto type : *(object->getTypes()))
	{
		for (auto memberOperation : *(type->getAllOperations()))
		{
			if (memberOperation == operation)
			{
				method = memberOperation->getMethod()->operator[](0);
			}
		}
	}
	return method;*/
	return nullptr;

	/*Behavior method = null;
	int i = 1;
	while (method == null & i <= object.types.size()) {
		Class type = object.types.get(i - 1);
		List<NamedElement> members = type.getMembers();
		int j = 1;
		while (method == null & j <= members.size()) {
			NamedElement member = members.get(j - 1);
			if (member instanceof Operation) {
				Operation memberOperation = (Operation) member;
				if (this.operationsMatch(memberOperation, operation)) {
					if(memberOperation.getMethods().size() > 0){
						method = memberOperation.getMethods().get(0);
					}
				}
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return method;*/
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
std::shared_ptr<ecore::EObject> SM_RedefinitionBasedDispatchStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void SM_RedefinitionBasedDispatchStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SM_RedefinitionBasedDispatchStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void SM_RedefinitionBasedDispatchStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void SM_RedefinitionBasedDispatchStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void SM_RedefinitionBasedDispatchStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void SM_RedefinitionBasedDispatchStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = PSSM::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& SM_RedefinitionBasedDispatchStrategyImpl::eStaticClass() const
{
	return PSSM::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getSM_RedefinitionBasedDispatchStrategy_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> SM_RedefinitionBasedDispatchStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool SM_RedefinitionBasedDispatchStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool SM_RedefinitionBasedDispatchStrategyImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> SM_RedefinitionBasedDispatchStrategyImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::StructuredClassifiers::SM_RedefinitionBasedDispatchStrategy::dispatch(fUML::MDE4CPP_Extensions::FUML_Object, uml::Operation) : fUML::Semantics::CommonBehavior::Execution: 1964522576
		case StructuredClassifiersPackage::SM_REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_DISPATCH_FUML_OBJECT_OPERATION:
		{
			//Retrieve input parameter 'object'
			//parameter 0
			std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> incoming_param_object;
			Bag<Any>::const_iterator incoming_param_object_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_object_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_object = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'object'. Failed to invoke operation 'dispatch'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'object'. Failed to invoke operation 'dispatch'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'operation'
			//parameter 1
			std::shared_ptr<uml::Operation> incoming_param_operation;
			Bag<Any>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_operation_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_operation = std::dynamic_pointer_cast<uml::Operation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'operation'. Failed to invoke operation 'dispatch'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'operation'. Failed to invoke operation 'dispatch'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->dispatch(incoming_param_object,incoming_param_operation), fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_CLASS);
			break;
		}
		// PSSM::Semantics::StructuredClassifiers::SM_RedefinitionBasedDispatchStrategy::getMethod(fUML::MDE4CPP_Extensions::FUML_Object, uml::Operation) : uml::Behavior: 1643090071
		case StructuredClassifiersPackage::SM_REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_GETMETHOD_FUML_OBJECT_OPERATION:
		{
			//Retrieve input parameter 'object'
			//parameter 0
			std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> incoming_param_object;
			Bag<Any>::const_iterator incoming_param_object_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_object_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_object = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'object'. Failed to invoke operation 'getMethod'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'object'. Failed to invoke operation 'getMethod'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'operation'
			//parameter 1
			std::shared_ptr<uml::Operation> incoming_param_operation;
			Bag<Any>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_operation_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_operation = std::dynamic_pointer_cast<uml::Operation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'operation'. Failed to invoke operation 'getMethod'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'operation'. Failed to invoke operation 'getMethod'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->getMethod(incoming_param_object,incoming_param_operation), uml::umlPackage::BEHAVIOR_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::StructuredClassifiers::SM_RedefinitionBasedDispatchStrategy> SM_RedefinitionBasedDispatchStrategyImpl::getThisSM_RedefinitionBasedDispatchStrategyPtr() const
{
	return m_thisSM_RedefinitionBasedDispatchStrategyPtr.lock();
}
void SM_RedefinitionBasedDispatchStrategyImpl::setThisSM_RedefinitionBasedDispatchStrategyPtr(std::weak_ptr<PSSM::Semantics::StructuredClassifiers::SM_RedefinitionBasedDispatchStrategy> thisSM_RedefinitionBasedDispatchStrategyPtr)
{
	m_thisSM_RedefinitionBasedDispatchStrategyPtr = thisSM_RedefinitionBasedDispatchStrategyPtr;
}


