
#include "ocl/Evaluations/impl/CollectionLiteralExpEvalImpl.hpp"
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
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ocl/Evaluations/CollectionLiteralPartEval.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "ocl/Evaluations/LiteralExpEval.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
CollectionLiteralExpEvalImpl::CollectionLiteralExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollectionLiteralExpEvalImpl::~CollectionLiteralExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollectionLiteralExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CollectionLiteralExpEvalImpl::CollectionLiteralExpEvalImpl(const CollectionLiteralExpEvalImpl & obj): CollectionLiteralExpEvalImpl()
{
	*this = obj;
}

CollectionLiteralExpEvalImpl& CollectionLiteralExpEvalImpl::operator=(const CollectionLiteralExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	LiteralExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CollectionLiteralExpEval 
	 * which is generated by the compiler (as CollectionLiteralExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CollectionLiteralExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollectionLiteralExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_parts  = obj.getParts();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CollectionLiteralExpEvalImpl::copy() const
{
	std::shared_ptr<CollectionLiteralExpEvalImpl> element(new CollectionLiteralExpEvalImpl());
	*element =(*this);
	element->setThisCollectionLiteralExpEvalPtr(element);
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
/* Getter & Setter for reference parts */
const std::shared_ptr<Bag<ocl::Evaluations::CollectionLiteralPartEval>>& CollectionLiteralExpEvalImpl::getParts() const
{
	if(m_parts == nullptr)
	{
		m_parts.reset(new Bag<ocl::Evaluations::CollectionLiteralPartEval>());
		
		
	}
    return m_parts;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CollectionLiteralExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CollectionLiteralExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollectionLiteralExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("parts");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parts")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	LiteralExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void CollectionLiteralExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LiteralExpEvalImpl::loadNode(nodeName, loadHandler);
}

void CollectionLiteralExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONLITERALEXPEVAL_ATTRIBUTE_PARTS:
		{
			std::shared_ptr<Bag<ocl::Evaluations::CollectionLiteralPartEval>> _parts = getParts();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEval>  _r = std::dynamic_pointer_cast<ocl::Evaluations::CollectionLiteralPartEval>(ref);
				if (_r != nullptr)
				{
					_parts->push_back(_r);
				}
			}
			return;
		}
	}
	LiteralExpEvalImpl::resolveReferences(featureID, references);
}

void CollectionLiteralExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CollectionLiteralExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Evaluations::CollectionLiteralPartEval>("parts", this->getParts());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& CollectionLiteralExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getCollectionLiteralExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CollectionLiteralExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONLITERALEXPEVAL_ATTRIBUTE_PARTS:
			return eAnyBag(getParts(),ocl::Evaluations::EvaluationsPackage::COLLECTIONLITERALPARTEVAL_CLASS); //166
	}
	return LiteralExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool CollectionLiteralExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONLITERALEXPEVAL_ATTRIBUTE_PARTS:
			return getParts() != nullptr; //166
	}
	return LiteralExpEvalImpl::internalEIsSet(featureID);
}

bool CollectionLiteralExpEvalImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONLITERALEXPEVAL_ATTRIBUTE_PARTS:
		{
			// CAST Any to Bag<ocl::Evaluations::CollectionLiteralPartEval>
			if((newValue->isContainer()) && (ocl::Evaluations::EvaluationsPackage::COLLECTIONLITERALPARTEVAL_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ocl::Evaluations::CollectionLiteralPartEval>> partsList= newValue->get<std::shared_ptr<Bag<ocl::Evaluations::CollectionLiteralPartEval>>>();
					std::shared_ptr<Bag<ocl::Evaluations::CollectionLiteralPartEval>> _parts=getParts();
					for(const std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEval> indexParts: *_parts)
					{
						if (partsList->find(indexParts) == -1)
						{
							_parts->erase(indexParts);
						}
					}

					for(const std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEval> indexParts: *partsList)
					{
						if (_parts->find(indexParts) == -1)
						{
							_parts->add(indexParts);
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

	return LiteralExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CollectionLiteralExpEvalImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = LiteralExpEvalImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::CollectionLiteralExpEval> CollectionLiteralExpEvalImpl::getThisCollectionLiteralExpEvalPtr() const
{
	return m_thisCollectionLiteralExpEvalPtr.lock();
}
void CollectionLiteralExpEvalImpl::setThisCollectionLiteralExpEvalPtr(std::weak_ptr<ocl::Evaluations::CollectionLiteralExpEval> thisCollectionLiteralExpEvalPtr)
{
	m_thisCollectionLiteralExpEvalPtr = thisCollectionLiteralExpEvalPtr;
	setThisLiteralExpEvalPtr(thisCollectionLiteralExpEvalPtr);
}


