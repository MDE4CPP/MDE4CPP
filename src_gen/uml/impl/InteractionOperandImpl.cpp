#include "InteractionOperandImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Constraint.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "ElementImport.hpp"

#include "GeneralOrdering.hpp"

#include "Interaction.hpp"

#include "InteractionConstraint.hpp"

#include "InteractionFragment.hpp"

#include "InteractionOperand.hpp"

#include "Lifeline.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "PackageImport.hpp"

#include "PackageableElement.hpp"

#include "StringExpression.hpp"


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
	//References
		/*Subset*/
		m_fragment.reset(new Subset<uml::InteractionFragment, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >()" << std::endl;
		#endif
	
	

	

	//Init references
		/*Subset*/
		m_fragment->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

	
}

InteractionOperandImpl::~InteractionOperandImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionOperand "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			InteractionOperandImpl::InteractionOperandImpl(std::shared_ptr<uml::Namespace > par_namespace)
			:InteractionOperandImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			InteractionOperandImpl::InteractionOperandImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:InteractionOperandImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			InteractionOperandImpl::InteractionOperandImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:InteractionOperandImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
			}






InteractionOperandImpl::InteractionOperandImpl(const InteractionOperandImpl & obj):InteractionOperandImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionOperand "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::Lifeline> > _covered = obj.getCovered();
	m_covered.reset(new Bag<uml::Lifeline>(*(obj.getCovered().get())));

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_owner  = obj.getOwner();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InteractionFragment>> _fragmentList = obj.getFragment();
	for(std::shared_ptr<uml::InteractionFragment> _fragment : *_fragmentList)
	{
		this->getFragment()->add(std::shared_ptr<uml::InteractionFragment>(dynamic_cast<uml::InteractionFragment*>(_fragment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_fragment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrderingList = obj.getGeneralOrdering();
	for(std::shared_ptr<uml::GeneralOrdering> _generalOrdering : *_generalOrderingList)
	{
		this->getGeneralOrdering()->add(std::shared_ptr<uml::GeneralOrdering>(dynamic_cast<uml::GeneralOrdering*>(_generalOrdering->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalOrdering" << std::endl;
	#endif
	if(obj.getGuard()!=nullptr)
	{
		m_guard.reset(dynamic_cast<uml::InteractionConstraint*>(obj.getGuard()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_guard" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(dynamic_cast<uml::PackageableElement*>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif

		/*Subset*/
		m_fragment->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

	

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
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionOperandImpl::guard_contain_references(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionOperandImpl::guard_directly_prior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement > > InteractionOperandImpl::getFragment() const
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
std::shared_ptr<uml::Namespace > InteractionOperandImpl::getNamespace() const
{
	return m_namespace;
}
std::weak_ptr<uml::Element > InteractionOperandImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > InteractionOperandImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::shared_ptr<Union<uml::NamedElement> > InteractionOperandImpl::getMember() const
{
	return m_member;
}
std::shared_ptr<Union<uml::Element> > InteractionOperandImpl::getOwnedElement() const
{
	return m_ownedElement;
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
