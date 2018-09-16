#include "subsetUnionBenchmark/impl/Element_Level1Impl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "subsetUnionBenchmark/impl/SubsetUnionBenchmarkPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "subsetUnionBenchmark/SubsetUnionBenchmarkFactory.hpp"
#include "subsetUnionBenchmark/SubsetUnionBenchmarkPackage.hpp"
#include <exception> // used in Persistence

#include "subsetUnionBenchmark/Element.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "subsetUnionBenchmark/SubsetUnionBenchmarkPackage.hpp"
#include "subsetUnionBenchmark/SubsetUnionBenchmarkFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace subsetUnionBenchmark;

//*********************************
// Constructor / Destructor
//*********************************
Element_Level1Impl::Element_Level1Impl()
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

Element_Level1Impl::~Element_Level1Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Element_Level1 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




Element_Level1Impl::Element_Level1Impl(const Element_Level1Impl & obj):Element_Level1Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Element_Level1 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  Element_Level1Impl::copy() const
{
	std::shared_ptr<Element_Level1Impl> element(new Element_Level1Impl(*this));
	element->setThisElement_Level1Ptr(element);
	return element;
}

std::shared_ptr<ecore::EClass> Element_Level1Impl::eStaticClass() const
{
	return SubsetUnionBenchmarkPackageImpl::eInstance()->getElement_Level1_EClass();
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


std::shared_ptr<Element_Level1> Element_Level1Impl::getThisElement_Level1Ptr() const
{
	return m_thisElement_Level1Ptr.lock();
}
void Element_Level1Impl::setThisElement_Level1Ptr(std::weak_ptr<Element_Level1> thisElement_Level1Ptr)
{
	m_thisElement_Level1Ptr = thisElement_Level1Ptr;
	setThisElementPtr(thisElement_Level1Ptr);
}
std::shared_ptr<ecore::EObject> Element_Level1Impl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any Element_Level1Impl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool Element_Level1Impl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool Element_Level1Impl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void Element_Level1Impl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get SubsetUnionBenchmarkFactory
	std::shared_ptr<subsetUnionBenchmark::SubsetUnionBenchmarkFactory> modelFactory = subsetUnionBenchmark::SubsetUnionBenchmarkFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void Element_Level1Impl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void Element_Level1Impl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<subsetUnionBenchmark::SubsetUnionBenchmarkFactory> modelFactory)
{


	ElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void Element_Level1Impl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ElementImpl::resolveReferences(featureID, references);
}

void Element_Level1Impl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void Element_Level1Impl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<subsetUnionBenchmark::SubsetUnionBenchmarkPackage> package = subsetUnionBenchmark::SubsetUnionBenchmarkPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

