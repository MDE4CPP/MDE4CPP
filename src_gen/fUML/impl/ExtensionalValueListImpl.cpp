#include "fUML/impl/ExtensionalValueListImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/ExtensionalValue.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Locus.hpp"

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
ExtensionalValueListImpl::ExtensionalValueListImpl()
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

ExtensionalValueListImpl::~ExtensionalValueListImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExtensionalValueList "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ExtensionalValueListImpl::ExtensionalValueListImpl(const ExtensionalValueListImpl & obj):ExtensionalValueListImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExtensionalValueList "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();


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

std::shared_ptr<ecore::EObject>  ExtensionalValueListImpl::copy() const
{
	std::shared_ptr<ExtensionalValueListImpl> element(new ExtensionalValueListImpl(*this));
	element->setThisExtensionalValueListPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExtensionalValueListImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExtensionalValueList_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ExtensionalValueListImpl::addValue(std::shared_ptr<fUML::ExtensionalValue>  value) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExtensionalValueListImpl::addValue(std::shared_ptr<fUML::ExtensionalValue>  value,int i) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::ExtensionalValue> ExtensionalValueListImpl::getValue() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string ExtensionalValueListImpl::removeValue(int i) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::Value> ExtensionalValueListImpl::setValue(std::shared_ptr<fUML::ExtensionalValue>  value,int i) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ExtensionalValueList> ExtensionalValueListImpl::getThisExtensionalValueListPtr()
{
	return m_thisExtensionalValueListPtr.lock();
}
void ExtensionalValueListImpl::setThisExtensionalValueListPtr(std::weak_ptr<ExtensionalValueList> thisExtensionalValueListPtr)
{
	m_thisExtensionalValueListPtr = thisExtensionalValueListPtr;
	setThisExtensionalValuePtr(thisExtensionalValueListPtr);
}
std::shared_ptr<ecore::EObject> ExtensionalValueListImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExtensionalValueListImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ExtensionalValueImpl::internalEIsSet(featureID);
}
bool ExtensionalValueListImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ExtensionalValueImpl::internalEIsSet(featureID);
}
bool ExtensionalValueListImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}

	return ExtensionalValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExtensionalValueListImpl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
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

void ExtensionalValueListImpl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExtensionalValueImpl::loadAttributes(loadHandler, attr_list);
}

void ExtensionalValueListImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ExtensionalValueImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExtensionalValueListImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ExtensionalValueImpl::resolveReferences(featureID, references);
}

void ExtensionalValueListImpl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExtensionalValueImpl::saveContent(saveHandler);
	
	CompoundValueImpl::saveContent(saveHandler);
	
	StructuredValueImpl::saveContent(saveHandler);
	
	ValueImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ExtensionalValueListImpl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

