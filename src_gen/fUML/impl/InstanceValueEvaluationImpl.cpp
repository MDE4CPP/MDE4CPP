#include "InstanceValueEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "InstanceSpecification.hpp"
#include "InstanceValue.hpp"
#include "Classifier.hpp"
#include "EnumerationLiteral.hpp"
#include "FUMLFactory.hpp"
#include "EnumerationLiteral.hpp"
#include "DataType.hpp"
#include "Object.hpp"
#include "Slot.hpp"
#include "Value.hpp"
#include "StructuralFeature.hpp"
#include "Enumeration.hpp"
#include "Behavior.hpp"
#include "Class.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
InstanceValueEvaluationImpl::InstanceValueEvaluationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

InstanceValueEvaluationImpl::~InstanceValueEvaluationImpl()
{
	
}

InstanceValueEvaluationImpl::InstanceValueEvaluationImpl(const InstanceValueEvaluationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//clone containt lists
}

ecore::EObject *  InstanceValueEvaluationImpl::copy() const
{
	return new InstanceValueEvaluationImpl(*this);
}

ecore::EClass* InstanceValueEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getInstanceValueEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::Value *  InstanceValueEvaluationImpl::evaluate() 
{
	//generated from body annotation
	    uml::InstanceSpecification * instance = (dynamic_cast<uml::InstanceValue * >(this->getSpecification()))->getInstance();
    std::vector< uml::Classifier *>* types = instance->getClassifier();
    uml::Classifier * myType = types->at(0);

    DEBUG_MESSAGE(std::cout<<("[evaluate] type = " + myType->getName())<<std::endl;)

    Value * value;
    if(dynamic_cast<uml::EnumerationLiteral * >(instance) != nullptr)
    {
        EnumerationValue * enumerationValue = FUMLFactory::eInstance()->createEnumerationValue();
        enumerationValue->setType(dynamic_cast<uml::Enumeration  * >(myType));
        enumerationValue->setLiteral(dynamic_cast<uml::EnumerationLiteral * >(instance));
        value = enumerationValue;
    }
    else
    {
        StructuredValue * structuredValue = nullptr;

        if(dynamic_cast<uml::DataType * >(myType) != nullptr)
        {
            // Debug.println("[evaluate] Type is a data type.");
            DataValue * dataValue = FUMLFactory::eInstance()->createDataValue();
            dataValue->setType(dynamic_cast<uml::DataType * >(myType));
            structuredValue = dataValue;
        }
        else
        {
            Object *object = nullptr;
            if(dynamic_cast<uml::Behavior * >(myType) != nullptr)
            {
                // Debug.println("[evaluate] Type is a behavior.");
                object = this->getLocus()->getFactory()->createExecution(dynamic_cast<uml::Behavior*>(myType), nullptr);
            }
            else
            {
                // Debug.println("[evaluate] Type is a class.");
                object = FUMLFactory::eInstance()->createObject();
                for(unsigned int i = 0; i < types->size(); i++)
                {
                    uml::Classifier * type = types->at(i);
                    object->getTypes()->push_back(dynamic_cast<uml::Class * >(type));
                }
            }

            this->getLocus()->add(object);

            Reference * reference = FUMLFactory::eInstance()->createReference();
            reference->setReferent(object);
            structuredValue = reference;
        }

        structuredValue->createFeatureValues();

        std::vector<uml::Slot * > * instanceSlots = instance->getSlot();
        for(unsigned int i = 0; i < instanceSlots->size(); i++)
        {
            uml::Slot * slot = instanceSlots->at(i);
            std::vector<Value *> * values = new std::vector<Value *>();

            std::vector<uml::ValueSpecification * > * slotValues = slot->getValue();
            for(unsigned int j = 0; j < slotValues->size(); j++)
            {
                uml::ValueSpecification * slotValue = slotValues->at(j);
                values->push_back(this->getLocus()->getExecutor()->evaluate(slotValue));
            }
            structuredValue->assignFeatureValue(slot->getDefiningFeature(), values, 0);
        }

        value = structuredValue;
    }

    return value;
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
boost::any InstanceValueEvaluationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_LOCUS:
			return getLocus(); //251
		case FUMLPackage::EVALUATION_SPECIFICATION:
			return getSpecification(); //250
	}
	return boost::any();
}
