
#include "fUML/Semantics/CommonBehavior/impl/ExecutionImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
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

//#include "fUML/Semantics/StructuredClassifiers/impl/ObjectImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "ecore/EAnnotation.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/Parameter.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "ecore/ecorePackage.hpp"
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
	fUML::Semantics::Loci::SemanticVisitorImpl::operator=(obj);
	uml::ElementImpl::operator=(obj);
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
	m_locus  = obj.getLocus();
	m_types  = obj.getTypes();
	//Clone references with containment (deep copy)
	//clone reference 'parameterValues'
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValuesList = obj.getParameterValues();
	if(parameterValuesList)
	{
		m_parameterValues.reset(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
		
		
		for(const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValuesindexElem: *parameterValuesList) 
		{
			std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> temp = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>((parameterValuesindexElem)->copy());
			m_parameterValues->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for parameterValues.")
	}
	
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Any> ExecutionImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new execution that has the same behavior and parameterValues as this execution.

/* Curretly not supported
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
*/

throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));

	//end of body
}

void ExecutionImpl::destroy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    
/* Currently not supported
if(this->getObjectActivation() != nullptr)
	{
		this->getObjectActivation()->stop();
		this->setObjectActivation(nullptr);
	}
*/

	this->getTypes()->clear();
    
	if(this->getLocus() != nullptr)
	{
		this->getLocus()->remove(getThisExecutionPtr());
	}
	//end of body
}

void ExecutionImpl::execute()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	//end of body
}



std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> ExecutionImpl::getOutputParameterValues()
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

std::shared_ptr<Any> ExecutionImpl::new_()
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

/* Getter & Setter for reference context */
std::shared_ptr<uml::Element> ExecutionImpl::getContext() const
{
    return m_context;
}
void ExecutionImpl::setContext(std::shared_ptr<uml::Element> _context)
{
    m_context = _context;
	
}

/* Getter & Setter for reference locus */
std::shared_ptr<fUML::Semantics::Loci::Locus> ExecutionImpl::getLocus() const
{
    return m_locus;
}
void ExecutionImpl::setLocus(std::shared_ptr<fUML::Semantics::Loci::Locus> _locus)
{
    m_locus = _locus;
	
}



/* Getter & Setter for reference parameterValues */
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> ExecutionImpl::getParameterValues() const
{
	if(m_parameterValues == nullptr)
	{
		m_parameterValues.reset(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
		
		
	}
    return m_parameterValues;
}

/* Getter & Setter for reference types */
std::shared_ptr<Bag<uml::Classifier>> ExecutionImpl::getTypes() const
{
	if(m_types == nullptr)
	{
		m_types.reset(new Bag<uml::Classifier>());
		
		
	}
    return m_types;
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

		iter = attr_list.find("locus");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("locus")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("types");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("types")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	uml::ElementImpl::loadAttributes(loadHandler, attr_list);
	fUML::Semantics::Loci::SemanticVisitorImpl::loadAttributes(loadHandler, attr_list);
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
	uml::ElementImpl::loadNode(nodeName, loadHandler);
	fUML::Semantics::Loci::SemanticVisitorImpl::loadNode(nodeName, loadHandler);
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
				std::shared_ptr<uml::Element> _context = std::dynamic_pointer_cast<uml::Element>( references.front() );
				setContext(_context);
			}
			
			return;
		}

		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_LOCUS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>( references.front() );
				setLocus(_locus);
			}
			
			return;
		}

		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_TYPES:
		{
			std::shared_ptr<Bag<uml::Classifier>> _types = getTypes();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_types->push_back(_r);
				}
			}
			return;
		}
	}
	uml::ElementImpl::resolveReferences(featureID, references);
	fUML::Semantics::Loci::SemanticVisitorImpl::resolveReferences(featureID, references);
}

void ExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	uml::ElementImpl::saveContent(saveHandler);
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getBehavior(), "behavior", getBehavior()->eClass() != uml::umlPackage::eInstance()->getBehavior_Class()); 
		saveHandler->addReference(this->getContext(), "context", getContext()->eClass() != uml::umlPackage::eInstance()->getElement_Class()); 
		saveHandler->addReference(this->getLocus(), "locus", getLocus()->eClass() != fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class()); 
		saveHandler->addReferences<uml::Classifier>("types", this->getTypes());
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

std::shared_ptr<ecore::EClass> ExecutionImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_BEHAVIOR:
			return eAny(getBehavior(),uml::umlPackage::BEHAVIOR_CLASS,false); //466
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_CONTEXT:
			return eAny(getContext(),uml::umlPackage::ELEMENT_CLASS,false); //464
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_LOCUS:
			return eAny(getLocus(),fUML::Semantics::Loci::LociPackage::LOCUS_CLASS,false); //467
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_PARAMETERVALUES:
			return eEcoreContainerAny(getParameterValues(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS); //465
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_TYPES:
			return eEcoreContainerAny(getTypes(),uml::umlPackage::CLASSIFIER_CLASS); //468
	}
	std::shared_ptr<Any> result;
	result = uml::ElementImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = fUML::Semantics::Loci::SemanticVisitorImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool ExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_BEHAVIOR:
			return getBehavior() != nullptr; //466
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_CONTEXT:
			return getContext() != nullptr; //464
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_LOCUS:
			return getLocus() != nullptr; //467
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_PARAMETERVALUES:
			return getParameterValues() != nullptr; //465
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_TYPES:
			return getTypes() != nullptr; //468
	}
	bool result = false;
	result = uml::ElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = fUML::Semantics::Loci::SemanticVisitorImpl::internalEIsSet(featureID);
	return result;
}

bool ExecutionImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_BEHAVIOR:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>(eObject);
					if(_behavior)
					{
						setBehavior(_behavior); //466
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'behavior'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'behavior'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_CONTEXT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Element> _context = std::dynamic_pointer_cast<uml::Element>(eObject);
					if(_context)
					{
						setContext(_context); //464
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'context'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'context'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_LOCUS:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(eObject);
					if(_locus)
					{
						setLocus(_locus); //467
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'locus'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'locus'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_PARAMETERVALUES:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> _parameterValues = getParameterValues();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> valueToAdd = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(anEObject);
	
							if (valueToAdd)
							{
								if(_parameterValues->find(valueToAdd) == -1)
								{
									_parameterValues->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'parameterValues'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'parameterValues'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_ATTRIBUTE_TYPES:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Classifier>> _types = getTypes();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Classifier> valueToAdd = std::dynamic_pointer_cast<uml::Classifier>(anEObject);
	
							if (valueToAdd)
							{
								if(_types->find(valueToAdd) == -1)
								{
									_types->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'types'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'types'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = uml::ElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = fUML::Semantics::Loci::SemanticVisitorImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ExecutionImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::CommonBehavior::Execution::_copy() : Any: 4021493409
		case CommonBehaviorPackage::EXECUTION_OPERATION__COPY:
		{
			result = eAny(this->_copy(), 0, false);
			break;
		}
		// fUML::Semantics::CommonBehavior::Execution::destroy(): 2183551203
		case CommonBehaviorPackage::EXECUTION_OPERATION_DESTROY:
		{
			this->destroy();
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
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> resultList = this->getOutputParameterValues();
			return eEcoreContainerAny(resultList,fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::Execution::getParameterValue(uml::Parameter) : fUML::Semantics::CommonBehavior::ParameterValue: 972104598
		case CommonBehaviorPackage::EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER:
		{
			//Retrieve input parameter 'parameter'
			//parameter 0
			std::shared_ptr<uml::Parameter> incoming_param_parameter;
			Bag<Any>::const_iterator incoming_param_parameter_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_parameter_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_parameter = std::dynamic_pointer_cast<uml::Parameter>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'parameter'. Failed to invoke operation 'getParameterValue'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'parameter'. Failed to invoke operation 'getParameterValue'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->getParameterValue(incoming_param_parameter), fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::Execution::new_() : Any: 1530257024
		case CommonBehaviorPackage::EXECUTION_OPERATION_NEW_:
		{
			result = eAny(this->new_(), 0, false);
			break;
		}
		// fUML::Semantics::CommonBehavior::Execution::setParameterValue(fUML::Semantics::CommonBehavior::ParameterValue): 1714178337
		case CommonBehaviorPackage::EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE:
		{
			//Retrieve input parameter 'parameterValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> incoming_param_parameterValue;
			Bag<Any>::const_iterator incoming_param_parameterValue_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_parameterValue_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_parameterValue = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'parameterValue'. Failed to invoke operation 'setParameterValue'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'parameterValue'. Failed to invoke operation 'setParameterValue'!")
					return nullptr;
				}
			}
		
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
			result = uml::ElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = fUML::Semantics::Loci::SemanticVisitorImpl::eInvoke(operationID, arguments);
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
	setThisElementPtr(thisExecutionPtr);
	setThisSemanticVisitorPtr(thisExecutionPtr);
}


