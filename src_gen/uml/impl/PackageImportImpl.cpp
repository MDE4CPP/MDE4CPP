#include "PackageImportImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
	
	
}

PackageImportImpl::~PackageImportImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PackageImport "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

PackageImportImpl::PackageImportImpl(const PackageImportImpl & obj)
{
	//create copy of all Attributes
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_importedPackage  = obj.getImportedPackage();

	m_importingNamespace  = obj.getImportingNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new 		Union<uml::Element> (*(obj.getRelatedElement().get())));// this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _source = obj.getSource();
	m_source.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getSource().get())));// this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _target = obj.getTarget();
	m_target.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getTarget().get())));// this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
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
// Attribute Setter Gettter
//*********************************
void PackageImportImpl::setVisibility (VisibilityKind _visibility)
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
bool
 PackageImportImpl::public_or_private(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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

std::shared_ptr<uml::Namespace > PackageImportImpl::getImportingNamespace() const
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
		std::shared_ptr<Union<uml::Element> > PackageImportImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::Element> > PackageImportImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 PackageImportImpl::getTarget() const
{
	

	return m_target;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 PackageImportImpl::getSource() const
{
	

	return m_source;
}
std::shared_ptr<uml::Element > PackageImportImpl::getOwner() const
{
	

	return m_owner;
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
