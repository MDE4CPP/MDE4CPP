
#include "ocl/Evaluations/impl/AssociationClassCallExpEvalImpl.hpp"
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
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/NavigationCallExpEval.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
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
AssociationClassCallExpEvalImpl::AssociationClassCallExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AssociationClassCallExpEvalImpl::~AssociationClassCallExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AssociationClassCallExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


AssociationClassCallExpEvalImpl::AssociationClassCallExpEvalImpl(const AssociationClassCallExpEvalImpl & obj): AssociationClassCallExpEvalImpl()
{
	*this = obj;
}

AssociationClassCallExpEvalImpl& AssociationClassCallExpEvalImpl::operator=(const AssociationClassCallExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	NavigationCallExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of AssociationClassCallExpEval 
	 * which is generated by the compiler (as AssociationClassCallExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//AssociationClassCallExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AssociationClassCallExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_referredAssociationClass  = obj.getReferredAssociationClass();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> AssociationClassCallExpEvalImpl::copy() const
{
	std::shared_ptr<AssociationClassCallExpEvalImpl> element(new AssociationClassCallExpEvalImpl());
	*element =(*this);
	element->setThisAssociationClassCallExpEvalPtr(element);
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
/* Getter & Setter for reference referredAssociationClass */
const std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue>& AssociationClassCallExpEvalImpl::getReferredAssociationClass() const
{
    return m_referredAssociationClass;
}
void AssociationClassCallExpEvalImpl::setReferredAssociationClass(const std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue>& _referredAssociationClass)
{
    m_referredAssociationClass = _referredAssociationClass;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> AssociationClassCallExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void AssociationClassCallExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AssociationClassCallExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("referredAssociationClass");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referredAssociationClass")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NavigationCallExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void AssociationClassCallExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	NavigationCallExpEvalImpl::loadNode(nodeName, loadHandler);
}

void AssociationClassCallExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::ASSOCIATIONCLASSCALLEXPEVAL_ATTRIBUTE_REFERREDASSOCIATIONCLASS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _referredAssociationClass = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>( references.front() );
				setReferredAssociationClass(_referredAssociationClass);
			}
			
			return;
		}
	}
	NavigationCallExpEvalImpl::resolveReferences(featureID, references);
}

void AssociationClassCallExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NavigationCallExpEvalImpl::saveContent(saveHandler);
	
	ModelPropertyCallExpEvalImpl::saveContent(saveHandler);
	
	PropertyCallExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void AssociationClassCallExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getReferredAssociationClass(), "referredAssociationClass", getReferredAssociationClass()->eClass() != fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getStringValue_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& AssociationClassCallExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getAssociationClassCallExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any AssociationClassCallExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::ASSOCIATIONCLASSCALLEXPEVAL_ATTRIBUTE_REFERREDASSOCIATIONCLASS:
			return eAny(getReferredAssociationClass(),fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::STRINGVALUE_CLASS,false); //49
	}
	return NavigationCallExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool AssociationClassCallExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::ASSOCIATIONCLASSCALLEXPEVAL_ATTRIBUTE_REFERREDASSOCIATIONCLASS:
			return getReferredAssociationClass() != nullptr; //49
	}
	return NavigationCallExpEvalImpl::internalEIsSet(featureID);
}

bool AssociationClassCallExpEvalImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::ASSOCIATIONCLASSCALLEXPEVAL_ATTRIBUTE_REFERREDASSOCIATIONCLASS:
		{
			// CAST Any to fUML::Semantics::SimpleClassifiers::StringValue
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _referredAssociationClass = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(_temp);
			setReferredAssociationClass(_referredAssociationClass); //49
			return true;
		}
	}

	return NavigationCallExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any AssociationClassCallExpEvalImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = NavigationCallExpEvalImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::AssociationClassCallExpEval> AssociationClassCallExpEvalImpl::getThisAssociationClassCallExpEvalPtr() const
{
	return m_thisAssociationClassCallExpEvalPtr.lock();
}
void AssociationClassCallExpEvalImpl::setThisAssociationClassCallExpEvalPtr(std::weak_ptr<ocl::Evaluations::AssociationClassCallExpEval> thisAssociationClassCallExpEvalPtr)
{
	m_thisAssociationClassCallExpEvalPtr = thisAssociationClassCallExpEvalPtr;
	setThisNavigationCallExpEvalPtr(thisAssociationClassCallExpEvalPtr);
}


