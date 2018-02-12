#include "fUML/impl/InstanceValueEvaluationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "uml/InstanceSpecification.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/Classifier.hpp"
#include "uml/EnumerationLiteral.hpp"
#include "fuml/FUMLFactory.hpp"
#include "uml/EnumerationLiteral.hpp"
#include "uml/DataType.hpp"
#include "fuml/Object.hpp"
#include "uml/Slot.hpp"
#include "fuml/Value.hpp"
#include "uml/StructuralFeature.hpp"
#include "uml/Enumeration.hpp"
#include "uml/Behavior.hpp"
#include "uml/Class.hpp"

//Forward declaration includes
#include "fUML/Evaluation.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
InstanceValueEvaluationImpl::InstanceValueEvaluationImpl()
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

InstanceValueEvaluationImpl::~InstanceValueEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InstanceValueEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




InstanceValueEvaluationImpl::InstanceValueEvaluationImpl(const InstanceValueEvaluationImpl & obj):InstanceValueEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InstanceValueEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  InstanceValueEvaluationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new InstanceValueEvaluationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> InstanceValueEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getInstanceValueEvaluation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> InstanceValueEvaluationImpl::evaluate() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::InstanceSpecification> instance = (std::dynamic_pointer_cast<uml::InstanceValue>(this->getSpecification()))->getInstance();
	std::shared_ptr<Bag<uml::Classifier> > types = instance->getClassifier();
	std::shared_ptr<uml::Classifier> myType = types->at(0);

    DEBUG_MESSAGE(std::cout<<("[evaluate] type = " + myType->getName())<<std::endl;)

	std::shared_ptr<Value> value;
    std::shared_ptr<uml::EnumerationLiteral> literal = std::dynamic_pointer_cast<uml::EnumerationLiteral>(instance);
    if(literal != nullptr)
    {
    	std::shared_ptr<EnumerationValue> enumerationValue(FUMLFactory::eInstance()->createEnumerationValue());
        enumerationValue->setType(std::dynamic_pointer_cast<uml::Enumeration>(myType));
        enumerationValue->setLiteral(literal);
        value = enumerationValue;
    }
    else
    {
    	std::shared_ptr<StructuredValue> structuredValue = nullptr;
    	std::shared_ptr<uml::DataType> type = std::dynamic_pointer_cast<uml::DataType>(myType);
        if(type != nullptr)
        {
            // Debug.println("[evaluate] Type is a data type.");
        	std::shared_ptr<DataValue> dataValue(FUMLFactory::eInstance()->createDataValue());
            dataValue->setType(type);
            structuredValue = dataValue;
        }
        else
        {
        	std::shared_ptr<Object> object = nullptr;
        	std::shared_ptr<uml::Behavior> behavior = std::dynamic_pointer_cast<uml::Behavior>(myType);
            if(behavior != nullptr)
            {
                // Debug.println("[evaluate] Type is a behavior.");
                object = this->getLocus()->getFactory()->createExecution(behavior, nullptr);
            }
            else
            {
                // Debug.println("[evaluate] Type is a class.");
                object = FUMLFactory::eInstance()->createObject();
                for(unsigned int i = 0; i < types->size(); i++)
                {
                	std::shared_ptr<uml::Classifier> type = types->at(i);
                    object->getTypes()->push_back(std::dynamic_pointer_cast<uml::Class>(type));
                }
            }

            this->getLocus()->add(object);

            std::shared_ptr<Reference> reference(FUMLFactory::eInstance()->createReference());
            reference->setReferent(object);
            structuredValue = reference;
        }

        structuredValue->createFeatureValues();

        std::shared_ptr<Bag<uml::Slot> > instanceSlots = instance->getSlot();
        for(unsigned int i = 0; i < instanceSlots->size(); i++)
        {
        	std::shared_ptr<uml::Slot> slot = instanceSlots->at(i);
        	std::shared_ptr<Bag<Value> > values(new Bag<Value>());

        	std::shared_ptr<Bag<uml::ValueSpecification> > slotValues = slot->getValue();
            for(unsigned int j = 0; j < slotValues->size(); j++)
            {
            	std::shared_ptr<uml::ValueSpecification> slotValue = slotValues->at(j);
                values->push_back(this->getLocus()->getExecutor()->evaluate(slotValue));
            }
            structuredValue->assignFeatureValue(slot->getDefiningFeature(), values, 0);
        }

        value = structuredValue;
    }

    return value;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> InstanceValueEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InstanceValueEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
			return getLocus(); //251
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
			return getSpecification(); //250
	}
	return boost::any();
}

void InstanceValueEvaluationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //251
			break;
		}
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setSpecification(_specification); //250
			break;
		}
	}
}
