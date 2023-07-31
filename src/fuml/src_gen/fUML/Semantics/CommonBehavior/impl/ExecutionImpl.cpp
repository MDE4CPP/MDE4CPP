
#include "fUML/Semantics/CommonBehavior/impl/ExecutionImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/Bag.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include <algorithm>
#include <uml/Parameter.hpp>
#include <uml/ParameterDirectionKind.hpp>
#include <fUML/Semantics/CommonBehavior/ParameterValue.hpp>
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "fUML/fUMLFactory.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/ObjectImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "uml/Parameter.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionImpl::ExecutionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExecutionImpl::~ExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Execution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ExecutionImpl::ExecutionImpl(const ExecutionImpl & obj): ExecutionImpl()
{
	*this = obj;
}

ExecutionImpl& ExecutionImpl::operator=(const ExecutionImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::StructuredClassifiers::ObjectImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Execution 
	 * which is generated by the compiler (as Execution is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Execution::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Execution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_behavior  = obj.getBehavior();
	m_context  = obj.getContext();
	//Clone references with containment (deep copy)
	//clone reference 'parameterValues'
	const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& parameterValuesList = obj.getParameterValues();
	if(parameterValuesList)
	{
		m_parameterValues.reset(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
		
		
		for(const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>& parameterValuesindexElem: *parameterValuesList) 
		{
			const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>& temp = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>((parameterValuesindexElem)->copy());
			m_parameterValues->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr parameterValues."<< std::endl;)
	}
	
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> ExecutionImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new execution that has the same behavior and parameterValues as this execution.

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> newValue = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(fUML::Semantics::StructuredClassifiers::ObjectImpl::_copy());

newValue->setContext(this->getContext());

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValues = this->getParameterValues();
unsigned int parameterValuesSize = parameterValues->size();

for(unsigned int i = 0; i < parameterValuesSize; i++)
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue = parameterValues->at(i);
	newValue->getParameterValues()->add(parameterValue->_copy());
}

return newValue;
	//end of body
}

void ExecutionImpl::execute()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	//end of body
}



std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > ExecutionImpl::getOutputParameterValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > outputs(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());

	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > outputParameterValueList = this->getParameterValues();
    for (std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue : *outputParameterValueList)
    {
    	std::shared_ptr<uml::Parameter> parameter = parameterValue->getParameter();
        if((parameter->getDirection() == uml::ParameterDirectionKind::INOUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::OUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::RETURN))
        {
            outputs->push_back(parameterValue);
        }
    }

    return outputs;
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> ExecutionImpl::getParameterValue(const std::shared_ptr<uml::Parameter>& parameter)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue = nullptr;

	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > list = this->getParameterValues();
	std::vector<std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>>::iterator it = std::find_if(list->begin(), list->end(), [parameter] (std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> p) { return p->getParameter() == parameter; } );
    if(it!= this->getParameterValues()->end() )
    {
        parameterValue  = *it;
    }
    return parameterValue;
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> ExecutionImpl::new_()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

void ExecutionImpl::setParameterValue(const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>& parameterValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> existingParameterValue = this->getParameterValue(parameterValue->getParameter());

	if (existingParameterValue == nullptr)
	{
		this->getParameterValues()->push_back(parameterValue);
	}
	else
	{
		existingParameterValue->getValues()->clear(); // memory Leak
		auto vec = parameterValue->getValues();
		existingParameterValue->getValues()->insert(existingParameterValue->getValues()->end(),vec->begin(),vec->end());
	}
	//end of body
}

void ExecutionImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference behavior */
const std::shared_ptr<uml::Behavior>& ExecutionImpl::getBehavior() const
{
	//generated from getterBody annotation
if(!m_behavior)
{
	m_behavior = std::dynamic_pointer_cast<uml::Behavior>(this->getTypes()->front());
}

return m_behavior;
	//end of body
}
void ExecutionImpl::setBehavior(const std::shared_ptr<uml::Behavior>& _behavior)
{
    m_behavior = _behavior;
	
}

/* Getter & Setter for reference context */
const std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>& ExecutionImpl::getContext() const
{
    return m_context;
}
void ExecutionImpl::setContext(const std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>& _context)
{
    m_context = _context;
	
}

/* Getter & Setter for reference parameterValues */
const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& ExecutionImpl::getParameterValues() const
{
	if(m_parameterValues == nullptr)
	{
		m_parameterValues.reset(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
		
		
	}
    return m_parameterValues;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ExecutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("behavior");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("behavior")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("context");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("context")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::StructuredClassifiers::ObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("parameterValues") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ParameterValue";
			}
			loadHandler->handleChildContainer<fUML::Semantics::CommonBehavior::ParameterValue>(this->getParameterValues());  

			return; 
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
	//load BasePackage Nodes
	fUML::Semantics::StructuredClassifiers::ObjectImpl::loadNode(nodeName, loadHandler);
}

void ExecutionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_BEHAVIOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setBehavior(_behavior);
			}
			
			return;
		}

		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_CONTEXT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> _context = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>( references.front() );
				setContext(_context);
			}
			
			return;
		}
	}
	fUML::Semantics::StructuredClassifiers::ObjectImpl::resolveReferences(featureID, references);
}

void ExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::StructuredClassifiers::ObjectImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getBehavior(), "behavior", getBehavior()->eClass() != uml::umlPackage::eInstance()->getBehavior_Class()); 
		saveHandler->addReference(this->getContext(), "context", getContext()->eClass() != fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class()); 
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'parameterValues'

		saveHandler->addReferences<fUML::Semantics::CommonBehavior::ParameterValue>("parameterValues", this->getParameterValues());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ExecutionImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_BEHAVIOR:
			return eAny(getBehavior(),uml::umlPackage::BEHAVIOR_CLASS,false); //466
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_CONTEXT:
			return eAny(getContext(),fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_CLASS,false); //464
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_PARAMETERVALUES:
			return eAnyBag(getParameterValues(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS); //465
	}
	return fUML::Semantics::StructuredClassifiers::ObjectImpl::eGet(featureID, resolve, coreType);
}

bool ExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_BEHAVIOR:
			return getBehavior() != nullptr; //466
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_CONTEXT:
			return getContext() != nullptr; //464
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_PARAMETERVALUES:
			return getParameterValues() != nullptr; //465
	}
	return fUML::Semantics::StructuredClassifiers::ObjectImpl::internalEIsSet(featureID);
}

bool ExecutionImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_BEHAVIOR:
		{
			// CAST Any to uml::Behavior
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setBehavior(_behavior); //466
			return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_CONTEXT:
		{
			// CAST Any to fUML::Semantics::StructuredClassifiers::Object
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> _context = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>(_temp);
			setContext(_context); //464
			return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_PARAMETERVALUES:
		{
			// CAST Any to Bag<fUML::Semantics::CommonBehavior::ParameterValue>
			if((newValue->isContainer()) && (fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValuesList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>>();
					std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> _parameterValues=getParameterValues();
					for(const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> indexParameterValues: *_parameterValues)
					{
						if (!(parameterValuesList->includes(indexParameterValues)))
						{
							_parameterValues->erase(indexParameterValues);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> indexParameterValues: *parameterValuesList)
					{
						if (!(_parameterValues->includes(indexParameterValues)))
						{
							_parameterValues->add(indexParameterValues);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
	}

	return fUML::Semantics::StructuredClassifiers::ObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ExecutionImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::CommonBehavior::Execution::_copy() : fUML::Semantics::Values::Value: 101589981
		case CommonBehaviorPackage::EXECUTION_OPERATION__COPY:
		{
			result = eAnyObject(this->_copy(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::Execution::execute(): 2717216448
		case CommonBehaviorPackage::EXECUTION_OPERATION_EXECUTE:
		{
			this->execute();
			break;
		}
		// fUML::Semantics::CommonBehavior::Execution::getOutputParameterValues() : fUML::Semantics::CommonBehavior::ParameterValue[*]: 3117320457
		case CommonBehaviorPackage::EXECUTION_OPERATION_GETOUTPUTPARAMETERVALUES:
		{
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > resultList = this->getOutputParameterValues();
			return eAnyBag(resultList,fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::Execution::getParameterValue(uml::Parameter) : fUML::Semantics::CommonBehavior::ParameterValue: 972104598
		case CommonBehaviorPackage::EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER:
		{
			//Retrieve input parameter 'parameter'
			//parameter 0
			std::shared_ptr<uml::Parameter> incoming_param_parameter;
			std::list<Any>::const_iterator incoming_param_parameter_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_parameter = (*incoming_param_parameter_arguments_citer)->get<std::shared_ptr<uml::Parameter> >();
			result = eAnyObject(this->getParameterValue(incoming_param_parameter), fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::Execution::new_() : fUML::Semantics::Values::Value: 1051110988
		case CommonBehaviorPackage::EXECUTION_OPERATION_NEW_:
		{
			result = eAnyObject(this->new_(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::Execution::setParameterValue(fUML::Semantics::CommonBehavior::ParameterValue): 1714178337
		case CommonBehaviorPackage::EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE:
		{
			//Retrieve input parameter 'parameterValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> incoming_param_parameterValue;
			std::list<Any>::const_iterator incoming_param_parameterValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_parameterValue = (*incoming_param_parameterValue_arguments_citer)->get<std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> >();
			this->setParameterValue(incoming_param_parameterValue);
			break;
		}
		// fUML::Semantics::CommonBehavior::Execution::terminate(): 1246638906
		case CommonBehaviorPackage::EXECUTION_OPERATION_TERMINATE:
		{
			this->terminate();
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::StructuredClassifiers::ObjectImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> ExecutionImpl::getThisExecutionPtr() const
{
	return m_thisExecutionPtr.lock();
}
void ExecutionImpl::setThisExecutionPtr(std::weak_ptr<fUML::Semantics::CommonBehavior::Execution> thisExecutionPtr)
{
	m_thisExecutionPtr = thisExecutionPtr;
	setThisObjectPtr(thisExecutionPtr);
}


