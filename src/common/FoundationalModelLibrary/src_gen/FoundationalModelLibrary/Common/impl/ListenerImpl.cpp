#include "FoundationalModelLibrary/Common/impl/ListenerImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

//General includes
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "util/util.hpp"
#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"
#include "uml/Property.hpp"
#include "uml/Operation.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "uml/FunctionBehavior.hpp"
#include "uml/Parameter.hpp"
#include "FoundationalModelLibrary/Common/CommonFactory.hpp"
#include "FoundationalModelLibrary/Common/impl/CommonPackageImpl.hpp"
#include "uml/Class.hpp"
//PSCS-specific includes
#include "fUML/Semantics/Loci/Locus.hpp"
#include "PSCS/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "PSCS/MDE4CPP_Extensions/PSCS_Link.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_LinkKind.hpp"
#include "uml/Port.hpp"

using namespace FoundationalModelLibrary::Common;

//*********************************
// Constructor / Destructor
//*********************************
ListenerImpl::ListenerImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'Listener' is created.")
	//***********************************
}

ListenerImpl::~ListenerImpl()
{
	DEBUG_INFO("Instance of 'Listener' is destroyed.")
}

ListenerImpl::ListenerImpl(const ListenerImpl & obj):ListenerImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  ListenerImpl::copy() const
{
	std::shared_ptr<ListenerImpl> element(new ListenerImpl());
	*element=(*this);
	element->setThisListenerPtr(element);
	return element;
}

ListenerImpl& ListenerImpl::operator=(const ListenerImpl & obj)
{
	//call overloaded =Operator for each base class
	PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Listener "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy attributes with no containment (soft copy)

	//clone attributes with containment (deep copy)

	return *this;
}

const std::shared_ptr<uml::Class>& ListenerImpl::getMetaClass() const
{
	return CommonPackageImpl::eInstance()->get_FoundationalModelLibrary_Common_Listener();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Union Getter
//*********************************



//*********************************
// Operations
//*********************************

// fUML-specific Method Overrides
const std::shared_ptr<Bag<uml::Classifier>>& ListenerImpl::getTypes() const
{
	static std::shared_ptr<Bag<uml::Classifier>> types;

	if(!types)
	{
		types.reset(new Bag<uml::Classifier>());
		// Add type of self 'Listener' : Class
		types->add(FoundationalModelLibrary::Common::CommonPackage::eInstance()->get_FoundationalModelLibrary_Common_Listener());
	}

	return types;
}

void ListenerImpl::destroy(bool isDestroyLinks, bool isDestroyOwnedObjects)
{
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::destroy(isDestroyLinks, isDestroyOwnedObjects);
}

// PSCS-specific Method Overrides
void ListenerImpl::construct()
{
}

void ListenerImpl::constructObject(const std::shared_ptr<uml::Class>& type)
{
	switch(type->_getID())
	{
		case FoundationalModelLibrary::Common::CommonPackage::LISTENER_CLASS:
		{
			this->construct();
			break;
		}
		default:
		{
			return;
		}
	}
}

bool ListenerImpl::contains(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& object)
{
	/*
	 * TODO Avoid cycles here
	 */ 
	return false;
}

bool ListenerImpl::directlyContains(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& object)
{
	return false;
}

std::shared_ptr<Any> ListenerImpl::dispatchCallInByPort(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<uml::Port>& onPort, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return nullptr;
}

std::shared_ptr<Any> ListenerImpl::dispatchCallInOnInteractionPoint(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object>& interactionPoint, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	if(interactionPoint->getDefiningPort()->getIsBehavior())
	{
		return this->dispatchCall(_operation, inputArguments, outputArguments);
	}
	else
	{
		std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Object>> potentialTargets(new Bag<fUML::MDE4CPP_Extensions::FUML_Object>);
		const std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Link>>& allLinks = interactionPoint->getLinks();
		
		for(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link>& link : *allLinks)
		{
			std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Link> cS_Link = std::dynamic_pointer_cast<PSCS::MDE4CPP_Extensions::PSCS_Link>(link);
			PSCS::Semantics::StructuredClassifiers::CS_LinkKind linkKind = cS_Link->retrieveLinkKind(interactionPoint);
			if(linkKind == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::UNKNOWN)
			{
				// LinkKind has to be calculated
				linkKind = this->retrieveLinkKind(cS_Link, interactionPoint);
				cS_Link->assignLinkKind(interactionPoint, linkKind);
			}
			if(linkKind == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::TOINTERNAL)
			{
				potentialTargets->add(cS_Link->retrieveOtherLinkEndValue(interactionPoint->getDefiningPort()));
			}
		}
		if(!(potentialTargets->size() == 0))
		{
			const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& target = potentialTargets->at(0); // TODO RequestPropagationStrategy should be invoked here
			return target->dispatchCall(_operation, inputArguments, outputArguments);
		}
		
		return nullptr;
	}
}

std::shared_ptr<Any> ListenerImpl::dispatchCallOutByPort(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<uml::Port>& onPort, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return nullptr;
}

std::shared_ptr<Any> ListenerImpl::dispatchCallOutOnInteractionPoint(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object>& interactionPoint, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Object>> targetsForDispatchingIn(new Bag<fUML::MDE4CPP_Extensions::FUML_Object>());
	std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Object>> targetsForDispatchingOut(new Bag<fUML::MDE4CPP_Extensions::FUML_Object>());
	
	const std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Link>>& allLinks = interactionPoint->getLinks();
	for(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link>& link : *allLinks)
	{
		std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Link> cS_Link = std::dynamic_pointer_cast<PSCS::MDE4CPP_Extensions::PSCS_Link>(link);
		PSCS::Semantics::StructuredClassifiers::CS_LinkKind linkKind = cS_Link->retrieveLinkKind(interactionPoint);
		if(linkKind == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::UNKNOWN)
		{
			// LinkKind has to be calculated
			linkKind = this->retrieveLinkKind(cS_Link, interactionPoint);
			cS_Link->assignLinkKind(interactionPoint, linkKind);
		}
		if(linkKind == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::TOENVIRONMENT)
		{
			std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> otherEndValue = cS_Link->retrieveOtherLinkEndValue(interactionPoint->getDefiningPort());
			std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> cS_Object = std::dynamic_pointer_cast<PSCS::MDE4CPP_Extensions::PSCS_Object>(otherEndValue);

			if(!(cS_Object->isInteractionPoint()))
			{
				if(PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl::isOperationProvided(cS_Object, _operation))
				{
					targetsForDispatchingIn->add(cS_Object);
				}
			}
			else
			{
				bool isAssembly = true, isDelegation = false;
				
				switch(cS_Object->getDefiningPort()->_getID())
				{
				}
				
				if(isAssembly)
				{
					if(PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl::isOperationProvided(cS_Object, _operation))
					{
						targetsForDispatchingIn->add(cS_Object);
					}
				}
				if(isDelegation)
				{
					if(PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl::isOperationRequired(cS_Object, _operation))
					{
						targetsForDispatchingOut->add(cS_Object);
					}
				}
			}
		}
	}

	unsigned int numOfTargetsToDispatchInTo = targetsForDispatchingIn->size();
	unsigned int numOfTargetsToDispatchOutTo = targetsForDispatchingOut->size();

	std::shared_ptr<Any> result = nullptr;
	
	for(unsigned int i = 0; i < numOfTargetsToDispatchInTo && result == nullptr; i++)
	{
		result = targetsForDispatchingIn->at(i)->dispatchCall(_operation, inputArguments, outputArguments);
	}
	for(unsigned int i = 0; i < numOfTargetsToDispatchOutTo && result == nullptr; i++)
	{
		std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> cS_Object = std::dynamic_pointer_cast<PSCS::MDE4CPP_Extensions::PSCS_Object>(targetsForDispatchingOut->at(i));
		if(cS_Object->isInteractionPoint())
		{
			std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> compositeOwner = cS_Object->getCompositeOwner();
			result = compositeOwner->dispatchCallOutOnInteractionPoint(_operation, cS_Object, inputArguments, outputArguments);
		}
	}
	
	return result;
}

std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> ListenerImpl::getCompositeOwner()
{
	std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> compositeOwner = nullptr;

	return nullptr;
}

bool ListenerImpl::isOperationProvided(const std::shared_ptr<uml::Operation>& operation)
{
	bool isProvided = false;
	if(this->isInteractionPoint()) // For interaction points, only realized interfaces are taken into account
	{
	}
	else
	{
		throw std::runtime_error("Now we are here...: " + std::string(__PRETTY_FUNCTION__));
	}
	return isProvided;
}

bool ListenerImpl::isOperationRequired(const std::shared_ptr<uml::Operation>& operation)
{
	bool isRequired = false;
	return isRequired;
}
//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> ListenerImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> ListenerImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> ListenerImpl::get(unsigned long _uID) const
{
	return nullptr;
}

//Set
bool ListenerImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool ListenerImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool ListenerImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	return false;
}

//Add
bool ListenerImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool ListenerImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool ListenerImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return false;
}

//Unset
bool ListenerImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool ListenerImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool ListenerImpl::unset(unsigned long _uID)
{
	return false;
}

//Remove
std::shared_ptr<Any> ListenerImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt, isRemoveDuplicates);
}

std::shared_ptr<Any> ListenerImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt, isRemoveDuplicates);
}

std::shared_ptr<Any> ListenerImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	std::shared_ptr<Any> removedValue = nullptr;
	return removedValue;
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> ListenerImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOperation(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> ListenerImpl::invokeOperation(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOperation(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> ListenerImpl::invokeOperation(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = nullptr;
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> ListenerImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOpaqueBehavior(_opaqueBehavior->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> ListenerImpl::invokeOpaqueBehavior(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOpaqueBehavior(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> ListenerImpl::invokeOpaqueBehavior(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return nullptr;
}

std::shared_ptr<Listener> ListenerImpl::getThisListenerPtr()
{
	return m_thisListenerPtr.lock();
}
void ListenerImpl::setThisListenerPtr(std::weak_ptr<Listener> thisListenerPtr)
{
	m_thisListenerPtr = thisListenerPtr;
	setThisPSCS_ObjectPtr(thisListenerPtr);
}
