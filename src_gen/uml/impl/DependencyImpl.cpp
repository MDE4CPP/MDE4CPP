#include "uml/impl/DependencyImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/DirectedRelationship.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DependencyImpl::DependencyImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*SubsetUnion*/
		m_client.reset(new SubsetUnion<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_client - SubsetUnion<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_supplier.reset(new SubsetUnion<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_supplier - SubsetUnion<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*SubsetUnion*/
		m_client->initSubsetUnion(m_source);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_client - SubsetUnion<uml::NamedElement, uml::Element >(m_source)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_supplier->initSubsetUnion(m_target);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_supplier - SubsetUnion<uml::NamedElement, uml::Element >(m_target)" << std::endl;
		#endif
	
	
}

DependencyImpl::~DependencyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Dependency "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			DependencyImpl::DependencyImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:DependencyImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			DependencyImpl::DependencyImpl(std::weak_ptr<uml::Element > par_owner)
			:DependencyImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			DependencyImpl::DependencyImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:DependencyImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			DependencyImpl::DependencyImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:DependencyImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






DependencyImpl::DependencyImpl(const DependencyImpl & obj):DependencyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Dependency "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  DependencyImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new DependencyImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> DependencyImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDependency_EClass();
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
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element > > DependencyImpl::getClient() const
{
//assert(m_client);
    return m_client;
}


std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element > > DependencyImpl::getSupplier() const
{
//assert(m_supplier);
    return m_supplier;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > DependencyImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > DependencyImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > DependencyImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > DependencyImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > DependencyImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > DependencyImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ecore::EObject> DependencyImpl::eContainer() const
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DependencyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_EREFERENCE_CLIENT:
			return getClient(); //3716
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //374
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //370
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //375
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //376
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //377
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //371
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //372
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //373
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //3712
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //374
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //378
		case UmlPackage::RELATIONSHIP_EREFERENCE_RELATEDELEMENT:
			return getRelatedElement(); //374
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_SOURCE:
			return getSource(); //375
		case UmlPackage::DEPENDENCY_EREFERENCE_SUPPLIER:
			return getSupplier(); //3717
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_TARGET:
			return getTarget(); //376
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //375
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //379
	}
	return boost::any();
}

void DependencyImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //375
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //376
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //3712
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //374
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //375
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //379
			break;
		}
	}
}
