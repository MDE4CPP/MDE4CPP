#include "uml/impl/GeneralOrderingImpl.hpp"

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

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/OccurrenceSpecification.hpp"

#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
GeneralOrderingImpl::GeneralOrderingImpl()
{	
}

GeneralOrderingImpl::~GeneralOrderingImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete GeneralOrdering "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
GeneralOrderingImpl::GeneralOrderingImpl(std::weak_ptr<uml::Namespace > par_namespace)
:GeneralOrderingImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
GeneralOrderingImpl::GeneralOrderingImpl(std::weak_ptr<uml::Element > par_owner)
:GeneralOrderingImpl()
{
	m_owner = par_owner;
}


GeneralOrderingImpl::GeneralOrderingImpl(const GeneralOrderingImpl & obj):GeneralOrderingImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy GeneralOrdering "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_after  = obj.getAfter();

	m_before  = obj.getBefore();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)

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

}

std::shared_ptr<ecore::EObject>  GeneralOrderingImpl::copy() const
{
	std::shared_ptr<GeneralOrderingImpl> element(new GeneralOrderingImpl(*this));
	element->setThisGeneralOrderingPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> GeneralOrderingImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getGeneralOrdering_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool GeneralOrderingImpl::irreflexive_transitive_closure(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference after
*/
std::shared_ptr<uml::OccurrenceSpecification > GeneralOrderingImpl::getAfter() const
{
//assert(m_after);
    return m_after;
}

void GeneralOrderingImpl::setAfter(std::shared_ptr<uml::OccurrenceSpecification> _after)
{
    m_after = _after;
}



/*
Getter & Setter for reference before
*/
std::shared_ptr<uml::OccurrenceSpecification > GeneralOrderingImpl::getBefore() const
{
//assert(m_before);
    return m_before;
}

void GeneralOrderingImpl::setBefore(std::shared_ptr<uml::OccurrenceSpecification> _before)
{
    m_before = _before;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> GeneralOrderingImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element > GeneralOrderingImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<GeneralOrdering> GeneralOrderingImpl::getThisGeneralOrderingPtr() const
{
	return m_thisGeneralOrderingPtr.lock();
}
void GeneralOrderingImpl::setThisGeneralOrderingPtr(std::weak_ptr<GeneralOrdering> thisGeneralOrderingPtr)
{
	m_thisGeneralOrderingPtr = thisGeneralOrderingPtr;
	setThisNamedElementPtr(thisGeneralOrderingPtr);
}
std::shared_ptr<ecore::EObject> GeneralOrderingImpl::eContainer() const
{
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
Any GeneralOrderingImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::GENERALORDERING_ATTRIBUTE_AFTER:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getAfter())); //1099
		case uml::UmlPackage::GENERALORDERING_ATTRIBUTE_BEFORE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getBefore())); //10910
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool GeneralOrderingImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::GENERALORDERING_ATTRIBUTE_AFTER:
			return getAfter() != nullptr; //1099
		case uml::UmlPackage::GENERALORDERING_ATTRIBUTE_BEFORE:
			return getBefore() != nullptr; //10910
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool GeneralOrderingImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::GENERALORDERING_ATTRIBUTE_AFTER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OccurrenceSpecification> _after = std::dynamic_pointer_cast<uml::OccurrenceSpecification>(_temp);
			setAfter(_after); //1099
			return true;
		}
		case uml::UmlPackage::GENERALORDERING_ATTRIBUTE_BEFORE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OccurrenceSpecification> _before = std::dynamic_pointer_cast<uml::OccurrenceSpecification>(_temp);
			setBefore(_before); //10910
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void GeneralOrderingImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void GeneralOrderingImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("after");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("after")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("before");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("before")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void GeneralOrderingImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void GeneralOrderingImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::GENERALORDERING_ATTRIBUTE_AFTER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OccurrenceSpecification> _after = std::dynamic_pointer_cast<uml::OccurrenceSpecification>( references.front() );
				setAfter(_after);
			}
			
			return;
		}

		case uml::UmlPackage::GENERALORDERING_ATTRIBUTE_BEFORE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OccurrenceSpecification> _before = std::dynamic_pointer_cast<uml::OccurrenceSpecification>( references.front() );
				setBefore(_before);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void GeneralOrderingImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void GeneralOrderingImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		saveHandler->addReference("after", this->getAfter());
		saveHandler->addReference("before", this->getBefore());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

