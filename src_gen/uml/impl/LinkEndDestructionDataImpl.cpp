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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "boost/any.hpp"
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

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/InputPin.hpp"

#include "uml/LinkEndData.hpp"

#include "uml/Property.hpp"

#include "uml/QualifierValue.hpp"

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
LinkEndDestructionDataImpl::LinkEndDestructionDataImpl()
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

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
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
	return UmlPackageImpl::eInstance()->getLinkEndDestructionData_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void LinkEndDestructionDataImpl::setIsDestroyDuplicates(bool _isDestroyDuplicates)
{
	m_isDestroyDuplicates = _isDestroyDuplicates;
} 

bool LinkEndDestructionDataImpl::getIsDestroyDuplicates() const 
{
	return m_isDestroyDuplicates;
}

//*********************************
// Operations
//*********************************
bool LinkEndDestructionDataImpl::destroyAt_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
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
	return m_ownedElement;
}


std::shared_ptr<LinkEndDestructionData> LinkEndDestructionDataImpl::getThisLinkEndDestructionDataPtr()
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
boost::any LinkEndDestructionDataImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDESTRUCTIONDATA_EREFERENCE_DESTROYAT:
			return getDestroyAt(); //1527
		case UmlPackage::LINKENDDESTRUCTIONDATA_EATTRIBUTE_ISDESTROYDUPLICATES:
			return getIsDestroyDuplicates(); //1528
	}
	return LinkEndDataImpl::internalEIsSet(featureID);
}
bool LinkEndDestructionDataImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDESTRUCTIONDATA_EREFERENCE_DESTROYAT:
			return getDestroyAt() != nullptr; //1527
		case UmlPackage::LINKENDDESTRUCTIONDATA_EATTRIBUTE_ISDESTROYDUPLICATES:
			return getIsDestroyDuplicates() != false; //1528
	}
	return LinkEndDataImpl::internalEIsSet(featureID);
}
bool LinkEndDestructionDataImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDESTRUCTIONDATA_EREFERENCE_DESTROYAT:
		{
			// BOOST CAST
			std::shared_ptr<uml::InputPin> _destroyAt = boost::any_cast<std::shared_ptr<uml::InputPin>>(newValue);
			setDestroyAt(_destroyAt); //1527
			return true;
		}
		case UmlPackage::LINKENDDESTRUCTIONDATA_EATTRIBUTE_ISDESTROYDUPLICATES:
		{
			// BOOST CAST
			bool _isDestroyDuplicates = boost::any_cast<bool>(newValue);
			setIsDestroyDuplicates(_isDestroyDuplicates); //1528
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void LinkEndDestructionDataImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	LinkEndDataImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void LinkEndDestructionDataImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDESTRUCTIONDATA_EREFERENCE_DESTROYAT:
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
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void LinkEndDestructionDataImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getLinkEndDestructionData_EAttribute_isDestroyDuplicates()) )
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

