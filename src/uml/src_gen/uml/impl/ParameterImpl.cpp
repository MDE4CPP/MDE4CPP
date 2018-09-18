#include "uml/impl/ParameterImpl.hpp"

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
#include "abstractDataTypes/Any.hpp"
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

#include "uml/Behavior.hpp"

#include "uml/Comment.hpp"

#include "uml/ConnectableElement.hpp"

#include "uml/ConnectorEnd.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/MultiplicityElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Operation.hpp"

#include "uml/ParameterSet.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"

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
ParameterImpl::ParameterImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	

		m_parameterSet.reset(new Bag<uml::ParameterSet>());
	
	

	//Init references
	

	

	

	
	
}

ParameterImpl::~ParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Parameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ParameterImpl::ParameterImpl(std::weak_ptr<uml::Behavior > par_behavior)
			:ParameterImpl()
			{
			    m_behavior = par_behavior;
				m_namespace = par_behavior;
			}





//Additional constructor for the containments back reference
			ParameterImpl::ParameterImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ParameterImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			ParameterImpl::ParameterImpl(std::weak_ptr<uml::Operation > par_operation)
			:ParameterImpl()
			{
			    m_operation = par_operation;
				m_namespace = par_operation;
			}





//Additional constructor for the containments back reference
			ParameterImpl::ParameterImpl(std::weak_ptr<uml::Element > par_owner)
			:ParameterImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ParameterImpl::ParameterImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ParameterImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






ParameterImpl::ParameterImpl(const ParameterImpl & obj):ParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Parameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_default = obj.getDefault();
	m_direction = obj.getDirection();
	m_effect = obj.getEffect();
	m_isException = obj.getIsException();
	m_isOrdered = obj.getIsOrdered();
	m_isStream = obj.getIsStream();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_upper = obj.getUpper();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_behavior  = obj.getBehavior();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::ConnectorEnd>> _end = obj.getEnd();
	m_end.reset(new Bag<uml::ConnectorEnd>(*(obj.getEnd().get())));

	m_namespace  = obj.getNamespace();

	m_operation  = obj.getOperation();

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Bag<uml::ParameterSet>> _parameterSet = obj.getParameterSet();
	m_parameterSet.reset(new Bag<uml::ParameterSet>(*(obj.getParameterSet().get())));

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	if(obj.getDefaultValue()!=nullptr)
	{
		m_defaultValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getDefaultValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_defaultValue" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  ParameterImpl::copy() const
{
	std::shared_ptr<ParameterImpl> element(new ParameterImpl(*this));
	element->setThisParameterPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ParameterImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getParameter_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ParameterImpl::setDefault(std::string _default)
{
	m_default = _default;
} 

std::string ParameterImpl::getDefault() const 
{
	return m_default;
}

void ParameterImpl::setDirection(ParameterDirectionKind _direction)
{
	m_direction = _direction;
} 

ParameterDirectionKind ParameterImpl::getDirection() const 
{
	return m_direction;
}

void ParameterImpl::setEffect(ParameterEffectKind _effect)
{
	m_effect = _effect;
} 

ParameterEffectKind ParameterImpl::getEffect() const 
{
	return m_effect;
}

void ParameterImpl::setIsException(bool _isException)
{
	m_isException = _isException;
} 

bool ParameterImpl::getIsException() const 
{
	return m_isException;
}

void ParameterImpl::setIsStream(bool _isStream)
{
	m_isStream = _isStream;
} 

bool ParameterImpl::getIsStream() const 
{
	return m_isStream;
}

//*********************************
// Operations
//*********************************
bool ParameterImpl::connector_end(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::in_and_out(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::isSetDefault()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::not_exception(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::object_effect(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::reentrant_behaviors(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setBooleanDefaultValue(bool value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setIntegerDefaultValue(int value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setNullDefaultValue()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setRealDefaultValue(double value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setStringDefaultValue(std::string value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setUnlimitedNaturalDefaultValue(int value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::stream_and_exception(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::unsetDefault()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::Behavior > ParameterImpl::getBehavior() const
{

    return m_behavior;
}
void ParameterImpl::setBehavior(std::shared_ptr<uml::Behavior> _behavior)
{
    m_behavior = _behavior;
}

std::shared_ptr<uml::ValueSpecification > ParameterImpl::getDefaultValue() const
{

    return m_defaultValue;
}
void ParameterImpl::setDefaultValue(std::shared_ptr<uml::ValueSpecification> _defaultValue)
{
    m_defaultValue = _defaultValue;
}

std::weak_ptr<uml::Operation > ParameterImpl::getOperation() const
{

    return m_operation;
}


std::shared_ptr<Bag<uml::ParameterSet>> ParameterImpl::getParameterSet() const
{

    return m_parameterSet;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > ParameterImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> ParameterImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ParameterImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<Parameter> ParameterImpl::getThisParameterPtr() const
{
	return m_thisParameterPtr.lock();
}
void ParameterImpl::setThisParameterPtr(std::weak_ptr<Parameter> thisParameterPtr)
{
	m_thisParameterPtr = thisParameterPtr;
	setThisConnectableElementPtr(thisParameterPtr);
	setThisMultiplicityElementPtr(thisParameterPtr);
}
std::shared_ptr<ecore::EObject> ParameterImpl::eContainer() const
{
	if(auto wp = m_behavior.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_operation.lock())
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PARAMETER_EREFERENCE_BEHAVIOR:
			return eAny(getBehavior()); //4428
		case UmlPackage::PARAMETER_EATTRIBUTE_DEFAULT:
			return eAny(getDefault()); //4420
		case UmlPackage::PARAMETER_EREFERENCE_DEFAULTVALUE:
			return eAny(getDefaultValue()); //4421
		case UmlPackage::PARAMETER_EATTRIBUTE_DIRECTION:
			return eAny(getDirection()); //4422
		case UmlPackage::PARAMETER_EATTRIBUTE_EFFECT:
			return eAny(getEffect()); //4423
		case UmlPackage::PARAMETER_EATTRIBUTE_ISEXCEPTION:
			return eAny(getIsException()); //4424
		case UmlPackage::PARAMETER_EATTRIBUTE_ISSTREAM:
			return eAny(getIsStream()); //4425
		case UmlPackage::PARAMETER_EREFERENCE_OPERATION:
			return eAny(getOperation()); //4426
		case UmlPackage::PARAMETER_EREFERENCE_PARAMETERSET:
			return eAny(getParameterSet()); //4427
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
bool ParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::PARAMETER_EREFERENCE_BEHAVIOR:
			return getBehavior().lock() != nullptr; //4428
		case UmlPackage::PARAMETER_EATTRIBUTE_DEFAULT:
			return getDefault() != ""; //4420
		case UmlPackage::PARAMETER_EREFERENCE_DEFAULTVALUE:
			return getDefaultValue() != nullptr; //4421
		case UmlPackage::PARAMETER_EATTRIBUTE_DIRECTION:
			return m_direction != ParameterDirectionKind::IN;; //4422
		case UmlPackage::PARAMETER_EATTRIBUTE_EFFECT:
			return m_effect != ParameterEffectKind::CREATE;; //4423
		case UmlPackage::PARAMETER_EATTRIBUTE_ISEXCEPTION:
			return getIsException() != false; //4424
		case UmlPackage::PARAMETER_EATTRIBUTE_ISSTREAM:
			return getIsStream() != false; //4425
		case UmlPackage::PARAMETER_EREFERENCE_OPERATION:
			return getOperation().lock() != nullptr; //4426
		case UmlPackage::PARAMETER_EREFERENCE_PARAMETERSET:
			return getParameterSet() != nullptr; //4427
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
bool ParameterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::PARAMETER_EREFERENCE_BEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _behavior = newValue->get<std::shared_ptr<uml::Behavior>>();
			setBehavior(_behavior); //4428
			return true;
		}
		case UmlPackage::PARAMETER_EATTRIBUTE_DEFAULT:
		{
			// BOOST CAST
			std::string _default = newValue->get<std::string>();
			setDefault(_default); //4420
			return true;
		}
		case UmlPackage::PARAMETER_EREFERENCE_DEFAULTVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _defaultValue = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setDefaultValue(_defaultValue); //4421
			return true;
		}
		case UmlPackage::PARAMETER_EATTRIBUTE_DIRECTION:
		{
			// BOOST CAST
			ParameterDirectionKind _direction = newValue->get<ParameterDirectionKind>();
			setDirection(_direction); //4422
			return true;
		}
		case UmlPackage::PARAMETER_EATTRIBUTE_EFFECT:
		{
			// BOOST CAST
			ParameterEffectKind _effect = newValue->get<ParameterEffectKind>();
			setEffect(_effect); //4423
			return true;
		}
		case UmlPackage::PARAMETER_EATTRIBUTE_ISEXCEPTION:
		{
			// BOOST CAST
			bool _isException = newValue->get<bool>();
			setIsException(_isException); //4424
			return true;
		}
		case UmlPackage::PARAMETER_EATTRIBUTE_ISSTREAM:
		{
			// BOOST CAST
			bool _isStream = newValue->get<bool>();
			setIsStream(_isStream); //4425
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
void ParameterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("direction");
		if ( iter != attr_list.end() )
		{
			ParameterDirectionKind value = ParameterDirectionKind::IN;
			std::string literal = iter->second;
			if (literal == "in")
			{
				value = ParameterDirectionKind::IN;
			}
			else if (literal == "inout")
			{
				value = ParameterDirectionKind::INOUT;
			}
			else if (literal == "out")
			{
				value = ParameterDirectionKind::OUT;
			}
			else if (literal == "return")
			{
				value = ParameterDirectionKind::RETURN;
			}
			this->setDirection(value);
		}

		iter = attr_list.find("effect");
		if ( iter != attr_list.end() )
		{
			ParameterEffectKind value = ParameterEffectKind::CREATE;
			std::string literal = iter->second;
			if (literal == "create")
			{
				value = ParameterEffectKind::CREATE;
			}
			else if (literal == "read")
			{
				value = ParameterEffectKind::READ;
			}
			else if (literal == "update")
			{
				value = ParameterEffectKind::UPDATE;
			}
			else if (literal == "delete")
			{
				value = ParameterEffectKind::DELETE;
			}
			this->setEffect(value);
		}

		iter = attr_list.find("isException");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsException(value);
		}

		iter = attr_list.find("isStream");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsStream(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("parameterSet");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parameterSet")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ConnectableElementImpl::loadAttributes(loadHandler, attr_list);
	MultiplicityElementImpl::loadAttributes(loadHandler, attr_list);
}

void ParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("defaultValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> defaultValue = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (defaultValue != nullptr)
			{
				this->setDefaultValue(defaultValue);
				loadHandler->handleChild(defaultValue);
			}
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

	ConnectableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
	MultiplicityElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ParameterImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::PARAMETER_EREFERENCE_BEHAVIOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setBehavior(_behavior);
			}
			
			return;
		}

		case UmlPackage::PARAMETER_EREFERENCE_PARAMETERSET:
		{
			std::shared_ptr<Bag<uml::ParameterSet>> _parameterSet = getParameterSet();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ParameterSet> _r = std::dynamic_pointer_cast<uml::ParameterSet>(ref);
				if (_r != nullptr)
				{
					_parameterSet->push_back(_r);
				}				
			}
			return;
		}
	}
	ConnectableElementImpl::resolveReferences(featureID, references);
	MultiplicityElementImpl::resolveReferences(featureID, references);
}

void ParameterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ConnectableElementImpl::saveContent(saveHandler);
	MultiplicityElementImpl::saveContent(saveHandler);
	
	ParameterableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ParameterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'defaultValue'
		std::shared_ptr<uml::ValueSpecification > defaultValue = this->getDefaultValue();
		if (defaultValue != nullptr)
		{
			saveHandler->addReference(defaultValue, "defaultValue", defaultValue->eClass() != package->getValueSpecification_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getParameter_EAttribute_direction()) )
		{
			ParameterDirectionKind value = this->getDirection();
			std::string literal = "";
			if (value == ParameterDirectionKind::IN)
			{
				literal = "in";
			}
			else if (value == ParameterDirectionKind::INOUT)
			{
				literal = "inout";
			}
			else if (value == ParameterDirectionKind::OUT)
			{
				literal = "out";
			}
			else if (value == ParameterDirectionKind::RETURN)
			{
				literal = "return";
			}
			saveHandler->addAttribute("direction", literal);
		}

		if ( this->eIsSet(package->getParameter_EAttribute_effect()) )
		{
			ParameterEffectKind value = this->getEffect();
			std::string literal = "";
			if (value == ParameterEffectKind::CREATE)
			{
				literal = "create";
			}
			else if (value == ParameterEffectKind::READ)
			{
				literal = "read";
			}
			else if (value == ParameterEffectKind::UPDATE)
			{
				literal = "update";
			}
			else if (value == ParameterEffectKind::DELETE)
			{
				literal = "delete";
			}
			saveHandler->addAttribute("effect", literal);
		}

		if ( this->eIsSet(package->getParameter_EAttribute_isException()) )
		{
			saveHandler->addAttribute("isException", this->getIsException());
		}

		if ( this->eIsSet(package->getParameter_EAttribute_isStream()) )
		{
			saveHandler->addAttribute("isStream", this->getIsStream());
		}

		// Add references
		std::shared_ptr<Bag<uml::ParameterSet>> parameterSet_list = this->getParameterSet();
		for (std::shared_ptr<uml::ParameterSet > object : *parameterSet_list)
		{ 
			saveHandler->addReferences("parameterSet", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

