#include "fUML/impl/ReferenceImpl.hpp"

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
#include "fUML/impl/FUMLPackageImpl.hpp"
#include <uml/Classifier.hpp>
    #include "fUML/FUMLFactory.hpp"
    #include "uml/Class.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "fUML/Execution.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Object.hpp"

#include "uml/Operation.hpp"

#include "fUML/ParameterValue.hpp"

#include "fUML/SignalInstance.hpp"

#include "uml/StructuralFeature.hpp"

#include "fUML/StructuredValue.hpp"

#include "fUML/Value.hpp"

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
ReferenceImpl::ReferenceImpl()
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

ReferenceImpl::~ReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Reference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ReferenceImpl::ReferenceImpl(const ReferenceImpl & obj):ReferenceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Reference "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_referent  = obj.getReferent();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ReferenceImpl::copy() const
{
	std::shared_ptr<ReferenceImpl> element(new ReferenceImpl(*this));
	element->setThisReferencePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ReferenceImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getReference_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ReferenceImpl::assignFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Value> >  values,int position)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->assignFeatureValue(feature,values,position);
	//end of body
}

void ReferenceImpl::destroy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getReferent()->destroy();
	//end of body
}

std::shared_ptr<fUML::Execution> ReferenceImpl::dispatch(std::shared_ptr<uml::Operation>  operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->dispatch(operation);
	//end of body
}

bool ReferenceImpl::equals(std::shared_ptr<fUML::Value>  otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool isEqual = false;
	if (otherValue->eClass()->getClassifierID() == fUML::FUMLPackage::REFERENCE_ECLASS) {
		auto other = std::dynamic_pointer_cast<Reference>(otherValue);
		if (this->getReferent() == nullptr) {
			isEqual = other->getReferent() == nullptr;
		} else {
			isEqual = this->getReferent()->equals(other->getReferent());
		}
	}
	return isEqual;
	//end of body
}

std::shared_ptr<Bag<uml::Classifier> > ReferenceImpl::getTypes()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		return  this->getReferent()->getTypes();
	//end of body
}

std::shared_ptr<fUML::Value> ReferenceImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(FUMLFactory::eInstance()->createReference());
	//end of body
}

std::shared_ptr<fUML::FeatureValue> ReferenceImpl::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->retrieveFeatureValue(feature);
	//end of body
}

std::shared_ptr<Bag<fUML::FeatureValue> > ReferenceImpl::retrieveFeatureValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->retrieveFeatureValues();
	//end of body
}

void ReferenceImpl::send(std::shared_ptr<fUML::SignalInstance>  signalInstance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getReferent()->send(signalInstance);
	//end of body
}

void ReferenceImpl::startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getReferent()->startBehavior(classifier,inputs);
	//end of body
}

std::string ReferenceImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "Reference to " + this->getReferent()->toString();
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Object > ReferenceImpl::getReferent() const
{
//assert(m_referent);
    return m_referent;
}
void ReferenceImpl::setReferent(std::shared_ptr<fUML::Object> _referent)
{
    m_referent = _referent;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<Reference> ReferenceImpl::getThisReferencePtr() const
{
	return m_thisReferencePtr.lock();
}
void ReferenceImpl::setThisReferencePtr(std::weak_ptr<Reference> thisReferencePtr)
{
	m_thisReferencePtr = thisReferencePtr;
	setThisStructuredValuePtr(thisReferencePtr);
}
std::shared_ptr<ecore::EObject> ReferenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ReferenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::REFERENCE_EREFERENCE_REFERENT:
			return eAny(getReferent()); //950
	}
	return StructuredValueImpl::eGet(featureID, resolve, coreType);
}
bool ReferenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::REFERENCE_EREFERENCE_REFERENT:
			return getReferent() != nullptr; //950
	}
	return StructuredValueImpl::internalEIsSet(featureID);
}
bool ReferenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::REFERENCE_EREFERENCE_REFERENT:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Object> _referent = newValue->get<std::shared_ptr<fUML::Object>>();
			setReferent(_referent); //950
			return true;
		}
	}

	return StructuredValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ReferenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReferenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("referent");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referent")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	StructuredValueImpl::loadAttributes(loadHandler, attr_list);
}

void ReferenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	StructuredValueImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ReferenceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::REFERENCE_EREFERENCE_REFERENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Object> _referent = std::dynamic_pointer_cast<fUML::Object>( references.front() );
				setReferent(_referent);
			}
			
			return;
		}
	}
	StructuredValueImpl::resolveReferences(featureID, references);
}

void ReferenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredValueImpl::saveContent(saveHandler);
	
	ValueImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ReferenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		saveHandler->addReference("referent", this->getReferent());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

