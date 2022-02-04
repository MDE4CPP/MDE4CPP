
#include "fUML/Semantics/Activities/impl/ExpansionActivationGroupImpl.hpp"
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


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "uml/ExpansionNode.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ExpansionNodeActivation.hpp"
#include "fUML/Semantics/Activities/ExpansionRegionActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionActivationGroupImpl::ExpansionActivationGroupImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExpansionActivationGroupImpl::~ExpansionActivationGroupImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionActivationGroup "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExpansionActivationGroupImpl::ExpansionActivationGroupImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> par_activityExecution)
:ExpansionActivationGroupImpl()
{
	m_activityExecution = par_activityExecution;
}

//Additional constructor for the containments back reference
ExpansionActivationGroupImpl::ExpansionActivationGroupImpl(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> par_containingNodeActivation)
:ExpansionActivationGroupImpl()
{
	m_containingNodeActivation = par_containingNodeActivation;
}

ExpansionActivationGroupImpl::ExpansionActivationGroupImpl(const ExpansionActivationGroupImpl & obj): ExpansionActivationGroupImpl()
{
	*this = obj;
}

ExpansionActivationGroupImpl& ExpansionActivationGroupImpl::operator=(const ExpansionActivationGroupImpl & obj)
{
	//call overloaded =Operator for each base class
	ActivityNodeActivationGroupImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExpansionActivationGroup 
	 * which is generated by the compiler (as ExpansionActivationGroup is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExpansionActivationGroup::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionActivationGroup "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_index = obj.getIndex();

	//copy references with no containment (soft copy)
	m_groupInputs  = obj.getGroupInputs();
	m_groupOutputs  = obj.getGroupOutputs();
	m_regionActivation  = obj.getRegionActivation();
	m_regionInputs  = obj.getRegionInputs();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExpansionActivationGroupImpl::copy() const
{
	std::shared_ptr<ExpansionActivationGroupImpl> element(new ExpansionActivationGroupImpl());
	*element =(*this);
	element->setThisExpansionActivationGroupPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> ExpansionActivationGroupImpl::getActivityExecution() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return m_regionActivation->getActivityExecution();
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ExpansionActivationGroupImpl::getNodeActivation(std::shared_ptr<uml::ActivityNode> node)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = nullptr;
	Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator pinIter = m_regionInputs->begin();
	Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator pinEnd = m_regionInputs->end();
	while ((!activation) and (pinIter != pinEnd))
	{
       	activation =(*pinIter)->getNodeActivation(node);
       	pinIter++;
	}

	Bag<fUML::Semantics::Activities::ExpansionNodeActivation>::iterator iter = m_groupInputs->begin();
	Bag<fUML::Semantics::Activities::ExpansionNodeActivation>::iterator end = m_groupInputs->end();

	iter = m_groupInputs->begin();
	end = m_groupInputs->end();
	while ((!activation) and (iter != end))
	{
		activation =(*iter)->getNodeActivation(node);
		iter++;
	}

	iter = m_groupOutputs->begin();
	end = m_groupOutputs->end();
	while ((!activation) and (iter != end))
	{
		activation =(*iter)->getNodeActivation(node);
		iter++;
	}

	if (activation == nullptr)
	{
		return ActivityNodeActivationGroupImpl::getNodeActivation(node);
	}

	return activation;
	//end of body
}

void ExpansionActivationGroupImpl::resume(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	ActivityNodeActivationGroupImpl::resume(activation);
	if (isSuspended())
	{
		m_regionActivation->resume(getThisExpansionActivationGroupPtr());
	}
	//end of body
}

void ExpansionActivationGroupImpl::suspend(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (!isSuspended())
	{
		m_regionActivation->suspend();
	}
	ActivityNodeActivationGroupImpl::suspend(activation);
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute index */
int ExpansionActivationGroupImpl::getIndex() const 
{
	return m_index;
}
void ExpansionActivationGroupImpl::setIndex(int _index)
{
	m_index = _index;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference groupInputs */
std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> ExpansionActivationGroupImpl::getGroupInputs() const
{
	if(m_groupInputs == nullptr)
	{
		m_groupInputs.reset(new Bag<fUML::Semantics::Activities::ExpansionNodeActivation>());
		
		
	}
    return m_groupInputs;
}

/* Getter & Setter for reference groupOutputs */
std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> ExpansionActivationGroupImpl::getGroupOutputs() const
{
	if(m_groupOutputs == nullptr)
	{
		m_groupOutputs.reset(new Bag<fUML::Semantics::Activities::ExpansionNodeActivation>());
		
		
	}
    return m_groupOutputs;
}

/* Getter & Setter for reference regionActivation */
std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> ExpansionActivationGroupImpl::getRegionActivation() const
{
    return m_regionActivation;
}
void ExpansionActivationGroupImpl::setRegionActivation(std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> _regionActivation)
{
    m_regionActivation = _regionActivation;
	
}

/* Getter & Setter for reference regionInputs */
std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> ExpansionActivationGroupImpl::getRegionInputs() const
{
	if(m_regionInputs == nullptr)
	{
		m_regionInputs.reset(new Bag<fUML::Semantics::Actions::OutputPinActivation>());
		
		
	}
    return m_regionInputs;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExpansionActivationGroupImpl::eContainer() const
{
	if(auto wp = m_activityExecution.lock())
	{
		return wp;
	}

	if(auto wp = m_containingNodeActivation.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ExpansionActivationGroupImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExpansionActivationGroupImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("index");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream(iter->second) >> value;
			this->setIndex(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("groupInputs");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("groupInputs")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("groupOutputs");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("groupOutputs")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("regionActivation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("regionActivation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("regionInputs");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("regionInputs")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActivityNodeActivationGroupImpl::loadAttributes(loadHandler, attr_list);
}

void ExpansionActivationGroupImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActivityNodeActivationGroupImpl::loadNode(nodeName, loadHandler);
}

void ExpansionActivationGroupImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> _groupInputs = getGroupInputs();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation>  _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionNodeActivation>(ref);
				if (_r != nullptr)
				{
					_groupInputs->push_back(_r);
				}
			}
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> _groupOutputs = getGroupOutputs();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation>  _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionNodeActivation>(ref);
				if (_r != nullptr)
				{
					_groupOutputs->push_back(_r);
				}
			}
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> _regionActivation = std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionRegionActivation>( references.front() );
				setRegionActivation(_regionActivation);
			}
			
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _regionInputs = getRegionInputs();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation>  _r = std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(ref);
				if (_r != nullptr)
				{
					_regionInputs->push_back(_r);
				}
			}
			return;
		}
	}
	ActivityNodeActivationGroupImpl::resolveReferences(featureID, references);
}

void ExpansionActivationGroupImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityNodeActivationGroupImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExpansionActivationGroupImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getExpansionActivationGroup_Attribute_index()) )
		{
			saveHandler->addAttribute("index", this->getIndex());
		}
	// Add references
		saveHandler->addReferences<fUML::Semantics::Activities::ExpansionNodeActivation>("groupInputs", this->getGroupInputs());
		saveHandler->addReferences<fUML::Semantics::Activities::ExpansionNodeActivation>("groupOutputs", this->getGroupOutputs());
		saveHandler->addReference(this->getRegionActivation(), "regionActivation", getRegionActivation()->eClass() != fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getExpansionRegionActivation_Class()); 
		saveHandler->addReferences<fUML::Semantics::Actions::OutputPinActivation>("regionInputs", this->getRegionInputs());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ExpansionActivationGroupImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getExpansionActivationGroup_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ExpansionActivationGroupImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS:
			return eAnyBag(getGroupInputs(),fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONNODEACTIVATION_CLASS); //495
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
			return eAnyBag(getGroupOutputs(),fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONNODEACTIVATION_CLASS); //496
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX:
			return eAny(getIndex(),ecore::ecorePackage::EINT_CLASS,false); //497
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION:
			return eAny(getRegionActivation(),fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONREGIONACTIVATION_CLASS,false); //498
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS:
			return eAnyBag(getRegionInputs(),fUML::Semantics::Actions::ActionsPackage::OUTPUTPINACTIVATION_CLASS); //499
	}
	return ActivityNodeActivationGroupImpl::eGet(featureID, resolve, coreType);
}

bool ExpansionActivationGroupImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS:
			return getGroupInputs() != nullptr; //495
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
			return getGroupOutputs() != nullptr; //496
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX:
			return getIndex() != 0; //497
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION:
			return getRegionActivation() != nullptr; //498
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS:
			return getRegionInputs() != nullptr; //499
	}
	return ActivityNodeActivationGroupImpl::internalEIsSet(featureID);
}

bool ExpansionActivationGroupImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS:
		{
			// CAST Any to Bag<fUML::Semantics::Activities::ExpansionNodeActivation>
			if((newValue->isContainer()) && (fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONNODEACTIVATION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> groupInputsList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>>>();
					std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> _groupInputs=getGroupInputs();
					for(const std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> indexGroupInputs: *_groupInputs)
					{
						if (groupInputsList->find(indexGroupInputs) == -1)
						{
							_groupInputs->erase(indexGroupInputs);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> indexGroupInputs: *groupInputsList)
					{
						if (_groupInputs->find(indexGroupInputs) == -1)
						{
							_groupInputs->add(indexGroupInputs);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
		{
			// CAST Any to Bag<fUML::Semantics::Activities::ExpansionNodeActivation>
			if((newValue->isContainer()) && (fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONNODEACTIVATION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> groupOutputsList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>>>();
					std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> _groupOutputs=getGroupOutputs();
					for(const std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> indexGroupOutputs: *_groupOutputs)
					{
						if (groupOutputsList->find(indexGroupOutputs) == -1)
						{
							_groupOutputs->erase(indexGroupOutputs);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> indexGroupOutputs: *groupOutputsList)
					{
						if (_groupOutputs->find(indexGroupOutputs) == -1)
						{
							_groupOutputs->add(indexGroupOutputs);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX:
		{
			// CAST Any to int
			int _index = newValue->get<int>();
			setIndex(_index); //497
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION:
		{
			// CAST Any to fUML::Semantics::Activities::ExpansionRegionActivation
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> _regionActivation = std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionRegionActivation>(_temp);
			setRegionActivation(_regionActivation); //498
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS:
		{
			// CAST Any to Bag<fUML::Semantics::Actions::OutputPinActivation>
			if((newValue->isContainer()) && (fUML::Semantics::Actions::ActionsPackage::OUTPUTPINACTIVATION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> regionInputsList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>>>();
					std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _regionInputs=getRegionInputs();
					for(const std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> indexRegionInputs: *_regionInputs)
					{
						if (regionInputsList->find(indexRegionInputs) == -1)
						{
							_regionInputs->erase(indexRegionInputs);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> indexRegionInputs: *regionInputsList)
					{
						if (_regionInputs->find(indexRegionInputs) == -1)
						{
							_regionInputs->add(indexRegionInputs);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
	}

	return ActivityNodeActivationGroupImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ExpansionActivationGroupImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::ExpansionActivationGroup::getActivityExecution() : fUML::Semantics::Activities::ActivityExecution {const}: 3008748080
		case ActivitiesPackage::EXPANSIONACTIVATIONGROUP_OPERATION_GETACTIVITYEXECUTION:
		{
			result = eAnyObject(this->getActivityExecution().lock(), fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_CLASS);
			break;
		}
		// fUML::Semantics::Activities::ExpansionActivationGroup::getNodeActivation(uml::ActivityNode) : fUML::Semantics::Activities::ActivityNodeActivation: 156883141
		case ActivitiesPackage::EXPANSIONACTIVATIONGROUP_OPERATION_GETNODEACTIVATION_ACTIVITYNODE:
		{
			//Retrieve input parameter 'node'
			//parameter 0
			std::shared_ptr<uml::ActivityNode> incoming_param_node;
			std::list<Any>::const_iterator incoming_param_node_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_node = (*incoming_param_node_arguments_citer)->get<std::shared_ptr<uml::ActivityNode> >();
			result = eAnyObject(this->getNodeActivation(incoming_param_node), fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_CLASS);
			break;
		}
		// fUML::Semantics::Activities::ExpansionActivationGroup::resume(fUML::Semantics::Activities::ActivityNodeActivation): 4278059019
		case ActivitiesPackage::EXPANSIONACTIVATIONGROUP_OPERATION_RESUME_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'activation'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> incoming_param_activation;
			std::list<Any>::const_iterator incoming_param_activation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_activation = (*incoming_param_activation_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> >();
			this->resume(incoming_param_activation);
			break;
		}
		// fUML::Semantics::Activities::ExpansionActivationGroup::suspend(fUML::Semantics::Activities::ActivityNodeActivation): 415784904
		case ActivitiesPackage::EXPANSIONACTIVATIONGROUP_OPERATION_SUSPEND_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'activation'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> incoming_param_activation;
			std::list<Any>::const_iterator incoming_param_activation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_activation = (*incoming_param_activation_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> >();
			this->suspend(incoming_param_activation);
			break;
		}

		default:
		{
			// call superTypes
			result = ActivityNodeActivationGroupImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> ExpansionActivationGroupImpl::getThisExpansionActivationGroupPtr() const
{
	return m_thisExpansionActivationGroupPtr.lock();
}
void ExpansionActivationGroupImpl::setThisExpansionActivationGroupPtr(std::weak_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> thisExpansionActivationGroupPtr)
{
	m_thisExpansionActivationGroupPtr = thisExpansionActivationGroupPtr;
	setThisActivityNodeActivationGroupPtr(thisExpansionActivationGroupPtr);
}


