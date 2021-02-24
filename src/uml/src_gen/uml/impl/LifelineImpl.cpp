#include "uml/impl/LifelineImpl.hpp"

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

#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionFragment.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/PartDecomposition.hpp"
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
LifelineImpl::LifelineImpl()
{	
}

LifelineImpl::~LifelineImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Lifeline "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LifelineImpl::LifelineImpl(std::weak_ptr<uml::Interaction> par_interaction)
:LifelineImpl()
{
	m_interaction = par_interaction;
	m_namespace = par_interaction;
}

//Additional constructor for the containments back reference
LifelineImpl::LifelineImpl(std::weak_ptr<uml::Namespace> par_namespace)
:LifelineImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
LifelineImpl::LifelineImpl(std::weak_ptr<uml::Element> par_owner)
:LifelineImpl()
{
	m_owner = par_owner;
}

LifelineImpl::LifelineImpl(const LifelineImpl & obj): NamedElementImpl(obj), Lifeline(obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Lifeline "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::InteractionFragment>> _coveredBy = obj.getCoveredBy();
	m_coveredBy.reset(new Bag<uml::InteractionFragment>(*(obj.getCoveredBy().get())));
	m_decomposedAs  = obj.getDecomposedAs();
	m_interaction  = obj.getInteraction();
	m_represents  = obj.getRepresents();

	//Clone references with containment (deep copy)
	if(obj.getSelector()!=nullptr)
	{
		m_selector = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getSelector()->copy());
	}
	
}

std::shared_ptr<ecore::EObject>  LifelineImpl::copy() const
{
	std::shared_ptr<LifelineImpl> element(new LifelineImpl(*this));
	element->setThisLifelinePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LifelineImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLifeline_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool LifelineImpl::interaction_uses_share_lifeline(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LifelineImpl::same_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LifelineImpl::selector_int_or_string(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LifelineImpl::selector_specified(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference coveredBy
*/
std::shared_ptr<Bag<uml::InteractionFragment>> LifelineImpl::getCoveredBy() const
{
	if(m_coveredBy == nullptr)
	{
		m_coveredBy.reset(new Bag<uml::InteractionFragment>());
		
		
	}

    return m_coveredBy;
}



/*
Getter & Setter for reference decomposedAs
*/
std::shared_ptr<uml::PartDecomposition> LifelineImpl::getDecomposedAs() const
{

    return m_decomposedAs;
}
void LifelineImpl::setDecomposedAs(std::shared_ptr<uml::PartDecomposition> _decomposedAs)
{
    m_decomposedAs = _decomposedAs;
}


/*
Getter & Setter for reference interaction
*/
std::weak_ptr<uml::Interaction> LifelineImpl::getInteraction() const
{
//assert(m_interaction);
    return m_interaction;
}
void LifelineImpl::setInteraction(std::weak_ptr<uml::Interaction> _interaction)
{
    m_interaction = _interaction;
}


/*
Getter & Setter for reference represents
*/
std::shared_ptr<uml::ConnectableElement> LifelineImpl::getRepresents() const
{

    return m_represents;
}
void LifelineImpl::setRepresents(std::shared_ptr<uml::ConnectableElement> _represents)
{
    m_represents = _represents;
}


/*
Getter & Setter for reference selector
*/
std::shared_ptr<uml::ValueSpecification> LifelineImpl::getSelector() const
{

    return m_selector;
}
void LifelineImpl::setSelector(std::shared_ptr<uml::ValueSpecification> _selector)
{
    m_selector = _selector;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> LifelineImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> LifelineImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> LifelineImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Lifeline> LifelineImpl::getThisLifelinePtr() const
{
	return m_thisLifelinePtr.lock();
}
void LifelineImpl::setThisLifelinePtr(std::weak_ptr<Lifeline> thisLifelinePtr)
{
	m_thisLifelinePtr = thisLifelinePtr;
	setThisNamedElementPtr(thisLifelinePtr);
}
std::shared_ptr<ecore::EObject> LifelineImpl::eContainer() const
{
	if(auto wp = m_interaction.lock())
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
Any LifelineImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LIFELINE_ATTRIBUTE_COVEREDBY:
		{
			return eAny(getCoveredBy()); //13213			
		}
		case uml::umlPackage::LIFELINE_ATTRIBUTE_DECOMPOSEDAS:
			return eAny(getDecomposedAs()); //1329
		case uml::umlPackage::LIFELINE_ATTRIBUTE_INTERACTION:
			return eAny(getInteraction().lock()); //13210
		case uml::umlPackage::LIFELINE_ATTRIBUTE_REPRESENTS:
			return eAny(getRepresents()); //13211
		case uml::umlPackage::LIFELINE_ATTRIBUTE_SELECTOR:
			return eAny(getSelector()); //13212
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool LifelineImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LIFELINE_ATTRIBUTE_COVEREDBY:
			return getCoveredBy() != nullptr; //13213
		case uml::umlPackage::LIFELINE_ATTRIBUTE_DECOMPOSEDAS:
			return getDecomposedAs() != nullptr; //1329
		case uml::umlPackage::LIFELINE_ATTRIBUTE_INTERACTION:
			return getInteraction().lock() != nullptr; //13210
		case uml::umlPackage::LIFELINE_ATTRIBUTE_REPRESENTS:
			return getRepresents() != nullptr; //13211
		case uml::umlPackage::LIFELINE_ATTRIBUTE_SELECTOR:
			return getSelector() != nullptr; //13212
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool LifelineImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LIFELINE_ATTRIBUTE_COVEREDBY:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InteractionFragment>> coveredByList(new Bag<uml::InteractionFragment>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				coveredByList->add(std::dynamic_pointer_cast<uml::InteractionFragment>(*iter));
				iter++;
			}
			
			Bag<uml::InteractionFragment>::iterator iterCoveredBy = m_coveredBy->begin();
			Bag<uml::InteractionFragment>::iterator endCoveredBy = m_coveredBy->end();
			while (iterCoveredBy != endCoveredBy)
			{
				if (coveredByList->find(*iterCoveredBy) == -1)
				{
					m_coveredBy->erase(*iterCoveredBy);
				}
				iterCoveredBy++;
			}
 
			iterCoveredBy = coveredByList->begin();
			endCoveredBy = coveredByList->end();
			while (iterCoveredBy != endCoveredBy)
			{
				if (m_coveredBy->find(*iterCoveredBy) == -1)
				{
					m_coveredBy->add(*iterCoveredBy);
				}
				iterCoveredBy++;			
			}
			return true;
		}
		case uml::umlPackage::LIFELINE_ATTRIBUTE_DECOMPOSEDAS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::PartDecomposition> _decomposedAs = std::dynamic_pointer_cast<uml::PartDecomposition>(_temp);
			setDecomposedAs(_decomposedAs); //1329
			return true;
		}
		case uml::umlPackage::LIFELINE_ATTRIBUTE_INTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interaction> _interaction = std::dynamic_pointer_cast<uml::Interaction>(_temp);
			setInteraction(_interaction); //13210
			return true;
		}
		case uml::umlPackage::LIFELINE_ATTRIBUTE_REPRESENTS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ConnectableElement> _represents = std::dynamic_pointer_cast<uml::ConnectableElement>(_temp);
			setRepresents(_represents); //13211
			return true;
		}
		case uml::umlPackage::LIFELINE_ATTRIBUTE_SELECTOR:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _selector = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setSelector(_selector); //13212
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LifelineImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LifelineImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("coveredBy");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("coveredBy")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("decomposedAs");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("decomposedAs")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("represents");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("represents")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void LifelineImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("selector") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getSelector()); 

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
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void LifelineImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::LIFELINE_ATTRIBUTE_COVEREDBY:
		{
			std::shared_ptr<Bag<uml::InteractionFragment>> _coveredBy = getCoveredBy();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::InteractionFragment>  _r = std::dynamic_pointer_cast<uml::InteractionFragment>(ref);
				if (_r != nullptr)
				{
					_coveredBy->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::LIFELINE_ATTRIBUTE_DECOMPOSEDAS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::PartDecomposition> _decomposedAs = std::dynamic_pointer_cast<uml::PartDecomposition>( references.front() );
				setDecomposedAs(_decomposedAs);
			}
			
			return;
		}

		case uml::umlPackage::LIFELINE_ATTRIBUTE_INTERACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interaction> _interaction = std::dynamic_pointer_cast<uml::Interaction>( references.front() );
				setInteraction(_interaction);
			}
			
			return;
		}

		case uml::umlPackage::LIFELINE_ATTRIBUTE_REPRESENTS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ConnectableElement> _represents = std::dynamic_pointer_cast<uml::ConnectableElement>( references.front() );
				setRepresents(_represents);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void LifelineImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void LifelineImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'selector'
		std::shared_ptr<uml::ValueSpecification> selector = this->getSelector();
		if (selector != nullptr)
		{
			saveHandler->addReference(selector, "selector", selector->eClass() != package->getValueSpecification_Class());
		}
	// Add references
		saveHandler->addReferences<uml::InteractionFragment>("coveredBy", this->getCoveredBy());
		saveHandler->addReference(this->getDecomposedAs(), "decomposedAs", getDecomposedAs()->eClass() != uml::umlPackage::eInstance()->getPartDecomposition_Class()); 
		saveHandler->addReference(this->getRepresents(), "represents", getRepresents()->eClass() != uml::umlPackage::eInstance()->getConnectableElement_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

