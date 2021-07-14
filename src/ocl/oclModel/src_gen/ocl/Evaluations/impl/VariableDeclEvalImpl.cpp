#include "ocl/Evaluations/impl/VariableDeclEvalImpl.hpp"

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
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"


#include "ocl/Evaluations/OclExpEval.hpp"
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
VariableDeclEvalImpl::VariableDeclEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

VariableDeclEvalImpl::~VariableDeclEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete VariableDeclEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


VariableDeclEvalImpl::VariableDeclEvalImpl(const VariableDeclEvalImpl & obj): VariableDeclEvalImpl()
{
	*this = obj;
}

VariableDeclEvalImpl& VariableDeclEvalImpl::operator=(const VariableDeclEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	VariableDeclEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy VariableDeclEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_initExp  = obj.getInitExp();
	m_name  = obj.getName();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> VariableDeclEvalImpl::copy() const
{
	std::shared_ptr<VariableDeclEvalImpl> element(new VariableDeclEvalImpl());
	*element =(*this);
	element->setThisVariableDeclEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> VariableDeclEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getVariableDeclEval_Class();
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
Getter & Setter for reference initExp
*/
std::shared_ptr<ocl::Evaluations::OclExpEval> VariableDeclEvalImpl::getInitExp() const
{
//assert(m_initExp);
    return m_initExp;
}
void VariableDeclEvalImpl::setInitExp(std::shared_ptr<ocl::Evaluations::OclExpEval> _initExp)
{
    m_initExp = _initExp;
	
}


/*
Getter & Setter for reference name
*/
std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> VariableDeclEvalImpl::getName() const
{
//assert(m_name);
    return m_name;
}
void VariableDeclEvalImpl::setName(std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _name)
{
    m_name = _name;
	
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<VariableDeclEval> VariableDeclEvalImpl::getThisVariableDeclEvalPtr() const
{
	return m_thisVariableDeclEvalPtr.lock();
}
void VariableDeclEvalImpl::setThisVariableDeclEvalPtr(std::weak_ptr<VariableDeclEval> thisVariableDeclEvalPtr)
{
	m_thisVariableDeclEvalPtr = thisVariableDeclEvalPtr;
}
std::shared_ptr<ecore::EObject> VariableDeclEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any VariableDeclEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::VARIABLEDECLEVAL_ATTRIBUTE_INITEXP:
			return eAny(getInitExp()); //970
		case ocl::Evaluations::EvaluationsPackage::VARIABLEDECLEVAL_ATTRIBUTE_NAME:
			return eAny(getName()); //971
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool VariableDeclEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::VARIABLEDECLEVAL_ATTRIBUTE_INITEXP:
			return getInitExp() != nullptr; //970
		case ocl::Evaluations::EvaluationsPackage::VARIABLEDECLEVAL_ATTRIBUTE_NAME:
			return getName() != nullptr; //971
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool VariableDeclEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::VARIABLEDECLEVAL_ATTRIBUTE_INITEXP:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _initExp = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setInitExp(_initExp); //970
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::VARIABLEDECLEVAL_ATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _name = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(_temp);
			setName(_name); //971
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any VariableDeclEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void VariableDeclEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void VariableDeclEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("initExp");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("initExp")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("name");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("name")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void VariableDeclEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void VariableDeclEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::VARIABLEDECLEVAL_ATTRIBUTE_INITEXP:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _initExp = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setInitExp(_initExp);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::VARIABLEDECLEVAL_ATTRIBUTE_NAME:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _name = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>( references.front() );
				setName(_name);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void VariableDeclEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void VariableDeclEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getInitExp(), "initExp", getInitExp()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
		saveHandler->addReference(this->getName(), "name", getName()->eClass() != fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getStringValue_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

