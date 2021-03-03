#include "uml/impl/ClauseImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Clause.hpp"
#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/ExecutableNode.hpp"
#include "uml/OutputPin.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ClauseImpl::ClauseImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ClauseImpl::~ClauseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Clause "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ClauseImpl::ClauseImpl(std::weak_ptr<uml::Element> par_owner)
:ClauseImpl()
{
	m_owner = par_owner;
}

ClauseImpl::ClauseImpl(const ClauseImpl & obj): ClauseImpl()
{
	*this = obj;
}

ClauseImpl& ClauseImpl::operator=(const ClauseImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	Clause::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Clause "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::ExecutableNode>> _body = obj.getBody();
	m_body.reset(new Bag<uml::ExecutableNode>(*(obj.getBody().get())));
	std::shared_ptr<Bag<uml::OutputPin>> _bodyOutput = obj.getBodyOutput();
	m_bodyOutput.reset(new Bag<uml::OutputPin>(*(obj.getBodyOutput().get())));
	m_decider  = obj.getDecider();
	std::shared_ptr<Bag<uml::Clause>> _predecessorClause = obj.getPredecessorClause();
	m_predecessorClause.reset(new Bag<uml::Clause>(*(obj.getPredecessorClause().get())));
	std::shared_ptr<Bag<uml::Clause>> _successorClause = obj.getSuccessorClause();
	m_successorClause.reset(new Bag<uml::Clause>(*(obj.getSuccessorClause().get())));
	std::shared_ptr<Bag<uml::ExecutableNode>> _test = obj.getTest();
	m_test.reset(new Bag<uml::ExecutableNode>(*(obj.getTest().get())));
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ClauseImpl::copy() const
{
	std::shared_ptr<ClauseImpl> element(new ClauseImpl());
	*element =(*this);
	element->setThisClausePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ClauseImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getClause_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ClauseImpl::body_output_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClauseImpl::decider_output(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClauseImpl::test_and_body(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference body
*/
std::shared_ptr<Bag<uml::ExecutableNode>> ClauseImpl::getBody() const
{
	if(m_body == nullptr)
	{
		m_body.reset(new Bag<uml::ExecutableNode>());
		
		
	}

    return m_body;
}



/*
Getter & Setter for reference bodyOutput
*/
std::shared_ptr<Bag<uml::OutputPin>> ClauseImpl::getBodyOutput() const
{
	if(m_bodyOutput == nullptr)
	{
		m_bodyOutput.reset(new Bag<uml::OutputPin>());
		
		
	}

    return m_bodyOutput;
}



/*
Getter & Setter for reference decider
*/
std::shared_ptr<uml::OutputPin> ClauseImpl::getDecider() const
{
//assert(m_decider);
    return m_decider;
}
void ClauseImpl::setDecider(std::shared_ptr<uml::OutputPin> _decider)
{
    m_decider = _decider;
}


/*
Getter & Setter for reference predecessorClause
*/
std::shared_ptr<Bag<uml::Clause>> ClauseImpl::getPredecessorClause() const
{
	if(m_predecessorClause == nullptr)
	{
		m_predecessorClause.reset(new Bag<uml::Clause>());
		
		
	}

    return m_predecessorClause;
}



/*
Getter & Setter for reference successorClause
*/
std::shared_ptr<Bag<uml::Clause>> ClauseImpl::getSuccessorClause() const
{
	if(m_successorClause == nullptr)
	{
		m_successorClause.reset(new Bag<uml::Clause>());
		
		
	}

    return m_successorClause;
}



/*
Getter & Setter for reference test
*/
std::shared_ptr<Bag<uml::ExecutableNode>> ClauseImpl::getTest() const
{
	if(m_test == nullptr)
	{
		m_test.reset(new Bag<uml::ExecutableNode>());
		
		
	}
//assert(m_test);
    return m_test;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ClauseImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}




std::shared_ptr<Clause> ClauseImpl::getThisClausePtr() const
{
	return m_thisClausePtr.lock();
}
void ClauseImpl::setThisClausePtr(std::weak_ptr<Clause> thisClausePtr)
{
	m_thisClausePtr = thisClausePtr;
	setThisElementPtr(thisClausePtr);
}
std::shared_ptr<ecore::EObject> ClauseImpl::eContainer() const
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
Any ClauseImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
		{
			return eAny(getBody()); //383			
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
		{
			return eAny(getBodyOutput()); //384			
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
			return eAny(getDecider()); //385
		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
		{
			return eAny(getPredecessorClause()); //386			
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
		{
			return eAny(getSuccessorClause()); //387			
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
		{
			return eAny(getTest()); //388			
		}
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool ClauseImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
			return getBody() != nullptr; //383
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
			return getBodyOutput() != nullptr; //384
		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
			return getDecider() != nullptr; //385
		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
			return getPredecessorClause() != nullptr; //386
		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
			return getSuccessorClause() != nullptr; //387
		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
			return getTest() != nullptr; //388
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool ClauseImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ExecutableNode>> bodyList(new Bag<uml::ExecutableNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				bodyList->add(std::dynamic_pointer_cast<uml::ExecutableNode>(*iter));
				iter++;
			}
			
			Bag<uml::ExecutableNode>::iterator iterBody = m_body->begin();
			Bag<uml::ExecutableNode>::iterator endBody = m_body->end();
			while (iterBody != endBody)
			{
				if (bodyList->find(*iterBody) == -1)
				{
					m_body->erase(*iterBody);
				}
				iterBody++;
			}
 
			iterBody = bodyList->begin();
			endBody = bodyList->end();
			while (iterBody != endBody)
			{
				if (m_body->find(*iterBody) == -1)
				{
					m_body->add(*iterBody);
				}
				iterBody++;			
			}
			return true;
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::OutputPin>> bodyOutputList(new Bag<uml::OutputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				bodyOutputList->add(std::dynamic_pointer_cast<uml::OutputPin>(*iter));
				iter++;
			}
			
			Bag<uml::OutputPin>::iterator iterBodyOutput = m_bodyOutput->begin();
			Bag<uml::OutputPin>::iterator endBodyOutput = m_bodyOutput->end();
			while (iterBodyOutput != endBodyOutput)
			{
				if (bodyOutputList->find(*iterBodyOutput) == -1)
				{
					m_bodyOutput->erase(*iterBodyOutput);
				}
				iterBodyOutput++;
			}
 
			iterBodyOutput = bodyOutputList->begin();
			endBodyOutput = bodyOutputList->end();
			while (iterBodyOutput != endBodyOutput)
			{
				if (m_bodyOutput->find(*iterBodyOutput) == -1)
				{
					m_bodyOutput->add(*iterBodyOutput);
				}
				iterBodyOutput++;			
			}
			return true;
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>(_temp);
			setDecider(_decider); //385
			return true;
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Clause>> predecessorClauseList(new Bag<uml::Clause>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				predecessorClauseList->add(std::dynamic_pointer_cast<uml::Clause>(*iter));
				iter++;
			}
			
			Bag<uml::Clause>::iterator iterPredecessorClause = m_predecessorClause->begin();
			Bag<uml::Clause>::iterator endPredecessorClause = m_predecessorClause->end();
			while (iterPredecessorClause != endPredecessorClause)
			{
				if (predecessorClauseList->find(*iterPredecessorClause) == -1)
				{
					m_predecessorClause->erase(*iterPredecessorClause);
				}
				iterPredecessorClause++;
			}
 
			iterPredecessorClause = predecessorClauseList->begin();
			endPredecessorClause = predecessorClauseList->end();
			while (iterPredecessorClause != endPredecessorClause)
			{
				if (m_predecessorClause->find(*iterPredecessorClause) == -1)
				{
					m_predecessorClause->add(*iterPredecessorClause);
				}
				iterPredecessorClause++;			
			}
			return true;
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Clause>> successorClauseList(new Bag<uml::Clause>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				successorClauseList->add(std::dynamic_pointer_cast<uml::Clause>(*iter));
				iter++;
			}
			
			Bag<uml::Clause>::iterator iterSuccessorClause = m_successorClause->begin();
			Bag<uml::Clause>::iterator endSuccessorClause = m_successorClause->end();
			while (iterSuccessorClause != endSuccessorClause)
			{
				if (successorClauseList->find(*iterSuccessorClause) == -1)
				{
					m_successorClause->erase(*iterSuccessorClause);
				}
				iterSuccessorClause++;
			}
 
			iterSuccessorClause = successorClauseList->begin();
			endSuccessorClause = successorClauseList->end();
			while (iterSuccessorClause != endSuccessorClause)
			{
				if (m_successorClause->find(*iterSuccessorClause) == -1)
				{
					m_successorClause->add(*iterSuccessorClause);
				}
				iterSuccessorClause++;			
			}
			return true;
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ExecutableNode>> testList(new Bag<uml::ExecutableNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				testList->add(std::dynamic_pointer_cast<uml::ExecutableNode>(*iter));
				iter++;
			}
			
			Bag<uml::ExecutableNode>::iterator iterTest = m_test->begin();
			Bag<uml::ExecutableNode>::iterator endTest = m_test->end();
			while (iterTest != endTest)
			{
				if (testList->find(*iterTest) == -1)
				{
					m_test->erase(*iterTest);
				}
				iterTest++;
			}
 
			iterTest = testList->begin();
			endTest = testList->end();
			while (iterTest != endTest)
			{
				if (m_test->find(*iterTest) == -1)
				{
					m_test->add(*iterTest);
				}
				iterTest++;			
			}
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ClauseImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ClauseImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("body");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("body")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("bodyOutput");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyOutput")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("decider");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("decider")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("predecessorClause");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("predecessorClause")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("successorClause");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("successorClause")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("test");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("test")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void ClauseImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ElementImpl::loadNode(nodeName, loadHandler);
}

void ClauseImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
		{
			std::shared_ptr<Bag<uml::ExecutableNode>> _body = getBody();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExecutableNode>  _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_body->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
		{
			std::shared_ptr<Bag<uml::OutputPin>> _bodyOutput = getBodyOutput();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::OutputPin>  _r = std::dynamic_pointer_cast<uml::OutputPin>(ref);
				if (_r != nullptr)
				{
					_bodyOutput->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>( references.front() );
				setDecider(_decider);
			}
			
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
		{
			std::shared_ptr<Bag<uml::Clause>> _predecessorClause = getPredecessorClause();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Clause>  _r = std::dynamic_pointer_cast<uml::Clause>(ref);
				if (_r != nullptr)
				{
					_predecessorClause->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
		{
			std::shared_ptr<Bag<uml::Clause>> _successorClause = getSuccessorClause();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Clause>  _r = std::dynamic_pointer_cast<uml::Clause>(ref);
				if (_r != nullptr)
				{
					_successorClause->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
		{
			std::shared_ptr<Bag<uml::ExecutableNode>> _test = getTest();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExecutableNode>  _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_test->push_back(_r);
				}
			}
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void ClauseImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ClauseImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::ExecutableNode>("body", this->getBody());
		saveHandler->addReferences<uml::OutputPin>("bodyOutput", this->getBodyOutput());
		saveHandler->addReference(this->getDecider(), "decider", getDecider()->eClass() != uml::umlPackage::eInstance()->getOutputPin_Class()); 
		saveHandler->addReferences<uml::Clause>("predecessorClause", this->getPredecessorClause());
		saveHandler->addReferences<uml::Clause>("successorClause", this->getSuccessorClause());
		saveHandler->addReferences<uml::ExecutableNode>("test", this->getTest());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

