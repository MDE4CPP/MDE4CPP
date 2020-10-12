#include "uml/impl/LiteralUnlimitedNaturalImpl.hpp"

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

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/LiteralSpecification.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/Slot.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

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
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl()
{	
}

LiteralUnlimitedNaturalImpl::~LiteralUnlimitedNaturalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralUnlimitedNatural "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Namespace > par_namespace)
:LiteralUnlimitedNaturalImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Element > par_owner)
:LiteralUnlimitedNaturalImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Package > par_owningPackage)
:LiteralUnlimitedNaturalImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Slot > par_owningSlot)
:LiteralUnlimitedNaturalImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:LiteralUnlimitedNaturalImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:LiteralUnlimitedNaturalImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}


LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(const LiteralUnlimitedNaturalImpl & obj):LiteralUnlimitedNaturalImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralUnlimitedNatural "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  LiteralUnlimitedNaturalImpl::copy() const
{
	std::shared_ptr<LiteralUnlimitedNaturalImpl> element(new LiteralUnlimitedNaturalImpl(*this));
	element->setThisLiteralUnlimitedNaturalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LiteralUnlimitedNaturalImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getLiteralUnlimitedNatural_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void LiteralUnlimitedNaturalImpl::setValue(int _value)
{
	m_value = _value;
} 
int LiteralUnlimitedNaturalImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************
bool LiteralUnlimitedNaturalImpl::isComputable()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return true;
	//end of body
}

int LiteralUnlimitedNaturalImpl::unlimitedValue()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return m_value;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > LiteralUnlimitedNaturalImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> LiteralUnlimitedNaturalImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element > LiteralUnlimitedNaturalImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<LiteralUnlimitedNatural> LiteralUnlimitedNaturalImpl::getThisLiteralUnlimitedNaturalPtr() const
{
	return m_thisLiteralUnlimitedNaturalPtr.lock();
}
void LiteralUnlimitedNaturalImpl::setThisLiteralUnlimitedNaturalPtr(std::weak_ptr<LiteralUnlimitedNatural> thisLiteralUnlimitedNaturalPtr)
{
	m_thisLiteralUnlimitedNaturalPtr = thisLiteralUnlimitedNaturalPtr;
	setThisLiteralSpecificationPtr(thisLiteralUnlimitedNaturalPtr);
}
std::shared_ptr<ecore::EObject> LiteralUnlimitedNaturalImpl::eContainer() const
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
Any LiteralUnlimitedNaturalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::LITERALUNLIMITEDNATURAL_ATTRIBUTE_VALUE:
			return eAny(getValue()); //14415
	}
	return LiteralSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool LiteralUnlimitedNaturalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::LITERALUNLIMITEDNATURAL_ATTRIBUTE_VALUE:
			return getValue() != 0; //14415
	}
	return LiteralSpecificationImpl::internalEIsSet(featureID);
}
bool LiteralUnlimitedNaturalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::LITERALUNLIMITEDNATURAL_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			int _value = newValue->get<int>();
			setValue(_value); //14415
			return true;
		}
	}

	return LiteralSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LiteralUnlimitedNaturalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LiteralUnlimitedNaturalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream ( iter->second ) >> value;
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

void LiteralUnlimitedNaturalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	LiteralSpecificationImpl::loadNode(nodeName, loadHandler);
}

void LiteralUnlimitedNaturalImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	LiteralSpecificationImpl::resolveReferences(featureID, references);
}

void LiteralUnlimitedNaturalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralSpecificationImpl::saveContent(saveHandler);
	
	ValueSpecificationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void LiteralUnlimitedNaturalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getLiteralUnlimitedNatural_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

