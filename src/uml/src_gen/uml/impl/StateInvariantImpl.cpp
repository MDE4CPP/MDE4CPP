#include "uml/impl/StateInvariantImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionFragment.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StateInvariantImpl::StateInvariantImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StateInvariantImpl::~StateInvariantImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StateInvariant "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StateInvariantImpl::StateInvariantImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:StateInvariantImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
StateInvariantImpl::StateInvariantImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:StateInvariantImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
StateInvariantImpl::StateInvariantImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StateInvariantImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StateInvariantImpl::StateInvariantImpl(std::weak_ptr<uml::Element> par_owner)
:StateInvariantImpl()
{
	m_owner = par_owner;
}

StateInvariantImpl::StateInvariantImpl(const StateInvariantImpl & obj): StateInvariantImpl()
{
	*this = obj;
}

StateInvariantImpl& StateInvariantImpl::operator=(const StateInvariantImpl & obj)
{
	//call overloaded =Operator for each base class
	InteractionFragmentImpl::operator=(obj);
	StateInvariant::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StateInvariant "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'invariant'
	if(obj.getInvariant()!=nullptr)
	{
		m_invariant = std::dynamic_pointer_cast<uml::Constraint>(obj.getInvariant()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> StateInvariantImpl::copy() const
{
	std::shared_ptr<StateInvariantImpl> element(new StateInvariantImpl());
	*element =(*this);
	element->setThisStateInvariantPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StateInvariantImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStateInvariant_Class();
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
/*
Getter & Setter for reference invariant
*/
std::shared_ptr<uml::Constraint> StateInvariantImpl::getInvariant() const
{
    return m_invariant;
}
void StateInvariantImpl::setInvariant(std::shared_ptr<uml::Constraint> _invariant)
{
    m_invariant = _invariant;
	
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> StateInvariantImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> StateInvariantImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> StateInvariantImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<StateInvariant> StateInvariantImpl::getThisStateInvariantPtr() const
{
	return m_thisStateInvariantPtr.lock();
}
void StateInvariantImpl::setThisStateInvariantPtr(std::weak_ptr<StateInvariant> thisStateInvariantPtr)
{
	m_thisStateInvariantPtr = thisStateInvariantPtr;
	setThisInteractionFragmentPtr(thisStateInvariantPtr);
}
std::shared_ptr<ecore::EObject> StateInvariantImpl::eContainer() const
{
	if(auto wp = m_enclosingInteraction.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingOperand.lock())
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any StateInvariantImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STATEINVARIANT_ATTRIBUTE_INVARIANT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getInvariant();
				return eAny(returnValue); //22113
			}
	}
	return InteractionFragmentImpl::eGet(featureID, resolve, coreType);
}
bool StateInvariantImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STATEINVARIANT_ATTRIBUTE_INVARIANT:
			return getInvariant() != nullptr; //22113
	}
	return InteractionFragmentImpl::internalEIsSet(featureID);
}
bool StateInvariantImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STATEINVARIANT_ATTRIBUTE_INVARIANT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Constraint> _invariant = std::dynamic_pointer_cast<uml::Constraint>(_temp);
			setInvariant(_invariant); //22113
			return true;
		}
	}

	return InteractionFragmentImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any StateInvariantImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = InteractionFragmentImpl::eInvoke(operationID, arguments);
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
void StateInvariantImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StateInvariantImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	InteractionFragmentImpl::loadAttributes(loadHandler, attr_list);
}

void StateInvariantImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("invariant") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			loadHandler->handleChild(this->getInvariant()); 

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
	InteractionFragmentImpl::loadNode(nodeName, loadHandler);
}

void StateInvariantImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	InteractionFragmentImpl::resolveReferences(featureID, references);
}

void StateInvariantImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void StateInvariantImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'invariant'
		std::shared_ptr<uml::Constraint> invariant = this->getInvariant();
		if (invariant != nullptr)
		{
			saveHandler->addReference(invariant, "invariant", invariant->eClass() != package->getConstraint_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

