
#include "ocl/Types/impl/SequenceTypeImpl.hpp"
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
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Types/TypesPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Types;

//*********************************
// Constructor / Destructor
//*********************************
SequenceTypeImpl::SequenceTypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SequenceTypeImpl::~SequenceTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SequenceType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
SequenceTypeImpl::SequenceTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage)
:SequenceTypeImpl()
{
	m_ePackage = par_ePackage;
}

SequenceTypeImpl::SequenceTypeImpl(const SequenceTypeImpl & obj): SequenceTypeImpl()
{
	*this = obj;
}

SequenceTypeImpl& SequenceTypeImpl::operator=(const SequenceTypeImpl & obj)
{
	//call overloaded =Operator for each base class
	CollectionTypeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of SequenceType 
	 * which is generated by the compiler (as SequenceType is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//SequenceType::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SequenceType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> SequenceTypeImpl::copy() const
{
	std::shared_ptr<SequenceTypeImpl> element(new SequenceTypeImpl());
	*element =(*this);
	element->setThisSequenceTypePtr(element);
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
std::shared_ptr<ecore::EObject> SequenceTypeImpl::eContainer() const
{
	if(auto wp = m_ePackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void SequenceTypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SequenceTypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CollectionTypeImpl::loadAttributes(loadHandler, attr_list);
}

void SequenceTypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CollectionTypeImpl::loadNode(nodeName, loadHandler);
}

void SequenceTypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	CollectionTypeImpl::resolveReferences(featureID, references);
}

void SequenceTypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CollectionTypeImpl::saveContent(saveHandler);
	
	ecore::EDataTypeImpl::saveContent(saveHandler);
	
	ecore::EClassifierImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void SequenceTypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> SequenceTypeImpl::eStaticClass() const
{
	return ocl::Types::TypesPackage::eInstance()->getSequenceType_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any SequenceTypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return CollectionTypeImpl::eGet(featureID, resolve, coreType);
}

bool SequenceTypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return CollectionTypeImpl::internalEIsSet(featureID);
}

bool SequenceTypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return CollectionTypeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any SequenceTypeImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = CollectionTypeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Types::SequenceType> SequenceTypeImpl::getThisSequenceTypePtr() const
{
	return m_thisSequenceTypePtr.lock();
}
void SequenceTypeImpl::setThisSequenceTypePtr(std::weak_ptr<ocl::Types::SequenceType> thisSequenceTypePtr)
{
	m_thisSequenceTypePtr = thisSequenceTypePtr;
	setThisCollectionTypePtr(thisSequenceTypePtr);
}


