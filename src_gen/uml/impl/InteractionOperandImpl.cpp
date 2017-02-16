#include "InteractionOperandImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionOperandImpl::InteractionOperandImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_fragment == nullptr)
	{
		m_fragment = new std::vector<uml::InteractionFragment * >();
	}
	
}

InteractionOperandImpl::~InteractionOperandImpl()
{
	if(m_fragment!=nullptr)
	{
		for(auto c :*m_fragment)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_guard!=nullptr)
	{
		if(m_guard)
		{
			delete(m_guard);
			m_guard = nullptr;
		}
	}
	
}

InteractionOperandImpl::InteractionOperandImpl(const InteractionOperandImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::Lifeline * > *  _covered = obj.getCovered();
	this->getCovered()->insert(this->getCovered()->end(), _covered->begin(), _covered->end());

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

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
	for(uml::InteractionFragment * 	_fragment : *obj.getFragment())
	{
		this->getFragment()->push_back(dynamic_cast<uml::InteractionFragment * >(_fragment->copy()));
	}
	for(uml::GeneralOrdering * 	_generalOrdering : *obj.getGeneralOrdering())
	{
		this->getGeneralOrdering()->push_back(dynamic_cast<uml::GeneralOrdering * >(_generalOrdering->copy()));
	}
	if(obj.getGuard()!=nullptr)
	{
		m_guard = dynamic_cast<uml::InteractionConstraint * >(obj.getGuard()->copy());
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

ecore::EObject *  InteractionOperandImpl::copy() const
{
	return new InteractionOperandImpl(*this);
}

ecore::EClass* InteractionOperandImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionOperand();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionOperandImpl::guard_contain_references(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionOperandImpl::guard_directly_prior(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::InteractionFragment * > *  InteractionOperandImpl::getFragment() const
{
	
	return m_fragment;
}


uml::InteractionConstraint *  InteractionOperandImpl::getGuard() const
{
	
	return m_guard;
}
void InteractionOperandImpl::setGuard(uml::InteractionConstraint *  _guard)
{
	m_guard = _guard;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  InteractionOperandImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	std::vector<uml::Element * > *  generalOrdering = (std::vector<uml::Element * > * ) getGeneralOrdering();
	_ownedElement->insert(_ownedElement->end(), generalOrdering->begin(), generalOrdering->end());

	_ownedElement->push_back(getGuard());
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
uml::Element *  InteractionOperandImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::NamedElement * > *  InteractionOperandImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
uml::Namespace *  InteractionOperandImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getEnclosingInteraction()!=nullptr)
	{
		_namespace = getEnclosingInteraction();
	}
	if(getEnclosingOperand()!=nullptr)
	{
		_namespace = getEnclosingOperand();
	}

	return _namespace;
}
std::vector<uml::NamedElement * > *  InteractionOperandImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  fragment = (std::vector<uml::NamedElement * > * ) getFragment();
	_ownedMember->insert(_ownedMember->end(), fragment->begin(), fragment->end());

	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());


	return _ownedMember;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InteractionOperandImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2184
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //21810
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2180
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //21811
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //21812
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //21811
		case UmlPackage::INTERACTIONOPERAND_FRAGMENT:
			return getFragment(); //21820
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //21813
		case UmlPackage::INTERACTIONOPERAND_GUARD:
			return getGuard(); //21821
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //21814
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //21815
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2185
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2186
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2187
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2181
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2182
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //21813
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //21810
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2183
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //21812
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2188
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2189
	}
	return boost::any();
}
