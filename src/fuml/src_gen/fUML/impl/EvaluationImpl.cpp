#include "fUML/impl/EvaluationImpl.hpp"

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
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/Locus.hpp"

#include "fUML/SemanticVisitor.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
EvaluationImpl::EvaluationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	//Init references
	

	
}

EvaluationImpl::~EvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Evaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




EvaluationImpl::EvaluationImpl(const EvaluationImpl & obj):EvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Evaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  EvaluationImpl::copy() const
{
	std::shared_ptr<EvaluationImpl> element(new EvaluationImpl(*this));
	element->setThisEvaluationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> EvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getEvaluation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> EvaluationImpl::evaluate()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Locus > EvaluationImpl::getLocus() const
{
//assert(m_locus);
    return m_locus;
}
void EvaluationImpl::setLocus(std::shared_ptr<fUML::Locus> _locus)
{
    m_locus = _locus;
}

std::shared_ptr<uml::ValueSpecification > EvaluationImpl::getSpecification() const
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
		case FUMLPackage::EVALUATION_ATTRIBUTE_LOCUS:
			return eAny(getLocus()); //361
		case FUMLPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
			return eAny(getSpecification()); //360
	}
	return SemanticVisitorImpl::eGet(featureID, resolve, coreType);
}
bool EvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_ATTRIBUTE_LOCUS:
			return getLocus() != nullptr; //361
		case FUMLPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
			return getSpecification() != nullptr; //360
	}
	return SemanticVisitorImpl::internalEIsSet(featureID);
}
bool EvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_ATTRIBUTE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = newValue->get<std::shared_ptr<fUML::Locus>>();
			setLocus(_locus); //361
			return true;
		}
		case FUMLPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setSpecification(_specification); //360
			return true;
		}
	}

	return SemanticVisitorImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

	SemanticVisitorImpl::loadAttributes(loadHandler, attr_list);
}

void EvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	SemanticVisitorImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EvaluationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_ATTRIBUTE_LOCUS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Locus> _locus = std::dynamic_pointer_cast<fUML::Locus>( references.front() );
				setLocus(_locus);
			}
			
			return;
		}

		case FUMLPackage::EVALUATION_ATTRIBUTE_SPECIFICATION:
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
	SemanticVisitorImpl::resolveReferences(featureID, references);
}

void EvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void EvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		saveHandler->addReference("locus", this->getLocus());
		saveHandler->addReference("specification", this->getSpecification());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

