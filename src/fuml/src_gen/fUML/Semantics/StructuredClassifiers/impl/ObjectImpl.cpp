#include "fUML/Semantics/StructuredClassifiers/impl/ObjectImpl.hpp"

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
#include "fUML/Semantics/StructuredClassifiers/DispatchStrategy.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"

#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"

#include "fUML/Semantics/CommonBehavior/Execution.hpp"

#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"

#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"

#include "uml/Operation.hpp"

#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"

#include "fUML/Semantics/SimpleClassifiers/SignalInstance.hpp"

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

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

	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue>(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(obj.getObjectActivation()->copy());
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
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ObjectImpl::_register(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>  accepter)
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
    fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::destroy();
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> ObjectImpl::dispatch(std::shared_ptr<uml::Operation>  operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	static std::shared_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategy> strategy = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::DispatchStrategy>(this->getLocus()->getFactory()->getStrategy("dispatch"));
	return strategy->dispatch(getThisObjectPtr(), operation);
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> ObjectImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createObject();
	//end of body
}

void ObjectImpl::send(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance>  signalInstance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->send(signalInstance);
    }
	//end of body
}

void ObjectImpl::send(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	//end of body
}

void ObjectImpl::startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if(this->getObjectActivation() == nullptr) 
    {
        this->setObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation>(fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createObjectActivation()));
        this->getObjectActivation()->setObject(getThisObjectPtr());
    }

    this->getObjectActivation()->startBehavior(classifier, inputs);
	//end of body
}

void ObjectImpl::unregister(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>  accepter)
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
std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation > ObjectImpl::getObjectActivation() const
{

    return m_objectActivation;
}
void ObjectImpl::setObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> _objectActivation)
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
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_OBJECTACTIVATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getObjectActivation())); //803
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_TYPES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Classifier>::iterator iter = m_types->begin();
			Bag<uml::Classifier>::iterator end = m_types->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //802
		}
	}
	return ExtensionalValueImpl::eGet(featureID, resolve, coreType);
}
bool ObjectImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_OBJECTACTIVATION:
			return getObjectActivation() != nullptr; //803
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_TYPES:
			return getTypes() != nullptr; //802
	}
	return ExtensionalValueImpl::internalEIsSet(featureID);
}
bool ObjectImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_OBJECTACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> _objectActivation = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(_temp);
			setObjectActivation(_objectActivation); //803
			return true;
		}
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_TYPES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> typesList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				typesList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterTypes = m_types->begin();
			Bag<uml::Classifier>::iterator endTypes = m_types->end();
			while (iterTypes != endTypes)
			{
				if (typesList->find(*iterTypes) == -1)
				{
					m_types->erase(*iterTypes);
				}
				iterTypes++;
			}

			iterTypes = typesList->begin();
			endTypes = typesList->end();
			while (iterTypes != endTypes)
			{
				if (m_types->find(*iterTypes) == -1)
				{
					m_types->add(*iterTypes);
				}
				iterTypes++;			
			}
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
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
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

void ObjectImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory> modelFactory=fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance();

	try
	{
		if ( nodeName.compare("objectActivation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ObjectActivation";
			}
			std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> objectActivation = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(modelFactory->create(typeName));
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
	//load BasePackage Nodes
	ExtensionalValueImpl::loadNode(nodeName, loadHandler);
}

void ObjectImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_TYPES:
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
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ObjectImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();

	

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
		std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation > objectActivation = this->getObjectActivation();
		if (objectActivation != nullptr)
		{
			saveHandler->addReference(objectActivation, "objectActivation", objectActivation->eClass() != fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getObjectActivation_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

