
#include "ocl/Evaluations/impl/LoopExpEvalImpl.hpp"
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


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Evaluations/PropertyCallExpEval.hpp"
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
LoopExpEvalImpl::LoopExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LoopExpEvalImpl::~LoopExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


LoopExpEvalImpl::LoopExpEvalImpl(const LoopExpEvalImpl & obj): LoopExpEvalImpl()
{
	*this = obj;
}

LoopExpEvalImpl& LoopExpEvalImpl::operator=(const LoopExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	PropertyCallExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LoopExpEval 
	 * which is generated by the compiler (as LoopExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LoopExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LoopExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_bodyEvals  = obj.getBodyEvals();
	m_iterators  = obj.getIterators();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LoopExpEvalImpl::copy() const
{
	std::shared_ptr<LoopExpEvalImpl> element(new LoopExpEvalImpl());
	*element =(*this);
	element->setThisLoopExpEvalPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference bodyEvals */
std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> LoopExpEvalImpl::getBodyEvals() const
{
	if(m_bodyEvals == nullptr)
	{
		m_bodyEvals.reset(new Bag<ocl::Evaluations::OclExpEval>());
		
		
	}
    return m_bodyEvals;
}

/* Getter & Setter for reference iterators */
std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::StringValue>> LoopExpEvalImpl::getIterators() const
{
	if(m_iterators == nullptr)
	{
		m_iterators.reset(new Bag<fUML::Semantics::SimpleClassifiers::StringValue>());
		
		
	}
    return m_iterators;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LoopExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void LoopExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void LoopExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("bodyEvals");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyEvals")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("iterators");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("iterators")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	PropertyCallExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void LoopExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PropertyCallExpEvalImpl::loadNode(nodeName, loadHandler);
}

void LoopExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_BODYEVALS:
		{
			std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> _bodyEvals = getBodyEvals();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Evaluations::OclExpEval>  _r = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(ref);
				if (_r != nullptr)
				{
					_bodyEvals->push_back(_r);
				}
			}
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_ITERATORS:
		{
			std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::StringValue>> _iterators = getIterators();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue>  _r = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(ref);
				if (_r != nullptr)
				{
					_iterators->push_back(_r);
				}
			}
			return;
		}
	}
	PropertyCallExpEvalImpl::resolveReferences(featureID, references);
}

void LoopExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PropertyCallExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LoopExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Evaluations::OclExpEval>("bodyEvals", this->getBodyEvals());
		saveHandler->addReferences<fUML::Semantics::SimpleClassifiers::StringValue>("iterators", this->getIterators());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> LoopExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getLoopExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any LoopExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_BODYEVALS:
			return eAnyBag(getBodyEvals(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS); //487
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_ITERATORS:
			return eAnyBag(getIterators(),fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::STRINGVALUE_CLASS); //488
	}
	return PropertyCallExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool LoopExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_BODYEVALS:
			return getBodyEvals() != nullptr; //487
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_ITERATORS:
			return getIterators() != nullptr; //488
	}
	return PropertyCallExpEvalImpl::internalEIsSet(featureID);
}

bool LoopExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_BODYEVALS:
		{
			// CAST Any to Bag<ocl::Evaluations::OclExpEval>
			if((newValue->isContainer()) && (ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> bodyEvalsList= newValue->get<std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>>>();
					std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> _bodyEvals=getBodyEvals();
					for(const std::shared_ptr<ocl::Evaluations::OclExpEval> indexBodyEvals: *_bodyEvals)
					{
						if (bodyEvalsList->find(indexBodyEvals) == -1)
						{
							_bodyEvals->erase(indexBodyEvals);
						}
					}

					for(const std::shared_ptr<ocl::Evaluations::OclExpEval> indexBodyEvals: *bodyEvalsList)
					{
						if (_bodyEvals->find(indexBodyEvals) == -1)
						{
							_bodyEvals->add(indexBodyEvals);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_ITERATORS:
		{
			// CAST Any to Bag<fUML::Semantics::SimpleClassifiers::StringValue>
			if((newValue->isContainer()) && (fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::STRINGVALUE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::StringValue>> iteratorsList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::StringValue>>>();
					std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::StringValue>> _iterators=getIterators();
					for(const std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> indexIterators: *_iterators)
					{
						if (iteratorsList->find(indexIterators) == -1)
						{
							_iterators->erase(indexIterators);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> indexIterators: *iteratorsList)
					{
						if (_iterators->find(indexIterators) == -1)
						{
							_iterators->add(indexIterators);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
	}

	return PropertyCallExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any LoopExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = PropertyCallExpEvalImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::LoopExpEval> LoopExpEvalImpl::getThisLoopExpEvalPtr() const
{
	return m_thisLoopExpEvalPtr.lock();
}
void LoopExpEvalImpl::setThisLoopExpEvalPtr(std::weak_ptr<ocl::Evaluations::LoopExpEval> thisLoopExpEvalPtr)
{
	m_thisLoopExpEvalPtr = thisLoopExpEvalPtr;
	setThisPropertyCallExpEvalPtr(thisLoopExpEvalPtr);
}


