#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
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
	m_idMap.insert(std::make_pair("fUML::MDE4CPP_Extensions::FUML_SignalInstance", MDE4CPP_ExtensionsPackage::FUML_SIGNALINSTANCE_CLASS));
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
		case MDE4CPP_ExtensionsPackage::FUML_SIGNALINSTANCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createFUML_SignalInstance(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//FUML_SignalInstance has source as a containment
					case  uml::umlPackage::DIRECTEDRELATIONSHIP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<uml::DirectedRelationship> castedContainer = std::dynamic_pointer_cast<uml::DirectedRelationship> (container);
						return this->createFUML_SignalInstance_as_source_in_DirectedRelationship(castedContainer,metaElementID);
					}
					//FUML_SignalInstance has target as a containment
					case  uml::umlPackage::DIRECTEDRELATIONSHIP_ATTRIBUTE_TARGET:	
					{
						std::shared_ptr<uml::DirectedRelationship> castedContainer = std::dynamic_pointer_cast<uml::DirectedRelationship> (container);
						return this->createFUML_SignalInstance_as_target_in_DirectedRelationship(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
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

std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> MDE4CPP_ExtensionsFactoryImpl::createFUML_SignalInstance(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstanceImpl> element(new fUML::MDE4CPP_Extensions::FUML_SignalInstanceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFUML_SignalInstancePtr(element);
	return element;
}
std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> MDE4CPP_ExtensionsFactoryImpl::createFUML_SignalInstance_as_source_in_DirectedRelationship(std::shared_ptr<uml::DirectedRelationship> par_DirectedRelationship, const int metaElementID) const
{
	std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstanceImpl> element(new fUML::MDE4CPP_Extensions::FUML_SignalInstanceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_DirectedRelationship)
	{
		par_DirectedRelationship->getSource()->push_back(element);
	}
	
	element->setThisFUML_SignalInstancePtr(element);
	return element;
	
}
std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> MDE4CPP_ExtensionsFactoryImpl::createFUML_SignalInstance_as_target_in_DirectedRelationship(std::shared_ptr<uml::DirectedRelationship> par_DirectedRelationship, const int metaElementID) const
{
	std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstanceImpl> element(new fUML::MDE4CPP_Extensions::FUML_SignalInstanceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_DirectedRelationship)
	{
		par_DirectedRelationship->getTarget()->push_back(element);
	}
	
	element->setThisFUML_SignalInstancePtr(element);
	return element;
	
}

