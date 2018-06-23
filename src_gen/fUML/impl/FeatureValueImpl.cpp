#include "fUML/impl/FeatureValueImpl.hpp"

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
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/FUMLFactory.hpp"
#include "uml/StructuralFeature.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/FeatureValue.hpp"

#include "uml/StructuralFeature.hpp"

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
FeatureValueImpl::FeatureValueImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_values.reset(new Bag<fUML::Value>());
	
	

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

	std::shared_ptr<Bag<fUML::Value>> _valuesList = obj.getValues();
	for(std::shared_ptr<fUML::Value> _values : *_valuesList)
	{
		this->getValues()->add(std::shared_ptr<fUML::Value>(std::dynamic_pointer_cast<fUML::Value>(_values->copy())));
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
	return FUMLPackageImpl::eInstance()->getFeatureValue_EClass();
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
bool FeatureValueImpl::hasEqualValues(std::shared_ptr<fUML::FeatureValue>  other) 
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
        	std::shared_ptr<FeatureValue> otherFeatureValues(FUMLFactory::eInstance()->createFeatureValue());
        	std::shared_ptr<Bag<Value> > values = other->getValues();
            for(unsigned int i = 0; i < values->size(); i++)
            {
            	std::shared_ptr<Value> value = values->at(i);
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

std::shared_ptr<Bag<fUML::Value>> FeatureValueImpl::getValues() const
{

    return m_values;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<FeatureValue> FeatureValueImpl::getThisFeatureValuePtr()
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
		case FUMLPackage::FEATUREVALUE_EREFERENCE_FEATURE:
			return eAny(getFeature()); //142
		case FUMLPackage::FEATUREVALUE_EATTRIBUTE_POSITION:
			return eAny(getPosition()); //141
		case FUMLPackage::FEATUREVALUE_EREFERENCE_VALUES:
			return eAny(getValues()); //140
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool FeatureValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::FEATUREVALUE_EREFERENCE_FEATURE:
			return getFeature() != nullptr; //142
		case FUMLPackage::FEATUREVALUE_EATTRIBUTE_POSITION:
			return getPosition() != 0; //141
		case FUMLPackage::FEATUREVALUE_EREFERENCE_VALUES:
			return getValues() != nullptr; //140
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool FeatureValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::FEATUREVALUE_EREFERENCE_FEATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuralFeature> _feature = newValue->get<std::shared_ptr<uml::StructuralFeature>>();
			setFeature(_feature); //142
			return true;
		}
		case FUMLPackage::FEATUREVALUE_EATTRIBUTE_POSITION:
		{
			// BOOST CAST
			int _position = newValue->get<int>();
			setPosition(_position); //141
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
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void FeatureValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
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
			std::shared_ptr<fUML::Value> values = std::dynamic_pointer_cast<fUML::Value>(modelFactory->create(typeName));
			if (values != nullptr)
			{
				std::shared_ptr<Bag<fUML::Value>> list_values = this->getValues();
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

	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void FeatureValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::FEATUREVALUE_EREFERENCE_FEATURE:
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getFeatureValue_EAttribute_position()) )
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
		std::shared_ptr<Bag<fUML::Value>> list_values = this->getValues();
		for (std::shared_ptr<fUML::Value> values : *list_values) 
		{
			saveHandler->addReference(values, "values", values->eClass() != package->getValue_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

