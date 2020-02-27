#include "uml/impl/ProfileApplicationImpl.hpp"

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

#include "uml/DirectedRelationship.hpp"

#include "ecore/ENamedElement.hpp"

#include "ecore/EPackage.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Package.hpp"

#include "uml/Profile.hpp"

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProfileApplicationImpl::ProfileApplicationImpl()
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

ProfileApplicationImpl::~ProfileApplicationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProfileApplication "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ProfileApplicationImpl::ProfileApplicationImpl(std::weak_ptr<uml::Package > par_applyingPackage)
			:ProfileApplicationImpl()
			{
			    m_applyingPackage = par_applyingPackage;
				m_owner = par_applyingPackage;
			}


//Additional constructor for the containments back reference
			ProfileApplicationImpl::ProfileApplicationImpl(std::weak_ptr<uml::Element > par_owner)
			:ProfileApplicationImpl()
			{
			    m_owner = par_owner;
			}



ProfileApplicationImpl::ProfileApplicationImpl(const ProfileApplicationImpl & obj):ProfileApplicationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ProfileApplication "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isStrict = obj.getIsStrict();

	//copy references with no containment (soft copy)
	
	m_applyingPackage  = obj.getApplyingPackage();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element>> _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));


	//Clone references with containment (deep copy)

	if(obj.getAppliedProfile()!=nullptr)
	{
		m_appliedProfile = std::dynamic_pointer_cast<uml::Profile>(obj.getAppliedProfile()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_appliedProfile" << std::endl;
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

std::shared_ptr<ecore::EObject>  ProfileApplicationImpl::copy() const
{
	std::shared_ptr<ProfileApplicationImpl> element(new ProfileApplicationImpl(*this));
	element->setThisProfileApplicationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ProfileApplicationImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getProfileApplication_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ProfileApplicationImpl::setIsStrict(bool _isStrict)
{
	m_isStrict = _isStrict;
} 

bool ProfileApplicationImpl::getIsStrict() const 
{
	return m_isStrict;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EPackage> ProfileApplicationImpl::getAppliedDefinition()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::ENamedElement> ProfileApplicationImpl::getAppliedDefinition(std::shared_ptr<uml::NamedElement>  namedElement)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Profile > ProfileApplicationImpl::getAppliedProfile() const
{
//assert(m_appliedProfile);
    return m_appliedProfile;
}
void ProfileApplicationImpl::setAppliedProfile(std::shared_ptr<uml::Profile> _appliedProfile)
{
    m_appliedProfile = _appliedProfile;
}

std::weak_ptr<uml::Package > ProfileApplicationImpl::getApplyingPackage() const
{
//assert(m_applyingPackage);
    return m_applyingPackage;
}
void ProfileApplicationImpl::setApplyingPackage(std::shared_ptr<uml::Package> _applyingPackage)
{
    m_applyingPackage = _applyingPackage;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ProfileApplicationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ProfileApplicationImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element>> ProfileApplicationImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ProfileApplicationImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ProfileApplicationImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ProfileApplication> ProfileApplicationImpl::getThisProfileApplicationPtr() const
{
	return m_thisProfileApplicationPtr.lock();
}
void ProfileApplicationImpl::setThisProfileApplicationPtr(std::weak_ptr<ProfileApplication> thisProfileApplicationPtr)
{
	m_thisProfileApplicationPtr = thisProfileApplicationPtr;
	setThisDirectedRelationshipPtr(thisProfileApplicationPtr);
}
std::shared_ptr<ecore::EObject> ProfileApplicationImpl::eContainer() const
{
	if(auto wp = m_applyingPackage.lock())
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
Any ProfileApplicationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLIEDPROFILE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getAppliedProfile())); //1856
		case uml::UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getApplyingPackage().lock())); //1858
		case uml::UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_ISSTRICT:
			return eAny(getIsStrict()); //1857
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}
bool ProfileApplicationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLIEDPROFILE:
			return getAppliedProfile() != nullptr; //1856
		case uml::UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE:
			return getApplyingPackage().lock() != nullptr; //1858
		case uml::UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_ISSTRICT:
			return getIsStrict() != false; //1857
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}
bool ProfileApplicationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLIEDPROFILE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Profile> _appliedProfile = std::dynamic_pointer_cast<uml::Profile>(_temp);
			setAppliedProfile(_appliedProfile); //1856
			return true;
		}
		case uml::UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Package> _applyingPackage = std::dynamic_pointer_cast<uml::Package>(_temp);
			setApplyingPackage(_applyingPackage); //1858
			return true;
		}
		case uml::UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_ISSTRICT:
		{
			// BOOST CAST
			bool _isStrict = newValue->get<bool>();
			setIsStrict(_isStrict); //1857
			return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ProfileApplicationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ProfileApplicationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isStrict");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsStrict(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("appliedProfile");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("appliedProfile")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ProfileApplicationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
}

void ProfileApplicationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLIEDPROFILE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Profile> _appliedProfile = std::dynamic_pointer_cast<uml::Profile>( references.front() );
				setAppliedProfile(_appliedProfile);
			}
			
			return;
		}

		case uml::UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Package> _applyingPackage = std::dynamic_pointer_cast<uml::Package>( references.front() );
				setApplyingPackage(_applyingPackage);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
}

void ProfileApplicationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ProfileApplicationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getProfileApplication_Attribute_isStrict()) )
		{
			saveHandler->addAttribute("isStrict", this->getIsStrict());
		}

		// Add references
		saveHandler->addReference("appliedProfile", this->getAppliedProfile());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

