#include "fUML/impl/LocusImpl.hpp"

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
#include "uml/Classifier.hpp"
#include "uml/Behavior.hpp"
#include "uml/Class.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/ExecutionFactory.hpp"
#include "fUML/ExtensionalValue.hpp"
#include "fUML/Executor.hpp"
#include "fUML/Object.hpp"
#include "fUML/Execution.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "fUML/ExecutionFactory.hpp"

#include "fUML/Executor.hpp"

#include "fUML/ExtensionalValue.hpp"

#include "fUML/Object.hpp"

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
LocusImpl::LocusImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_extensionalValues.reset(new Bag<fUML::ExtensionalValue>());
	
	

	

	//Init references
	

	
	

	
}

LocusImpl::~LocusImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Locus "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




LocusImpl::LocusImpl(const LocusImpl & obj):LocusImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Locus "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	if(obj.getExecutor()!=nullptr)
	{
		m_executor = std::dynamic_pointer_cast<fUML::Executor>(obj.getExecutor()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_executor" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ExtensionalValue>> _extensionalValuesList = obj.getExtensionalValues();
	for(std::shared_ptr<fUML::ExtensionalValue> _extensionalValues : *_extensionalValuesList)
	{
		this->getExtensionalValues()->add(std::shared_ptr<fUML::ExtensionalValue>(std::dynamic_pointer_cast<fUML::ExtensionalValue>(_extensionalValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_extensionalValues" << std::endl;
	#endif
	if(obj.getFactory()!=nullptr)
	{
		m_factory = std::dynamic_pointer_cast<fUML::ExecutionFactory>(obj.getFactory()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_factory" << std::endl;
	#endif

	

	
	

	
}

std::shared_ptr<ecore::EObject>  LocusImpl::copy() const
{
	std::shared_ptr<LocusImpl> element(new LocusImpl(*this));
	element->setThisLocusPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LocusImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLocus_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void LocusImpl::add(std::shared_ptr<fUML::ExtensionalValue>  value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	value->setLocus(getThisLocusPtr());
	this->getExtensionalValues()->push_back(value);
	//end of body
}

void LocusImpl::assignExecutor(std::shared_ptr<fUML::Executor>  executor)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->setExecutor(executor);
	this->getExecutor()->setLocus(getThisLocusPtr());
	//end of body
}

void LocusImpl::assignFactory(std::shared_ptr<fUML::ExecutionFactory>  factory)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->setFactory(factory);
	this->getFactory()->setLocus(getThisLocusPtr());
	//end of body
}

bool LocusImpl::conforms(std::shared_ptr<uml::Classifier>  type,std::shared_ptr<uml::Classifier>  classifier)
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

std::shared_ptr<fUML::Object> LocusImpl::instantiate(std::shared_ptr<uml::Class>  type)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Object> object = nullptr;
	std::shared_ptr<uml::Behavior> behavior = std::dynamic_pointer_cast<uml::Behavior>(type);
    if(behavior != nullptr)
    {
    	std::shared_ptr<fUML::Object>  context = nullptr;
        object = std::dynamic_pointer_cast<Object>(this->getFactory()->createExecution(behavior, nullptr));
    }
    else
    {
        object = FUMLFactory::eInstance()->createObject();
        object->getTypes()->push_back(type);
        object->createFeatureValues();
        this->add(object);
    }
    
    return object;
	//end of body
}

void LocusImpl::remove(std::shared_ptr<fUML::ExtensionalValue>  value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	value->setLocus(nullptr);
	this->getExtensionalValues()->erase(value);
	//end of body
}

std::shared_ptr<Bag<fUML::ExtensionalValue> > LocusImpl::retrieveExtent(std::shared_ptr<uml::Classifier>  classifier)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<fUML::ExtensionalValue> > extent =this->getExtensionalValues();
	std::shared_ptr<Bag<fUML::ExtensionalValue> > extensionalValues = this->getExtensionalValues();

	for (unsigned int i=0; i < extensionalValues->size();i++)
	{
		std::shared_ptr<fUML::ExtensionalValue> value = extensionalValues->at(i);
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
// References
//*********************************
std::shared_ptr<fUML::Executor > LocusImpl::getExecutor() const
{

    return m_executor;
}
void LocusImpl::setExecutor(std::shared_ptr<fUML::Executor> _executor)
{
    m_executor = _executor;
}

std::shared_ptr<Bag<fUML::ExtensionalValue>> LocusImpl::getExtensionalValues() const
{

    return m_extensionalValues;
}


std::shared_ptr<fUML::ExecutionFactory > LocusImpl::getFactory() const
{
//assert(m_factory);
    return m_factory;
}
void LocusImpl::setFactory(std::shared_ptr<fUML::ExecutionFactory> _factory)
{
    m_factory = _factory;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<Locus> LocusImpl::getThisLocusPtr() const
{
	return m_thisLocusPtr.lock();
}
void LocusImpl::setThisLocusPtr(std::weak_ptr<Locus> thisLocusPtr)
{
	m_thisLocusPtr = thisLocusPtr;
}
std::shared_ptr<ecore::EObject> LocusImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LocusImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::LOCUS_EREFERENCE_EXECUTOR:
			return eAny(getExecutor()); //1140
		case FUMLPackage::LOCUS_EREFERENCE_EXTENSIONALVALUES:
			return eAny(getExtensionalValues()); //1142
		case FUMLPackage::LOCUS_EREFERENCE_FACTORY:
			return eAny(getFactory()); //1141
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool LocusImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::LOCUS_EREFERENCE_EXECUTOR:
			return getExecutor() != nullptr; //1140
		case FUMLPackage::LOCUS_EREFERENCE_EXTENSIONALVALUES:
			return getExtensionalValues() != nullptr; //1142
		case FUMLPackage::LOCUS_EREFERENCE_FACTORY:
			return getFactory() != nullptr; //1141
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool LocusImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::LOCUS_EREFERENCE_EXECUTOR:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Executor> _executor = newValue->get<std::shared_ptr<fUML::Executor>>();
			setExecutor(_executor); //1140
			return true;
		}
		case FUMLPackage::LOCUS_EREFERENCE_FACTORY:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ExecutionFactory> _factory = newValue->get<std::shared_ptr<fUML::ExecutionFactory>>();
			setFactory(_factory); //1141
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void LocusImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void LocusImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
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
			std::shared_ptr<ecore::EObject> executor = modelFactory->create(typeName, loadHandler->getCurrentObject(), FUMLPackage::EXECUTOR_EREFERENCE_LOCUS);
			if (executor != nullptr)
			{
				loadHandler->handleChild(executor);
			}
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
			std::shared_ptr<fUML::ExtensionalValue> extensionalValues = std::dynamic_pointer_cast<fUML::ExtensionalValue>(modelFactory->create(typeName));
			if (extensionalValues != nullptr)
			{
				std::shared_ptr<Bag<fUML::ExtensionalValue>> list_extensionalValues = this->getExtensionalValues();
				list_extensionalValues->push_back(extensionalValues);
				loadHandler->handleChild(extensionalValues);
			}
			return;
		}

		if ( nodeName.compare("factory") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> factory = modelFactory->create(typeName, loadHandler->getCurrentObject(), FUMLPackage::EXECUTIONFACTORY_EREFERENCE_LOCUS);
			if (factory != nullptr)
			{
				loadHandler->handleChild(factory);
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

	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void LocusImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'executor'
		std::shared_ptr<fUML::Executor > executor = this->getExecutor();
		if (executor != nullptr)
		{
			saveHandler->addReference(executor, "executor", executor->eClass() != package->getExecutor_EClass());
		}

		// Save 'extensionalValues'
		std::shared_ptr<Bag<fUML::ExtensionalValue>> list_extensionalValues = this->getExtensionalValues();
		for (std::shared_ptr<fUML::ExtensionalValue> extensionalValues : *list_extensionalValues) 
		{
			saveHandler->addReference(extensionalValues, "extensionalValues", extensionalValues->eClass() != package->getExtensionalValue_EClass());
		}

		// Save 'factory'
		std::shared_ptr<fUML::ExecutionFactory > factory = this->getFactory();
		if (factory != nullptr)
		{
			saveHandler->addReference(factory, "factory", factory->eClass() != package->getExecutionFactory_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

