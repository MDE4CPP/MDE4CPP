#include "ocl/Types/impl/OrderedSetTypeImpl.hpp"

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
#include "ecore/ecoreFactory.hpp"
#include "ocl/Values/ValuesFactory.hpp"


#include "ocl/Types/CollectionType.hpp"
#include "ocl/Values/CollectionValue.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/ETypeParameter.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Types/TypesPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Types;

//*********************************
// Constructor / Destructor
//*********************************
OrderedSetTypeImpl::OrderedSetTypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OrderedSetTypeImpl::~OrderedSetTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OrderedSetType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OrderedSetTypeImpl::OrderedSetTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage)
:OrderedSetTypeImpl()
{
	m_ePackage = par_ePackage;
}

OrderedSetTypeImpl::OrderedSetTypeImpl(const OrderedSetTypeImpl & obj): OrderedSetTypeImpl()
{
	*this = obj;
}

OrderedSetTypeImpl& OrderedSetTypeImpl::operator=(const OrderedSetTypeImpl & obj)
{
	//call overloaded =Operator for each base class
	CollectionTypeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OrderedSetType 
	 * which is generated by the compiler (as OrderedSetType is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OrderedSetType::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OrderedSetType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OrderedSetTypeImpl::copy() const
{
	std::shared_ptr<OrderedSetTypeImpl> element(new OrderedSetTypeImpl());
	*element =(*this);
	element->setThisOrderedSetTypePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OrderedSetTypeImpl::eStaticClass() const
{
	return ocl::Types::TypesPackage::eInstance()->getOrderedSetType_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<OrderedSetType> OrderedSetTypeImpl::getThisOrderedSetTypePtr() const
{
	return m_thisOrderedSetTypePtr.lock();
}
void OrderedSetTypeImpl::setThisOrderedSetTypePtr(std::weak_ptr<OrderedSetType> thisOrderedSetTypePtr)
{
	m_thisOrderedSetTypePtr = thisOrderedSetTypePtr;
	setThisCollectionTypePtr(thisOrderedSetTypePtr);
}
std::shared_ptr<ecore::EObject> OrderedSetTypeImpl::eContainer() const
{
	if(auto wp = m_ePackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any OrderedSetTypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return CollectionTypeImpl::eGet(featureID, resolve, coreType);
}
bool OrderedSetTypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return CollectionTypeImpl::internalEIsSet(featureID);
}
bool OrderedSetTypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return CollectionTypeImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any OrderedSetTypeImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = CollectionTypeImpl::eInvoke(operationID, arguments);
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
void OrderedSetTypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OrderedSetTypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CollectionTypeImpl::loadAttributes(loadHandler, attr_list);
}

void OrderedSetTypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CollectionTypeImpl::loadNode(nodeName, loadHandler);
}

void OrderedSetTypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	CollectionTypeImpl::resolveReferences(featureID, references);
}

void OrderedSetTypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CollectionTypeImpl::saveContent(saveHandler);
	
	ecore::EDataTypeImpl::saveContent(saveHandler);
	
	ecore::EClassifierImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void OrderedSetTypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Types::TypesPackage> package = ocl::Types::TypesPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

