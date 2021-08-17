#include "uml/impl/ExtendImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/ExtensionPoint.hpp"
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
ExtendImpl::ExtendImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExtendImpl::~ExtendImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Extend "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExtendImpl::ExtendImpl(std::weak_ptr<uml::UseCase> par_extension)
:ExtendImpl()
{
	m_extension = par_extension;
	m_namespace = par_extension;
}

//Additional constructor for the containments back reference
ExtendImpl::ExtendImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExtendImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExtendImpl::ExtendImpl(std::weak_ptr<uml::Element> par_owner)
:ExtendImpl()
{
	m_owner = par_owner;
}

ExtendImpl::ExtendImpl(const ExtendImpl & obj): ExtendImpl()
{
	*this = obj;
}

ExtendImpl& ExtendImpl::operator=(const ExtendImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	DirectedRelationshipImpl::operator=(obj);
	Extend::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Extend "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_extension  = obj.getExtension();
	m_extensionLocation  = obj.getExtensionLocation();
	//Clone references with containment (deep copy)
	//clone reference 'condition'
	if(obj.getCondition()!=nullptr)
	{
		m_condition = std::dynamic_pointer_cast<uml::Constraint>(obj.getCondition()->copy());
	}

	//clone reference 'extendedCase'
	if(obj.getExtendedCase()!=nullptr)
	{
		m_extendedCase = std::dynamic_pointer_cast<uml::UseCase>(obj.getExtendedCase()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ExtendImpl::copy() const
{
	std::shared_ptr<ExtendImpl> element(new ExtendImpl());
	*element =(*this);
	element->setThisExtendPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExtendImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExtend_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ExtendImpl::extension_points(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference condition
*/
std::shared_ptr<uml::Constraint> ExtendImpl::getCondition() const
{
    return m_condition;
}
void ExtendImpl::setCondition(std::shared_ptr<uml::Constraint> _condition)
{
    m_condition = _condition;
	
}


/*
Getter & Setter for reference extendedCase
*/
std::shared_ptr<uml::UseCase> ExtendImpl::getExtendedCase() const
{
    return m_extendedCase;
}
void ExtendImpl::setExtendedCase(std::shared_ptr<uml::UseCase> _extendedCase)
{
    m_extendedCase = _extendedCase;
	
}


/*
Getter & Setter for reference extension
*/
std::weak_ptr<uml::UseCase> ExtendImpl::getExtension() const
{
    return m_extension;
}
void ExtendImpl::setExtension(std::weak_ptr<uml::UseCase> _extension)
{
    m_extension = _extension;
	
}


/*
Getter & Setter for reference extensionLocation
*/
std::shared_ptr<Bag<uml::ExtensionPoint>> ExtendImpl::getExtensionLocation() const
{
	if(m_extensionLocation == nullptr)
	{
		m_extensionLocation.reset(new Bag<uml::ExtensionPoint>());
		
		
	}
    return m_extensionLocation;
}



//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> ExtendImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ExtendImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ExtendImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> ExtendImpl::getRelatedElement() const
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

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ExtendImpl::getSource() const
{
	if(m_source == nullptr)
	{
		/*SubsetUnion*/
		m_source.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getSource()->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_source;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ExtendImpl::getTarget() const
{
	if(m_target == nullptr)
	{
		/*SubsetUnion*/
		m_target.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getTarget()->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_target;
}




std::shared_ptr<Extend> ExtendImpl::getThisExtendPtr() const
{
	return m_thisExtendPtr.lock();
}
void ExtendImpl::setThisExtendPtr(std::weak_ptr<Extend> thisExtendPtr)
{
	m_thisExtendPtr = thisExtendPtr;
	setThisDirectedRelationshipPtr(thisExtendPtr);
	setThisNamedElementPtr(thisExtendPtr);
}
std::shared_ptr<ecore::EObject> ExtendImpl::eContainer() const
{
	if(auto wp = m_extension.lock())
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
Any ExtendImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXTEND_ATTRIBUTE_CONDITION:
			{
				std::shared_ptr<ecore::EObject> returnValue=getCondition();
				return eAny(returnValue); //9612
			}
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENDEDCASE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getExtendedCase();
				return eAny(returnValue); //9613
			}
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSION:
			{
				std::shared_ptr<ecore::EObject> returnValue=getExtension().lock();
				return eAny(returnValue); //9615
			}
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSIONLOCATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ExtensionPoint>::iterator iter = getExtensionLocation()->begin();
			Bag<uml::ExtensionPoint>::iterator end = getExtensionLocation()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //9614			
		}
	}
	Any result;
	result = DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = NamedElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool ExtendImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXTEND_ATTRIBUTE_CONDITION:
			return getCondition() != nullptr; //9612
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENDEDCASE:
			return getExtendedCase() != nullptr; //9613
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSION:
			return getExtension().lock() != nullptr; //9615
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSIONLOCATION:
			return getExtensionLocation() != nullptr; //9614
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
bool ExtendImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXTEND_ATTRIBUTE_CONDITION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Constraint> _condition = std::dynamic_pointer_cast<uml::Constraint>(_temp);
			setCondition(_condition); //9612
			return true;
		}
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENDEDCASE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::UseCase> _extendedCase = std::dynamic_pointer_cast<uml::UseCase>(_temp);
			setExtendedCase(_extendedCase); //9613
			return true;
		}
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::UseCase> _extension = std::dynamic_pointer_cast<uml::UseCase>(_temp);
			setExtension(_extension); //9615
			return true;
		}
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSIONLOCATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ExtensionPoint>> extensionLocationList(new Bag<uml::ExtensionPoint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				extensionLocationList->add(std::dynamic_pointer_cast<uml::ExtensionPoint>(*iter));
				iter++;
			}
			
			Bag<uml::ExtensionPoint>::iterator iterExtensionLocation = getExtensionLocation()->begin();
			Bag<uml::ExtensionPoint>::iterator endExtensionLocation = getExtensionLocation()->end();
			while (iterExtensionLocation != endExtensionLocation)
			{
				if (extensionLocationList->find(*iterExtensionLocation) == -1)
				{
					getExtensionLocation()->erase(*iterExtensionLocation);
				}
				iterExtensionLocation++;
			}
 
			iterExtensionLocation = extensionLocationList->begin();
			endExtensionLocation = extensionLocationList->end();
			while (iterExtensionLocation != endExtensionLocation)
			{
				if (getExtensionLocation()->find(*iterExtensionLocation) == -1)
				{
					getExtensionLocation()->add(*iterExtensionLocation);
				}
				iterExtensionLocation++;			
			}
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
Any ExtendImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 9672
		case umlPackage::EXTEND_OPERATION_EXTENSION_POINTS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->extension_points(incoming_param_diagnostics,incoming_param_context));
			break;
		}

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
void ExtendImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExtendImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("extendedCase");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("extendedCase")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("extensionLocation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("extensionLocation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ExtendImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("condition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			loadHandler->handleChild(this->getCondition()); 

			return; 
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
	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void ExtendImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENDEDCASE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::UseCase> _extendedCase = std::dynamic_pointer_cast<uml::UseCase>( references.front() );
				setExtendedCase(_extendedCase);
			}
			
			return;
		}

		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::UseCase> _extension = std::dynamic_pointer_cast<uml::UseCase>( references.front() );
				setExtension(_extension);
			}
			
			return;
		}

		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSIONLOCATION:
		{
			std::shared_ptr<Bag<uml::ExtensionPoint>> _extensionLocation = getExtensionLocation();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExtensionPoint>  _r = std::dynamic_pointer_cast<uml::ExtensionPoint>(ref);
				if (_r != nullptr)
				{
					_extensionLocation->push_back(_r);
				}
			}
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
	NamedElementImpl::resolveReferences(featureID, references);
}

void ExtendImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	NamedElementImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ExtendImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'condition'
		std::shared_ptr<uml::Constraint> condition = this->getCondition();
		if (condition != nullptr)
		{
			saveHandler->addReference(condition, "condition", condition->eClass() != package->getConstraint_Class());
		}
	// Add references
		saveHandler->addReference(this->getExtendedCase(), "extendedCase", getExtendedCase()->eClass() != uml::umlPackage::eInstance()->getUseCase_Class()); 
		saveHandler->addReferences<uml::ExtensionPoint>("extensionLocation", this->getExtensionLocation());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

