#include "ocl/Types/impl/VoidTypeImpl.hpp"

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
#include "ecore/EcoreFactory.hpp"


#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/ETypeParameter.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Types/TypesPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Types;

//*********************************
// Constructor / Destructor
//*********************************
VoidTypeImpl::VoidTypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

VoidTypeImpl::~VoidTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete VoidType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
VoidTypeImpl::VoidTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage)
:VoidTypeImpl()
{
	m_ePackage = par_ePackage;
}

VoidTypeImpl::VoidTypeImpl(const VoidTypeImpl & obj): VoidTypeImpl()
{
	*this = obj;
}

VoidTypeImpl& VoidTypeImpl::operator=(const VoidTypeImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EClassifierImpl::operator=(obj);
	VoidType::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy VoidType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> VoidTypeImpl::copy() const
{
	std::shared_ptr<VoidTypeImpl> element(new VoidTypeImpl());
	*element =(*this);
	element->setThisVoidTypePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> VoidTypeImpl::eStaticClass() const
{
	return ocl::Types::TypesPackage::eInstance()->getVoidType_Class();
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



std::shared_ptr<VoidType> VoidTypeImpl::getThisVoidTypePtr() const
{
	return m_thisVoidTypePtr.lock();
}
void VoidTypeImpl::setThisVoidTypePtr(std::weak_ptr<VoidType> thisVoidTypePtr)
{
	m_thisVoidTypePtr = thisVoidTypePtr;
	setThisEClassifierPtr(thisVoidTypePtr);
}
std::shared_ptr<ecore::EObject> VoidTypeImpl::eContainer() const
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
Any VoidTypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EClassifierImpl::eGet(featureID, resolve, coreType);
}
bool VoidTypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EClassifierImpl::internalEIsSet(featureID);
}
bool VoidTypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any VoidTypeImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::EClassifierImpl::eInvoke(operationID, arguments);
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
void VoidTypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void VoidTypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void VoidTypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ecore::EClassifierImpl::loadNode(nodeName, loadHandler);
}

void VoidTypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EClassifierImpl::resolveReferences(featureID, references);
}

void VoidTypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EClassifierImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void VoidTypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

