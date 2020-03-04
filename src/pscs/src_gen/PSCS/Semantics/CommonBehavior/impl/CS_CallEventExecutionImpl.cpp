#include "PSCS/Semantics/CommonBehavior/impl/CS_CallEventExecutionImpl.hpp"

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
#include "PSCS/Semantics/CommonBehavior/CS_EventOccurrence.hpp"
#include "fUML/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"

#include "fUML/Semantics/CommonBehavior/CallEventExecution.hpp"

#include "uml/Classifier.hpp"

#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"

#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"

#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "PSCS/Semantics/CommonBehavior/Impl/CommonBehaviorFactoryImpl.hpp"
#include "PSCS/Semantics/CommonBehavior/Impl/CommonBehaviorPackageImpl.hpp"

#include "PSCS/Semantics/SemanticsFactory.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
CS_CallEventExecutionImpl::CS_CallEventExecutionImpl()
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

CS_CallEventExecutionImpl::~CS_CallEventExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_CallEventExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_CallEventExecutionImpl::CS_CallEventExecutionImpl(const CS_CallEventExecutionImpl & obj):CS_CallEventExecutionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_CallEventExecution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_callerSuspended = obj.getCallerSuspended();

	//copy references with no containment (soft copy)
	
	m_context  = obj.getContext();

	m_interactionPoint  = obj.getInteractionPoint();

	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<uml::Classifier>> _types = obj.getTypes();
	m_types.reset(new Bag<uml::Classifier>(*(obj.getTypes().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue>(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(obj.getObjectActivation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_objectActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> _parameterValuesList = obj.getParameterValues();
	for(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> _parameterValues : *_parameterValuesList)
	{
		this->getParameterValues()->add(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(_parameterValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_parameterValues" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  CS_CallEventExecutionImpl::copy() const
{
	std::shared_ptr<CS_CallEventExecutionImpl> element(new CS_CallEventExecutionImpl(*this));
	element->setThisCS_CallEventExecutionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_CallEventExecutionImpl::eStaticClass() const
{
	return PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCS_CallEventExecution_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************


std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> CS_CallEventExecutionImpl::createEventOccurrence()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Wrap the created event occurrence within a CS_EventOccurrence which
	// references the behavior port on which the call was dispatched.
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrence> wrappingEventOccurrence = PSCS::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createCS_EventOccurrence();
	wrappingEventOccurrence->setInteractionPoint(this->getInteractionPoint());
	wrappingEventOccurrence->setWrappedEventOccurrence(fUML::Semantics::CommonBehavior::CallEventExecutionImpl::createEventOccurrence());
	return wrappingEventOccurrence;
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> CS_CallEventExecutionImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new call event execution.

return PSCS::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createCS_CallEventExecution();
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint > CS_CallEventExecutionImpl::getInteractionPoint() const
{

    return m_interactionPoint;
}
void CS_CallEventExecutionImpl::setInteractionPoint(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> _interactionPoint)
{
    m_interactionPoint = _interactionPoint;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<CS_CallEventExecution> CS_CallEventExecutionImpl::getThisCS_CallEventExecutionPtr() const
{
	return m_thisCS_CallEventExecutionPtr.lock();
}
void CS_CallEventExecutionImpl::setThisCS_CallEventExecutionPtr(std::weak_ptr<CS_CallEventExecution> thisCS_CallEventExecutionPtr)
{
	m_thisCS_CallEventExecutionPtr = thisCS_CallEventExecutionPtr;
	setThisCallEventExecutionPtr(thisCS_CallEventExecutionPtr);
}
std::shared_ptr<ecore::EObject> CS_CallEventExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_CallEventExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_CALLEVENTEXECUTION_ATTRIBUTE_INTERACTIONPOINT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getInteractionPoint())); //47
	}
	return fUML::Semantics::CommonBehavior::CallEventExecutionImpl::eGet(featureID, resolve, coreType);
}
bool CS_CallEventExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_CALLEVENTEXECUTION_ATTRIBUTE_INTERACTIONPOINT:
			return getInteractionPoint() != nullptr; //47
	}
	return fUML::Semantics::CommonBehavior::CallEventExecutionImpl::internalEIsSet(featureID);
}
bool CS_CallEventExecutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_CALLEVENTEXECUTION_ATTRIBUTE_INTERACTIONPOINT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> _interactionPoint = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(_temp);
			setInteractionPoint(_interactionPoint); //47
			return true;
		}
	}

	return fUML::Semantics::CommonBehavior::CallEventExecutionImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_CallEventExecutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_CallEventExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("interactionPoint");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("interactionPoint")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::CommonBehavior::CallEventExecutionImpl::loadAttributes(loadHandler, attr_list);
}

void CS_CallEventExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CommonBehaviorFactory> modelFactory=PSCS::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::CallEventExecutionImpl::loadNode(nodeName, loadHandler);
}

void CS_CallEventExecutionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_CALLEVENTEXECUTION_ATTRIBUTE_INTERACTIONPOINT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> _interactionPoint = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>( references.front() );
				setInteractionPoint(_interactionPoint);
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::CallEventExecutionImpl::resolveReferences(featureID, references);
}

void CS_CallEventExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::CallEventExecutionImpl::saveContent(saveHandler);
	
	fUML::Semantics::CommonBehavior::ExecutionImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ObjectImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
	
}

void CS_CallEventExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::CommonBehavior::CommonBehaviorPackage> package = PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();

	

		// Add references
		saveHandler->addReference("interactionPoint", this->getInteractionPoint());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

