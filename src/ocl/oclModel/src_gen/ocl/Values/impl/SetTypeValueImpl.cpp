#include "ocl/Values/impl/SetTypeValueImpl.hpp"

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
#include "ocl/Values/ValuesPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************
SetTypeValueImpl::SetTypeValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SetTypeValueImpl::~SetTypeValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SetTypeValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


SetTypeValueImpl::SetTypeValueImpl(const SetTypeValueImpl & obj): SetTypeValueImpl()
{
	*this = obj;
}

SetTypeValueImpl& SetTypeValueImpl::operator=(const SetTypeValueImpl & obj)
{
	//call overloaded =Operator for each base class
	CollectionValueImpl::operator=(obj);
	SetTypeValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SetTypeValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> SetTypeValueImpl::copy() const
{
	std::shared_ptr<SetTypeValueImpl> element(new SetTypeValueImpl());
	*element =(*this);
	element->setThisSetTypeValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> SetTypeValueImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getSetTypeValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool SetTypeValueImpl::addValue(std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if(!this->find(value)) {
    std::shared_ptr<ocl::Values::Element> elem = ocl::Values::ValuesFactory::eInstance()->createElement();
    elem->setValue(value);
    elem->setIndexNr(this->getElements()->size());
    this->getElements()->add(elem);

    return true;
}
return false;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<SetTypeValue> SetTypeValueImpl::getThisSetTypeValuePtr() const
{
	return m_thisSetTypeValuePtr.lock();
}
void SetTypeValueImpl::setThisSetTypeValuePtr(std::weak_ptr<SetTypeValue> thisSetTypeValuePtr)
{
	m_thisSetTypeValuePtr = thisSetTypeValuePtr;
	setThisCollectionValuePtr(thisSetTypeValuePtr);
}
std::shared_ptr<ecore::EObject> SetTypeValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any SetTypeValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return CollectionValueImpl::eGet(featureID, resolve, coreType);
}
bool SetTypeValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return CollectionValueImpl::internalEIsSet(featureID);
}
bool SetTypeValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return CollectionValueImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any SetTypeValueImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 7816
		case ValuesPackage::SETTYPEVALUE_OPERATION_ADDVALUE_VALUE:
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
void SetTypeValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SetTypeValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CollectionValueImpl::loadAttributes(loadHandler, attr_list);
}

void SetTypeValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CollectionValueImpl::loadNode(nodeName, loadHandler);
}

void SetTypeValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	CollectionValueImpl::resolveReferences(featureID, references);
}

void SetTypeValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CollectionValueImpl::saveContent(saveHandler);
	
	StaticValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void SetTypeValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

