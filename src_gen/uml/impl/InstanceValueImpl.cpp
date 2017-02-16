#include "InstanceValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InstanceValueImpl::InstanceValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

InstanceValueImpl::~InstanceValueImpl()
{
	
}

InstanceValueImpl::InstanceValueImpl(const InstanceValueImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_instance  = obj.getInstance();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  InstanceValueImpl::copy() const
{
	return new InstanceValueImpl(*this);
}

ecore::EClass* InstanceValueImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInstanceValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
uml::InstanceSpecification *  InstanceValueImpl::getInstance() const
{
	//assert(m_instance);
	return m_instance;
}
void InstanceValueImpl::setInstance(uml::InstanceSpecification *  _instance)
{
	m_instance = _instance;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  InstanceValueImpl::getOwner() const
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
std::vector<uml::Element * > *  InstanceValueImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InstanceValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1944
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1940
		case UmlPackage::INSTANCEVALUE_INSTANCE:
			return getInstance(); //19413
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1945
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1946
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1947
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1941
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1942
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1943
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1944
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1948
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1945
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //19410
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1949
	}
	return boost::any();
}
