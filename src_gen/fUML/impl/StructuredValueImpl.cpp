#include "StructuredValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "InstanceValue.hpp"
#include "UmlFactory.hpp"
#include "Slot.hpp"
#include "Classifier.hpp"
#include "NamedElement.hpp"
#include "InstanceSpecification.hpp"

#include "FUMLFactory.hpp"
#include "StructuralFeature.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
StructuredValueImpl::StructuredValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

StructuredValueImpl::~StructuredValueImpl()
{
	
}

StructuredValueImpl::StructuredValueImpl(const StructuredValueImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  StructuredValueImpl::copy() const
{
	return new StructuredValueImpl(*this);
}

ecore::EClass* StructuredValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getStructuredValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void StructuredValueImpl::assignFeatureValue(uml::StructuralFeature *  feature,std::vector<fUML::Value * > *  values,int position) 
{
	//generated from body annotation
	
}

void StructuredValueImpl::createFeatureValues() 
{
	//generated from body annotation
	 std::vector<uml::Classifier *>  * types = this->getTypes();

    if(types!= nullptr)
    {
                for(unsigned int i = 0; i < types->size(); i++)
                    {
                    uml::Classifier  * type = types->at(i);
                    std::vector<uml::NamedElement *> * members = type->getMember();

                    for(unsigned int j = 0; j < members->size(); j++)
                        {
                        uml::NamedElement* member = members->at(j);
                        if(dynamic_cast< uml::StructuralFeature * >(member) != nullptr)
                            {
                            this->assignFeatureValue(dynamic_cast<uml::StructuralFeature * >(member), new std::vector<fUML::Value*>(), 0);
                            }
                        }
                    }
    }

}

fUML::FeatureValue *  StructuredValueImpl::retrieveFeatureValue(uml::StructuralFeature *  feature) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<fUML::FeatureValue * > *  StructuredValueImpl::retrieveFeatureValues() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::ValueSpecification *  StructuredValueImpl::specify() 
{
	//generated from body annotation
	    uml::InstanceValue  * instanceValue = uml::UmlFactory::eInstance()->createInstanceValue();
    uml::InstanceSpecification * instance = uml::UmlFactory::eInstance()->createInstanceSpecification();

    instanceValue->setType(nullptr);
    instanceValue->setInstance(instance);

    instance->getClassifier();//->push_back(this->getTypes());

    std::vector<FeatureValue*> * featureValues = this->retrieveFeatureValues();
    // Debug.println("[specify] " + featureValues.size() + " feature(s).");

    for(unsigned int i = 0; i < featureValues->size(); i++)
    {
        FeatureValue * featureValue = featureValues->at(i);

        uml::Slot * slot = uml::UmlFactory::eInstance()->createSlot();
        slot->setDefiningFeature(featureValue->getFeature());

        // Debug.println("[specify] feature = " + featureValue.feature.name
        // + ", " + featureValue.values.size() + " value(s).");

        std::vector<Value *> * values = featureValue->getValues();
        for(unsigned int j = 0; j < values->size(); j++)
        {
            Value * value = values->at(j);
            // Debug.println("[specify] value = " + value);
            slot->getValue()->push_back(value->specify());
        }

        instance->getSlot()->push_back(slot);
    }

    return instanceValue;
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any StructuredValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}
