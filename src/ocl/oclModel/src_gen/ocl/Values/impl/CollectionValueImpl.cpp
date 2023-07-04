
#include "ocl/Values/impl/CollectionValueImpl.hpp"
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
#include <stdexcept>
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
#include "ocl/Values/ValuesFactory.hpp"
#include "ocl/Values/Element.hpp"
#include "ocl/Values/StaticValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"

using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************
CollectionValueImpl::CollectionValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollectionValueImpl::~CollectionValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollectionValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CollectionValueImpl::CollectionValueImpl(const CollectionValueImpl & obj): CollectionValueImpl()
{
	*this = obj;
}

CollectionValueImpl& CollectionValueImpl::operator=(const CollectionValueImpl & obj)
{
	//call overloaded =Operator for each base class
	StaticValueImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CollectionValue 
	 * which is generated by the compiler (as CollectionValue is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CollectionValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollectionValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_elements  = obj.getElements();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CollectionValueImpl::copy() const
{
	std::shared_ptr<CollectionValueImpl> element(new CollectionValueImpl());
	*element =(*this);
	element->setThisCollectionValuePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool CollectionValueImpl::addValue(const std::shared_ptr<fUML::Semantics::Values::Value>& value)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool CollectionValueImpl::equals(const std::shared_ptr<fUML::Semantics::Values::Value>& otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	 if(otherValue != nullptr)
    {
        std::shared_ptr<ocl::Values::CollectionValue> otherBag = std::dynamic_pointer_cast<ocl::Values::CollectionValue>(otherValue);

	if(otherBag != nullptr && otherBag->getElements()->size() == this->getElements()->size())
	{
           for(size_t i = 0; i < this->getElements()->size(); i++) {
                auto item1 = this->getElements()->at(i)->getValue();
                auto item2 = otherBag->getElements()->at(i)->getValue();
                
                if(!item1->equals(item2)) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
	//end of body
}

bool CollectionValueImpl::find(const std::shared_ptr<fUML::Semantics::Values::Value>& value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (Bag<ocl::Values::Element>::const_iterator it_elem = this->getElements()->begin(); it_elem != this->getElements()->end(); ++it_elem)
    {
        if ((*it_elem)->getValue()->equals(value)) {
            return true;
        }
    }
    return false;
	//end of body
}

std::string CollectionValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::string result = "";

Bag<Element>::const_iterator endIt_elem = this->getElements()->end();
for (Bag<Element>::const_iterator it_reference = this->getElements()->begin();
	 it_reference != endIt_elem; ++it_reference)
{
       if(!result.empty()) {
            result += "\n";
        }
	result += (*it_reference)->getValue()->toString();
}
return result;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference elements */
const std::shared_ptr<Bag<ocl::Values::Element>>& CollectionValueImpl::getElements() const
{
	if(m_elements == nullptr)
	{
		m_elements.reset(new Bag<ocl::Values::Element>());
		
		
	}
    return m_elements;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CollectionValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CollectionValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollectionValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("elements");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("elements")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	StaticValueImpl::loadAttributes(loadHandler, attr_list);
}

void CollectionValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	StaticValueImpl::loadNode(nodeName, loadHandler);
}

void CollectionValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_ELEMENTS:
		{
			const std::shared_ptr<Bag<ocl::Values::Element>>& _elements = getElements();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Values::Element>  _r = std::dynamic_pointer_cast<ocl::Values::Element>(ref);
				if (_r != nullptr)
				{
					_elements->push_back(_r);
				}
			}
			return;
		}
	}
	StaticValueImpl::resolveReferences(featureID, references);
}

void CollectionValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StaticValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CollectionValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Values::ValuesPackage> package = ocl::Values::ValuesPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Values::Element>("elements", this->getElements());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& CollectionValueImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getCollectionValue_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CollectionValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_ELEMENTS:
			return eAnyBag(getElements(),ocl::Values::ValuesPackage::ELEMENT_CLASS); //220
	}
	return StaticValueImpl::eGet(featureID, resolve, coreType);
}

bool CollectionValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_ELEMENTS:
			return getElements() != nullptr; //220
	}
	return StaticValueImpl::internalEIsSet(featureID);
}

bool CollectionValueImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_ELEMENTS:
		{
			// CAST Any to Bag<ocl::Values::Element>
			if((newValue->isContainer()) && (ocl::Values::ValuesPackage::ELEMENT_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ocl::Values::Element>> elementsList= newValue->get<std::shared_ptr<Bag<ocl::Values::Element>>>();
					std::shared_ptr<Bag<ocl::Values::Element>> _elements=getElements();
					for(const std::shared_ptr<ocl::Values::Element> indexElements: *_elements)
					{
						if (!(elementsList->includes(indexElements)))
						{
							_elements->erase(indexElements);
						}
					}

					for(const std::shared_ptr<ocl::Values::Element> indexElements: *elementsList)
					{
						if (!(_elements->includes(indexElements)))
						{
							_elements->add(indexElements);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
	}

	return StaticValueImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CollectionValueImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// ocl::Values::CollectionValue::addValue(fUML::Semantics::Values::Value) : bool: 2527489752
		case ValuesPackage::COLLECTIONVALUE_OPERATION_ADDVALUE_VALUE:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->addValue(incoming_param_value),0,false);
			break;
		}
		// ocl::Values::CollectionValue::equals(fUML::Semantics::Values::Value) : bool: 4237584245
		case ValuesPackage::COLLECTIONVALUE_OPERATION_EQUALS_VALUE:
		{
			//Retrieve input parameter 'otherValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_otherValue;
			std::list<Any>::const_iterator incoming_param_otherValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_otherValue = (*incoming_param_otherValue_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->equals(incoming_param_otherValue),0,false);
			break;
		}
		// ocl::Values::CollectionValue::find(fUML::Semantics::Values::Value) : bool: 844392547
		case ValuesPackage::COLLECTIONVALUE_OPERATION_FIND_VALUE:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->find(incoming_param_value),0,false);
			break;
		}
		// ocl::Values::CollectionValue::toString() : std::string: 744572618
		case ValuesPackage::COLLECTIONVALUE_OPERATION_TOSTRING:
		{
			result = eAny(this->toString(),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = StaticValueImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Values::CollectionValue> CollectionValueImpl::getThisCollectionValuePtr() const
{
	return m_thisCollectionValuePtr.lock();
}
void CollectionValueImpl::setThisCollectionValuePtr(std::weak_ptr<ocl::Values::CollectionValue> thisCollectionValuePtr)
{
	m_thisCollectionValuePtr = thisCollectionValuePtr;
	setThisStaticValuePtr(thisCollectionValuePtr);
}


