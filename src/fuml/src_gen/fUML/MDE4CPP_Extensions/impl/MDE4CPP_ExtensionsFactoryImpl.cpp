#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/MDE4CPP_Extensions/impl/FUML_LinkImpl.hpp"
#include "fUML/MDE4CPP_Extensions/impl/FUML_LinkEndImpl.hpp"
#include "fUML/MDE4CPP_Extensions/impl/FUML_ObjectImpl.hpp"
#include "fUML/MDE4CPP_Extensions/impl/FUML_SignalInstanceImpl.hpp"

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
	m_idMap.insert(std::make_pair("fUML::MDE4CPP_Extensions::FUML_Link", MDE4CPP_ExtensionsPackage::FUML_LINK_CLASS));
	m_idMap.insert(std::make_pair("fUML::MDE4CPP_Extensions::FUML_LinkEnd", MDE4CPP_ExtensionsPackage::FUML_LINKEND_CLASS));
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
		case MDE4CPP_ExtensionsPackage::FUML_LINK_CLASS:
		{
				return this->createFUML_Link(metaElementID);
			
			break;
		}
		case MDE4CPP_ExtensionsPackage::FUML_LINKEND_CLASS:
		{
			if (nullptr == container)
			{
				return this->createFUML_LinkEnd(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link> castedContainer = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Link>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_LinkEnd>(this->createFUML_LinkEnd_as_linkEnds_in_FUML_Link(castedContainer,metaElementID));
			}
			break;
		}
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

std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link> MDE4CPP_ExtensionsFactoryImpl::createFUML_Link(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_LinkImpl> element(new fUML::MDE4CPP_Extensions::FUML_LinkImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFUML_LinkPtr(element);
	return element;
}
std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_LinkEnd> MDE4CPP_ExtensionsFactoryImpl::createFUML_LinkEnd(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_LinkEndImpl> element(new fUML::MDE4CPP_Extensions::FUML_LinkEndImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFUML_LinkEndPtr(element);
	return element;
}
std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_LinkEnd> MDE4CPP_ExtensionsFactoryImpl::createFUML_LinkEnd_as_linkEnds_in_FUML_Link(std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link> par_FUML_Link, const int metaElementID) const
{
	std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_LinkEndImpl> element(new fUML::MDE4CPP_Extensions::FUML_LinkEndImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FUML_Link)
	{
		par_FUML_Link->getLinkEnds()->push_back(element);
	}
	
	element->setThisFUML_LinkEndPtr(element);
	return element;
	
}

