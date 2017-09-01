#include "ElementImportImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "DirectedRelationship.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Namespace.hpp"

#include "PackageableElement.hpp"


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
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getImportedElement()!=nullptr)
	{
		m_importedElement.reset(dynamic_cast<uml::PackageableElement*>(obj.getImportedElement()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedElement" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif


}

ecore::EObject *  ElementImportImpl::copy() const
{
	return new ElementImportImpl(*this);
}

std::shared_ptr<ecore::EClass> ElementImportImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getElementImport();
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
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ElementImportImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<Union<uml::Element> > ElementImportImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ElementImportImpl::getTarget() const
{
	return m_target;
}
std::weak_ptr<uml::Element > ElementImportImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > ElementImportImpl::getRelatedElement() const
{
	return m_relatedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ElementImportImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ELEMENTIMPORT_ALIAS:
			return getAlias(); //827
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //820
		case UmlPackage::ELEMENTIMPORT_IMPORTEDELEMENT:
			return getImportedElement(); //828
		case UmlPackage::ELEMENTIMPORT_IMPORTINGNAMESPACE:
			return getImportingNamespace(); //829
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //821
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //822
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //823
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //824
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //825
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //826
		case UmlPackage::ELEMENTIMPORT_VISIBILITY:
			return getVisibility(); //8210
	}
	return boost::any();
}
