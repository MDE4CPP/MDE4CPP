
#include "uml/impl/FunctionBehaviorImpl.hpp"
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
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Behavior.hpp"
#include "uml/BehavioralFeature.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/DataType.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Extension.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterSet.hpp"
#include "uml/Port.hpp"
#include "uml/Property.hpp"
#include "uml/Reception.hpp"
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
FunctionBehaviorImpl::FunctionBehaviorImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

FunctionBehaviorImpl::~FunctionBehaviorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FunctionBehavior "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
FunctionBehaviorImpl::FunctionBehaviorImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier)
:FunctionBehaviorImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}

//Additional constructor for the containments back reference
FunctionBehaviorImpl::FunctionBehaviorImpl(std::weak_ptr<uml::Namespace> par_namespace)
:FunctionBehaviorImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
FunctionBehaviorImpl::FunctionBehaviorImpl(std::weak_ptr<uml::Element> par_owner)
:FunctionBehaviorImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
FunctionBehaviorImpl::FunctionBehaviorImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:FunctionBehaviorImpl()
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
FunctionBehaviorImpl::FunctionBehaviorImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:FunctionBehaviorImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


FunctionBehaviorImpl::FunctionBehaviorImpl(const FunctionBehaviorImpl & obj): FunctionBehaviorImpl()
{
	*this = obj;
}

FunctionBehaviorImpl& FunctionBehaviorImpl::operator=(const FunctionBehaviorImpl & obj)
{
	//call overloaded =Operator for each base class
	OpaqueBehaviorImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of FunctionBehavior 
	 * which is generated by the compiler (as FunctionBehavior is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//FunctionBehavior::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FunctionBehavior "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> FunctionBehaviorImpl::copy() const
{
	std::shared_ptr<FunctionBehaviorImpl> element(new FunctionBehaviorImpl());
	*element =(*this);
	element->setThisFunctionBehaviorPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool FunctionBehaviorImpl::hasAllDataTypeAttributes(const std::shared_ptr<uml::DataType>& d)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> FunctionBehaviorImpl::eContainer() const
{
	if(auto wp = m_behavioredClassifier.lock())
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
void FunctionBehaviorImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void FunctionBehaviorImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	OpaqueBehaviorImpl::loadAttributes(loadHandler, attr_list);
}

void FunctionBehaviorImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OpaqueBehaviorImpl::loadNode(nodeName, loadHandler);
}

void FunctionBehaviorImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	OpaqueBehaviorImpl::resolveReferences(featureID, references);
}

void FunctionBehaviorImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OpaqueBehaviorImpl::saveContent(saveHandler);
	
	BehaviorImpl::saveContent(saveHandler);
	
	ClassImpl::saveContent(saveHandler);
	
	BehavioredClassifierImpl::saveContent(saveHandler);
	EncapsulatedClassifierImpl::saveContent(saveHandler);
	
	StructuredClassifierImpl::saveContent(saveHandler);
	
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

void FunctionBehaviorImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& FunctionBehaviorImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getFunctionBehavior_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> FunctionBehaviorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return OpaqueBehaviorImpl::eGet(featureID, resolve, coreType);
}

bool FunctionBehaviorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return OpaqueBehaviorImpl::internalEIsSet(featureID);
}

bool FunctionBehaviorImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return OpaqueBehaviorImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> FunctionBehaviorImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::FunctionBehavior::hasAllDataTypeAttributes(uml::DataType) : bool: 206268165
		case umlPackage::FUNCTIONBEHAVIOR_OPERATION_HASALLDATATYPEATTRIBUTES_DATATYPE:
		{
			//Retrieve input parameter 'd'
			//parameter 0
			std::shared_ptr<uml::DataType> incoming_param_d;
			Bag<Any>::const_iterator incoming_param_d_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_d_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_d = std::dynamic_pointer_cast<uml::DataType>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'd'. Failed to invoke operation 'hasAllDataTypeAttributes'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'd'. Failed to invoke operation 'hasAllDataTypeAttributes'!")
					return nullptr;
				}
			}
		
			result = eAny(this->hasAllDataTypeAttributes(incoming_param_d), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = OpaqueBehaviorImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::FunctionBehavior> FunctionBehaviorImpl::getThisFunctionBehaviorPtr() const
{
	return m_thisFunctionBehaviorPtr.lock();
}
void FunctionBehaviorImpl::setThisFunctionBehaviorPtr(std::weak_ptr<uml::FunctionBehavior> thisFunctionBehaviorPtr)
{
	m_thisFunctionBehaviorPtr = thisFunctionBehaviorPtr;
	setThisOpaqueBehaviorPtr(thisFunctionBehaviorPtr);
}


