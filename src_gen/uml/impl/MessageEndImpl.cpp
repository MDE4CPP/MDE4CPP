#include "MessageEndImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "InteractionFragment.hpp"

#include "Message.hpp"

#include "MessageEnd.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "StringExpression.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
MessageEndImpl::MessageEndImpl()
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

MessageEndImpl::~MessageEndImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete MessageEnd "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			MessageEndImpl::MessageEndImpl(std::shared_ptr<uml::Namespace > par_namespace)
			:MessageEndImpl()
			{
			    m_namespace = par_namespace;
			}






MessageEndImpl::MessageEndImpl(const MessageEndImpl & obj):MessageEndImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MessageEnd "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_message  = obj.getMessage();

	m_owner  = obj.getOwner();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
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

ecore::EObject *  MessageEndImpl::copy() const
{
	return new MessageEndImpl(*this);
}

std::shared_ptr<ecore::EClass> MessageEndImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getMessageEnd();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::InteractionFragment> > MessageEndImpl::enclosingFragment() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageEndImpl::isReceive() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageEndImpl::isSend() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::MessageEnd> > MessageEndImpl::oppositeEnd() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Message > MessageEndImpl::getMessage() const
{

    return m_message;
}
void MessageEndImpl::setMessage(std::shared_ptr<uml::Message> _message)
{
    m_message = _message;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Element > MessageEndImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > MessageEndImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any MessageEndImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2174
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2170
		case UmlPackage::MESSAGEEND_MESSAGE:
			return getMessage(); //21710
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2175
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2176
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2177
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2171
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2172
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2173
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2178
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2179
	}
	return boost::any();
}
