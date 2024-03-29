
#include "fUML/Semantics/SimpleClassifiers/impl/FeatureValueImpl.hpp"
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
//Includes from codegen annotation
#include "uml/StructuralFeature.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "uml/StructuralFeature.hpp"
#include "fUML/Semantics/Values/Value.hpp"
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
FeatureValueImpl::FeatureValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

FeatureValueImpl::~FeatureValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FeatureValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


FeatureValueImpl::FeatureValueImpl(const FeatureValueImpl & obj): FeatureValueImpl()
{
	*this = obj;
}

FeatureValueImpl& FeatureValueImpl::operator=(const FeatureValueImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of FeatureValue 
	 * which is generated by the compiler (as FeatureValue is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//FeatureValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FeatureValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_position = obj.getPosition();

	//copy references with no containment (soft copy)
	m_feature  = obj.getFeature();
	//Clone references with containment (deep copy)
	//clone reference 'values'
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> valuesList = obj.getValues();
	if(valuesList)
	{
		m_values.reset(new Bag<fUML::Semantics::Values::Value>());
		
		
		for(const std::shared_ptr<fUML::Semantics::Values::Value> valuesindexElem: *valuesList) 
		{
			std::shared_ptr<fUML::Semantics::Values::Value> temp = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>((valuesindexElem)->copy());
			m_values->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr values."<< std::endl;)
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> FeatureValueImpl::copy() const
{
	std::shared_ptr<FeatureValueImpl> element(new FeatureValueImpl());
	*element =(*this);
	element->setThisFeatureValuePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> FeatureValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a copy of this feature value.

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> newValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createFeatureValue();
newValue->setFeature(this->getFeature());
newValue->setPosition(this->getPosition());

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = this->getValues();
unsigned int valuesSize = values->size();

for(unsigned int i = 0; i < valuesSize; i++)
{
	std::shared_ptr<fUML::Semantics::Values::Value> value = values->at(i);
	newValue->getValues()->add(value->_copy());
}

return newValue;
	//end of body
}

bool FeatureValueImpl::hasEqualValues(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> other)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool equal = true;

    if(this->getValues()->size() != other->getValues()->size())
    {
        equal = false;

    }
    else
    {
    	std::shared_ptr<uml::StructuralFeature> feature = this->getFeature();
        if(feature->getIsOrdered())
        {
            unsigned int i = 0;
            while(equal && (i < this->getValues()->size()))
            {
                equal = this->getValues()->at(i)->equals(other->getValues()->at(i));
                i = i + 1;
            }

        }
        else
        {
        	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> otherFeatureValues(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createFeatureValue());
        	std::shared_ptr<Bag<fUML::Semantics::Values::Value> > values = other->getValues();
            for(unsigned int i = 0; i < values->size(); i++)
            {
            	std::shared_ptr<fUML::Semantics::Values::Value> value = values->at(i);
                otherFeatureValues->getValues()->push_back(value);
            }

            unsigned int i = 0;
            while(equal && (i < this->getValues()->size()))
            {
                bool matched = false;
                unsigned int j = 0;
                while(!matched && (j < otherFeatureValues->getValues()->size()))
                {
                    if(this->getValues()->at(i)->equals(otherFeatureValues->getValues()->at(j)))
                    {
                        matched = true;
                        otherFeatureValues->getValues()->erase(otherFeatureValues->getValues()->begin() + j);
                    }
                    j = j + 1;
                }

                equal = matched;
                i = i + 1;
            }
        }
    }

    return equal;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute position */
int FeatureValueImpl::getPosition() const 
{
	return m_position;
}
void FeatureValueImpl::setPosition(int _position)
{
	m_position = _position;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference feature */
std::shared_ptr<uml::StructuralFeature> FeatureValueImpl::getFeature() const
{
    return m_feature;
}
void FeatureValueImpl::setFeature(std::shared_ptr<uml::StructuralFeature> _feature)
{
    m_feature = _feature;
	
}

/* Getter & Setter for reference values */
std::shared_ptr<Bag<fUML::Semantics::Values::Value>> FeatureValueImpl::getValues() const
{
	if(m_values == nullptr)
	{
		m_values.reset(new Bag<fUML::Semantics::Values::Value>());
		
		
	}
    return m_values;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> FeatureValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void FeatureValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void FeatureValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("position");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream(iter->second) >> value;
			this->setPosition(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("feature");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("feature")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void FeatureValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("values") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<fUML::Semantics::Values::Value>(this->getValues());  

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
	//load BasePackage Nodes
}

void FeatureValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_FEATURE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuralFeature> _feature = std::dynamic_pointer_cast<uml::StructuralFeature>( references.front() );
				setFeature(_feature);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void FeatureValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void FeatureValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> package = fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getFeatureValue_Attribute_position()) )
		{
			saveHandler->addAttribute("position", this->getPosition());
		}
	// Add references
		saveHandler->addReference(this->getFeature(), "feature", getFeature()->eClass() != uml::umlPackage::eInstance()->getStructuralFeature_Class()); 
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'values'

		saveHandler->addReferences<fUML::Semantics::Values::Value>("values", this->getValues());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> FeatureValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getFeatureValue_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any FeatureValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_FEATURE:
			return eAny(getFeature(),uml::umlPackage::STRUCTURALFEATURE_CLASS,false); //552
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_POSITION:
			return eAny(getPosition(),ecore::ecorePackage::EINT_CLASS,false); //551
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:
			return eAnyBag(getValues(),fUML::Semantics::Values::ValuesPackage::VALUE_CLASS); //550
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool FeatureValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_FEATURE:
			return getFeature() != nullptr; //552
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_POSITION:
			return getPosition() != 0; //551
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:
			return getValues() != nullptr; //550
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool FeatureValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_FEATURE:
		{
			// CAST Any to uml::StructuralFeature
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StructuralFeature> _feature = std::dynamic_pointer_cast<uml::StructuralFeature>(_temp);
			setFeature(_feature); //552
			return true;
		}
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_POSITION:
		{
			// CAST Any to int
			int _position = newValue->get<int>();
			setPosition(_position); //551
			return true;
		}
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:
		{
			// CAST Any to Bag<fUML::Semantics::Values::Value>
			if((newValue->isContainer()) && (fUML::Semantics::Values::ValuesPackage::VALUE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::Values::Value>> valuesList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::Values::Value>>>();
					std::shared_ptr<Bag<fUML::Semantics::Values::Value>> _values=getValues();
					for(const std::shared_ptr<fUML::Semantics::Values::Value> indexValues: *_values)
					{
						if (valuesList->find(indexValues) == -1)
						{
							_values->erase(indexValues);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::Values::Value> indexValues: *valuesList)
					{
						if (_values->find(indexValues) == -1)
						{
							_values->add(indexValues);
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

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any FeatureValueImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::SimpleClassifiers::FeatureValue::_copy() : fUML::Semantics::SimpleClassifiers::FeatureValue: 3021163793
		case SimpleClassifiersPackage::FEATUREVALUE_OPERATION__COPY:
		{
			result = eAnyObject(this->_copy(), fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_CLASS);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::FeatureValue::hasEqualValues(fUML::Semantics::SimpleClassifiers::FeatureValue) : bool: 2370187995
		case SimpleClassifiersPackage::FEATUREVALUE_OPERATION_HASEQUALVALUES_FEATUREVALUE:
		{
			//Retrieve input parameter 'other'
			//parameter 0
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> incoming_param_other;
			std::list<Any>::const_iterator incoming_param_other_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_other = (*incoming_param_other_arguments_citer)->get<std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> >();
			result = eAny(this->hasEqualValues(incoming_param_other),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> FeatureValueImpl::getThisFeatureValuePtr() const
{
	return m_thisFeatureValuePtr.lock();
}
void FeatureValueImpl::setThisFeatureValuePtr(std::weak_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> thisFeatureValuePtr)
{
	m_thisFeatureValuePtr = thisFeatureValuePtr;
}


