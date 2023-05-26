
#include "uml/impl/TemplateBindingImpl.hpp"
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
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/TemplateParameterSubstitution.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/TemplateableElement.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateBindingImpl::TemplateBindingImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TemplateBindingImpl::~TemplateBindingImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateBinding "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TemplateBindingImpl::TemplateBindingImpl(std::weak_ptr<uml::TemplateableElement> par_boundElement)
:TemplateBindingImpl()
{
	m_boundElement = par_boundElement;
	m_owner = par_boundElement;
}

//Additional constructor for the containments back reference
TemplateBindingImpl::TemplateBindingImpl(std::weak_ptr<uml::Element> par_owner)
:TemplateBindingImpl()
{
	m_owner = par_owner;
}

TemplateBindingImpl::TemplateBindingImpl(const TemplateBindingImpl & obj): TemplateBindingImpl()
{
	*this = obj;
}

TemplateBindingImpl& TemplateBindingImpl::operator=(const TemplateBindingImpl & obj)
{
	//call overloaded =Operator for each base class
	DirectedRelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TemplateBinding 
	 * which is generated by the compiler (as TemplateBinding is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TemplateBinding::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateBinding "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_boundElement  = obj.getBoundElement();
	//Clone references with containment (deep copy)
	//clone reference 'parameterSubstitution'
	std::shared_ptr<Subset<uml::TemplateParameterSubstitution, uml::Element>> parameterSubstitutionList = obj.getParameterSubstitution();
	if(parameterSubstitutionList)
	{
		/*Subset*/
		m_parameterSubstitution.reset(new Subset<uml::TemplateParameterSubstitution, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getParameterSubstitution()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::TemplateParameterSubstitution> parameterSubstitutionindexElem: *parameterSubstitutionList) 
		{
			std::shared_ptr<uml::TemplateParameterSubstitution> temp = std::dynamic_pointer_cast<uml::TemplateParameterSubstitution>((parameterSubstitutionindexElem)->copy());
			m_parameterSubstitution->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for parameterSubstitution.")
	}

	//clone reference 'signature'
	if(obj.getSignature()!=nullptr)
	{
		m_signature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getSignature()->copy());
	}
	/*Subset*/
	getParameterSubstitution()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> TemplateBindingImpl::copy() const
{
	std::shared_ptr<TemplateBindingImpl> element(new TemplateBindingImpl());
	*element =(*this);
	element->setThisTemplateBindingPtr(element);
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
/* Getter & Setter for reference boundElement */
std::weak_ptr<uml::TemplateableElement> TemplateBindingImpl::getBoundElement() const
{
    return m_boundElement;
}
void TemplateBindingImpl::setBoundElement(std::weak_ptr<uml::TemplateableElement> _boundElement)
{
    m_boundElement = _boundElement;
	
}

/* Getter & Setter for reference parameterSubstitution */
std::shared_ptr<Subset<uml::TemplateParameterSubstitution, uml::Element>> TemplateBindingImpl::getParameterSubstitution() const
{
	if(m_parameterSubstitution == nullptr)
	{
		/*Subset*/
		m_parameterSubstitution.reset(new Subset<uml::TemplateParameterSubstitution, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getParameterSubstitution()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_parameterSubstitution;
}

/* Getter & Setter for reference signature */
std::shared_ptr<uml::TemplateSignature> TemplateBindingImpl::getSignature() const
{
    return m_signature;
}
void TemplateBindingImpl::setSignature(const std::shared_ptr<uml::TemplateSignature>& _signature)
{
    m_signature = _signature;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TemplateBindingImpl::eContainer() const
{
	if(auto wp = m_boundElement.lock())
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
void TemplateBindingImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TemplateBindingImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("signature");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("signature")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DirectedRelationshipImpl::loadAttributes(loadHandler, attr_list);
}

void TemplateBindingImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("parameterSubstitution") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "TemplateParameterSubstitution";
			}
			loadHandler->handleChildContainer<uml::TemplateParameterSubstitution>(this->getParameterSubstitution());  

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
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
}

void TemplateBindingImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateableElement> _boundElement = std::dynamic_pointer_cast<uml::TemplateableElement>( references.front() );
				setBoundElement(_boundElement);
			}
			
			return;
		}

		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_SIGNATURE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateSignature> _signature = std::dynamic_pointer_cast<uml::TemplateSignature>( references.front() );
				setSignature(_signature);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
}

void TemplateBindingImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TemplateBindingImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'parameterSubstitution'
		for (std::shared_ptr<uml::TemplateParameterSubstitution> parameterSubstitution : *this->getParameterSubstitution()) 
		{
			saveHandler->addReference(parameterSubstitution, "parameterSubstitution", parameterSubstitution->eClass() != package->getTemplateParameterSubstitution_Class());
		}
	// Add references
		saveHandler->addReference(this->getSignature(), "signature", getSignature()->eClass() != uml::umlPackage::eInstance()->getTemplateSignature_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> TemplateBindingImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTemplateBinding_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> TemplateBindingImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT:
		{
			std::shared_ptr<ecore::EObject> returnValue=getBoundElement().lock();
			return eEcoreAny(returnValue,uml::umlPackage::TEMPLATEABLEELEMENT_CLASS); //2308
		}
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_PARAMETERSUBSTITUTION:
			return eEcoreContainerAny(getParameterSubstitution(),uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_CLASS); //2306
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_SIGNATURE:
			return eAny(getSignature(),uml::umlPackage::TEMPLATESIGNATURE_CLASS,false); //2307
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}

bool TemplateBindingImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT:
			return getBoundElement().lock() != nullptr; //2308
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_PARAMETERSUBSTITUTION:
			return getParameterSubstitution() != nullptr; //2306
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_SIGNATURE:
			return getSignature() != nullptr; //2307
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}

bool TemplateBindingImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::TemplateableElement> _boundElement = std::dynamic_pointer_cast<uml::TemplateableElement>(eObject);
					if(_boundElement)
					{
						setBoundElement(_boundElement); //2308
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'boundElement'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'boundElement'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_PARAMETERSUBSTITUTION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::TemplateParameterSubstitution>> _parameterSubstitution = getParameterSubstitution();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::TemplateParameterSubstitution> valueToAdd = std::dynamic_pointer_cast<uml::TemplateParameterSubstitution>(anEObject);
	
							if (valueToAdd)
							{
								if(_parameterSubstitution->find(valueToAdd) == -1)
								{
									_parameterSubstitution->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'parameterSubstitution'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'parameterSubstitution'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_SIGNATURE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::TemplateSignature> _signature = std::dynamic_pointer_cast<uml::TemplateSignature>(eObject);
					if(_signature)
					{
						setSignature(_signature); //2307
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'signature'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'signature'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> TemplateBindingImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::TemplateBinding> TemplateBindingImpl::getThisTemplateBindingPtr() const
{
	return m_thisTemplateBindingPtr.lock();
}
void TemplateBindingImpl::setThisTemplateBindingPtr(std::weak_ptr<uml::TemplateBinding> thisTemplateBindingPtr)
{
	m_thisTemplateBindingPtr = thisTemplateBindingPtr;
	setThisDirectedRelationshipPtr(thisTemplateBindingPtr);
}


