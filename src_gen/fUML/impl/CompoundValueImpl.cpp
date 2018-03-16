#include "fUML/impl/CompoundValueImpl.hpp"

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
#include "uml/Classifier.hpp"
#include <fuml/FUMLFactory.hpp>
#include <cstdio>

#include "uml/StructuralFeature.hpp"

//Forward declaration includes
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Classifier.hpp"

#include "fUML/FeatureValue.hpp"

#include "uml/StructuralFeature.hpp"

#include "fUML/StructuredValue.hpp"

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
CompoundValueImpl::CompoundValueImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_featureValues.reset(new Bag<fUML::FeatureValue>());
	
	

	//Init references
	
	
}

CompoundValueImpl::~CompoundValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CompoundValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CompoundValueImpl::CompoundValueImpl(const CompoundValueImpl & obj):CompoundValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CompoundValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

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

std::shared_ptr<ecore::EObject>  CompoundValueImpl::copy() const
{
	std::shared_ptr<CompoundValueImpl> element(new CompoundValueImpl(*this));
	element->setThisCompoundValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CompoundValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCompoundValue_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CompoundValueImpl::assignFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Value> >  values,int position) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::FeatureValue> featureValue = this->retrieveFeatureValue(feature);
    if(featureValue == nullptr)
    {
        featureValue = FUMLFactory::eInstance()->createFeatureValue();
        this->getFeatureValues()->push_back(featureValue);
    }
    featureValue->setFeature(feature);
    std::vector<std::shared_ptr<fUML::Value>>::iterator i;
    for(i=values->begin();i!=values->end();++i)
    {
    	featureValue->getValues()->push_back(*i);
    }
    featureValue->setPosition(position);
	//end of body
}

bool CompoundValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<CompoundValue> otherCompoundValue = std::dynamic_pointer_cast<CompoundValue>(otherValue);
	bool isEqual = (otherCompoundValue != nullptr);
    if (isEqual)
    {
        isEqual = StructuredValueImpl::equals(otherValue)
                && otherCompoundValue->getFeatureValues()->size() == this->getFeatureValues()->size();

        unsigned int i = 0;
        while (isEqual && i < this->getFeatureValues()->size())
        {
        	std::shared_ptr<FeatureValue> thisFeatureValue = this->getFeatureValues()->at(i);

            bool matched = false;
            unsigned int j = 0;
            while (!matched && j < otherCompoundValue->getFeatureValues()->size())
            {
            	std::shared_ptr<FeatureValue> otherFeatureValue = otherCompoundValue->getFeatureValues()->at(j);
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

void CompoundValueImpl::removeFeatureValues(std::shared_ptr<uml::Classifier>  classifier) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::remove_if(this->getFeatureValues()->begin(),this->getFeatureValues()->end(),[classifier](std::shared_ptr<FeatureValue> featureValue){return featureValue->getFeature()->getType()==classifier;});
	//end of body
}

std::shared_ptr<fUML::FeatureValue> CompoundValueImpl::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<fUML::FeatureValue> featureValue = nullptr;
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

std::shared_ptr<Bag<fUML::FeatureValue> > CompoundValueImpl::retrieveFeatureValues() 
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
    	std::shared_ptr<FeatureValue> featureValue = this->getFeatureValues()->at(k);
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
std::shared_ptr<Bag<fUML::FeatureValue>> CompoundValueImpl::getFeatureValues() const
{

    return m_featureValues;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<CompoundValue> CompoundValueImpl::getThisCompoundValuePtr()
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
boost::any CompoundValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_EREFERENCE_FEATUREVALUES:
			return getFeatureValues(); //130
	}
	return StructuredValueImpl::internalEIsSet(featureID);
}
bool CompoundValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_EREFERENCE_FEATUREVALUES:
			return getFeatureValues() != nullptr; //130
	}
	return StructuredValueImpl::internalEIsSet(featureID);
}
bool CompoundValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}

	return StructuredValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CompoundValueImpl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
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

void CompoundValueImpl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StructuredValueImpl::loadAttributes(loadHandler, attr_list);
}

void CompoundValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
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
			std::shared_ptr<fUML::FeatureValue> featureValues = std::dynamic_pointer_cast<fUML::FeatureValue>(modelFactory->create(typeName));
			if (featureValues != nullptr)
			{
				std::shared_ptr<Bag<fUML::FeatureValue>> list_featureValues = this->getFeatureValues();
				list_featureValues->push_back(featureValues);
				loadHandler->handleChild(featureValues);
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

	StructuredValueImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void CompoundValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	StructuredValueImpl::resolveReferences(featureID, references);
}

void CompoundValueImpl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredValueImpl::saveContent(saveHandler);
	
	ValueImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void CompoundValueImpl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'featureValues'
		std::shared_ptr<Bag<fUML::FeatureValue>> list_featureValues = this->getFeatureValues();
		for (std::shared_ptr<fUML::FeatureValue> featureValues : *list_featureValues) 
		{
			saveHandler->addReference(featureValues, "featureValues", featureValues->eClass() != package->getFeatureValue_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

