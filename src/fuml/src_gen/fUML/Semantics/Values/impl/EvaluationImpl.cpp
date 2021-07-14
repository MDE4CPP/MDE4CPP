#include "fUML/Semantics/Values/impl/EvaluationImpl.hpp"

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
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/umlFactory.hpp"


#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************
EvaluationImpl::EvaluationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EvaluationImpl::~EvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Evaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


EvaluationImpl::EvaluationImpl(const EvaluationImpl & obj): EvaluationImpl()
{
	*this = obj;
}

EvaluationImpl& EvaluationImpl::operator=(const EvaluationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Loci::SemanticVisitorImpl::operator=(obj);
	Evaluation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Evaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_locus  = obj.getLocus();
	m_specification  = obj.getSpecification();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EvaluationImpl::copy() const
{
	std::shared_ptr<EvaluationImpl> element(new EvaluationImpl());
	*element =(*this);
	element->setThisEvaluationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> EvaluationImpl::eStaticClass() const
{
	return fUML::Semantics::Values::ValuesPackage::eInstance()->getEvaluation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> EvaluationImpl::evaluate()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference locus
*/
std::shared_ptr<fUML::Semantics::Loci::Locus> EvaluationImpl::getLocus() const
{
//assert(m_locus);
    return m_locus;
}
void EvaluationImpl::setLocus(std::shared_ptr<fUML::Semantics::Loci::Locus> _locus)
{
    m_locus = _locus;
	
}


/*
Getter & Setter for reference specification
*/
std::shared_ptr<uml::ValueSpecification> EvaluationImpl::getSpecification() const
{
//assert(m_specification);
    return m_specification;
}
void EvaluationImpl::setSpecification(std::shared_ptr<uml::ValueSpecification> _specification)
{
    m_specification = _specification;
	
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<Evaluation> EvaluationImpl::getThisEvaluationPtr() const
{
	return m_thisEvaluationPtr.lock();
}
void EvaluationImpl::setThisEvaluationPtr(std::weak_ptr<Evaluation> thisEvaluationPtr)
{
	m_thisEvaluationPtr = thisEvaluationPtr;
	setThisSemanticVisitorPtr(thisEvaluationPtr);
}
std::shared_ptr<ecore::EObject> EvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_LOCUS:
			return eAny(getLocus()); //421
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
			return eAny(getSpecification()); //420
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::eGet(featureID, resolve, coreType);
}
bool EvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_LOCUS:
			return getLocus() != nullptr; //421
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
			return getSpecification() != nullptr; //420
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::internalEIsSet(featureID);
}
bool EvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(_temp);
			setLocus(_locus); //421
			return true;
		}
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _specification = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setSpecification(_specification); //420
			return true;
		}
	}

	return fUML::Semantics::Loci::SemanticVisitorImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any EvaluationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 4204
		case ValuesPackage::EVALUATION_OPERATION_EVALUATE:
		{
			result = eAny(this->evaluate());
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Loci::SemanticVisitorImpl::eInvoke(operationID, arguments);
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
void EvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("locus");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("locus")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("specification");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("specification")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Loci::SemanticVisitorImpl::loadAttributes(loadHandler, attr_list);
}

void EvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Loci::SemanticVisitorImpl::loadNode(nodeName, loadHandler);
}

void EvaluationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_LOCUS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>( references.front() );
				setLocus(_locus);
			}
			
			return;
		}

		case fUML::Semantics::Values::ValuesPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ValueSpecification> _specification = std::dynamic_pointer_cast<uml::ValueSpecification>( references.front() );
				setSpecification(_specification);
			}
			
			return;
		}
	}
	fUML::Semantics::Loci::SemanticVisitorImpl::resolveReferences(featureID, references);
}

void EvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void EvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Values::ValuesPackage> package = fUML::Semantics::Values::ValuesPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getLocus(), "locus", getLocus()->eClass() != fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class()); 
		saveHandler->addReference(this->getSpecification(), "specification", getSpecification()->eClass() != uml::umlPackage::eInstance()->getValueSpecification_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

