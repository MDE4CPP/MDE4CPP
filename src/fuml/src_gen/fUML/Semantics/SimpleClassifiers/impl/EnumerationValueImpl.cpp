
#include "fUML/Semantics/SimpleClassifiers/impl/EnumerationValueImpl.hpp"
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
#include "uml/Class.hpp"
#include "uml/Enumeration.hpp"
#include "uml/EnumerationLiteral.hpp"
#include "uml/InstanceSpecification.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/umlFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Classifier.hpp"
#include "uml/Enumeration.hpp"
#include "uml/EnumerationLiteral.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
EnumerationValueImpl::EnumerationValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EnumerationValueImpl::~EnumerationValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EnumerationValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


EnumerationValueImpl::EnumerationValueImpl(const EnumerationValueImpl & obj): EnumerationValueImpl()
{
	*this = obj;
}

EnumerationValueImpl& EnumerationValueImpl::operator=(const EnumerationValueImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::ValueImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EnumerationValue 
	 * which is generated by the compiler (as EnumerationValue is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EnumerationValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EnumerationValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_literal  = obj.getLiteral();
	m_type  = obj.getType();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EnumerationValueImpl::copy() const
{
	std::shared_ptr<EnumerationValueImpl> element(new EnumerationValueImpl());
	*element =(*this);
	element->setThisEnumerationValuePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> EnumerationValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new enumeration value with the same literal as this enumeration value.

std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> newValue(new fUML::Semantics::SimpleClassifiers::EnumerationValueImpl());
newValue->setType(this->getType());
newValue->setLiteral(this->getLiteral());
return newValue;
	//end of body
}

bool EnumerationValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	bool isEqual = false;
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> value = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(otherValue);
    if(value != nullptr)
    {
        isEqual = (value->getLiteral() == this->getLiteral());
    }
    return isEqual;
	//end of body
}

std::shared_ptr<Bag<uml::Classifier> > EnumerationValueImpl::getTypes()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());
    types->push_back(std::dynamic_pointer_cast<uml::Classifier>(this->getType()));
    return types;
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> EnumerationValueImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new enumeration value with no literal.
return std::shared_ptr<fUML::Semantics::Values::Value>(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createEnumerationValue());
	//end of body
}

std::shared_ptr<uml::ValueSpecification> EnumerationValueImpl::specify()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::InstanceValue> instanceValue(uml::umlFactory::eInstance()->createInstanceValue_as_ownedMember_in_Namespace(std::shared_ptr<uml::Class>()));
    //Remark: instance is so defined in the specification, but even there is not used.
    //uml::InstanceSpecification * instance = uml::umlFactory::eInstance()->createInstanceSpecification(std::shared_ptr<uml::Class>());

    instanceValue->setType(this->getType());
    instanceValue->setInstance(this->getLiteral());

    return instanceValue;
	//end of body
}

std::string EnumerationValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return this->getLiteral()->getName();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference literal */
std::shared_ptr<uml::EnumerationLiteral> EnumerationValueImpl::getLiteral() const
{
    return m_literal;
}
void EnumerationValueImpl::setLiteral(std::shared_ptr<uml::EnumerationLiteral> _literal)
{
    m_literal = _literal;
	
}

/* Getter & Setter for reference type */
std::shared_ptr<uml::Enumeration> EnumerationValueImpl::getType() const
{
    return m_type;
}
void EnumerationValueImpl::setType(std::shared_ptr<uml::Enumeration> _type)
{
    m_type = _type;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EnumerationValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EnumerationValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EnumerationValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("literal");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("literal")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("type");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("type")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Values::ValueImpl::loadAttributes(loadHandler, attr_list);
}

void EnumerationValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::ValueImpl::loadNode(nodeName, loadHandler);
}

void EnumerationValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::ENUMERATIONVALUE_ATTRIBUTE_LITERAL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::EnumerationLiteral> _literal = std::dynamic_pointer_cast<uml::EnumerationLiteral>( references.front() );
				setLiteral(_literal);
			}
			
			return;
		}

		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::ENUMERATIONVALUE_ATTRIBUTE_TYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Enumeration> _type = std::dynamic_pointer_cast<uml::Enumeration>( references.front() );
				setType(_type);
			}
			
			return;
		}
	}
	fUML::Semantics::Values::ValueImpl::resolveReferences(featureID, references);
}

void EnumerationValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EnumerationValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> package = fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getLiteral(), "literal", getLiteral()->eClass() != uml::umlPackage::eInstance()->getEnumerationLiteral_Class()); 
		saveHandler->addReference(this->getType(), "type", getType()->eClass() != uml::umlPackage::eInstance()->getEnumeration_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> EnumerationValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getEnumerationValue_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EnumerationValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::ENUMERATIONVALUE_ATTRIBUTE_LITERAL:
			return eAny(getLiteral(),uml::umlPackage::ENUMERATIONLITERAL_CLASS,false); //410
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::ENUMERATIONVALUE_ATTRIBUTE_TYPE:
			return eAny(getType(),uml::umlPackage::ENUMERATION_CLASS,false); //411
	}
	return fUML::Semantics::Values::ValueImpl::eGet(featureID, resolve, coreType);
}

bool EnumerationValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::ENUMERATIONVALUE_ATTRIBUTE_LITERAL:
			return getLiteral() != nullptr; //410
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::ENUMERATIONVALUE_ATTRIBUTE_TYPE:
			return getType() != nullptr; //411
	}
	return fUML::Semantics::Values::ValueImpl::internalEIsSet(featureID);
}

bool EnumerationValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::ENUMERATIONVALUE_ATTRIBUTE_LITERAL:
		{
			// CAST Any to uml::EnumerationLiteral
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::EnumerationLiteral> _literal = std::dynamic_pointer_cast<uml::EnumerationLiteral>(_temp);
			setLiteral(_literal); //410
			return true;
		}
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::ENUMERATIONVALUE_ATTRIBUTE_TYPE:
		{
			// CAST Any to uml::Enumeration
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Enumeration> _type = std::dynamic_pointer_cast<uml::Enumeration>(_temp);
			setType(_type); //411
			return true;
		}
	}

	return fUML::Semantics::Values::ValueImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EnumerationValueImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::SimpleClassifiers::EnumerationValue::_copy() : fUML::Semantics::Values::Value: 412360958
		case SimpleClassifiersPackage::ENUMERATIONVALUE_OPERATION__COPY:
		{
			result = eAnyObject(this->_copy(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::EnumerationValue::equals(fUML::Semantics::Values::Value) : bool: 594639323
		case SimpleClassifiersPackage::ENUMERATIONVALUE_OPERATION_EQUALS_VALUE:
		{
			//Retrieve input parameter 'otherValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_otherValue;
			std::list<Any>::const_iterator incoming_param_otherValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_otherValue = (*incoming_param_otherValue_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->equals(incoming_param_otherValue),0,false);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::EnumerationValue::getTypes() : uml::Classifier[*]: 1927916094
		case SimpleClassifiersPackage::ENUMERATIONVALUE_OPERATION_GETTYPES:
		{
			std::shared_ptr<Bag<uml::Classifier> > resultList = this->getTypes();
			return eAnyBag(resultList,uml::umlPackage::CLASSIFIER_CLASS);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::EnumerationValue::new_() : fUML::Semantics::Values::Value: 2131877013
		case SimpleClassifiersPackage::ENUMERATIONVALUE_OPERATION_NEW_:
		{
			result = eAnyObject(this->new_(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::EnumerationValue::specify() : uml::ValueSpecification: 2045018959
		case SimpleClassifiersPackage::ENUMERATIONVALUE_OPERATION_SPECIFY:
		{
			result = eAnyObject(this->specify(), uml::umlPackage::VALUESPECIFICATION_CLASS);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::EnumerationValue::toString() : std::string: 3964346320
		case SimpleClassifiersPackage::ENUMERATIONVALUE_OPERATION_TOSTRING:
		{
			result = eAny(this->toString(),0,false);
			break;
		}

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

std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> EnumerationValueImpl::getThisEnumerationValuePtr() const
{
	return m_thisEnumerationValuePtr.lock();
}
void EnumerationValueImpl::setThisEnumerationValuePtr(std::weak_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> thisEnumerationValuePtr)
{
	m_thisEnumerationValuePtr = thisEnumerationValuePtr;
	setThisValuePtr(thisEnumerationValuePtr);
}


