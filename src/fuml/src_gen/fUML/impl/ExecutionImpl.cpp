#include "fUML/impl/ExecutionImpl.hpp"

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
#include "fUML/impl/FUMLPackageImpl.hpp"
#include <algorithm>
#include <uml/Parameter.hpp>
#include <uml/ParameterDirectionKind.hpp>
#include <fUML/ParameterValue.hpp>
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "fUML/FUMLFactory.hpp"

#include "fUML/impl/ObjectImpl.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Object.hpp"

#include "fUML/ObjectActivation.hpp"

#include "uml/Parameter.hpp"

#include "fUML/ParameterValue.hpp"

#include "fUML/Value.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionImpl::ExecutionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_parameterValues.reset(new Bag<fUML::ParameterValue>());
	
	

	//Init references
	

	
	
}

ExecutionImpl::~ExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Execution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ExecutionImpl::ExecutionImpl(const ExecutionImpl & obj):ExecutionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Execution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_context  = obj.getContext();

	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<uml::Classifier>> _types = obj.getTypes();
	m_types.reset(new Bag<uml::Classifier>(*(obj.getTypes().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(std::dynamic_pointer_cast<fUML::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation = std::dynamic_pointer_cast<fUML::ObjectActivation>(obj.getObjectActivation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_objectActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ParameterValue>> _parameterValuesList = obj.getParameterValues();
	for(std::shared_ptr<fUML::ParameterValue> _parameterValues : *_parameterValuesList)
	{
		this->getParameterValues()->add(std::shared_ptr<fUML::ParameterValue>(std::dynamic_pointer_cast<fUML::ParameterValue>(_parameterValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_parameterValues" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  ExecutionImpl::copy() const
{
	std::shared_ptr<ExecutionImpl> element(new ExecutionImpl(*this));
	element->setThisExecutionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecution_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ExecutionImpl::execute()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	//end of body
}

std::shared_ptr<uml::Behavior> ExecutionImpl::getBehavior()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::dynamic_pointer_cast<uml::Behavior>(this->getTypes()->front());
	//end of body
}

std::shared_ptr<Bag<fUML::ParameterValue> > ExecutionImpl::getOutputParameterValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<ParameterValue> > outputs(new Bag<ParameterValue>());

	std::shared_ptr<Bag<ParameterValue> > outputParameterValueList = this->getParameterValues();
    for (std::shared_ptr<ParameterValue> parameterValue : *outputParameterValueList)
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

std::shared_ptr<fUML::ParameterValue> ExecutionImpl::getParameterValue(std::shared_ptr<uml::Parameter>  parameter)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<ParameterValue> parameterValue = nullptr;

	std::shared_ptr<Bag<fUML::ParameterValue> > list = this->getParameterValues();
	std::vector<std::shared_ptr<fUML::ParameterValue>>::iterator it = std::find_if(list->begin(), list->end(), [parameter] (std::shared_ptr<ParameterValue> p) { return p->getParameter() == parameter; } );
    if(it!= this->getParameterValues()->end() )
    {
        parameterValue  = *it;
    }
    return parameterValue;
	//end of body
}

std::shared_ptr<fUML::Value> ExecutionImpl::new_()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExecutionImpl::setParameterValue(std::shared_ptr<fUML::ParameterValue>  parameterValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<ParameterValue> existingParameterValue = this->getParameterValue(parameterValue->getParameter());

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
std::shared_ptr<fUML::Object > ExecutionImpl::getContext() const
{
//assert(m_context);
    return m_context;
}
void ExecutionImpl::setContext(std::shared_ptr<fUML::Object> _context)
{
    m_context = _context;
}

std::shared_ptr<Bag<fUML::ParameterValue>> ExecutionImpl::getParameterValues() const
{

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
		case FUMLPackage::EXECUTION_ATTRIBUTE_CONTEXT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getContext())); //404
		case FUMLPackage::EXECUTION_ATTRIBUTE_PARAMETERVALUES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::ParameterValue>::iterator iter = m_parameterValues->begin();
			Bag<fUML::ParameterValue>::iterator end = m_parameterValues->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //405
		}
	}
	return ObjectImpl::eGet(featureID, resolve, coreType);
}
bool ExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTION_ATTRIBUTE_CONTEXT:
			return getContext() != nullptr; //404
		case FUMLPackage::EXECUTION_ATTRIBUTE_PARAMETERVALUES:
			return getParameterValues() != nullptr; //405
	}
	return ObjectImpl::internalEIsSet(featureID);
}
bool ExecutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTION_ATTRIBUTE_CONTEXT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Object> _context = std::dynamic_pointer_cast<fUML::Object>(_temp);
			setContext(_context); //404
			return true;
		}
		case FUMLPackage::EXECUTION_ATTRIBUTE_PARAMETERVALUES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::ParameterValue>> parameterValuesList(new Bag<fUML::ParameterValue>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				parameterValuesList->add(std::dynamic_pointer_cast<fUML::ParameterValue>(*iter));
				iter++;
			}
			
			Bag<fUML::ParameterValue>::iterator iterParameterValues = m_parameterValues->begin();
			Bag<fUML::ParameterValue>::iterator endParameterValues = m_parameterValues->end();
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

	return ObjectImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void ExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
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

	ObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
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
			std::shared_ptr<fUML::ParameterValue> parameterValues = std::dynamic_pointer_cast<fUML::ParameterValue>(modelFactory->create(typeName));
			if (parameterValues != nullptr)
			{
				std::shared_ptr<Bag<fUML::ParameterValue>> list_parameterValues = this->getParameterValues();
				list_parameterValues->push_back(parameterValues);
				loadHandler->handleChild(parameterValues);
			}
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

	ObjectImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExecutionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTION_ATTRIBUTE_CONTEXT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Object> _context = std::dynamic_pointer_cast<fUML::Object>( references.front() );
				setContext(_context);
			}
			
			return;
		}
	}
	ObjectImpl::resolveReferences(featureID, references);
}

void ExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObjectImpl::saveContent(saveHandler);
	
	ExtensionalValueImpl::saveContent(saveHandler);
	
	CompoundValueImpl::saveContent(saveHandler);
	
	StructuredValueImpl::saveContent(saveHandler);
	
	ValueImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void ExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		saveHandler->addReference("context", this->getContext());


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'parameterValues'
		std::shared_ptr<Bag<fUML::ParameterValue>> list_parameterValues = this->getParameterValues();
		for (std::shared_ptr<fUML::ParameterValue> parameterValues : *list_parameterValues) 
		{
			saveHandler->addReference(parameterValues, "parameterValues", parameterValues->eClass() != package->getParameterValue_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

