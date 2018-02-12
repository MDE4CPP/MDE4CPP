#include "uml/impl/ElementImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"
#include "util/stereotypestorage.hpp"

//Forward declaration includes
#include "uml/Class.hpp"

#include "uml/Comment.hpp"

#include "uml/DirectedRelationship.hpp"

#include "ecore/EAnnotation.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EModelElement.hpp"

#include "ecore/EObject.hpp"

#include "uml/Element.hpp"

#include "uml/Model.hpp"

#include "uml/Object.hpp"

#include "uml/Package.hpp"

#include "uml/Relationship.hpp"

#include "uml/Stereotype.hpp"


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
	//References
		/*Subset*/
		m_ownedComment.reset(new Subset<uml::Comment, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedComment - Subset<uml::Comment, uml::Element >()" << std::endl;
		#endif
	
	

		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
	
	

	

	//Init references
		/*Subset*/
		m_ownedComment->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedComment - Subset<uml::Comment, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
	

	
}

ElementImpl::~ElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Element "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ElementImpl::ElementImpl(std::weak_ptr<uml::Element > par_owner)
			:ElementImpl()
			{
			    m_owner = par_owner;
			}






ElementImpl::ElementImpl(const ElementImpl & obj):ElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Element "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

		/*Subset*/
		m_ownedComment->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedComment - Subset<uml::Comment, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ElementImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ElementImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getElement_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ElementImpl::addKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Element> > ElementImpl::allOwnedElements() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EObject> ElementImpl::applyStereotype(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	util::StereotypeStorage::eInstance()->applyStereotype(this,stereotype);
return nullptr;
	//end of body
}

std::shared_ptr<uml::Element> ElementImpl::container() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EAnnotation> ElementImpl::createEAnnotation(std::string source) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ElementImpl::destroy() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Stereotype> ElementImpl::getApplicableStereotype(std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> > ElementImpl::getApplicableStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Stereotype> ElementImpl::getAppliedStereotype(std::string qualifiedName) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->getAppliedStereotype(this,qualifiedName);
	//end of body
}

std::shared_ptr<Bag<uml::Stereotype> > ElementImpl::getAppliedStereotypes() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->getAppliedStereotypes(this);
	//end of body
}

std::shared_ptr<uml::Stereotype> ElementImpl::getAppliedSubstereotype(std::shared_ptr<uml::Stereotype>  stereotype,std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> > ElementImpl::getAppliedSubstereotypes(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<std::string> > ElementImpl::getKeywords() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Class> ElementImpl::getMetaClass() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Model> ElementImpl::getModel() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Package> ElementImpl::getNearestPackage() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Relationship> > ElementImpl::getRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Relationship> > ElementImpl::getRelationships(std::shared_ptr<ecore::EClass>  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Stereotype> ElementImpl::getRequiredStereotype(std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> > ElementImpl::getRequiredStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> > ElementImpl::getSourceDirectedRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> > ElementImpl::getSourceDirectedRelationships(std::shared_ptr<ecore::EClass>  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EObject> ElementImpl::getStereotypeApplication(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<ecore::EObject> > ElementImpl::getStereotypeApplications() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> > ElementImpl::getTargetDirectedRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> > ElementImpl::getTargetDirectedRelationships(std::shared_ptr<ecore::EClass>  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

boost::any ElementImpl::getValue(std::shared_ptr<uml::Stereotype>  stereotype,std::string propertyName) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//end of body
}

bool ElementImpl::hasKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::hasValue(std::shared_ptr<uml::Stereotype>  stereotype,std::string propertyName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::has_owner(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::isStereotypeApplicable(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::isStereotypeApplied(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->isStereotypeApplied(this,stereotype);
	//end of body
}

bool ElementImpl::isStereotypeRequired(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::mustBeOwned() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::not_own_self(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::removeKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ElementImpl::setValue(std::shared_ptr<uml::Stereotype>  stereotype,std::string propertyName,boost::any newValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	uml::NamedElement * elem = dynamic_cast<uml::NamedElement *>(this);
if(elem)
{
    //apply stereotype to map
    //std::vector<uml::Stereotype *> appliedStList = map->find(elem->getQualifiedName())
    //return std::any(appliedStList->cbegin();appliedStList->cend();[stereotype](stereo){return });
}
	//end of body
}

std::shared_ptr<ecore::EObject> ElementImpl::unapplyStereotype(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Comment, uml::Element > > ElementImpl::getOwnedComment() const
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
std::weak_ptr<uml::Element > ElementImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> ElementImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //80
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //81
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //82
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //83
	}
	return boost::any();
}

void ElementImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
