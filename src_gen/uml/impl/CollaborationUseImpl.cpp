#include "CollaborationUseImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
CollaborationUseImpl::CollaborationUseImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_roleBinding == nullptr)
	{
		m_roleBinding = new std::vector<uml::Dependency * >();
	}
	
}

CollaborationUseImpl::~CollaborationUseImpl()
{
	if(m_roleBinding!=nullptr)
	{
		for(auto c :*m_roleBinding)
		{
			delete(c);
			c = 0;
		}
	}
	
}

CollaborationUseImpl::CollaborationUseImpl(const CollaborationUseImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

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
	for(uml::Dependency * 	_roleBinding : *obj.getRoleBinding())
	{
		this->getRoleBinding()->push_back(dynamic_cast<uml::Dependency * >(_roleBinding->copy()));
	}
}

ecore::EObject *  CollaborationUseImpl::copy() const
{
	return new CollaborationUseImpl(*this);
}

ecore::EClass* CollaborationUseImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getCollaborationUse();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool CollaborationUseImpl::client_elements(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CollaborationUseImpl::connectors(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CollaborationUseImpl::every_role(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Dependency * > *  CollaborationUseImpl::getRoleBinding() const
{
	
	return m_roleBinding;
}


uml::Collaboration *  CollaborationUseImpl::getType() const
{
	//assert(m_type);
	return m_type;
}
void CollaborationUseImpl::setType(uml::Collaboration *  _type)
{
	m_type = _type;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  CollaborationUseImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  roleBinding = (std::vector<uml::Element * > * ) getRoleBinding();
	_ownedElement->insert(_ownedElement->end(), roleBinding->begin(), roleBinding->end());


	return _ownedElement;
}
uml::Element *  CollaborationUseImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any CollaborationUseImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //904
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //900
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //905
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //906
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //907
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //901
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //902
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //903
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //908
		case UmlPackage::COLLABORATIONUSE_ROLEBINDING:
			return getRoleBinding(); //9010
		case UmlPackage::COLLABORATIONUSE_TYPE:
			return getType(); //9011
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //909
	}
	return boost::any();
}
