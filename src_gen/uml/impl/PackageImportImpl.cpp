#include "PackageImportImpl.hpp"
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

#include "Package.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PackageImportImpl::PackageImportImpl()
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

PackageImportImpl::~PackageImportImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PackageImport "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			PackageImportImpl::PackageImportImpl(std::weak_ptr<uml::Namespace > par_importingNamespace)
			:PackageImportImpl()
			{
			    m_importingNamespace = par_importingNamespace;
			}






PackageImportImpl::PackageImportImpl(const PackageImportImpl & obj):PackageImportImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PackageImport "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
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
	if(obj.getImportedPackage()!=nullptr)
	{
		m_importedPackage.reset(dynamic_cast<uml::Package*>(obj.getImportedPackage()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedPackage" << std::endl;
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

ecore::EObject *  PackageImportImpl::copy() const
{
	return new PackageImportImpl(*this);
}

std::shared_ptr<ecore::EClass> PackageImportImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPackageImport();
}

//*********************************
// Attribute Setter Getter
//*********************************
void PackageImportImpl::setVisibility(VisibilityKind _visibility)
{
	m_visibility = _visibility;
} 

VisibilityKind PackageImportImpl::getVisibility() const 
{
	return m_visibility;
}

//*********************************
// Operations
//*********************************
bool PackageImportImpl::public_or_private(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Package > PackageImportImpl::getImportedPackage() const
{
//assert(m_importedPackage);
    return m_importedPackage;
}
void PackageImportImpl::setImportedPackage(std::shared_ptr<uml::Package> _importedPackage)
{
    m_importedPackage = _importedPackage;
}

std::weak_ptr<uml::Namespace > PackageImportImpl::getImportingNamespace() const
{
//assert(m_importingNamespace);
    return m_importingNamespace;
}
void PackageImportImpl::setImportingNamespace(std::shared_ptr<uml::Namespace> _importingNamespace)
{
    m_importingNamespace = _importingNamespace;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > PackageImportImpl::getSource() const
{
	return m_source;
}
std::weak_ptr<uml::Element > PackageImportImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > PackageImportImpl::getTarget() const
{
	return m_target;
}
std::shared_ptr<Union<uml::Element> > PackageImportImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<Union<uml::Element> > PackageImportImpl::getRelatedElement() const
{
	return m_relatedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PackageImportImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //830
		case UmlPackage::PACKAGEIMPORT_IMPORTEDPACKAGE:
			return getImportedPackage(); //837
		case UmlPackage::PACKAGEIMPORT_IMPORTINGNAMESPACE:
			return getImportingNamespace(); //838
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //831
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //832
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //833
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //834
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //835
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //836
		case UmlPackage::PACKAGEIMPORT_VISIBILITY:
			return getVisibility(); //839
	}
	return boost::any();
}
