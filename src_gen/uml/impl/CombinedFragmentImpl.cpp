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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Gate.hpp"

#include "uml/GeneralOrdering.hpp"

#include "uml/Interaction.hpp"

#include "uml/InteractionFragment.hpp"

#include "uml/InteractionOperand.hpp"

#include "uml/Lifeline.hpp"

#include "uml/Namespace.hpp"

#include "uml/StringExpression.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
CombinedFragmentImpl::CombinedFragmentImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_cfragmentGate.reset(new Subset<uml::Gate, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_cfragmentGate - Subset<uml::Gate, uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_operand.reset(new Subset<uml::InteractionOperand, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_operand - Subset<uml::InteractionOperand, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_cfragmentGate->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_cfragmentGate - Subset<uml::Gate, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_operand->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::InteractionOperand, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

CombinedFragmentImpl::~CombinedFragmentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CombinedFragment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:CombinedFragmentImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
				m_namespace = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:CombinedFragmentImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
				m_namespace = par_enclosingOperand;
			}





//Additional constructor for the containments back reference
			CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:CombinedFragmentImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::Element > par_owner)
			:CombinedFragmentImpl()
			{
			    m_owner = par_owner;
			}






CombinedFragmentImpl::CombinedFragmentImpl(const CombinedFragmentImpl & obj):CombinedFragmentImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CombinedFragment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_interactionOperator = obj.getInteractionOperator();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::Lifeline>> _covered = obj.getCovered();
	m_covered.reset(new Bag<uml::Lifeline>(*(obj.getCovered().get())));

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Gate>> _cfragmentGateList = obj.getCfragmentGate();
	for(std::shared_ptr<uml::Gate> _cfragmentGate : *_cfragmentGateList)
	{
		this->getCfragmentGate()->add(std::shared_ptr<uml::Gate>(std::dynamic_pointer_cast<uml::Gate>(_cfragmentGate->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_cfragmentGate" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrderingList = obj.getGeneralOrdering();
	for(std::shared_ptr<uml::GeneralOrdering> _generalOrdering : *_generalOrderingList)
	{
		this->getGeneralOrdering()->add(std::shared_ptr<uml::GeneralOrdering>(std::dynamic_pointer_cast<uml::GeneralOrdering>(_generalOrdering->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalOrdering" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InteractionOperand>> _operandList = obj.getOperand();
	for(std::shared_ptr<uml::InteractionOperand> _operand : *_operandList)
	{
		this->getOperand()->add(std::shared_ptr<uml::InteractionOperand>(std::dynamic_pointer_cast<uml::InteractionOperand>(_operand->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_operand" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

		/*Subset*/
		m_cfragmentGate->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_cfragmentGate - Subset<uml::Gate, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_operand->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::InteractionOperand, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  CombinedFragmentImpl::copy() const
{
	std::shared_ptr<CombinedFragmentImpl> element(new CombinedFragmentImpl(*this));
	element->setThisCombinedFragmentPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CombinedFragmentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getCombinedFragment_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void CombinedFragmentImpl::setInteractionOperator(InteractionOperatorKind _interactionOperator)
{
	m_interactionOperator = _interactionOperator;
} 

InteractionOperatorKind CombinedFragmentImpl::getInteractionOperator() const 
{
	return m_interactionOperator;
}

//*********************************
// Operations
//*********************************
bool CombinedFragmentImpl::break_(Any diagnostics,std::map <   Any, Any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CombinedFragmentImpl::consider_and_ignore(Any diagnostics,std::map <   Any, Any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CombinedFragmentImpl::opt_loop_break_neg(Any diagnostics,std::map <   Any, Any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Gate, uml::Element>> CombinedFragmentImpl::getCfragmentGate() const
{

    return m_cfragmentGate;
}


std::shared_ptr<Subset<uml::InteractionOperand, uml::Element>> CombinedFragmentImpl::getOperand() const
{
//assert(m_operand);
    return m_operand;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > CombinedFragmentImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> CombinedFragmentImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > CombinedFragmentImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<CombinedFragment> CombinedFragmentImpl::getThisCombinedFragmentPtr()
{
	return m_thisCombinedFragmentPtr.lock();
}
void CombinedFragmentImpl::setThisCombinedFragmentPtr(std::weak_ptr<CombinedFragment> thisCombinedFragmentPtr)
{
	m_thisCombinedFragmentPtr = thisCombinedFragmentPtr;
	setThisInteractionFragmentPtr(thisCombinedFragmentPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any CombinedFragmentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::COMBINEDFRAGMENT_EREFERENCE_CFRAGMENTGATE:
			return eAny(getCfragmentGate()); //22814
		case UmlPackage::COMBINEDFRAGMENT_EATTRIBUTE_INTERACTIONOPERATOR:
			return eAny(getInteractionOperator()); //22815
		case UmlPackage::COMBINEDFRAGMENT_EREFERENCE_OPERAND:
			return eAny(getOperand()); //22816
	}
	return InteractionFragmentImpl::eGet(featureID, resolve, coreType);
}
bool CombinedFragmentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::COMBINEDFRAGMENT_EREFERENCE_CFRAGMENTGATE:
			return getCfragmentGate() != nullptr; //22814
		case UmlPackage::COMBINEDFRAGMENT_EATTRIBUTE_INTERACTIONOPERATOR:
			return m_interactionOperator != InteractionOperatorKind::SEQ;; //22815
		case UmlPackage::COMBINEDFRAGMENT_EREFERENCE_OPERAND:
			return getOperand() != nullptr; //22816
	}
	return InteractionFragmentImpl::internalEIsSet(featureID);
}
bool CombinedFragmentImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::COMBINEDFRAGMENT_EATTRIBUTE_INTERACTIONOPERATOR:
		{
			// BOOST CAST
			InteractionOperatorKind _interactionOperator = newValue->get<InteractionOperatorKind>();
			setInteractionOperator(_interactionOperator); //22815
			return true;
		}
	}

	return InteractionFragmentImpl::eSet(featureID, newValue);
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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
			InteractionOperatorKind value = InteractionOperatorKind::SEQ;
			std::string literal = iter->second;
			if (literal == "seq")
			{
				value = InteractionOperatorKind::SEQ;
			}
			else if (literal == "alt")
			{
				value = InteractionOperatorKind::ALT;
			}
			else if (literal == "opt")
			{
				value = InteractionOperatorKind::OPT;
			}
			else if (literal == "break")
			{
				value = InteractionOperatorKind::BREAK;
			}
			else if (literal == "par")
			{
				value = InteractionOperatorKind::PAR;
			}
			else if (literal == "strict")
			{
				value = InteractionOperatorKind::STRICT;
			}
			else if (literal == "loop")
			{
				value = InteractionOperatorKind::LOOP;
			}
			else if (literal == "critical")
			{
				value = InteractionOperatorKind::CRITICAL;
			}
			else if (literal == "neg")
			{
				value = InteractionOperatorKind::NEG;
			}
			else if (literal == "assert")
			{
				value = InteractionOperatorKind::ASSERT;
			}
			else if (literal == "ignore")
			{
				value = InteractionOperatorKind::IGNORE;
			}
			else if (literal == "consider")
			{
				value = InteractionOperatorKind::CONSIDER;
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

void CombinedFragmentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
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
			std::shared_ptr<uml::Gate> cfragmentGate = std::dynamic_pointer_cast<uml::Gate>(modelFactory->create(typeName));
			if (cfragmentGate != nullptr)
			{
				std::shared_ptr<Subset<uml::Gate, uml::Element>> list_cfragmentGate = this->getCfragmentGate();
				list_cfragmentGate->push_back(cfragmentGate);
				loadHandler->handleChild(cfragmentGate);
			}
			return;
		}

		if ( nodeName.compare("operand") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InteractionOperand";
			}
			std::shared_ptr<uml::InteractionOperand> operand = std::dynamic_pointer_cast<uml::InteractionOperand>(modelFactory->create(typeName));
			if (operand != nullptr)
			{
				std::shared_ptr<Subset<uml::InteractionOperand, uml::Element>> list_operand = this->getOperand();
				list_operand->push_back(operand);
				loadHandler->handleChild(operand);
			}
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

	InteractionFragmentImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void CombinedFragmentImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	InteractionFragmentImpl::resolveReferences(featureID, references);
}

void CombinedFragmentImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void CombinedFragmentImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'cfragmentGate'
		for (std::shared_ptr<uml::Gate> cfragmentGate : *this->getCfragmentGate()) 
		{
			saveHandler->addReference(cfragmentGate, "cfragmentGate", cfragmentGate->eClass() != package->getGate_EClass());
		}

		// Save 'operand'
		for (std::shared_ptr<uml::InteractionOperand> operand : *this->getOperand()) 
		{
			saveHandler->addReference(operand, "operand", operand->eClass() != package->getInteractionOperand_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getCombinedFragment_EAttribute_interactionOperator()) )
		{
			InteractionOperatorKind value = this->getInteractionOperator();
			std::string literal = "";
			if (value == InteractionOperatorKind::SEQ)
			{
				literal = "seq";
			}
			else if (value == InteractionOperatorKind::ALT)
			{
				literal = "alt";
			}
			else if (value == InteractionOperatorKind::OPT)
			{
				literal = "opt";
			}
			else if (value == InteractionOperatorKind::BREAK)
			{
				literal = "break";
			}
			else if (value == InteractionOperatorKind::PAR)
			{
				literal = "par";
			}
			else if (value == InteractionOperatorKind::STRICT)
			{
				literal = "strict";
			}
			else if (value == InteractionOperatorKind::LOOP)
			{
				literal = "loop";
			}
			else if (value == InteractionOperatorKind::CRITICAL)
			{
				literal = "critical";
			}
			else if (value == InteractionOperatorKind::NEG)
			{
				literal = "neg";
			}
			else if (value == InteractionOperatorKind::ASSERT)
			{
				literal = "assert";
			}
			else if (value == InteractionOperatorKind::IGNORE)
			{
				literal = "ignore";
			}
			else if (value == InteractionOperatorKind::CONSIDER)
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

