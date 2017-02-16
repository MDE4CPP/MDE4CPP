#include "ExceptionHandlerImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExceptionHandlerImpl::ExceptionHandlerImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_exceptionType == nullptr)
	{
		m_exceptionType = new std::vector<uml::Classifier * >();
	}
	
	
}

ExceptionHandlerImpl::~ExceptionHandlerImpl()
{
	if(m_exceptionType!=nullptr)
	{
		delete(m_exceptionType);
	 	m_exceptionType = nullptr;
	}
	
}

ExceptionHandlerImpl::ExceptionHandlerImpl(const ExceptionHandlerImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_exceptionInput  = obj.getExceptionInput();

	std::vector<uml::Classifier * > *  _exceptionType = obj.getExceptionType();
	this->getExceptionType()->insert(this->getExceptionType()->end(), _exceptionType->begin(), _exceptionType->end());

	m_handlerBody  = obj.getHandlerBody();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_protectedNode  = obj.getProtectedNode();


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

ecore::EObject *  ExceptionHandlerImpl::copy() const
{
	return new ExceptionHandlerImpl(*this);
}

ecore::EClass* ExceptionHandlerImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExceptionHandler();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ExceptionHandlerImpl::edge_source_target(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::exception_input_type(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::handler_body_edges(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::handler_body_owner(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::one_input(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::output_pins(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::ObjectNode *  ExceptionHandlerImpl::getExceptionInput() const
{
	//assert(m_exceptionInput);
	return m_exceptionInput;
}
void ExceptionHandlerImpl::setExceptionInput(uml::ObjectNode *  _exceptionInput)
{
	m_exceptionInput = _exceptionInput;
}

std::vector<uml::Classifier * > *  ExceptionHandlerImpl::getExceptionType() const
{
	//assert(m_exceptionType);
	return m_exceptionType;
}


uml::ExecutableNode *  ExceptionHandlerImpl::getHandlerBody() const
{
	//assert(m_handlerBody);
	return m_handlerBody;
}
void ExceptionHandlerImpl::setHandlerBody(uml::ExecutableNode *  _handlerBody)
{
	m_handlerBody = _handlerBody;
}

uml::ExecutableNode *  ExceptionHandlerImpl::getProtectedNode() const
{
	//assert(m_protectedNode);
	return m_protectedNode;
}
void ExceptionHandlerImpl::setProtectedNode(uml::ExecutableNode *  _protectedNode)
{
	m_protectedNode = _protectedNode;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  ExceptionHandlerImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getProtectedNode()!=nullptr)
	{
		_owner = getProtectedNode();
	}

	return _owner;
}
std::vector<uml::Element * > *  ExceptionHandlerImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
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
