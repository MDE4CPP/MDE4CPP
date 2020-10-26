#include "fUML/Semantics/SimpleClassifiers/impl/StructuredValueImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "fUML/FUMLFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/InstanceSpecification.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Slot.hpp"
#include "uml/StructuralFeature.hpp"
#include "uml/UmlFactory.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"

#include "uml/StructuralFeature.hpp"

#include "fUML/Semantics/Values/Value.hpp"

#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersPackageImpl.hpp"

#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
StructuredValueImpl::StructuredValueImpl()
{	
}

StructuredValueImpl::~StructuredValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuredValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}



StructuredValueImpl::StructuredValueImpl(const StructuredValueImpl & obj):StructuredValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuredValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  StructuredValueImpl::copy() const
{
	std::shared_ptr<StructuredValueImpl> element(new StructuredValueImpl(*this));
	element->setThisStructuredValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StructuredValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getStructuredValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void StructuredValueImpl::assignFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value> >  values,int position)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	//end of body
}

void StructuredValueImpl::createFeatureValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types = this->getTypes();

    if(types!= nullptr)
    {
    	for(unsigned int i = 0; i < types->size(); i++)
    	{
    		std::shared_ptr<uml::Classifier> type = types->at(i);
    		std::shared_ptr<Bag<uml::NamedElement> > members = type->getMember();

    		for(unsigned int j = 0; j < members->size(); j++)
    		{
    			std::shared_ptr<uml::NamedElement> member = members->at(j);
    			std::shared_ptr<uml::StructuralFeature> structuralFeature = std::dynamic_pointer_cast<uml::StructuralFeature>(member);
    			if(structuralFeature != nullptr)
    			{
    				std::shared_ptr<Bag<fUML::Semantics::Values::Value> > valueList(new Bag<fUML::Semantics::Values::Value>());
    				this->assignFeatureValue(structuralFeature, valueList, 0);
    			}
    		}
    	}
    }
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value> > StructuredValueImpl::getValues(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> >  featureValues)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void StructuredValueImpl::removeValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<fUML::Semantics::Values::Value>  value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> StructuredValueImpl::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > StructuredValueImpl::retrieveFeatureValues()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void StructuredValueImpl::setFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value> >  values,int position)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	//end of body
}

std::shared_ptr<uml::ValueSpecification> StructuredValueImpl::specify()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::InstanceValue> instanceValue = uml::UmlFactory::eInstance()->createInstanceValue_in_Namespace(std::shared_ptr<uml::Class>());
	std::shared_ptr<uml::InstanceSpecification> instance = uml::UmlFactory::eInstance()->createInstanceSpecification_in_Namespace(std::shared_ptr<uml::Class>());

    instanceValue->setType(nullptr);
    instanceValue->setInstance(instance);

    instance->getClassifier();//->push_back(this->getTypes());

    std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > featureValues = this->retrieveFeatureValues();
    // Debug.println("[specify] " + featureValues.size() + " feature(s).");

    for(unsigned int i = 0; i < featureValues->size(); i++)
    {
    	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = featureValues->at(i);

    	std::shared_ptr<uml::Slot> slot = uml::UmlFactory::eInstance()->createSlot_in_OwningInstance(std::shared_ptr<uml::InstanceSpecification>());
        slot->setDefiningFeature(featureValue->getFeature());

        // Debug.println("[specify] feature = " + featureValue.feature.name
        // + ", " + featureValue.values.size() + " value(s).");

        std::shared_ptr<Bag<fUML::Semantics::Values::Value> > values = featureValue->getValues();
        for(unsigned int j = 0; j < values->size(); j++)
        {
        	std::shared_ptr<fUML::Semantics::Values::Value> value = values->at(j);
            // Debug.println("[specify] value = " + value);
            slot->getValue()->push_back(value->specify());
        }

        instance->getSlot()->push_back(slot);
    }

    return instanceValue;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<StructuredValue> StructuredValueImpl::getThisStructuredValuePtr() const
{
	return m_thisStructuredValuePtr.lock();
}
void StructuredValueImpl::setThisStructuredValuePtr(std::weak_ptr<StructuredValue> thisStructuredValuePtr)
{
	m_thisStructuredValuePtr = thisStructuredValuePtr;
	setThisValuePtr(thisStructuredValuePtr);
}
std::shared_ptr<ecore::EObject> StructuredValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any StructuredValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::ValueImpl::eGet(featureID, resolve, coreType);
}
bool StructuredValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::ValueImpl::internalEIsSet(featureID);
}
bool StructuredValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Values::ValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void StructuredValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StructuredValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Values::ValueImpl::loadAttributes(loadHandler, attr_list);
}

void StructuredValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory> modelFactory=fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::Values::ValueImpl::loadNode(nodeName, loadHandler);
}

void StructuredValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::ValueImpl::resolveReferences(featureID, references);
}

void StructuredValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void StructuredValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> package = fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

