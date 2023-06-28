
#include "uml/impl/PackageMergeImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/Package.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PackageMergeImpl::PackageMergeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PackageMergeImpl::~PackageMergeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PackageMerge "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PackageMergeImpl::PackageMergeImpl(std::weak_ptr<uml::Element> par_owner)
:PackageMergeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
PackageMergeImpl::PackageMergeImpl(std::weak_ptr<uml::Package> par_receivingPackage)
:PackageMergeImpl()
{
	m_receivingPackage = par_receivingPackage;
	m_owner = par_receivingPackage;
}

PackageMergeImpl::PackageMergeImpl(const PackageMergeImpl & obj): PackageMergeImpl()
{
	*this = obj;
}

PackageMergeImpl& PackageMergeImpl::operator=(const PackageMergeImpl & obj)
{
	//call overloaded =Operator for each base class
	DirectedRelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PackageMerge 
	 * which is generated by the compiler (as PackageMerge is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PackageMerge::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PackageMerge "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_receivingPackage  = obj.getReceivingPackage();
	//Clone references with containment (deep copy)
	//clone reference 'mergedPackage'
	if(obj.getMergedPackage()!=nullptr)
	{
		m_mergedPackage = std::dynamic_pointer_cast<uml::Package>(obj.getMergedPackage()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> PackageMergeImpl::copy() const
{
	std::shared_ptr<PackageMergeImpl> element(new PackageMergeImpl());
	*element =(*this);
	element->setThisPackageMergePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference mergedPackage */
const std::shared_ptr<uml::Package>& PackageMergeImpl::getMergedPackage() const
{
    return m_mergedPackage;
}
void PackageMergeImpl::setMergedPackage(const std::shared_ptr<uml::Package>& _mergedPackage)
{
    m_mergedPackage = _mergedPackage;
	
}

/* Getter & Setter for reference receivingPackage */
std::weak_ptr<uml::Package> PackageMergeImpl::getReceivingPackage() const
{
    return m_receivingPackage;
}
void PackageMergeImpl::setReceivingPackage(std::weak_ptr<uml::Package> _receivingPackage)
{
    m_receivingPackage = _receivingPackage;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PackageMergeImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_receivingPackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void PackageMergeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PackageMergeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("mergedPackage");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("mergedPackage")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void PackageMergeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
}

void PackageMergeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEMERGE_ATTRIBUTE_MERGEDPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Package> _mergedPackage = std::dynamic_pointer_cast<uml::Package>( references.front() );
				setMergedPackage(_mergedPackage);
			}
			
			return;
		}

		case uml::umlPackage::PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Package> _receivingPackage = std::dynamic_pointer_cast<uml::Package>( references.front() );
				setReceivingPackage(_receivingPackage);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
}

void PackageMergeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PackageMergeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getMergedPackage(), "mergedPackage", getMergedPackage()->eClass() != uml::umlPackage::eInstance()->getPackage_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> PackageMergeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getPackageMerge_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PackageMergeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEMERGE_ATTRIBUTE_MERGEDPACKAGE:
			return eAny(getMergedPackage(),uml::umlPackage::PACKAGE_CLASS,false); //1726
		case uml::umlPackage::PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getReceivingPackage().lock();
			return eEcoreAny(returnValue,uml::umlPackage::PACKAGE_CLASS); //1727
		}
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}

bool PackageMergeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEMERGE_ATTRIBUTE_MERGEDPACKAGE:
			return getMergedPackage() != nullptr; //1726
		case uml::umlPackage::PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE:
			return getReceivingPackage().lock() != nullptr; //1727
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}

bool PackageMergeImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEMERGE_ATTRIBUTE_MERGEDPACKAGE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Package> _mergedPackage = std::dynamic_pointer_cast<uml::Package>(eObject);
					if(_mergedPackage)
					{
						setMergedPackage(_mergedPackage); //1726
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'mergedPackage'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'mergedPackage'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Package> _receivingPackage = std::dynamic_pointer_cast<uml::Package>(eObject);
					if(_receivingPackage)
					{
						setReceivingPackage(_receivingPackage); //1727
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'receivingPackage'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'receivingPackage'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> PackageMergeImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::PackageMerge> PackageMergeImpl::getThisPackageMergePtr() const
{
	return m_thisPackageMergePtr.lock();
}
void PackageMergeImpl::setThisPackageMergePtr(std::weak_ptr<uml::PackageMerge> thisPackageMergePtr)
{
	m_thisPackageMergePtr = thisPackageMergePtr;
	setThisDirectedRelationshipPtr(thisPackageMergePtr);
}


