#include "ClauseImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ClauseImpl::ClauseImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	m_body.reset(new std::vector<std::shared_ptr<uml::ExecutableNode>>());
	m_bodyOutput.reset(new std::vector<std::shared_ptr<uml::OutputPin>>());
	
	m_predecessorClause.reset(new std::vector<std::shared_ptr<uml::Clause>>());
	m_successorClause.reset(new std::vector<std::shared_ptr<uml::Clause>>());
	m_test.reset(new std::vector<std::shared_ptr<uml::ExecutableNode>>());
}

ClauseImpl::~ClauseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Clause "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ClauseImpl::ClauseImpl(const ClauseImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::ExecutableNode>>> _body = obj.getBody();
	this->getBody()->insert(this->getBody()->end(), _body->begin(), _body->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::OutputPin>>> _bodyOutput = obj.getBodyOutput();
	this->getBodyOutput()->insert(this->getBodyOutput()->end(), _bodyOutput->begin(), _bodyOutput->end());

	m_decider  = obj.getDecider();

	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	std::shared_ptr<std::vector<std::shared_ptr<uml::Clause>>> _predecessorClause = obj.getPredecessorClause();
	this->getPredecessorClause()->insert(this->getPredecessorClause()->end(), _predecessorClause->begin(), _predecessorClause->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Clause>>> _successorClause = obj.getSuccessorClause();
	this->getSuccessorClause()->insert(this->getSuccessorClause()->end(), _successorClause->begin(), _successorClause->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::ExecutableNode>>> _test = obj.getTest();
	this->getTest()->insert(this->getTest()->end(), _test->begin(), _test->end());


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAnnotation>>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->push_back(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  ClauseImpl::copy() const
{
	return new ClauseImpl(*this);
}

std::shared_ptr<ecore::EClass> ClauseImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getClause();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ClauseImpl::body_output_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClauseImpl::decider_output(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClauseImpl::test_and_body(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<uml::ExecutableNode>>> ClauseImpl::getBody() const
{

    return m_body;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::OutputPin>>> ClauseImpl::getBodyOutput() const
{

    return m_bodyOutput;
}


std::shared_ptr<uml::OutputPin> ClauseImpl::getDecider() const
{
//assert(m_decider);
    return m_decider;
}
void ClauseImpl::setDecider(std::shared_ptr<uml::OutputPin> _decider)
{
    m_decider = _decider;
}

std::shared_ptr<std::vector<std::shared_ptr<uml::Clause>>> ClauseImpl::getPredecessorClause() const
{

    return m_predecessorClause;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::Clause>>> ClauseImpl::getSuccessorClause() const
{

    return m_successorClause;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::ExecutableNode>>> ClauseImpl::getTest() const
{
//assert(m_test);
    return m_test;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> ClauseImpl::getOwnedElement() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement(new std::vector<std::shared_ptr<uml::Element>>()) ;
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> ownedComment = getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ClauseImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLAUSE_BODY:
			return getBody(); //1424
		case UmlPackage::CLAUSE_BODYOUTPUT:
			return getBodyOutput(); //1425
		case UmlPackage::CLAUSE_DECIDER:
			return getDecider(); //1426
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1420
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1421
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1422
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1423
		case UmlPackage::CLAUSE_PREDECESSORCLAUSE:
			return getPredecessorClause(); //1427
		case UmlPackage::CLAUSE_SUCCESSORCLAUSE:
			return getSuccessorClause(); //1428
		case UmlPackage::CLAUSE_TEST:
			return getTest(); //1429
	}
	return boost::any();
}
