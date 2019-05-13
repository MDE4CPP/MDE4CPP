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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

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
InteractionFragmentImpl::InteractionFragmentImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_covered.reset(new Bag<uml::Lifeline>());
	
	

	

	

		/*Subset*/
		m_generalOrdering.reset(new Subset<uml::GeneralOrdering, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
	
	

	

	

		/*Subset*/
		m_generalOrdering->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

InteractionFragmentImpl::~InteractionFragmentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionFragment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:InteractionFragmentImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
				m_namespace = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:InteractionFragmentImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
				m_namespace = par_enclosingOperand;
			}





//Additional constructor for the containments back reference
			InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InteractionFragmentImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			InteractionFragmentImpl::InteractionFragmentImpl(std::weak_ptr<uml::Element > par_owner)
			:InteractionFragmentImpl()
			{
			    m_owner = par_owner;
			}






InteractionFragmentImpl::InteractionFragmentImpl(const InteractionFragmentImpl & obj):InteractionFragmentImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionFragment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
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
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

		/*Subset*/
		m_generalOrdering->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalOrdering - Subset<uml::GeneralOrdering, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  InteractionFragmentImpl::copy() const
{
	std::shared_ptr<InteractionFragmentImpl> element(new InteractionFragmentImpl(*this));
	element->setThisInteractionFragmentPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InteractionFragmentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionFragment_EClass();
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
std::shared_ptr<Bag<uml::Lifeline>> InteractionFragmentImpl::getCovered() const
{

    return m_covered;
}


std::weak_ptr<uml::Interaction > InteractionFragmentImpl::getEnclosingInteraction() const
{

    return m_enclosingInteraction;
}
void InteractionFragmentImpl::setEnclosingInteraction(std::shared_ptr<uml::Interaction> _enclosingInteraction)
{
    m_enclosingInteraction = _enclosingInteraction;
}

std::weak_ptr<uml::InteractionOperand > InteractionFragmentImpl::getEnclosingOperand() const
{

    return m_enclosingOperand;
}
void InteractionFragmentImpl::setEnclosingOperand(std::shared_ptr<uml::InteractionOperand> _enclosingOperand)
{
    m_enclosingOperand = _enclosingOperand;
}

std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element>> InteractionFragmentImpl::getGeneralOrdering() const
{

    return m_generalOrdering;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > InteractionFragmentImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> InteractionFragmentImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InteractionFragmentImpl::getOwner() const
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
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_COVERED:
			return eAny(getCovered()); //1219
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
			return eAny(getEnclosingInteraction()); //12111
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
			return eAny(getEnclosingOperand()); //12110
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_GENERALORDERING:
			return eAny(getGeneralOrdering()); //12112
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool InteractionFragmentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_COVERED:
			return getCovered() != nullptr; //1219
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
			return getEnclosingInteraction().lock() != nullptr; //12111
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
			return getEnclosingOperand().lock() != nullptr; //12110
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_GENERALORDERING:
			return getGeneralOrdering() != nullptr; //12112
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool InteractionFragmentImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _enclosingInteraction = newValue->get<std::shared_ptr<uml::Interaction>>();
			setEnclosingInteraction(_enclosingInteraction); //12111
			return true;
		}
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
		{
			// BOOST CAST
			std::shared_ptr<uml::InteractionOperand> _enclosingOperand = newValue->get<std::shared_ptr<uml::InteractionOperand>>();
			setEnclosingOperand(_enclosingOperand); //12110
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void InteractionFragmentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
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
			std::shared_ptr<uml::GeneralOrdering> generalOrdering = std::dynamic_pointer_cast<uml::GeneralOrdering>(modelFactory->create(typeName));
			if (generalOrdering != nullptr)
			{
				std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element>> list_generalOrdering = this->getGeneralOrdering();
				list_generalOrdering->push_back(generalOrdering);
				loadHandler->handleChild(generalOrdering);
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

	NamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void InteractionFragmentImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_COVERED:
		{
			std::shared_ptr<Bag<uml::Lifeline>> _covered = getCovered();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Lifeline> _r = std::dynamic_pointer_cast<uml::Lifeline>(ref);
				if (_r != nullptr)
				{
					_covered->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interaction> _enclosingInteraction = std::dynamic_pointer_cast<uml::Interaction>( references.front() );
				setEnclosingInteraction(_enclosingInteraction);
			}
			
			return;
		}

		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'generalOrdering'
		for (std::shared_ptr<uml::GeneralOrdering> generalOrdering : *this->getGeneralOrdering()) 
		{
			saveHandler->addReference(generalOrdering, "generalOrdering", generalOrdering->eClass() != package->getGeneralOrdering_EClass());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::Lifeline>> covered_list = this->getCovered();
		for (std::shared_ptr<uml::Lifeline > object : *covered_list)
		{ 
			saveHandler->addReferences("covered", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

