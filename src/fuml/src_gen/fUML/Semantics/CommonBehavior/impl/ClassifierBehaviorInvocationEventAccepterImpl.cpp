#include "fUML/Semantics/CommonBehavior/impl/ClassifierBehaviorInvocationEventAccepterImpl.hpp"

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
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "fUML/Semantics/CommonBehavior/InvocationEventOccurrence.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Class.hpp"

#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"

#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"

#include "fUML/Semantics/CommonBehavior/Execution.hpp"

#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"

#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"

//Factories an Package includes
#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
ClassifierBehaviorInvocationEventAccepterImpl::ClassifierBehaviorInvocationEventAccepterImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ClassifierBehaviorInvocationEventAccepterImpl::~ClassifierBehaviorInvocationEventAccepterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClassifierBehaviorInvocationEventAccepter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}



ClassifierBehaviorInvocationEventAccepterImpl::ClassifierBehaviorInvocationEventAccepterImpl(const ClassifierBehaviorInvocationEventAccepterImpl & obj):ClassifierBehaviorInvocationEventAccepterImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  ClassifierBehaviorInvocationEventAccepterImpl::copy() const
{
	std::shared_ptr<ClassifierBehaviorInvocationEventAccepterImpl> element(new ClassifierBehaviorInvocationEventAccepterImpl(*this));
	element->setThisClassifierBehaviorInvocationEventAccepterPtr(element);
	return element;
}

ClassifierBehaviorInvocationEventAccepterImpl& ClassifierBehaviorInvocationEventAccepterImpl::operator=(const ClassifierBehaviorInvocationEventAccepterImpl & obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ClassifierBehaviorInvocationEventAccepter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_classifier  = obj.getClassifier();

	m_execution  = obj.getExecution();

	m_objectActivation  = obj.getObjectActivation();


	//Clone references with containment (deep copy)



	return *this;
}

std::shared_ptr<ecore::EClass> ClassifierBehaviorInvocationEventAccepterImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getClassifierBehaviorInvocationEventAccepter_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ClassifierBehaviorInvocationEventAccepterImpl::accept(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Accept an invocation event occurrence. Execute the execution of this
// classifier behavior invocation event accepter.

if(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::InvocationEventOccurrence>(eventOccurrence) != nullptr)
{
	this->getExecution()->execute();
}
	//end of body
}



bool ClassifierBehaviorInvocationEventAccepterImpl::match(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return true if the given event occurrence is an invocation event
// occurrence for the execution of this classifier behavior invocation
// event accepter.

bool matches = false;

if(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::InvocationEventOccurrence>(eventOccurrence) != nullptr)
{
	matches = (std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::InvocationEventOccurrence>(eventOccurrence))->getExecution() == this->getExecution();
}

return matches;
	//end of body
}

void ClassifierBehaviorInvocationEventAccepterImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Terminate the associated execution.
// If the execution is not itself the object of the object activation, then destroy it.

this->getExecution()->terminate();

if(this->getExecution() != this->getObjectActivation()->getObject())
{
	this->getExecution()->destroy();
}
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference classifier
*/
std::shared_ptr<uml::Class > ClassifierBehaviorInvocationEventAccepterImpl::getClassifier() const
{
//assert(m_classifier);
    return m_classifier;
}

void ClassifierBehaviorInvocationEventAccepterImpl::setClassifier(std::shared_ptr<uml::Class> _classifier)
{
    m_classifier = _classifier;
}



/*
Getter & Setter for reference execution
*/
std::shared_ptr<fUML::Semantics::CommonBehavior::Execution > ClassifierBehaviorInvocationEventAccepterImpl::getExecution() const
{
//assert(m_execution);
    return m_execution;
}

void ClassifierBehaviorInvocationEventAccepterImpl::setExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _execution)
{
    m_execution = _execution;
}



/*
Getter & Setter for reference objectActivation
*/
std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation > ClassifierBehaviorInvocationEventAccepterImpl::getObjectActivation() const
{

    return m_objectActivation;
}

void ClassifierBehaviorInvocationEventAccepterImpl::setObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> _objectActivation)
{
    m_objectActivation = _objectActivation;
}



//*********************************
// Union Getter
//*********************************



std::shared_ptr<ClassifierBehaviorInvocationEventAccepter> ClassifierBehaviorInvocationEventAccepterImpl::getThisClassifierBehaviorInvocationEventAccepterPtr() const
{
	return m_thisClassifierBehaviorInvocationEventAccepterPtr.lock();
}
void ClassifierBehaviorInvocationEventAccepterImpl::setThisClassifierBehaviorInvocationEventAccepterPtr(std::weak_ptr<ClassifierBehaviorInvocationEventAccepter> thisClassifierBehaviorInvocationEventAccepterPtr)
{
	m_thisClassifierBehaviorInvocationEventAccepterPtr = thisClassifierBehaviorInvocationEventAccepterPtr;
	setThisEventAccepterPtr(thisClassifierBehaviorInvocationEventAccepterPtr);
}
std::shared_ptr<ecore::EObject> ClassifierBehaviorInvocationEventAccepterImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ClassifierBehaviorInvocationEventAccepterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_CLASSIFIER:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getClassifier())); //250
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_EXECUTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getExecution())); //251
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_OBJECTACTIVATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getObjectActivation())); //252
	}
	return EventAccepterImpl::eGet(featureID, resolve, coreType);
}
bool ClassifierBehaviorInvocationEventAccepterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_CLASSIFIER:
			return getClassifier() != nullptr; //250
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_EXECUTION:
			return getExecution() != nullptr; //251
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_OBJECTACTIVATION:
			return getObjectActivation() != nullptr; //252
	}
	return EventAccepterImpl::internalEIsSet(featureID);
}
bool ClassifierBehaviorInvocationEventAccepterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_CLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Class> _classifier = std::dynamic_pointer_cast<uml::Class>(_temp);
			setClassifier(_classifier); //250
			return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_EXECUTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _execution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(_temp);
			setExecution(_execution); //251
			return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_OBJECTACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> _objectActivation = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(_temp);
			setObjectActivation(_objectActivation); //252
			return true;
		}
	}

	return EventAccepterImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ClassifierBehaviorInvocationEventAccepterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClassifierBehaviorInvocationEventAccepterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("classifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("classifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("execution");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("execution")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("objectActivation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("objectActivation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	EventAccepterImpl::loadAttributes(loadHandler, attr_list);
}

void ClassifierBehaviorInvocationEventAccepterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorFactory> modelFactory=fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance();

	//load BasePackage Nodes
	EventAccepterImpl::loadNode(nodeName, loadHandler);
}

void ClassifierBehaviorInvocationEventAccepterImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_CLASSIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Class> _classifier = std::dynamic_pointer_cast<uml::Class>( references.front() );
				setClassifier(_classifier);
			}
			
			return;
		}

		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_EXECUTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _execution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>( references.front() );
				setExecution(_execution);
			}
			
			return;
		}

		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_OBJECTACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> _objectActivation = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>( references.front() );
				setObjectActivation(_objectActivation);
			}
			
			return;
		}
	}
	EventAccepterImpl::resolveReferences(featureID, references);
}

void ClassifierBehaviorInvocationEventAccepterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EventAccepterImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ClassifierBehaviorInvocationEventAccepterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();

	

		// Add references
		saveHandler->addReference("classifier", this->getClassifier());
		saveHandler->addReference("execution", this->getExecution());
		saveHandler->addReference("objectActivation", this->getObjectActivation());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

