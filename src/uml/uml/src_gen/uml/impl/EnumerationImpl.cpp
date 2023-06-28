
#include "uml/impl/EnumerationImpl.hpp"
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
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/DataType.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/EnumerationLiteral.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
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
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
EnumerationImpl::EnumerationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EnumerationImpl::~EnumerationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Enumeration "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EnumerationImpl::EnumerationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:EnumerationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
EnumerationImpl::EnumerationImpl(std::weak_ptr<uml::Element> par_owner)
:EnumerationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
EnumerationImpl::EnumerationImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:EnumerationImpl()
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
EnumerationImpl::EnumerationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:EnumerationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


EnumerationImpl::EnumerationImpl(const EnumerationImpl & obj): EnumerationImpl()
{
	*this = obj;
}

EnumerationImpl& EnumerationImpl::operator=(const EnumerationImpl & obj)
{
	//call overloaded =Operator for each base class
	DataTypeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Enumeration 
	 * which is generated by the compiler (as Enumeration is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Enumeration::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Enumeration "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'ownedLiteral'
	std::shared_ptr<Subset<uml::EnumerationLiteral, uml::NamedElement>> ownedLiteralList = obj.getOwnedLiteral();
	if(ownedLiteralList)
	{
		/*Subset*/
		m_ownedLiteral.reset(new Subset<uml::EnumerationLiteral, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedLiteral - Subset<uml::EnumerationLiteral, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedLiteral()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedLiteral - Subset<uml::EnumerationLiteral, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::EnumerationLiteral>& ownedLiteralindexElem: *ownedLiteralList) 
		{
			std::shared_ptr<uml::EnumerationLiteral> temp = std::dynamic_pointer_cast<uml::EnumerationLiteral>((ownedLiteralindexElem)->copy());
			m_ownedLiteral->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedLiteral.")
	}
	/*Subset*/
	getOwnedLiteral()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedLiteral - Subset<uml::EnumerationLiteral, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> EnumerationImpl::copy() const
{
	std::shared_ptr<EnumerationImpl> element(new EnumerationImpl());
	*element =(*this);
	element->setThisEnumerationPtr(element);
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
/* Getter & Setter for reference ownedLiteral */
const std::shared_ptr<Subset<uml::EnumerationLiteral, uml::NamedElement>>& EnumerationImpl::getOwnedLiteral() const
{
	if(m_ownedLiteral == nullptr)
	{
		/*Subset*/
		m_ownedLiteral.reset(new Subset<uml::EnumerationLiteral, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedLiteral - Subset<uml::EnumerationLiteral, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedLiteral()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedLiteral - Subset<uml::EnumerationLiteral, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_ownedLiteral;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EnumerationImpl::eContainer() const
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
void EnumerationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EnumerationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	DataTypeImpl::loadAttributes(loadHandler, attr_list);
}

void EnumerationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedLiteral") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EnumerationLiteral";
			}
			loadHandler->handleChildContainer<uml::EnumerationLiteral>(this->getOwnedLiteral());  

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
	DataTypeImpl::loadNode(nodeName, loadHandler);
}

void EnumerationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	DataTypeImpl::resolveReferences(featureID, references);
}

void EnumerationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DataTypeImpl::saveContent(saveHandler);
	
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

void EnumerationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedLiteral'
		for (const std::shared_ptr<uml::EnumerationLiteral>& ownedLiteral : *this->getOwnedLiteral()) 
		{
			saveHandler->addReference(ownedLiteral, "ownedLiteral", ownedLiteral->eClass() != package->getEnumerationLiteral_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> EnumerationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getEnumeration_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EnumerationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ENUMERATION_ATTRIBUTE_OWNEDLITERAL:
			return eEcoreContainerAny(getOwnedLiteral(),uml::umlPackage::ENUMERATIONLITERAL_CLASS); //8440
	}
	return DataTypeImpl::eGet(featureID, resolve, coreType);
}

bool EnumerationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ENUMERATION_ATTRIBUTE_OWNEDLITERAL:
			return getOwnedLiteral() != nullptr; //8440
	}
	return DataTypeImpl::internalEIsSet(featureID);
}

bool EnumerationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ENUMERATION_ATTRIBUTE_OWNEDLITERAL:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::EnumerationLiteral>> _ownedLiteral = getOwnedLiteral();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::EnumerationLiteral> valueToAdd = std::dynamic_pointer_cast<uml::EnumerationLiteral>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_ownedLiteral->includes(valueToAdd)))
								{
									_ownedLiteral->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedLiteral'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedLiteral'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return DataTypeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> EnumerationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DataTypeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Enumeration> EnumerationImpl::getThisEnumerationPtr() const
{
	return m_thisEnumerationPtr.lock();
}
void EnumerationImpl::setThisEnumerationPtr(std::weak_ptr<uml::Enumeration> thisEnumerationPtr)
{
	m_thisEnumerationPtr = thisEnumerationPtr;
	setThisDataTypePtr(thisEnumerationPtr);
}


