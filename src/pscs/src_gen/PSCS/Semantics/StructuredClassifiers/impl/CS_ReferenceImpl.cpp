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
#include "PSCS/impl/PSCSPackageImpl.hpp"
#include "fUML/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"

#include <exception> // used in Persistence

#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"

#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"

#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"

#include "fUML/Semantics/CommonBehavior/Execution.hpp"

#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

#include "uml/Operation.hpp"

#include "uml/Port.hpp"

#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"

#include "fUML/Semantics/Values/Value.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CS_ReferenceImpl::CS_ReferenceImpl()
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

CS_ReferenceImpl::~CS_ReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_Reference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_ReferenceImpl::CS_ReferenceImpl(const CS_ReferenceImpl & obj):CS_ReferenceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_Reference "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_compositeReferent  = obj.getCompositeReferent();

	m_referent  = obj.getReferent();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_ReferenceImpl::copy() const
{
	std::shared_ptr<CS_ReferenceImpl> element(new CS_ReferenceImpl(*this));
	element->setThisCS_ReferencePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_ReferenceImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_Reference_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************


std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ReferenceImpl::dispatchIn(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		//Delegates dispatching to composite referent
	return this->getCompositeReferent()->dispatchIn(operation, interactionPoint);
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ReferenceImpl::dispatchIn(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<uml::Port>  onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// delegates dispatching to composite referent
	return this->getCompositeReferent()->dispatchIn(operation, onPort);
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ReferenceImpl::dispatchOut(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<uml::Port>  onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// delegates dispatching to composite referent
	return this->getCompositeReferent()->dispatchOut(operation, onPort);
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ReferenceImpl::dispatchOut(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Delegates dispatching (through the interaction point, to the environment) 
	// to compositeReferent
	return this->getCompositeReferent()->dispatchOut(operation, interactionPoint);
	//end of body
}

void CS_ReferenceImpl::sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// delegates sending to composite referent
	this->getCompositeReferent()->sendIn(eventOccurrence, interactionPoint);
	//end of body
}

void CS_ReferenceImpl::sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<uml::Port>  onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// delegates sending to composite referent
	this->getCompositeReferent()->sendIn(eventOccurrence, onPort);
	//end of body
}

void CS_ReferenceImpl::sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<uml::Port>  onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// delegates sending to composite referent
	this->getCompositeReferent()->sendOut(eventOccurrence, onPort);
	//end of body
}

void CS_ReferenceImpl::sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint)
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
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object > CS_ReferenceImpl::getCompositeReferent() const
{
//assert(m_compositeReferent);
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
		case PSCS::PSCSPackage::CS_REFERENCE_ATTRIBUTE_COMPOSITEREFERENT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getCompositeReferent())); //261
	}
	return fUML::Semantics::StructuredClassifiers::ReferenceImpl::eGet(featureID, resolve, coreType);
}
bool CS_ReferenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_REFERENCE_ATTRIBUTE_COMPOSITEREFERENT:
			return getCompositeReferent() != nullptr; //261
	}
	return fUML::Semantics::StructuredClassifiers::ReferenceImpl::internalEIsSet(featureID);
}
bool CS_ReferenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_REFERENCE_ATTRIBUTE_COMPOSITEREFERENT:
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
	std::shared_ptr<PSCS::PSCSFactory> modelFactory = PSCS::PSCSFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void CS_ReferenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	fUML::Semantics::StructuredClassifiers::ReferenceImpl::loadNode(nodeName, loadHandler, fUML::FUMLFactory::eInstance());
}

void CS_ReferenceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_REFERENCE_ATTRIBUTE_COMPOSITEREFERENT:
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
		std::shared_ptr<PSCS::PSCSPackage> package = PSCS::PSCSPackage::eInstance();

	

		// Add references
		saveHandler->addReference("compositeReferent", this->getCompositeReferent());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

