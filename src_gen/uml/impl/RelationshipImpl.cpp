#include "uml/impl/RelationshipImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"


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

}

std::shared_ptr<ecore::EObject>  RelationshipImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new RelationshipImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> RelationshipImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRelationship_EClass();
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
std::shared_ptr<Union<uml::Element> > RelationshipImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<Union<uml::Element> > RelationshipImpl::getRelatedElement() const
{
	return m_relatedElement;
}


std::shared_ptr<ecore::EObject> RelationshipImpl::eContainer() const
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
boost::any RelationshipImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //210
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //211
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //212
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //213
		case UmlPackage::RELATIONSHIP_EREFERENCE_RELATEDELEMENT:
			return getRelatedElement(); //214
	}
	return boost::any();
}

void RelationshipImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
