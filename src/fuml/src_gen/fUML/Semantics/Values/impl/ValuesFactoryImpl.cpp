#include "fUML/Semantics/Values/impl/ValuesFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "fUML/Semantics/Values/impl/EvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralBooleanEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralIntegerEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralNullEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralRealEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralStringEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralUnlimitedNaturalEvaluationImpl.hpp"
#include "fUML/Semantics/Values/impl/ValueImpl.hpp"



using namespace fUML::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************

ValuesFactoryImpl::ValuesFactoryImpl()
{
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralBooleanEvaluation", ValuesPackage::LITERALBOOLEANEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralIntegerEvaluation", ValuesPackage::LITERALINTEGEREVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralNullEvaluation", ValuesPackage::LITERALNULLEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralRealEvaluation", ValuesPackage::LITERALREALEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralStringEvaluation", ValuesPackage::LITERALSTRINGEVALUATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluation", ValuesPackage::LITERALUNLIMITEDNATURALEVALUATION_CLASS));
}

ValuesFactoryImpl::~ValuesFactoryImpl()
{
}

ValuesFactory* ValuesFactoryImpl::create()
{
	return new ValuesFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> ValuesFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case ValuesPackage::LITERALBOOLEANEVALUATION_CLASS:
		{
				return this->createLiteralBooleanEvaluation(metaElementID);
			
		}
		case ValuesPackage::LITERALINTEGEREVALUATION_CLASS:
		{
				return this->createLiteralIntegerEvaluation(metaElementID);
			
		}
		case ValuesPackage::LITERALNULLEVALUATION_CLASS:
		{
				return this->createLiteralNullEvaluation(metaElementID);
			
		}
		case ValuesPackage::LITERALREALEVALUATION_CLASS:
		{
				return this->createLiteralRealEvaluation(metaElementID);
			
		}
		case ValuesPackage::LITERALSTRINGEVALUATION_CLASS:
		{
				return this->createLiteralStringEvaluation(metaElementID);
			
		}
		case ValuesPackage::LITERALUNLIMITEDNATURALEVALUATION_CLASS:
		{
				return this->createLiteralUnlimitedNaturalEvaluation(metaElementID);
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> ValuesFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> ValuesFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}

std::shared_ptr<fUML::Semantics::Values::LiteralBooleanEvaluation> ValuesFactoryImpl::createLiteralBooleanEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralBooleanEvaluationImpl> element(new fUML::Semantics::Values::LiteralBooleanEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralBooleanEvaluationPtr(element);
	return element;
}

std::shared_ptr<fUML::Semantics::Values::LiteralIntegerEvaluation> ValuesFactoryImpl::createLiteralIntegerEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralIntegerEvaluationImpl> element(new fUML::Semantics::Values::LiteralIntegerEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralIntegerEvaluationPtr(element);
	return element;
}

std::shared_ptr<fUML::Semantics::Values::LiteralNullEvaluation> ValuesFactoryImpl::createLiteralNullEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralNullEvaluationImpl> element(new fUML::Semantics::Values::LiteralNullEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralNullEvaluationPtr(element);
	return element;
}

std::shared_ptr<fUML::Semantics::Values::LiteralRealEvaluation> ValuesFactoryImpl::createLiteralRealEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralRealEvaluationImpl> element(new fUML::Semantics::Values::LiteralRealEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralRealEvaluationPtr(element);
	return element;
}

std::shared_ptr<fUML::Semantics::Values::LiteralStringEvaluation> ValuesFactoryImpl::createLiteralStringEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralStringEvaluationImpl> element(new fUML::Semantics::Values::LiteralStringEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralStringEvaluationPtr(element);
	return element;
}

std::shared_ptr<fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluation> ValuesFactoryImpl::createLiteralUnlimitedNaturalEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl> element(new fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralUnlimitedNaturalEvaluationPtr(element);
	return element;
}


