#include "PSCS/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/MDE4CPP_Extensions/impl/PSCS_ObjectImpl.hpp"

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/umlPackage.hpp"
#include "uml/DirectedRelationship.hpp"


using namespace PSCS::MDE4CPP_Extensions;

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
	m_idMap.insert(std::make_pair("PSCS::MDE4CPP_Extensions::PSCS_Object", MDE4CPP_ExtensionsPackage::PSCS_OBJECT_CLASS));
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
		case MDE4CPP_ExtensionsPackage::PSCS_OBJECT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPSCS_Object(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PSCS_Object has extensionalValues as a containment
					case  fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXTENSIONALVALUES:	
					{
						std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus> (container);
						return this->createPSCS_Object_as_extensionalValues_in_Locus(castedContainer,metaElementID);
					}
					//PSCS_Object has source as a containment
					case  uml::umlPackage::DIRECTEDRELATIONSHIP_ATTRIBUTE_SOURCE:	
					{
						std::shared_ptr<uml::DirectedRelationship> castedContainer = std::dynamic_pointer_cast<uml::DirectedRelationship> (container);
						return this->createPSCS_Object_as_source_in_DirectedRelationship(castedContainer,metaElementID);
					}
					//PSCS_Object has target as a containment
					case  uml::umlPackage::DIRECTEDRELATIONSHIP_ATTRIBUTE_TARGET:	
					{
						std::shared_ptr<uml::DirectedRelationship> castedContainer = std::dynamic_pointer_cast<uml::DirectedRelationship> (container);
						return this->createPSCS_Object_as_target_in_DirectedRelationship(castedContainer,metaElementID);
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

std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> MDE4CPP_ExtensionsFactoryImpl::createPSCS_Object(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl> element(new PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPSCS_ObjectPtr(element);
	return element;
}
std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> MDE4CPP_ExtensionsFactoryImpl::createPSCS_Object_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl> element(new PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	}
	
	element->setThisPSCS_ObjectPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> MDE4CPP_ExtensionsFactoryImpl::createPSCS_Object_as_source_in_DirectedRelationship(std::shared_ptr<uml::DirectedRelationship> par_DirectedRelationship, const int metaElementID) const
{
	std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl> element(new PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_DirectedRelationship)
	{
		par_DirectedRelationship->getSource()->push_back(element);
	}
	
	element->setThisPSCS_ObjectPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> MDE4CPP_ExtensionsFactoryImpl::createPSCS_Object_as_target_in_DirectedRelationship(std::shared_ptr<uml::DirectedRelationship> par_DirectedRelationship, const int metaElementID) const
{
	std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl> element(new PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_DirectedRelationship)
	{
		par_DirectedRelationship->getTarget()->push_back(element);
	}
	
	element->setThisPSCS_ObjectPtr(element);
	return element;
	
}

