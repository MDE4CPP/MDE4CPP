#include "uml/impl/ExceptionHandlerImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ExecutableNode.hpp"

#include "uml/ObjectNode.hpp"


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


//Additional constructor for the containments back reference
			ExceptionHandlerImpl::ExceptionHandlerImpl(std::weak_ptr<uml::Element > par_owner)
			:ExceptionHandlerImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ExceptionHandlerImpl::ExceptionHandlerImpl(std::weak_ptr<uml::ExecutableNode > par_protectedNode)
			:ExceptionHandlerImpl()
			{
			    m_protectedNode = par_protectedNode;
			}






ExceptionHandlerImpl::ExceptionHandlerImpl(const ExceptionHandlerImpl & obj):ExceptionHandlerImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExceptionHandler "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_exceptionInput  = obj.getExceptionInput();

	std::shared_ptr< Bag<uml::Classifier> > _exceptionType = obj.getExceptionType();
	m_exceptionType.reset(new Bag<uml::Classifier>(*(obj.getExceptionType().get())));

	m_handlerBody  = obj.getHandlerBody();

	m_owner  = obj.getOwner();

	m_protectedNode  = obj.getProtectedNode();


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

std::shared_ptr<ecore::EObject>  ExceptionHandlerImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExceptionHandlerImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExceptionHandlerImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExceptionHandler_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ExceptionHandlerImpl::edge_source_target(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::exception_input_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::handler_body_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::handler_body_owner(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::one_input(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::output_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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

std::shared_ptr< Bag<uml::Classifier> > ExceptionHandlerImpl::getExceptionType() const
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

std::weak_ptr<uml::ExecutableNode > ExceptionHandlerImpl::getProtectedNode() const
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
std::shared_ptr<Union<uml::Element> > ExceptionHandlerImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ExceptionHandlerImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> ExceptionHandlerImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_protectedNode.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExceptionHandlerImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //1150
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONINPUT:
			return getExceptionInput(); //1154
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONTYPE:
			return getExceptionType(); //1155
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_HANDLERBODY:
			return getHandlerBody(); //1156
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //1151
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //1152
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //1153
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_PROTECTEDNODE:
			return getProtectedNode(); //1157
	}
	return boost::any();
}

void ExceptionHandlerImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONINPUT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ObjectNode> _exceptionInput = boost::any_cast<std::shared_ptr<uml::ObjectNode>>(newValue);
			setExceptionInput(_exceptionInput); //1154
			break;
		}
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_HANDLERBODY:
		{
			// BOOST CAST
			std::shared_ptr<uml::ExecutableNode> _handlerBody = boost::any_cast<std::shared_ptr<uml::ExecutableNode>>(newValue);
			setHandlerBody(_handlerBody); //1156
			break;
		}
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_PROTECTEDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ExecutableNode> _protectedNode = boost::any_cast<std::shared_ptr<uml::ExecutableNode>>(newValue);
			setProtectedNode(_protectedNode); //1157
			break;
		}
	}
}
