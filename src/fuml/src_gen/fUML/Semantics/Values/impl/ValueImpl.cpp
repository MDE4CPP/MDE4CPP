#include "fUML/Semantics/Values/impl/ValueImpl.hpp"

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

//Includes from codegen annotation
#include "abstractDataTypes/Subset.hpp"
#include "uml/Classifier.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Classifier.hpp"

#include "fUML/Semantics/Loci/SemanticVisitor.hpp"

#include "fUML/Semantics/Values/Value.hpp"

#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/Values/impl/ValuesFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************
ValueImpl::ValueImpl()
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

ValueImpl::~ValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Value "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ValueImpl::ValueImpl(const ValueImpl & obj):ValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Value "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ValueImpl::copy() const
{
	std::shared_ptr<ValueImpl> element(new ValueImpl(*this));
	element->setThisValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ValueImpl::eStaticClass() const
{
	return fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ValueImpl::checkAllParents(std::shared_ptr<uml::Classifier>  type,std::shared_ptr<uml::Classifier>  classifier)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value>  otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Classifier> > myTypes = this->getTypes();
	std::shared_ptr<Bag<uml::Classifier> > otherTypes = otherValue->getTypes();

    DEBUG_MESSAGE(std::cout<<"in Value"<<std::endl;)
    bool isEqual = true;

    if(myTypes->size() != otherTypes->size())
    {
        isEqual = false;
    }
    else
    {
        unsigned int i = 0;
        while(isEqual && i < myTypes->size())
        {
            bool matched = false;
            unsigned int j = 0;
            while(!matched && j < otherTypes->size())
            {
                matched = (otherTypes->at(j) == myTypes->at(i));
                j = j + 1;
            }

            isEqual = matched;
            i = i + 1;
        }
    }

    return isEqual;
	//end of body
}

std::shared_ptr<Bag<uml::Classifier> > ValueImpl::getTypes() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ValueImpl::hasTypes(std::shared_ptr<uml::Classifier>  type)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Classifier> > types = this->getTypes();

    bool found = false;
    unsigned int i = 0;
    while(!found && i < types->size())
    {
        found = (types->at(i) == type);
        i = i + 1;
    }

    return found;
	//end of body
}

std::string ValueImpl::objectId()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "SemanticVisitor";//typename(SemanticVisitor); //return super.toString();

	//end of body
}

std::shared_ptr<uml::ValueSpecification> ValueImpl::specify()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string ValueImpl::toString()
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


std::shared_ptr<Value> ValueImpl::getThisValuePtr() const
{
	return m_thisValuePtr.lock();
}
void ValueImpl::setThisValuePtr(std::weak_ptr<Value> thisValuePtr)
{
	m_thisValuePtr = thisValuePtr;
	setThisSemanticVisitorPtr(thisValuePtr);
}
std::shared_ptr<ecore::EObject> ValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::eGet(featureID, resolve, coreType);
}
bool ValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::internalEIsSet(featureID);
}
bool ValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Loci::SemanticVisitorImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Loci::SemanticVisitorImpl::loadAttributes(loadHandler, attr_list);
}

void ValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Values::ValuesFactory> modelFactory=fUML::Semantics::Values::ValuesFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::Loci::SemanticVisitorImpl::loadNode(nodeName, loadHandler);
}

void ValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Loci::SemanticVisitorImpl::resolveReferences(featureID, references);
}

void ValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Values::ValuesPackage> package = fUML::Semantics::Values::ValuesPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

