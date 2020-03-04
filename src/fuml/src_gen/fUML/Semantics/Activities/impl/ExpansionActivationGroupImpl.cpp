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

#include "fUML/Semantics/Activities/ExpansionRegionActivation.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"

//Factories an Package includes
#include "fUML/Semantics/Activities/Impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/Impl/ActivitiesPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionActivationGroupImpl::ExpansionActivationGroupImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_groupInputs.reset(new Bag<fUML::Semantics::Actions::OutputPinActivation>());
	
	

		m_groupOutputs.reset(new Bag<fUML::Semantics::Actions::OutputPinActivation>());
	
	

	

		m_regionInputs.reset(new Bag<fUML::Semantics::Actions::OutputPinActivation>());
	
	

	//Init references
	
	

	
	

	

	
	
}

ExpansionActivationGroupImpl::~ExpansionActivationGroupImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionActivationGroup "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExpansionActivationGroupImpl::ExpansionActivationGroupImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution > par_activityExecution)
			:ExpansionActivationGroupImpl()
			{
			    m_activityExecution = par_activityExecution;
			}


//Additional constructor for the containments back reference
			ExpansionActivationGroupImpl::ExpansionActivationGroupImpl(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation > par_containingNodeActivation)
			:ExpansionActivationGroupImpl()
			{
			    m_containingNodeActivation = par_containingNodeActivation;
			}



ExpansionActivationGroupImpl::ExpansionActivationGroupImpl(const ExpansionActivationGroupImpl & obj):ExpansionActivationGroupImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionActivationGroup "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_index = obj.getIndex();

	//copy references with no containment (soft copy)
	
	m_activityExecution  = obj.getActivityExecution();

	m_containingNodeActivation  = obj.getContainingNodeActivation();

	std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _groupInputs = obj.getGroupInputs();
	m_groupInputs.reset(new Bag<fUML::Semantics::Actions::OutputPinActivation>(*(obj.getGroupInputs().get())));

	std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _groupOutputs = obj.getGroupOutputs();
	m_groupOutputs.reset(new Bag<fUML::Semantics::Actions::OutputPinActivation>(*(obj.getGroupOutputs().get())));

	m_regionActivation  = obj.getRegionActivation();

	std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _regionInputs = obj.getRegionInputs();
	m_regionInputs.reset(new Bag<fUML::Semantics::Actions::OutputPinActivation>(*(obj.getRegionInputs().get())));

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> _suspendedActivations = obj.getSuspendedActivations();
	m_suspendedActivations.reset(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>(*(obj.getSuspendedActivations().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _edgeInstancesList = obj.getEdgeInstances();
	for(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> _edgeInstances : *_edgeInstancesList)
	{
		this->getEdgeInstances()->add(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityEdgeInstance>(_edgeInstances->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_edgeInstances" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> _nodeActivationsList = obj.getNodeActivations();
	for(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _nodeActivations : *_nodeActivationsList)
	{
		this->getNodeActivations()->add(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(_nodeActivations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nodeActivations" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ExpansionActivationGroupImpl::copy() const
{
	std::shared_ptr<ExpansionActivationGroupImpl> element(new ExpansionActivationGroupImpl(*this));
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
void ExpansionActivationGroupImpl::setIndex(int _index)
{
	m_index = _index;
} 

int ExpansionActivationGroupImpl::getIndex() const 
{
	return m_index;
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

std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ExpansionActivationGroupImpl::getNodeActivation(std::shared_ptr<uml::ActivityNode>  node)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = nullptr;
	Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator iter = m_regionInputs->begin();
	Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator end = m_regionInputs->end();
	while ((!activation) and (iter != end))
	{
       	activation =(*iter)->getNodeActivation(node);
       	iter++;
	}

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

void ExpansionActivationGroupImpl::resume(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>  activation)
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

void ExpansionActivationGroupImpl::suspend(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>  activation)
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
std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> ExpansionActivationGroupImpl::getGroupInputs() const
{

    return m_groupInputs;
}


std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> ExpansionActivationGroupImpl::getGroupOutputs() const
{

    return m_groupOutputs;
}


std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation > ExpansionActivationGroupImpl::getRegionActivation() const
{
//assert(m_regionActivation);
    return m_regionActivation;
}
void ExpansionActivationGroupImpl::setRegionActivation(std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> _regionActivation)
{
    m_regionActivation = _regionActivation;
}

std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> ExpansionActivationGroupImpl::getRegionInputs() const
{

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
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator iter = m_groupInputs->begin();
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator end = m_groupInputs->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //495
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator iter = m_groupOutputs->begin();
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator end = m_groupOutputs->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //496
		}
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX:
			return eAny(getIndex()); //497
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getRegionActivation())); //498
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator iter = m_regionInputs->begin();
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator end = m_regionInputs->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //499
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
			std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> groupInputsList(new Bag<fUML::Semantics::Actions::OutputPinActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				groupInputsList->add(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator iterGroupInputs = m_groupInputs->begin();
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator endGroupInputs = m_groupInputs->end();
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
			std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> groupOutputsList(new Bag<fUML::Semantics::Actions::OutputPinActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				groupOutputsList->add(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator iterGroupOutputs = m_groupOutputs->begin();
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator endGroupOutputs = m_groupOutputs->end();
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
// Persistence Functions
//*********************************
void ExpansionActivationGroupImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
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
	std::shared_ptr<fUML::Semantics::Activities::ActivitiesFactory> modelFactory=fUML::Semantics::Activities::ActivitiesFactory::eInstance();

	//load BasePackage Nodes
	ActivityNodeActivationGroupImpl::loadNode(nodeName, loadHandler);
}

void ExpansionActivationGroupImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _groupInputs = getGroupInputs();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> _r = std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(ref);
				if (_r != nullptr)
				{
					_groupInputs->push_back(_r);
				}				
			}
			return;
		}

		case fUML::Semantics::Activities::ActivitiesPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _groupOutputs = getGroupOutputs();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> _r = std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(ref);
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
				std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> _r = std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(ref);
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
		std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> groupInputs_list = this->getGroupInputs();
		for (std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation > object : *groupInputs_list)
		{ 
			saveHandler->addReferences("groupInputs", object);
		}
		std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> groupOutputs_list = this->getGroupOutputs();
		for (std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation > object : *groupOutputs_list)
		{ 
			saveHandler->addReferences("groupOutputs", object);
		}
		saveHandler->addReference("regionActivation", this->getRegionActivation());
		std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> regionInputs_list = this->getRegionInputs();
		for (std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation > object : *regionInputs_list)
		{ 
			saveHandler->addReferences("regionInputs", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

