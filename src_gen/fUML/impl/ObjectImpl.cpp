#include "fUML/impl/ObjectImpl.hpp"

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
#include "fUML/DispatchStrategy.hpp"
#include "fUML/ExecutionFactory.hpp"
#include "fUML/FUMLFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "fUML/EventAccepter.hpp"

#include "fUML/Execution.hpp"

#include "fUML/ExtensionalValue.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Locus.hpp"

#include "fUML/ObjectActivation.hpp"

#include "uml/Operation.hpp"

#include "fUML/ParameterValue.hpp"

#include "fUML/SignalInstance.hpp"

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
ObjectImpl::ObjectImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_types.reset(new Bag<uml::Classifier>());
	
	

	//Init references
	

	
	
}

ObjectImpl::~ObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Object "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ObjectImpl::ObjectImpl(const ObjectImpl & obj):ObjectImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Object "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
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

	
}

std::shared_ptr<ecore::EObject>  ObjectImpl::copy() const
{
	std::shared_ptr<ObjectImpl> element(new ObjectImpl(*this));
	element->setThisObjectPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ObjectImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObject_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ObjectImpl::_register(std::shared_ptr<fUML::EventAccepter>  accepter)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->_register(accepter);
    }
	//end of body
}

void ObjectImpl::destroy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if(this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->stop();
        this->setObjectActivation(nullptr);
    }

    this->getTypes()->clear();
    ExtensionalValueImpl::destroy();
	//end of body
}

std::shared_ptr<fUML::Execution> ObjectImpl::dispatch(std::shared_ptr<uml::Operation>  operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	static std::shared_ptr<DispatchStrategy> strategy = std::dynamic_pointer_cast<DispatchStrategy>(this->getLocus()->getFactory()->getStrategy("dispatch"));
	return strategy->dispatch(getThisObjectPtr(), operation);
	//end of body
}

std::shared_ptr<fUML::Value> ObjectImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(FUMLFactory::eInstance()->createObject());
	//end of body
}

void ObjectImpl::send(std::shared_ptr<fUML::SignalInstance>  signalInstance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->send(signalInstance);
    }
	//end of body
}

void ObjectImpl::startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if(this->getObjectActivation() == nullptr)
    {
        this->setObjectActivation(std::shared_ptr<ObjectActivation>(fUML::FUMLFactory::eInstance()->createObjectActivation()));
        this->getObjectActivation()->setObject(getThisObjectPtr());
    }

    this->getObjectActivation()->startBehavior(classifier, inputs);
	//end of body
}

void ObjectImpl::unregister(std::shared_ptr<fUML::EventAccepter>  accepter)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->unregister(accepter);
    }
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::ObjectActivation > ObjectImpl::getObjectActivation() const
{

    return m_objectActivation;
}
void ObjectImpl::setObjectActivation(std::shared_ptr<fUML::ObjectActivation> _objectActivation)
{
    m_objectActivation = _objectActivation;
}

std::shared_ptr<Bag<uml::Classifier>> ObjectImpl::getTypes() const
{

    return m_types;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<Object> ObjectImpl::getThisObjectPtr() const
{
	return m_thisObjectPtr.lock();
}
void ObjectImpl::setThisObjectPtr(std::weak_ptr<Object> thisObjectPtr)
{
	m_thisObjectPtr = thisObjectPtr;
	setThisExtensionalValuePtr(thisObjectPtr);
}
std::shared_ptr<ecore::EObject> ObjectImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::OBJECT_EREFERENCE_OBJECTACTIVATION:
			return eAny(getObjectActivation()); //373
		case FUMLPackage::OBJECT_EREFERENCE_TYPES:
			return eAny(getTypes()); //372
	}
	return ExtensionalValueImpl::eGet(featureID, resolve, coreType);
}
bool ObjectImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::OBJECT_EREFERENCE_OBJECTACTIVATION:
			return getObjectActivation() != nullptr; //373
		case FUMLPackage::OBJECT_EREFERENCE_TYPES:
			return getTypes() != nullptr; //372
	}
	return ExtensionalValueImpl::internalEIsSet(featureID);
}
bool ObjectImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::OBJECT_EREFERENCE_OBJECTACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ObjectActivation> _objectActivation = newValue->get<std::shared_ptr<fUML::ObjectActivation>>();
			setObjectActivation(_objectActivation); //373
			return true;
		}
	}

	return ExtensionalValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ObjectImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
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

	ExtensionalValueImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("objectActivation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ObjectActivation";
			}
			std::shared_ptr<fUML::ObjectActivation> objectActivation = std::dynamic_pointer_cast<fUML::ObjectActivation>(modelFactory->create(typeName));
			if (objectActivation != nullptr)
			{
				this->setObjectActivation(objectActivation);
				loadHandler->handleChild(objectActivation);
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

	ExtensionalValueImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ObjectImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::OBJECT_EREFERENCE_TYPES:
		{
			std::shared_ptr<Bag<uml::Classifier>> _types = getTypes();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier> _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_types->push_back(_r);
				}				
			}
			return;
		}
	}
	ExtensionalValueImpl::resolveReferences(featureID, references);
}

void ObjectImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExtensionalValueImpl::saveContent(saveHandler);
	
	CompoundValueImpl::saveContent(saveHandler);
	
	StructuredValueImpl::saveContent(saveHandler);
	
	ValueImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ObjectImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<uml::Classifier>> types_list = this->getTypes();
		for (std::shared_ptr<uml::Classifier > object : *types_list)
		{ 
			saveHandler->addReferences("types", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'objectActivation'
		std::shared_ptr<fUML::ObjectActivation > objectActivation = this->getObjectActivation();
		if (objectActivation != nullptr)
		{
			saveHandler->addReference(objectActivation, "objectActivation", objectActivation->eClass() != package->getObjectActivation_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

