#include "uml/impl/PackageMergeImpl.hpp"

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

#include "uml/DirectedRelationship.hpp"

#include "uml/Element.hpp"

#include "uml/Package.hpp"

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
PackageMergeImpl::PackageMergeImpl()
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

PackageMergeImpl::~PackageMergeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PackageMerge "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			PackageMergeImpl::PackageMergeImpl(std::weak_ptr<uml::Element > par_owner)
			:PackageMergeImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			PackageMergeImpl::PackageMergeImpl(std::weak_ptr<uml::Package > par_receivingPackage)
			:PackageMergeImpl()
			{
			    m_receivingPackage = par_receivingPackage;
				m_owner = par_receivingPackage;
			}






PackageMergeImpl::PackageMergeImpl(const PackageMergeImpl & obj):PackageMergeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PackageMerge "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();

	m_receivingPackage  = obj.getReceivingPackage();

	std::shared_ptr<Union<uml::Element>> _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));


	//Clone references with containment (deep copy)

	if(obj.getMergedPackage()!=nullptr)
	{
		m_mergedPackage = std::dynamic_pointer_cast<uml::Package>(obj.getMergedPackage()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_mergedPackage" << std::endl;
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

std::shared_ptr<ecore::EObject>  PackageMergeImpl::copy() const
{
	std::shared_ptr<PackageMergeImpl> element(new PackageMergeImpl(*this));
	element->setThisPackageMergePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PackageMergeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPackageMerge_Class();
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
std::shared_ptr<uml::Package > PackageMergeImpl::getMergedPackage() const
{
//assert(m_mergedPackage);
    return m_mergedPackage;
}
void PackageMergeImpl::setMergedPackage(std::shared_ptr<uml::Package> _mergedPackage)
{
    m_mergedPackage = _mergedPackage;
}

std::weak_ptr<uml::Package > PackageMergeImpl::getReceivingPackage() const
{
//assert(m_receivingPackage);
    return m_receivingPackage;
}
void PackageMergeImpl::setReceivingPackage(std::shared_ptr<uml::Package> _receivingPackage)
{
    m_receivingPackage = _receivingPackage;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> PackageMergeImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > PackageMergeImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element>> PackageMergeImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> PackageMergeImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> PackageMergeImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<PackageMerge> PackageMergeImpl::getThisPackageMergePtr() const
{
	return m_thisPackageMergePtr.lock();
}
void PackageMergeImpl::setThisPackageMergePtr(std::weak_ptr<PackageMerge> thisPackageMergePtr)
{
	m_thisPackageMergePtr = thisPackageMergePtr;
	setThisDirectedRelationshipPtr(thisPackageMergePtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any PackageMergeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PACKAGEMERGE_ATTRIBUTE_MERGEDPACKAGE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getMergedPackage())); //1736
		case UmlPackage::PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getReceivingPackage().lock())); //1737
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}
bool PackageMergeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::PACKAGEMERGE_ATTRIBUTE_MERGEDPACKAGE:
			return getMergedPackage() != nullptr; //1736
		case UmlPackage::PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE:
			return getReceivingPackage().lock() != nullptr; //1737
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}
bool PackageMergeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::PACKAGEMERGE_ATTRIBUTE_MERGEDPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Package> _mergedPackage = std::dynamic_pointer_cast<uml::Package>(_temp);
			setMergedPackage(_mergedPackage); //1736
			return true;
		}
		case UmlPackage::PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Package> _receivingPackage = std::dynamic_pointer_cast<uml::Package>(_temp);
			setReceivingPackage(_receivingPackage); //1737
			return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void PackageMergeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	DirectedRelationshipImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void PackageMergeImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::PACKAGEMERGE_ATTRIBUTE_MERGEDPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Package> _mergedPackage = std::dynamic_pointer_cast<uml::Package>( references.front() );
				setMergedPackage(_mergedPackage);
			}
			
			return;
		}

		case UmlPackage::PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE:
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		saveHandler->addReference("mergedPackage", this->getMergedPackage());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

