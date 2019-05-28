#include "fUML/impl/InstanceValueEvaluationImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "fUML/DataValue.hpp"
#include "fUML/EnumerationValue.hpp"
#include "fUML/Execution.hpp"
#include "fUML/ExecutionFactory.hpp"
#include "fUML/Executor.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Object.hpp"
#include "fUML/Reference.hpp"
#include "fUML/Value.hpp"
#include "uml/Behavior.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/DataType.hpp"
#include "uml/Enumeration.hpp"
#include "uml/EnumerationLiteral.hpp"
#include "uml/InstanceSpecification.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/Slot.hpp"
#include "uml/StructuralFeature.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/Evaluation.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"

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
	std::shared_ptr<InstanceValueEvaluationImpl> element(new InstanceValueEvaluationImpl(*this));
	element->setThisInstanceValueEvaluationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InstanceValueEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getInstanceValueEvaluation_Class();
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


std::shared_ptr<InstanceValueEvaluation> InstanceValueEvaluationImpl::getThisInstanceValueEvaluationPtr() const
{
	return m_thisInstanceValueEvaluationPtr.lock();
}
void InstanceValueEvaluationImpl::setThisInstanceValueEvaluationPtr(std::weak_ptr<InstanceValueEvaluation> thisInstanceValueEvaluationPtr)
{
	m_thisInstanceValueEvaluationPtr = thisInstanceValueEvaluationPtr;
	setThisEvaluationPtr(thisInstanceValueEvaluationPtr);
}
std::shared_ptr<ecore::EObject> InstanceValueEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any InstanceValueEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return EvaluationImpl::eGet(featureID, resolve, coreType);
}
bool InstanceValueEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return EvaluationImpl::internalEIsSet(featureID);
}
bool InstanceValueEvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return EvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void InstanceValueEvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InstanceValueEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	EvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void InstanceValueEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	EvaluationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void InstanceValueEvaluationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	EvaluationImpl::resolveReferences(featureID, references);
}

void InstanceValueEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EvaluationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void InstanceValueEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

