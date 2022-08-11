
#include "ecore/impl/EAnnotationImpl.hpp"
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
#include "ecore/ecoreFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EModelElement.hpp"
#include "ecore/EObject.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EAnnotationImpl::EAnnotationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EAnnotationImpl::~EAnnotationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EAnnotation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EAnnotationImpl::EAnnotationImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EAnnotationImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EAnnotationImpl::EAnnotationImpl(std::weak_ptr<ecore::EModelElement> par_eModelElement)
:EAnnotationImpl()
{
	m_eModelElement = par_eModelElement;
}

EAnnotationImpl::EAnnotationImpl(const EAnnotationImpl & obj): EAnnotationImpl()
{
	*this = obj;
}

EAnnotationImpl& EAnnotationImpl::operator=(const EAnnotationImpl & obj)
{
	//call overloaded =Operator for each base class
	EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EAnnotation 
	 * which is generated by the compiler (as EAnnotation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EAnnotation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EAnnotation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	std::shared_ptr<std::map < std::string, std::string>> detailsContainer = getDetails();
	for(const auto pair_details : *obj.getDetails())
	{
		detailsContainer->insert(std::make_pair(pair_details.first, pair_details.second));
	}
	m_source = obj.getSource();

	//copy references with no containment (soft copy)
	m_eModelElement  = obj.getEModelElement();
	m_references  = obj.getReferences();
	//Clone references with containment (deep copy)
	//clone reference 'contents'
	std::shared_ptr<Subset<ecore::EObject, ecore::EObject>> contentsList = obj.getContents();
	if(contentsList)
	{
		/*Subset*/
		m_contents.reset(new Subset<ecore::EObject, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getContents()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
		for(const std::shared_ptr<ecore::EObject> contentsindexElem: *contentsList) 
		{
			std::shared_ptr<ecore::EObject> temp = std::dynamic_pointer_cast<ecore::EObject>((contentsindexElem)->copy());
			m_contents->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr contents."<< std::endl;)
	}
	/*Subset*/
	getContents()->initSubset(getEContentUnion());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >(getEContentUnion())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> EAnnotationImpl::copy() const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl());
	*element =(*this);
	element->setThisEAnnotationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute details */
std::shared_ptr<std::map < std::string, std::string>> EAnnotationImpl::getDetails() const 
{
	return m_details;
}
void EAnnotationImpl::setDetails(std::shared_ptr<std::map < std::string, std::string>> _details)
{
	m_details = _details;
	
}

/* Getter & Setter for attribute source */
std::string EAnnotationImpl::getSource() const 
{
	return m_source;
}
void EAnnotationImpl::setSource(std::string _source)
{
	m_source = _source;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference contents */
std::shared_ptr<Subset<ecore::EObject, ecore::EObject>> EAnnotationImpl::getContents() const
{
	if(m_contents == nullptr)
	{
		/*Subset*/
		m_contents.reset(new Subset<ecore::EObject, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getContents()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
	}
    return m_contents;
}

/* Getter & Setter for reference eModelElement */
std::weak_ptr<ecore::EModelElement> EAnnotationImpl::getEModelElement() const
{
    return m_eModelElement;
}
void EAnnotationImpl::setEModelElement(std::weak_ptr<ecore::EModelElement> _eModelElement)
{
    m_eModelElement = _eModelElement;
	
}

/* Getter & Setter for reference references */
std::shared_ptr<Bag<ecore::EObject>> EAnnotationImpl::getReferences() const
{
	if(m_references == nullptr)
	{
		m_references.reset(new Bag<ecore::EObject>());
		
		
	}
    return m_references;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EAnnotationImpl::getEContentUnion() const
{
	if(m_eContentUnion == nullptr)
	{
		/*Union*/
		m_eContentUnion.reset(new Union<ecore::EObject>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eContentUnion - Union<ecore::EObject>()" << std::endl;
		#endif
		
		
	}
	return m_eContentUnion;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EAnnotationImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eModelElement.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EAnnotationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get ecoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EAnnotationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("source");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setSource(value);
		}
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("references");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("references")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	EModelElementImpl::loadAttributes(loadHandler, attr_list);
}

void EAnnotationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("contents") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EObject";
			}
			loadHandler->handleChildContainer<ecore::EObject>(this->getContents());  

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
	EModelElementImpl::loadNode(nodeName, loadHandler);
}

void EAnnotationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_EMODELELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EModelElement> _eModelElement = std::dynamic_pointer_cast<ecore::EModelElement>( references.front() );
				setEModelElement(_eModelElement);
			}
			
			return;
		}

		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_REFERENCES:
		{
			std::shared_ptr<Bag<ecore::EObject>> _references = getReferences();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ecore::EObject>  _r = std::dynamic_pointer_cast<ecore::EObject>(ref);
				if (_r != nullptr)
				{
					_references->push_back(_r);
				}
			}
			return;
		}
	}
	EModelElementImpl::resolveReferences(featureID, references);
}

void EAnnotationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EAnnotationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Save 'contents'
		for (std::shared_ptr<ecore::EObject> contents : *this->getContents()) 
		{
			saveHandler->addReference(contents, "contents", contents->eClass() != package->getEObject_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getEAnnotation_Attribute_source()) )
		{
			saveHandler->addAttribute("source", this->getSource());
		}
	// Add references
		saveHandler->addReferences<ecore::EObject>("references", this->getReferences());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<EClass> EAnnotationImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEAnnotation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EAnnotationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:
			return eEcoreContainerAny(getContents(),ecore::ecorePackage::EOBJECT_CLASS); //26
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_DETAILS:
			return eAny(getDetails(),ecore::ecorePackage::EMAP_CLASS,false); //28
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_EMODELELEMENT:
		{
			std::shared_ptr<ecore::EObject> returnValue=getEModelElement().lock();
			return eEcoreAny(returnValue,ecore::ecorePackage::EMODELELEMENT_CLASS); //25
		}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_REFERENCES:
			return eEcoreContainerAny(getReferences(),ecore::ecorePackage::EOBJECT_CLASS); //27
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_SOURCE:
			return eAny(getSource(),ecore::ecorePackage::ESTRING_CLASS,false); //24
	}
	return EModelElementImpl::eGet(featureID, resolve, coreType);
}

bool EAnnotationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:
			return getContents() != nullptr; //26
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_DETAILS:
			return getDetails() != nullptr; //28
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_EMODELELEMENT:
			return getEModelElement().lock() != nullptr; //25
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_REFERENCES:
			return getReferences() != nullptr; //27
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_SOURCE:
			return getSource() != ""; //24
	}
	return EModelElementImpl::internalEIsSet(featureID);
}

bool EAnnotationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ecore::EObject>> _contents = getContents();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<ecore::EObject> valueToAdd = std::dynamic_pointer_cast<ecore::EObject>(anEObject);
	
							if (valueToAdd)
							{
								if(_contents->find(valueToAdd) == -1)
								{
									_contents->add(valueToAdd);
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
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'contents'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'contents'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_DETAILS:
		{
			try
			{
				std::shared_ptr<std::map < std::string, std::string>> _details = newValue->get<std::shared_ptr<std::map < std::string, std::string>>>();
				setDetails(_details); //28
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for feature 'details'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_EMODELELEMENT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ecore::EModelElement> _eModelElement = std::dynamic_pointer_cast<ecore::EModelElement>(eObject);
					if(_eModelElement)
					{
						setEModelElement(_eModelElement); //25
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'eModelElement'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'eModelElement'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_REFERENCES:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ecore::EObject>> _references = getReferences();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<ecore::EObject> valueToAdd = std::dynamic_pointer_cast<ecore::EObject>(anEObject);
	
							if (valueToAdd)
							{
								if(_references->find(valueToAdd) == -1)
								{
									_references->add(valueToAdd);
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
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'references'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'references'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_SOURCE:
		{
			try
			{
				std::string _source = newValue->get<std::string>();
				setSource(_source); //24
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for feature 'source'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
	}

	return EModelElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> EAnnotationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EAnnotation> EAnnotationImpl::getThisEAnnotationPtr() const
{
	return m_thisEAnnotationPtr.lock();
}
void EAnnotationImpl::setThisEAnnotationPtr(std::weak_ptr<ecore::EAnnotation> thisEAnnotationPtr)
{
	m_thisEAnnotationPtr = thisEAnnotationPtr;
	setThisEModelElementPtr(thisEAnnotationPtr);
}


