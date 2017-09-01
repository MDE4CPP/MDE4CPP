#include "RelationshipImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RelationshipImpl::RelationshipImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Union*/
		m_relatedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_relatedElement - Union<uml::Element>()" << std::endl;
		#endif
	
	

	//Init references
	
	
}

RelationshipImpl::~RelationshipImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Relationship "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			RelationshipImpl::RelationshipImpl(std::weak_ptr<uml::Element > par_owner)
			:RelationshipImpl()
			{
			    m_owner = par_owner;
			}






RelationshipImpl::RelationshipImpl(const RelationshipImpl & obj):RelationshipImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Relationship "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
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
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif


}

ecore::EObject *  RelationshipImpl::copy() const
{
	return new RelationshipImpl(*this);
}

std::shared_ptr<ecore::EClass> RelationshipImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRelationship();
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



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > RelationshipImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<Union<uml::Element> > RelationshipImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RelationshipImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //210
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //211
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //212
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //213
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //214
	}
	return boost::any();
}
