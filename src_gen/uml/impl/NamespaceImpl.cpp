#include "NamespaceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
NamespaceImpl::NamespaceImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_elementImport == nullptr)
	{
		m_elementImport = new std::vector<uml::ElementImport * >();
	}
	if( m_importedMember == nullptr)
	{
		m_importedMember = new std::vector<uml::PackageableElement * >();
	}
	if( m_member == nullptr)
	{
		m_member = new std::vector<uml::NamedElement * >();
	}
	if( m_ownedMember == nullptr)
	{
		m_ownedMember = new std::vector<uml::NamedElement * >();
	}
	if( m_ownedRule == nullptr)
	{
		m_ownedRule = new std::vector<uml::Constraint * >();
	}
	if( m_packageImport == nullptr)
	{
		m_packageImport = new std::vector<uml::PackageImport * >();
	}
}

NamespaceImpl::~NamespaceImpl()
{
	if(m_ownedRule!=nullptr)
	{
		for(auto c :*m_ownedRule)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_elementImport!=nullptr)
	{
		for(auto c :*m_elementImport)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_packageImport!=nullptr)
	{
		for(auto c :*m_packageImport)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_ownedMember!=nullptr)
	{
		delete(m_ownedMember);
	 	m_ownedMember = nullptr;
	}
	if(m_importedMember!=nullptr)
	{
		delete(m_importedMember);
	 	m_importedMember = nullptr;
	}
	if(m_member!=nullptr)
	{
		delete(m_member);
	 	m_member = nullptr;
	}
	
}

NamespaceImpl::NamespaceImpl(const NamespaceImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::PackageableElement * > *  _importedMember = obj.getImportedMember();
	this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	std::vector<uml::NamedElement * > *  _member = obj.getMember();
	this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());
	delete(_member);

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	std::vector<uml::NamedElement * > *  _ownedMember = obj.getOwnedMember();
	this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());
	delete(_ownedMember);

	m_owner  = obj.getOwner();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::ElementImport * 	_elementImport : *obj.getElementImport())
	{
		this->getElementImport()->push_back(dynamic_cast<uml::ElementImport * >(_elementImport->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::Constraint * 	_ownedRule : *obj.getOwnedRule())
	{
		this->getOwnedRule()->push_back(dynamic_cast<uml::Constraint * >(_ownedRule->copy()));
	}
	for(uml::PackageImport * 	_packageImport : *obj.getPackageImport())
	{
		this->getPackageImport()->push_back(dynamic_cast<uml::PackageImport * >(_packageImport->copy()));
	}
}

ecore::EObject *  NamespaceImpl::copy() const
{
	return new NamespaceImpl(*this);
}

ecore::EClass* NamespaceImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getNamespace();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool NamespaceImpl::cannot_import_ownedMembers(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamespaceImpl::cannot_import_self(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::ElementImport *  NamespaceImpl::createElementImport(uml::PackageableElement *  element,VisibilityKind visibility) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::PackageImport *  NamespaceImpl::createPackageImport(uml::Package *  package_,VisibilityKind visibility) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::PackageableElement * > *  NamespaceImpl::excludeCollisions(std::vector<uml::PackageableElement * > *  imps) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::PackageableElement * > *  NamespaceImpl::getImportedElements() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::PackageableElement * > *  NamespaceImpl::getImportedMembers() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Package * > *  NamespaceImpl::getImportedPackages() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<std::string> *  NamespaceImpl::getNamesOfMember(uml::NamedElement *  element) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::NamedElement * > *  NamespaceImpl::getOwnedMembers() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::PackageableElement * > *  NamespaceImpl::importMembers(std::vector<uml::PackageableElement * > *  imps) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamespaceImpl::membersAreDistinguishable() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamespaceImpl::members_distinguishable(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::ElementImport * > *  NamespaceImpl::getElementImport() const
{
	
	return m_elementImport;
}


std::vector<uml::PackageableElement * > *  NamespaceImpl::getImportedMember() const
{
	
	return m_importedMember;
}








std::vector<uml::Constraint * > *  NamespaceImpl::getOwnedRule() const
{
	
	return m_ownedRule;
}


std::vector<uml::PackageImport * > *  NamespaceImpl::getPackageImport() const
{
	
	return m_packageImport;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  NamespaceImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedMember = (std::vector<uml::Element * > * ) getOwnedMember();
	_ownedElement->insert(_ownedElement->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);
	std::vector<uml::Element * > *  packageImport = (std::vector<uml::Element * > * ) getPackageImport();
	_ownedElement->insert(_ownedElement->end(), packageImport->begin(), packageImport->end());


	return _ownedElement;
}
uml::Element *  NamespaceImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::NamedElement * > *  NamespaceImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());


	return _ownedMember;
}
std::vector<uml::NamedElement * > *  NamespaceImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any NamespaceImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //64
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //60
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //611
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //614
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //615
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //65
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //66
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //67
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //61
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //62
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //613
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //610
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //63
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //612
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //68
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //69
	}
	return boost::any();
}
