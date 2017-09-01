#include "SubstitutionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Classifier.hpp"

#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "OpaqueExpression.hpp"

#include "Realization.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
SubstitutionImpl::SubstitutionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	//Init references
	

	
}

SubstitutionImpl::~SubstitutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Substitution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			SubstitutionImpl::SubstitutionImpl(std::weak_ptr<uml::Classifier > par_substitutingClassifier)
			:SubstitutionImpl()
			{
			    m_substitutingClassifier = par_substitutingClassifier;
			}






SubstitutionImpl::SubstitutionImpl(const SubstitutionImpl & obj):SubstitutionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Substitution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_substitutingClassifier  = obj.getSubstitutingClassifier();

	m_templateParameter  = obj.getTemplateParameter();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::NamedElement>> _clientList = obj.getClient();
	for(std::shared_ptr<uml::NamedElement> _client : *_clientList)
	{
		this->getClient()->add(std::shared_ptr<uml::NamedElement>(dynamic_cast<uml::NamedElement*>(_client->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_client" << std::endl;
	#endif
	if(obj.getContract()!=nullptr)
	{
		m_contract.reset(dynamic_cast<uml::Classifier*>(obj.getContract()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_contract" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getMapping()!=nullptr)
	{
		m_mapping.reset(dynamic_cast<uml::OpaqueExpression*>(obj.getMapping()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_mapping" << std::endl;
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
	std::shared_ptr<Bag<uml::NamedElement>> _supplierList = obj.getSupplier();
	for(std::shared_ptr<uml::NamedElement> _supplier : *_supplierList)
	{
		this->getSupplier()->add(std::shared_ptr<uml::NamedElement>(dynamic_cast<uml::NamedElement*>(_supplier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_supplier" << std::endl;
	#endif


}

ecore::EObject *  SubstitutionImpl::copy() const
{
	return new SubstitutionImpl(*this);
}

std::shared_ptr<ecore::EClass> SubstitutionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getSubstitution();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::Classifier > SubstitutionImpl::getContract() const
{
//assert(m_contract);
    return m_contract;
}
void SubstitutionImpl::setContract(std::shared_ptr<uml::Classifier> _contract)
{
    m_contract = _contract;
}

std::weak_ptr<uml::Classifier > SubstitutionImpl::getSubstitutingClassifier() const
{
//assert(m_substitutingClassifier);
    return m_substitutingClassifier;
}
void SubstitutionImpl::setSubstitutingClassifier(std::shared_ptr<uml::Classifier> _substitutingClassifier)
{
    m_substitutingClassifier = _substitutingClassifier;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > SubstitutionImpl::getTarget() const
{
	return m_target;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > SubstitutionImpl::getSource() const
{
	return m_source;
}
std::weak_ptr<uml::Element > SubstitutionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > SubstitutionImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<Union<uml::Element> > SubstitutionImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any SubstitutionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //10215
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1024
		case UmlPackage::SUBSTITUTION_CONTRACT:
			return getContract(); //10218
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1020
		case UmlPackage::ABSTRACTION_MAPPING:
			return getMapping(); //10217
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1025
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1026
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1027
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1021
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1022
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1023
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1024
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1028
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //1024
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //1025
		case UmlPackage::SUBSTITUTION_SUBSTITUTINGCLASSIFIER:
			return getSubstitutingClassifier(); //10219
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //10216
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //1026
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1025
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1029
	}
	return boost::any();
}
