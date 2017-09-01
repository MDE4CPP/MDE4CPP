#include "DependencyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Dependency.hpp"

#include "DirectedRelationship.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "PackageableElement.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"


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
			DependencyImpl::DependencyImpl(std::shared_ptr<uml::Namespace > par_namespace)
			:DependencyImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			DependencyImpl::DependencyImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:DependencyImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}





//Additional constructor for the containments back reference
			DependencyImpl::DependencyImpl(std::weak_ptr<uml::Element > par_owner)
			:DependencyImpl()
			{
			    m_owner = par_owner;
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

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

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
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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

ecore::EObject *  DependencyImpl::copy() const
{
	return new DependencyImpl(*this);
}

std::shared_ptr<ecore::EClass> DependencyImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDependency();
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
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > DependencyImpl::getTarget() const
{
	return m_target;
}
std::weak_ptr<uml::Element > DependencyImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > DependencyImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<Union<uml::Element> > DependencyImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > DependencyImpl::getSource() const
{
	return m_source;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DependencyImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //3715
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //374
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //370
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //375
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //376
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //377
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //371
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //372
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //373
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //374
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //378
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //374
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //375
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //3716
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //376
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //375
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //379
	}
	return boost::any();
}
