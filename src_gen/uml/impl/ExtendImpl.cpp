#include "ExtendImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExtendImpl::ExtendImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	
	if( m_extensionLocation == nullptr)
	{
		m_extensionLocation = new std::vector<uml::ExtensionPoint * >();
	}
}

ExtendImpl::~ExtendImpl()
{
	if(m_condition!=nullptr)
	{
		if(m_condition)
		{
			delete(m_condition);
			m_condition = nullptr;
		}
	}
	if(m_extensionLocation!=nullptr)
	{
		delete(m_extensionLocation);
	 	m_extensionLocation = nullptr;
	}
	
}

ExtendImpl::ExtendImpl(const ExtendImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_extendedCase  = obj.getExtendedCase();

	m_extension  = obj.getExtension();

	std::vector<uml::ExtensionPoint * > *  _extensionLocation = obj.getExtensionLocation();
	this->getExtensionLocation()->insert(this->getExtensionLocation()->end(), _extensionLocation->begin(), _extensionLocation->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::Element * > *  _relatedElement = obj.getRelatedElement();
	this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());
	delete(_relatedElement);

	std::vector<uml::Element * > *  _source = obj.getSource();
	this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());
	delete(_source);

	std::vector<uml::Element * > *  _target = obj.getTarget();
	this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());
	delete(_target);


	//clone containt lists
	if(obj.getCondition()!=nullptr)
	{
		m_condition = dynamic_cast<uml::Constraint * >(obj.getCondition()->copy());
	}
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

ecore::EObject *  ExtendImpl::copy() const
{
	return new ExtendImpl(*this);
}

ecore::EClass* ExtendImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExtend();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ExtendImpl::extension_points(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Constraint *  ExtendImpl::getCondition() const
{
	
	return m_condition;
}
void ExtendImpl::setCondition(uml::Constraint *  _condition)
{
	m_condition = _condition;
}

uml::UseCase *  ExtendImpl::getExtendedCase() const
{
	//assert(m_extendedCase);
	return m_extendedCase;
}
void ExtendImpl::setExtendedCase(uml::UseCase *  _extendedCase)
{
	m_extendedCase = _extendedCase;
}

uml::UseCase *  ExtendImpl::getExtension() const
{
	//assert(m_extension);
	return m_extension;
}
void ExtendImpl::setExtension(uml::UseCase *  _extension)
{
	m_extension = _extension;
}

std::vector<uml::ExtensionPoint * > *  ExtendImpl::getExtensionLocation() const
{
	//assert(m_extensionLocation);
	return m_extensionLocation;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ExtendImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	_source->push_back(getExtension());

	return _source;
}
uml::Element *  ExtendImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::Element * > *  ExtendImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	_target->push_back(getExtendedCase());

	return _target;
}
uml::Namespace *  ExtendImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getExtension()!=nullptr)
	{
		_namespace = getExtension();
	}

	return _namespace;
}
std::vector<uml::Element * > *  ExtendImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getCondition());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
std::vector<uml::Element * > *  ExtendImpl::getRelatedElement() const
{
	std::vector<uml::Element * > *  _relatedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  source = (std::vector<uml::Element * > * ) getSource();
	_relatedElement->insert(_relatedElement->end(), source->begin(), source->end());

	delete(source);
	std::vector<uml::Element * > *  target = (std::vector<uml::Element * > * ) getTarget();
	_relatedElement->insert(_relatedElement->end(), target->begin(), target->end());

	delete(target);

	return _relatedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExtendImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //994
		case UmlPackage::EXTEND_CONDITION:
			return getCondition(); //9913
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //990
		case UmlPackage::EXTEND_EXTENDEDCASE:
			return getExtendedCase(); //9914
		case UmlPackage::EXTEND_EXTENSION:
			return getExtension(); //9916
		case UmlPackage::EXTEND_EXTENSIONLOCATION:
			return getExtensionLocation(); //9915
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //995
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //996
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //997
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //991
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //992
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //993
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //998
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //994
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //995
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //996
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //999
	}
	return boost::any();
}
