#include "uml/impl/PartDecompositionImpl.hpp"

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

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Gate.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/InteractionUse.hpp"
#include "uml/Lifeline.hpp"
#include "uml/Namespace.hpp"
#include "uml/Property.hpp"
#include "uml/StringExpression.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PartDecompositionImpl::PartDecompositionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PartDecompositionImpl::~PartDecompositionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PartDecomposition "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PartDecompositionImpl::PartDecompositionImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:PartDecompositionImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
PartDecompositionImpl::PartDecompositionImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:PartDecompositionImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
PartDecompositionImpl::PartDecompositionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:PartDecompositionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
PartDecompositionImpl::PartDecompositionImpl(std::weak_ptr<uml::Element> par_owner)
:PartDecompositionImpl()
{
	m_owner = par_owner;
}

PartDecompositionImpl::PartDecompositionImpl(const PartDecompositionImpl & obj): PartDecompositionImpl()
{
	*this = obj;
}

PartDecompositionImpl& PartDecompositionImpl::operator=(const PartDecompositionImpl & obj)
{
	//call overloaded =Operator for each base class
	InteractionUseImpl::operator=(obj);
	PartDecomposition::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PartDecomposition "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PartDecompositionImpl::copy() const
{
	std::shared_ptr<PartDecompositionImpl> element(new PartDecompositionImpl());
	*element =(*this);
	element->setThisPartDecompositionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PartDecompositionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getPartDecomposition_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool PartDecompositionImpl::assume(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PartDecompositionImpl::commutativity_of_decomposition(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PartDecompositionImpl::parts_of_internal_structures(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> PartDecompositionImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> PartDecompositionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> PartDecompositionImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<PartDecomposition> PartDecompositionImpl::getThisPartDecompositionPtr() const
{
	return m_thisPartDecompositionPtr.lock();
}
void PartDecompositionImpl::setThisPartDecompositionPtr(std::weak_ptr<PartDecomposition> thisPartDecompositionPtr)
{
	m_thisPartDecompositionPtr = thisPartDecompositionPtr;
	setThisInteractionUsePtr(thisPartDecompositionPtr);
}
std::shared_ptr<ecore::EObject> PartDecompositionImpl::eContainer() const
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
Any PartDecompositionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return InteractionUseImpl::eGet(featureID, resolve, coreType);
}
bool PartDecompositionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return InteractionUseImpl::internalEIsSet(featureID);
}
bool PartDecompositionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return InteractionUseImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void PartDecompositionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PartDecompositionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	InteractionUseImpl::loadAttributes(loadHandler, attr_list);
}

void PartDecompositionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	InteractionUseImpl::loadNode(nodeName, loadHandler);
}

void PartDecompositionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	InteractionUseImpl::resolveReferences(featureID, references);
}

void PartDecompositionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionUseImpl::saveContent(saveHandler);
	
	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void PartDecompositionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

