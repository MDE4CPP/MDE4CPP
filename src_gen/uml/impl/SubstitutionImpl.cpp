#include "uml/impl/SubstitutionImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/OpaqueExpression.hpp"

#include "uml/Package.hpp"

#include "uml/Realization.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"


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
			SubstitutionImpl::SubstitutionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:SubstitutionImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			SubstitutionImpl::SubstitutionImpl(std::weak_ptr<uml::Element > par_owner)
			:SubstitutionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			SubstitutionImpl::SubstitutionImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:SubstitutionImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			SubstitutionImpl::SubstitutionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:SubstitutionImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
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

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_substitutingClassifier  = obj.getSubstitutingClassifier();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::NamedElement>> _clientList = obj.getClient();
	for(std::shared_ptr<uml::NamedElement> _client : *_clientList)
	{
		this->getClient()->add(std::shared_ptr<uml::NamedElement>(std::dynamic_pointer_cast<uml::NamedElement>(_client->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_client" << std::endl;
	#endif
	if(obj.getContract()!=nullptr)
	{
		m_contract = std::dynamic_pointer_cast<uml::Classifier>(obj.getContract()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_contract" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getMapping()!=nullptr)
	{
		m_mapping = std::dynamic_pointer_cast<uml::OpaqueExpression>(obj.getMapping()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_mapping" << std::endl;
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
	std::shared_ptr<Bag<uml::NamedElement>> _supplierList = obj.getSupplier();
	for(std::shared_ptr<uml::NamedElement> _supplier : *_supplierList)
	{
		this->getSupplier()->add(std::shared_ptr<uml::NamedElement>(std::dynamic_pointer_cast<uml::NamedElement>(_supplier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_supplier" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  SubstitutionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new SubstitutionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> SubstitutionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getSubstitution_EClass();
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
std::weak_ptr<uml::Namespace > SubstitutionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > SubstitutionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > SubstitutionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > SubstitutionImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > SubstitutionImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > SubstitutionImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ecore::EObject> SubstitutionImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	if(auto wp = m_substitutingClassifier.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any SubstitutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_EREFERENCE_CLIENT:
			return getClient(); //10216
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //1024
		case UmlPackage::SUBSTITUTION_EREFERENCE_CONTRACT:
			return getContract(); //10219
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //1020
		case UmlPackage::ABSTRACTION_EREFERENCE_MAPPING:
			return getMapping(); //10218
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //1025
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //1026
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //1027
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //1021
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //1022
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //1023
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //10212
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1024
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //1028
		case UmlPackage::RELATIONSHIP_EREFERENCE_RELATEDELEMENT:
			return getRelatedElement(); //1024
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_SOURCE:
			return getSource(); //1025
		case UmlPackage::SUBSTITUTION_EREFERENCE_SUBSTITUTINGCLASSIFIER:
			return getSubstitutingClassifier(); //10220
		case UmlPackage::DEPENDENCY_EREFERENCE_SUPPLIER:
			return getSupplier(); //10217
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_TARGET:
			return getTarget(); //1026
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1025
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //1029
	}
	return boost::any();
}

void SubstitutionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::SUBSTITUTION_EREFERENCE_CONTRACT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Classifier> _contract = boost::any_cast<std::shared_ptr<uml::Classifier>>(newValue);
			setContract(_contract); //10219
			break;
		}
		case UmlPackage::ABSTRACTION_EREFERENCE_MAPPING:
		{
			// BOOST CAST
			std::shared_ptr<uml::OpaqueExpression> _mapping = boost::any_cast<std::shared_ptr<uml::OpaqueExpression>>(newValue);
			setMapping(_mapping); //10218
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1025
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1026
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //10212
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //1024
			break;
		}
		case UmlPackage::SUBSTITUTION_EREFERENCE_SUBSTITUTINGCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<uml::Classifier> _substitutingClassifier = boost::any_cast<std::shared_ptr<uml::Classifier>>(newValue);
			setSubstitutingClassifier(_substitutingClassifier); //10220
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //1025
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1029
			break;
		}
	}
}
