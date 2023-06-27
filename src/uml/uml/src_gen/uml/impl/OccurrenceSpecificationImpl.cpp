
#include "uml/impl/OccurrenceSpecificationImpl.hpp"
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
#include <stdexcept>
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
#include "uml/InteractionFragment.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OccurrenceSpecificationImpl::~OccurrenceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OccurrenceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:OccurrenceSpecificationImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:OccurrenceSpecificationImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:OccurrenceSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(std::weak_ptr<uml::Element> par_owner)
:OccurrenceSpecificationImpl()
{
	m_owner = par_owner;
}

OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(const OccurrenceSpecificationImpl & obj): OccurrenceSpecificationImpl()
{
	*this = obj;
}

OccurrenceSpecificationImpl& OccurrenceSpecificationImpl::operator=(const OccurrenceSpecificationImpl & obj)
{
	//call overloaded =Operator for each base class
	InteractionFragmentImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OccurrenceSpecification 
	 * which is generated by the compiler (as OccurrenceSpecification is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OccurrenceSpecification::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OccurrenceSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_toAfter  = obj.getToAfter();
	m_toBefore  = obj.getToBefore();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OccurrenceSpecificationImpl::copy() const
{
	std::shared_ptr<OccurrenceSpecificationImpl> element(new OccurrenceSpecificationImpl());
	*element =(*this);
	element->setThisOccurrenceSpecificationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************


void OccurrenceSpecificationImpl::setCovered(const std::shared_ptr<uml::Lifeline>& value)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference toAfter */
const std::shared_ptr<Bag<uml::GeneralOrdering>>& OccurrenceSpecificationImpl::getToAfter() const
{
	if(m_toAfter == nullptr)
	{
		m_toAfter.reset(new Bag<uml::GeneralOrdering>());
		
		
	}
    return m_toAfter;
}

/* Getter & Setter for reference toBefore */
const std::shared_ptr<Bag<uml::GeneralOrdering>>& OccurrenceSpecificationImpl::getToBefore() const
{
	if(m_toBefore == nullptr)
	{
		m_toBefore.reset(new Bag<uml::GeneralOrdering>());
		
		
	}
    return m_toBefore;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> OccurrenceSpecificationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> OccurrenceSpecificationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> OccurrenceSpecificationImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> OccurrenceSpecificationImpl::eContainer() const
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
void OccurrenceSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OccurrenceSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("toAfter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("toAfter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("toBefore");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("toBefore")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	InteractionFragmentImpl::loadAttributes(loadHandler, attr_list);
}

void OccurrenceSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	InteractionFragmentImpl::loadNode(nodeName, loadHandler);
}

void OccurrenceSpecificationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOAFTER:
		{
			std::shared_ptr<Bag<uml::GeneralOrdering>> _toAfter = getToAfter();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::GeneralOrdering>  _r = std::dynamic_pointer_cast<uml::GeneralOrdering>(ref);
				if (_r != nullptr)
				{
					_toAfter->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOBEFORE:
		{
			std::shared_ptr<Bag<uml::GeneralOrdering>> _toBefore = getToBefore();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::GeneralOrdering>  _r = std::dynamic_pointer_cast<uml::GeneralOrdering>(ref);
				if (_r != nullptr)
				{
					_toBefore->push_back(_r);
				}
			}
			return;
		}
	}
	InteractionFragmentImpl::resolveReferences(featureID, references);
}

void OccurrenceSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void OccurrenceSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::GeneralOrdering>("toAfter", this->getToAfter());
		saveHandler->addReferences<uml::GeneralOrdering>("toBefore", this->getToBefore());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& OccurrenceSpecificationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getOccurrenceSpecification_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any OccurrenceSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOAFTER:
			return eAnyBag(getToAfter(),uml::umlPackage::GENERALORDERING_CLASS); //16313
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOBEFORE:
			return eAnyBag(getToBefore(),uml::umlPackage::GENERALORDERING_CLASS); //16314
	}
	return InteractionFragmentImpl::eGet(featureID, resolve, coreType);
}

bool OccurrenceSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOAFTER:
			return getToAfter() != nullptr; //16313
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOBEFORE:
			return getToBefore() != nullptr; //16314
	}
	return InteractionFragmentImpl::internalEIsSet(featureID);
}

bool OccurrenceSpecificationImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOAFTER:
		{
			// CAST Any to Bag<uml::GeneralOrdering>
			if((newValue->isContainer()) && (uml::umlPackage::GENERALORDERING_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::GeneralOrdering>> toAfterList= newValue->get<std::shared_ptr<Bag<uml::GeneralOrdering>>>();
					std::shared_ptr<Bag<uml::GeneralOrdering>> _toAfter=getToAfter();
					for(const std::shared_ptr<uml::GeneralOrdering> indexToAfter: *_toAfter)
					{
						if (toAfterList->find(indexToAfter) == -1)
						{
							_toAfter->erase(indexToAfter);
						}
					}

					for(const std::shared_ptr<uml::GeneralOrdering> indexToAfter: *toAfterList)
					{
						if (_toAfter->find(indexToAfter) == -1)
						{
							_toAfter->add(indexToAfter);
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
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOBEFORE:
		{
			// CAST Any to Bag<uml::GeneralOrdering>
			if((newValue->isContainer()) && (uml::umlPackage::GENERALORDERING_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::GeneralOrdering>> toBeforeList= newValue->get<std::shared_ptr<Bag<uml::GeneralOrdering>>>();
					std::shared_ptr<Bag<uml::GeneralOrdering>> _toBefore=getToBefore();
					for(const std::shared_ptr<uml::GeneralOrdering> indexToBefore: *_toBefore)
					{
						if (toBeforeList->find(indexToBefore) == -1)
						{
							_toBefore->erase(indexToBefore);
						}
					}

					for(const std::shared_ptr<uml::GeneralOrdering> indexToBefore: *toBeforeList)
					{
						if (_toBefore->find(indexToBefore) == -1)
						{
							_toBefore->add(indexToBefore);
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

	return InteractionFragmentImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any OccurrenceSpecificationImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::OccurrenceSpecification::setCovered(uml::Lifeline): 3135951751
		case umlPackage::OCCURRENCESPECIFICATION_OPERATION_SETCOVERED_LIFELINE:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::shared_ptr<uml::Lifeline> incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::shared_ptr<uml::Lifeline> >();
			this->setCovered(incoming_param_value);
			break;
		}

		default:
		{
			// call superTypes
			result = InteractionFragmentImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::OccurrenceSpecification> OccurrenceSpecificationImpl::getThisOccurrenceSpecificationPtr() const
{
	return m_thisOccurrenceSpecificationPtr.lock();
}
void OccurrenceSpecificationImpl::setThisOccurrenceSpecificationPtr(std::weak_ptr<uml::OccurrenceSpecification> thisOccurrenceSpecificationPtr)
{
	m_thisOccurrenceSpecificationPtr = thisOccurrenceSpecificationPtr;
	setThisInteractionFragmentPtr(thisOccurrenceSpecificationPtr);
}


