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
	// Reference Members
	//*********************************
	if( m_body == nullptr)
	{
		m_body = new std::vector<uml::ExecutableNode * >();
	}
	if( m_bodyOutput == nullptr)
	{
		m_bodyOutput = new std::vector<uml::OutputPin * >();
	}
	
	if( m_predecessorClause == nullptr)
	{
		m_predecessorClause = new std::vector<uml::Clause * >();
	}
	if( m_successorClause == nullptr)
	{
		m_successorClause = new std::vector<uml::Clause * >();
	}
	if( m_test == nullptr)
	{
		m_test = new std::vector<uml::ExecutableNode * >();
	}
}

ClauseImpl::~ClauseImpl()
{
	if(m_body!=nullptr)
	{
		delete(m_body);
	 	m_body = nullptr;
	}
	if(m_bodyOutput!=nullptr)
	{
		delete(m_bodyOutput);
	 	m_bodyOutput = nullptr;
	}
	if(m_predecessorClause!=nullptr)
	{
		delete(m_predecessorClause);
	 	m_predecessorClause = nullptr;
	}
	if(m_successorClause!=nullptr)
	{
		delete(m_successorClause);
	 	m_successorClause = nullptr;
	}
	if(m_test!=nullptr)
	{
		delete(m_test);
	 	m_test = nullptr;
	}
	
}

ClauseImpl::ClauseImpl(const ClauseImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::vector<uml::ExecutableNode * > *  _body = obj.getBody();
	this->getBody()->insert(this->getBody()->end(), _body->begin(), _body->end());

	std::vector<uml::OutputPin * > *  _bodyOutput = obj.getBodyOutput();
	this->getBodyOutput()->insert(this->getBodyOutput()->end(), _bodyOutput->begin(), _bodyOutput->end());

	m_decider  = obj.getDecider();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::Clause * > *  _predecessorClause = obj.getPredecessorClause();
	this->getPredecessorClause()->insert(this->getPredecessorClause()->end(), _predecessorClause->begin(), _predecessorClause->end());

	std::vector<uml::Clause * > *  _successorClause = obj.getSuccessorClause();
	this->getSuccessorClause()->insert(this->getSuccessorClause()->end(), _successorClause->begin(), _successorClause->end());

	std::vector<uml::ExecutableNode * > *  _test = obj.getTest();
	this->getTest()->insert(this->getTest()->end(), _test->begin(), _test->end());


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

ecore::EObject *  ClauseImpl::copy() const
{
	return new ClauseImpl(*this);
}

ecore::EClass* ClauseImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getClause();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ClauseImpl::body_output_pins(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClauseImpl::decider_output(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClauseImpl::test_and_body(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::ExecutableNode * > *  ClauseImpl::getBody() const
{
	
	return m_body;
}


std::vector<uml::OutputPin * > *  ClauseImpl::getBodyOutput() const
{
	
	return m_bodyOutput;
}


uml::OutputPin *  ClauseImpl::getDecider() const
{
	//assert(m_decider);
	return m_decider;
}
void ClauseImpl::setDecider(uml::OutputPin *  _decider)
{
	m_decider = _decider;
}

std::vector<uml::Clause * > *  ClauseImpl::getPredecessorClause() const
{
	
	return m_predecessorClause;
}


std::vector<uml::Clause * > *  ClauseImpl::getSuccessorClause() const
{
	
	return m_successorClause;
}


std::vector<uml::ExecutableNode * > *  ClauseImpl::getTest() const
{
	//assert(m_test);
	return m_test;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ClauseImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
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
