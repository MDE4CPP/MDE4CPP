#include "uml/impl/VariableImpl.hpp"

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

#include "uml/Action.hpp"

#include "uml/Activity.hpp"

#include "uml/Comment.hpp"

#include "uml/ConnectableElement.hpp"

#include "uml/ConnectorEnd.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/MultiplicityElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
VariableImpl::VariableImpl()
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

VariableImpl::~VariableImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Variable "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			VariableImpl::VariableImpl(std::weak_ptr<uml::Activity > par_activityScope)
			:VariableImpl()
			{
			    m_activityScope = par_activityScope;
				m_namespace = par_activityScope;
			}


//Additional constructor for the containments back reference
			VariableImpl::VariableImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:VariableImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			VariableImpl::VariableImpl(std::weak_ptr<uml::Element > par_owner)
			:VariableImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
			VariableImpl::VariableImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:VariableImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}


//Additional constructor for the containments back reference
			VariableImpl::VariableImpl(std::weak_ptr<uml::StructuredActivityNode > par_scope)
			:VariableImpl()
			{
			    m_scope = par_scope;
				m_namespace = par_scope;
			}



VariableImpl::VariableImpl(const VariableImpl & obj):VariableImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Variable "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isOrdered = obj.getIsOrdered();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_upper = obj.getUpper();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_activityScope  = obj.getActivityScope();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::ConnectorEnd>> _end = obj.getEnd();
	m_end.reset(new Bag<uml::ConnectorEnd>(*(obj.getEnd().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_scope  = obj.getScope();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getLowerValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_lowerValue" << std::endl;
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
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_upperValue" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  VariableImpl::copy() const
{
	std::shared_ptr<VariableImpl> element(new VariableImpl(*this));
	element->setThisVariablePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> VariableImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getVariable_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool VariableImpl::isAccessibleBy(std::shared_ptr<uml::Action>  a)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::Activity > VariableImpl::getActivityScope() const
{

    return m_activityScope;
}
void VariableImpl::setActivityScope(std::shared_ptr<uml::Activity> _activityScope)
{
    m_activityScope = _activityScope;
}

std::weak_ptr<uml::StructuredActivityNode > VariableImpl::getScope() const
{

    return m_scope;
}
void VariableImpl::setScope(std::shared_ptr<uml::StructuredActivityNode> _scope)
{
    m_scope = _scope;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > VariableImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> VariableImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > VariableImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<Variable> VariableImpl::getThisVariablePtr() const
{
	return m_thisVariablePtr.lock();
}
void VariableImpl::setThisVariablePtr(std::weak_ptr<Variable> thisVariablePtr)
{
	m_thisVariablePtr = thisVariablePtr;
	setThisConnectableElementPtr(thisVariablePtr);
	setThisMultiplicityElementPtr(thisVariablePtr);
}
std::shared_ptr<ecore::EObject> VariableImpl::eContainer() const
{
	if(auto wp = m_activityScope.lock())
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

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	if(auto wp = m_scope.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any VariableImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getActivityScope().lock())); //25319
		case uml::UmlPackage::VARIABLE_ATTRIBUTE_SCOPE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getScope().lock())); //25320
	}
	Any result;
	result = ConnectableElementImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = MultiplicityElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool VariableImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE:
			return getActivityScope().lock() != nullptr; //25319
		case uml::UmlPackage::VARIABLE_ATTRIBUTE_SCOPE:
			return getScope().lock() != nullptr; //25320
	}
	bool result = false;
	result = ConnectableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = MultiplicityElementImpl::internalEIsSet(featureID);
	return result;
}
bool VariableImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Activity> _activityScope = std::dynamic_pointer_cast<uml::Activity>(_temp);
			setActivityScope(_activityScope); //25319
			return true;
		}
		case uml::UmlPackage::VARIABLE_ATTRIBUTE_SCOPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StructuredActivityNode> _scope = std::dynamic_pointer_cast<uml::StructuredActivityNode>(_temp);
			setScope(_scope); //25320
			return true;
		}
	}

	bool result = false;
	result = ConnectableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = MultiplicityElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void VariableImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void VariableImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ConnectableElementImpl::loadAttributes(loadHandler, attr_list);
	MultiplicityElementImpl::loadAttributes(loadHandler, attr_list);
}

void VariableImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	ConnectableElementImpl::loadNode(nodeName, loadHandler);
	MultiplicityElementImpl::loadNode(nodeName, loadHandler);
}

void VariableImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Activity> _activityScope = std::dynamic_pointer_cast<uml::Activity>( references.front() );
				setActivityScope(_activityScope);
			}
			
			return;
		}

		case uml::UmlPackage::VARIABLE_ATTRIBUTE_SCOPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuredActivityNode> _scope = std::dynamic_pointer_cast<uml::StructuredActivityNode>( references.front() );
				setScope(_scope);
			}
			
			return;
		}
	}
	ConnectableElementImpl::resolveReferences(featureID, references);
	MultiplicityElementImpl::resolveReferences(featureID, references);
}

void VariableImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ConnectableElementImpl::saveContent(saveHandler);
	MultiplicityElementImpl::saveContent(saveHandler);
	
	ParameterableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void VariableImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

