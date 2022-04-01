
#include "uml/impl/InteractionFragmentImpl.hpp"
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


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
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
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionFragmentImpl::InteractionFragmentImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InteractionFragmentImpl::~InteractionFragmentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionFragment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:InteractionFragmentImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:InteractionFragmentImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InteractionFragmentImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::Element> par_owner)
:InteractionFragmentImpl()
{
	m_owner = par_owner;
}

InteractionFragmentImpl::InteractionFragmentImpl(const InteractionFragmentImpl & obj): InteractionFragmentImpl()
{
	*this = obj;
}

InteractionFragmentImpl& InteractionFragmentImpl::operator=(const InteractionFragmentImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InteractionFragment 
	 * which is generated by the compiler (as InteractionFragment is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InteractionFragment::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionFragment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_covered  = obj.getCovered();
	m_enclosingInteraction  = obj.getEnclosingInteraction();
	m_enclosingOperand  = obj.getEnclosingOperand();
	//Clone references with containment (deep copy)
	//clone reference 'generalOrdering'
	std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element>> generalOrderingList = obj.getGeneralOrdering();
	if(generalOrderingList)
	{
		/*Subset*/
		m_generalOrdering.reset(new Subset<uml::GeneralOrdering, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getGeneralOrdering()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::GeneralOrdering> generalOrderingindexElem: *generalOrderingList) 
		{
			std::shared_ptr<uml::GeneralOrdering> temp = std::dynamic_pointer_cast<uml::GeneralOrdering>((generalOrderingindexElem)->copy());
			m_generalOrdering->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr generalOrdering."<< std::endl;)
	}
	/*Subset*/
	getGeneralOrdering()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
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
/* Getter & Setter for reference covered */
std::shared_ptr<Bag<uml::Lifeline>> InteractionFragmentImpl::getCovered() const
{
	if(m_covered == nullptr)
	{
		m_covered.reset(new Bag<uml::Lifeline>());
		
		
	}
    return m_covered;
}

/* Getter & Setter for reference enclosingInteraction */
std::weak_ptr<uml::Interaction> InteractionFragmentImpl::getEnclosingInteraction() const
{
    return m_enclosingInteraction;
}
void InteractionFragmentImpl::setEnclosingInteraction(std::weak_ptr<uml::Interaction> _enclosingInteraction)
{
    m_enclosingInteraction = _enclosingInteraction;
	
}

/* Getter & Setter for reference enclosingOperand */
std::weak_ptr<uml::InteractionOperand> InteractionFragmentImpl::getEnclosingOperand() const
{
    return m_enclosingOperand;
}
void InteractionFragmentImpl::setEnclosingOperand(std::weak_ptr<uml::InteractionOperand> _enclosingOperand)
{
    m_enclosingOperand = _enclosingOperand;
	
}

/* Getter & Setter for reference generalOrdering */
std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element>> InteractionFragmentImpl::getGeneralOrdering() const
{
	if(m_generalOrdering == nullptr)
	{
		/*Subset*/
		m_generalOrdering.reset(new Subset<uml::GeneralOrdering, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getGeneralOrdering()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_generalOrdering;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> InteractionFragmentImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> InteractionFragmentImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> InteractionFragmentImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InteractionFragmentImpl::eContainer() const
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
void InteractionFragmentImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InteractionFragmentImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("covered");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("covered")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void InteractionFragmentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("generalOrdering") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "GeneralOrdering";
			}
			loadHandler->handleChildContainer<uml::GeneralOrdering>(this->getGeneralOrdering());  

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
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void InteractionFragmentImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_COVERED:
		{
			std::shared_ptr<Bag<uml::Lifeline>> _covered = getCovered();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Lifeline>  _r = std::dynamic_pointer_cast<uml::Lifeline>(ref);
				if (_r != nullptr)
				{
					_covered->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interaction> _enclosingInteraction = std::dynamic_pointer_cast<uml::Interaction>( references.front() );
				setEnclosingInteraction(_enclosingInteraction);
			}
			
			return;
		}

		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InteractionOperand> _enclosingOperand = std::dynamic_pointer_cast<uml::InteractionOperand>( references.front() );
				setEnclosingOperand(_enclosingOperand);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void InteractionFragmentImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InteractionFragmentImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'generalOrdering'
		for (std::shared_ptr<uml::GeneralOrdering> generalOrdering : *this->getGeneralOrdering()) 
		{
			saveHandler->addReference(generalOrdering, "generalOrdering", generalOrdering->eClass() != package->getGeneralOrdering_Class());
		}
	// Add references
		saveHandler->addReferences<uml::Lifeline>("covered", this->getCovered());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> InteractionFragmentImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInteractionFragment_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> InteractionFragmentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_COVERED:
			return eAnyBag(getCovered(),uml::umlPackage::LIFELINE_CLASS); //1219
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getEnclosingInteraction().lock();
			return eAnyObject(returnValue,uml::umlPackage::INTERACTION_CLASS); //12111
		}
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
		{
			std::shared_ptr<ecore::EObject> returnValue=getEnclosingOperand().lock();
			return eAnyObject(returnValue,uml::umlPackage::INTERACTIONOPERAND_CLASS); //12110
		}
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_GENERALORDERING:
			return eAnyBag(getGeneralOrdering(),uml::umlPackage::GENERALORDERING_CLASS); //12112
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}

bool InteractionFragmentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_COVERED:
			return getCovered() != nullptr; //1219
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
			return getEnclosingInteraction().lock() != nullptr; //12111
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
			return getEnclosingOperand().lock() != nullptr; //12110
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_GENERALORDERING:
			return getGeneralOrdering() != nullptr; //12112
	}
	return NamedElementImpl::internalEIsSet(featureID);
}

bool InteractionFragmentImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_COVERED:
		{
			// CAST Any to Bag<uml::Lifeline>
			if((newValue->isContainer()) && (uml::umlPackage::LIFELINE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Lifeline>> coveredList= newValue->get<std::shared_ptr<Bag<uml::Lifeline>>>();
					std::shared_ptr<Bag<uml::Lifeline>> _covered=getCovered();
					for(const std::shared_ptr<uml::Lifeline> indexCovered: *_covered)
					{
						if (coveredList->find(indexCovered) == -1)
						{
							_covered->erase(indexCovered);
						}
					}

					for(const std::shared_ptr<uml::Lifeline> indexCovered: *coveredList)
					{
						if (_covered->find(indexCovered) == -1)
						{
							_covered->add(indexCovered);
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
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
		{
			// CAST Any to uml::Interaction
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interaction> _enclosingInteraction = std::dynamic_pointer_cast<uml::Interaction>(_temp);
			setEnclosingInteraction(_enclosingInteraction); //12111
			return true;
		}
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
		{
			// CAST Any to uml::InteractionOperand
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InteractionOperand> _enclosingOperand = std::dynamic_pointer_cast<uml::InteractionOperand>(_temp);
			setEnclosingOperand(_enclosingOperand); //12110
			return true;
		}
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_GENERALORDERING:
		{
			// CAST Any to Bag<uml::GeneralOrdering>
			if((newValue->isContainer()) && (uml::umlPackage::GENERALORDERING_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::GeneralOrdering>> generalOrderingList= newValue->get<std::shared_ptr<Bag<uml::GeneralOrdering>>>();
					std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrdering=getGeneralOrdering();
					for(const std::shared_ptr<uml::GeneralOrdering> indexGeneralOrdering: *_generalOrdering)
					{
						if (generalOrderingList->find(indexGeneralOrdering) == -1)
						{
							_generalOrdering->erase(indexGeneralOrdering);
						}
					}

					for(const std::shared_ptr<uml::GeneralOrdering> indexGeneralOrdering: *generalOrderingList)
					{
						if (_generalOrdering->find(indexGeneralOrdering) == -1)
						{
							_generalOrdering->add(indexGeneralOrdering);
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

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> InteractionFragmentImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::InteractionFragment> InteractionFragmentImpl::getThisInteractionFragmentPtr() const
{
	return m_thisInteractionFragmentPtr.lock();
}
void InteractionFragmentImpl::setThisInteractionFragmentPtr(std::weak_ptr<uml::InteractionFragment> thisInteractionFragmentPtr)
{
	m_thisInteractionFragmentPtr = thisInteractionFragmentPtr;
	setThisNamedElementPtr(thisInteractionFragmentPtr);
}


