#include "uml/impl/InterfaceRealizationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/BehavioredClassifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Interface.hpp"

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
InterfaceRealizationImpl::InterfaceRealizationImpl()
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

InterfaceRealizationImpl::~InterfaceRealizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InterfaceRealization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::BehavioredClassifier > par_implementingClassifier)
			:InterfaceRealizationImpl()
			{
			    m_implementingClassifier = par_implementingClassifier;
			}





//Additional constructor for the containments back reference
			InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InterfaceRealizationImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Element > par_owner)
			:InterfaceRealizationImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:InterfaceRealizationImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:InterfaceRealizationImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






InterfaceRealizationImpl::InterfaceRealizationImpl(const InterfaceRealizationImpl & obj):InterfaceRealizationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InterfaceRealization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_implementingClassifier  = obj.getImplementingClassifier();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

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
		m_contract = std::dynamic_pointer_cast<uml::Interface>(obj.getContract()->copy());
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

std::shared_ptr<ecore::EObject>  InterfaceRealizationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new InterfaceRealizationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> InterfaceRealizationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInterfaceRealization();
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
std::shared_ptr<uml::Interface > InterfaceRealizationImpl::getContract() const
{
//assert(m_contract);
    return m_contract;
}
void InterfaceRealizationImpl::setContract(std::shared_ptr<uml::Interface> _contract)
{
    m_contract = _contract;
}

std::weak_ptr<uml::BehavioredClassifier > InterfaceRealizationImpl::getImplementingClassifier() const
{
//assert(m_implementingClassifier);
    return m_implementingClassifier;
}
void InterfaceRealizationImpl::setImplementingClassifier(std::shared_ptr<uml::BehavioredClassifier> _implementingClassifier)
{
    m_implementingClassifier = _implementingClassifier;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > InterfaceRealizationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > InterfaceRealizationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InterfaceRealizationImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > InterfaceRealizationImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > InterfaceRealizationImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > InterfaceRealizationImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ecore::EObject> InterfaceRealizationImpl::eContainer() const
{
	if(auto wp = m_implementingClassifier.lock())
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

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InterfaceRealizationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //10516
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1054
		case UmlPackage::INTERFACEREALIZATION_CONTRACT:
			return getContract(); //10519
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1050
		case UmlPackage::INTERFACEREALIZATION_IMPLEMENTINGCLASSIFIER:
			return getImplementingClassifier(); //10520
		case UmlPackage::ABSTRACTION_MAPPING:
			return getMapping(); //10518
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1055
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1056
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1057
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1051
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1052
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1053
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //10512
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1054
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1058
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //1054
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //1055
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //10517
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //1056
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1055
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1059
	}
	return boost::any();
}

void InterfaceRealizationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INTERFACEREALIZATION_CONTRACT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interface> _contract = boost::any_cast<std::shared_ptr<uml::Interface>>(newValue);
			setContract(_contract); //10519
			break;
		}
		case UmlPackage::INTERFACEREALIZATION_IMPLEMENTINGCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<uml::BehavioredClassifier> _implementingClassifier = boost::any_cast<std::shared_ptr<uml::BehavioredClassifier>>(newValue);
			setImplementingClassifier(_implementingClassifier); //10520
			break;
		}
		case UmlPackage::ABSTRACTION_MAPPING:
		{
			// BOOST CAST
			std::shared_ptr<uml::OpaqueExpression> _mapping = boost::any_cast<std::shared_ptr<uml::OpaqueExpression>>(newValue);
			setMapping(_mapping); //10518
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1055
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1056
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //10512
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //1054
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //1055
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1059
			break;
		}
	}
}
