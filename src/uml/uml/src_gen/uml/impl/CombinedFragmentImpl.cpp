
#include "uml/impl/CombinedFragmentImpl.hpp"
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
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
CombinedFragmentImpl::CombinedFragmentImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CombinedFragmentImpl::~CombinedFragmentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CombinedFragment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:CombinedFragmentImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:CombinedFragmentImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::Namespace> par_namespace)
:CombinedFragmentImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::Element> par_owner)
:CombinedFragmentImpl()
{
	m_owner = par_owner;
}

CombinedFragmentImpl::CombinedFragmentImpl(const CombinedFragmentImpl & obj): CombinedFragmentImpl()
{
	*this = obj;
}

CombinedFragmentImpl& CombinedFragmentImpl::operator=(const CombinedFragmentImpl & obj)
{
	//call overloaded =Operator for each base class
	InteractionFragmentImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CombinedFragment 
	 * which is generated by the compiler (as CombinedFragment is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CombinedFragment::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CombinedFragment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_interactionOperator = obj.getInteractionOperator();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'cfragmentGate'
	std::shared_ptr<Subset<uml::Gate, uml::Element>> cfragmentGateList = obj.getCfragmentGate();
	if(cfragmentGateList)
	{
		/*Subset*/
		m_cfragmentGate.reset(new Subset<uml::Gate, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_cfragmentGate - Subset<uml::Gate, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getCfragmentGate()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_cfragmentGate - Subset<uml::Gate, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Gate> cfragmentGateindexElem: *cfragmentGateList) 
		{
			std::shared_ptr<uml::Gate> temp = std::dynamic_pointer_cast<uml::Gate>((cfragmentGateindexElem)->copy());
			m_cfragmentGate->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr cfragmentGate."<< std::endl;)
	}

	//clone reference 'operand'
	std::shared_ptr<Subset<uml::InteractionOperand, uml::Element>> operandList = obj.getOperand();
	if(operandList)
	{
		/*Subset*/
		m_operand.reset(new Subset<uml::InteractionOperand, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_operand - Subset<uml::InteractionOperand, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getOperand()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::InteractionOperand, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::InteractionOperand> operandindexElem: *operandList) 
		{
			std::shared_ptr<uml::InteractionOperand> temp = std::dynamic_pointer_cast<uml::InteractionOperand>((operandindexElem)->copy());
			m_operand->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr operand."<< std::endl;)
	}
	/*Subset*/
	getCfragmentGate()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_cfragmentGate - Subset<uml::Gate, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	getOperand()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::InteractionOperand, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> CombinedFragmentImpl::copy() const
{
	std::shared_ptr<CombinedFragmentImpl> element(new CombinedFragmentImpl());
	*element =(*this);
	element->setThisCombinedFragmentPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool CombinedFragmentImpl::break_(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool CombinedFragmentImpl::consider_and_ignore(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool CombinedFragmentImpl::opt_loop_break_neg(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute interactionOperator */
uml::InteractionOperatorKind CombinedFragmentImpl::getInteractionOperator() const
{
	return m_interactionOperator;
}
void CombinedFragmentImpl::setInteractionOperator(uml::InteractionOperatorKind _interactionOperator)
{
	m_interactionOperator = _interactionOperator;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference cfragmentGate */
const std::shared_ptr<Subset<uml::Gate, uml::Element>>& CombinedFragmentImpl::getCfragmentGate() const
{
	if(m_cfragmentGate == nullptr)
	{
		/*Subset*/
		m_cfragmentGate.reset(new Subset<uml::Gate, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_cfragmentGate - Subset<uml::Gate, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getCfragmentGate()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_cfragmentGate - Subset<uml::Gate, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_cfragmentGate;
}

/* Getter & Setter for reference operand */
const std::shared_ptr<Subset<uml::InteractionOperand, uml::Element>>& CombinedFragmentImpl::getOperand() const
{
	if(m_operand == nullptr)
	{
		/*Subset*/
		m_operand.reset(new Subset<uml::InteractionOperand, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_operand - Subset<uml::InteractionOperand, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getOperand()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::InteractionOperand, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_operand;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> CombinedFragmentImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> CombinedFragmentImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> CombinedFragmentImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CombinedFragmentImpl::eContainer() const
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
void CombinedFragmentImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CombinedFragmentImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("interactionOperator");
		if ( iter != attr_list.end() )
		{
			uml::InteractionOperatorKind value = uml::InteractionOperatorKind::SEQ;
			std::string literal = iter->second;
						if (literal == "seq")
			{
				value = uml::InteractionOperatorKind::SEQ;
			}
			else 			if (literal == "alt")
			{
				value = uml::InteractionOperatorKind::ALT;
			}
			else 			if (literal == "opt")
			{
				value = uml::InteractionOperatorKind::OPT;
			}
			else 			if (literal == "break")
			{
				value = uml::InteractionOperatorKind::BREAK;
			}
			else 			if (literal == "par")
			{
				value = uml::InteractionOperatorKind::PAR;
			}
			else 			if (literal == "strict")
			{
				value = uml::InteractionOperatorKind::STRICT;
			}
			else 			if (literal == "loop")
			{
				value = uml::InteractionOperatorKind::LOOP;
			}
			else 			if (literal == "critical")
			{
				value = uml::InteractionOperatorKind::CRITICAL;
			}
			else 			if (literal == "neg")
			{
				value = uml::InteractionOperatorKind::NEG;
			}
			else 			if (literal == "assert")
			{
				value = uml::InteractionOperatorKind::ASSERT;
			}
			else 			if (literal == "ignore")
			{
				value = uml::InteractionOperatorKind::IGNORE;
			}
			else 			if (literal == "consider")
			{
				value = uml::InteractionOperatorKind::CONSIDER;
			}
			this->setInteractionOperator(value);
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

void CombinedFragmentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("cfragmentGate") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Gate";
			}
			loadHandler->handleChildContainer<uml::Gate>(this->getCfragmentGate());  

			return; 
		}

		if ( nodeName.compare("operand") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InteractionOperand";
			}
			loadHandler->handleChildContainer<uml::InteractionOperand>(this->getOperand());  

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

void CombinedFragmentImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	InteractionFragmentImpl::resolveReferences(featureID, references);
}

void CombinedFragmentImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CombinedFragmentImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'cfragmentGate'
		for (const std::shared_ptr<uml::Gate>& cfragmentGate : *this->getCfragmentGate()) 
		{
			saveHandler->addReference(cfragmentGate, "cfragmentGate", cfragmentGate->eClass() != package->getGate_Class());
		}

		// Save 'operand'
		for (const std::shared_ptr<uml::InteractionOperand>& operand : *this->getOperand()) 
		{
			saveHandler->addReference(operand, "operand", operand->eClass() != package->getInteractionOperand_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getCombinedFragment_Attribute_interactionOperator()) )
		{
			uml::InteractionOperatorKind value = this->getInteractionOperator();
			std::string literal = "";
			if (value == uml::InteractionOperatorKind::SEQ)
			{
				literal = "seq";
			}
			else if (value == uml::InteractionOperatorKind::ALT)
			{
				literal = "alt";
			}
			else if (value == uml::InteractionOperatorKind::OPT)
			{
				literal = "opt";
			}
			else if (value == uml::InteractionOperatorKind::BREAK)
			{
				literal = "break";
			}
			else if (value == uml::InteractionOperatorKind::PAR)
			{
				literal = "par";
			}
			else if (value == uml::InteractionOperatorKind::STRICT)
			{
				literal = "strict";
			}
			else if (value == uml::InteractionOperatorKind::LOOP)
			{
				literal = "loop";
			}
			else if (value == uml::InteractionOperatorKind::CRITICAL)
			{
				literal = "critical";
			}
			else if (value == uml::InteractionOperatorKind::NEG)
			{
				literal = "neg";
			}
			else if (value == uml::InteractionOperatorKind::ASSERT)
			{
				literal = "assert";
			}
			else if (value == uml::InteractionOperatorKind::IGNORE)
			{
				literal = "ignore";
			}
			else if (value == uml::InteractionOperatorKind::CONSIDER)
			{
				literal = "consider";
			}
			saveHandler->addAttribute("interactionOperator", literal);
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& CombinedFragmentImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getCombinedFragment_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CombinedFragmentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::COMBINEDFRAGMENT_ATTRIBUTE_CFRAGMENTGATE:
			return eAnyBag(getCfragmentGate(),uml::umlPackage::GATE_CLASS); //4413
		case uml::umlPackage::COMBINEDFRAGMENT_ATTRIBUTE_INTERACTIONOPERATOR:
			return eAny(getInteractionOperator(),uml::umlPackage::INTERACTIONOPERATORKIND_CLASS,false); //4414
		case uml::umlPackage::COMBINEDFRAGMENT_ATTRIBUTE_OPERAND:
			return eAnyBag(getOperand(),uml::umlPackage::INTERACTIONOPERAND_CLASS); //4415
	}
	return InteractionFragmentImpl::eGet(featureID, resolve, coreType);
}

bool CombinedFragmentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::COMBINEDFRAGMENT_ATTRIBUTE_CFRAGMENTGATE:
			return getCfragmentGate() != nullptr; //4413
		case uml::umlPackage::COMBINEDFRAGMENT_ATTRIBUTE_INTERACTIONOPERATOR:
			return m_interactionOperator != uml::InteractionOperatorKind::SEQ;; //4414
		case uml::umlPackage::COMBINEDFRAGMENT_ATTRIBUTE_OPERAND:
			return getOperand() != nullptr; //4415
	}
	return InteractionFragmentImpl::internalEIsSet(featureID);
}

bool CombinedFragmentImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::COMBINEDFRAGMENT_ATTRIBUTE_CFRAGMENTGATE:
		{
			// CAST Any to Bag<uml::Gate>
			if((newValue->isContainer()) && (uml::umlPackage::GATE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Gate>> cfragmentGateList= newValue->get<std::shared_ptr<Bag<uml::Gate>>>();
					std::shared_ptr<Bag<uml::Gate>> _cfragmentGate=getCfragmentGate();
					for(const std::shared_ptr<uml::Gate> indexCfragmentGate: *_cfragmentGate)
					{
						if (!(cfragmentGateList->includes(indexCfragmentGate)))
						{
							_cfragmentGate->erase(indexCfragmentGate);
						}
					}

					for(const std::shared_ptr<uml::Gate> indexCfragmentGate: *cfragmentGateList)
					{
						if (!(_cfragmentGate->includes(indexCfragmentGate)))
						{
							_cfragmentGate->add(indexCfragmentGate);
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
		case uml::umlPackage::COMBINEDFRAGMENT_ATTRIBUTE_INTERACTIONOPERATOR:
		{
			// CAST Any to uml::InteractionOperatorKind
			uml::InteractionOperatorKind _interactionOperator = newValue->get<uml::InteractionOperatorKind>();
			setInteractionOperator(_interactionOperator); //4414
			return true;
		}
		case uml::umlPackage::COMBINEDFRAGMENT_ATTRIBUTE_OPERAND:
		{
			// CAST Any to Bag<uml::InteractionOperand>
			if((newValue->isContainer()) && (uml::umlPackage::INTERACTIONOPERAND_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::InteractionOperand>> operandList= newValue->get<std::shared_ptr<Bag<uml::InteractionOperand>>>();
					std::shared_ptr<Bag<uml::InteractionOperand>> _operand=getOperand();
					for(const std::shared_ptr<uml::InteractionOperand> indexOperand: *_operand)
					{
						if (!(operandList->includes(indexOperand)))
						{
							_operand->erase(indexOperand);
						}
					}

					for(const std::shared_ptr<uml::InteractionOperand> indexOperand: *operandList)
					{
						if (!(_operand->includes(indexOperand)))
						{
							_operand->add(indexOperand);
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
	}

	return InteractionFragmentImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CombinedFragmentImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::CombinedFragment::break_(Any, std::map) : bool: 3240199571
		case umlPackage::COMBINEDFRAGMENT_OPERATION_BREAK__EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->break_(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::CombinedFragment::consider_and_ignore(Any, std::map) : bool: 161942571
		case umlPackage::COMBINEDFRAGMENT_OPERATION_CONSIDER_AND_IGNORE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->consider_and_ignore(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::CombinedFragment::opt_loop_break_neg(Any, std::map) : bool: 1641284448
		case umlPackage::COMBINEDFRAGMENT_OPERATION_OPT_LOOP_BREAK_NEG_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->opt_loop_break_neg(incoming_param_diagnostics,incoming_param_context),0,false);
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

std::shared_ptr<uml::CombinedFragment> CombinedFragmentImpl::getThisCombinedFragmentPtr() const
{
	return m_thisCombinedFragmentPtr.lock();
}
void CombinedFragmentImpl::setThisCombinedFragmentPtr(std::weak_ptr<uml::CombinedFragment> thisCombinedFragmentPtr)
{
	m_thisCombinedFragmentPtr = thisCombinedFragmentPtr;
	setThisInteractionFragmentPtr(thisCombinedFragmentPtr);
}


