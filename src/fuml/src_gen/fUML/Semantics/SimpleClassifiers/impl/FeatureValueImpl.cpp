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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "uml/StructuralFeature.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"

#include "uml/StructuralFeature.hpp"

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/SimpleClassifiers/Impl/SimpleClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/Impl/SimpleClassifiersPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
FeatureValueImpl::FeatureValueImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_values.reset(new Bag<fUML::Semantics::Values::Value>());
	
	

	//Init references
	

	
	
}

FeatureValueImpl::~FeatureValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FeatureValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




FeatureValueImpl::FeatureValueImpl(const FeatureValueImpl & obj):FeatureValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FeatureValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_position = obj.getPosition();

	//copy references with no containment (soft copy)
	
	m_feature  = obj.getFeature();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> _valuesList = obj.getValues();
	for(std::shared_ptr<fUML::Semantics::Values::Value> _values : *_valuesList)
	{
		this->getValues()->add(std::shared_ptr<fUML::Semantics::Values::Value>(std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(_values->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_values" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  FeatureValueImpl::copy() const
{
	std::shared_ptr<FeatureValueImpl> element(new FeatureValueImpl(*this));
	element->setThisFeatureValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> FeatureValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getFeatureValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void FeatureValueImpl::setPosition(int _position)
{
	m_position = _position;
} 

int FeatureValueImpl::getPosition() const 
{
	return m_position;
}

//*********************************
// Operations
//*********************************
bool FeatureValueImpl::hasEqualValues(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue>  other)
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
// References
//*********************************
std::shared_ptr<uml::StructuralFeature > FeatureValueImpl::getFeature() const
{
//assert(m_feature);
    return m_feature;
}
void FeatureValueImpl::setFeature(std::shared_ptr<uml::StructuralFeature> _feature)
{
    m_feature = _feature;
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> FeatureValueImpl::getValues() const
{

    return m_values;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<FeatureValue> FeatureValueImpl::getThisFeatureValuePtr() const
{
	return m_thisFeatureValuePtr.lock();
}
void FeatureValueImpl::setThisFeatureValuePtr(std::weak_ptr<FeatureValue> thisFeatureValuePtr)
{
	m_thisFeatureValuePtr = thisFeatureValuePtr;
}
std::shared_ptr<ecore::EObject> FeatureValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any FeatureValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_FEATURE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getFeature())); //552
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_POSITION:
			return eAny(getPosition()); //551
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Values::Value>::iterator iter = m_values->begin();
			Bag<fUML::Semantics::Values::Value>::iterator end = m_values->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //550
		}
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
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StructuralFeature> _feature = std::dynamic_pointer_cast<uml::StructuralFeature>(_temp);
			setFeature(_feature); //552
			return true;
		}
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_POSITION:
		{
			// BOOST CAST
			int _position = newValue->get<int>();
			setPosition(_position); //551
			return true;
		}
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> valuesList(new Bag<fUML::Semantics::Values::Value>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				valuesList->add(std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Values::Value>::iterator iterValues = m_values->begin();
			Bag<fUML::Semantics::Values::Value>::iterator endValues = m_values->end();
			while (iterValues != endValues)
			{
				if (valuesList->find(*iterValues) == -1)
				{
					m_values->erase(*iterValues);
				}
				iterValues++;
			}

			iterValues = valuesList->begin();
			endValues = valuesList->end();
			while (iterValues != endValues)
			{
				if (m_values->find(*iterValues) == -1)
				{
					m_values->add(*iterValues);
				}
				iterValues++;			
			}
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
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
			std::istringstream ( iter->second ) >> value;
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
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory> modelFactory=fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance();

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
			std::shared_ptr<fUML::Semantics::Values::Value> values = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(modelFactory->create(typeName));
			if (values != nullptr)
			{
				std::shared_ptr<Bag<fUML::Semantics::Values::Value>> list_values = this->getValues();
				list_values->push_back(values);
				loadHandler->handleChild(values);
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
	//load BasePackage Nodes
}

void FeatureValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
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
		saveHandler->addReference("feature", this->getFeature());


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'values'
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> list_values = this->getValues();
		for (std::shared_ptr<fUML::Semantics::Values::Value> values : *list_values) 
		{
			saveHandler->addReference(values, "values", values->eClass() !=fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

