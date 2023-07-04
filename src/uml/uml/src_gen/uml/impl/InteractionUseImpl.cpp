
#include "uml/impl/InteractionUseImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/SubsetUnion.hpp"


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
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Gate.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionFragment.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/Namespace.hpp"
#include "uml/Property.hpp"
#include "uml/StringExpression.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionUseImpl::InteractionUseImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InteractionUseImpl::~InteractionUseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionUse "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:InteractionUseImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:InteractionUseImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InteractionUseImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::Element> par_owner)
:InteractionUseImpl()
{
	m_owner = par_owner;
}

InteractionUseImpl::InteractionUseImpl(const InteractionUseImpl & obj): InteractionUseImpl()
{
	*this = obj;
}

InteractionUseImpl& InteractionUseImpl::operator=(const InteractionUseImpl & obj)
{
	//call overloaded =Operator for each base class
	InteractionFragmentImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InteractionUse 
	 * which is generated by the compiler (as InteractionUse is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InteractionUse::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionUse "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_refersTo  = obj.getRefersTo();
	m_returnValueRecipient  = obj.getReturnValueRecipient();
	//Clone references with containment (deep copy)
	//clone reference 'actualGate'
	std::shared_ptr<Subset<uml::Gate, uml::Element>> actualGateList = obj.getActualGate();
	if(actualGateList)
	{
		/*Subset*/
		m_actualGate.reset(new Subset<uml::Gate, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_actualGate - Subset<uml::Gate, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getActualGate()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_actualGate - Subset<uml::Gate, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Gate> actualGateindexElem: *actualGateList) 
		{
			std::shared_ptr<uml::Gate> temp = std::dynamic_pointer_cast<uml::Gate>((actualGateindexElem)->copy());
			m_actualGate->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr actualGate."<< std::endl;)
	}

	//clone reference 'argument'
	std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> argumentList = obj.getArgument();
	if(argumentList)
	{
		/*Subset*/
		m_argument.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getArgument()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ValueSpecification> argumentindexElem: *argumentList) 
		{
			std::shared_ptr<uml::ValueSpecification> temp = std::dynamic_pointer_cast<uml::ValueSpecification>((argumentindexElem)->copy());
			m_argument->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr argument."<< std::endl;)
	}

	//clone reference 'returnValue'
	if(obj.getReturnValue()!=nullptr)
	{
		m_returnValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getReturnValue()->copy());
	}
	/*Subset*/
	getActualGate()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_actualGate - Subset<uml::Gate, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	getArgument()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> InteractionUseImpl::copy() const
{
	std::shared_ptr<InteractionUseImpl> element(new InteractionUseImpl());
	*element =(*this);
	element->setThisInteractionUsePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool InteractionUseImpl::all_lifelines(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool InteractionUseImpl::arguments_are_constants(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool InteractionUseImpl::arguments_correspond_to_parameters(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool InteractionUseImpl::gates_match(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool InteractionUseImpl::returnValueRecipient_coverage(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool InteractionUseImpl::returnValue_type_recipient_correspondence(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference actualGate */
const std::shared_ptr<Subset<uml::Gate, uml::Element>>& InteractionUseImpl::getActualGate() const
{
	if(m_actualGate == nullptr)
	{
		/*Subset*/
		m_actualGate.reset(new Subset<uml::Gate, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_actualGate - Subset<uml::Gate, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getActualGate()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_actualGate - Subset<uml::Gate, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_actualGate;
}

/* Getter & Setter for reference argument */
const std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>>& InteractionUseImpl::getArgument() const
{
	if(m_argument == nullptr)
	{
		/*Subset*/
		m_argument.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getArgument()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_argument;
}

/* Getter & Setter for reference refersTo */
const std::shared_ptr<uml::Interaction>& InteractionUseImpl::getRefersTo() const
{
    return m_refersTo;
}
void InteractionUseImpl::setRefersTo(const std::shared_ptr<uml::Interaction>& _refersTo)
{
    m_refersTo = _refersTo;
	
}

/* Getter & Setter for reference returnValue */
const std::shared_ptr<uml::ValueSpecification>& InteractionUseImpl::getReturnValue() const
{
    return m_returnValue;
}
void InteractionUseImpl::setReturnValue(const std::shared_ptr<uml::ValueSpecification>& _returnValue)
{
    m_returnValue = _returnValue;
	
}

/* Getter & Setter for reference returnValueRecipient */
const std::shared_ptr<uml::Property>& InteractionUseImpl::getReturnValueRecipient() const
{
    return m_returnValueRecipient;
}
void InteractionUseImpl::setReturnValueRecipient(const std::shared_ptr<uml::Property>& _returnValueRecipient)
{
    m_returnValueRecipient = _returnValueRecipient;
	
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> InteractionUseImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> InteractionUseImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> InteractionUseImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InteractionUseImpl::eContainer() const
{
	if(auto wp = m_enclosingInteraction.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingOperand.lock())
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
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void InteractionUseImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InteractionUseImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("refersTo");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("refersTo")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("returnValueRecipient");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("returnValueRecipient")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	InteractionFragmentImpl::loadAttributes(loadHandler, attr_list);
}

void InteractionUseImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("actualGate") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Gate";
			}
			loadHandler->handleChildContainer<uml::Gate>(this->getActualGate());  

			return; 
		}

		if ( nodeName.compare("argument") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ValueSpecification>(this->getArgument());  

			return; 
		}

		if ( nodeName.compare("returnValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getReturnValue()); 

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
	InteractionFragmentImpl::loadNode(nodeName, loadHandler);
}

void InteractionUseImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_REFERSTO:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interaction> _refersTo = std::dynamic_pointer_cast<uml::Interaction>( references.front() );
				setRefersTo(_refersTo);
			}
			
			return;
		}

		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUERECIPIENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _returnValueRecipient = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setReturnValueRecipient(_returnValueRecipient);
			}
			
			return;
		}
	}
	InteractionFragmentImpl::resolveReferences(featureID, references);
}

void InteractionUseImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InteractionUseImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'actualGate'
		for (std::shared_ptr<uml::Gate> actualGate : *this->getActualGate()) 
		{
			saveHandler->addReference(actualGate, "actualGate", actualGate->eClass() != package->getGate_Class());
		}

		// Save 'argument'
		for (std::shared_ptr<uml::ValueSpecification> argument : *this->getArgument()) 
		{
			saveHandler->addReference(argument, "argument", argument->eClass() != package->getValueSpecification_Class());
		}

		// Save 'returnValue'
		std::shared_ptr<uml::ValueSpecification> returnValue = this->getReturnValue();
		if (returnValue != nullptr)
		{
			saveHandler->addReference(returnValue, "returnValue", returnValue->eClass() != package->getValueSpecification_Class());
		}
	// Add references
		saveHandler->addReference(this->getRefersTo(), "refersTo", getRefersTo()->eClass() != uml::umlPackage::eInstance()->getInteraction_Class()); 
		saveHandler->addReference(this->getReturnValueRecipient(), "returnValueRecipient", getReturnValueRecipient()->eClass() != uml::umlPackage::eInstance()->getProperty_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& InteractionUseImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInteractionUse_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any InteractionUseImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_ACTUALGATE:
			return eAnyBag(getActualGate(),uml::umlPackage::GATE_CLASS); //12413
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_ARGUMENT:
			return eAnyBag(getArgument(),uml::umlPackage::VALUESPECIFICATION_CLASS); //12414
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_REFERSTO:
			return eAny(getRefersTo(),uml::umlPackage::INTERACTION_CLASS,false); //12415
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUE:
			return eAny(getReturnValue(),uml::umlPackage::VALUESPECIFICATION_CLASS,false); //12416
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUERECIPIENT:
			return eAny(getReturnValueRecipient(),uml::umlPackage::PROPERTY_CLASS,false); //12417
	}
	return InteractionFragmentImpl::eGet(featureID, resolve, coreType);
}

bool InteractionUseImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_ACTUALGATE:
			return getActualGate() != nullptr; //12413
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_ARGUMENT:
			return getArgument() != nullptr; //12414
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_REFERSTO:
			return getRefersTo() != nullptr; //12415
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUE:
			return getReturnValue() != nullptr; //12416
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUERECIPIENT:
			return getReturnValueRecipient() != nullptr; //12417
	}
	return InteractionFragmentImpl::internalEIsSet(featureID);
}

bool InteractionUseImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_ACTUALGATE:
		{
			// CAST Any to Bag<uml::Gate>
			if((newValue->isContainer()) && (uml::umlPackage::GATE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Gate>> actualGateList= newValue->get<std::shared_ptr<Bag<uml::Gate>>>();
					std::shared_ptr<Bag<uml::Gate>> _actualGate=getActualGate();
					for(const std::shared_ptr<uml::Gate> indexActualGate: *_actualGate)
					{
						if (!(actualGateList->includes(indexActualGate)))
						{
							_actualGate->erase(indexActualGate);
						}
					}

					for(const std::shared_ptr<uml::Gate> indexActualGate: *actualGateList)
					{
						if (!(_actualGate->includes(indexActualGate)))
						{
							_actualGate->add(indexActualGate);
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
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_ARGUMENT:
		{
			// CAST Any to Bag<uml::ValueSpecification>
			if((newValue->isContainer()) && (uml::umlPackage::VALUESPECIFICATION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ValueSpecification>> argumentList= newValue->get<std::shared_ptr<Bag<uml::ValueSpecification>>>();
					std::shared_ptr<Bag<uml::ValueSpecification>> _argument=getArgument();
					for(const std::shared_ptr<uml::ValueSpecification> indexArgument: *_argument)
					{
						if (!(argumentList->includes(indexArgument)))
						{
							_argument->erase(indexArgument);
						}
					}

					for(const std::shared_ptr<uml::ValueSpecification> indexArgument: *argumentList)
					{
						if (!(_argument->includes(indexArgument)))
						{
							_argument->add(indexArgument);
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
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_REFERSTO:
		{
			// CAST Any to uml::Interaction
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interaction> _refersTo = std::dynamic_pointer_cast<uml::Interaction>(_temp);
			setRefersTo(_refersTo); //12415
			return true;
		}
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUE:
		{
			// CAST Any to uml::ValueSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _returnValue = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setReturnValue(_returnValue); //12416
			return true;
		}
		case uml::umlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUERECIPIENT:
		{
			// CAST Any to uml::Property
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Property> _returnValueRecipient = std::dynamic_pointer_cast<uml::Property>(_temp);
			setReturnValueRecipient(_returnValueRecipient); //12417
			return true;
		}
	}

	return InteractionFragmentImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any InteractionUseImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::InteractionUse::all_lifelines(Any, std::map) : bool: 1011637994
		case umlPackage::INTERACTIONUSE_OPERATION_ALL_LIFELINES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->all_lifelines(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::InteractionUse::arguments_are_constants(Any, std::map) : bool: 733280904
		case umlPackage::INTERACTIONUSE_OPERATION_ARGUMENTS_ARE_CONSTANTS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->arguments_are_constants(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::InteractionUse::arguments_correspond_to_parameters(Any, std::map) : bool: 3043306836
		case umlPackage::INTERACTIONUSE_OPERATION_ARGUMENTS_CORRESPOND_TO_PARAMETERS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->arguments_correspond_to_parameters(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::InteractionUse::gates_match(Any, std::map) : bool: 1724788051
		case umlPackage::INTERACTIONUSE_OPERATION_GATES_MATCH_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->gates_match(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::InteractionUse::returnValueRecipient_coverage(Any, std::map) : bool: 1468221886
		case umlPackage::INTERACTIONUSE_OPERATION_RETURNVALUERECIPIENT_COVERAGE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->returnValueRecipient_coverage(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::InteractionUse::returnValue_type_recipient_correspondence(Any, std::map) : bool: 31244600
		case umlPackage::INTERACTIONUSE_OPERATION_RETURNVALUE_TYPE_RECIPIENT_CORRESPONDENCE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->returnValue_type_recipient_correspondence(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = InteractionFragmentImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::InteractionUse> InteractionUseImpl::getThisInteractionUsePtr() const
{
	return m_thisInteractionUsePtr.lock();
}
void InteractionUseImpl::setThisInteractionUsePtr(std::weak_ptr<uml::InteractionUse> thisInteractionUsePtr)
{
	m_thisInteractionUsePtr = thisInteractionUsePtr;
	setThisInteractionFragmentPtr(thisInteractionUsePtr);
}


