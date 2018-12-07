#include "uml/impl/LinkEndCreationDataImpl.hpp"

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
LinkEndCreationDataImpl::LinkEndCreationDataImpl()
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

LinkEndCreationDataImpl::~LinkEndCreationDataImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkEndCreationData "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			LinkEndCreationDataImpl::LinkEndCreationDataImpl(std::weak_ptr<uml::Element > par_owner)
			:LinkEndCreationDataImpl()
			{
			    m_owner = par_owner;
			}






LinkEndCreationDataImpl::LinkEndCreationDataImpl(const LinkEndCreationDataImpl & obj):LinkEndCreationDataImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkEndCreationData "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isReplaceAll = obj.getIsReplaceAll();

	//copy references with no containment (soft copy)
	
	m_end  = obj.getEnd();

	m_insertAt  = obj.getInsertAt();

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

std::shared_ptr<ecore::EObject>  LinkEndCreationDataImpl::copy() const
{
	std::shared_ptr<LinkEndCreationDataImpl> element(new LinkEndCreationDataImpl(*this));
	element->setThisLinkEndCreationDataPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LinkEndCreationDataImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLinkEndCreationData_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void LinkEndCreationDataImpl::setIsReplaceAll(bool _isReplaceAll)
{
	m_isReplaceAll = _isReplaceAll;
} 

bool LinkEndCreationDataImpl::getIsReplaceAll() const 
{
	return m_isReplaceAll;
}

//*********************************
// Operations
//*********************************
bool LinkEndCreationDataImpl::insertAt_pin(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::InputPin > LinkEndCreationDataImpl::getInsertAt() const
{

    return m_insertAt;
}
void LinkEndCreationDataImpl::setInsertAt(std::shared_ptr<uml::InputPin> _insertAt)
{
    m_insertAt = _insertAt;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> LinkEndCreationDataImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<LinkEndCreationData> LinkEndCreationDataImpl::getThisLinkEndCreationDataPtr() const
{
	return m_thisLinkEndCreationDataPtr.lock();
}
void LinkEndCreationDataImpl::setThisLinkEndCreationDataPtr(std::weak_ptr<LinkEndCreationData> thisLinkEndCreationDataPtr)
{
	m_thisLinkEndCreationDataPtr = thisLinkEndCreationDataPtr;
	setThisLinkEndDataPtr(thisLinkEndCreationDataPtr);
}
std::shared_ptr<ecore::EObject> LinkEndCreationDataImpl::eContainer() const
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
Any LinkEndCreationDataImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::LINKENDCREATIONDATA_EREFERENCE_INSERTAT:
			return eAny(getInsertAt()); //1347
		case UmlPackage::LINKENDCREATIONDATA_EATTRIBUTE_ISREPLACEALL:
			return eAny(getIsReplaceAll()); //1348
	}
	return LinkEndDataImpl::eGet(featureID, resolve, coreType);
}
bool LinkEndCreationDataImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::LINKENDCREATIONDATA_EREFERENCE_INSERTAT:
			return getInsertAt() != nullptr; //1347
		case UmlPackage::LINKENDCREATIONDATA_EATTRIBUTE_ISREPLACEALL:
			return getIsReplaceAll() != false; //1348
	}
	return LinkEndDataImpl::internalEIsSet(featureID);
}
bool LinkEndCreationDataImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::LINKENDCREATIONDATA_EREFERENCE_INSERTAT:
		{
			// BOOST CAST
			std::shared_ptr<uml::InputPin> _insertAt = newValue->get<std::shared_ptr<uml::InputPin>>();
			setInsertAt(_insertAt); //1347
			return true;
		}
		case UmlPackage::LINKENDCREATIONDATA_EATTRIBUTE_ISREPLACEALL:
		{
			// BOOST CAST
			bool _isReplaceAll = newValue->get<bool>();
			setIsReplaceAll(_isReplaceAll); //1348
			return true;
		}
	}

	return LinkEndDataImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LinkEndCreationDataImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LinkEndCreationDataImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isReplaceAll");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsReplaceAll(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("insertAt");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("insertAt")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void LinkEndCreationDataImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	LinkEndDataImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void LinkEndCreationDataImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::LINKENDCREATIONDATA_EREFERENCE_INSERTAT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InputPin> _insertAt = std::dynamic_pointer_cast<uml::InputPin>( references.front() );
				setInsertAt(_insertAt);
			}
			
			return;
		}
	}
	LinkEndDataImpl::resolveReferences(featureID, references);
}

void LinkEndCreationDataImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LinkEndDataImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void LinkEndCreationDataImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getLinkEndCreationData_EAttribute_isReplaceAll()) )
		{
			saveHandler->addAttribute("isReplaceAll", this->getIsReplaceAll());
		}

		// Add references
		saveHandler->addReference("insertAt", this->getInsertAt());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

