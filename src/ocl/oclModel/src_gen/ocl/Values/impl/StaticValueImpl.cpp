
#include "ocl/Values/impl/StaticValueImpl.hpp"
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



#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/fUMLFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Values/Value.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"

using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************
StaticValueImpl::StaticValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StaticValueImpl::~StaticValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StaticValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


StaticValueImpl::StaticValueImpl(const StaticValueImpl & obj): StaticValueImpl()
{
	*this = obj;
}

StaticValueImpl& StaticValueImpl::operator=(const StaticValueImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::ValueImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of StaticValue 
	 * which is generated by the compiler (as StaticValue is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//StaticValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StaticValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> StaticValueImpl::copy() const
{
	std::shared_ptr<StaticValueImpl> element(new StaticValueImpl());
	*element =(*this);
	element->setThisStaticValuePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> StaticValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void StaticValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StaticValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Values::ValueImpl::loadAttributes(loadHandler, attr_list);
}

void StaticValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::ValueImpl::loadNode(nodeName, loadHandler);
}

void StaticValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::ValueImpl::resolveReferences(featureID, references);
}

void StaticValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void StaticValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> StaticValueImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getStaticValue_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any StaticValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::ValueImpl::eGet(featureID, resolve, coreType);
}

bool StaticValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::ValueImpl::internalEIsSet(featureID);
}

bool StaticValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Values::ValueImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any StaticValueImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::ValueImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Values::StaticValue> StaticValueImpl::getThisStaticValuePtr() const
{
	return m_thisStaticValuePtr.lock();
}
void StaticValueImpl::setThisStaticValuePtr(std::weak_ptr<ocl::Values::StaticValue> thisStaticValuePtr)
{
	m_thisStaticValuePtr = thisStaticValuePtr;
	setThisValuePtr(thisStaticValuePtr);
}


