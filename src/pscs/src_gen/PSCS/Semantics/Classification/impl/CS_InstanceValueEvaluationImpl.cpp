#include "PSCS/Semantics/Classification/impl/CS_InstanceValueEvaluationImpl.hpp"

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

//Includes from codegen annotation
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/EnumerationValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/DataValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Loci/Executor.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/InstanceSpecification.hpp"
#include "uml/EnumerationLiteral.hpp"
#include "uml/Enumeration.hpp"
#include "uml/Behavior.hpp"
#include "uml/Slot.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Classification/InstanceValueEvaluation.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/Values/Value.hpp"

#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "PSCS/Semantics/Classification/Impl/ClassificationFactoryImpl.hpp"
#include "PSCS/Semantics/Classification/Impl/ClassificationPackageImpl.hpp"

#include "PSCS/Semantics/SemanticsFactory.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Classification;

//*********************************
// Constructor / Destructor
//*********************************
CS_InstanceValueEvaluationImpl::CS_InstanceValueEvaluationImpl()
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

CS_InstanceValueEvaluationImpl::~CS_InstanceValueEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_InstanceValueEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_InstanceValueEvaluationImpl::CS_InstanceValueEvaluationImpl(const CS_InstanceValueEvaluationImpl & obj):CS_InstanceValueEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_InstanceValueEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_InstanceValueEvaluationImpl::copy() const
{
	std::shared_ptr<CS_InstanceValueEvaluationImpl> element(new CS_InstanceValueEvaluationImpl(*this));
	element->setThisCS_InstanceValueEvaluationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_InstanceValueEvaluationImpl::eStaticClass() const
{
	return PSCS::Semantics::Classification::ClassificationPackage::eInstance()->getCS_InstanceValueEvaluation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> CS_InstanceValueEvaluationImpl::evaluate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If the instance specification is for an enumeration, then return the
	// identified enumeration literal.
	// If the instance specification is for a data type (but not a primitive
	// value or an enumeration), then create a data value of the given data
	// type.
	// If the instance specification is for an object, then create an object
	// at the current locus with the specified types.
	// Set each feature of the created value to the result of evaluating the
	// value specifications for the specified slot for the feature.
	// Extends fUML semantics in the sense that when the instance specification
	// is for an object which is not typed by a Behaviore, A CS_Reference (to a
	// CS_Object) is produced instead of a Reference (to an Object)

	DEBUG_MESSAGE(std::cout << "[evaluate] InstanceValueEvaluation..." << std::endl;)

	std::shared_ptr<uml::InstanceValue> instanceValue = std::dynamic_pointer_cast<uml::InstanceValue>(this->getSpecification());
	std::shared_ptr<uml::InstanceSpecification> instance = instanceValue->getInstance();

	std::shared_ptr<Bag<uml::Classifier>> types = instance->getClassifier();
	std::shared_ptr<uml::Classifier> myType = types->at(0);

	DEBUG_MESSAGE(std::cout << "[evaluate] type = " << myType->getName() << std::endl;)

	std::shared_ptr<fUML::Semantics::Values::Value> value;
	
	if(std::dynamic_pointer_cast<uml::EnumerationLiteral>(instance) != nullptr) {
		DEBUG_MESSAGE(std::cout << "[evaluate] Type is an enumeration." << std::endl;)
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumerationValue(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createEnumerationValue());

		enumerationValue->setType(std::dynamic_pointer_cast<uml::Enumeration>(myType));
		enumerationValue->setLiteral(std::dynamic_pointer_cast<uml::EnumerationLiteral>(instance));

		value = enumerationValue;
	}
	else {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue> structuredValue = nullptr;
		if(std::dynamic_pointer_cast<uml::DataType>(myType) != nullptr){
			DEBUG_MESSAGE(std::cout << "[evaluate] Type is a data type." << std::endl;)
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> dataValue(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createDataValue());
			dataValue->setType(std::dynamic_pointer_cast<uml::DataType>(myType));
			structuredValue = dataValue;
		}
		else {
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object = nullptr;
			if(std::dynamic_pointer_cast<uml::Behavior>(myType) != nullptr){
				DEBUG_MESSAGE(std::cout << "[evaluate] Type is a behavior." << std::endl;)
				std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> execution = this->getLocus()->getFactory()->createExecution(std::dynamic_pointer_cast<uml::Behavior>(myType), nullptr);
				object = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>(execution);	
			}
			else {
				DEBUG_MESSAGE(std::cout << "[evaluate] Type is a class." << std::endl;)
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> csObject(PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Object());
				object = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>(csObject);
				
				for(Bag<uml::Classifier>::const_iterator itClass = types->begin(); itClass != types->end(); itClass++) {
					std::shared_ptr<uml::Classifier> type = (*itClass);
					object->getTypes()->add(std::dynamic_pointer_cast<uml::Class>(type));
				}	
			}
			this->getLocus()->add(object);
			
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference;
			if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(object) != nullptr){
				reference = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();
				(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(reference))->setCompositeReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(object));
			}
			else{
				reference = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();
			}
			reference->setReferent(object);
			structuredValue = reference;
		}
		structuredValue->createFeatureValues();
		
		DEBUG_MESSAGE(std::cout << "[evaluate] " << instance->getSlot->size() << " slot(s)." << std::endl;)
		
		std::shared_ptr<Bag<uml::Slot>> instanceSlots = instance->getSlot(); 
		for(Bag<uml::Slot>::const_iterator itSlot = instanceSlots->begin(); itSlot != instanceSlots->end(); itSlot++){
			std::shared_ptr<uml::Slot> slot = (*itSlot);
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
			
			DEBUG_MESSAGE(std::cout << "[evaluate] feature" << slot->getDefiningFeature->getName() << ", " << slot->getValue->size() << " value(s)." << std::endl;)
			
			std::shared_ptr<Bag<uml::ValueSpecification>> slotValues = slot->getValue();
			for(Bag<uml::ValueSpecification>::const_iterator itValSpec = slotValues->begin(); itValSpec != slotValues->end(); itValSpec++){
				std::shared_ptr<uml::ValueSpecification> slotValue = (*itValSpec);
				DEBUG_MESSAGE(std::cout << "[evaluate] Value " << slotValue->getClass()->getName() << std::endl;)
				values->add(this->getLocus()->getExecutor()->evaluate(slotValue));
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


std::shared_ptr<CS_InstanceValueEvaluation> CS_InstanceValueEvaluationImpl::getThisCS_InstanceValueEvaluationPtr() const
{
	return m_thisCS_InstanceValueEvaluationPtr.lock();
}
void CS_InstanceValueEvaluationImpl::setThisCS_InstanceValueEvaluationPtr(std::weak_ptr<CS_InstanceValueEvaluation> thisCS_InstanceValueEvaluationPtr)
{
	m_thisCS_InstanceValueEvaluationPtr = thisCS_InstanceValueEvaluationPtr;
	setThisInstanceValueEvaluationPtr(thisCS_InstanceValueEvaluationPtr);
}
std::shared_ptr<ecore::EObject> CS_InstanceValueEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_InstanceValueEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Classification::InstanceValueEvaluationImpl::eGet(featureID, resolve, coreType);
}
bool CS_InstanceValueEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Classification::InstanceValueEvaluationImpl::internalEIsSet(featureID);
}
bool CS_InstanceValueEvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Classification::InstanceValueEvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_InstanceValueEvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CS_InstanceValueEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Classification::InstanceValueEvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_InstanceValueEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<PSCS::Semantics::Classification::ClassificationFactory> modelFactory=PSCS::Semantics::Classification::ClassificationFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::Classification::InstanceValueEvaluationImpl::loadNode(nodeName, loadHandler);
}

void CS_InstanceValueEvaluationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Classification::InstanceValueEvaluationImpl::resolveReferences(featureID, references);
}

void CS_InstanceValueEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Classification::InstanceValueEvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void CS_InstanceValueEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::Classification::ClassificationPackage> package = PSCS::Semantics::Classification::ClassificationPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

