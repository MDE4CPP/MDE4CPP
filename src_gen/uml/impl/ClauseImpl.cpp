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
		m_body.reset(new Bag<uml::ExecutableNode>());
	
	
		m_bodyOutput.reset(new Bag<uml::OutputPin>());
	
	
	
		m_predecessorClause.reset(new Bag<uml::Clause>());
	
	
		m_successorClause.reset(new Bag<uml::Clause>());
	
	
		m_test.reset(new Bag<uml::ExecutableNode>());
	
	
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
	
		std::shared_ptr< Bag<uml::ExecutableNode> >
	 _body = obj.getBody();
	m_body.reset(new 	 Bag<uml::ExecutableNode> 
	(*(obj.getBody().get())));// this->getBody()->insert(this->getBody()->end(), _body->begin(), _body->end());

		std::shared_ptr< Bag<uml::OutputPin> >
	 _bodyOutput = obj.getBodyOutput();
	m_bodyOutput.reset(new 	 Bag<uml::OutputPin> 
	(*(obj.getBodyOutput().get())));// this->getBodyOutput()->insert(this->getBodyOutput()->end(), _bodyOutput->begin(), _bodyOutput->end());

	m_decider  = obj.getDecider();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

		std::shared_ptr< Bag<uml::Clause> >
	 _predecessorClause = obj.getPredecessorClause();
	m_predecessorClause.reset(new 	 Bag<uml::Clause> 
	(*(obj.getPredecessorClause().get())));// this->getPredecessorClause()->insert(this->getPredecessorClause()->end(), _predecessorClause->begin(), _predecessorClause->end());

		std::shared_ptr< Bag<uml::Clause> >
	 _successorClause = obj.getSuccessorClause();
	m_successorClause.reset(new 	 Bag<uml::Clause> 
	(*(obj.getSuccessorClause().get())));// this->getSuccessorClause()->insert(this->getSuccessorClause()->end(), _successorClause->begin(), _successorClause->end());

		std::shared_ptr< Bag<uml::ExecutableNode> >
	 _test = obj.getTest();
	m_test.reset(new 	 Bag<uml::ExecutableNode> 
	(*(obj.getTest().get())));// this->getTest()->insert(this->getTest()->end(), _test->begin(), _test->end());


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
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
bool
 ClauseImpl::body_output_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClauseImpl::decider_output(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClauseImpl::test_and_body(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::ExecutableNode> >
 ClauseImpl::getBody() const
{

    return m_body;
}


	std::shared_ptr< Bag<uml::OutputPin> >
 ClauseImpl::getBodyOutput() const
{

    return m_bodyOutput;
}


std::shared_ptr<uml::OutputPin > ClauseImpl::getDecider() const
{
//assert(m_decider);
    return m_decider;
}
void ClauseImpl::setDecider(std::shared_ptr<uml::OutputPin> _decider)
{
    m_decider = _decider;
}

	std::shared_ptr< Bag<uml::Clause> >
 ClauseImpl::getPredecessorClause() const
{

    return m_predecessorClause;
}


	std::shared_ptr< Bag<uml::Clause> >
 ClauseImpl::getSuccessorClause() const
{

    return m_successorClause;
}


	std::shared_ptr< Bag<uml::ExecutableNode> >
 ClauseImpl::getTest() const
{
//assert(m_test);
    return m_test;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ClauseImpl::getOwnedElement() const
{
	

	return m_ownedElement;
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
