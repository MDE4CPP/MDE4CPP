#include "uml/impl/ProtocolConformanceImpl.hpp"

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

#include "uml/DirectedRelationship.hpp"

#include "uml/Element.hpp"

#include "uml/ProtocolStateMachine.hpp"

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
ProtocolConformanceImpl::ProtocolConformanceImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	//Init references
	

	
}

ProtocolConformanceImpl::~ProtocolConformanceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProtocolConformance "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ProtocolConformanceImpl::ProtocolConformanceImpl(std::weak_ptr<uml::Element > par_owner)
			:ProtocolConformanceImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ProtocolConformanceImpl::ProtocolConformanceImpl(std::weak_ptr<uml::ProtocolStateMachine > par_specificMachine)
			:ProtocolConformanceImpl()
			{
			    m_specificMachine = par_specificMachine;
				m_owner = par_specificMachine;
			}






ProtocolConformanceImpl::ProtocolConformanceImpl(const ProtocolConformanceImpl & obj):ProtocolConformanceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ProtocolConformance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element>> _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_specificMachine  = obj.getSpecificMachine();


	//Clone references with containment (deep copy)

	if(obj.getGeneralMachine()!=nullptr)
	{
		m_generalMachine = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(obj.getGeneralMachine()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalMachine" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ProtocolConformanceImpl::copy() const
{
	std::shared_ptr<ProtocolConformanceImpl> element(new ProtocolConformanceImpl(*this));
	element->setThisProtocolConformancePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ProtocolConformanceImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProtocolConformance_EClass();
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
std::shared_ptr<uml::ProtocolStateMachine > ProtocolConformanceImpl::getGeneralMachine() const
{
//assert(m_generalMachine);
    return m_generalMachine;
}
void ProtocolConformanceImpl::setGeneralMachine(std::shared_ptr<uml::ProtocolStateMachine> _generalMachine)
{
    m_generalMachine = _generalMachine;
}

std::weak_ptr<uml::ProtocolStateMachine > ProtocolConformanceImpl::getSpecificMachine() const
{
//assert(m_specificMachine);
    return m_specificMachine;
}
void ProtocolConformanceImpl::setSpecificMachine(std::shared_ptr<uml::ProtocolStateMachine> _specificMachine)
{
    m_specificMachine = _specificMachine;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ProtocolConformanceImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ProtocolConformanceImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element>> ProtocolConformanceImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ProtocolConformanceImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ProtocolConformanceImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ProtocolConformance> ProtocolConformanceImpl::getThisProtocolConformancePtr() const
{
	return m_thisProtocolConformancePtr.lock();
}
void ProtocolConformanceImpl::setThisProtocolConformancePtr(std::weak_ptr<ProtocolConformance> thisProtocolConformancePtr)
{
	m_thisProtocolConformancePtr = thisProtocolConformancePtr;
	setThisDirectedRelationshipPtr(thisProtocolConformancePtr);
}
std::shared_ptr<ecore::EObject> ProtocolConformanceImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_specificMachine.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ProtocolConformanceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PROTOCOLCONFORMANCE_EREFERENCE_GENERALMACHINE:
			return eAny(getGeneralMachine()); //1866
		case UmlPackage::PROTOCOLCONFORMANCE_EREFERENCE_SPECIFICMACHINE:
			return eAny(getSpecificMachine()); //1867
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}
bool ProtocolConformanceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::PROTOCOLCONFORMANCE_EREFERENCE_GENERALMACHINE:
			return getGeneralMachine() != nullptr; //1866
		case UmlPackage::PROTOCOLCONFORMANCE_EREFERENCE_SPECIFICMACHINE:
			return getSpecificMachine().lock() != nullptr; //1867
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}
bool ProtocolConformanceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::PROTOCOLCONFORMANCE_EREFERENCE_GENERALMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ProtocolStateMachine> _generalMachine = newValue->get<std::shared_ptr<uml::ProtocolStateMachine>>();
			setGeneralMachine(_generalMachine); //1866
			return true;
		}
		case UmlPackage::PROTOCOLCONFORMANCE_EREFERENCE_SPECIFICMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ProtocolStateMachine> _specificMachine = newValue->get<std::shared_ptr<uml::ProtocolStateMachine>>();
			setSpecificMachine(_specificMachine); //1867
			return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ProtocolConformanceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ProtocolConformanceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("generalMachine");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("generalMachine")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DirectedRelationshipImpl::loadAttributes(loadHandler, attr_list);
}

void ProtocolConformanceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	DirectedRelationshipImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ProtocolConformanceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::PROTOCOLCONFORMANCE_EREFERENCE_GENERALMACHINE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ProtocolStateMachine> _generalMachine = std::dynamic_pointer_cast<uml::ProtocolStateMachine>( references.front() );
				setGeneralMachine(_generalMachine);
			}
			
			return;
		}

		case UmlPackage::PROTOCOLCONFORMANCE_EREFERENCE_SPECIFICMACHINE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ProtocolStateMachine> _specificMachine = std::dynamic_pointer_cast<uml::ProtocolStateMachine>( references.front() );
				setSpecificMachine(_specificMachine);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
}

void ProtocolConformanceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ProtocolConformanceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		saveHandler->addReference("generalMachine", this->getGeneralMachine());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

