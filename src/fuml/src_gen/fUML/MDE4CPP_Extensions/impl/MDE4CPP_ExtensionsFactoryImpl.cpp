#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/MDE4CPP_Extensions/impl/FUML_ObjectImpl.hpp"

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/umlPackage.hpp"
#include "uml/DirectedRelationship.hpp"


using namespace fUML::MDE4CPP_Extensions;

std::shared_ptr<MDE4CPP_ExtensionsFactory> MDE4CPP_ExtensionsFactory::eInstance()
{
	static std::shared_ptr<MDE4CPP_ExtensionsFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(MDE4CPP_ExtensionsFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

MDE4CPP_ExtensionsFactoryImpl::MDE4CPP_ExtensionsFactoryImpl()
{
}

MDE4CPP_ExtensionsFactoryImpl::~MDE4CPP_ExtensionsFactoryImpl()
{
}

MDE4CPP_ExtensionsFactory* MDE4CPP_ExtensionsFactoryImpl::create()
{
	return new MDE4CPP_ExtensionsFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> MDE4CPP_ExtensionsFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> MDE4CPP_ExtensionsFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> MDE4CPP_ExtensionsFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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


