
#include "uml/impl/DataTypeImpl.hpp"
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
#include "uml/Type.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DataTypeImpl::DataTypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DataTypeImpl::~DataTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DataType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DataTypeImpl::DataTypeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DataTypeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DataTypeImpl::DataTypeImpl(std::weak_ptr<uml::Element> par_owner)
:DataTypeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
DataTypeImpl::DataTypeImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:DataTypeImpl()
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
DataTypeImpl::DataTypeImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:DataTypeImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


DataTypeImpl::DataTypeImpl(const DataTypeImpl & obj): DataTypeImpl()
{
	*this = obj;
}

DataTypeImpl& DataTypeImpl::operator=(const DataTypeImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassifierImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DataType 
	 * which is generated by the compiler (as DataType is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DataType::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DataType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	//clone reference 'ownedOperation'
	std::shared_ptr<Subset<uml::Operation, uml::Feature, uml::NamedElement>> ownedOperationList = obj.getOwnedOperation();
	if(ownedOperationList)
	{
		/*Subset*/
		m_ownedOperation.reset(new Subset<uml::Operation, uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedOperation()->initSubset(getFeature(), getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Operation> ownedOperationindexElem: *ownedOperationList) 
		{
			std::shared_ptr<uml::Operation> temp = std::dynamic_pointer_cast<uml::Operation>((ownedOperationindexElem)->copy());
			m_ownedOperation->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedOperation.")
	}
	/*Subset*/
	getOwnedAttribute()->initSubset(getOwnedMember(), getAttribute());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::NamedElement, uml::Property >(getOwnedMember(), getAttribute())" << std::endl;
	#endif
	
	/*Subset*/
	getOwnedOperation()->initSubset(getFeature(), getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> DataTypeImpl::copy() const
{
	std::shared_ptr<DataTypeImpl> element(new DataTypeImpl());
	*element =(*this);
	element->setThisDataTypePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Property> DataTypeImpl::createOwnedAttribute(std::string name, const std::shared_ptr<uml::Type>& type, int lower, int upper)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Operation> DataTypeImpl::createOwnedOperation(std::string name, const std::shared_ptr<Bag<std::string>>& parameterNames, const std::shared_ptr<Bag<uml::Type>>& parameterTypes, const std::shared_ptr<uml::Type>& returnType)
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
std::shared_ptr<Subset<uml::Property, uml::NamedElement, uml::Property>> DataTypeImpl::getOwnedAttribute() const
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

/* Getter & Setter for reference ownedOperation */
std::shared_ptr<Subset<uml::Operation, uml::Feature, uml::NamedElement>> DataTypeImpl::getOwnedOperation() const
{
	if(m_ownedOperation == nullptr)
	{
		/*Subset*/
		m_ownedOperation.reset(new Subset<uml::Operation, uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedOperation()->initSubset(getFeature(), getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_ownedOperation;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DataTypeImpl::eContainer() const
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
void DataTypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DataTypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void DataTypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

		if ( nodeName.compare("ownedOperation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Operation";
			}
			loadHandler->handleChildContainer<uml::Operation>(this->getOwnedOperation());  

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

void DataTypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ClassifierImpl::resolveReferences(featureID, references);
}

void DataTypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void DataTypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedAttribute'
		for (std::shared_ptr<uml::Property> ownedAttribute : *this->getOwnedAttribute()) 
		{
			saveHandler->addReference(ownedAttribute, "ownedAttribute", ownedAttribute->eClass() != package->getProperty_Class());
		}

		// Save 'ownedOperation'
		for (std::shared_ptr<uml::Operation> ownedOperation : *this->getOwnedOperation()) 
		{
			saveHandler->addReference(ownedOperation, "ownedOperation", ownedOperation->eClass() != package->getOperation_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> DataTypeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDataType_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> DataTypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::DATATYPE_ATTRIBUTE_OWNEDATTRIBUTE:
			return eEcoreContainerAny(getOwnedAttribute(),uml::umlPackage::PROPERTY_CLASS); //6538
		case uml::umlPackage::DATATYPE_ATTRIBUTE_OWNEDOPERATION:
			return eEcoreContainerAny(getOwnedOperation(),uml::umlPackage::OPERATION_CLASS); //6539
	}
	return ClassifierImpl::eGet(featureID, resolve, coreType);
}

bool DataTypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::DATATYPE_ATTRIBUTE_OWNEDATTRIBUTE:
			return getOwnedAttribute() != nullptr; //6538
		case uml::umlPackage::DATATYPE_ATTRIBUTE_OWNEDOPERATION:
			return getOwnedOperation() != nullptr; //6539
	}
	return ClassifierImpl::internalEIsSet(featureID);
}

bool DataTypeImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::DATATYPE_ATTRIBUTE_OWNEDATTRIBUTE:
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
		case uml::umlPackage::DATATYPE_ATTRIBUTE_OWNEDOPERATION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Operation>> _ownedOperation = getOwnedOperation();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Operation> valueToAdd = std::dynamic_pointer_cast<uml::Operation>(anEObject);
	
							if (valueToAdd)
							{
								if(_ownedOperation->find(valueToAdd) == -1)
								{
									_ownedOperation->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedOperation'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedOperation'. Failed to set feature!")
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
std::shared_ptr<Any> DataTypeImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::DataType::createOwnedAttribute(std::string, uml::Type, int, int) : uml::Property: 1758368293
		case umlPackage::DATATYPE_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL:
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
		// uml::DataType::createOwnedOperation(std::string, std::string[*], uml::Type[*], uml::Type) : uml::Operation: 4057743014
		case umlPackage::DATATYPE_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE:
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
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'name'. Failed to invoke operation 'createOwnedOperation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'parameterNames'
			//parameter 1
			std::shared_ptr<Bag<std::string>> incoming_param_parameterNames;
			Bag<Any>::const_iterator incoming_param_parameterNames_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_parameterNames = (*incoming_param_parameterNames_arguments_citer)->get<std::shared_ptr<Bag<std::string>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'parameterNames'. Failed to invoke operation 'createOwnedOperation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'parameterTypes'
			//parameter 2
			std::shared_ptr<Bag<uml::Type>> incoming_param_parameterTypes;
			Bag<Any>::const_iterator incoming_param_parameterTypes_arguments_citer = std::next(arguments->begin(), 2);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_parameterTypes_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_parameterTypes.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<uml::Type> _temp = std::dynamic_pointer_cast<uml::Type>(anEObject);
								incoming_param_parameterTypes->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'parameterTypes'. Failed to invoke operation 'createOwnedOperation'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'parameterTypes'. Failed to invoke operation 'createOwnedOperation'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'returnType'
			//parameter 3
			std::shared_ptr<uml::Type> incoming_param_returnType;
			Bag<Any>::const_iterator incoming_param_returnType_arguments_citer = std::next(arguments->begin(), 3);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_returnType_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_returnType = std::dynamic_pointer_cast<uml::Type>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'returnType'. Failed to invoke operation 'createOwnedOperation'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'returnType'. Failed to invoke operation 'createOwnedOperation'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->createOwnedOperation(incoming_param_name,incoming_param_parameterNames,incoming_param_parameterTypes,incoming_param_returnType), uml::umlPackage::OPERATION_CLASS);
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

std::shared_ptr<uml::DataType> DataTypeImpl::getThisDataTypePtr() const
{
	return m_thisDataTypePtr.lock();
}
void DataTypeImpl::setThisDataTypePtr(std::weak_ptr<uml::DataType> thisDataTypePtr)
{
	m_thisDataTypePtr = thisDataTypePtr;
	setThisClassifierPtr(thisDataTypePtr);
}


