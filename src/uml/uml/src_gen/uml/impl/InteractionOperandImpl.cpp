
#include "uml/impl/InteractionOperandImpl.hpp"
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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionConstraint.hpp"
#include "uml/InteractionFragment.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionOperandImpl::InteractionOperandImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InteractionOperandImpl::~InteractionOperandImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionOperand "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InteractionOperandImpl::InteractionOperandImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:InteractionOperandImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
InteractionOperandImpl::InteractionOperandImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:InteractionOperandImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
InteractionOperandImpl::InteractionOperandImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InteractionOperandImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InteractionOperandImpl::InteractionOperandImpl(std::weak_ptr<uml::Element> par_owner)
:InteractionOperandImpl()
{
	m_owner = par_owner;
}

InteractionOperandImpl::InteractionOperandImpl(const InteractionOperandImpl & obj): InteractionOperandImpl()
{
	*this = obj;
}

InteractionOperandImpl& InteractionOperandImpl::operator=(const InteractionOperandImpl & obj)
{
	//call overloaded =Operator for each base class
	NamespaceImpl::operator=(obj);
	InteractionFragmentImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InteractionOperand 
	 * which is generated by the compiler (as InteractionOperand is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InteractionOperand::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionOperand "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'fragment'
	std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>> fragmentList = obj.getFragment();
	if(fragmentList)
	{
		/*Subset*/
		m_fragment.reset(new Subset<uml::InteractionFragment, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getFragment()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::InteractionFragment>& fragmentindexElem: *fragmentList) 
		{
			std::shared_ptr<uml::InteractionFragment> temp = std::dynamic_pointer_cast<uml::InteractionFragment>((fragmentindexElem)->copy());
			m_fragment->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for fragment.")
	}

	//clone reference 'guard'
	if(obj.getGuard()!=nullptr)
	{
		m_guard = std::dynamic_pointer_cast<uml::InteractionConstraint>(obj.getGuard()->copy());
	}
	/*Subset*/
	getFragment()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> InteractionOperandImpl::copy() const
{
	std::shared_ptr<InteractionOperandImpl> element(new InteractionOperandImpl());
	*element =(*this);
	element->setThisInteractionOperandPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference fragment */
const std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>>& InteractionOperandImpl::getFragment() const
{
	if(m_fragment == nullptr)
	{
		/*Subset*/
		m_fragment.reset(new Subset<uml::InteractionFragment, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getFragment()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_fragment;
}

/* Getter & Setter for reference guard */
const std::shared_ptr<uml::InteractionConstraint>& InteractionOperandImpl::getGuard() const
{
    return m_guard;
}
void InteractionOperandImpl::setGuard(const std::shared_ptr<uml::InteractionConstraint>& _guard)
{
    m_guard = _guard;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InteractionOperandImpl::eContainer() const
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
// Persistence Functions
//*********************************
void InteractionOperandImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InteractionOperandImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	InteractionFragmentImpl::loadAttributes(loadHandler, attr_list);
	NamespaceImpl::loadAttributes(loadHandler, attr_list);
}

void InteractionOperandImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("fragment") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::InteractionFragment>(this->getFragment());  

			return; 
		}

		if ( nodeName.compare("guard") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InteractionConstraint";
			}
			loadHandler->handleChild(this->getGuard()); 

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
	NamespaceImpl::loadNode(nodeName, loadHandler);
}

void InteractionOperandImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	InteractionFragmentImpl::resolveReferences(featureID, references);
	NamespaceImpl::resolveReferences(featureID, references);
}

void InteractionOperandImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionFragmentImpl::saveContent(saveHandler);
	NamespaceImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InteractionOperandImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'fragment'
		for (std::shared_ptr<uml::InteractionFragment> fragment : *this->getFragment()) 
		{
			saveHandler->addReference(fragment, "fragment", fragment->eClass() != package->getInteractionFragment_Class());
		}

		// Save 'guard'
		std::shared_ptr<uml::InteractionConstraint> guard = this->getGuard();
		if (guard != nullptr)
		{
			saveHandler->addReference(guard, "guard", guard->eClass() != package->getInteractionConstraint_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> InteractionOperandImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInteractionOperand_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> InteractionOperandImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONOPERAND_ATTRIBUTE_FRAGMENT:
			return eEcoreContainerAny(getFragment(),uml::umlPackage::INTERACTIONFRAGMENT_CLASS); //12219
		case uml::umlPackage::INTERACTIONOPERAND_ATTRIBUTE_GUARD:
			return eAny(getGuard(),uml::umlPackage::INTERACTIONCONSTRAINT_CLASS,false); //12220
	}
	std::shared_ptr<Any> result;
	result = InteractionFragmentImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool InteractionOperandImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONOPERAND_ATTRIBUTE_FRAGMENT:
			return getFragment() != nullptr; //12219
		case uml::umlPackage::INTERACTIONOPERAND_ATTRIBUTE_GUARD:
			return getGuard() != nullptr; //12220
	}
	bool result = false;
	result = InteractionFragmentImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::internalEIsSet(featureID);
	return result;
}

bool InteractionOperandImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONOPERAND_ATTRIBUTE_FRAGMENT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::InteractionFragment>> _fragment = getFragment();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::InteractionFragment> valueToAdd = std::dynamic_pointer_cast<uml::InteractionFragment>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_fragment->includes(valueToAdd)))
								{
									_fragment->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'fragment'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'fragment'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INTERACTIONOPERAND_ATTRIBUTE_GUARD:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::InteractionConstraint> _guard = std::dynamic_pointer_cast<uml::InteractionConstraint>(eObject);
					if(_guard)
					{
						setGuard(_guard); //12220
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'guard'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'guard'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = InteractionFragmentImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> InteractionOperandImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = InteractionFragmentImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = NamespaceImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::InteractionOperand> InteractionOperandImpl::getThisInteractionOperandPtr() const
{
	return m_thisInteractionOperandPtr.lock();
}
void InteractionOperandImpl::setThisInteractionOperandPtr(std::weak_ptr<uml::InteractionOperand> thisInteractionOperandPtr)
{
	m_thisInteractionOperandPtr = thisInteractionOperandPtr;
	setThisInteractionFragmentPtr(thisInteractionOperandPtr);
	setThisNamespacePtr(thisInteractionOperandPtr);
}


