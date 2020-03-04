#include "PSCS/Semantics/StructuredClassifiers/impl/CS_InteractionPointImpl.hpp"

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
#include "PSCS/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"

#include "fUML/Semantics/CommonBehavior/Execution.hpp"

#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

#include "uml/Operation.hpp"

#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"

#include "uml/Port.hpp"

#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"

//Factories an Package includes
#include "PSCS/Semantics/StructuredClassifiers/Impl/StructuredClassifiersFactoryImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/Impl/StructuredClassifiersPackageImpl.hpp"

#include "PSCS/Semantics/SemanticsFactory.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CS_InteractionPointImpl::CS_InteractionPointImpl()
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

CS_InteractionPointImpl::~CS_InteractionPointImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_InteractionPoint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_InteractionPointImpl::CS_InteractionPointImpl(const CS_InteractionPointImpl & obj):CS_InteractionPointImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_InteractionPoint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_definingPort  = obj.getDefiningPort();

	m_owner  = obj.getOwner();

	m_referent  = obj.getReferent();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_InteractionPointImpl::copy() const
{
	std::shared_ptr<CS_InteractionPointImpl> element(new CS_InteractionPointImpl(*this));
	element->setThisCS_InteractionPointPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_InteractionPointImpl::eStaticClass() const
{
	return PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_InteractionPoint_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool CS_InteractionPointImpl::checkAllParents(std::shared_ptr<uml::Classifier>  type,std::shared_ptr<uml::Classifier>  classifier)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Delegates the type checking to the reference
	return std::dynamic_pointer_cast<CS_InteractionPoint>(this->getReferent())->checkAllParents(type, classifier);
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_InteractionPointImpl::dispatch(std::shared_ptr<uml::Operation>  operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Delegates dispatching to the owning object
	return this->getOwner()->dispatchIn(operation, getThisCS_InteractionPointPtr());
	//end of body
}

void CS_InteractionPointImpl::send(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// An event occurrence that passes through a CS_InteractionPoint is
	// (if necessary) wrapped in a CS_EventOccurrence. This event occurrence
	// is then sent to the owning object.

	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrence> wrappingEventOccurrence = nullptr;
	if(std::dynamic_pointer_cast<PSCS::Semantics::CommonBehavior::CS_EventOccurrence>(eventOccurrence) != nullptr) {
		wrappingEventOccurrence = std::dynamic_pointer_cast<PSCS::Semantics::CommonBehavior::CS_EventOccurrence>(eventOccurrence);
	}
	else {
		wrappingEventOccurrence = PSCS::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createCS_EventOccurrence();
		wrappingEventOccurrence->setWrappedEventOccurrence(eventOccurrence);
	}
	wrappingEventOccurrence->setInteractionPoint(getThisCS_InteractionPointPtr());
	this->getOwner()->sendIn(wrappingEventOccurrence, getThisCS_InteractionPointPtr());
	//end of body
}

void CS_InteractionPointImpl::startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Overriden to do nothing
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Port > CS_InteractionPointImpl::getDefiningPort() const
{
//assert(m_definingPort);
    return m_definingPort;
}
void CS_InteractionPointImpl::setDefiningPort(std::shared_ptr<uml::Port> _definingPort)
{
    m_definingPort = _definingPort;
}

std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference > CS_InteractionPointImpl::getOwner() const
{
//assert(m_owner);
    return m_owner;
}
void CS_InteractionPointImpl::setOwner(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> _owner)
{
    m_owner = _owner;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<CS_InteractionPoint> CS_InteractionPointImpl::getThisCS_InteractionPointPtr() const
{
	return m_thisCS_InteractionPointPtr.lock();
}
void CS_InteractionPointImpl::setThisCS_InteractionPointPtr(std::weak_ptr<CS_InteractionPoint> thisCS_InteractionPointPtr)
{
	m_thisCS_InteractionPointPtr = thisCS_InteractionPointPtr;
	setThisReferencePtr(thisCS_InteractionPointPtr);
}
std::shared_ptr<ecore::EObject> CS_InteractionPointImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_InteractionPointImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_INTERACTIONPOINT_ATTRIBUTE_DEFININGPORT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getDefiningPort())); //172
		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_INTERACTIONPOINT_ATTRIBUTE_OWNER:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getOwner())); //171
	}
	return fUML::Semantics::StructuredClassifiers::ReferenceImpl::eGet(featureID, resolve, coreType);
}
bool CS_InteractionPointImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_INTERACTIONPOINT_ATTRIBUTE_DEFININGPORT:
			return getDefiningPort() != nullptr; //172
		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_INTERACTIONPOINT_ATTRIBUTE_OWNER:
			return getOwner() != nullptr; //171
	}
	return fUML::Semantics::StructuredClassifiers::ReferenceImpl::internalEIsSet(featureID);
}
bool CS_InteractionPointImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_INTERACTIONPOINT_ATTRIBUTE_DEFININGPORT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Port> _definingPort = std::dynamic_pointer_cast<uml::Port>(_temp);
			setDefiningPort(_definingPort); //172
			return true;
		}
		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_INTERACTIONPOINT_ATTRIBUTE_OWNER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> _owner = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(_temp);
			setOwner(_owner); //171
			return true;
		}
	}

	return fUML::Semantics::StructuredClassifiers::ReferenceImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_InteractionPointImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_InteractionPointImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("definingPort");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("definingPort")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("owner");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("owner")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void CS_InteractionPointImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory> modelFactory=PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::StructuredClassifiers::ReferenceImpl::loadNode(nodeName, loadHandler);
}

void CS_InteractionPointImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_INTERACTIONPOINT_ATTRIBUTE_DEFININGPORT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Port> _definingPort = std::dynamic_pointer_cast<uml::Port>( references.front() );
				setDefiningPort(_definingPort);
			}
			
			return;
		}

		case PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_INTERACTIONPOINT_ATTRIBUTE_OWNER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> _owner = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>( references.front() );
				setOwner(_owner);
			}
			
			return;
		}
	}
	fUML::Semantics::StructuredClassifiers::ReferenceImpl::resolveReferences(featureID, references);
}

void CS_InteractionPointImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::StructuredClassifiers::ReferenceImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void CS_InteractionPointImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();

	

		// Add references
		saveHandler->addReference("definingPort", this->getDefiningPort());
		saveHandler->addReference("owner", this->getOwner());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

