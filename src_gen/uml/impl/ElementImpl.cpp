#include "ElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"
#include "stereotypestorage.h"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ElementImpl::ElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		/*Subset*/
		m_ownedComment.reset(new Subset<uml::Comment, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
	
	
}

ElementImpl::~ElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Element "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ElementImpl::ElementImpl(const ElementImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();


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

ecore::EObject *  ElementImpl::copy() const
{
	return new ElementImpl(*this);
}

std::shared_ptr<ecore::EClass> ElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ElementImpl::addKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Element> >
 ElementImpl::allOwnedElements() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EObject> 
 ElementImpl::applyStereotype(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	//generated from body annotation
	util::StereotypeStorage::eInstance()->applyStereotype(this,stereotype);
return nullptr;
}

std::shared_ptr<uml::Element> 
 ElementImpl::container() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EAnnotation> 
 ElementImpl::createEAnnotation(std::string source) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void
 ElementImpl::destroy() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Stereotype> 
 ElementImpl::getApplicableStereotype(std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> >
 ElementImpl::getApplicableStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Stereotype> 
 ElementImpl::getAppliedStereotype(std::string qualifiedName) 
{
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->getAppliedStereotype(this,qualifiedName);
}

std::shared_ptr<Bag<uml::Stereotype> >
 ElementImpl::getAppliedStereotypes() 
{
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->getAppliedStereotypes(this);
}

std::shared_ptr<uml::Stereotype> 
 ElementImpl::getAppliedSubstereotype(std::shared_ptr<uml::Stereotype>  stereotype,std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> >
 ElementImpl::getAppliedSubstereotypes(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<std::string> >
 ElementImpl::getKeywords() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Class> 
 ElementImpl::getMetaClass() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Model> 
 ElementImpl::getModel() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Package> 
 ElementImpl::getNearestPackage() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Relationship> >
 ElementImpl::getRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Relationship> >
 ElementImpl::getRelationships(std::shared_ptr<ecore::EClass>  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Stereotype> 
 ElementImpl::getRequiredStereotype(std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> >
 ElementImpl::getRequiredStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> >
 ElementImpl::getSourceDirectedRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> >
 ElementImpl::getSourceDirectedRelationships(std::shared_ptr<ecore::EClass>  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EObject> 
 ElementImpl::getStereotypeApplication(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<ecore::EObject> >
 ElementImpl::getStereotypeApplications() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> >
 ElementImpl::getTargetDirectedRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> >
 ElementImpl::getTargetDirectedRelationships(std::shared_ptr<ecore::EClass>  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

boost::any
 ElementImpl::getValue(std::shared_ptr<uml::Stereotype>  stereotype,std::string propertyName) 
{
	//generated from body annotation
	std::shared_ptr<uml::Stereotype> stereoInstance = util::StereotypeStorage::eInstance()->getAppliedStereotype(this,stereotype->getQualifiedName());
	if(stereoInstance == nullptr)
	{
	   return boost::any();
	}

	std::shared_ptr<Bag<uml::Property> > propertyList = stereoInstance->getMetaClass()->getAttribute();
	for(std::shared_ptr<uml::Property> p: *propertyList)
	{
		if(p->getName()==propertyName)
		{
			return stereoInstance->get(p);
		}
	}
	return boost::any();
}

bool
 ElementImpl::hasKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ElementImpl::hasValue(std::shared_ptr<uml::Stereotype>  stereotype,std::string propertyName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ElementImpl::has_owner(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ElementImpl::isStereotypeApplicable(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ElementImpl::isStereotypeApplied(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->isStereotypeApplied(this,stereotype);
}

bool
 ElementImpl::isStereotypeRequired(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ElementImpl::mustBeOwned() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ElementImpl::not_own_self(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ElementImpl::removeKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void
 ElementImpl::setValue(std::shared_ptr<uml::Stereotype>  stereotype,std::string propertyName,boost::any newValue) 
{
	//generated from body annotation
	uml::NamedElement * elem = dynamic_cast<uml::NamedElement *>(this);
if(elem)
{
    //apply stereotype to map
    //std::vector<uml::Stereotype *> appliedStList = map->find(elem->getQualifiedName())
    //return std::any(appliedStList->cbegin();appliedStList->cend();[stereotype](stereo){return });
}
}

std::shared_ptr<ecore::EObject> 
 ElementImpl::unapplyStereotype(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
		std::shared_ptr<Subset<uml::Comment, uml::Element > >
 ElementImpl::getOwnedComment() const
{

    return m_ownedComment;
}








//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ElementImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > ElementImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //80
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //81
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //82
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //83
	}
	return boost::any();
}
