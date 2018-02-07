#include "uml/impl/CommentImpl.hpp"
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
CommentImpl::CommentImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_annotatedElement.reset(new Bag<uml::Element>());
	
	

	//Init references
	
	
}

CommentImpl::~CommentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Comment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			CommentImpl::CommentImpl(std::weak_ptr<uml::Element > par_owner)
			:CommentImpl()
			{
			    m_owner = par_owner;
			}






CommentImpl::CommentImpl(const CommentImpl & obj):CommentImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Comment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_body = obj.getBody();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Element> > _annotatedElement = obj.getAnnotatedElement();
	m_annotatedElement.reset(new Bag<uml::Element>(*(obj.getAnnotatedElement().get())));

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

}

std::shared_ptr<ecore::EObject>  CommentImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new CommentImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> CommentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getComment();
}

//*********************************
// Attribute Setter Getter
//*********************************
void CommentImpl::setBody(std::string _body)
{
	m_body = _body;
} 

std::string CommentImpl::getBody() const 
{
	return m_body;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr< Bag<uml::Element> > CommentImpl::getAnnotatedElement() const
{

    return m_annotatedElement;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > CommentImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<ecore::EObject> CommentImpl::eContainer() const
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
boost::any CommentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::COMMENT_ANNOTATEDELEMENT:
			return getAnnotatedElement(); //94
		case UmlPackage::COMMENT_BODY:
			return getBody(); //95
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //90
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //91
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //92
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //93
	}
	return boost::any();
}

void CommentImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::COMMENT_BODY:
		{
			// BOOST CAST
			std::string _body = boost::any_cast<std::string>(newValue);
			setBody(_body); //95
			break;
		}
	}
}
