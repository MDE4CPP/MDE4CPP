#include "PSCS/Semantics/Classification/impl/ClassificationFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/Semantics/Classification/impl/CS_InstanceValueEvaluationImpl.hpp"



using namespace PSCS::Semantics::Classification;

//*********************************
// Constructor / Destructor
//*********************************

ClassificationFactoryImpl::ClassificationFactoryImpl()
{
	m_idMap.insert(std::make_pair("PSCS::Semantics::Classification::CS_InstanceValueEvaluation", ClassificationPackage::CS_INSTANCEVALUEEVALUATION_CLASS));
}

ClassificationFactoryImpl::~ClassificationFactoryImpl()
{
}

ClassificationFactory* ClassificationFactoryImpl::create()
{
	return new ClassificationFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> ClassificationFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case ClassificationPackage::CS_INSTANCEVALUEEVALUATION_CLASS:
		{
				return this->createCS_InstanceValueEvaluation(metaElementID);
			
			break;
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> ClassificationFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> ClassificationFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<PSCS::Semantics::Classification::CS_InstanceValueEvaluation> ClassificationFactoryImpl::createCS_InstanceValueEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::Classification::CS_InstanceValueEvaluationImpl> element(new PSCS::Semantics::Classification::CS_InstanceValueEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_InstanceValueEvaluationPtr(element);
	return element;
}

