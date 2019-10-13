#include "fUML/impl/DataValueImpl.hpp"

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
#include "fUML/DataValue.hpp"
#include "uml/UmlFactory.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/CompoundValue.hpp"
#include "uml/DataType.hpp"
#include "uml/Classifier.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Classifier.hpp"

#include "fUML/CompoundValue.hpp"

#include "uml/DataType.hpp"

#include "fUML/FeatureValue.hpp"

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
DataValueImpl::DataValueImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

DataValueImpl::~DataValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DataValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




DataValueImpl::DataValueImpl(const DataValueImpl & obj):DataValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DataValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(std::dynamic_pointer_cast<fUML::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  DataValueImpl::copy() const
{
	std::shared_ptr<DataValueImpl> element(new DataValueImpl(*this));
	element->setThisDataValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DataValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDataValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Classifier> > DataValueImpl::getTypes()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());
    types->push_back(std::dynamic_pointer_cast<uml::Classifier>(this->getType()));
    return types;
	//end of body
}

std::shared_ptr<fUML::Value> DataValueImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(FUMLFactory::eInstance()->createDataValue());
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::DataType > DataValueImpl::getType() const
{
//assert(m_type);
    return m_type;
}
void DataValueImpl::setType(std::shared_ptr<uml::DataType> _type)
{
    m_type = _type;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<DataValue> DataValueImpl::getThisDataValuePtr() const
{
	return m_thisDataValuePtr.lock();
}
void DataValueImpl::setThisDataValuePtr(std::weak_ptr<DataValue> thisDataValuePtr)
{
	m_thisDataValuePtr = thisDataValuePtr;
	setThisCompoundValuePtr(thisDataValuePtr);
}
std::shared_ptr<ecore::EObject> DataValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DataValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::DATAVALUE_ATTRIBUTE_TYPE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getType())); //331
	}
	return CompoundValueImpl::eGet(featureID, resolve, coreType);
}
bool DataValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::DATAVALUE_ATTRIBUTE_TYPE:
			return getType() != nullptr; //331
	}
	return CompoundValueImpl::internalEIsSet(featureID);
}
bool DataValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::DATAVALUE_ATTRIBUTE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::DataType> _type = std::dynamic_pointer_cast<uml::DataType>(_temp);
			setType(_type); //331
			return true;
		}
	}

	return CompoundValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void DataValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DataValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("type");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("type")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	CompoundValueImpl::loadAttributes(loadHandler, attr_list);
}

void DataValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	CompoundValueImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void DataValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::DATAVALUE_ATTRIBUTE_TYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DataType> _type = std::dynamic_pointer_cast<uml::DataType>( references.front() );
				setType(_type);
			}
			
			return;
		}
	}
	CompoundValueImpl::resolveReferences(featureID, references);
}

void DataValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CompoundValueImpl::saveContent(saveHandler);
	
	StructuredValueImpl::saveContent(saveHandler);
	
	ValueImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void DataValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		saveHandler->addReference("type", this->getType());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

