
#include "uml/impl/SlotImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


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
#include "uml/Element.hpp"
#include "uml/InstanceSpecification.hpp"
#include "uml/StructuralFeature.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
SlotImpl::SlotImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SlotImpl::~SlotImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Slot "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
SlotImpl::SlotImpl(std::weak_ptr<uml::Element> par_owner)
:SlotImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
SlotImpl::SlotImpl(std::weak_ptr<uml::InstanceSpecification> par_owningInstance)
:SlotImpl()
{
	m_owningInstance = par_owningInstance;
	m_owner = par_owningInstance;
}

SlotImpl::SlotImpl(const SlotImpl & obj): SlotImpl()
{
	*this = obj;
}

SlotImpl& SlotImpl::operator=(const SlotImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Slot 
	 * which is generated by the compiler (as Slot is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Slot::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Slot "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_definingFeature  = obj.getDefiningFeature();
	m_owningInstance  = obj.getOwningInstance();
	//Clone references with containment (deep copy)
	//clone reference 'value'
	std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> valueList = obj.getValue();
	if(valueList)
	{
		/*Subset*/
		m_value.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_value - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getValue()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_value - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ValueSpecification> valueindexElem: *valueList) 
		{
			std::shared_ptr<uml::ValueSpecification> temp = std::dynamic_pointer_cast<uml::ValueSpecification>((valueindexElem)->copy());
			m_value->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr value."<< std::endl;)
	}
	/*Subset*/
	getValue()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_value - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> SlotImpl::copy() const
{
	std::shared_ptr<SlotImpl> element(new SlotImpl());
	*element =(*this);
	element->setThisSlotPtr(element);
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
/* Getter & Setter for reference definingFeature */
std::shared_ptr<uml::StructuralFeature> SlotImpl::getDefiningFeature() const
{
    return m_definingFeature;
}
void SlotImpl::setDefiningFeature(std::shared_ptr<uml::StructuralFeature> _definingFeature)
{
    m_definingFeature = _definingFeature;
	
}

/* Getter & Setter for reference owningInstance */
std::weak_ptr<uml::InstanceSpecification> SlotImpl::getOwningInstance() const
{
    return m_owningInstance;
}
void SlotImpl::setOwningInstance(std::weak_ptr<uml::InstanceSpecification> _owningInstance)
{
    m_owningInstance = _owningInstance;
	
}

/* Getter & Setter for reference value */
std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> SlotImpl::getValue() const
{
	if(m_value == nullptr)
	{
		/*Subset*/
		m_value.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_value - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getValue()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_value - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_value;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> SlotImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> SlotImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> SlotImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningInstance.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void SlotImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SlotImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("definingFeature");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("definingFeature")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void SlotImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("value") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ValueSpecification>(this->getValue());  

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
	ElementImpl::loadNode(nodeName, loadHandler);
}

void SlotImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::SLOT_ATTRIBUTE_DEFININGFEATURE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuralFeature> _definingFeature = std::dynamic_pointer_cast<uml::StructuralFeature>( references.front() );
				setDefiningFeature(_definingFeature);
			}
			
			return;
		}

		case uml::umlPackage::SLOT_ATTRIBUTE_OWNINGINSTANCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InstanceSpecification> _owningInstance = std::dynamic_pointer_cast<uml::InstanceSpecification>( references.front() );
				setOwningInstance(_owningInstance);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void SlotImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void SlotImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'value'
		for (std::shared_ptr<uml::ValueSpecification> value : *this->getValue()) 
		{
			saveHandler->addReference(value, "value", value->eClass() != package->getValueSpecification_Class());
		}
	// Add references
		saveHandler->addReference(this->getDefiningFeature(), "definingFeature", getDefiningFeature()->eClass() != uml::umlPackage::eInstance()->getStructuralFeature_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> SlotImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getSlot_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any SlotImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::SLOT_ATTRIBUTE_DEFININGFEATURE:
			return eAny(getDefiningFeature(),uml::umlPackage::STRUCTURALFEATURE_CLASS,false); //2173
		case uml::umlPackage::SLOT_ATTRIBUTE_OWNINGINSTANCE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getOwningInstance().lock();
			return eAnyObject(returnValue,uml::umlPackage::INSTANCESPECIFICATION_CLASS); //2175
		}
		case uml::umlPackage::SLOT_ATTRIBUTE_VALUE:
			return eAnyBag(getValue(),uml::umlPackage::VALUESPECIFICATION_CLASS); //2174
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}

bool SlotImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::SLOT_ATTRIBUTE_DEFININGFEATURE:
			return getDefiningFeature() != nullptr; //2173
		case uml::umlPackage::SLOT_ATTRIBUTE_OWNINGINSTANCE:
			return getOwningInstance().lock() != nullptr; //2175
		case uml::umlPackage::SLOT_ATTRIBUTE_VALUE:
			return getValue() != nullptr; //2174
	}
	return ElementImpl::internalEIsSet(featureID);
}

bool SlotImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::SLOT_ATTRIBUTE_DEFININGFEATURE:
		{
			// CAST Any to uml::StructuralFeature
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StructuralFeature> _definingFeature = std::dynamic_pointer_cast<uml::StructuralFeature>(_temp);
			setDefiningFeature(_definingFeature); //2173
			return true;
		}
		case uml::umlPackage::SLOT_ATTRIBUTE_OWNINGINSTANCE:
		{
			// CAST Any to uml::InstanceSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InstanceSpecification> _owningInstance = std::dynamic_pointer_cast<uml::InstanceSpecification>(_temp);
			setOwningInstance(_owningInstance); //2175
			return true;
		}
		case uml::umlPackage::SLOT_ATTRIBUTE_VALUE:
		{
			// CAST Any to Bag<uml::ValueSpecification>
			if((newValue->isContainer()) && (uml::umlPackage::VALUESPECIFICATION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ValueSpecification>> valueList= newValue->get<std::shared_ptr<Bag<uml::ValueSpecification>>>();
					std::shared_ptr<Bag<uml::ValueSpecification>> _value=getValue();
					for(const std::shared_ptr<uml::ValueSpecification> indexValue: *_value)
					{
						if (valueList->find(indexValue) == -1)
						{
							_value->erase(indexValue);
						}
					}

					for(const std::shared_ptr<uml::ValueSpecification> indexValue: *valueList)
					{
						if (_value->find(indexValue) == -1)
						{
							_value->add(indexValue);
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

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any SlotImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Slot> SlotImpl::getThisSlotPtr() const
{
	return m_thisSlotPtr.lock();
}
void SlotImpl::setThisSlotPtr(std::weak_ptr<uml::Slot> thisSlotPtr)
{
	m_thisSlotPtr = thisSlotPtr;
	setThisElementPtr(thisSlotPtr);
}


