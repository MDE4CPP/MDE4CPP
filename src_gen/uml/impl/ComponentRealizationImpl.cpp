#include "uml/impl/ComponentRealizationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Component.hpp"

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
ComponentRealizationImpl::ComponentRealizationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		/*Subset*/
		m_realizingClassifier.reset(new Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_realizingClassifier - Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

	//Init references
	

		/*Subset*/
		m_realizingClassifier->initSubset(m_client);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_realizingClassifier - Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >(m_client)" << std::endl;
		#endif
	
	
}

ComponentRealizationImpl::~ComponentRealizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ComponentRealization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Component > par_abstraction)
			:ComponentRealizationImpl()
			{
			    m_abstraction = par_abstraction;
			}





//Additional constructor for the containments back reference
			ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ComponentRealizationImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Element > par_owner)
			:ComponentRealizationImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:ComponentRealizationImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ComponentRealizationImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






ComponentRealizationImpl::ComponentRealizationImpl(const ComponentRealizationImpl & obj):ComponentRealizationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ComponentRealization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_abstraction  = obj.getAbstraction();

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

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
	std::shared_ptr<Bag<uml::Classifier>> _realizingClassifierList = obj.getRealizingClassifier();
	for(std::shared_ptr<uml::Classifier> _realizingClassifier : *_realizingClassifierList)
	{
		this->getRealizingClassifier()->add(std::shared_ptr<uml::Classifier>(std::dynamic_pointer_cast<uml::Classifier>(_realizingClassifier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_realizingClassifier" << std::endl;
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

std::shared_ptr<ecore::EObject>  ComponentRealizationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ComponentRealizationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ComponentRealizationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getComponentRealization();
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
std::weak_ptr<uml::Component > ComponentRealizationImpl::getAbstraction() const
{

    return m_abstraction;
}
void ComponentRealizationImpl::setAbstraction(std::shared_ptr<uml::Component> _abstraction)
{
    m_abstraction = _abstraction;
}

std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ > > ComponentRealizationImpl::getRealizingClassifier() const
{
//assert(m_realizingClassifier);
    return m_realizingClassifier;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > ComponentRealizationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > ComponentRealizationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ComponentRealizationImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > ComponentRealizationImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ComponentRealizationImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ComponentRealizationImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ecore::EObject> ComponentRealizationImpl::eContainer() const
{
	if(auto wp = m_abstraction.lock())
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
boost::any ComponentRealizationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::COMPONENTREALIZATION_ABSTRACTION:
			return getAbstraction(); //24020
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //24016
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2404
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2400
		case UmlPackage::ABSTRACTION_MAPPING:
			return getMapping(); //24018
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2405
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2406
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2407
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2401
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2402
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2403
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //24012
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2404
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2408
		case UmlPackage::COMPONENTREALIZATION_REALIZINGCLASSIFIER:
			return getRealizingClassifier(); //24019
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //2404
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //2405
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //24017
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //2406
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2405
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2409
	}
	return boost::any();
}

void ComponentRealizationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::COMPONENTREALIZATION_ABSTRACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Component> _abstraction = boost::any_cast<std::shared_ptr<uml::Component>>(newValue);
			setAbstraction(_abstraction); //24020
			break;
		}
		case UmlPackage::ABSTRACTION_MAPPING:
		{
			// BOOST CAST
			std::shared_ptr<uml::OpaqueExpression> _mapping = boost::any_cast<std::shared_ptr<uml::OpaqueExpression>>(newValue);
			setMapping(_mapping); //24018
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2405
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2406
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //24012
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //2404
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //2405
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2409
			break;
		}
	}
}
