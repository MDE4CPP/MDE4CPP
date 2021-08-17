#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ReferenceImpl.hpp"

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
#include "fUML/fUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"


#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "uml/Operation.hpp"
#include "uml/Port.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CS_ReferenceImpl::CS_ReferenceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_ReferenceImpl::~CS_ReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_Reference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CS_ReferenceImpl::CS_ReferenceImpl(const CS_ReferenceImpl & obj): CS_ReferenceImpl()
{
	*this = obj;
}

CS_ReferenceImpl& CS_ReferenceImpl::operator=(const CS_ReferenceImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::StructuredClassifiers::ReferenceImpl::operator=(obj);
	CS_Reference::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_Reference "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_compositeReferent  = obj.getCompositeReferent();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_ReferenceImpl::copy() const
{
	std::shared_ptr<CS_ReferenceImpl> element(new CS_ReferenceImpl());
	*element =(*this);
	element->setThisCS_ReferencePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_ReferenceImpl::eStaticClass() const
{
	return PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_Reference_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> CS_ReferenceImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new reference with the same referent and composite referent
// as this reference.

std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> newValue = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
newValue->setReferent(this->getReferent());
newValue->setCompositeReferent(this->getCompositeReferent());

return newValue;
	//end of body
}



std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ReferenceImpl::dispatchIn(std::shared_ptr<uml::Operation> operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		//Delegates dispatching to composite referent
	return this->getCompositeReferent()->dispatchIn(operation, interactionPoint);
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ReferenceImpl::dispatchIn(std::shared_ptr<uml::Operation> operation,std::shared_ptr<uml::Port> onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// delegates dispatching to composite referent
	return this->getCompositeReferent()->dispatchIn(operation, onPort);
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ReferenceImpl::dispatchOut(std::shared_ptr<uml::Operation> operation,std::shared_ptr<uml::Port> onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// delegates dispatching to composite referent
	return this->getCompositeReferent()->dispatchOut(operation, onPort);
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ReferenceImpl::dispatchOut(std::shared_ptr<uml::Operation> operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Delegates dispatching (through the interaction point, to the environment) 
	// to compositeReferent
	return this->getCompositeReferent()->dispatchOut(operation, interactionPoint);
	//end of body
}

void CS_ReferenceImpl::sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// delegates sending to composite referent
	this->getCompositeReferent()->sendIn(eventOccurrence, interactionPoint);
	//end of body
}

void CS_ReferenceImpl::sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<uml::Port> onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// delegates sending to composite referent
	this->getCompositeReferent()->sendIn(eventOccurrence, onPort);
	//end of body
}

void CS_ReferenceImpl::sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<uml::Port> onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// delegates sending to composite referent
	this->getCompositeReferent()->sendOut(eventOccurrence, onPort);
	//end of body
}

void CS_ReferenceImpl::sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Delegates sending (through the interaction point, to the environment)
	// to compositeReferent
	this->getCompositeReferent()->sendOut(eventOccurrence, interactionPoint);
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference compositeReferent
*/
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> CS_ReferenceImpl::getCompositeReferent() const
{
    return m_compositeReferent;
}
void CS_ReferenceImpl::setCompositeReferent(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> _compositeReferent)
{
    m_compositeReferent = _compositeReferent;
	
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<CS_Reference> CS_ReferenceImpl::getThisCS_ReferencePtr() const
{
	return m_thisCS_ReferencePtr.lock();
}
void CS_ReferenceImpl::setThisCS_ReferencePtr(std::weak_ptr<CS_Reference> thisCS_ReferencePtr)
{
	m_thisCS_ReferencePtr = thisCS_ReferencePtr;
	setThisReferencePtr(thisCS_ReferencePtr);
}
std::shared_ptr<ecore::EObject> CS_ReferenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_ReferenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_REFERENCE_ATTRIBUTE_COMPOSITEREFERENT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getCompositeReferent();
				return eAny(returnValue); //261
			}
	}
	return fUML::Semantics::StructuredClassifiers::ReferenceImpl::eGet(featureID, resolve, coreType);
}
bool CS_ReferenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_REFERENCE_ATTRIBUTE_COMPOSITEREFERENT:
			return getCompositeReferent() != nullptr; //261
	}
	return fUML::Semantics::StructuredClassifiers::ReferenceImpl::internalEIsSet(featureID);
}
bool CS_ReferenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_REFERENCE_ATTRIBUTE_COMPOSITEREFERENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> _compositeReferent = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(_temp);
			setCompositeReferent(_compositeReferent); //261
			return true;
		}
	}

	return fUML::Semantics::StructuredClassifiers::ReferenceImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CS_ReferenceImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 2645
		case StructuredClassifiersPackage::CS_REFERENCE_OPERATION__COPY:
		{
			result = eAny(this->_copy());
			break;
		}
		
		// 2637
		case StructuredClassifiersPackage::CS_REFERENCE_OPERATION_DISPATCHIN_OPERATION_CS_INTERACTIONPOINT:
		{
			//Retrieve input parameter 'operation'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_operation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_operation = (*incoming_param_operation_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			//Retrieve input parameter 'interactionPoint'
			//parameter 1
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> incoming_param_interactionPoint;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_interactionPoint_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_interactionPoint = (*incoming_param_interactionPoint_arguments_citer)->get()->get<std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> >();
			result = eAny(this->dispatchIn(incoming_param_operation,incoming_param_interactionPoint));
			break;
		}
		
		// 2641
		case StructuredClassifiersPackage::CS_REFERENCE_OPERATION_DISPATCHIN_OPERATION_PORT:
		{
			//Retrieve input parameter 'operation'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_operation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_operation = (*incoming_param_operation_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			//Retrieve input parameter 'onPort'
			//parameter 1
			std::shared_ptr<uml::Port> incoming_param_onPort;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_onPort_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_onPort = (*incoming_param_onPort_arguments_citer)->get()->get<std::shared_ptr<uml::Port> >();
			result = eAny(this->dispatchIn(incoming_param_operation,incoming_param_onPort));
			break;
		}
		
		// 2640
		case StructuredClassifiersPackage::CS_REFERENCE_OPERATION_DISPATCHOUT_OPERATION_PORT:
		{
			//Retrieve input parameter 'operation'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_operation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_operation = (*incoming_param_operation_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			//Retrieve input parameter 'onPort'
			//parameter 1
			std::shared_ptr<uml::Port> incoming_param_onPort;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_onPort_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_onPort = (*incoming_param_onPort_arguments_citer)->get()->get<std::shared_ptr<uml::Port> >();
			result = eAny(this->dispatchOut(incoming_param_operation,incoming_param_onPort));
			break;
		}
		
		// 2643
		case StructuredClassifiersPackage::CS_REFERENCE_OPERATION_DISPATCHOUT_OPERATION_CS_INTERACTIONPOINT:
		{
			//Retrieve input parameter 'operation'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_operation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_operation = (*incoming_param_operation_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			//Retrieve input parameter 'interactionPoint'
			//parameter 1
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> incoming_param_interactionPoint;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_interactionPoint_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_interactionPoint = (*incoming_param_interactionPoint_arguments_citer)->get()->get<std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> >();
			result = eAny(this->dispatchOut(incoming_param_operation,incoming_param_interactionPoint));
			break;
		}
		
		// 2638
		case StructuredClassifiersPackage::CS_REFERENCE_OPERATION_SENDIN_EVENTOCCURRENCE_CS_INTERACTIONPOINT:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			//Retrieve input parameter 'interactionPoint'
			//parameter 1
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> incoming_param_interactionPoint;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_interactionPoint_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_interactionPoint = (*incoming_param_interactionPoint_arguments_citer)->get()->get<std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> >();
			this->sendIn(incoming_param_eventOccurrence,incoming_param_interactionPoint);
			break;
		}
		
		// 2642
		case StructuredClassifiersPackage::CS_REFERENCE_OPERATION_SENDIN_EVENTOCCURRENCE_PORT:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			//Retrieve input parameter 'onPort'
			//parameter 1
			std::shared_ptr<uml::Port> incoming_param_onPort;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_onPort_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_onPort = (*incoming_param_onPort_arguments_citer)->get()->get<std::shared_ptr<uml::Port> >();
			this->sendIn(incoming_param_eventOccurrence,incoming_param_onPort);
			break;
		}
		
		// 2639
		case StructuredClassifiersPackage::CS_REFERENCE_OPERATION_SENDOUT_EVENTOCCURRENCE_PORT:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			//Retrieve input parameter 'onPort'
			//parameter 1
			std::shared_ptr<uml::Port> incoming_param_onPort;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_onPort_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_onPort = (*incoming_param_onPort_arguments_citer)->get()->get<std::shared_ptr<uml::Port> >();
			this->sendOut(incoming_param_eventOccurrence,incoming_param_onPort);
			break;
		}
		
		// 2644
		case StructuredClassifiersPackage::CS_REFERENCE_OPERATION_SENDOUT_EVENTOCCURRENCE_CS_INTERACTIONPOINT:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			//Retrieve input parameter 'interactionPoint'
			//parameter 1
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> incoming_param_interactionPoint;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_interactionPoint_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_interactionPoint = (*incoming_param_interactionPoint_arguments_citer)->get()->get<std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> >();
			this->sendOut(incoming_param_eventOccurrence,incoming_param_interactionPoint);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::StructuredClassifiers::ReferenceImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void CS_ReferenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_ReferenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("compositeReferent");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("compositeReferent")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::StructuredClassifiers::ReferenceImpl::loadAttributes(loadHandler, attr_list);
}

void CS_ReferenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::StructuredClassifiers::ReferenceImpl::loadNode(nodeName, loadHandler);
}

void CS_ReferenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_REFERENCE_ATTRIBUTE_COMPOSITEREFERENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> _compositeReferent = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>( references.front() );
				setCompositeReferent(_compositeReferent);
			}
			
			return;
		}
	}
	fUML::Semantics::StructuredClassifiers::ReferenceImpl::resolveReferences(featureID, references);
}

void CS_ReferenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::StructuredClassifiers::ReferenceImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void CS_ReferenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getCompositeReferent(), "compositeReferent", getCompositeReferent()->eClass() != PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_Object_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

