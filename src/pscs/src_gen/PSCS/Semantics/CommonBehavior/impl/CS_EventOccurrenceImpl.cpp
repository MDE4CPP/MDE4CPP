#include "PSCS/Semantics/CommonBehavior/impl/CS_EventOccurrenceImpl.hpp"

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
#include "fUML/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"

#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"

#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"

#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"

#include "uml/Port.hpp"

#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"

#include "uml/Trigger.hpp"

//Factories an Package includes
#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"
#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/SemanticsFactory.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
CS_EventOccurrenceImpl::CS_EventOccurrenceImpl()
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

CS_EventOccurrenceImpl::~CS_EventOccurrenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_EventOccurrence "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_EventOccurrenceImpl::CS_EventOccurrenceImpl(const CS_EventOccurrenceImpl & obj):CS_EventOccurrenceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_EventOccurrence "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_propagationInward = obj.isPropagationInward();

	//copy references with no containment (soft copy)
	
	m_interactionPoint  = obj.getInteractionPoint();

	m_onPort  = obj.getOnPort();

	m_target  = obj.getTarget();

	m_wrappedEventOccurrence  = obj.getWrappedEventOccurrence();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_EventOccurrenceImpl::copy() const
{
	std::shared_ptr<CS_EventOccurrenceImpl> element(new CS_EventOccurrenceImpl(*this));
	element->setThisCS_EventOccurrencePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_EventOccurrenceImpl::eStaticClass() const
{
	return PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCS_EventOccurrence_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void CS_EventOccurrenceImpl::setPropagationInward(bool _propagationInward)
{
	m_propagationInward = _propagationInward;
} 

bool CS_EventOccurrenceImpl::isPropagationInward() const 
{
	return m_propagationInward;
}

//*********************************
// Operations
//*********************************
void CS_EventOccurrenceImpl::doSend()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If the specified target is a CS_Reference and the propagation must be done
	// to the environment, then the operation sendOut(EventOccurrence, Port) is called
	// and make the propagation to continue.
	// If the specified target is a CS_Reference but the propagation must be done to
	// the internals then the operation sendIn(EventOccurrence, Port) is called.
	// In the case were the target is not a CS_EventOccurrence then send(EventOccurence)
	// is called.
	if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(this->getTarget()) != nullptr) {
		if(this->isPropagationInward()) {
			std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(this->getTarget())->sendIn(this->getThisCS_EventOccurrencePtr(), this->getOnPort());
		}
		else {
			std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(this->getTarget())->sendOut(this->getThisCS_EventOccurrencePtr(), this->getOnPort());
		}
	}
	else {
		fUML::Semantics::CommonBehavior::EventOccurrenceImpl::doSend();
	}
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > CS_EventOccurrenceImpl::getParameterValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return the parametric data of the referenced event occurrence
return this->getWrappedEventOccurrence()->getParameterValues();
	//end of body
}

bool CS_EventOccurrenceImpl::match(std::shared_ptr<uml::Trigger>  trigger)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If the trigger references ports then to match this latter it is required that 
	// 1] the interaction point is instance of port referenced by the trigger
	// 2] the referenced event occurrence match operation returns true.
	// If the trigger does not reference ports then the behavior is the same than for fUML.

	bool matches = false;
	if(trigger->getPort()->size() > 0) {
		unsigned int i = 1;
		while((!matches) && (i <= trigger->getPort()->size())) {
			if(this->getInteractionPoint()->getDefiningPort() == trigger->getPort()->at(i-1)){
				matches = true;
			}
			i++;
		}
		if(matches)	{
			matches = this->getWrappedEventOccurrence()->match(trigger);
		}
	}
	else {
		matches = this->getWrappedEventOccurrence()->match(trigger);
	}
	return matches;
	//end of body
}

void CS_EventOccurrenceImpl::sendInTo(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  target,std::shared_ptr<uml::Port>  port)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Propagate the sending of the event occurrence to the internals
	this->setOnPort(port);
	this->setPropagationInward(true);
	this->sendTo(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(target));
	//end of body
}

void CS_EventOccurrenceImpl::sendOutTo(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  target,std::shared_ptr<uml::Port>  port)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Propagate the sending of the event occurrence to the environment
	this->setOnPort(port);
	this->setPropagationInward(false);
	this->sendTo(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(target));
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint > CS_EventOccurrenceImpl::getInteractionPoint() const
{

    return m_interactionPoint;
}
void CS_EventOccurrenceImpl::setInteractionPoint(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> _interactionPoint)
{
    m_interactionPoint = _interactionPoint;
}

std::shared_ptr<uml::Port > CS_EventOccurrenceImpl::getOnPort() const
{

    return m_onPort;
}
void CS_EventOccurrenceImpl::setOnPort(std::shared_ptr<uml::Port> _onPort)
{
    m_onPort = _onPort;
}

std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence > CS_EventOccurrenceImpl::getWrappedEventOccurrence() const
{

    return m_wrappedEventOccurrence;
}
void CS_EventOccurrenceImpl::setWrappedEventOccurrence(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> _wrappedEventOccurrence)
{
    m_wrappedEventOccurrence = _wrappedEventOccurrence;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<CS_EventOccurrence> CS_EventOccurrenceImpl::getThisCS_EventOccurrencePtr() const
{
	return m_thisCS_EventOccurrencePtr.lock();
}
void CS_EventOccurrenceImpl::setThisCS_EventOccurrencePtr(std::weak_ptr<CS_EventOccurrence> thisCS_EventOccurrencePtr)
{
	m_thisCS_EventOccurrencePtr = thisCS_EventOccurrencePtr;
	setThisEventOccurrencePtr(thisCS_EventOccurrencePtr);
}
std::shared_ptr<ecore::EObject> CS_EventOccurrenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_EventOccurrenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_INTERACTIONPOINT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getInteractionPoint())); //131
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_ONPORT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getOnPort())); //134
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_PROPAGATIONINWARD:
			return eAny(isPropagationInward()); //133
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_WRAPPEDEVENTOCCURRENCE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getWrappedEventOccurrence())); //132
	}
	return fUML::Semantics::CommonBehavior::EventOccurrenceImpl::eGet(featureID, resolve, coreType);
}
bool CS_EventOccurrenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_INTERACTIONPOINT:
			return getInteractionPoint() != nullptr; //131
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_ONPORT:
			return getOnPort() != nullptr; //134
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_PROPAGATIONINWARD:
			return isPropagationInward() != false; //133
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_WRAPPEDEVENTOCCURRENCE:
			return getWrappedEventOccurrence() != nullptr; //132
	}
	return fUML::Semantics::CommonBehavior::EventOccurrenceImpl::internalEIsSet(featureID);
}
bool CS_EventOccurrenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_INTERACTIONPOINT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> _interactionPoint = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(_temp);
			setInteractionPoint(_interactionPoint); //131
			return true;
		}
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_ONPORT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Port> _onPort = std::dynamic_pointer_cast<uml::Port>(_temp);
			setOnPort(_onPort); //134
			return true;
		}
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_PROPAGATIONINWARD:
		{
			// BOOST CAST
			bool _propagationInward = newValue->get<bool>();
			setPropagationInward(_propagationInward); //133
			return true;
		}
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_WRAPPEDEVENTOCCURRENCE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> _wrappedEventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>(_temp);
			setWrappedEventOccurrence(_wrappedEventOccurrence); //132
			return true;
		}
	}

	return fUML::Semantics::CommonBehavior::EventOccurrenceImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_EventOccurrenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_EventOccurrenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("propagationInward");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setPropagationInward(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("interactionPoint");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("interactionPoint")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("onPort");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("onPort")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("wrappedEventOccurrence");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("wrappedEventOccurrence")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::loadAttributes(loadHandler, attr_list);
}

void CS_EventOccurrenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CommonBehaviorFactory> modelFactory=PSCS::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::loadNode(nodeName, loadHandler);
}

void CS_EventOccurrenceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_INTERACTIONPOINT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> _interactionPoint = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>( references.front() );
				setInteractionPoint(_interactionPoint);
			}
			
			return;
		}

		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_ONPORT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Port> _onPort = std::dynamic_pointer_cast<uml::Port>( references.front() );
				setOnPort(_onPort);
			}
			
			return;
		}

		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_EVENTOCCURRENCE_ATTRIBUTE_WRAPPEDEVENTOCCURRENCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> _wrappedEventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>( references.front() );
				setWrappedEventOccurrence(_wrappedEventOccurrence);
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::resolveReferences(featureID, references);
}

void CS_EventOccurrenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_EventOccurrenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::CommonBehavior::CommonBehaviorPackage> package = PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getCS_EventOccurrence_Attribute_propagationInward()) )
		{
			saveHandler->addAttribute("propagationInward", this->isPropagationInward());
		}

		// Add references
		saveHandler->addReference("interactionPoint", this->getInteractionPoint());
		saveHandler->addReference("onPort", this->getOnPort());
		saveHandler->addReference("wrappedEventOccurrence", this->getWrappedEventOccurrence());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

