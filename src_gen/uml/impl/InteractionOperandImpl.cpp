#include "uml/impl/InteractionOperandImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/GeneralOrdering.hpp"

#include "uml/Interaction.hpp"

#include "uml/InteractionConstraint.hpp"

#include "uml/InteractionFragment.hpp"

#include "uml/InteractionOperand.hpp"

#include "uml/Lifeline.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/StringExpression.hpp"


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





//Additional constructor for the containments back reference
			InteractionOperandImpl::InteractionOperandImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InteractionOperandImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			InteractionOperandImpl::InteractionOperandImpl(std::weak_ptr<uml::Element > par_owner)
			:InteractionOperandImpl()
			{
			    m_owner = par_owner;
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

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InteractionFragment>> _fragmentList = obj.getFragment();
	for(std::shared_ptr<uml::InteractionFragment> _fragment : *_fragmentList)
	{
		this->getFragment()->add(std::shared_ptr<uml::InteractionFragment>(std::dynamic_pointer_cast<uml::InteractionFragment>(_fragment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_fragment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrderingList = obj.getGeneralOrdering();
	for(std::shared_ptr<uml::GeneralOrdering> _generalOrdering : *_generalOrderingList)
	{
		this->getGeneralOrdering()->add(std::shared_ptr<uml::GeneralOrdering>(std::dynamic_pointer_cast<uml::GeneralOrdering>(_generalOrdering->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalOrdering" << std::endl;
	#endif
	if(obj.getGuard()!=nullptr)
	{
		m_guard = std::dynamic_pointer_cast<uml::InteractionConstraint>(obj.getGuard()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_guard" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
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
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
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

std::shared_ptr<ecore::EObject>  InteractionOperandImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new InteractionOperandImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> InteractionOperandImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionOperand_EClass();
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
std::shared_ptr<Union<uml::NamedElement> > InteractionOperandImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > InteractionOperandImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > InteractionOperandImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > InteractionOperandImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > InteractionOperandImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> InteractionOperandImpl::eContainer() const
{
	if(auto wp = m_enclosingInteraction.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingOperand.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InteractionOperandImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //2184
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_COVERED:
			return getCovered(); //21810
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //2180
		case UmlPackage::NAMESPACE_EREFERENCE_ELEMENTIMPORT:
			return getElementImport(); //21811
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //21812
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //21811
		case UmlPackage::INTERACTIONOPERAND_EREFERENCE_FRAGMENT:
			return getFragment(); //21820
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_GENERALORDERING:
			return getGeneralOrdering(); //21813
		case UmlPackage::INTERACTIONOPERAND_EREFERENCE_GUARD:
			return getGuard(); //21821
		case UmlPackage::NAMESPACE_EREFERENCE_IMPORTEDMEMBER:
			return getImportedMember(); //21814
		case UmlPackage::NAMESPACE_EREFERENCE_MEMBER:
			return getMember(); //21815
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //2185
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //2186
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //2187
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //2181
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //2182
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDMEMBER:
			return getOwnedMember(); //21813
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDRULE:
			return getOwnedRule(); //21810
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //2183
		case UmlPackage::NAMESPACE_EREFERENCE_PACKAGEIMPORT:
			return getPackageImport(); //21812
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //2188
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //2189
	}
	return boost::any();
}

void InteractionOperandImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _enclosingInteraction = boost::any_cast<std::shared_ptr<uml::Interaction>>(newValue);
			setEnclosingInteraction(_enclosingInteraction); //21812
			break;
		}
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
		{
			// BOOST CAST
			std::shared_ptr<uml::InteractionOperand> _enclosingOperand = boost::any_cast<std::shared_ptr<uml::InteractionOperand>>(newValue);
			setEnclosingOperand(_enclosingOperand); //21811
			break;
		}
		case UmlPackage::INTERACTIONOPERAND_EREFERENCE_GUARD:
		{
			// BOOST CAST
			std::shared_ptr<uml::InteractionConstraint> _guard = boost::any_cast<std::shared_ptr<uml::InteractionConstraint>>(newValue);
			setGuard(_guard); //21821
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2185
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2186
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2189
			break;
		}
	}
}
