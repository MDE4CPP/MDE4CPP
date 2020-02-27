#include "fUML/Semantics/Classification/impl/ClassificationFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/Classification/ClassificationPackage.hpp"
#include "fUML/Semantics/Classification/impl/InstanceValueEvaluationImpl.hpp"



using namespace fUML::Semantics::Classification;

//*********************************
// Constructor / Destructor
//*********************************

ClassificationFactoryImpl::ClassificationFactoryImpl()
{
	m_idMap.insert(std::make_pair("fUML::Semantics::Classification::InstanceValueEvaluation", ClassificationPackage::INSTANCEVALUEEVALUATION_CLASS));
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
		case ClassificationPackage::INSTANCEVALUEEVALUATION_CLASS:
		{
				return this->createInstanceValueEvaluation(metaElementID);
			
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

std::shared_ptr<fUML::Semantics::Classification::InstanceValueEvaluation> ClassificationFactoryImpl::createInstanceValueEvaluation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Classification::InstanceValueEvaluationImpl> element(new fUML::Semantics::Classification::InstanceValueEvaluationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInstanceValueEvaluationPtr(element);
	return element;
}

