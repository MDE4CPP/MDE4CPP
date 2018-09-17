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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Clause.hpp"

#include "uml/Comment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ExecutableNode.hpp"

#include "uml/OutputPin.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	//References
		m_body.reset(new Bag<uml::ExecutableNode>());
	
	

		m_bodyOutput.reset(new Bag<uml::OutputPin>());
	
	

	

		m_predecessorClause.reset(new Bag<uml::Clause>());
	
	

		m_successorClause.reset(new Bag<uml::Clause>());
	
	

		m_test.reset(new Bag<uml::ExecutableNode>());
	
	

	//Init references
	
	

	
	

	

	
	

	
	

	
	
}

ClauseImpl::~ClauseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Clause "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ClauseImpl::ClauseImpl(std::weak_ptr<uml::Element > par_owner)
			:ClauseImpl()
			{
			    m_owner = par_owner;
			}






ClauseImpl::ClauseImpl(const ClauseImpl & obj):ClauseImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Clause "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::ExecutableNode>> _body = obj.getBody();
	m_body.reset(new Bag<uml::ExecutableNode>(*(obj.getBody().get())));

	std::shared_ptr<Bag<uml::OutputPin>> _bodyOutput = obj.getBodyOutput();
	m_bodyOutput.reset(new Bag<uml::OutputPin>(*(obj.getBodyOutput().get())));

	m_decider  = obj.getDecider();

	m_owner  = obj.getOwner();

	std::shared_ptr<Bag<uml::Clause>> _predecessorClause = obj.getPredecessorClause();
	m_predecessorClause.reset(new Bag<uml::Clause>(*(obj.getPredecessorClause().get())));

	std::shared_ptr<Bag<uml::Clause>> _successorClause = obj.getSuccessorClause();
	m_successorClause.reset(new Bag<uml::Clause>(*(obj.getSuccessorClause().get())));

	std::shared_ptr<Bag<uml::ExecutableNode>> _test = obj.getTest();
	m_test.reset(new Bag<uml::ExecutableNode>(*(obj.getTest().get())));


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

std::shared_ptr<ecore::EObject>  ClauseImpl::copy() const
{
	std::shared_ptr<ClauseImpl> element(new ClauseImpl(*this));
	element->setThisClausePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ClauseImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getClause_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ClauseImpl::body_output_pins(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClauseImpl::decider_output(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClauseImpl::test_and_body(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::ExecutableNode>> ClauseImpl::getBody() const
{

    return m_body;
}


std::shared_ptr<Bag<uml::OutputPin>> ClauseImpl::getBodyOutput() const
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

std::shared_ptr<Bag<uml::Clause>> ClauseImpl::getPredecessorClause() const
{

    return m_predecessorClause;
}


std::shared_ptr<Bag<uml::Clause>> ClauseImpl::getSuccessorClause() const
{

    return m_successorClause;
}


std::shared_ptr<Bag<uml::ExecutableNode>> ClauseImpl::getTest() const
{
//assert(m_test);
    return m_test;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ClauseImpl::getOwnedElement() const
{
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
		case UmlPackage::CLAUSE_EREFERENCE_BODY:
			return eAny(getBody()); //1424
		case UmlPackage::CLAUSE_EREFERENCE_BODYOUTPUT:
			return eAny(getBodyOutput()); //1425
		case UmlPackage::CLAUSE_EREFERENCE_DECIDER:
			return eAny(getDecider()); //1426
		case UmlPackage::CLAUSE_EREFERENCE_PREDECESSORCLAUSE:
			return eAny(getPredecessorClause()); //1427
		case UmlPackage::CLAUSE_EREFERENCE_SUCCESSORCLAUSE:
			return eAny(getSuccessorClause()); //1428
		case UmlPackage::CLAUSE_EREFERENCE_TEST:
			return eAny(getTest()); //1429
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool ClauseImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::CLAUSE_EREFERENCE_BODY:
			return getBody() != nullptr; //1424
		case UmlPackage::CLAUSE_EREFERENCE_BODYOUTPUT:
			return getBodyOutput() != nullptr; //1425
		case UmlPackage::CLAUSE_EREFERENCE_DECIDER:
			return getDecider() != nullptr; //1426
		case UmlPackage::CLAUSE_EREFERENCE_PREDECESSORCLAUSE:
			return getPredecessorClause() != nullptr; //1427
		case UmlPackage::CLAUSE_EREFERENCE_SUCCESSORCLAUSE:
			return getSuccessorClause() != nullptr; //1428
		case UmlPackage::CLAUSE_EREFERENCE_TEST:
			return getTest() != nullptr; //1429
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool ClauseImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::CLAUSE_EREFERENCE_DECIDER:
		{
			// BOOST CAST
			std::shared_ptr<uml::OutputPin> _decider = newValue->get<std::shared_ptr<uml::OutputPin>>();
			setDecider(_decider); //1426
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void ClauseImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	ElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ClauseImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::CLAUSE_EREFERENCE_BODY:
		{
			std::shared_ptr<Bag<uml::ExecutableNode>> _body = getBody();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExecutableNode> _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_body->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::CLAUSE_EREFERENCE_BODYOUTPUT:
		{
			std::shared_ptr<Bag<uml::OutputPin>> _bodyOutput = getBodyOutput();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::OutputPin> _r = std::dynamic_pointer_cast<uml::OutputPin>(ref);
				if (_r != nullptr)
				{
					_bodyOutput->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::CLAUSE_EREFERENCE_DECIDER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>( references.front() );
				setDecider(_decider);
			}
			
			return;
		}

		case UmlPackage::CLAUSE_EREFERENCE_PREDECESSORCLAUSE:
		{
			std::shared_ptr<Bag<uml::Clause>> _predecessorClause = getPredecessorClause();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Clause> _r = std::dynamic_pointer_cast<uml::Clause>(ref);
				if (_r != nullptr)
				{
					_predecessorClause->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::CLAUSE_EREFERENCE_SUCCESSORCLAUSE:
		{
			std::shared_ptr<Bag<uml::Clause>> _successorClause = getSuccessorClause();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Clause> _r = std::dynamic_pointer_cast<uml::Clause>(ref);
				if (_r != nullptr)
				{
					_successorClause->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::CLAUSE_EREFERENCE_TEST:
		{
			std::shared_ptr<Bag<uml::ExecutableNode>> _test = getTest();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExecutableNode> _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
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
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ClauseImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<uml::ExecutableNode>> body_list = this->getBody();
		for (std::shared_ptr<uml::ExecutableNode > object : *body_list)
		{ 
			saveHandler->addReferences("body", object);
		}
		std::shared_ptr<Bag<uml::OutputPin>> bodyOutput_list = this->getBodyOutput();
		for (std::shared_ptr<uml::OutputPin > object : *bodyOutput_list)
		{ 
			saveHandler->addReferences("bodyOutput", object);
		}
		saveHandler->addReference("decider", this->getDecider());
		std::shared_ptr<Bag<uml::Clause>> predecessorClause_list = this->getPredecessorClause();
		for (std::shared_ptr<uml::Clause > object : *predecessorClause_list)
		{ 
			saveHandler->addReferences("predecessorClause", object);
		}
		std::shared_ptr<Bag<uml::Clause>> successorClause_list = this->getSuccessorClause();
		for (std::shared_ptr<uml::Clause > object : *successorClause_list)
		{ 
			saveHandler->addReferences("successorClause", object);
		}
		std::shared_ptr<Bag<uml::ExecutableNode>> test_list = this->getTest();
		for (std::shared_ptr<uml::ExecutableNode > object : *test_list)
		{ 
			saveHandler->addReferences("test", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

