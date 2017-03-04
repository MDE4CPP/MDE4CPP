#include "ParameterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
	
	
	m_parameterSet.reset(new std::vector<std::shared_ptr<uml::ParameterSet>>());
}

ParameterImpl::~ParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Parameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ParameterImpl::ParameterImpl(const ParameterImpl & obj)
{
	//create copy of all Attributes
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

	//copy references with now containment
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::Dependency>>> _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::ConnectorEnd>>> _end = obj.getEnd();
	this->getEnd()->insert(this->getEnd()->end(), _end->begin(), _end->end());

	m_namespace  = obj.getNamespace();

	m_operation  = obj.getOperation();

	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<std::vector<std::shared_ptr<uml::ParameterSet>>> _parameterSet = obj.getParameterSet();
	this->getParameterSet()->insert(this->getParameterSet()->end(), _parameterSet->begin(), _parameterSet->end());

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//clone containt lists
	if(obj.getDefaultValue()!=nullptr)
	{
		m_defaultValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getDefaultValue()->copy()));
	}
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAnnotation>>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getLowerValue()->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->push_back(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getUpperValue()->copy()));
	}
}

ecore::EObject *  ParameterImpl::copy() const
{
	return new ParameterImpl(*this);
}

std::shared_ptr<ecore::EClass> ParameterImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getParameter();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ParameterImpl::setDefault (std::string _default)
{
	m_default = _default;
} 

std::string ParameterImpl::getDefault() const 
{
	return m_default;
}

void ParameterImpl::setDirection (ParameterDirectionKind _direction)
{
	m_direction = _direction;
} 

ParameterDirectionKind ParameterImpl::getDirection() const 
{
	return m_direction;
}

void ParameterImpl::setEffect (ParameterEffectKind _effect)
{
	m_effect = _effect;
} 

ParameterEffectKind ParameterImpl::getEffect() const 
{
	return m_effect;
}

void ParameterImpl::setIsException (bool _isException)
{
	m_isException = _isException;
} 

bool ParameterImpl::getIsException() const 
{
	return m_isException;
}

void ParameterImpl::setIsStream (bool _isStream)
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
std::shared_ptr<uml::ValueSpecification> ParameterImpl::getDefaultValue() const
{

    return m_defaultValue;
}
void ParameterImpl::setDefaultValue(std::shared_ptr<uml::ValueSpecification> _defaultValue)
{
    m_defaultValue = _defaultValue;
}

std::shared_ptr<uml::Operation> ParameterImpl::getOperation() const
{

    return m_operation;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::ParameterSet>>> ParameterImpl::getParameterSet() const
{

    return m_parameterSet;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> ParameterImpl::getOwnedElement() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement(new std::vector<std::shared_ptr<uml::Element>>()) ;
	
	_ownedElement->push_back(getDefaultValue());
	_ownedElement->push_back(getLowerValue());
	_ownedElement->push_back(getNameExpression());
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> ownedComment = getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());
	_ownedElement->push_back(getUpperValue());

	return _ownedElement;
}
std::shared_ptr<uml::Namespace> ParameterImpl::getNamespace() const
{
	std::shared_ptr<uml::Namespace> _namespace = nullptr ;
	
	if(getOperation()!=nullptr)
	{
		_namespace = getOperation();
	}

	return _namespace;
}
std::shared_ptr<uml::Element> ParameterImpl::getOwner() const
{
	std::shared_ptr<uml::Element> _owner = nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}
	if(getOwningTemplateParameter()!=nullptr)
	{
		_owner = getOwningTemplateParameter();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ParameterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
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
