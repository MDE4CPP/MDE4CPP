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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "uml/ExpansionNode.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ExpansionNodeActivation.hpp"
#include "fUML/Semantics/Activities/ExpansionRegionActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	ExpansionActivationGroup::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionActivationGroup "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_index = obj.getIndex();

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> _groupInputs = obj.getGroupInputs();
	m_groupInputs.reset(new Bag<fUML::Semantics::Activities::ExpansionNodeActivation>(*(obj.getGroupInputs().get())));
	std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> _groupOutputs = obj.getGroupOutputs();
	m_groupOutputs.reset(new Bag<fUML::Semantics::Activities::ExpansionNodeActivation>(*(obj.getGroupOutputs().get())));
	m_regionActivation  = obj.getRegionActivation();
	std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _regionInputs = obj.getRegionInputs();
	m_regionInputs.reset(new Bag<fUML::Semantics::Actions::OutputPinActivation>(*(obj.getRegionInputs().get())));
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

std::shared_ptr<ecore::EClass> ExpansionActivationGroupImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getExpansionActivationGroup_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute index
*/
int ExpansionActivationGroupImpl::getIndex() const 
{
	return m_index;
}
void ExpansionActivationGroupImpl::setIndex(int _index)
{
	m_index = _index;
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
// References
//*********************************
/*
Getter & Setter for reference groupInputs
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> ExpansionActivationGroupImpl::getGroupInputs() const
{
	if(m_groupInputs == nullptr)
	{
		m_groupInputs.reset(new Bag<fUML::Semantics::Activities::ExpansionNodeActivation>());
		
		
	}

    return m_groupInputs;
}



/*
Getter & Setter for reference groupOutputs
*/
std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> ExpansionActivationGroupImpl::getGroupOutputs() const
{
	if(m_groupOutputs == nullptr)
	{
		m_groupOutputs.reset(new Bag<fUML::Semantics::Activities::ExpansionNodeActivation>());
		
		
	}

    return m_groupOutputs;
}



/*
Getter & Setter for reference regionActivation
*/
std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> ExpansionActivationGroupImpl::getRegionActivation() const
{
//assert(m_regionActivation);
    return m_regionActivation;
}
void ExpansionActivationGroupImpl::setRegionActivation(std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> _regionActivation)
{
    m_regionActivation = _regionActivation;
}


/*
Getter & Setter for reference regionInputs
*/
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



std::shared_ptr<ExpansionActivationGroup> ExpansionActivationGroupImpl::getThisExpansionActivationGroupPtr() const
{
	return m_thisExpansionActivationGroupPtr.lock();
}
void ExpansionActivationGroupImpl::setThisExpansionActivationGroupPtr(std::weak_ptr<ExpansionActivationGroup> thisExpansionActivationGroupPtr)
{
	m_thisExpansionActivationGroupPtr = thisExpansionActivationGroupPtr;
	setThisActivityNodeActivationGroupPtr(thisExpansionActivationGroupPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any ExpansionActivationGroupImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS:
		{
			return eAny(getGroupInputs()); //495			
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
		{
			return eAny(getGroupOutputs()); //496			
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX:
			return eAny(getIndex()); //497
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION:
			return eAny(getRegionActivation()); //498
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS:
		{
			return eAny(getRegionInputs()); //499			
		}
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
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> groupInputsList(new Bag<fUML::Semantics::Activities::ExpansionNodeActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				groupInputsList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionNodeActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::ExpansionNodeActivation>::iterator iterGroupInputs = m_groupInputs->begin();
			Bag<fUML::Semantics::Activities::ExpansionNodeActivation>::iterator endGroupInputs = m_groupInputs->end();
			while (iterGroupInputs != endGroupInputs)
			{
				if (groupInputsList->find(*iterGroupInputs) == -1)
				{
					m_groupInputs->erase(*iterGroupInputs);
				}
				iterGroupInputs++;
			}
 
			iterGroupInputs = groupInputsList->begin();
			endGroupInputs = groupInputsList->end();
			while (iterGroupInputs != endGroupInputs)
			{
				if (m_groupInputs->find(*iterGroupInputs) == -1)
				{
					m_groupInputs->add(*iterGroupInputs);
				}
				iterGroupInputs++;			
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> groupOutputsList(new Bag<fUML::Semantics::Activities::ExpansionNodeActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				groupOutputsList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionNodeActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::ExpansionNodeActivation>::iterator iterGroupOutputs = m_groupOutputs->begin();
			Bag<fUML::Semantics::Activities::ExpansionNodeActivation>::iterator endGroupOutputs = m_groupOutputs->end();
			while (iterGroupOutputs != endGroupOutputs)
			{
				if (groupOutputsList->find(*iterGroupOutputs) == -1)
				{
					m_groupOutputs->erase(*iterGroupOutputs);
				}
				iterGroupOutputs++;
			}
 
			iterGroupOutputs = groupOutputsList->begin();
			endGroupOutputs = groupOutputsList->end();
			while (iterGroupOutputs != endGroupOutputs)
			{
				if (m_groupOutputs->find(*iterGroupOutputs) == -1)
				{
					m_groupOutputs->add(*iterGroupOutputs);
				}
				iterGroupOutputs++;			
			}
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX:
		{
			// BOOST CAST
			int _index = newValue->get<int>();
			setIndex(_index); //497
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> _regionActivation = std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionRegionActivation>(_temp);
			setRegionActivation(_regionActivation); //498
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> regionInputsList(new Bag<fUML::Semantics::Actions::OutputPinActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				regionInputsList->add(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator iterRegionInputs = m_regionInputs->begin();
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator endRegionInputs = m_regionInputs->end();
			while (iterRegionInputs != endRegionInputs)
			{
				if (regionInputsList->find(*iterRegionInputs) == -1)
				{
					m_regionInputs->erase(*iterRegionInputs);
				}
				iterRegionInputs++;
			}
 
			iterRegionInputs = regionInputsList->begin();
			endRegionInputs = regionInputsList->end();
			while (iterRegionInputs != endRegionInputs)
			{
				if (m_regionInputs->find(*iterRegionInputs) == -1)
				{
					m_regionInputs->add(*iterRegionInputs);
				}
				iterRegionInputs++;			
			}
			return true;
		}
	}

	return ActivityNodeActivationGroupImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ExpansionActivationGroupImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 4927
		case ActivitiesPackage::EXPANSIONACTIVATIONGROUP_OPERATION_GETACTIVITYEXECUTION:
		{
			result = eAny(this->getActivityExecution());
			break;
		}
		
		// 4928
		case ActivitiesPackage::EXPANSIONACTIVATIONGROUP_OPERATION_GETNODEACTIVATION_ACTIVITYNODE:
		{
			//Retrieve input parameter 'node'
			//parameter 0
			std::shared_ptr<uml::ActivityNode> incoming_param_node;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_node_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_node = (*incoming_param_node_arguments_citer)->get()->get<std::shared_ptr<uml::ActivityNode> >();
			result = eAny(this->getNodeActivation(incoming_param_node));
			break;
		}
		
		// 4929
		case ActivitiesPackage::EXPANSIONACTIVATIONGROUP_OPERATION_RESUME_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'activation'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> incoming_param_activation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_activation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_activation = (*incoming_param_activation_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> >();
			this->resume(incoming_param_activation);
			break;
		}
		
		// 4930
		case ActivitiesPackage::EXPANSIONACTIVATIONGROUP_OPERATION_SUSPEND_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'activation'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> incoming_param_activation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_activation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_activation = (*incoming_param_activation_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> >();
			this->suspend(incoming_param_activation);
			break;
		}

		default:
		{
			// call superTypes
			result = ActivityNodeActivationGroupImpl::eInvoke(operationID, arguments);
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
			std::istringstream ( iter->second ) >> value;
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

