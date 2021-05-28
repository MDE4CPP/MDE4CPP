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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include <algorithm>
#include <uml/Parameter.hpp>
#include <uml/ParameterDirectionKind.hpp>
#include <fUML/Semantics/CommonBehavior/ParameterValue.hpp>
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "fUML/FUMLFactory.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/ObjectImpl.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
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

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	Execution::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Execution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_behavior  = obj.getBehavior();
	m_context  = obj.getContext();
	//Clone references with containment (deep copy)
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValuesContainer = getParameterValues();
	if(nullptr != parameterValuesContainer )
	{
		int size = parameterValuesContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _parameterValues=(*parameterValuesContainer)[i];
			if(nullptr != _parameterValues)
			{
				parameterValuesContainer->push_back(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(_parameterValues->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container parameterValues."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr parameterValues."<< std::endl;)
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ExecutionImpl::copy() const
{
	std::shared_ptr<ExecutionImpl> element(new ExecutionImpl());
	*element =(*this);
	element->setThisExecutionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

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

std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> ExecutionImpl::getParameterValue(std::shared_ptr<uml::Parameter> parameter)
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
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExecutionImpl::setParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue)
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
// References
//*********************************
/*
Getter & Setter for reference behavior
*/
std::shared_ptr<uml::Behavior> ExecutionImpl::getBehavior() const
{
	//generated from getterBody annotation
if(!m_behavior)
{
	m_behavior = std::dynamic_pointer_cast<uml::Behavior>(this->getTypes()->front());
}

return m_behavior;
	//end of body
}
void ExecutionImpl::setBehavior(std::shared_ptr<uml::Behavior> _behavior)
{
    m_behavior = _behavior;
}


/*
Getter & Setter for reference context
*/
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> ExecutionImpl::getContext() const
{
//assert(m_context);
    return m_context;
}
void ExecutionImpl::setContext(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> _context)
{
    m_context = _context;
}


/*
Getter & Setter for reference parameterValues
*/
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> ExecutionImpl::getParameterValues() const
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



std::shared_ptr<Execution> ExecutionImpl::getThisExecutionPtr() const
{
	return m_thisExecutionPtr.lock();
}
void ExecutionImpl::setThisExecutionPtr(std::weak_ptr<Execution> thisExecutionPtr)
{
	m_thisExecutionPtr = thisExecutionPtr;
	setThisObjectPtr(thisExecutionPtr);
}
std::shared_ptr<ecore::EObject> ExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_BEHAVIOR:
			return eAny(getBehavior()); //466
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_CONTEXT:
			return eAny(getContext()); //464
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_PARAMETERVALUES:
		{
			return eAny(getParameterValues()); //465			
		}
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
bool ExecutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_BEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setBehavior(_behavior); //466
			return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_CONTEXT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> _context = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>(_temp);
			setContext(_context); //464
			return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_PARAMETERVALUES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValuesList(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				parameterValuesList->add(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::CommonBehavior::ParameterValue>::iterator iterParameterValues = m_parameterValues->begin();
			Bag<fUML::Semantics::CommonBehavior::ParameterValue>::iterator endParameterValues = m_parameterValues->end();
			while (iterParameterValues != endParameterValues)
			{
				if (parameterValuesList->find(*iterParameterValues) == -1)
				{
					m_parameterValues->erase(*iterParameterValues);
				}
				iterParameterValues++;
			}
 
			iterParameterValues = parameterValuesList->begin();
			endParameterValues = parameterValuesList->end();
			while (iterParameterValues != endParameterValues)
			{
				if (m_parameterValues->find(*iterParameterValues) == -1)
				{
					m_parameterValues->add(*iterParameterValues);
				}
				iterParameterValues++;			
			}
			return true;
		}
	}

	return fUML::Semantics::StructuredClassifiers::ObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ExecutionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 4650
		case CommonBehaviorPackage::EXECUTION_OPERATION__COPY:
		{
			result = eAny(this->_copy());
			break;
		}
		
		// 4643
		case CommonBehaviorPackage::EXECUTION_OPERATION_EXECUTE:
		{
			this->execute();
			break;
		}
		
		// 4647
		case CommonBehaviorPackage::EXECUTION_OPERATION_GETOUTPUTPARAMETERVALUES:
		{
			result = eAny(this->getOutputParameterValues());
			break;
		}
		
		// 4646
		case CommonBehaviorPackage::EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER:
		{
			//Retrieve input parameter 'parameter'
			//parameter 0
			std::shared_ptr<uml::Parameter> incoming_param_parameter;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_parameter_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_parameter = (*incoming_param_parameter_arguments_citer)->get()->get<std::shared_ptr<uml::Parameter> >();
			result = eAny(this->getParameterValue(incoming_param_parameter));
			break;
		}
		
		// 4649
		case CommonBehaviorPackage::EXECUTION_OPERATION_NEW_:
		{
			result = eAny(this->new_());
			break;
		}
		
		// 4645
		case CommonBehaviorPackage::EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE:
		{
			//Retrieve input parameter 'parameterValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> incoming_param_parameterValue;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_parameterValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_parameterValue = (*incoming_param_parameterValue_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> >();
			this->setParameterValue(incoming_param_parameterValue);
			break;
		}
		
		// 4644
		case CommonBehaviorPackage::EXECUTION_OPERATION_TERMINATE:
		{
			this->terminate();
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::StructuredClassifiers::ObjectImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
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

