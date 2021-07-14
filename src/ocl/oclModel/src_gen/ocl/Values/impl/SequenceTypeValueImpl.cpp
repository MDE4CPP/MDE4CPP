#include "ocl/Values/impl/SequenceTypeValueImpl.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Values/ValuesFactory.hpp"
#include "ocl/Types/TypesFactory.hpp"


#include "ocl/Types/CollectionType.hpp"
#include "ocl/Values/CollectionValue.hpp"
#include "ocl/Values/Element.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Types/TypesPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************
SequenceTypeValueImpl::SequenceTypeValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SequenceTypeValueImpl::~SequenceTypeValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SequenceTypeValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


SequenceTypeValueImpl::SequenceTypeValueImpl(const SequenceTypeValueImpl & obj): SequenceTypeValueImpl()
{
	*this = obj;
}

SequenceTypeValueImpl& SequenceTypeValueImpl::operator=(const SequenceTypeValueImpl & obj)
{
	//call overloaded =Operator for each base class
	CollectionValueImpl::operator=(obj);
	SequenceTypeValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SequenceTypeValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> SequenceTypeValueImpl::copy() const
{
	std::shared_ptr<SequenceTypeValueImpl> element(new SequenceTypeValueImpl());
	*element =(*this);
	element->setThisSequenceTypeValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> SequenceTypeValueImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getSequenceTypeValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool SequenceTypeValueImpl::addValue(std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<ocl::Values::Element> elem = ocl::Values::ValuesFactory::eInstance()->createElement();
elem->setValue(value);
elem->setIndexNr(this->getElements()->size());
this->getElements()->add(elem);

return true;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<SequenceTypeValue> SequenceTypeValueImpl::getThisSequenceTypeValuePtr() const
{
	return m_thisSequenceTypeValuePtr.lock();
}
void SequenceTypeValueImpl::setThisSequenceTypeValuePtr(std::weak_ptr<SequenceTypeValue> thisSequenceTypeValuePtr)
{
	m_thisSequenceTypeValuePtr = thisSequenceTypeValuePtr;
	setThisCollectionValuePtr(thisSequenceTypeValuePtr);
}
std::shared_ptr<ecore::EObject> SequenceTypeValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any SequenceTypeValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return CollectionValueImpl::eGet(featureID, resolve, coreType);
}
bool SequenceTypeValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return CollectionValueImpl::internalEIsSet(featureID);
}
bool SequenceTypeValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return CollectionValueImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any SequenceTypeValueImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 7616
		case ValuesPackage::SEQUENCETYPEVALUE_OPERATION_ADDVALUE_VALUE:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_value;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->addValue(incoming_param_value));
			break;
		}

		default:
		{
			// call superTypes
			result = CollectionValueImpl::eInvoke(operationID, arguments);
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
void SequenceTypeValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void SequenceTypeValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CollectionValueImpl::loadAttributes(loadHandler, attr_list);
}

void SequenceTypeValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CollectionValueImpl::loadNode(nodeName, loadHandler);
}

void SequenceTypeValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	CollectionValueImpl::resolveReferences(featureID, references);
}

void SequenceTypeValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CollectionValueImpl::saveContent(saveHandler);
	
	StaticValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void SequenceTypeValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Values::ValuesPackage> package = ocl::Values::ValuesPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

