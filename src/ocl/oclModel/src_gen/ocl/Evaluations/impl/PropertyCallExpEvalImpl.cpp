
#include "ocl/Evaluations/impl/PropertyCallExpEvalImpl.hpp"
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
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
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
PropertyCallExpEvalImpl::PropertyCallExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PropertyCallExpEvalImpl::~PropertyCallExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PropertyCallExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


PropertyCallExpEvalImpl::PropertyCallExpEvalImpl(const PropertyCallExpEvalImpl & obj): PropertyCallExpEvalImpl()
{
	*this = obj;
}

PropertyCallExpEvalImpl& PropertyCallExpEvalImpl::operator=(const PropertyCallExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PropertyCallExpEval 
	 * which is generated by the compiler (as PropertyCallExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PropertyCallExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PropertyCallExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_source  = obj.getSource();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PropertyCallExpEvalImpl::copy() const
{
	std::shared_ptr<PropertyCallExpEvalImpl> element(new PropertyCallExpEvalImpl());
	*element =(*this);
	element->setThisPropertyCallExpEvalPtr(element);
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
/* Getter & Setter for reference source */
std::shared_ptr<ocl::Evaluations::OclExpEval> PropertyCallExpEvalImpl::getSource() const
{
    return m_source;
}
void PropertyCallExpEvalImpl::setSource(std::shared_ptr<ocl::Evaluations::OclExpEval> _source)
{
    m_source = _source;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PropertyCallExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void PropertyCallExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PropertyCallExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("source");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("source")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	OclExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void PropertyCallExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpEvalImpl::loadNode(nodeName, loadHandler);
}

void PropertyCallExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::PROPERTYCALLEXPEVAL_ATTRIBUTE_SOURCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _source = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setSource(_source);
			}
			
			return;
		}
	}
	OclExpEvalImpl::resolveReferences(featureID, references);
}

void PropertyCallExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PropertyCallExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getSource(), "source", getSource()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> PropertyCallExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getPropertyCallExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any PropertyCallExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::PROPERTYCALLEXPEVAL_ATTRIBUTE_SOURCE:
			return eAny(getSource(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //736
	}
	return OclExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool PropertyCallExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::PROPERTYCALLEXPEVAL_ATTRIBUTE_SOURCE:
			return getSource() != nullptr; //736
	}
	return OclExpEvalImpl::internalEIsSet(featureID);
}

bool PropertyCallExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::PROPERTYCALLEXPEVAL_ATTRIBUTE_SOURCE:
		{
			// CAST Any to ocl::Evaluations::OclExpEval
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _source = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setSource(_source); //736
			return true;
		}
	}

	return OclExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any PropertyCallExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = OclExpEvalImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::PropertyCallExpEval> PropertyCallExpEvalImpl::getThisPropertyCallExpEvalPtr() const
{
	return m_thisPropertyCallExpEvalPtr.lock();
}
void PropertyCallExpEvalImpl::setThisPropertyCallExpEvalPtr(std::weak_ptr<ocl::Evaluations::PropertyCallExpEval> thisPropertyCallExpEvalPtr)
{
	m_thisPropertyCallExpEvalPtr = thisPropertyCallExpEvalPtr;
	setThisOclExpEvalPtr(thisPropertyCallExpEvalPtr);
}


