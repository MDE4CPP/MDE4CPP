#include "uml/impl/ConnectorEndImpl.hpp"

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

#include "uml/ConnectableElement.hpp"

#include "uml/Element.hpp"

#include "uml/MultiplicityElement.hpp"

#include "uml/Property.hpp"

#include "uml/ValueSpecification.hpp"

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
ConnectorEndImpl::ConnectorEndImpl()
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

ConnectorEndImpl::~ConnectorEndImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConnectorEnd "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ConnectorEndImpl::ConnectorEndImpl(std::weak_ptr<uml::Element > par_owner)
			:ConnectorEndImpl()
			{
			    m_owner = par_owner;
			}






ConnectorEndImpl::ConnectorEndImpl(const ConnectorEndImpl & obj):ConnectorEndImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConnectorEnd "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isOrdered = obj.getIsOrdered();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_upper = obj.getUpper();

	//copy references with no containment (soft copy)
	
	m_definingEnd  = obj.getDefiningEnd();

	m_owner  = obj.getOwner();

	m_partWithPort  = obj.getPartWithPort();

	m_role  = obj.getRole();


	//Clone references with containment (deep copy)

	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getLowerValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_lowerValue" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_upperValue" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ConnectorEndImpl::copy() const
{
	std::shared_ptr<ConnectorEndImpl> element(new ConnectorEndImpl(*this));
	element->setThisConnectorEndPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConnectorEndImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConnectorEnd_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************


bool ConnectorEndImpl::multiplicity(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorEndImpl::part_with_port_empty(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorEndImpl::role_and_part_with_port(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorEndImpl::self_part_with_port(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Property > ConnectorEndImpl::getDefiningEnd() const
{

    return m_definingEnd;
}


std::shared_ptr<uml::Property > ConnectorEndImpl::getPartWithPort() const
{

    return m_partWithPort;
}
void ConnectorEndImpl::setPartWithPort(std::shared_ptr<uml::Property> _partWithPort)
{
    m_partWithPort = _partWithPort;
}

std::shared_ptr<uml::ConnectableElement > ConnectorEndImpl::getRole() const
{
//assert(m_role);
    return m_role;
}
void ConnectorEndImpl::setRole(std::shared_ptr<uml::ConnectableElement> _role)
{
    m_role = _role;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ConnectorEndImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<ConnectorEnd> ConnectorEndImpl::getThisConnectorEndPtr() const
{
	return m_thisConnectorEndPtr.lock();
}
void ConnectorEndImpl::setThisConnectorEndPtr(std::weak_ptr<ConnectorEnd> thisConnectorEndPtr)
{
	m_thisConnectorEndPtr = thisConnectorEndPtr;
	setThisMultiplicityElementPtr(thisConnectorEndPtr);
}
std::shared_ptr<ecore::EObject> ConnectorEndImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ConnectorEndImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CONNECTOREND_ATTRIBUTE_DEFININGEND:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getDefiningEnd())); //559
		case UmlPackage::CONNECTOREND_ATTRIBUTE_PARTWITHPORT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getPartWithPort())); //5510
		case UmlPackage::CONNECTOREND_ATTRIBUTE_ROLE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getRole())); //5511
	}
	return MultiplicityElementImpl::eGet(featureID, resolve, coreType);
}
bool ConnectorEndImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::CONNECTOREND_ATTRIBUTE_DEFININGEND:
			return getDefiningEnd() != nullptr; //559
		case UmlPackage::CONNECTOREND_ATTRIBUTE_PARTWITHPORT:
			return getPartWithPort() != nullptr; //5510
		case UmlPackage::CONNECTOREND_ATTRIBUTE_ROLE:
			return getRole() != nullptr; //5511
	}
	return MultiplicityElementImpl::internalEIsSet(featureID);
}
bool ConnectorEndImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::CONNECTOREND_ATTRIBUTE_PARTWITHPORT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Property> _partWithPort = std::dynamic_pointer_cast<uml::Property>(_temp);
			setPartWithPort(_partWithPort); //5510
			return true;
		}
		case UmlPackage::CONNECTOREND_ATTRIBUTE_ROLE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ConnectableElement> _role = std::dynamic_pointer_cast<uml::ConnectableElement>(_temp);
			setRole(_role); //5511
			return true;
		}
	}

	return MultiplicityElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ConnectorEndImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConnectorEndImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("partWithPort");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("partWithPort")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("role");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("role")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	MultiplicityElementImpl::loadAttributes(loadHandler, attr_list);
}

void ConnectorEndImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	MultiplicityElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ConnectorEndImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::CONNECTOREND_ATTRIBUTE_PARTWITHPORT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _partWithPort = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setPartWithPort(_partWithPort);
			}
			
			return;
		}

		case UmlPackage::CONNECTOREND_ATTRIBUTE_ROLE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ConnectableElement> _role = std::dynamic_pointer_cast<uml::ConnectableElement>( references.front() );
				setRole(_role);
			}
			
			return;
		}
	}
	MultiplicityElementImpl::resolveReferences(featureID, references);
}

void ConnectorEndImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	MultiplicityElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ConnectorEndImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		saveHandler->addReference("partWithPort", this->getPartWithPort());
		saveHandler->addReference("role", this->getRole());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

