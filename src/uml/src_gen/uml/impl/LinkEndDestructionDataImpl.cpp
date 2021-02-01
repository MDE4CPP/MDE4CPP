#include "uml/impl/LinkEndDestructionDataImpl.hpp"

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

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/InputPin.hpp"
#include "uml/LinkEndData.hpp"
#include "uml/Property.hpp"
#include "uml/QualifierValue.hpp"

//Factories an Package includes
#include "uml/impl/umlFactoryImpl.hpp"
#include "uml/impl/umlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LinkEndDestructionDataImpl::LinkEndDestructionDataImpl()
{	
}

LinkEndDestructionDataImpl::~LinkEndDestructionDataImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkEndDestructionData "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LinkEndDestructionDataImpl::LinkEndDestructionDataImpl(std::weak_ptr<uml::Element > par_owner)
:LinkEndDestructionDataImpl()
{
	m_owner = par_owner;
}


LinkEndDestructionDataImpl::LinkEndDestructionDataImpl(const LinkEndDestructionDataImpl & obj):LinkEndDestructionDataImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkEndDestructionData "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isDestroyDuplicates = obj.getIsDestroyDuplicates();

	//copy references with no containment (soft copy)
	
	m_destroyAt  = obj.getDestroyAt();

	m_end  = obj.getEnd();

	m_owner  = obj.getOwner();

	m_value  = obj.getValue();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::QualifierValue>> _qualifierList = obj.getQualifier();
	for(std::shared_ptr<uml::QualifierValue> _qualifier : *_qualifierList)
	{
		this->getQualifier()->add(std::shared_ptr<uml::QualifierValue>(std::dynamic_pointer_cast<uml::QualifierValue>(_qualifier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_qualifier" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  LinkEndDestructionDataImpl::copy() const
{
	std::shared_ptr<LinkEndDestructionDataImpl> element(new LinkEndDestructionDataImpl(*this));
	element->setThisLinkEndDestructionDataPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LinkEndDestructionDataImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLinkEndDestructionData_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isDestroyDuplicates
*/
bool LinkEndDestructionDataImpl::getIsDestroyDuplicates() const 
{
	return m_isDestroyDuplicates;
}

void LinkEndDestructionDataImpl::setIsDestroyDuplicates(bool _isDestroyDuplicates)
{
	m_isDestroyDuplicates = _isDestroyDuplicates;
} 



//*********************************
// Operations
//*********************************
bool LinkEndDestructionDataImpl::destroyAt_pin(Any diagnostics,std::map <  Any ,  Any > context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference destroyAt
*/
std::shared_ptr<uml::InputPin > LinkEndDestructionDataImpl::getDestroyAt() const
{

    return m_destroyAt;
}

void LinkEndDestructionDataImpl::setDestroyAt(std::shared_ptr<uml::InputPin> _destroyAt)
{
    m_destroyAt = _destroyAt;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> LinkEndDestructionDataImpl::getOwnedElement() const
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




std::shared_ptr<LinkEndDestructionData> LinkEndDestructionDataImpl::getThisLinkEndDestructionDataPtr() const
{
	return m_thisLinkEndDestructionDataPtr.lock();
}
void LinkEndDestructionDataImpl::setThisLinkEndDestructionDataPtr(std::weak_ptr<LinkEndDestructionData> thisLinkEndDestructionDataPtr)
{
	m_thisLinkEndDestructionDataPtr = thisLinkEndDestructionDataPtr;
	setThisLinkEndDataPtr(thisLinkEndDestructionDataPtr);
}
std::shared_ptr<ecore::EObject> LinkEndDestructionDataImpl::eContainer() const
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
Any LinkEndDestructionDataImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_DESTROYAT:
			return eAny(getDestroyAt()); //1366
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_ISDESTROYDUPLICATES:
			return eAny(getIsDestroyDuplicates()); //1367
	}
	return LinkEndDataImpl::eGet(featureID, resolve, coreType);
}
bool LinkEndDestructionDataImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_DESTROYAT:
			return getDestroyAt() != nullptr; //1366
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_ISDESTROYDUPLICATES:
			return getIsDestroyDuplicates() != false; //1367
	}
	return LinkEndDataImpl::internalEIsSet(featureID);
}
bool LinkEndDestructionDataImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_DESTROYAT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _destroyAt = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setDestroyAt(_destroyAt); //1366
			return true;
		}
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_ISDESTROYDUPLICATES:
		{
			// BOOST CAST
			bool _isDestroyDuplicates = newValue->get<bool>();
			setIsDestroyDuplicates(_isDestroyDuplicates); //1367
			return true;
		}
	}

	return LinkEndDataImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LinkEndDestructionDataImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LinkEndDestructionDataImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isDestroyDuplicates");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsDestroyDuplicates(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("destroyAt");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("destroyAt")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	LinkEndDataImpl::loadAttributes(loadHandler, attr_list);
}

void LinkEndDestructionDataImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::umlFactory> modelFactory=uml::umlFactory::eInstance();

	//load BasePackage Nodes
	LinkEndDataImpl::loadNode(nodeName, loadHandler);
}

void LinkEndDestructionDataImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_DESTROYAT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InputPin> _destroyAt = std::dynamic_pointer_cast<uml::InputPin>( references.front() );
				setDestroyAt(_destroyAt);
			}
			
			return;
		}
	}
	LinkEndDataImpl::resolveReferences(featureID, references);
}

void LinkEndDestructionDataImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LinkEndDataImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void LinkEndDestructionDataImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getLinkEndDestructionData_Attribute_isDestroyDuplicates()) )
		{
			saveHandler->addAttribute("isDestroyDuplicates", this->getIsDestroyDuplicates());
		}

	// Add references
		saveHandler->addReference("destroyAt", this->getDestroyAt()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

