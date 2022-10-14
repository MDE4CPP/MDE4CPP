
#include "uml/impl/StructuredClassifierImpl.hpp"
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
#include <stdexcept>
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
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/Type.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StructuredClassifierImpl::StructuredClassifierImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StructuredClassifierImpl::~StructuredClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuredClassifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StructuredClassifierImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::Element> par_owner)
:StructuredClassifierImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:StructuredClassifierImpl()
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
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:StructuredClassifierImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


StructuredClassifierImpl::StructuredClassifierImpl(const StructuredClassifierImpl & obj): StructuredClassifierImpl()
{
	*this = obj;
}

StructuredClassifierImpl& StructuredClassifierImpl::operator=(const StructuredClassifierImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassifierImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of StructuredClassifier 
	 * which is generated by the compiler (as StructuredClassifier is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//StructuredClassifier::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuredClassifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_part  = obj.getPart();
	//Clone references with containment (deep copy)
	//clone reference 'ownedAttribute'
	std::shared_ptr<SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property>> ownedAttributeList = obj.getOwnedAttribute();
	if(ownedAttributeList)
	{
		/*SubsetUnion*/
		m_ownedAttribute.reset(new SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedAttribute()->initSubsetUnion(getRole(), getOwnedMember(), getAttribute());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >(getRole(), getOwnedMember(), getAttribute())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Property> ownedAttributeindexElem: *ownedAttributeList) 
		{
			std::shared_ptr<uml::Property> temp = std::dynamic_pointer_cast<uml::Property>((ownedAttributeindexElem)->copy());
			m_ownedAttribute->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedAttribute.")
	}

	//clone reference 'ownedConnector'
	std::shared_ptr<Subset<uml::Connector, uml::Feature, uml::NamedElement>> ownedConnectorList = obj.getOwnedConnector();
	if(ownedConnectorList)
	{
		/*Subset*/
		m_ownedConnector.reset(new Subset<uml::Connector, uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedConnector()->initSubset(getFeature(), getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Connector> ownedConnectorindexElem: *ownedConnectorList) 
		{
			std::shared_ptr<uml::Connector> temp = std::dynamic_pointer_cast<uml::Connector>((ownedConnectorindexElem)->copy());
			m_ownedConnector->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedConnector.")
	}
	/*SubsetUnion*/
	getOwnedAttribute()->initSubsetUnion(getRole(), getOwnedMember(), getAttribute());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >(getRole(), getOwnedMember(), getAttribute())" << std::endl;
	#endif
	
	/*Subset*/
	getOwnedConnector()->initSubset(getFeature(), getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::ConnectableElement>> StructuredClassifierImpl::allRoles()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Property> StructuredClassifierImpl::createOwnedAttribute(std::string name, std::shared_ptr<uml::Type> type, int lower, int upper)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Property>> StructuredClassifierImpl::getParts()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		return this->getPart();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference ownedAttribute */
std::shared_ptr<SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property>> StructuredClassifierImpl::getOwnedAttribute() const
{
	if(m_ownedAttribute == nullptr)
	{
		/*SubsetUnion*/
		m_ownedAttribute.reset(new SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedAttribute()->initSubsetUnion(getRole(), getOwnedMember(), getAttribute());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >(getRole(), getOwnedMember(), getAttribute())" << std::endl;
		#endif
		
	}
    return m_ownedAttribute;
}

/* Getter & Setter for reference ownedConnector */
std::shared_ptr<Subset<uml::Connector, uml::Feature, uml::NamedElement>> StructuredClassifierImpl::getOwnedConnector() const
{
	if(m_ownedConnector == nullptr)
	{
		/*Subset*/
		m_ownedConnector.reset(new Subset<uml::Connector, uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedConnector()->initSubset(getFeature(), getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_ownedConnector;
}

/* Getter & Setter for reference part */
std::shared_ptr<Bag<uml::Property>> StructuredClassifierImpl::getPart() const
{
	//generated from getterBody annotation
	std::shared_ptr<SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property>> ownedAttribute = this->getOwnedAttribute();
	std::shared_ptr<Bag<uml::Property>> ownedParts(new Bag<uml::Property>());

	Bag<uml::Property>::iterator ownedAttributeIter = ownedAttribute->begin();
	Bag<uml::Property>::iterator ownedAttributeEnd = ownedAttribute->end();

	while (ownedAttributeIter != ownedAttributeEnd)
	{
		if((*ownedAttributeIter)->isComposite())
		{
			ownedParts->add(*ownedAttributeIter);
		}

		ownedAttributeIter++;
	}

	return ownedParts;
	//end of body
}

/* Getter & Setter for reference role */

//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> StructuredClassifierImpl::getRole() const
{
	if(m_role == nullptr)
	{
		/*SubsetUnion*/
		m_role.reset(new SubsetUnion<uml::ConnectableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getRole()->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_role;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> StructuredClassifierImpl::eContainer() const
{
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

std::shared_ptr<ecore::EClass> StructuredClassifierImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStructuredClassifier_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> StructuredClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE:
			return eEcoreContainerAny(getOwnedAttribute(),uml::umlPackage::PROPERTY_CLASS); //22838
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR:
			return eEcoreContainerAny(getOwnedConnector(),uml::umlPackage::CONNECTOR_CLASS); //22839
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_PART:
			return eEcoreContainerAny(getPart(),uml::umlPackage::PROPERTY_CLASS); //22840
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_ROLE:
			return eEcoreContainerAny(getRole(),uml::umlPackage::CONNECTABLEELEMENT_CLASS); //22841
	}
	return ClassifierImpl::eGet(featureID, resolve, coreType);
}

bool StructuredClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE:
			return getOwnedAttribute() != nullptr; //22838
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR:
			return getOwnedConnector() != nullptr; //22839
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_PART:
			return getPart() != nullptr; //22840
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_ROLE:
			return getRole() != nullptr; //22841
	}
	return ClassifierImpl::internalEIsSet(featureID);
}

bool StructuredClassifierImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Property>> _ownedAttribute = getOwnedAttribute();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Property> valueToAdd = std::dynamic_pointer_cast<uml::Property>(anEObject);
	
							if (valueToAdd)
							{
								if(_ownedAttribute->find(valueToAdd) == -1)
								{
									_ownedAttribute->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedAttribute'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedAttribute'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Connector>> _ownedConnector = getOwnedConnector();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Connector> valueToAdd = std::dynamic_pointer_cast<uml::Connector>(anEObject);
	
							if (valueToAdd)
							{
								if(_ownedConnector->find(valueToAdd) == -1)
								{
									_ownedConnector->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedConnector'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedConnector'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> StructuredClassifierImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::StructuredClassifier::allRoles() : uml::ConnectableElement[*]: 3047328929
		case umlPackage::STRUCTUREDCLASSIFIER_OPERATION_ALLROLES:
		{
			std::shared_ptr<Bag<uml::ConnectableElement>> resultList = this->allRoles();
			return eEcoreContainerAny(resultList,uml::umlPackage::CONNECTABLEELEMENT_CLASS);
			break;
		}
		// uml::StructuredClassifier::createOwnedAttribute(std::string, uml::Type, int, int) : uml::Property: 2674132819
		case umlPackage::STRUCTUREDCLASSIFIER_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			Bag<Any>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_name = (*incoming_param_name_arguments_citer)->get<std::string>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'name'. Failed to invoke operation 'createOwnedAttribute'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'type'
			//parameter 1
			std::shared_ptr<uml::Type> incoming_param_type;
			Bag<Any>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_type_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_type = std::dynamic_pointer_cast<uml::Type>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'type'. Failed to invoke operation 'createOwnedAttribute'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'type'. Failed to invoke operation 'createOwnedAttribute'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'lower'
			//parameter 2
			int incoming_param_lower;
			Bag<Any>::const_iterator incoming_param_lower_arguments_citer = std::next(arguments->begin(), 2);
			try
			{
				incoming_param_lower = (*incoming_param_lower_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'lower'. Failed to invoke operation 'createOwnedAttribute'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'upper'
			//parameter 3
			int incoming_param_upper;
			Bag<Any>::const_iterator incoming_param_upper_arguments_citer = std::next(arguments->begin(), 3);
			try
			{
				incoming_param_upper = (*incoming_param_upper_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'upper'. Failed to invoke operation 'createOwnedAttribute'!")
				return nullptr;
			}
		
			result = eEcoreAny(this->createOwnedAttribute(incoming_param_name,incoming_param_type,incoming_param_lower,incoming_param_upper), uml::umlPackage::PROPERTY_CLASS);
			break;
		}
		// uml::StructuredClassifier::getParts() : uml::Property[*]: 2304451414
		case umlPackage::STRUCTUREDCLASSIFIER_OPERATION_GETPARTS:
		{
			std::shared_ptr<Bag<uml::Property>> resultList = this->getParts();
			return eEcoreContainerAny(resultList,uml::umlPackage::PROPERTY_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ClassifierImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::StructuredClassifier> StructuredClassifierImpl::getThisStructuredClassifierPtr() const
{
	return m_thisStructuredClassifierPtr.lock();
}
void StructuredClassifierImpl::setThisStructuredClassifierPtr(std::weak_ptr<uml::StructuredClassifier> thisStructuredClassifierPtr)
{
	m_thisStructuredClassifierPtr = thisStructuredClassifierPtr;
	setThisClassifierPtr(thisStructuredClassifierPtr);
}


