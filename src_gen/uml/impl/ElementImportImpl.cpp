#include "uml/impl/ElementImportImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/DirectedRelationship.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/PackageableElement.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ElementImportImpl::ElementImportImpl()
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

ElementImportImpl::~ElementImportImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ElementImport "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ElementImportImpl::ElementImportImpl(std::weak_ptr<uml::Namespace > par_importingNamespace)
			:ElementImportImpl()
			{
			    m_importingNamespace = par_importingNamespace;
			}





//Additional constructor for the containments back reference
			ElementImportImpl::ElementImportImpl(std::weak_ptr<uml::Element > par_owner)
			:ElementImportImpl()
			{
			    m_owner = par_owner;
			}






ElementImportImpl::ElementImportImpl(const ElementImportImpl & obj):ElementImportImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ElementImport "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_alias = obj.getAlias();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_importingNamespace  = obj.getImportingNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getImportedElement()!=nullptr)
	{
		m_importedElement = std::dynamic_pointer_cast<uml::PackageableElement>(obj.getImportedElement()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedElement" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ElementImportImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ElementImportImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ElementImportImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getElementImport_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ElementImportImpl::setAlias(std::string _alias)
{
	m_alias = _alias;
} 

std::string ElementImportImpl::getAlias() const 
{
	return m_alias;
}

void ElementImportImpl::setVisibility(VisibilityKind _visibility)
{
	m_visibility = _visibility;
} 

VisibilityKind ElementImportImpl::getVisibility() const 
{
	return m_visibility;
}

//*********************************
// Operations
//*********************************
std::string ElementImportImpl::getName() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImportImpl::imported_element_is_public(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImportImpl::visibility_public_or_private(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::PackageableElement > ElementImportImpl::getImportedElement() const
{
//assert(m_importedElement);
    return m_importedElement;
}
void ElementImportImpl::setImportedElement(std::shared_ptr<uml::PackageableElement> _importedElement)
{
    m_importedElement = _importedElement;
}

std::weak_ptr<uml::Namespace > ElementImportImpl::getImportingNamespace() const
{
//assert(m_importingNamespace);
    return m_importingNamespace;
}
void ElementImportImpl::setImportingNamespace(std::shared_ptr<uml::Namespace> _importingNamespace)
{
    m_importingNamespace = _importingNamespace;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > ElementImportImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ElementImportImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > ElementImportImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ElementImportImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ElementImportImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ecore::EObject> ElementImportImpl::eContainer() const
{
	if(auto wp = m_importingNamespace.lock())
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
boost::any ElementImportImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ELEMENTIMPORT_EATTRIBUTE_ALIAS:
			return getAlias(); //827
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //820
		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTEDELEMENT:
			return getImportedElement(); //828
		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTINGNAMESPACE:
			return getImportingNamespace(); //829
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //821
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //822
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //823
		case UmlPackage::RELATIONSHIP_EREFERENCE_RELATEDELEMENT:
			return getRelatedElement(); //824
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_SOURCE:
			return getSource(); //825
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_TARGET:
			return getTarget(); //826
		case UmlPackage::ELEMENTIMPORT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //8210
	}
	return boost::any();
}

void ElementImportImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ELEMENTIMPORT_EATTRIBUTE_ALIAS:
		{
			// BOOST CAST
			std::string _alias = boost::any_cast<std::string>(newValue);
			setAlias(_alias); //827
			break;
		}
		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTEDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::PackageableElement> _importedElement = boost::any_cast<std::shared_ptr<uml::PackageableElement>>(newValue);
			setImportedElement(_importedElement); //828
			break;
		}
		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTINGNAMESPACE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Namespace> _importingNamespace = boost::any_cast<std::shared_ptr<uml::Namespace>>(newValue);
			setImportingNamespace(_importingNamespace); //829
			break;
		}
		case UmlPackage::ELEMENTIMPORT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //8210
			break;
		}
	}
}
