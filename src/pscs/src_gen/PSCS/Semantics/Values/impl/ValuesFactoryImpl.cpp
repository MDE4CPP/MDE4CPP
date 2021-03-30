#include "PSCS/Semantics/Values/impl/ValuesFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/Semantics/Values/ValuesPackage.hpp"
#include "PSCS/Semantics/Values/impl/CS_OpaqueExpressionEvaluationImpl.hpp"



using namespace PSCS::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************

ValuesFactoryImpl::ValuesFactoryImpl()
{
	m_idMap.insert(std::make_pair("PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation", ValuesPackage::CS_OPAQUEEXPRESSIONEVALUATION_CLASS));
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
		case ValuesPackage::CS_OPAQUEEXPRESSIONEVALUATION_CLASS:
		{
				return this->createCS_OpaqueExpressionEvaluation(metaElementID);
			
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

std::shared_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation> ValuesFactoryImpl::createCS_OpaqueExpressionEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluationImpl> element(new PSCS::Semantics::Values::CS_OpaqueExpressionEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_OpaqueExpressionEvaluationPtr(element);
	return element;
}


