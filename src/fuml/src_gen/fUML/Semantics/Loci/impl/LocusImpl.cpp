
#include "fUML/Semantics/Loci/impl/LocusImpl.hpp"
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
#include "uml/Classifier.hpp"
#include "uml/Behavior.hpp"
#include "uml/Class.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/Loci/Executor.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Executor.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
LocusImpl::LocusImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LocusImpl::~LocusImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Locus "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


LocusImpl::LocusImpl(const LocusImpl & obj): LocusImpl()
{
	*this = obj;
}

LocusImpl& LocusImpl::operator=(const LocusImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Locus 
	 * which is generated by the compiler (as Locus is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Locus::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Locus "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'executor'
	if(obj.getExecutor()!=nullptr)
	{
		m_executor = std::dynamic_pointer_cast<fUML::Semantics::Loci::Executor>(obj.getExecutor()->copy());
	}

	//clone reference 'extensionalValues'
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extensionalValuesList = obj.getExtensionalValues();
	if(extensionalValuesList)
	{
		m_extensionalValues.reset(new Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>());
		
		
		for(const std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> extensionalValuesindexElem: *extensionalValuesList) 
		{
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> temp = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::ExtensionalValue>((extensionalValuesindexElem)->copy());
			m_extensionalValues->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr extensionalValues."<< std::endl;)
	}

	//clone reference 'factory'
	if(obj.getFactory()!=nullptr)
	{
		m_factory = std::dynamic_pointer_cast<fUML::Semantics::Loci::ExecutionFactory>(obj.getFactory()->copy());
	}
	
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> LocusImpl::copy() const
{
	std::shared_ptr<LocusImpl> element(new LocusImpl());
	*element =(*this);
	element->setThisLocusPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void LocusImpl::add(const std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue>& value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	value->setLocus(getThisLocusPtr());
	this->getExtensionalValues()->push_back(value);
	//end of body
}

void LocusImpl::assignExecutor(const std::shared_ptr<fUML::Semantics::Loci::Executor>& executor)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->setExecutor(executor);
	this->getExecutor()->setLocus(getThisLocusPtr());
	//end of body
}

void LocusImpl::assignFactory(const std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory>& factory)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->setFactory(factory);
	this->getFactory()->setLocus(getThisLocusPtr());
	//end of body
}

bool LocusImpl::conforms(const std::shared_ptr<uml::Classifier>& type, const std::shared_ptr<uml::Classifier>& classifier)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool doesConform = false;
    if(type == classifier)
    {
        doesConform = true;
    }
    else
    {
        unsigned int i = 0;
        while(!doesConform && (i < type->getGeneral()->size()))
        {
            doesConform = this->conforms(type->getGeneral()->at(i), classifier);
            i = i + 1;
        }
    }
    return doesConform;
	//end of body
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> LocusImpl::instantiate(const std::shared_ptr<uml::Class>& type)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object = nullptr;
	std::shared_ptr<uml::Behavior> behavior = std::dynamic_pointer_cast<uml::Behavior>(type);
    if(behavior != nullptr)
    {
    	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>  context = nullptr;
        object = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>(this->getFactory()->createExecution(behavior, nullptr));
    }
    else
    {
        object = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createObject();
        object->getTypes()->push_back(type);
        object->createFeatureValues();
        this->add(object);
    }
    
    return object;
	//end of body
}

void LocusImpl::remove(const std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue>& value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	value->setLocus(nullptr);
	this->getExtensionalValues()->erase(value);
	value.reset();
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue> > LocusImpl::retrieveExtent(const std::shared_ptr<uml::Classifier>& classifier)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue> > extent(new Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>());
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue> > extensionalValues = this->getExtensionalValues();

	unsigned int extensionalValuesSize = extensionalValues->size();

	for (unsigned int i=0; i < extensionalValuesSize; i++)
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value = extensionalValues->at(i);
		std::shared_ptr<Bag<uml::Classifier> > types = value->getTypes();
		bool conforms = false;
		unsigned int j = 0;
		while(!conforms && j < types->size())
		{
			conforms = this->conforms(types->at(j), classifier);
			j = j + 1;
		}
		if(conforms)
		{
			extent->push_back(value);
		}
	}
	return extent;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference executor */
const std::shared_ptr<fUML::Semantics::Loci::Executor>& LocusImpl::getExecutor() const
{
    return m_executor;
}
void LocusImpl::setExecutor(const std::shared_ptr<fUML::Semantics::Loci::Executor>& _executor)
{
    m_executor = _executor;
	
}

/* Getter & Setter for reference extensionalValues */
const std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>>& LocusImpl::getExtensionalValues() const
{
	if(m_extensionalValues == nullptr)
	{
		m_extensionalValues.reset(new Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>());
		
		
	}
    return m_extensionalValues;
}

/* Getter & Setter for reference factory */
const std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory>& LocusImpl::getFactory() const
{
    return m_factory;
}
void LocusImpl::setFactory(const std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory>& _factory)
{
    m_factory = _factory;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LocusImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void LocusImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LocusImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void LocusImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("executor") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Executor";
			}
			loadHandler->handleChild(this->getExecutor()); 

			return; 
		}

		if ( nodeName.compare("extensionalValues") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<fUML::Semantics::StructuredClassifiers::ExtensionalValue>(this->getExtensionalValues());  

			return; 
		}

		if ( nodeName.compare("factory") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ExecutionFactory";
			}
			loadHandler->handleChild(this->getFactory()); 

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
}

void LocusImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void LocusImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void LocusImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Loci::LociPackage> package = fUML::Semantics::Loci::LociPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'executor'

		saveHandler->addReference(this->getExecutor(), "executor", getExecutor()->eClass() != fUML::Semantics::Loci::LociPackage::eInstance()->getExecutor_Class());

		// Save 'extensionalValues'

		saveHandler->addReferences<fUML::Semantics::StructuredClassifiers::ExtensionalValue>("extensionalValues", this->getExtensionalValues());

		// Save 'factory'

		saveHandler->addReference(this->getFactory(), "factory", getFactory()->eClass() != fUML::Semantics::Loci::LociPackage::eInstance()->getExecutionFactory_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& LocusImpl::eStaticClass() const
{
	return fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any LocusImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXECUTOR:
			return eAny(getExecutor(),fUML::Semantics::Loci::LociPackage::EXECUTOR_CLASS,false); //770
		case fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXTENSIONALVALUES:
			return eAnyBag(getExtensionalValues(),fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::EXTENSIONALVALUE_CLASS); //772
		case fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_FACTORY:
			return eAny(getFactory(),fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_CLASS,false); //771
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool LocusImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXECUTOR:
			return getExecutor() != nullptr; //770
		case fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXTENSIONALVALUES:
			return getExtensionalValues() != nullptr; //772
		case fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_FACTORY:
			return getFactory() != nullptr; //771
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool LocusImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXECUTOR:
		{
			// CAST Any to fUML::Semantics::Loci::Executor
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Loci::Executor> _executor = std::dynamic_pointer_cast<fUML::Semantics::Loci::Executor>(_temp);
			setExecutor(_executor); //770
			return true;
		}
		case fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXTENSIONALVALUES:
		{
			// CAST Any to Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>
			if((newValue->isContainer()) && (fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::EXTENSIONALVALUE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extensionalValuesList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>>>();
					std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> _extensionalValues=getExtensionalValues();
					for(const std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> indexExtensionalValues: *_extensionalValues)
					{
						if (extensionalValuesList->find(indexExtensionalValues) == -1)
						{
							_extensionalValues->erase(indexExtensionalValues);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> indexExtensionalValues: *extensionalValuesList)
					{
						if (_extensionalValues->find(indexExtensionalValues) == -1)
						{
							_extensionalValues->add(indexExtensionalValues);
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
		case fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_FACTORY:
		{
			// CAST Any to fUML::Semantics::Loci::ExecutionFactory
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> _factory = std::dynamic_pointer_cast<fUML::Semantics::Loci::ExecutionFactory>(_temp);
			setFactory(_factory); //771
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any LocusImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Loci::Locus::add(fUML::Semantics::StructuredClassifiers::ExtensionalValue): 2767538417
		case LociPackage::LOCUS_OPERATION_ADD_EXTENSIONALVALUE:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> >();
			this->add(incoming_param_value);
			break;
		}
		// fUML::Semantics::Loci::Locus::assignExecutor(fUML::Semantics::Loci::Executor): 4071294562
		case LociPackage::LOCUS_OPERATION_ASSIGNEXECUTOR_EXECUTOR:
		{
			//Retrieve input parameter 'executor'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Loci::Executor> incoming_param_executor;
			std::list<Any>::const_iterator incoming_param_executor_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_executor = (*incoming_param_executor_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Loci::Executor> >();
			this->assignExecutor(incoming_param_executor);
			break;
		}
		// fUML::Semantics::Loci::Locus::assignFactory(fUML::Semantics::Loci::ExecutionFactory): 2681202388
		case LociPackage::LOCUS_OPERATION_ASSIGNFACTORY_EXECUTIONFACTORY:
		{
			//Retrieve input parameter 'factory'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> incoming_param_factory;
			std::list<Any>::const_iterator incoming_param_factory_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_factory = (*incoming_param_factory_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> >();
			this->assignFactory(incoming_param_factory);
			break;
		}
		// fUML::Semantics::Loci::Locus::conforms(uml::Classifier, uml::Classifier) : bool: 2253046160
		case LociPackage::LOCUS_OPERATION_CONFORMS_CLASSIFIER_CLASSIFIER:
		{
			//Retrieve input parameter 'type'
			//parameter 0
			std::shared_ptr<uml::Classifier> incoming_param_type;
			std::list<Any>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_type = (*incoming_param_type_arguments_citer)->get<std::shared_ptr<uml::Classifier> >();
			//Retrieve input parameter 'classifier'
			//parameter 1
			std::shared_ptr<uml::Classifier> incoming_param_classifier;
			std::list<Any>::const_iterator incoming_param_classifier_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_classifier = (*incoming_param_classifier_arguments_citer)->get<std::shared_ptr<uml::Classifier> >();
			result = eAny(this->conforms(incoming_param_type,incoming_param_classifier),0,false);
			break;
		}
		// fUML::Semantics::Loci::Locus::instantiate(uml::Class) : fUML::Semantics::StructuredClassifiers::Object: 2294841442
		case LociPackage::LOCUS_OPERATION_INSTANTIATE_CLASS:
		{
			//Retrieve input parameter 'type'
			//parameter 0
			std::shared_ptr<uml::Class> incoming_param_type;
			std::list<Any>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_type = (*incoming_param_type_arguments_citer)->get<std::shared_ptr<uml::Class> >();
			result = eAnyObject(this->instantiate(incoming_param_type), fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_CLASS);
			break;
		}
		// fUML::Semantics::Loci::Locus::remove(fUML::Semantics::StructuredClassifiers::ExtensionalValue): 3347304930
		case LociPackage::LOCUS_OPERATION_REMOVE_EXTENSIONALVALUE:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> >();
			this->remove(incoming_param_value);
			break;
		}
		// fUML::Semantics::Loci::Locus::retrieveExtent(uml::Classifier) : fUML::Semantics::StructuredClassifiers::ExtensionalValue[*]: 3026082825
		case LociPackage::LOCUS_OPERATION_RETRIEVEEXTENT_CLASSIFIER:
		{
			//Retrieve input parameter 'classifier'
			//parameter 0
			std::shared_ptr<uml::Classifier> incoming_param_classifier;
			std::list<Any>::const_iterator incoming_param_classifier_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_classifier = (*incoming_param_classifier_arguments_citer)->get<std::shared_ptr<uml::Classifier> >();
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue> > resultList = this->retrieveExtent(incoming_param_classifier);
			return eAnyBag(resultList,fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::EXTENSIONALVALUE_CLASS);
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

std::shared_ptr<fUML::Semantics::Loci::Locus> LocusImpl::getThisLocusPtr() const
{
	return m_thisLocusPtr.lock();
}
void LocusImpl::setThisLocusPtr(std::weak_ptr<fUML::Semantics::Loci::Locus> thisLocusPtr)
{
	m_thisLocusPtr = thisLocusPtr;
}


