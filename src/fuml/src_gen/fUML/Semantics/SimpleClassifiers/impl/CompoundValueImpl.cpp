#include "fUML/Semantics/SimpleClassifiers/impl/CompoundValueImpl.hpp"

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
#include <algorithm>
#include "uml/Classifier.hpp"
#include <fUML/FUMLFactory.hpp>
#include <cstdio>

#include "uml/StructuralFeature.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"


#include "uml/Classifier.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "uml/StructuralFeature.hpp"
#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CompoundValueImpl::CompoundValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CompoundValueImpl::~CompoundValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CompoundValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CompoundValueImpl::CompoundValueImpl(const CompoundValueImpl & obj): CompoundValueImpl()
{
	*this = obj;
}

CompoundValueImpl& CompoundValueImpl::operator=(const CompoundValueImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuredValueImpl::operator=(obj);
	CompoundValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CompoundValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValuesContainer = getFeatureValues();
	if(nullptr != featureValuesContainer )
	{
		int size = featureValuesContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _featureValues=(*featureValuesContainer)[i];
			if(nullptr != _featureValues)
			{
				featureValuesContainer->push_back(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue>(_featureValues->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container featureValues."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr featureValues."<< std::endl;)
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> CompoundValueImpl::copy() const
{
	std::shared_ptr<CompoundValueImpl> element(new CompoundValueImpl());
	*element =(*this);
	element->setThisCompoundValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CompoundValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getCompoundValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> CompoundValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new data value with the same featureValues as this data value.

std::shared_ptr<fUML::Semantics::SimpleClassifiers::CompoundValue> newValue(new fUML::Semantics::SimpleClassifiers::CompoundValueImpl());

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues = this->retrieveFeatureValues();
unsigned int featureValuesSize = featureValues->size();

for(unsigned int i = 0; i < featureValuesSize; i++)
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = featureValues->at(i);
	newValue->getFeatureValues()->add(featureValue);
}

return newValue;

	//end of body
}

void CompoundValueImpl::assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values,int position)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = this->retrieveFeatureValue(feature);
    if(featureValue == nullptr)
    {
        featureValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createFeatureValue();
        this->getFeatureValues()->push_back(featureValue);
    }
    featureValue->setFeature(feature);
    std::vector<std::shared_ptr<fUML::Semantics::Values::Value>>::iterator i;
    for(i=values->begin();i!=values->end();++i)
    {
    	featureValue->getValues()->push_back(*i);
    }
    featureValue->setPosition(position);
	//end of body
}

bool CompoundValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::CompoundValue> otherCompoundValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::CompoundValue>(otherValue);
	bool isEqual = (otherCompoundValue != nullptr);
	
    if (isEqual)
    {
        isEqual = fUML::Semantics::SimpleClassifiers::StructuredValueImpl::equals(otherValue)
                && otherCompoundValue->retrieveFeatureValues()->size() == this->retrieveFeatureValues()->size();

        unsigned int i = 0;
        while (isEqual && i < this->retrieveFeatureValues()->size())
        {
        	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> thisFeatureValue = this->retrieveFeatureValues()->at(i);

            bool matched = false;
            unsigned int j = 0;
            while (!matched && j < otherCompoundValue->retrieveFeatureValues()->size())
            {
            	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> otherFeatureValue = otherCompoundValue->retrieveFeatureValues()->at(j);		
				
                if (thisFeatureValue->getFeature() == otherFeatureValue->getFeature())
                {
                    matched = thisFeatureValue->hasEqualValues(otherFeatureValue);
                }
                j = j + 1;
            }

            isEqual = matched;
            i = i + 1;
        }
    }
	
    return isEqual;
	//end of body
}

void CompoundValueImpl::removeFeatureValues(std::shared_ptr<uml::Classifier> classifier)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::remove_if(this->getFeatureValues()->begin(),this->getFeatureValues()->end(),[classifier](std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue){return featureValue->getFeature()->getType()==classifier;});
	//end of body
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> CompoundValueImpl::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = nullptr;
    unsigned int i = 0;
    while(featureValue == nullptr && i < this->getFeatureValues()->size())
    {
        if(this->getFeatureValues()->at(i)->getFeature() == feature)
        {
            featureValue = this->getFeatureValues()->at(i);
        }
        i = i + 1;
    }
    return featureValue;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > CompoundValueImpl::retrieveFeatureValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	 return this->getFeatureValues();
	//end of body
}

std::string CompoundValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::string buffer = "(" + this->objectId() + ":";

	std::shared_ptr<Bag<uml::Classifier> > types = this->getTypes();

    unsigned int i = 0;
    while(i < types->size())
    {
        buffer = buffer + " " + types->at(i)->getName();
        i = i + 1;
    }

    unsigned int k = 0;
    while(k < this->getFeatureValues()->size())
    {
    	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = this->getFeatureValues()->at(k);
        char buf [11];
        std::sprintf(buf, "%d", featureValue->getPosition());
        buffer = buffer + "\n\t\t" + featureValue->getFeature()->getName() + "[" + std::string(buf) + "]  =";

        unsigned int j = 0;
        while(j < featureValue->getValues()->size())
        {
            buffer = buffer + " " + featureValue->getValues()->at(j)->toString();
            j = j + 1;
        }

        k = k + 1;
    }

    return buffer + ")";
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference featureValues
*/
std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> CompoundValueImpl::getFeatureValues() const
{
	if(m_featureValues == nullptr)
	{
		m_featureValues.reset(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
		
		
	}

    return m_featureValues;
}



//*********************************
// Union Getter
//*********************************



std::shared_ptr<CompoundValue> CompoundValueImpl::getThisCompoundValuePtr() const
{
	return m_thisCompoundValuePtr.lock();
}
void CompoundValueImpl::setThisCompoundValuePtr(std::weak_ptr<CompoundValue> thisCompoundValuePtr)
{
	m_thisCompoundValuePtr = thisCompoundValuePtr;
	setThisStructuredValuePtr(thisCompoundValuePtr);
}
std::shared_ptr<ecore::EObject> CompoundValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CompoundValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::COMPOUNDVALUE_ATTRIBUTE_FEATUREVALUES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>::iterator iter = m_featureValues->begin();
			Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>::iterator end = m_featureValues->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //290
		}
	}
	return StructuredValueImpl::eGet(featureID, resolve, coreType);
}
bool CompoundValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::COMPOUNDVALUE_ATTRIBUTE_FEATUREVALUES:
			return getFeatureValues() != nullptr; //290
	}
	return StructuredValueImpl::internalEIsSet(featureID);
}
bool CompoundValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::COMPOUNDVALUE_ATTRIBUTE_FEATUREVALUES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValuesList(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				featureValuesList->add(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>::iterator iterFeatureValues = m_featureValues->begin();
			Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>::iterator endFeatureValues = m_featureValues->end();
			while (iterFeatureValues != endFeatureValues)
			{
				if (featureValuesList->find(*iterFeatureValues) == -1)
				{
					m_featureValues->erase(*iterFeatureValues);
				}
				iterFeatureValues++;
			}
 
			iterFeatureValues = featureValuesList->begin();
			endFeatureValues = featureValuesList->end();
			while (iterFeatureValues != endFeatureValues)
			{
				if (m_featureValues->find(*iterFeatureValues) == -1)
				{
					m_featureValues->add(*iterFeatureValues);
				}
				iterFeatureValues++;			
			}
			return true;
		}
	}

	return StructuredValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CompoundValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CompoundValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StructuredValueImpl::loadAttributes(loadHandler, attr_list);
}

void CompoundValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("featureValues") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "FeatureValue";
			}
			loadHandler->handleChildContainer<fUML::Semantics::SimpleClassifiers::FeatureValue>(this->getFeatureValues());  

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
	StructuredValueImpl::loadNode(nodeName, loadHandler);
}

void CompoundValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	StructuredValueImpl::resolveReferences(featureID, references);
}

void CompoundValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void CompoundValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> package = fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'featureValues'

		saveHandler->addReferences<fUML::Semantics::SimpleClassifiers::FeatureValue>("featureValues", this->getFeatureValues());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

