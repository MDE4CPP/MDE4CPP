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
	// Reference Members
	//*********************************
	if( m_ownedComment == nullptr)
	{
		m_ownedComment = new std::vector<uml::Comment * >();
	}
	if( m_ownedElement == nullptr)
	{
		m_ownedElement = new std::vector<uml::Element * >();
	}
	
}

ElementImpl::~ElementImpl()
{
	if(m_ownedComment!=nullptr)
	{
		for(auto c :*m_ownedComment)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_ownedElement!=nullptr)
	{
		delete(m_ownedElement);
	 	m_ownedElement = nullptr;
	}
	
}

ElementImpl::ElementImpl(const ElementImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  ElementImpl::copy() const
{
	return new ElementImpl(*this);
}

ecore::EClass* ElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ElementImpl::addKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Element * > *  ElementImpl::allOwnedElements() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

ecore::EObject *  ElementImpl::applyStereotype(uml::Stereotype *  stereotype) 
{
	//generated from body annotation
	util::StereotypeStorage::eInstance()->applyStereotype(this,stereotype);
return nullptr;
}

uml::Element *  ElementImpl::container() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

ecore::EAnnotation *  ElementImpl::createEAnnotation(std::string source) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ElementImpl::destroy() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Stereotype *  ElementImpl::getApplicableStereotype(std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Stereotype * > *  ElementImpl::getApplicableStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Stereotype *  ElementImpl::getAppliedStereotype(std::string qualifiedName) 
{
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->getAppliedStereotype(this,qualifiedName);
}

std::vector<uml::Stereotype * > *  ElementImpl::getAppliedStereotypes() 
{
	//generated from body annotation
	return new std::vector<uml::Stereotype*>(util::StereotypeStorage::eInstance()->getAppliedStereotypes(this));
}

uml::Stereotype *  ElementImpl::getAppliedSubstereotype(uml::Stereotype *  stereotype,std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Stereotype * > *  ElementImpl::getAppliedSubstereotypes(uml::Stereotype *  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<std::string> *  ElementImpl::getKeywords() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Class *  ElementImpl::getMetaClass() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Model *  ElementImpl::getModel() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Package *  ElementImpl::getNearestPackage() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Relationship * > *  ElementImpl::getRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Relationship * > *  ElementImpl::getRelationships(ecore::EClass *  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Stereotype *  ElementImpl::getRequiredStereotype(std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Stereotype * > *  ElementImpl::getRequiredStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::DirectedRelationship * > *  ElementImpl::getSourceDirectedRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::DirectedRelationship * > *  ElementImpl::getSourceDirectedRelationships(ecore::EClass *  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

ecore::EObject *  ElementImpl::getStereotypeApplication(uml::Stereotype *  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<ecore::EObject * > *  ElementImpl::getStereotypeApplications() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::DirectedRelationship * > *  ElementImpl::getTargetDirectedRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::DirectedRelationship * > *  ElementImpl::getTargetDirectedRelationships(ecore::EClass *  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

boost::any ElementImpl::getValue(uml::Stereotype *  stereotype,std::string propertyName) 
{
	//generated from body annotation
	uml::Stereotype * stereoInstance = util::StereotypeStorage::eInstance()->getAppliedStereotype(this,stereotype->getQualifiedName());
if(stereoInstance == nullptr)
{
   return boost::any();
}

for(Property * p: *stereoInstance->getMetaClass()->getAttribute())
{
    if(p->getName()==propertyName)
    {
        return stereoInstance->get(p);
    }
}

return boost::any();

}

bool ElementImpl::hasKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::hasValue(uml::Stereotype *  stereotype,std::string propertyName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::has_owner(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::isStereotypeApplicable(uml::Stereotype *  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::isStereotypeApplied(uml::Stereotype *  stereotype) 
{
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->isStereotypeApplied(this,stereotype);
}

bool ElementImpl::isStereotypeRequired(uml::Stereotype *  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::mustBeOwned() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::not_own_self(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::removeKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ElementImpl::setValue(uml::Stereotype *  stereotype,std::string propertyName,boost::any newValue) 
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

ecore::EObject *  ElementImpl::unapplyStereotype(uml::Stereotype *  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Comment * > *  ElementImpl::getOwnedComment() const
{
	
	return m_ownedComment;
}








//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ElementImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  ElementImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	

	return _owner;
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
