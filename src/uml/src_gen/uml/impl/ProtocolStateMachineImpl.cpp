#include "uml/impl/ProtocolStateMachineImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

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
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterSet.hpp"
#include "uml/Port.hpp"
#include "uml/Property.hpp"
#include "uml/ProtocolConformance.hpp"
#include "uml/Pseudostate.hpp"
#include "uml/Reception.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/Region.hpp"
#include "uml/State.hpp"
#include "uml/StateMachine.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/UseCase.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProtocolStateMachineImpl::ProtocolStateMachineImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ProtocolStateMachineImpl::~ProtocolStateMachineImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProtocolStateMachine "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ProtocolStateMachineImpl::ProtocolStateMachineImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier)
:ProtocolStateMachineImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}

//Additional constructor for the containments back reference
ProtocolStateMachineImpl::ProtocolStateMachineImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ProtocolStateMachineImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ProtocolStateMachineImpl::ProtocolStateMachineImpl(std::weak_ptr<uml::Element> par_owner)
:ProtocolStateMachineImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ProtocolStateMachineImpl::ProtocolStateMachineImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:ProtocolStateMachineImpl()
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
ProtocolStateMachineImpl::ProtocolStateMachineImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ProtocolStateMachineImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


ProtocolStateMachineImpl::ProtocolStateMachineImpl(const ProtocolStateMachineImpl & obj): ProtocolStateMachineImpl()
{
	*this = obj;
}

ProtocolStateMachineImpl& ProtocolStateMachineImpl::operator=(const ProtocolStateMachineImpl & obj)
{
	//call overloaded =Operator for each base class
	StateMachineImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ProtocolStateMachine 
	 * which is generated by the compiler (as ProtocolStateMachine is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ProtocolStateMachine::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ProtocolStateMachine "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'conformance'
	std::shared_ptr<Subset<uml::ProtocolConformance, uml::Element>> conformanceList = obj.getConformance();
	if(conformanceList)
	{
		/*Subset*/
		m_conformance.reset(new Subset<uml::ProtocolConformance, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_conformance - Subset<uml::ProtocolConformance, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getConformance()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_conformance - Subset<uml::ProtocolConformance, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		

		Bag<uml::ProtocolConformance>::iterator conformanceIter = conformanceList->begin();
		Bag<uml::ProtocolConformance>::iterator conformanceEnd = conformanceList->end();
		while (conformanceIter != conformanceEnd) 
		{
			std::shared_ptr<uml::ProtocolConformance> temp = std::dynamic_pointer_cast<uml::ProtocolConformance>((*conformanceIter)->copy());
			getConformance()->push_back(temp);
			conformanceIter++;
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr conformance."<< std::endl;)
	}
	/*Subset*/
	getConformance()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_conformance - Subset<uml::ProtocolConformance, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ProtocolStateMachineImpl::copy() const
{
	std::shared_ptr<ProtocolStateMachineImpl> element(new ProtocolStateMachineImpl());
	*element =(*this);
	element->setThisProtocolStateMachinePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ProtocolStateMachineImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getProtocolStateMachine_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ProtocolStateMachineImpl::deep_or_shallow_history(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProtocolStateMachineImpl::entry_exit_do(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProtocolStateMachineImpl::protocol_transitions(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference conformance
*/
std::shared_ptr<Subset<uml::ProtocolConformance, uml::Element>> ProtocolStateMachineImpl::getConformance() const
{
	if(m_conformance == nullptr)
	{
		/*Subset*/
		m_conformance.reset(new Subset<uml::ProtocolConformance, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_conformance - Subset<uml::ProtocolConformance, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getConformance()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_conformance - Subset<uml::ProtocolConformance, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_conformance;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> ProtocolStateMachineImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getAttribute()->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> ProtocolStateMachineImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getFeature()->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

std::shared_ptr<Union<uml::NamedElement>> ProtocolStateMachineImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> ProtocolStateMachineImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ProtocolStateMachineImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> ProtocolStateMachineImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedMember()->initSubsetUnion(getOwnedElement(), getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >(getOwnedElement(), getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> ProtocolStateMachineImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ProtocolStateMachineImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}

std::shared_ptr<Union<uml::Classifier>> ProtocolStateMachineImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_redefinitionContext;
}

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> ProtocolStateMachineImpl::getRole() const
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




std::shared_ptr<ProtocolStateMachine> ProtocolStateMachineImpl::getThisProtocolStateMachinePtr() const
{
	return m_thisProtocolStateMachinePtr.lock();
}
void ProtocolStateMachineImpl::setThisProtocolStateMachinePtr(std::weak_ptr<ProtocolStateMachine> thisProtocolStateMachinePtr)
{
	m_thisProtocolStateMachinePtr = thisProtocolStateMachinePtr;
	setThisStateMachinePtr(thisProtocolStateMachinePtr);
}
std::shared_ptr<ecore::EObject> ProtocolStateMachineImpl::eContainer() const
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
// Structural Feature Getter/Setter
//*********************************
Any ProtocolStateMachineImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLSTATEMACHINE_ATTRIBUTE_CONFORMANCE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ProtocolConformance>::iterator iter = getConformance()->begin();
			Bag<uml::ProtocolConformance>::iterator end = getConformance()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //18766			
		}
	}
	return StateMachineImpl::eGet(featureID, resolve, coreType);
}
bool ProtocolStateMachineImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLSTATEMACHINE_ATTRIBUTE_CONFORMANCE:
			return getConformance() != nullptr; //18766
	}
	return StateMachineImpl::internalEIsSet(featureID);
}
bool ProtocolStateMachineImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLSTATEMACHINE_ATTRIBUTE_CONFORMANCE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ProtocolConformance>> conformanceList(new Bag<uml::ProtocolConformance>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				conformanceList->add(std::dynamic_pointer_cast<uml::ProtocolConformance>(*iter));
				iter++;
			}
			
			Bag<uml::ProtocolConformance>::iterator iterConformance = getConformance()->begin();
			Bag<uml::ProtocolConformance>::iterator endConformance = getConformance()->end();
			while (iterConformance != endConformance)
			{
				if (conformanceList->find(*iterConformance) == -1)
				{
					getConformance()->erase(*iterConformance);
				}
				iterConformance++;
			}
 
			iterConformance = conformanceList->begin();
			endConformance = conformanceList->end();
			while (iterConformance != endConformance)
			{
				if (getConformance()->find(*iterConformance) == -1)
				{
					getConformance()->add(*iterConformance);
				}
				iterConformance++;			
			}
			return true;
		}
	}

	return StateMachineImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ProtocolStateMachineImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 18904
		case umlPackage::PROTOCOLSTATEMACHINE_OPERATION_DEEP_OR_SHALLOW_HISTORY_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->deep_or_shallow_history(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 18905
		case umlPackage::PROTOCOLSTATEMACHINE_OPERATION_ENTRY_EXIT_DO_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->entry_exit_do(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 18906
		case umlPackage::PROTOCOLSTATEMACHINE_OPERATION_PROTOCOL_TRANSITIONS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->protocol_transitions(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = StateMachineImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ProtocolStateMachineImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ProtocolStateMachineImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StateMachineImpl::loadAttributes(loadHandler, attr_list);
}

void ProtocolStateMachineImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("conformance") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ProtocolConformance";
			}
			loadHandler->handleChildContainer<uml::ProtocolConformance>(this->getConformance());  

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
	StateMachineImpl::loadNode(nodeName, loadHandler);
}

void ProtocolStateMachineImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	StateMachineImpl::resolveReferences(featureID, references);
}

void ProtocolStateMachineImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StateMachineImpl::saveContent(saveHandler);
	
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

void ProtocolStateMachineImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'conformance'
		for (std::shared_ptr<uml::ProtocolConformance> conformance : *this->getConformance()) 
		{
			saveHandler->addReference(conformance, "conformance", conformance->eClass() != package->getProtocolConformance_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

