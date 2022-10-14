
#include "uml/impl/UnmarshallActionImpl.hpp"
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
#include "abstractDataTypes/SubsetUnion.hpp"


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
#include "uml/umlFactory.hpp"
#include "uml/Action.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
UnmarshallActionImpl::UnmarshallActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

UnmarshallActionImpl::~UnmarshallActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UnmarshallAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
UnmarshallActionImpl::UnmarshallActionImpl(std::weak_ptr<uml::Activity> par_activity)
:UnmarshallActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
UnmarshallActionImpl::UnmarshallActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:UnmarshallActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
UnmarshallActionImpl::UnmarshallActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:UnmarshallActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
UnmarshallActionImpl::UnmarshallActionImpl(std::weak_ptr<uml::Element> par_owner)
:UnmarshallActionImpl()
{
	m_owner = par_owner;
}

UnmarshallActionImpl::UnmarshallActionImpl(const UnmarshallActionImpl & obj): UnmarshallActionImpl()
{
	*this = obj;
}

UnmarshallActionImpl& UnmarshallActionImpl::operator=(const UnmarshallActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of UnmarshallAction 
	 * which is generated by the compiler (as UnmarshallAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//UnmarshallAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UnmarshallAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_unmarshallType  = obj.getUnmarshallType();
	//Clone references with containment (deep copy)
	//clone reference 'object'
	if(obj.getObject()!=nullptr)
	{
		m_object = std::dynamic_pointer_cast<uml::InputPin>(obj.getObject()->copy());
	}

	//clone reference 'result'
	std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> resultList = obj.getResult();
	if(resultList)
	{
		/*Subset*/
		m_result.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getResult()->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::OutputPin> resultindexElem: *resultList) 
		{
			std::shared_ptr<uml::OutputPin> temp = std::dynamic_pointer_cast<uml::OutputPin>((resultindexElem)->copy());
			m_result->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for result.")
	}
	
	/*Subset*/
	getResult()->initSubset(getOutput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> UnmarshallActionImpl::copy() const
{
	std::shared_ptr<UnmarshallActionImpl> element(new UnmarshallActionImpl());
	*element =(*this);
	element->setThisUnmarshallActionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool UnmarshallActionImpl::multiplicity_of_object(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool UnmarshallActionImpl::number_of_result(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool UnmarshallActionImpl::object_type(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool UnmarshallActionImpl::structural_feature(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool UnmarshallActionImpl::type_ordering_and_multiplicity(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference object */
std::shared_ptr<uml::InputPin> UnmarshallActionImpl::getObject() const
{
    return m_object;
}
void UnmarshallActionImpl::setObject(std::shared_ptr<uml::InputPin> _object)
{
    m_object = _object;
	
}

/* Getter & Setter for reference result */
std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> UnmarshallActionImpl::getResult() const
{
	if(m_result == nullptr)
	{
		/*Subset*/
		m_result.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getResult()->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
	}
    return m_result;
}

/* Getter & Setter for reference unmarshallType */
std::shared_ptr<uml::Classifier> UnmarshallActionImpl::getUnmarshallType() const
{
    return m_unmarshallType;
}
void UnmarshallActionImpl::setUnmarshallType(std::shared_ptr<uml::Classifier> _unmarshallType)
{
    m_unmarshallType = _unmarshallType;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> UnmarshallActionImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void UnmarshallActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void UnmarshallActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("unmarshallType");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("unmarshallType")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActionImpl::loadAttributes(loadHandler, attr_list);
}

void UnmarshallActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("object") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getObject()); 

			return; 
		}

		if ( nodeName.compare("result") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			loadHandler->handleChildContainer<uml::OutputPin>(this->getResult());  

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
	ActionImpl::loadNode(nodeName, loadHandler);
}

void UnmarshallActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_UNMARSHALLTYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _unmarshallType = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setUnmarshallType(_unmarshallType);
			}
			
			return;
		}
	}
	ActionImpl::resolveReferences(featureID, references);
}

void UnmarshallActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void UnmarshallActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'object'
		std::shared_ptr<uml::InputPin> object = this->getObject();
		if (object != nullptr)
		{
			saveHandler->addReference(object, "object", object->eClass() != package->getInputPin_Class());
		}

		// Save 'result'
		for (std::shared_ptr<uml::OutputPin> result : *this->getResult()) 
		{
			saveHandler->addReference(result, "result", result->eClass() != package->getOutputPin_Class());
		}
	// Add references
		saveHandler->addReference(this->getUnmarshallType(), "unmarshallType", getUnmarshallType()->eClass() != uml::umlPackage::eInstance()->getClassifier_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> UnmarshallActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getUnmarshallAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> UnmarshallActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_OBJECT:
			return eAny(getObject(),uml::umlPackage::INPUTPIN_CLASS,false); //24627
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_RESULT:
			return eEcoreContainerAny(getResult(),uml::umlPackage::OUTPUTPIN_CLASS); //24628
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_UNMARSHALLTYPE:
			return eAny(getUnmarshallType(),uml::umlPackage::CLASSIFIER_CLASS,false); //24629
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}

bool UnmarshallActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_OBJECT:
			return getObject() != nullptr; //24627
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //24628
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_UNMARSHALLTYPE:
			return getUnmarshallType() != nullptr; //24629
	}
	return ActionImpl::internalEIsSet(featureID);
}

bool UnmarshallActionImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_OBJECT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::InputPin> _object = std::dynamic_pointer_cast<uml::InputPin>(eObject);
					if(_object)
					{
						setObject(_object); //24627
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'object'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'object'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_RESULT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::OutputPin>> _result = getResult();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::OutputPin> valueToAdd = std::dynamic_pointer_cast<uml::OutputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(_result->find(valueToAdd) == -1)
								{
									_result->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'result'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'result'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_UNMARSHALLTYPE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Classifier> _unmarshallType = std::dynamic_pointer_cast<uml::Classifier>(eObject);
					if(_unmarshallType)
					{
						setUnmarshallType(_unmarshallType); //24629
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'unmarshallType'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'unmarshallType'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> UnmarshallActionImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::UnmarshallAction::multiplicity_of_object(Any, std::map) : bool: 3775595378
		case umlPackage::UNMARSHALLACTION_OPERATION_MULTIPLICITY_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'multiplicity_of_object'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'multiplicity_of_object'!")
				return nullptr;
			}
		
			result = eAny(this->multiplicity_of_object(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::UnmarshallAction::number_of_result(Any, std::map) : bool: 2179134906
		case umlPackage::UNMARSHALLACTION_OPERATION_NUMBER_OF_RESULT_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'number_of_result'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'number_of_result'!")
				return nullptr;
			}
		
			result = eAny(this->number_of_result(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::UnmarshallAction::object_type(Any, std::map) : bool: 4019536035
		case umlPackage::UNMARSHALLACTION_OPERATION_OBJECT_TYPE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'object_type'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'object_type'!")
				return nullptr;
			}
		
			result = eAny(this->object_type(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::UnmarshallAction::structural_feature(Any, std::map) : bool: 1053679643
		case umlPackage::UNMARSHALLACTION_OPERATION_STRUCTURAL_FEATURE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'structural_feature'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'structural_feature'!")
				return nullptr;
			}
		
			result = eAny(this->structural_feature(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::UnmarshallAction::type_ordering_and_multiplicity(Any, std::map) : bool: 1424955868
		case umlPackage::UNMARSHALLACTION_OPERATION_TYPE_ORDERING_AND_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'type_ordering_and_multiplicity'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'type_ordering_and_multiplicity'!")
				return nullptr;
			}
		
			result = eAny(this->type_ordering_and_multiplicity(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = ActionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::UnmarshallAction> UnmarshallActionImpl::getThisUnmarshallActionPtr() const
{
	return m_thisUnmarshallActionPtr.lock();
}
void UnmarshallActionImpl::setThisUnmarshallActionPtr(std::weak_ptr<uml::UnmarshallAction> thisUnmarshallActionPtr)
{
	m_thisUnmarshallActionPtr = thisUnmarshallActionPtr;
	setThisActionPtr(thisUnmarshallActionPtr);
}


