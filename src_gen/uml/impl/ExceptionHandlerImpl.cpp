#include "ExceptionHandlerImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Classifier.hpp"

#include "Comment.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "ExecutableNode.hpp"

#include "ObjectNode.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExceptionHandlerImpl::ExceptionHandlerImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_exceptionType.reset(new Bag<uml::Classifier>());
	
	

	

	

	//Init references
	

	
	

	

	
}

ExceptionHandlerImpl::~ExceptionHandlerImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExceptionHandler "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExceptionHandlerImpl::ExceptionHandlerImpl(const ExceptionHandlerImpl & obj):ExceptionHandlerImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExceptionHandler "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_exceptionInput  = obj.getExceptionInput();

		std::shared_ptr< Bag<uml::Classifier> >
	 _exceptionType = obj.getExceptionType();
	m_exceptionType.reset(new 	 Bag<uml::Classifier> 
	(*(obj.getExceptionType().get())));

	m_handlerBody  = obj.getHandlerBody();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

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
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getProtectedNode()!=nullptr)
	{
		m_protectedNode.reset(dynamic_cast<uml::ExecutableNode*>(obj.getProtectedNode()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_protectedNode" << std::endl;
	#endif


}

ecore::EObject *  ExceptionHandlerImpl::copy() const
{
	return new ExceptionHandlerImpl(*this);
}

std::shared_ptr<ecore::EClass> ExceptionHandlerImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExceptionHandler();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ExceptionHandlerImpl::edge_source_target(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ExceptionHandlerImpl::exception_input_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ExceptionHandlerImpl::handler_body_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ExceptionHandlerImpl::handler_body_owner(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ExceptionHandlerImpl::one_input(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ExceptionHandlerImpl::output_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ObjectNode > ExceptionHandlerImpl::getExceptionInput() const
{
//assert(m_exceptionInput);
    return m_exceptionInput;
}
void ExceptionHandlerImpl::setExceptionInput(std::shared_ptr<uml::ObjectNode> _exceptionInput)
{
    m_exceptionInput = _exceptionInput;
}

	std::shared_ptr< Bag<uml::Classifier> >
 ExceptionHandlerImpl::getExceptionType() const
{
//assert(m_exceptionType);
    return m_exceptionType;
}


std::shared_ptr<uml::ExecutableNode > ExceptionHandlerImpl::getHandlerBody() const
{
//assert(m_handlerBody);
    return m_handlerBody;
}
void ExceptionHandlerImpl::setHandlerBody(std::shared_ptr<uml::ExecutableNode> _handlerBody)
{
    m_handlerBody = _handlerBody;
}

std::shared_ptr<uml::ExecutableNode > ExceptionHandlerImpl::getProtectedNode() const
{
//assert(m_protectedNode);
    return m_protectedNode;
}
void ExceptionHandlerImpl::setProtectedNode(std::shared_ptr<uml::ExecutableNode> _protectedNode)
{
    m_protectedNode = _protectedNode;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > ExceptionHandlerImpl::getOwner() const
{
	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > ExceptionHandlerImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExceptionHandlerImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1150
		case UmlPackage::EXCEPTIONHANDLER_EXCEPTIONINPUT:
			return getExceptionInput(); //1154
		case UmlPackage::EXCEPTIONHANDLER_EXCEPTIONTYPE:
			return getExceptionType(); //1155
		case UmlPackage::EXCEPTIONHANDLER_HANDLERBODY:
			return getHandlerBody(); //1156
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1151
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1152
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1153
		case UmlPackage::EXCEPTIONHANDLER_PROTECTEDNODE:
			return getProtectedNode(); //1157
	}
	return boost::any();
}
