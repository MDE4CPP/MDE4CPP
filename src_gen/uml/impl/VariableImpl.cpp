#include "VariableImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
VariableImpl::VariableImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

VariableImpl::~VariableImpl()
{
	
}

VariableImpl::VariableImpl(const VariableImpl & obj)
{
	//create copy of all Attributes
	m_isOrdered = obj.getIsOrdered();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_upper = obj.getUpper();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_activityScope  = obj.getActivityScope();

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::ConnectorEnd * > *  _end = obj.getEnd();
	this->getEnd()->insert(this->getEnd()->end(), _end->begin(), _end->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_scope  = obj.getScope();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = dynamic_cast<uml::ValueSpecification * >(obj.getLowerValue()->copy());
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = dynamic_cast<uml::ValueSpecification * >(obj.getUpperValue()->copy());
	}
}

ecore::EObject *  VariableImpl::copy() const
{
	return new VariableImpl(*this);
}

ecore::EClass* VariableImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getVariable();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool VariableImpl::isAccessibleBy(uml::Action *  a) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Activity *  VariableImpl::getActivityScope() const
{
	
	return m_activityScope;
}
void VariableImpl::setActivityScope(uml::Activity *  _activityScope)
{
	m_activityScope = _activityScope;
}

uml::StructuredActivityNode *  VariableImpl::getScope() const
{
	
	return m_scope;
}
void VariableImpl::setScope(uml::StructuredActivityNode *  _scope)
{
	m_scope = _scope;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  VariableImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
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
uml::Namespace *  VariableImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getActivityScope()!=nullptr)
	{
		_namespace = getActivityScope();
	}
	if(getScope()!=nullptr)
	{
		_namespace = getScope();
	}

	return _namespace;
}
std::vector<uml::Element * > *  VariableImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getLowerValue());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getUpperValue());

	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any VariableImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::VARIABLE_ACTIVITYSCOPE:
			return getActivityScope(); //12120
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1214
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1210
		case UmlPackage::CONNECTABLEELEMENT_END:
			return getEnd(); //12113
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //1214
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //1215
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //1216
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //1217
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1215
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1216
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1217
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1211
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1212
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1213
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1214
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1218
		case UmlPackage::VARIABLE_SCOPE:
			return getScope(); //12121
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1215
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //12110
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //1218
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //1219
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1219
	}
	return boost::any();
}
