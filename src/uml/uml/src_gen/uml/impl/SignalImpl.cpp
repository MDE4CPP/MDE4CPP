
#include "uml/impl/SignalImpl.hpp"
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
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
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
SignalImpl::SignalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SignalImpl::~SignalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Signal "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
SignalImpl::SignalImpl(std::weak_ptr<uml::Namespace> par_namespace)
:SignalImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
SignalImpl::SignalImpl(std::weak_ptr<uml::Element> par_owner)
:SignalImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
SignalImpl::SignalImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:SignalImpl()
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
SignalImpl::SignalImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:SignalImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


SignalImpl::SignalImpl(const SignalImpl & obj): SignalImpl()
{
	*this = obj;
}

SignalImpl& SignalImpl::operator=(const SignalImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassifierImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Signal 
	 * which is generated by the compiler (as Signal is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Signal::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Signal "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'ownedAttribute'
	std::shared_ptr<Subset<uml::Property, uml::NamedElement, uml::Property>> ownedAttributeList = obj.getOwnedAttribute();
	if(ownedAttributeList)
	{
		/*Subset*/
		m_ownedAttribute.reset(new Subset<uml::Property, uml::NamedElement, uml::Property >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::NamedElement, uml::Property >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedAttribute()->initSubset(getOwnedMember(), getAttribute());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::NamedElement, uml::Property >(getOwnedMember(), getAttribute())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Property>& ownedAttributeindexElem: *ownedAttributeList) 
		{
			std::shared_ptr<uml::Property> temp = std::dynamic_pointer_cast<uml::Property>((ownedAttributeindexElem)->copy());
			m_ownedAttribute->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedAttribute.")
	}
	/*Subset*/
	getOwnedAttribute()->initSubset(getOwnedMember(), getAttribute());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::NamedElement, uml::Property >(getOwnedMember(), getAttribute())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> SignalImpl::copy() const
{
	std::shared_ptr<SignalImpl> element(new SignalImpl());
	*element =(*this);
	element->setThisSignalPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Property> SignalImpl::createOwnedAttribute(std::string name, const std::shared_ptr<uml::Type>& type, int lower, int upper)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference ownedAttribute */
const std::shared_ptr<Subset<uml::Property, uml::NamedElement, uml::Property>>& SignalImpl::getOwnedAttribute() const
{
	if(m_ownedAttribute == nullptr)
	{
		/*Subset*/
		m_ownedAttribute.reset(new Subset<uml::Property, uml::NamedElement, uml::Property >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::NamedElement, uml::Property >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedAttribute()->initSubset(getOwnedMember(), getAttribute());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::NamedElement, uml::Property >(getOwnedMember(), getAttribute())" << std::endl;
		#endif
		
	}
    return m_ownedAttribute;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> SignalImpl::eContainer() const
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

//*********************************
// Persistence Functions
//*********************************
void SignalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SignalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void SignalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedAttribute") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Property";
			}
			loadHandler->handleChildContainer<uml::Property>(this->getOwnedAttribute());  

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
	ClassifierImpl::loadNode(nodeName, loadHandler);
}

void SignalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	ClassifierImpl::resolveReferences(featureID, references);
}

void SignalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void SignalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedAttribute'
		for (const std::shared_ptr<uml::Property>& ownedAttribute : *this->getOwnedAttribute()) 
		{
			saveHandler->addReference(ownedAttribute, "ownedAttribute", ownedAttribute->eClass() != package->getProperty_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> SignalImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getSignal_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> SignalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::SIGNAL_ATTRIBUTE_OWNEDATTRIBUTE:
			return eEcoreContainerAny(getOwnedAttribute(),uml::umlPackage::PROPERTY_CLASS); //21538
	}
	return ClassifierImpl::eGet(featureID, resolve, coreType);
}

bool SignalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::SIGNAL_ATTRIBUTE_OWNEDATTRIBUTE:
			return getOwnedAttribute() != nullptr; //21538
	}
	return ClassifierImpl::internalEIsSet(featureID);
}

bool SignalImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::SIGNAL_ATTRIBUTE_OWNEDATTRIBUTE:
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
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Property> valueToAdd = std::dynamic_pointer_cast<uml::Property>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_ownedAttribute->includes(valueToAdd)))
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
	}

	return ClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> SignalImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Signal::createOwnedAttribute(std::string, uml::Type, int, int) : uml::Property: 2958211947
		case umlPackage::SIGNAL_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL:
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

std::shared_ptr<uml::Signal> SignalImpl::getThisSignalPtr() const
{
	return m_thisSignalPtr.lock();
}
void SignalImpl::setThisSignalPtr(std::weak_ptr<uml::Signal> thisSignalPtr)
{
	m_thisSignalPtr = thisSignalPtr;
	setThisClassifierPtr(thisSignalPtr);
}


