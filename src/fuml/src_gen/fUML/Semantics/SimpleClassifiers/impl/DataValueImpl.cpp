#include "fUML/Semantics/SimpleClassifiers/impl/DataValueImpl.hpp"

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
#include "fUML/Semantics/SimpleClassifiers/DataValue.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/CompoundValue.hpp"
#include "uml/DataType.hpp"
#include "uml/Classifier.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"


#include "uml/Classifier.hpp"
#include "fUML/Semantics/SimpleClassifiers/CompoundValue.hpp"
#include "uml/DataType.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
DataValueImpl::DataValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DataValueImpl::~DataValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DataValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


DataValueImpl::DataValueImpl(const DataValueImpl & obj): DataValueImpl()
{
	*this = obj;
}

DataValueImpl& DataValueImpl::operator=(const DataValueImpl & obj)
{
	//call overloaded =Operator for each base class
	CompoundValueImpl::operator=(obj);
	DataValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DataValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_type  = obj.getType();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DataValueImpl::copy() const
{
	std::shared_ptr<DataValueImpl> element(new DataValueImpl());
	*element =(*this);
	element->setThisDataValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DataValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getDataValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> DataValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new data value with the same type and feature values as this data value.

std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> newValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::DataValue>(fUML::Semantics::SimpleClassifiers::CompoundValueImpl::_copy());
newValue->setType(this->getType());
return newValue;
	//end of body
}

std::shared_ptr<Bag<uml::Classifier> > DataValueImpl::getTypes()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());
    types->push_back(std::dynamic_pointer_cast<uml::Classifier>(this->getType()));
    return types;
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> DataValueImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::shared_ptr<fUML::Semantics::Values::Value>(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createDataValue());
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference type
*/
std::shared_ptr<uml::DataType> DataValueImpl::getType() const
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
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::DATAVALUE_ATTRIBUTE_TYPE:
			return eAny(getType()); //361
	}
	return CompoundValueImpl::eGet(featureID, resolve, coreType);
}
bool DataValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::DATAVALUE_ATTRIBUTE_TYPE:
			return getType() != nullptr; //361
	}
	return CompoundValueImpl::internalEIsSet(featureID);
}
bool DataValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::DATAVALUE_ATTRIBUTE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::DataType> _type = std::dynamic_pointer_cast<uml::DataType>(_temp);
			setType(_type); //361
			return true;
		}
	}

	return CompoundValueImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any DataValueImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 3629
		case SimpleClassifiersPackage::DATAVALUE_OPERATION__COPY:
		{
			result = eAny(this->_copy());
			break;
		}
		
		// 3628
		case SimpleClassifiersPackage::DATAVALUE_OPERATION_GETTYPES:
		{
			result = eAny(this->getTypes());
			break;
		}
		
		// 3627
		case SimpleClassifiersPackage::DATAVALUE_OPERATION_NEW_:
		{
			result = eAny(this->new_());
			break;
		}

		default:
		{
			// call superTypes
			result = CompoundValueImpl::eInvoke(operationID, arguments);
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
void DataValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DataValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CompoundValueImpl::loadNode(nodeName, loadHandler);
}

void DataValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::DATAVALUE_ATTRIBUTE_TYPE:
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
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void DataValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> package = fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getType(), "type", getType()->eClass() != uml::umlPackage::eInstance()->getDataType_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

