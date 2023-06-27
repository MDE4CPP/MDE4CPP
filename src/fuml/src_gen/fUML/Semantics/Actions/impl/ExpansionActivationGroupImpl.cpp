
#include "fUML/Semantics/Actions/impl/ExpansionActivationGroupImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
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
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/ExpansionNodeActivation.hpp"
#include "fUML/Semantics/Actions/ExpansionRegionActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

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
	fUML::Semantics::Activities::ActivityNodeActivationGroupImpl::operator=(obj);
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

std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ExpansionActivationGroupImpl::getNodeActivation(const std::shared_ptr<uml::ActivityNode>& node)
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

	Bag<fUML::Semantics::Actions::ExpansionNodeActivation>::iterator iter = m_groupInputs->begin();
	Bag<fUML::Semantics::Actions::ExpansionNodeActivation>::iterator end = m_groupInputs->end();

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

void ExpansionActivationGroupImpl::resume(const std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>& activation)
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

void ExpansionActivationGroupImpl::suspend(const std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>& activation)
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
const std::shared_ptr<Bag<fUML::Semantics::Actions::ExpansionNodeActivation>>& ExpansionActivationGroupImpl::getGroupInputs() const
{
	if(m_groupInputs == nullptr)
	{
		m_groupInputs.reset(new Bag<fUML::Semantics::Actions::ExpansionNodeActivation>());
		
		
	}
    return m_groupInputs;
}

/* Getter & Setter for reference groupOutputs */
const std::shared_ptr<Bag<fUML::Semantics::Actions::ExpansionNodeActivation>>& ExpansionActivationGroupImpl::getGroupOutputs() const
{
	if(m_groupOutputs == nullptr)
	{
		m_groupOutputs.reset(new Bag<fUML::Semantics::Actions::ExpansionNodeActivation>());
		
		
	}
    return m_groupOutputs;
}

/* Getter & Setter for reference regionActivation */
const std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation>& ExpansionActivationGroupImpl::getRegionActivation() const
{
    return m_regionActivation;
}
void ExpansionActivationGroupImpl::setRegionActivation(const std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation>& _regionActivation)
{
    m_regionActivation = _regionActivation;
	
}

/* Getter & Setter for reference regionInputs */
const std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>>& ExpansionActivationGroupImpl::getRegionInputs() const
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

	fUML::Semantics::Activities::ActivityNodeActivationGroupImpl::loadAttributes(loadHandler, attr_list);
}

void ExpansionActivationGroupImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Activities::ActivityNodeActivationGroupImpl::loadNode(nodeName, loadHandler);
}

void ExpansionActivationGroupImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Actions::ExpansionNodeActivation>> _groupInputs = getGroupInputs();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivation>  _r = std::dynamic_pointer_cast<fUML::Semantics::Actions::ExpansionNodeActivation>(ref);
				if (_r != nullptr)
				{
					_groupInputs->push_back(_r);
				}
			}
			return;
		}

		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Actions::ExpansionNodeActivation>> _groupOutputs = getGroupOutputs();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivation>  _r = std::dynamic_pointer_cast<fUML::Semantics::Actions::ExpansionNodeActivation>(ref);
				if (_r != nullptr)
				{
					_groupOutputs->push_back(_r);
				}
			}
			return;
		}

		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation> _regionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ExpansionRegionActivation>( references.front() );
				setRegionActivation(_regionActivation);
			}
			
			return;
		}

		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _regionInputs = getRegionInputs();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
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
	fUML::Semantics::Activities::ActivityNodeActivationGroupImpl::resolveReferences(featureID, references);
}

void ExpansionActivationGroupImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Activities::ActivityNodeActivationGroupImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExpansionActivationGroupImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getExpansionActivationGroup_Attribute_index()) )
		{
			saveHandler->addAttribute("index", this->getIndex());
		}
	// Add references
		saveHandler->addReferences<fUML::Semantics::Actions::ExpansionNodeActivation>("groupInputs", this->getGroupInputs());
		saveHandler->addReferences<fUML::Semantics::Actions::ExpansionNodeActivation>("groupOutputs", this->getGroupOutputs());
		saveHandler->addReference(this->getRegionActivation(), "regionActivation", getRegionActivation()->eClass() != fUML::Semantics::Actions::ActionsPackage::eInstance()->getExpansionRegionActivation_Class()); 
		saveHandler->addReferences<fUML::Semantics::Actions::OutputPinActivation>("regionInputs", this->getRegionInputs());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ExpansionActivationGroupImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getExpansionActivationGroup_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ExpansionActivationGroupImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS:
			return eEcoreContainerAny(getGroupInputs(),fUML::Semantics::Actions::ActionsPackage::EXPANSIONNODEACTIVATION_CLASS); //495
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
			return eEcoreContainerAny(getGroupOutputs(),fUML::Semantics::Actions::ActionsPackage::EXPANSIONNODEACTIVATION_CLASS); //496
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX:
			return eAny(getIndex(),ecore::ecorePackage::EINT_CLASS,false); //497
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION:
			return eAny(getRegionActivation(),fUML::Semantics::Actions::ActionsPackage::EXPANSIONREGIONACTIVATION_CLASS,false); //498
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS:
			return eEcoreContainerAny(getRegionInputs(),fUML::Semantics::Actions::ActionsPackage::OUTPUTPINACTIVATION_CLASS); //499
	}
	return fUML::Semantics::Activities::ActivityNodeActivationGroupImpl::eGet(featureID, resolve, coreType);
}

bool ExpansionActivationGroupImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS:
			return getGroupInputs() != nullptr; //495
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
			return getGroupOutputs() != nullptr; //496
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX:
			return getIndex() != 0; //497
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION:
			return getRegionActivation() != nullptr; //498
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS:
			return getRegionInputs() != nullptr; //499
	}
	return fUML::Semantics::Activities::ActivityNodeActivationGroupImpl::internalEIsSet(featureID);
}

bool ExpansionActivationGroupImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<fUML::Semantics::Actions::ExpansionNodeActivation>> _groupInputs = getGroupInputs();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivation> valueToAdd = std::dynamic_pointer_cast<fUML::Semantics::Actions::ExpansionNodeActivation>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_groupInputs->includes(valueToAdd)))
								{
									_groupInputs->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'groupInputs'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'groupInputs'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<fUML::Semantics::Actions::ExpansionNodeActivation>> _groupOutputs = getGroupOutputs();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivation> valueToAdd = std::dynamic_pointer_cast<fUML::Semantics::Actions::ExpansionNodeActivation>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_groupOutputs->includes(valueToAdd)))
								{
									_groupOutputs->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'groupOutputs'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'groupOutputs'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX:
		{
			try
			{
				int _index = newValue->get<int>();
				setIndex(_index); //497
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'index'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation> _regionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ExpansionRegionActivation>(eObject);
					if(_regionActivation)
					{
						setRegionActivation(_regionActivation); //498
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'regionActivation'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'regionActivation'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _regionInputs = getRegionInputs();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> valueToAdd = std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_regionInputs->includes(valueToAdd)))
								{
									_regionInputs->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'regionInputs'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'regionInputs'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return fUML::Semantics::Activities::ActivityNodeActivationGroupImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ExpansionActivationGroupImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::ExpansionActivationGroup::getActivityExecution() : fUML::Semantics::Activities::ActivityExecution {const}: 466733328
		case ActionsPackage::EXPANSIONACTIVATIONGROUP_OPERATION_GETACTIVITYEXECUTION:
		{
			result = eEcoreAny(this->getActivityExecution().lock(), fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_CLASS);
			break;
		}
		// fUML::Semantics::Actions::ExpansionActivationGroup::getNodeActivation(uml::ActivityNode) : fUML::Semantics::Activities::ActivityNodeActivation: 2828128313
		case ActionsPackage::EXPANSIONACTIVATIONGROUP_OPERATION_GETNODEACTIVATION_ACTIVITYNODE:
		{
			//Retrieve input parameter 'node'
			//parameter 0
			std::shared_ptr<uml::ActivityNode> incoming_param_node;
			Bag<Any>::const_iterator incoming_param_node_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_node_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_node = std::dynamic_pointer_cast<uml::ActivityNode>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'node'. Failed to invoke operation 'getNodeActivation'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'node'. Failed to invoke operation 'getNodeActivation'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->getNodeActivation(incoming_param_node), fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_CLASS);
			break;
		}
		// fUML::Semantics::Actions::ExpansionActivationGroup::resume(fUML::Semantics::Activities::ActivityNodeActivation): 1335215127
		case ActionsPackage::EXPANSIONACTIVATIONGROUP_OPERATION_RESUME_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'activation'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> incoming_param_activation;
			Bag<Any>::const_iterator incoming_param_activation_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_activation_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_activation = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'activation'. Failed to invoke operation 'resume'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'activation'. Failed to invoke operation 'resume'!")
					return nullptr;
				}
			}
		
			this->resume(incoming_param_activation);
			break;
		}
		// fUML::Semantics::Actions::ExpansionActivationGroup::suspend(fUML::Semantics::Activities::ActivityNodeActivation): 3809461000
		case ActionsPackage::EXPANSIONACTIVATIONGROUP_OPERATION_SUSPEND_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'activation'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> incoming_param_activation;
			Bag<Any>::const_iterator incoming_param_activation_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_activation_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_activation = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'activation'. Failed to invoke operation 'suspend'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'activation'. Failed to invoke operation 'suspend'!")
					return nullptr;
				}
			}
		
			this->suspend(incoming_param_activation);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Activities::ActivityNodeActivationGroupImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroup> ExpansionActivationGroupImpl::getThisExpansionActivationGroupPtr() const
{
	return m_thisExpansionActivationGroupPtr.lock();
}
void ExpansionActivationGroupImpl::setThisExpansionActivationGroupPtr(std::weak_ptr<fUML::Semantics::Actions::ExpansionActivationGroup> thisExpansionActivationGroupPtr)
{
	m_thisExpansionActivationGroupPtr = thisExpansionActivationGroupPtr;
	setThisActivityNodeActivationGroupPtr(thisExpansionActivationGroupPtr);
}


