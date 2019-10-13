#include "uml/impl/ValueSpecificationImpl.hpp"

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
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Slot.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

#include "uml/TypedElement.hpp"

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
ValueSpecificationImpl::ValueSpecificationImpl()
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

ValueSpecificationImpl::~ValueSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ValueSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ValueSpecificationImpl::ValueSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ValueSpecificationImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			ValueSpecificationImpl::ValueSpecificationImpl(std::weak_ptr<uml::Element > par_owner)
			:ValueSpecificationImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ValueSpecificationImpl::ValueSpecificationImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:ValueSpecificationImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			ValueSpecificationImpl::ValueSpecificationImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:ValueSpecificationImpl()
			{
			    m_owningSlot = par_owningSlot;
				m_owner = par_owningSlot;
			}





//Additional constructor for the containments back reference
			ValueSpecificationImpl::ValueSpecificationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ValueSpecificationImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






ValueSpecificationImpl::ValueSpecificationImpl(const ValueSpecificationImpl & obj):ValueSpecificationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ValueSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
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

std::shared_ptr<ecore::EObject>  ValueSpecificationImpl::copy() const
{
	std::shared_ptr<ValueSpecificationImpl> element(new ValueSpecificationImpl(*this));
	element->setThisValueSpecificationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ValueSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getValueSpecification_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ValueSpecificationImpl::booleanValue()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int ValueSpecificationImpl::integerValue()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ValueSpecificationImpl::isComputable()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ValueSpecificationImpl::isNull()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

double ValueSpecificationImpl::realValue()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string ValueSpecificationImpl::stringValue()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int ValueSpecificationImpl::unlimitedValue()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::Slot > ValueSpecificationImpl::getOwningSlot() const
{

    return m_owningSlot;
}
void ValueSpecificationImpl::setOwningSlot(std::shared_ptr<uml::Slot> _owningSlot)
{
    m_owningSlot = _owningSlot;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > ValueSpecificationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> ValueSpecificationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ValueSpecificationImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ValueSpecification> ValueSpecificationImpl::getThisValueSpecificationPtr() const
{
	return m_thisValueSpecificationPtr.lock();
}
void ValueSpecificationImpl::setThisValueSpecificationPtr(std::weak_ptr<ValueSpecification> thisValueSpecificationPtr)
{
	m_thisValueSpecificationPtr = thisValueSpecificationPtr;
	setThisPackageableElementPtr(thisValueSpecificationPtr);
	setThisTypedElementPtr(thisValueSpecificationPtr);
}
std::shared_ptr<ecore::EObject> ValueSpecificationImpl::eContainer() const
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
Any ValueSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getOwningSlot().lock())); //25113
	}
	Any result;
	result = PackageableElementImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = TypedElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool ValueSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
			return getOwningSlot().lock() != nullptr; //25113
	}
	bool result = false;
	result = PackageableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TypedElementImpl::internalEIsSet(featureID);
	return result;
}
bool ValueSpecificationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Slot> _owningSlot = std::dynamic_pointer_cast<uml::Slot>(_temp);
			setOwningSlot(_owningSlot); //25113
			return true;
		}
	}

	bool result = false;
	result = PackageableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TypedElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ValueSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ValueSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
	TypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ValueSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	PackageableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
	TypedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ValueSpecificationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Slot> _owningSlot = std::dynamic_pointer_cast<uml::Slot>( references.front() );
				setOwningSlot(_owningSlot);
			}
			
			return;
		}
	}
	PackageableElementImpl::resolveReferences(featureID, references);
	TypedElementImpl::resolveReferences(featureID, references);
}

void ValueSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ValueSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

