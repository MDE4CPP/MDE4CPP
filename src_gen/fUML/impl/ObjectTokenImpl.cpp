#include "fUML/impl/ObjectTokenImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
 #include "fUML/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/Token.hpp"

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
ObjectTokenImpl::ObjectTokenImpl()
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

ObjectTokenImpl::~ObjectTokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectToken "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ObjectTokenImpl::ObjectTokenImpl(const ObjectTokenImpl & obj):ObjectTokenImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectToken "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_withdrawn = obj.isWithdrawn();

	//copy references with no containment (soft copy)
	
	m_holder  = obj.getHolder();


	//Clone references with containment (deep copy)

	if(obj.getValue()!=nullptr)
	{
		m_value = std::dynamic_pointer_cast<fUML::Value>(obj.getValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_value" << std::endl;
	#endif

	
}

std::shared_ptr<ecore::EObject>  ObjectTokenImpl::copy() const
{
	std::shared_ptr<ObjectTokenImpl> element(new ObjectTokenImpl(*this));
	element->setThisObjectTokenPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ObjectTokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObjectToken_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ObjectTokenImpl::equals(std::shared_ptr<fUML::Token>  other) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (this == other.get());
	//end of body
}

bool ObjectTokenImpl::isControl() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return false;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Value > ObjectTokenImpl::getValue() const
{

    return m_value;
}
void ObjectTokenImpl::setValue(std::shared_ptr<fUML::Value> _value)
{
    m_value = _value;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ObjectToken> ObjectTokenImpl::getThisObjectTokenPtr()
{
	return m_thisObjectTokenPtr.lock();
}
void ObjectTokenImpl::setThisObjectTokenPtr(std::weak_ptr<ObjectToken> thisObjectTokenPtr)
{
	m_thisObjectTokenPtr = thisObjectTokenPtr;
	setThisTokenPtr(thisObjectTokenPtr);
}
std::shared_ptr<ecore::EObject> ObjectTokenImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ObjectTokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::OBJECTTOKEN_EREFERENCE_VALUE:
			return getValue(); //542
	}
	return TokenImpl::internalEIsSet(featureID);
}
bool ObjectTokenImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::OBJECTTOKEN_EREFERENCE_VALUE:
			return getValue() != nullptr; //542
	}
	return TokenImpl::internalEIsSet(featureID);
}
bool ObjectTokenImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::OBJECTTOKEN_EREFERENCE_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Value> _value = boost::any_cast<std::shared_ptr<fUML::Value>>(newValue);
			setValue(_value); //542
			return true;
		}
	}

	return TokenImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ObjectTokenImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectTokenImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	TokenImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectTokenImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("value") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<fUML::Value> value = std::dynamic_pointer_cast<fUML::Value>(modelFactory->create(typeName));
			if (value != nullptr)
			{
				this->setValue(value);
				loadHandler->handleChild(value);
			}
			return;
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

	TokenImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ObjectTokenImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	TokenImpl::resolveReferences(featureID, references);
}

void ObjectTokenImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TokenImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ObjectTokenImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'value'
		std::shared_ptr<fUML::Value > value = this->getValue();
		if (value != nullptr)
		{
			saveHandler->addReference(value, "value", value->eClass() != package->getValue_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

