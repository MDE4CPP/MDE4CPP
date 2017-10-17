#include "ParameterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Behavior.hpp"

#include "Comment.hpp"

#include "ConnectableElement.hpp"

#include "ConnectorEnd.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "MultiplicityElement.hpp"

#include "Namespace.hpp"

#include "Operation.hpp"

#include "ParameterSet.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "Type.hpp"

#include "ValueSpecification.hpp"


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
			}





//Additional constructor for the containments back reference
			ParameterImpl::ParameterImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ParameterImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ParameterImpl::ParameterImpl(std::weak_ptr<uml::Operation > par_operation)
			:ParameterImpl()
			{
			    m_operation = par_operation;
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

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::ConnectorEnd> > _end = obj.getEnd();
	m_end.reset(new Bag<uml::ConnectorEnd>(*(obj.getEnd().get())));

	m_namespace  = obj.getNamespace();

	m_operation  = obj.getOperation();

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr< Bag<uml::ParameterSet> > _parameterSet = obj.getParameterSet();
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
	std::shared_ptr<ecore::EObject> element(new ParameterImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ParameterImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getParameter();
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
bool ParameterImpl::connector_end(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::in_and_out(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::isSetDefault() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::not_exception(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::object_effect(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::reentrant_behaviors(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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

bool ParameterImpl::stream_and_exception(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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


std::shared_ptr< Bag<uml::ParameterSet> > ParameterImpl::getParameterSet() const
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
std::shared_ptr<Union<uml::Element> > ParameterImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ParameterImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ParameterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PARAMETER_BEHAVIOR:
			return getBehavior(); //4428
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //444
		case UmlPackage::PARAMETER_DEFAULT:
			return getDefault(); //4420
		case UmlPackage::PARAMETER_DEFAULTVALUE:
			return getDefaultValue(); //4421
		case UmlPackage::PARAMETER_DIRECTION:
			return getDirection(); //4422
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //440
		case UmlPackage::PARAMETER_EFFECT:
			return getEffect(); //4423
		case UmlPackage::CONNECTABLEELEMENT_END:
			return getEnd(); //4413
		case UmlPackage::PARAMETER_ISEXCEPTION:
			return getIsException(); //4424
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //444
		case UmlPackage::PARAMETER_ISSTREAM:
			return getIsStream(); //4425
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //445
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //446
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //447
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //445
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //446
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //447
		case UmlPackage::PARAMETER_OPERATION:
			return getOperation(); //4426
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //441
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //442
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //443
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //444
		case UmlPackage::PARAMETER_PARAMETERSET:
			return getParameterSet(); //4427
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //448
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //445
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //4410
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //448
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //449
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //449
	}
	return boost::any();
}
