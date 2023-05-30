
#include "uml/impl/EncapsulatedClassifierImpl.hpp"
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
#include "uml/Port.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredClassifier.hpp"
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
EncapsulatedClassifierImpl::EncapsulatedClassifierImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EncapsulatedClassifierImpl::~EncapsulatedClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EncapsulatedClassifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(std::weak_ptr<uml::Namespace> par_namespace)
:EncapsulatedClassifierImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(std::weak_ptr<uml::Element> par_owner)
:EncapsulatedClassifierImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:EncapsulatedClassifierImpl()
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
EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:EncapsulatedClassifierImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(const EncapsulatedClassifierImpl & obj): EncapsulatedClassifierImpl()
{
	*this = obj;
}

EncapsulatedClassifierImpl& EncapsulatedClassifierImpl::operator=(const EncapsulatedClassifierImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuredClassifierImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EncapsulatedClassifier 
	 * which is generated by the compiler (as EncapsulatedClassifier is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EncapsulatedClassifier::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EncapsulatedClassifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'ownedPort'
	std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>> ownedPortList = obj.getOwnedPort();
	if(ownedPortList)
	{
		/*Subset*/
		m_ownedPort.reset(new Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedPort()->initSubset(getOwnedAttribute());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >(getOwnedAttribute())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Port> ownedPortindexElem: *ownedPortList) 
		{
			std::shared_ptr<uml::Port> temp = std::dynamic_pointer_cast<uml::Port>((ownedPortindexElem)->copy());
			m_ownedPort->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedPort.")
	}
	/*Subset*/
	getOwnedPort()->initSubset(getOwnedAttribute());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >(getOwnedAttribute())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Port>> EncapsulatedClassifierImpl::getOwnedPorts()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		return this->getOwnedPort();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference ownedPort */
std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>> EncapsulatedClassifierImpl::getOwnedPort() const
{
	//generated from getterBody annotation
	std::shared_ptr<SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property>> ownedAttribute = this->getOwnedAttribute();
	std::shared_ptr<Subset<uml::Port, uml::Property>> ownedPort(new Subset<uml::Port, uml::Property>());
	ownedPort->initSubset(ownedAttribute);

	Bag<uml::Property>::iterator ownedAttributeIter = ownedAttribute->begin();
	Bag<uml::Property>::iterator ownedAttributeEnd = ownedAttribute->end();

	while (ownedAttributeIter != ownedAttributeEnd)
	{
		std::shared_ptr<uml::Port> port = std::dynamic_pointer_cast<uml::Port>(*ownedAttributeIter);

		if(port)
		{
			ownedPort->add(port);
		}

		ownedAttributeIter++;
	}

	return ownedPort;
	//end of body
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EncapsulatedClassifierImpl::eContainer() const
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
void EncapsulatedClassifierImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EncapsulatedClassifierImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StructuredClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void EncapsulatedClassifierImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedPort") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Port";
			}
			loadHandler->handleChildContainer<uml::Port>(this->getOwnedPort());  

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
	StructuredClassifierImpl::loadNode(nodeName, loadHandler);
}

void EncapsulatedClassifierImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	StructuredClassifierImpl::resolveReferences(featureID, references);
}

void EncapsulatedClassifierImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void EncapsulatedClassifierImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedPort'
		for (std::shared_ptr<uml::Port> ownedPort : *this->getOwnedPort()) 
		{
			saveHandler->addReference(ownedPort, "ownedPort", ownedPort->eClass() != package->getPort_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> EncapsulatedClassifierImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getEncapsulatedClassifier_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EncapsulatedClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ENCAPSULATEDCLASSIFIER_ATTRIBUTE_OWNEDPORT:
			return eEcoreContainerAny(getOwnedPort(),uml::umlPackage::PORT_CLASS); //8342
	}
	return StructuredClassifierImpl::eGet(featureID, resolve, coreType);
}

bool EncapsulatedClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ENCAPSULATEDCLASSIFIER_ATTRIBUTE_OWNEDPORT:
			return getOwnedPort() != nullptr; //8342
	}
	return StructuredClassifierImpl::internalEIsSet(featureID);
}

bool EncapsulatedClassifierImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return StructuredClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> EncapsulatedClassifierImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::EncapsulatedClassifier::getOwnedPorts() : uml::Port[*]: 1835476817
		case umlPackage::ENCAPSULATEDCLASSIFIER_OPERATION_GETOWNEDPORTS:
		{
			std::shared_ptr<Bag<uml::Port>> resultList = this->getOwnedPorts();
			return eEcoreContainerAny(resultList,uml::umlPackage::PORT_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = StructuredClassifierImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::EncapsulatedClassifier> EncapsulatedClassifierImpl::getThisEncapsulatedClassifierPtr() const
{
	return m_thisEncapsulatedClassifierPtr.lock();
}
void EncapsulatedClassifierImpl::setThisEncapsulatedClassifierPtr(std::weak_ptr<uml::EncapsulatedClassifier> thisEncapsulatedClassifierPtr)
{
	m_thisEncapsulatedClassifierPtr = thisEncapsulatedClassifierPtr;
	setThisStructuredClassifierPtr(thisEncapsulatedClassifierPtr);
}


