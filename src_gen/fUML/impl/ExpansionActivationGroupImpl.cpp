#include "fUML/impl/ExpansionActivationGroupImpl.hpp"

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

#include "fUML/ActivityEdgeInstance.hpp"

#include "fUML/ActivityExecution.hpp"

#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/ExpansionRegionActivation.hpp"

#include "fUML/StructuredActivityNodeActivation.hpp"

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
ExpansionActivationGroupImpl::ExpansionActivationGroupImpl()
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

ExpansionActivationGroupImpl::~ExpansionActivationGroupImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionActivationGroup "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExpansionActivationGroupImpl::ExpansionActivationGroupImpl(std::weak_ptr<fUML::ActivityExecution > par_activityExecution)
			:ExpansionActivationGroupImpl()
			{
			    m_activityExecution = par_activityExecution;
			}





//Additional constructor for the containments back reference
			ExpansionActivationGroupImpl::ExpansionActivationGroupImpl(std::weak_ptr<fUML::StructuredActivityNodeActivation > par_containingNodeActivation)
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

	//copy references with no containment (soft copy)
	
	m_activityExecution  = obj.getActivityExecution();

	m_containingNodeActivation  = obj.getContainingNodeActivation();

	m_regionActivation  = obj.getRegionActivation();

	std::shared_ptr<Bag<fUML::ActivityNodeActivation>> _suspendedActivations = obj.getSuspendedActivations();
	m_suspendedActivations.reset(new Bag<fUML::ActivityNodeActivation>(*(obj.getSuspendedActivations().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _edgeInstancesList = obj.getEdgeInstances();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _edgeInstances : *_edgeInstancesList)
	{
		this->getEdgeInstances()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_edgeInstances->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_edgeInstances" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityNodeActivation>> _nodeActivationsList = obj.getNodeActivations();
	for(std::shared_ptr<fUML::ActivityNodeActivation> _nodeActivations : *_nodeActivationsList)
	{
		this->getNodeActivations()->add(std::shared_ptr<fUML::ActivityNodeActivation>(std::dynamic_pointer_cast<fUML::ActivityNodeActivation>(_nodeActivations->copy())));
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
	return FUMLPackageImpl::eInstance()->getExpansionActivationGroup_EClass();
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
std::shared_ptr<fUML::ExpansionRegionActivation > ExpansionActivationGroupImpl::getRegionActivation() const
{
//assert(m_regionActivation);
    return m_regionActivation;
}
void ExpansionActivationGroupImpl::setRegionActivation(std::shared_ptr<fUML::ExpansionRegionActivation> _regionActivation)
{
    m_regionActivation = _regionActivation;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ExpansionActivationGroup> ExpansionActivationGroupImpl::getThisExpansionActivationGroupPtr()
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
		case FUMLPackage::EXPANSIONACTIVATIONGROUP_EREFERENCE_REGIONACTIVATION:
			return eAny(getRegionActivation()); //755
	}
	return ActivityNodeActivationGroupImpl::eGet(featureID, resolve, coreType);
}
bool ExpansionActivationGroupImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::EXPANSIONACTIVATIONGROUP_EREFERENCE_REGIONACTIVATION:
			return getRegionActivation() != nullptr; //755
	}
	return ActivityNodeActivationGroupImpl::internalEIsSet(featureID);
}
bool ExpansionActivationGroupImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EXPANSIONACTIVATIONGROUP_EREFERENCE_REGIONACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ExpansionRegionActivation> _regionActivation = newValue->get<std::shared_ptr<fUML::ExpansionRegionActivation>>();
			setRegionActivation(_regionActivation); //755
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
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void ExpansionActivationGroupImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("regionActivation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("regionActivation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ExpansionActivationGroupImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ActivityNodeActivationGroupImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExpansionActivationGroupImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::EXPANSIONACTIVATIONGROUP_EREFERENCE_REGIONACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::ExpansionRegionActivation> _regionActivation = std::dynamic_pointer_cast<fUML::ExpansionRegionActivation>( references.front() );
				setRegionActivation(_regionActivation);
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		saveHandler->addReference("regionActivation", this->getRegionActivation());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

