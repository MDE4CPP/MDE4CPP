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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		/*Subset*/
		m_fragment.reset(new Subset<uml::InteractionFragment, uml::NamedElement >(m_ownedMember));//(m_ownedMember));
	
	
	
}

InteractionOperandImpl::~InteractionOperandImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionOperand "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

InteractionOperandImpl::InteractionOperandImpl(const InteractionOperandImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

		std::shared_ptr< Bag<uml::Lifeline> >
	 _covered = obj.getCovered();
	m_covered.reset(new 	 Bag<uml::Lifeline> 
	(*(obj.getCovered().get())));// this->getCovered()->insert(this->getCovered()->end(), _covered->begin(), _covered->end());

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

			std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement > >
	 _importedMember = obj.getImportedMember();
	m_importedMember.reset(new 		Subset<uml::PackageableElement, uml::NamedElement > 
	(*(obj.getImportedMember().get())));// this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

			std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new 		Union<uml::NamedElement> (*(obj.getMember().get())));// this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > >
	 _ownedMember = obj.getOwnedMember();
	m_ownedMember.reset(new 		SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > 
	(*(obj.getOwnedMember().get())));// this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());

	m_owner  = obj.getOwner();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
	}
	std::shared_ptr<Bag<uml::InteractionFragment>> _fragmentList = obj.getFragment();
	for(std::shared_ptr<uml::InteractionFragment> _fragment : *_fragmentList)
	{
		this->getFragment()->add(std::shared_ptr<uml::InteractionFragment>(dynamic_cast<uml::InteractionFragment*>(_fragment->copy())));
	}
	std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrderingList = obj.getGeneralOrdering();
	for(std::shared_ptr<uml::GeneralOrdering> _generalOrdering : *_generalOrderingList)
	{
		this->getGeneralOrdering()->add(std::shared_ptr<uml::GeneralOrdering>(dynamic_cast<uml::GeneralOrdering*>(_generalOrdering->copy())));
	}
	if(obj.getGuard()!=nullptr)
	{
		m_guard.reset(dynamic_cast<uml::InteractionConstraint*>(obj.getGuard()->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
}

ecore::EObject *  InteractionOperandImpl::copy() const
{
	return new InteractionOperandImpl(*this);
}

std::shared_ptr<ecore::EClass> InteractionOperandImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionOperand();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 InteractionOperandImpl::guard_contain_references(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InteractionOperandImpl::guard_directly_prior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
		std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement > >
 InteractionOperandImpl::getFragment() const
{

    return m_fragment;
}


std::shared_ptr<uml::InteractionConstraint > InteractionOperandImpl::getGuard() const
{

    return m_guard;
}
void InteractionOperandImpl::setGuard(std::shared_ptr<uml::InteractionConstraint> _guard)
{
    m_guard = _guard;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 InteractionOperandImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}
std::shared_ptr<uml::Element > InteractionOperandImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > InteractionOperandImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::NamedElement> > InteractionOperandImpl::getMember() const
{
	

	return m_member;
}
std::shared_ptr<uml::Namespace > InteractionOperandImpl::getNamespace() const
{
	

	return m_namespace;
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
