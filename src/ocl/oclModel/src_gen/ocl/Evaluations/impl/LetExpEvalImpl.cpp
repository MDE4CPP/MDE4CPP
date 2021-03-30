#include "ocl/Evaluations/impl/LetExpEvalImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"


#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
LetExpEvalImpl::LetExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LetExpEvalImpl::~LetExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LetExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


LetExpEvalImpl::LetExpEvalImpl(const LetExpEvalImpl & obj): LetExpEvalImpl()
{
	*this = obj;
}

LetExpEvalImpl& LetExpEvalImpl::operator=(const LetExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpEvalImpl::operator=(obj);
	LetExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LetExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_in  = obj.getIn();
	m_initExpression  = obj.getInitExpression();
	m_variable  = obj.getVariable();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LetExpEvalImpl::copy() const
{
	std::shared_ptr<LetExpEvalImpl> element(new LetExpEvalImpl());
	*element =(*this);
	element->setThisLetExpEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LetExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getLetExpEval_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference in
*/
std::shared_ptr<ocl::Evaluations::OclExpEval> LetExpEvalImpl::getIn() const
{
//assert(m_in);
    return m_in;
}
void LetExpEvalImpl::setIn(std::shared_ptr<ocl::Evaluations::OclExpEval> _in)
{
    m_in = _in;
}


/*
Getter & Setter for reference initExpression
*/
std::shared_ptr<ocl::Evaluations::OclExpEval> LetExpEvalImpl::getInitExpression() const
{

    return m_initExpression;
}
void LetExpEvalImpl::setInitExpression(std::shared_ptr<ocl::Evaluations::OclExpEval> _initExpression)
{
    m_initExpression = _initExpression;
}


/*
Getter & Setter for reference variable
*/
std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> LetExpEvalImpl::getVariable() const
{
//assert(m_variable);
    return m_variable;
}
void LetExpEvalImpl::setVariable(std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _variable)
{
    m_variable = _variable;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<LetExpEval> LetExpEvalImpl::getThisLetExpEvalPtr() const
{
	return m_thisLetExpEvalPtr.lock();
}
void LetExpEvalImpl::setThisLetExpEvalPtr(std::weak_ptr<LetExpEval> thisLetExpEvalPtr)
{
	m_thisLetExpEvalPtr = thisLetExpEvalPtr;
	setThisOclExpEvalPtr(thisLetExpEvalPtr);
}
std::shared_ptr<ecore::EObject> LetExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LetExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_IN:
			return eAny(getIn()); //426
		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_INITEXPRESSION:
			return eAny(getInitExpression()); //427
		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_VARIABLE:
			return eAny(getVariable()); //428
	}
	return OclExpEvalImpl::eGet(featureID, resolve, coreType);
}
bool LetExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_IN:
			return getIn() != nullptr; //426
		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_INITEXPRESSION:
			return getInitExpression() != nullptr; //427
		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_VARIABLE:
			return getVariable() != nullptr; //428
	}
	return OclExpEvalImpl::internalEIsSet(featureID);
}
bool LetExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_IN:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _in = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setIn(_in); //426
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_INITEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _initExpression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setInitExpression(_initExpression); //427
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_VARIABLE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _variable = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(_temp);
			setVariable(_variable); //428
			return true;
		}
	}

	return OclExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LetExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LetExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("in");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("in")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("initExpression");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("initExpression")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("variable");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("variable")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void LetExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpEvalImpl::loadNode(nodeName, loadHandler);
}

void LetExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_IN:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _in = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setIn(_in);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_INITEXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _initExpression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setInitExpression(_initExpression);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::LETEXPEVAL_ATTRIBUTE_VARIABLE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _variable = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>( references.front() );
				setVariable(_variable);
			}
			
			return;
		}
	}
	OclExpEvalImpl::resolveReferences(featureID, references);
}

void LetExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void LetExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getIn(), "in", getIn()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
		saveHandler->addReference(this->getInitExpression(), "initExpression", getInitExpression()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
		saveHandler->addReference(this->getVariable(), "variable", getVariable()->eClass() != fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getStringValue_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

