#include "fUML/impl/RealValueImpl.hpp"

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
#include <sstream>
#include "fUML/FUMLFactory.hpp"
#include "uml/Class.hpp"
#include "uml/LiteralReal.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/Type.hpp"

//Forward declaration includes
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "uml/PrimitiveType.hpp"

#include "fUML/PrimitiveValue.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"

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
RealValueImpl::RealValueImpl()
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

RealValueImpl::~RealValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RealValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




RealValueImpl::RealValueImpl(const RealValueImpl & obj):RealValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RealValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  RealValueImpl::copy() const
{
	std::shared_ptr<RealValueImpl> element(new RealValueImpl(*this));
	element->setThisRealValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> RealValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getRealValue_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void RealValueImpl::setValue(float _value)
{
	m_value = _value;
} 

float RealValueImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************
bool RealValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool isEqual = false;

    if(otherValue != nullptr && otherValue->eClass()->getClassifierID() == fUML::FUMLPackage::REALVALUE_ECLASS)
    {
		std::shared_ptr<RealValue> otherRealValue = std::dynamic_pointer_cast<RealValue>(otherValue);
        isEqual = (otherRealValue->getValue() == this->getValue());
    }

    return isEqual;
	//end of body
}

std::shared_ptr<uml::ValueSpecification> RealValueImpl::specify() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralReal> literal = uml::UmlFactory::eInstance()->createLiteralReal_in_Namespace(std::shared_ptr<uml::Class>());
	literal->setType(this->getType());
    literal->setValue(this->getValue());
    return literal;
	//end of body
}

std::string RealValueImpl::toString() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::ostringstream o;
     if (!(o << this->getValue()))
       return "";
     return o.str();
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<RealValue> RealValueImpl::getThisRealValuePtr()
{
	return m_thisRealValuePtr.lock();
}
void RealValueImpl::setThisRealValuePtr(std::weak_ptr<RealValue> thisRealValuePtr)
{
	m_thisRealValuePtr = thisRealValuePtr;
	setThisPrimitiveValuePtr(thisRealValuePtr);
}
std::shared_ptr<ecore::EObject> RealValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RealValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::REALVALUE_EATTRIBUTE_VALUE:
			return getValue(); //191
	}
	return PrimitiveValueImpl::internalEIsSet(featureID);
}
bool RealValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::REALVALUE_EATTRIBUTE_VALUE:
			return getValue() != 0; //191
	}
	return PrimitiveValueImpl::internalEIsSet(featureID);
}
bool RealValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::REALVALUE_EATTRIBUTE_VALUE:
		{
			// BOOST CAST
			float _value = boost::any_cast<float>(newValue);
			setValue(_value); //191
			return true;
		}
	}

	return PrimitiveValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void RealValueImpl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
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

void RealValueImpl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'float'
			float value;
			std::istringstream ( iter->second ) >> value;
			this->setValue(value);
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

	PrimitiveValueImpl::loadAttributes(loadHandler, attr_list);
}

void RealValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	PrimitiveValueImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void RealValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	PrimitiveValueImpl::resolveReferences(featureID, references);
}

void RealValueImpl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PrimitiveValueImpl::saveContent(saveHandler);
	
	ValueImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void RealValueImpl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getRealValue_EAttribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

