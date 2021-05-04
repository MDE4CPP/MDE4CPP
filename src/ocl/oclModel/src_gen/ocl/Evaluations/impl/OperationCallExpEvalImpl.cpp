#include "ocl/Evaluations/impl/OperationCallExpEvalImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"


#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/ModelPropertyCallExpEval.hpp"
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
OperationCallExpEvalImpl::OperationCallExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OperationCallExpEvalImpl::~OperationCallExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OperationCallExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


OperationCallExpEvalImpl::OperationCallExpEvalImpl(const OperationCallExpEvalImpl & obj): OperationCallExpEvalImpl()
{
	*this = obj;
}

OperationCallExpEvalImpl& OperationCallExpEvalImpl::operator=(const OperationCallExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	ModelPropertyCallExpEvalImpl::operator=(obj);
	OperationCallExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OperationCallExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> _arguments = obj.getArguments();
	m_arguments.reset(new Bag<ocl::Evaluations::OclExpEval>(*(obj.getArguments().get())));
	m_referredOperation  = obj.getReferredOperation();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OperationCallExpEvalImpl::copy() const
{
	std::shared_ptr<OperationCallExpEvalImpl> element(new OperationCallExpEvalImpl());
	*element =(*this);
	element->setThisOperationCallExpEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OperationCallExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getOperationCallExpEval_Class();
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
Getter & Setter for reference arguments
*/
std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> OperationCallExpEvalImpl::getArguments() const
{
	if(m_arguments == nullptr)
	{
		m_arguments.reset(new Bag<ocl::Evaluations::OclExpEval>());
		
		
	}

    return m_arguments;
}



/*
Getter & Setter for reference referredOperation
*/
std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> OperationCallExpEvalImpl::getReferredOperation() const
{
//assert(m_referredOperation);
    return m_referredOperation;
}
void OperationCallExpEvalImpl::setReferredOperation(std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _referredOperation)
{
    m_referredOperation = _referredOperation;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<OperationCallExpEval> OperationCallExpEvalImpl::getThisOperationCallExpEvalPtr() const
{
	return m_thisOperationCallExpEvalPtr.lock();
}
void OperationCallExpEvalImpl::setThisOperationCallExpEvalPtr(std::weak_ptr<OperationCallExpEval> thisOperationCallExpEvalPtr)
{
	m_thisOperationCallExpEvalPtr = thisOperationCallExpEvalPtr;
	setThisModelPropertyCallExpEvalPtr(thisOperationCallExpEvalPtr);
}
std::shared_ptr<ecore::EObject> OperationCallExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any OperationCallExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OPERATIONCALLEXPEVAL_ATTRIBUTE_ARGUMENTS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ocl::Evaluations::OclExpEval>::iterator iter = m_arguments->begin();
			Bag<ocl::Evaluations::OclExpEval>::iterator end = m_arguments->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //668
		}
		case ocl::Evaluations::EvaluationsPackage::OPERATIONCALLEXPEVAL_ATTRIBUTE_REFERREDOPERATION:
			return eAny(getReferredOperation()); //667
	}
	return ModelPropertyCallExpEvalImpl::eGet(featureID, resolve, coreType);
}
bool OperationCallExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OPERATIONCALLEXPEVAL_ATTRIBUTE_ARGUMENTS:
			return getArguments() != nullptr; //668
		case ocl::Evaluations::EvaluationsPackage::OPERATIONCALLEXPEVAL_ATTRIBUTE_REFERREDOPERATION:
			return getReferredOperation() != nullptr; //667
	}
	return ModelPropertyCallExpEvalImpl::internalEIsSet(featureID);
}
bool OperationCallExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OPERATIONCALLEXPEVAL_ATTRIBUTE_ARGUMENTS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> argumentsList(new Bag<ocl::Evaluations::OclExpEval>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				argumentsList->add(std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(*iter));
				iter++;
			}
			
			Bag<ocl::Evaluations::OclExpEval>::iterator iterArguments = m_arguments->begin();
			Bag<ocl::Evaluations::OclExpEval>::iterator endArguments = m_arguments->end();
			while (iterArguments != endArguments)
			{
				if (argumentsList->find(*iterArguments) == -1)
				{
					m_arguments->erase(*iterArguments);
				}
				iterArguments++;
			}
 
			iterArguments = argumentsList->begin();
			endArguments = argumentsList->end();
			while (iterArguments != endArguments)
			{
				if (m_arguments->find(*iterArguments) == -1)
				{
					m_arguments->add(*iterArguments);
				}
				iterArguments++;			
			}
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::OPERATIONCALLEXPEVAL_ATTRIBUTE_REFERREDOPERATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _referredOperation = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(_temp);
			setReferredOperation(_referredOperation); //667
			return true;
		}
	}

	return ModelPropertyCallExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void OperationCallExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OperationCallExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("arguments");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("arguments")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("referredOperation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referredOperation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ModelPropertyCallExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void OperationCallExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ModelPropertyCallExpEvalImpl::loadNode(nodeName, loadHandler);
}

void OperationCallExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OPERATIONCALLEXPEVAL_ATTRIBUTE_ARGUMENTS:
		{
			std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> _arguments = getArguments();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Evaluations::OclExpEval>  _r = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(ref);
				if (_r != nullptr)
				{
					_arguments->push_back(_r);
				}
			}
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::OPERATIONCALLEXPEVAL_ATTRIBUTE_REFERREDOPERATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _referredOperation = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>( references.front() );
				setReferredOperation(_referredOperation);
			}
			
			return;
		}
	}
	ModelPropertyCallExpEvalImpl::resolveReferences(featureID, references);
}

void OperationCallExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ModelPropertyCallExpEvalImpl::saveContent(saveHandler);
	
	PropertyCallExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void OperationCallExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Evaluations::OclExpEval>("arguments", this->getArguments());
		saveHandler->addReference(this->getReferredOperation(), "referredOperation", getReferredOperation()->eClass() != fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getStringValue_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

