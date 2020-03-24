#include "uml/impl/OpaqueExpressionImpl.hpp"

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

#include "uml/Behavior.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/Parameter.hpp"

#include "uml/Slot.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"

#include "uml/ValueSpecificationAction.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueExpressionImpl::OpaqueExpressionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	m_body.reset(new Bag<std::string>());
	m_language.reset(new Bag<std::string>());
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	//Init references
	

	
}

OpaqueExpressionImpl::~OpaqueExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OpaqueExpression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:OpaqueExpressionImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Element > par_owner)
			:OpaqueExpressionImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
			OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:OpaqueExpressionImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}


//Additional constructor for the containments back reference
			OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:OpaqueExpressionImpl()
			{
			    m_owningSlot = par_owningSlot;
				m_owner = par_owningSlot;
			}


//Additional constructor for the containments back reference
			OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:OpaqueExpressionImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}


//Additional constructor for the containments back reference
			OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
			:OpaqueExpressionImpl()
			{
			    m_valueSpecificationAction = par_valueSpecificationAction;
				m_owner = par_valueSpecificationAction;
			}



OpaqueExpressionImpl::OpaqueExpressionImpl(const OpaqueExpressionImpl & obj):OpaqueExpressionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OpaqueExpression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_body = obj.getBody();
	m_language = obj.getLanguage();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_behavior  = obj.getBehavior();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningSlot  = obj.getOwningSlot();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_result  = obj.getResult();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();

	m_valueSpecificationAction  = obj.getValueSpecificationAction();


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

std::shared_ptr<ecore::EObject>  OpaqueExpressionImpl::copy() const
{
	std::shared_ptr<OpaqueExpressionImpl> element(new OpaqueExpressionImpl(*this));
	element->setThisOpaqueExpressionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OpaqueExpressionImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getOpaqueExpression_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************


std::shared_ptr<Bag<std::string> > OpaqueExpressionImpl::getBody() const 
{
	return m_body;
}



std::shared_ptr<Bag<std::string> > OpaqueExpressionImpl::getLanguage() const 
{
	return m_language;
}

//*********************************
// Operations
//*********************************


bool OpaqueExpressionImpl::isIntegral()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::isNonNegative()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::isPositive()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::language_body_size(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::one_return_result_parameter(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::only_return_result_parameters(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int OpaqueExpressionImpl::value()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Behavior > OpaqueExpressionImpl::getBehavior() const
{

    return m_behavior;
}
void OpaqueExpressionImpl::setBehavior(std::shared_ptr<uml::Behavior> _behavior)
{
    m_behavior = _behavior;
}

std::shared_ptr<uml::Parameter > OpaqueExpressionImpl::getResult() const
{

    return m_result;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > OpaqueExpressionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> OpaqueExpressionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > OpaqueExpressionImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<OpaqueExpression> OpaqueExpressionImpl::getThisOpaqueExpressionPtr() const
{
	return m_thisOpaqueExpressionPtr.lock();
}
void OpaqueExpressionImpl::setThisOpaqueExpressionPtr(std::weak_ptr<OpaqueExpression> thisOpaqueExpressionPtr)
{
	m_thisOpaqueExpressionPtr = thisOpaqueExpressionPtr;
	setThisValueSpecificationPtr(thisOpaqueExpressionPtr);
}
std::shared_ptr<ecore::EObject> OpaqueExpressionImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningSlot.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	if(auto wp = m_valueSpecificationAction.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any OpaqueExpressionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BEHAVIOR:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getBehavior())); //16715
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BODY:
			return eAny(getBody()); //16716
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_LANGUAGE:
			return eAny(getLanguage()); //16717
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_RESULT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getResult())); //16718
	}
	return ValueSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool OpaqueExpressionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BEHAVIOR:
			return getBehavior() != nullptr; //16715
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BODY:
			return !getBody()->empty(); //16716
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_LANGUAGE:
			return !getLanguage()->empty(); //16717
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //16718
	}
	return ValueSpecificationImpl::internalEIsSet(featureID);
}
bool OpaqueExpressionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setBehavior(_behavior); //16715
			return true;
		}
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BODY:
		{
			// BOOST CAST
			// nothing to do
			return true;
		}
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_LANGUAGE:
		{
			// BOOST CAST
			// nothing to do
			return true;
		}
	}

	return ValueSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void OpaqueExpressionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OpaqueExpressionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("behavior");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("behavior")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ValueSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void OpaqueExpressionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();
	try
	{
		if (nodeName.compare("body") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string> > list_body = this->getBody();
			list_body->push_back(value);
			return;
		}

		if (nodeName.compare("language") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string> > list_language = this->getLanguage();
			list_language->push_back(value);
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
	ValueSpecificationImpl::loadNode(nodeName, loadHandler);
}

void OpaqueExpressionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BEHAVIOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setBehavior(_behavior);
			}
			
			return;
		}
	}
	ValueSpecificationImpl::resolveReferences(featureID, references);
}

void OpaqueExpressionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ValueSpecificationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void OpaqueExpressionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getOpaqueExpression_Attribute_body()) )
		{
			for (std::shared_ptr<std::string> value : *m_body)
			{
				saveHandler->addAttributeAsNode("body", *value);
			}
		}

		if ( this->eIsSet(package->getOpaqueExpression_Attribute_language()) )
		{
			for (std::shared_ptr<std::string> value : *m_language)
			{
				saveHandler->addAttributeAsNode("language", *value);
			}
		}

		// Add references
		saveHandler->addReference("behavior", this->getBehavior());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

