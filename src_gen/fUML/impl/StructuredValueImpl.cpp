#include "StructuredValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "InstanceValue.hpp"
#include "UmlFactory.hpp"
#include "Slot.hpp"
#include "Classifier.hpp"
#include "NamedElement.hpp"
#include "InstanceSpecification.hpp"

#include "FUMLFactory.hpp"
#include "StructuralFeature.hpp"


//Forward declaration includes
#include "FeatureValue.hpp"

#include "StructuralFeature.hpp"

#include "Value.hpp"

#include "ValueSpecification.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
StructuredValueImpl::StructuredValueImpl()
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
	std::shared_ptr<ecore::EObject> element(new StructuredValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> StructuredValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getStructuredValue();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void StructuredValueImpl::assignFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Value> >  values,int position) 
{
	//generated from body annotation
	
	//end of body
}

void StructuredValueImpl::createFeatureValues() 
{
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
    				std::shared_ptr<Bag<fUML::Value> > valueList(new Bag<fUML::Value>());
    				this->assignFeatureValue(structuralFeature, valueList, 0);
    			}
    		}
    	}
    }
	//end of body
}

std::shared_ptr<fUML::FeatureValue> StructuredValueImpl::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<fUML::FeatureValue> > StructuredValueImpl::retrieveFeatureValues() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::ValueSpecification> StructuredValueImpl::specify() 
{
	//generated from body annotation
		std::shared_ptr<uml::InstanceValue> instanceValue = uml::UmlFactory::eInstance()->createInstanceValue_in_Namespace(std::shared_ptr<uml::Class>());
	std::shared_ptr<uml::InstanceSpecification> instance = uml::UmlFactory::eInstance()->createInstanceSpecification_in_Namespace(std::shared_ptr<uml::Class>());

    instanceValue->setType(nullptr);
    instanceValue->setInstance(instance);

    instance->getClassifier();//->push_back(this->getTypes());

    std::shared_ptr<Bag<FeatureValue> > featureValues = this->retrieveFeatureValues();
    // Debug.println("[specify] " + featureValues.size() + " feature(s).");

    for(unsigned int i = 0; i < featureValues->size(); i++)
    {
    	std::shared_ptr<FeatureValue> featureValue = featureValues->at(i);

    	std::shared_ptr<uml::Slot> slot = uml::UmlFactory::eInstance()->createSlot_in_OwningInstance(std::shared_ptr<uml::InstanceSpecification>());
        slot->setDefiningFeature(featureValue->getFeature());

        // Debug.println("[specify] feature = " + featureValue.feature.name
        // + ", " + featureValue.values.size() + " value(s).");

        std::shared_ptr<Bag<Value> > values = featureValue->getValues();
        for(unsigned int j = 0; j < values->size(); j++)
        {
        	std::shared_ptr<Value> value = values->at(j);
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
