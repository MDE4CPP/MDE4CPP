#include "PSSM/Semantics/Actions/impl/ActionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSSM/Semantics/Actions/impl/SM_ReadSelfActionActivationImpl.hpp"



using namespace PSSM::Semantics::Actions;

std::shared_ptr<ActionsFactory> ActionsFactory::eInstance()
{
	static std::shared_ptr<ActionsFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ActionsFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

ActionsFactoryImpl::ActionsFactoryImpl()
{
	m_idMap.insert(std::make_pair("PSSM::Semantics::Actions::SM_ReadSelfActionActivation", ActionsPackage::SM_READSELFACTIONACTIVATION_CLASS));
}

ActionsFactoryImpl::~ActionsFactoryImpl()
{
}

ActionsFactory* ActionsFactoryImpl::create()
{
	return new ActionsFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> ActionsFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case ActionsPackage::SM_READSELFACTIONACTIVATION_CLASS:
		{
				return this->createSM_ReadSelfActionActivation(metaElementID);
			
			break;
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> ActionsFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> ActionsFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<PSSM::Semantics::Actions::SM_ReadSelfActionActivation> ActionsFactoryImpl::createSM_ReadSelfActionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::Actions::SM_ReadSelfActionActivationImpl> element(new PSSM::Semantics::Actions::SM_ReadSelfActionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSM_ReadSelfActionActivationPtr(element);
	return element;
}

