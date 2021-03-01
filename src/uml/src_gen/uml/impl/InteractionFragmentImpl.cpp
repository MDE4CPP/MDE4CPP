#include "uml/impl/InteractionFragmentImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionFragmentImpl::InteractionFragmentImpl()
{	
}

InteractionFragmentImpl::~InteractionFragmentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionFragment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:InteractionFragmentImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:InteractionFragmentImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InteractionFragmentImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::Element> par_owner)
:InteractionFragmentImpl()
{
	m_owner = par_owner;
}

InteractionFragmentImpl::InteractionFragmentImpl(const InteractionFragmentImpl & obj): InteractionFragmentImpl()
{
	*this = obj;
}

InteractionFragmentImpl& InteractionFragmentImpl::operator=(const InteractionFragmentImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	InteractionFragment::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionFragment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Lifeline>> _covered = obj.getCovered();
	m_covered.reset(new Bag<uml::Lifeline>(*(obj.getCovered().get())));
	m_enclosingInteraction  = obj.getEnclosingInteraction();
	m_enclosingOperand  = obj.getEnclosingOperand();

	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element>> generalOrderingContainer = getGeneralOrdering();
	for(auto _generalOrdering : *obj.getGeneralOrdering()) 
	{
		generalOrderingContainer->push_back(std::dynamic_pointer_cast<uml::GeneralOrdering>(_generalOrdering->copy()));
	}
	/*Subset*/
	m_generalOrdering->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> InteractionFragmentImpl::copy() const
{
	std::shared_ptr<InteractionFragmentImpl> element(new InteractionFragmentImpl());
	*element =(*this);
	element->setThisInteractionFragmentPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InteractionFragmentImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInteractionFragment_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference covered
*/
std::shared_ptr<Bag<uml::Lifeline>> InteractionFragmentImpl::getCovered() const
{
	if(m_covered == nullptr)
	{
		m_covered.reset(new Bag<uml::Lifeline>());
		
		
	}

    return m_covered;
}



/*
Getter & Setter for reference enclosingInteraction
*/
std::weak_ptr<uml::Interaction> InteractionFragmentImpl::getEnclosingInteraction() const
{

    return m_enclosingInteraction;
}
void InteractionFragmentImpl::setEnclosingInteraction(std::weak_ptr<uml::Interaction> _enclosingInteraction)
{
    m_enclosingInteraction = _enclosingInteraction;
}


/*
Getter & Setter for reference enclosingOperand
*/
std::weak_ptr<uml::InteractionOperand> InteractionFragmentImpl::getEnclosingOperand() const
{

    return m_enclosingOperand;
}
void InteractionFragmentImpl::setEnclosingOperand(std::weak_ptr<uml::InteractionOperand> _enclosingOperand)
{
    m_enclosingOperand = _enclosingOperand;
}


/*
Getter & Setter for reference generalOrdering
*/
std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element>> InteractionFragmentImpl::getGeneralOrdering() const
{
	if(m_generalOrdering == nullptr)
	{
		/*Subset*/
		m_generalOrdering.reset(new Subset<uml::GeneralOrdering, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_generalOrdering->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_generalOrdering;
}



//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> InteractionFragmentImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> InteractionFragmentImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> InteractionFragmentImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<InteractionFragment> InteractionFragmentImpl::getThisInteractionFragmentPtr() const
{
	return m_thisInteractionFragmentPtr.lock();
}
void InteractionFragmentImpl::setThisInteractionFragmentPtr(std::weak_ptr<InteractionFragment> thisInteractionFragmentPtr)
{
	m_thisInteractionFragmentPtr = thisInteractionFragmentPtr;
	setThisNamedElementPtr(thisInteractionFragmentPtr);
}
std::shared_ptr<ecore::EObject> InteractionFragmentImpl::eContainer() const
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
Any InteractionFragmentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_COVERED:
		{
			return eAny(getCovered()); //1219			
		}
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
			return eAny(getEnclosingInteraction().lock()); //12111
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
			return eAny(getEnclosingOperand().lock()); //12110
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_GENERALORDERING:
		{
			return eAny(getGeneralOrdering()); //12112			
		}
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool InteractionFragmentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_COVERED:
			return getCovered() != nullptr; //1219
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
			return getEnclosingInteraction().lock() != nullptr; //12111
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
			return getEnclosingOperand().lock() != nullptr; //12110
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_GENERALORDERING:
			return getGeneralOrdering() != nullptr; //12112
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool InteractionFragmentImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_COVERED:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Lifeline>> coveredList(new Bag<uml::Lifeline>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				coveredList->add(std::dynamic_pointer_cast<uml::Lifeline>(*iter));
				iter++;
			}
			
			Bag<uml::Lifeline>::iterator iterCovered = m_covered->begin();
			Bag<uml::Lifeline>::iterator endCovered = m_covered->end();
			while (iterCovered != endCovered)
			{
				if (coveredList->find(*iterCovered) == -1)
				{
					m_covered->erase(*iterCovered);
				}
				iterCovered++;
			}
 
			iterCovered = coveredList->begin();
			endCovered = coveredList->end();
			while (iterCovered != endCovered)
			{
				if (m_covered->find(*iterCovered) == -1)
				{
					m_covered->add(*iterCovered);
				}
				iterCovered++;			
			}
			return true;
		}
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interaction> _enclosingInteraction = std::dynamic_pointer_cast<uml::Interaction>(_temp);
			setEnclosingInteraction(_enclosingInteraction); //12111
			return true;
		}
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InteractionOperand> _enclosingOperand = std::dynamic_pointer_cast<uml::InteractionOperand>(_temp);
			setEnclosingOperand(_enclosingOperand); //12110
			return true;
		}
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_GENERALORDERING:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::GeneralOrdering>> generalOrderingList(new Bag<uml::GeneralOrdering>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				generalOrderingList->add(std::dynamic_pointer_cast<uml::GeneralOrdering>(*iter));
				iter++;
			}
			
			Bag<uml::GeneralOrdering>::iterator iterGeneralOrdering = m_generalOrdering->begin();
			Bag<uml::GeneralOrdering>::iterator endGeneralOrdering = m_generalOrdering->end();
			while (iterGeneralOrdering != endGeneralOrdering)
			{
				if (generalOrderingList->find(*iterGeneralOrdering) == -1)
				{
					m_generalOrdering->erase(*iterGeneralOrdering);
				}
				iterGeneralOrdering++;
			}
 
			iterGeneralOrdering = generalOrderingList->begin();
			endGeneralOrdering = generalOrderingList->end();
			while (iterGeneralOrdering != endGeneralOrdering)
			{
				if (m_generalOrdering->find(*iterGeneralOrdering) == -1)
				{
					m_generalOrdering->add(*iterGeneralOrdering);
				}
				iterGeneralOrdering++;			
			}
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void InteractionFragmentImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InteractionFragmentImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("covered");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("covered")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void InteractionFragmentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("generalOrdering") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "GeneralOrdering";
			}
			loadHandler->handleChildContainer<uml::GeneralOrdering>(this->getGeneralOrdering());  

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

void InteractionFragmentImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_COVERED:
		{
			std::shared_ptr<Bag<uml::Lifeline>> _covered = getCovered();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Lifeline>  _r = std::dynamic_pointer_cast<uml::Lifeline>(ref);
				if (_r != nullptr)
				{
					_covered->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interaction> _enclosingInteraction = std::dynamic_pointer_cast<uml::Interaction>( references.front() );
				setEnclosingInteraction(_enclosingInteraction);
			}
			
			return;
		}

		case uml::umlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InteractionOperand> _enclosingOperand = std::dynamic_pointer_cast<uml::InteractionOperand>( references.front() );
				setEnclosingOperand(_enclosingOperand);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void InteractionFragmentImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void InteractionFragmentImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'generalOrdering'
		for (std::shared_ptr<uml::GeneralOrdering> generalOrdering : *this->getGeneralOrdering()) 
		{
			saveHandler->addReference(generalOrdering, "generalOrdering", generalOrdering->eClass() != package->getGeneralOrdering_Class());
		}
	// Add references
		saveHandler->addReferences<uml::Lifeline>("covered", this->getCovered());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

