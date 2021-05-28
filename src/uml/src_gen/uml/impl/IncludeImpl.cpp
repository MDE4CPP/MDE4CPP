#include "uml/impl/IncludeImpl.hpp"

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
#include "uml/UmlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
#include "uml/UseCase.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
IncludeImpl::IncludeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

IncludeImpl::~IncludeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Include "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
IncludeImpl::IncludeImpl(std::weak_ptr<uml::UseCase> par_includingCase)
:IncludeImpl()
{
	m_includingCase = par_includingCase;
	m_namespace = par_includingCase;
}

//Additional constructor for the containments back reference
IncludeImpl::IncludeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:IncludeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
IncludeImpl::IncludeImpl(std::weak_ptr<uml::Element> par_owner)
:IncludeImpl()
{
	m_owner = par_owner;
}

IncludeImpl::IncludeImpl(const IncludeImpl & obj): IncludeImpl()
{
	*this = obj;
}

IncludeImpl& IncludeImpl::operator=(const IncludeImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	DirectedRelationshipImpl::operator=(obj);
	Include::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Include "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_includingCase  = obj.getIncludingCase();
	//Clone references with containment (deep copy)
	if(obj.getAddition()!=nullptr)
	{
		m_addition = std::dynamic_pointer_cast<uml::UseCase>(obj.getAddition()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> IncludeImpl::copy() const
{
	std::shared_ptr<IncludeImpl> element(new IncludeImpl());
	*element =(*this);
	element->setThisIncludePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> IncludeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInclude_Class();
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
/*
Getter & Setter for reference addition
*/
std::shared_ptr<uml::UseCase> IncludeImpl::getAddition() const
{
//assert(m_addition);
    return m_addition;
}
void IncludeImpl::setAddition(std::shared_ptr<uml::UseCase> _addition)
{
    m_addition = _addition;
}


/*
Getter & Setter for reference includingCase
*/
std::weak_ptr<uml::UseCase> IncludeImpl::getIncludingCase() const
{
//assert(m_includingCase);
    return m_includingCase;
}
void IncludeImpl::setIncludingCase(std::weak_ptr<uml::UseCase> _includingCase)
{
    m_includingCase = _includingCase;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> IncludeImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> IncludeImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> IncludeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> IncludeImpl::getRelatedElement() const
{
	if(m_relatedElement == nullptr)
	{
		/*Union*/
		m_relatedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_relatedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_relatedElement;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> IncludeImpl::getSource() const
{
	if(m_source == nullptr)
	{
		/*SubsetUnion*/
		m_source.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_source->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_source;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> IncludeImpl::getTarget() const
{
	if(m_target == nullptr)
	{
		/*SubsetUnion*/
		m_target.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_target->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_target;
}




std::shared_ptr<Include> IncludeImpl::getThisIncludePtr() const
{
	return m_thisIncludePtr.lock();
}
void IncludeImpl::setThisIncludePtr(std::weak_ptr<Include> thisIncludePtr)
{
	m_thisIncludePtr = thisIncludePtr;
	setThisDirectedRelationshipPtr(thisIncludePtr);
	setThisNamedElementPtr(thisIncludePtr);
}
std::shared_ptr<ecore::EObject> IncludeImpl::eContainer() const
{
	if(auto wp = m_includingCase.lock())
	{
		return wp;
	}

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
Any IncludeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INCLUDE_ATTRIBUTE_ADDITION:
			return eAny(getAddition()); //11212
		case uml::umlPackage::INCLUDE_ATTRIBUTE_INCLUDINGCASE:
			return eAny(getIncludingCase().lock()); //11213
	}
	Any result;
	result = DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = NamedElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool IncludeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INCLUDE_ATTRIBUTE_ADDITION:
			return getAddition() != nullptr; //11212
		case uml::umlPackage::INCLUDE_ATTRIBUTE_INCLUDINGCASE:
			return getIncludingCase().lock() != nullptr; //11213
	}
	bool result = false;
	result = DirectedRelationshipImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NamedElementImpl::internalEIsSet(featureID);
	return result;
}
bool IncludeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INCLUDE_ATTRIBUTE_ADDITION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::UseCase> _addition = std::dynamic_pointer_cast<uml::UseCase>(_temp);
			setAddition(_addition); //11212
			return true;
		}
		case uml::umlPackage::INCLUDE_ATTRIBUTE_INCLUDINGCASE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::UseCase> _includingCase = std::dynamic_pointer_cast<uml::UseCase>(_temp);
			setIncludingCase(_includingCase); //11213
			return true;
		}
	}

	bool result = false;
	result = DirectedRelationshipImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NamedElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any IncludeImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void IncludeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void IncludeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("addition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("addition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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
	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void IncludeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void IncludeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INCLUDE_ATTRIBUTE_ADDITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::UseCase> _addition = std::dynamic_pointer_cast<uml::UseCase>( references.front() );
				setAddition(_addition);
			}
			
			return;
		}

		case uml::umlPackage::INCLUDE_ATTRIBUTE_INCLUDINGCASE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::UseCase> _includingCase = std::dynamic_pointer_cast<uml::UseCase>( references.front() );
				setIncludingCase(_includingCase);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
	NamedElementImpl::resolveReferences(featureID, references);
}

void IncludeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	NamedElementImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void IncludeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getAddition(), "addition", getAddition()->eClass() != uml::umlPackage::eInstance()->getUseCase_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

