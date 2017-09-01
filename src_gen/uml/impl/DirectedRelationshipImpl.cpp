#include "DirectedRelationshipImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Relationship.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DirectedRelationshipImpl::DirectedRelationshipImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*SubsetUnion*/
		m_source.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_target.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*SubsetUnion*/
		m_source->initSubsetUnion(m_relatedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >(m_relatedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_target->initSubsetUnion(m_relatedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >(m_relatedElement)" << std::endl;
		#endif
	
	
}

DirectedRelationshipImpl::~DirectedRelationshipImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DirectedRelationship "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			DirectedRelationshipImpl::DirectedRelationshipImpl(std::weak_ptr<uml::Element > par_owner)
			:DirectedRelationshipImpl()
			{
			    m_owner = par_owner;
			}






DirectedRelationshipImpl::DirectedRelationshipImpl(const DirectedRelationshipImpl & obj):DirectedRelationshipImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DirectedRelationship "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

ecore::EObject *  DirectedRelationshipImpl::copy() const
{
	return new DirectedRelationshipImpl(*this);
}

std::shared_ptr<ecore::EClass> DirectedRelationshipImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDirectedRelationship();
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
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > DirectedRelationshipImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<Union<uml::Element> > DirectedRelationshipImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<Union<uml::Element> > DirectedRelationshipImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > DirectedRelationshipImpl::getTarget() const
{
	return m_target;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DirectedRelationshipImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //200
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //201
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //202
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //203
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //204
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //205
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //206
	}
	return boost::any();
}
