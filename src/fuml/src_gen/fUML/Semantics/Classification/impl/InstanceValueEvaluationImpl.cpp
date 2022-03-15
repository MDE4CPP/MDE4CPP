
#include "fUML/Semantics/Classification/impl/InstanceValueEvaluationImpl.hpp"
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



#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/fUMLFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

#include "abstractDataTypes/Subset.hpp"
#include "fUML/Semantics/SimpleClassifiers/DataValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/EnumerationValue.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Executor.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/Values/Value.hpp"
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

#include <exception> // used in Persistence
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Classification/ClassificationPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Classification;

//*********************************
// Constructor / Destructor
//*********************************
InstanceValueEvaluationImpl::InstanceValueEvaluationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InstanceValueEvaluationImpl::~InstanceValueEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InstanceValueEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


InstanceValueEvaluationImpl::InstanceValueEvaluationImpl(const InstanceValueEvaluationImpl & obj): InstanceValueEvaluationImpl()
{
	*this = obj;
}

InstanceValueEvaluationImpl& InstanceValueEvaluationImpl::operator=(const InstanceValueEvaluationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::EvaluationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InstanceValueEvaluation 
	 * which is generated by the compiler (as InstanceValueEvaluation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InstanceValueEvaluation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InstanceValueEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> InstanceValueEvaluationImpl::copy() const
{
	std::shared_ptr<InstanceValueEvaluationImpl> element(new InstanceValueEvaluationImpl());
	*element =(*this);
	element->setThisInstanceValueEvaluationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
Any InstanceValueEvaluationImpl::evaluate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::InstanceSpecification> instance = (std::dynamic_pointer_cast<uml::InstanceValue>(this->getSpecification()))->getInstance();
	std::shared_ptr<Bag<uml::Classifier> > types = instance->getClassifier();
	std::shared_ptr<uml::Classifier> myType = types->at(0);

    DEBUG_MESSAGE(std::cout<<("[evaluate] type = " + myType->getName())<<std::endl;)

    std::shared_ptr<fUML::Semantics::Values::Value> value;
    std::shared_ptr<uml::EnumerationLiteral> literal = std::dynamic_pointer_cast<uml::EnumerationLiteral>(instance);
    if(literal != nullptr)
    {
    	std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumerationValue(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createEnumerationValue());
        enumerationValue->setType(std::dynamic_pointer_cast<uml::Enumeration>(myType));
        enumerationValue->setLiteral(literal);
        value = enumerationValue;
    }
    else
    {
    	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue> structuredValue = nullptr;
    	std::shared_ptr<uml::DataType> type = std::dynamic_pointer_cast<uml::DataType>(myType);
        if(type != nullptr)
        {
            // Debug.println("[evaluate] Type is a data type.");
        	std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> dataValue(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createDataValue());
            dataValue->setType(type);
            structuredValue = dataValue;
        }
        else
        {
        	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object = nullptr;
        	std::shared_ptr<uml::Behavior> behavior = std::dynamic_pointer_cast<uml::Behavior>(myType);
            if(behavior != nullptr)
            {
                // Debug.println("[evaluate] Type is a behavior.");
                object = this->getLocus()->getFactory()->createExecution(behavior, nullptr);
            }
            else
            {
                // Debug.println("[evaluate] Type is a class.");
                object = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createObject();
                for(unsigned int i = 0; i < types->size(); i++)
                {
                	std::shared_ptr<uml::Classifier> type = types->at(i);
                    object->getTypes()->push_back(std::dynamic_pointer_cast<uml::Class>(type));
                }
            }

            this->getLocus()->add(object);

            std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference(fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference());
            reference->setReferent(object);
            structuredValue = reference;
        }

        structuredValue->createFeatureValues();

        std::shared_ptr<Bag<uml::Slot> > instanceSlots = instance->getSlot();
        for(unsigned int i = 0; i < instanceSlots->size(); i++)
        {
        	std::shared_ptr<uml::Slot> slot = instanceSlots->at(i);
        	std::shared_ptr<Bag<fUML::Semantics::Values::Value> > values(new Bag<fUML::Semantics::Values::Value>());

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
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InstanceValueEvaluationImpl::eContainer() const
{
	return nullptr;
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
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void InstanceValueEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Values::EvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void InstanceValueEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::EvaluationImpl::loadNode(nodeName, loadHandler);
}

void InstanceValueEvaluationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::EvaluationImpl::resolveReferences(featureID, references);
}

void InstanceValueEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InstanceValueEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Classification::ClassificationPackage> package = fUML::Semantics::Classification::ClassificationPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> InstanceValueEvaluationImpl::eStaticClass() const
{
	return fUML::Semantics::Classification::ClassificationPackage::eInstance()->getInstanceValueEvaluation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any InstanceValueEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::EvaluationImpl::eGet(featureID, resolve, coreType);
}

bool InstanceValueEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::EvaluationImpl::internalEIsSet(featureID);
}

bool InstanceValueEvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Values::EvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any InstanceValueEvaluationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Classification::InstanceValueEvaluation::evaluate() : Any: 2570786047
		case ClassificationPackage::INSTANCEVALUEEVALUATION_OPERATION_EVALUATE:
		{
			result = this->evaluate();
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::EvaluationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Classification::InstanceValueEvaluation> InstanceValueEvaluationImpl::getThisInstanceValueEvaluationPtr() const
{
	return m_thisInstanceValueEvaluationPtr.lock();
}
void InstanceValueEvaluationImpl::setThisInstanceValueEvaluationPtr(std::weak_ptr<fUML::Semantics::Classification::InstanceValueEvaluation> thisInstanceValueEvaluationPtr)
{
	m_thisInstanceValueEvaluationPtr = thisInstanceValueEvaluationPtr;
	setThisEvaluationPtr(thisInstanceValueEvaluationPtr);
}


