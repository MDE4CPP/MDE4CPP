#include "uml/impl/LiteralBooleanImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/LiteralSpecification.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/Slot.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

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
LiteralBooleanImpl::LiteralBooleanImpl()
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

LiteralBooleanImpl::~LiteralBooleanImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralBoolean "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:LiteralBooleanImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::Element > par_owner)
			:LiteralBooleanImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:LiteralBooleanImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:LiteralBooleanImpl()
			{
			    m_owningSlot = par_owningSlot;
				m_owner = par_owningSlot;
			}





//Additional constructor for the containments back reference
			LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:LiteralBooleanImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






LiteralBooleanImpl::LiteralBooleanImpl(const LiteralBooleanImpl & obj):LiteralBooleanImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralBoolean "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_value = obj.getValue();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningSlot  = obj.getOwningSlot();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  LiteralBooleanImpl::copy() const
{
	std::shared_ptr<LiteralBooleanImpl> element(new LiteralBooleanImpl(*this));
	element->setThisLiteralBooleanPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LiteralBooleanImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLiteralBoolean_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void LiteralBooleanImpl::setValue(bool _value)
{
	m_value = _value;
} 

bool LiteralBooleanImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > LiteralBooleanImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> LiteralBooleanImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > LiteralBooleanImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<LiteralBoolean> LiteralBooleanImpl::getThisLiteralBooleanPtr() const
{
	return m_thisLiteralBooleanPtr.lock();
}
void LiteralBooleanImpl::setThisLiteralBooleanPtr(std::weak_ptr<LiteralBoolean> thisLiteralBooleanPtr)
{
	m_thisLiteralBooleanPtr = thisLiteralBooleanPtr;
	setThisLiteralSpecificationPtr(thisLiteralBooleanPtr);
}
std::shared_ptr<ecore::EObject> LiteralBooleanImpl::eContainer() const
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LiteralBooleanImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::LITERALBOOLEAN_EATTRIBUTE_VALUE:
			return eAny(getValue()); //24815
	}
	return LiteralSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool LiteralBooleanImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::LITERALBOOLEAN_EATTRIBUTE_VALUE:
			return getValue() != false; //24815
	}
	return LiteralSpecificationImpl::internalEIsSet(featureID);
}
bool LiteralBooleanImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::LITERALBOOLEAN_EATTRIBUTE_VALUE:
		{
			// BOOST CAST
			bool _value = newValue->get<bool>();
			setValue(_value); //24815
			return true;
		}
	}

	return LiteralSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LiteralBooleanImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LiteralBooleanImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setValue(value);
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

	LiteralSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralBooleanImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	LiteralSpecificationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void LiteralBooleanImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	LiteralSpecificationImpl::resolveReferences(featureID, references);
}

void LiteralBooleanImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralSpecificationImpl::saveContent(saveHandler);
	
	ValueSpecificationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void LiteralBooleanImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getLiteralBoolean_EAttribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

