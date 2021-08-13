#include "uml/impl/StateMachineImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Behavior.hpp"
#include "uml/BehavioralFeature.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Extension.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterSet.hpp"
#include "uml/Port.hpp"
#include "uml/Property.hpp"
#include "uml/Pseudostate.hpp"
#include "uml/Reception.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/Region.hpp"
#include "uml/State.hpp"
#include "uml/StateMachine.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/UseCase.hpp"
#include "uml/Vertex.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StateMachineImpl::StateMachineImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StateMachineImpl::~StateMachineImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StateMachine "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier)
:StateMachineImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}

//Additional constructor for the containments back reference
StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StateMachineImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::Element> par_owner)
:StateMachineImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:StateMachineImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:StateMachineImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


StateMachineImpl::StateMachineImpl(const StateMachineImpl & obj): StateMachineImpl()
{
	*this = obj;
}

StateMachineImpl& StateMachineImpl::operator=(const StateMachineImpl & obj)
{
	//call overloaded =Operator for each base class
	BehaviorImpl::operator=(obj);
	StateMachine::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StateMachine "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::StateMachine>> _extendedStateMachine = obj.getExtendedStateMachine();
	m_extendedStateMachine.reset(new Bag<uml::StateMachine>(*(obj.getExtendedStateMachine().get())));
	std::shared_ptr<Bag<uml::State>> _submachineState = obj.getSubmachineState();
	m_submachineState.reset(new Bag<uml::State>(*(obj.getSubmachineState().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> connectionPointContainer = getConnectionPoint();
	if(nullptr != connectionPointContainer )
	{
		int size = connectionPointContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _connectionPoint=(*connectionPointContainer)[i];
			if(nullptr != _connectionPoint)
			{
				connectionPointContainer->push_back(std::dynamic_pointer_cast<uml::Pseudostate>(_connectionPoint->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container connectionPoint."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr connectionPoint."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Region, uml::NamedElement>> regionContainer = getRegion();
	if(nullptr != regionContainer )
	{
		int size = regionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _region=(*regionContainer)[i];
			if(nullptr != _region)
			{
				regionContainer->push_back(std::dynamic_pointer_cast<uml::Region>(_region->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container region."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr region."<< std::endl;)
	}
	/*Subset*/
	m_connectionPoint->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_region->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> StateMachineImpl::copy() const
{
	std::shared_ptr<StateMachineImpl> element(new StateMachineImpl());
	*element =(*this);
	element->setThisStateMachinePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StateMachineImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStateMachine_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Region> StateMachineImpl::LCA(std::shared_ptr<uml::Vertex> s1,std::shared_ptr<uml::Vertex> s2)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::State> StateMachineImpl::LCAState(std::shared_ptr<uml::Vertex> v1,std::shared_ptr<uml::Vertex> v2)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateMachineImpl::ancestor(std::shared_ptr<uml::Vertex> s1,std::shared_ptr<uml::Vertex> s2)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateMachineImpl::classifier_context(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateMachineImpl::connection_points(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateMachineImpl::context_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateMachineImpl::method(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference connectionPoint
*/
std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> StateMachineImpl::getConnectionPoint() const
{
	if(m_connectionPoint == nullptr)
	{
		/*Subset*/
		m_connectionPoint.reset(new Subset<uml::Pseudostate, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_connectionPoint->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_connectionPoint;
}



/*
Getter & Setter for reference extendedStateMachine
*/
std::shared_ptr<Bag<uml::StateMachine>> StateMachineImpl::getExtendedStateMachine() const
{
	if(m_extendedStateMachine == nullptr)
	{
		m_extendedStateMachine.reset(new Bag<uml::StateMachine>());
		
		
	}

    return m_extendedStateMachine;
}



/*
Getter & Setter for reference region
*/
std::shared_ptr<Subset<uml::Region, uml::NamedElement>> StateMachineImpl::getRegion() const
{
	if(m_region == nullptr)
	{
		/*Subset*/
		m_region.reset(new Subset<uml::Region, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_region->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
//assert(m_region);
    return m_region;
}



/*
Getter & Setter for reference submachineState
*/
std::shared_ptr<Bag<uml::State>> StateMachineImpl::getSubmachineState() const
{
	if(m_submachineState == nullptr)
	{
		m_submachineState.reset(new Bag<uml::State>());
		
		
	}

    return m_submachineState;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> StateMachineImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_attribute->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> StateMachineImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_feature->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

std::shared_ptr<Union<uml::NamedElement>> StateMachineImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> StateMachineImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> StateMachineImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> StateMachineImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> StateMachineImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> StateMachineImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}

std::shared_ptr<Union<uml::Classifier>> StateMachineImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_redefinitionContext;
}

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> StateMachineImpl::getRole() const
{
	if(m_role == nullptr)
	{
		/*SubsetUnion*/
		m_role.reset(new SubsetUnion<uml::ConnectableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_role->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_role;
}




std::shared_ptr<StateMachine> StateMachineImpl::getThisStateMachinePtr() const
{
	return m_thisStateMachinePtr.lock();
}
void StateMachineImpl::setThisStateMachinePtr(std::weak_ptr<StateMachine> thisStateMachinePtr)
{
	m_thisStateMachinePtr = thisStateMachinePtr;
	setThisBehaviorPtr(thisStateMachinePtr);
}
std::shared_ptr<ecore::EObject> StateMachineImpl::eContainer() const
{
	if(auto wp = m_behavioredClassifier.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}
	if(auto wp = m_package.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any StateMachineImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Pseudostate>::iterator iter = getConnectionPoint()->begin();
			Bag<uml::Pseudostate>::iterator end = getConnectionPoint()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22262			
		}
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::StateMachine>::iterator iter = getExtendedStateMachine()->begin();
			Bag<uml::StateMachine>::iterator end = getExtendedStateMachine()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22265			
		}
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_REGION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Region>::iterator iter = getRegion()->begin();
			Bag<uml::Region>::iterator end = getRegion()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22264			
		}
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::State>::iterator iter = getSubmachineState()->begin();
			Bag<uml::State>::iterator end = getSubmachineState()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22263			
		}
	}
	return BehaviorImpl::eGet(featureID, resolve, coreType);
}
bool StateMachineImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT:
			return getConnectionPoint() != nullptr; //22262
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
			return getExtendedStateMachine() != nullptr; //22265
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_REGION:
			return getRegion() != nullptr; //22264
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
			return getSubmachineState() != nullptr; //22263
	}
	return BehaviorImpl::internalEIsSet(featureID);
}
bool StateMachineImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Pseudostate>> connectionPointList(new Bag<uml::Pseudostate>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				connectionPointList->add(std::dynamic_pointer_cast<uml::Pseudostate>(*iter));
				iter++;
			}
			
			Bag<uml::Pseudostate>::iterator iterConnectionPoint = getConnectionPoint()->begin();
			Bag<uml::Pseudostate>::iterator endConnectionPoint = getConnectionPoint()->end();
			while (iterConnectionPoint != endConnectionPoint)
			{
				if (connectionPointList->find(*iterConnectionPoint) == -1)
				{
					getConnectionPoint()->erase(*iterConnectionPoint);
				}
				iterConnectionPoint++;
			}
 
			iterConnectionPoint = connectionPointList->begin();
			endConnectionPoint = connectionPointList->end();
			while (iterConnectionPoint != endConnectionPoint)
			{
				if (getConnectionPoint()->find(*iterConnectionPoint) == -1)
				{
					getConnectionPoint()->add(*iterConnectionPoint);
				}
				iterConnectionPoint++;			
			}
			return true;
		}
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::StateMachine>> extendedStateMachineList(new Bag<uml::StateMachine>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				extendedStateMachineList->add(std::dynamic_pointer_cast<uml::StateMachine>(*iter));
				iter++;
			}
			
			Bag<uml::StateMachine>::iterator iterExtendedStateMachine = getExtendedStateMachine()->begin();
			Bag<uml::StateMachine>::iterator endExtendedStateMachine = getExtendedStateMachine()->end();
			while (iterExtendedStateMachine != endExtendedStateMachine)
			{
				if (extendedStateMachineList->find(*iterExtendedStateMachine) == -1)
				{
					getExtendedStateMachine()->erase(*iterExtendedStateMachine);
				}
				iterExtendedStateMachine++;
			}
 
			iterExtendedStateMachine = extendedStateMachineList->begin();
			endExtendedStateMachine = extendedStateMachineList->end();
			while (iterExtendedStateMachine != endExtendedStateMachine)
			{
				if (getExtendedStateMachine()->find(*iterExtendedStateMachine) == -1)
				{
					getExtendedStateMachine()->add(*iterExtendedStateMachine);
				}
				iterExtendedStateMachine++;			
			}
			return true;
		}
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_REGION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Region>> regionList(new Bag<uml::Region>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				regionList->add(std::dynamic_pointer_cast<uml::Region>(*iter));
				iter++;
			}
			
			Bag<uml::Region>::iterator iterRegion = getRegion()->begin();
			Bag<uml::Region>::iterator endRegion = getRegion()->end();
			while (iterRegion != endRegion)
			{
				if (regionList->find(*iterRegion) == -1)
				{
					getRegion()->erase(*iterRegion);
				}
				iterRegion++;
			}
 
			iterRegion = regionList->begin();
			endRegion = regionList->end();
			while (iterRegion != endRegion)
			{
				if (getRegion()->find(*iterRegion) == -1)
				{
					getRegion()->add(*iterRegion);
				}
				iterRegion++;			
			}
			return true;
		}
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::State>> submachineStateList(new Bag<uml::State>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				submachineStateList->add(std::dynamic_pointer_cast<uml::State>(*iter));
				iter++;
			}
			
			Bag<uml::State>::iterator iterSubmachineState = getSubmachineState()->begin();
			Bag<uml::State>::iterator endSubmachineState = getSubmachineState()->end();
			while (iterSubmachineState != endSubmachineState)
			{
				if (submachineStateList->find(*iterSubmachineState) == -1)
				{
					getSubmachineState()->erase(*iterSubmachineState);
				}
				iterSubmachineState++;
			}
 
			iterSubmachineState = submachineStateList->begin();
			endSubmachineState = submachineStateList->end();
			while (iterSubmachineState != endSubmachineState)
			{
				if (getSubmachineState()->find(*iterSubmachineState) == -1)
				{
					getSubmachineState()->add(*iterSubmachineState);
				}
				iterSubmachineState++;			
			}
			return true;
		}
	}

	return BehaviorImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any StateMachineImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 22400
		case umlPackage::STATEMACHINE_OPERATION_LCA_VERTEX_VERTEX:
		{
			//Retrieve input parameter 's1'
			//parameter 0
			std::shared_ptr<uml::Vertex> incoming_param_s1;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_s1_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_s1 = (*incoming_param_s1_arguments_citer)->get()->get<std::shared_ptr<uml::Vertex> >();
			//Retrieve input parameter 's2'
			//parameter 1
			std::shared_ptr<uml::Vertex> incoming_param_s2;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_s2_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_s2 = (*incoming_param_s2_arguments_citer)->get()->get<std::shared_ptr<uml::Vertex> >();
			result = eAny(this->LCA(incoming_param_s1,incoming_param_s2));
			break;
		}
		
		// 22402
		case umlPackage::STATEMACHINE_OPERATION_LCASTATE_VERTEX_VERTEX:
		{
			//Retrieve input parameter 'v1'
			//parameter 0
			std::shared_ptr<uml::Vertex> incoming_param_v1;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_v1_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_v1 = (*incoming_param_v1_arguments_citer)->get()->get<std::shared_ptr<uml::Vertex> >();
			//Retrieve input parameter 'v2'
			//parameter 1
			std::shared_ptr<uml::Vertex> incoming_param_v2;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_v2_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_v2 = (*incoming_param_v2_arguments_citer)->get()->get<std::shared_ptr<uml::Vertex> >();
			result = eAny(this->LCAState(incoming_param_v1,incoming_param_v2));
			break;
		}
		
		// 22401
		case umlPackage::STATEMACHINE_OPERATION_ANCESTOR_VERTEX_VERTEX:
		{
			//Retrieve input parameter 's1'
			//parameter 0
			std::shared_ptr<uml::Vertex> incoming_param_s1;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_s1_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_s1 = (*incoming_param_s1_arguments_citer)->get()->get<std::shared_ptr<uml::Vertex> >();
			//Retrieve input parameter 's2'
			//parameter 1
			std::shared_ptr<uml::Vertex> incoming_param_s2;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_s2_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_s2 = (*incoming_param_s2_arguments_citer)->get()->get<std::shared_ptr<uml::Vertex> >();
			result = eAny(this->ancestor(incoming_param_s1,incoming_param_s2));
			break;
		}
		
		// 22397
		case umlPackage::STATEMACHINE_OPERATION_CLASSIFIER_CONTEXT_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->classifier_context(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 22396
		case umlPackage::STATEMACHINE_OPERATION_CONNECTION_POINTS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->connection_points(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 22399
		case umlPackage::STATEMACHINE_OPERATION_CONTEXT_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->context_classifier(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 22398
		case umlPackage::STATEMACHINE_OPERATION_METHOD_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->method(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = BehaviorImpl::eInvoke(operationID, arguments);
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
void StateMachineImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void StateMachineImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("extendedStateMachine");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("extendedStateMachine")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("submachineState");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("submachineState")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	BehaviorImpl::loadAttributes(loadHandler, attr_list);
}

void StateMachineImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("connectionPoint") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Pseudostate";
			}
			loadHandler->handleChildContainer<uml::Pseudostate>(this->getConnectionPoint());  

			return; 
		}

		if ( nodeName.compare("region") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Region";
			}
			loadHandler->handleChildContainer<uml::Region>(this->getRegion());  

			return; 
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
	//load BasePackage Nodes
	BehaviorImpl::loadNode(nodeName, loadHandler);
}

void StateMachineImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
		{
			std::shared_ptr<Bag<uml::StateMachine>> _extendedStateMachine = getExtendedStateMachine();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::StateMachine>  _r = std::dynamic_pointer_cast<uml::StateMachine>(ref);
				if (_r != nullptr)
				{
					_extendedStateMachine->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
		{
			std::shared_ptr<Bag<uml::State>> _submachineState = getSubmachineState();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::State>  _r = std::dynamic_pointer_cast<uml::State>(ref);
				if (_r != nullptr)
				{
					_submachineState->push_back(_r);
				}
			}
			return;
		}
	}
	BehaviorImpl::resolveReferences(featureID, references);
}

void StateMachineImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehaviorImpl::saveContent(saveHandler);
	
	ClassImpl::saveContent(saveHandler);
	
	BehavioredClassifierImpl::saveContent(saveHandler);
	EncapsulatedClassifierImpl::saveContent(saveHandler);
	
	StructuredClassifierImpl::saveContent(saveHandler);
	
	ClassifierImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
	
	
	
}

void StateMachineImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'connectionPoint'
		for (std::shared_ptr<uml::Pseudostate> connectionPoint : *this->getConnectionPoint()) 
		{
			saveHandler->addReference(connectionPoint, "connectionPoint", connectionPoint->eClass() != package->getPseudostate_Class());
		}

		// Save 'region'
		for (std::shared_ptr<uml::Region> region : *this->getRegion()) 
		{
			saveHandler->addReference(region, "region", region->eClass() != package->getRegion_Class());
		}
	// Add references
		saveHandler->addReferences<uml::StateMachine>("extendedStateMachine", this->getExtendedStateMachine());
		saveHandler->addReferences<uml::State>("submachineState", this->getSubmachineState());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

