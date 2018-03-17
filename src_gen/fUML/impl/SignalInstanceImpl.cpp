#include "fUML/impl/SignalInstanceImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/CompoundValue.hpp"

#include "fUML/FeatureValue.hpp"

#include "uml/Signal.hpp"

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
SignalInstanceImpl::SignalInstanceImpl()
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

SignalInstanceImpl::~SignalInstanceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SignalInstance "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




SignalInstanceImpl::SignalInstanceImpl(const SignalInstanceImpl & obj):SignalInstanceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SignalInstance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(std::dynamic_pointer_cast<fUML::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  SignalInstanceImpl::copy() const
{
	std::shared_ptr<SignalInstanceImpl> element(new SignalInstanceImpl(*this));
	element->setThisSignalInstancePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> SignalInstanceImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getSignalInstance_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::Signal > SignalInstanceImpl::getType() const
{
//assert(m_type);
    return m_type;
}
void SignalInstanceImpl::setType(std::shared_ptr<uml::Signal> _type)
{
    m_type = _type;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<SignalInstance> SignalInstanceImpl::getThisSignalInstancePtr()
{
	return m_thisSignalInstancePtr.lock();
}
void SignalInstanceImpl::setThisSignalInstancePtr(std::weak_ptr<SignalInstance> thisSignalInstancePtr)
{
	m_thisSignalInstancePtr = thisSignalInstancePtr;
	setThisCompoundValuePtr(thisSignalInstancePtr);
}
std::shared_ptr<ecore::EObject> SignalInstanceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any SignalInstanceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::SIGNALINSTANCE_EREFERENCE_TYPE:
			return getType(); //451
	}
	return CompoundValueImpl::internalEIsSet(featureID);
}
bool SignalInstanceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::SIGNALINSTANCE_EREFERENCE_TYPE:
			return getType() != nullptr; //451
	}
	return CompoundValueImpl::internalEIsSet(featureID);
}
bool SignalInstanceImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::SIGNALINSTANCE_EREFERENCE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Signal> _type = boost::any_cast<std::shared_ptr<uml::Signal>>(newValue);
			setType(_type); //451
			return true;
		}
	}

	return CompoundValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void SignalInstanceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SignalInstanceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("type");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("type")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	CompoundValueImpl::loadAttributes(loadHandler, attr_list);
}

void SignalInstanceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	CompoundValueImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void SignalInstanceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::SIGNALINSTANCE_EREFERENCE_TYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Signal> _type = std::dynamic_pointer_cast<uml::Signal>( references.front() );
				setType(_type);
			}
			
			return;
		}
	}
	CompoundValueImpl::resolveReferences(featureID, references);
}

void SignalInstanceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CompoundValueImpl::saveContent(saveHandler);
	
	StructuredValueImpl::saveContent(saveHandler);
	
	ValueImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void SignalInstanceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		saveHandler->addReference("type", this->getType());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

