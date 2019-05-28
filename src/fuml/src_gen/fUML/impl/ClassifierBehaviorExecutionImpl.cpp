#include "fUML/impl/ClassifierBehaviorExecutionImpl.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Class.hpp"

#include "fUML/Execution.hpp"

#include "fUML/ObjectActivation.hpp"

#include "fUML/ParameterValue.hpp"

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
ClassifierBehaviorExecutionImpl::ClassifierBehaviorExecutionImpl()
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

ClassifierBehaviorExecutionImpl::~ClassifierBehaviorExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClassifierBehaviorExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ClassifierBehaviorExecutionImpl::ClassifierBehaviorExecutionImpl(const ClassifierBehaviorExecutionImpl & obj):ClassifierBehaviorExecutionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ClassifierBehaviorExecution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_classifier  = obj.getClassifier();

	m_execution  = obj.getExecution();

	m_objectActivation  = obj.getObjectActivation();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ClassifierBehaviorExecutionImpl::copy() const
{
	std::shared_ptr<ClassifierBehaviorExecutionImpl> element(new ClassifierBehaviorExecutionImpl(*this));
	element->setThisClassifierBehaviorExecutionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ClassifierBehaviorExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClassifierBehaviorExecution_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ClassifierBehaviorExecutionImpl::_startObjectBehavior()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ClassifierBehaviorExecutionImpl::execute(std::shared_ptr<Bag<uml::Class> >  classifier,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ClassifierBehaviorExecutionImpl::terminate()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Class > ClassifierBehaviorExecutionImpl::getClassifier() const
{
//assert(m_classifier);
    return m_classifier;
}
void ClassifierBehaviorExecutionImpl::setClassifier(std::shared_ptr<uml::Class> _classifier)
{
    m_classifier = _classifier;
}

std::shared_ptr<fUML::Execution > ClassifierBehaviorExecutionImpl::getExecution() const
{
//assert(m_execution);
    return m_execution;
}
void ClassifierBehaviorExecutionImpl::setExecution(std::shared_ptr<fUML::Execution> _execution)
{
    m_execution = _execution;
}

std::shared_ptr<fUML::ObjectActivation > ClassifierBehaviorExecutionImpl::getObjectActivation() const
{

    return m_objectActivation;
}
void ClassifierBehaviorExecutionImpl::setObjectActivation(std::shared_ptr<fUML::ObjectActivation> _objectActivation)
{
    m_objectActivation = _objectActivation;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ClassifierBehaviorExecution> ClassifierBehaviorExecutionImpl::getThisClassifierBehaviorExecutionPtr() const
{
	return m_thisClassifierBehaviorExecutionPtr.lock();
}
void ClassifierBehaviorExecutionImpl::setThisClassifierBehaviorExecutionPtr(std::weak_ptr<ClassifierBehaviorExecution> thisClassifierBehaviorExecutionPtr)
{
	m_thisClassifierBehaviorExecutionPtr = thisClassifierBehaviorExecutionPtr;
}
std::shared_ptr<ecore::EObject> ClassifierBehaviorExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ClassifierBehaviorExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_CLASSIFIER:
			return eAny(getClassifier()); //171
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_EXECUTION:
			return eAny(getExecution()); //170
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_OBJECTACTIVATION:
			return eAny(getObjectActivation()); //172
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ClassifierBehaviorExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_CLASSIFIER:
			return getClassifier() != nullptr; //171
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_EXECUTION:
			return getExecution() != nullptr; //170
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_OBJECTACTIVATION:
			return getObjectActivation() != nullptr; //172
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ClassifierBehaviorExecutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_CLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<uml::Class> _classifier = newValue->get<std::shared_ptr<uml::Class>>();
			setClassifier(_classifier); //171
			return true;
		}
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_EXECUTION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Execution> _execution = newValue->get<std::shared_ptr<fUML::Execution>>();
			setExecution(_execution); //170
			return true;
		}
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_OBJECTACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ObjectActivation> _objectActivation = newValue->get<std::shared_ptr<fUML::ObjectActivation>>();
			setObjectActivation(_objectActivation); //172
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ClassifierBehaviorExecutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClassifierBehaviorExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ClassifierBehaviorExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void ClassifierBehaviorExecutionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_CLASSIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Class> _classifier = std::dynamic_pointer_cast<uml::Class>( references.front() );
				setClassifier(_classifier);
			}
			
			return;
		}

		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_EXECUTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Execution> _execution = std::dynamic_pointer_cast<fUML::Execution>( references.front() );
				setExecution(_execution);
			}
			
			return;
		}

		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_OBJECTACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::ObjectActivation> _objectActivation = std::dynamic_pointer_cast<fUML::ObjectActivation>( references.front() );
				setObjectActivation(_objectActivation);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ClassifierBehaviorExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ClassifierBehaviorExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

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

