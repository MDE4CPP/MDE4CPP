#include "StandardProfile/impl/StandardProfileFactoryImpl.hpp"
#include "StandardProfile/StandardProfilePackage.hpp"

#include "abstractDataTypes/Bag.hpp"
#include "uml/Class.hpp"
#include <cassert>

#include "StandardProfile/impl/AuxiliaryImpl.hpp"
#include "StandardProfile/impl/BuildComponentImpl.hpp"
#include "StandardProfile/impl/CallImpl.hpp"
#include "StandardProfile/impl/CreateImpl.hpp"
#include "StandardProfile/impl/DeriveImpl.hpp"
#include "StandardProfile/impl/DestroyImpl.hpp"
#include "StandardProfile/impl/DocumentImpl.hpp"
#include "StandardProfile/impl/EntityImpl.hpp"
#include "StandardProfile/impl/ExecutableImpl.hpp"
#include "StandardProfile/impl/FileImpl.hpp"
#include "StandardProfile/impl/FocusImpl.hpp"
#include "StandardProfile/impl/FrameworkImpl.hpp"
#include "StandardProfile/impl/ImplementImpl.hpp"
#include "StandardProfile/impl/ImplementationClassImpl.hpp"
#include "StandardProfile/impl/InstantiateImpl.hpp"
#include "StandardProfile/impl/LibraryImpl.hpp"
#include "StandardProfile/impl/MetaclassImpl.hpp"
#include "StandardProfile/impl/MetamodelImpl.hpp"
#include "StandardProfile/impl/ModelLibraryImpl.hpp"
#include "StandardProfile/impl/ProcessImpl.hpp"
#include "StandardProfile/impl/RealizationImpl.hpp"
#include "StandardProfile/impl/RefineImpl.hpp"
#include "StandardProfile/impl/ResponsibilityImpl.hpp"
#include "StandardProfile/impl/ScriptImpl.hpp"
#include "StandardProfile/impl/SendImpl.hpp"
#include "StandardProfile/impl/ServiceImpl.hpp"
#include "StandardProfile/impl/SourceImpl.hpp"
#include "StandardProfile/impl/SpecificationImpl.hpp"
#include "StandardProfile/impl/SubsystemImpl.hpp"
#include "StandardProfile/impl/SystemModelImpl.hpp"
#include "StandardProfile/impl/TraceImpl.hpp"
#include "StandardProfile/impl/TypeImpl.hpp"
#include "StandardProfile/impl/UtilityImpl.hpp"


using namespace StandardProfile;
//*********************************
// Constructor / Destructor
//*********************************
StandardProfileFactoryImpl::StandardProfileFactoryImpl()
{
	m_idMap.insert(std::make_pair("StandardProfile::Auxiliary", StandardProfilePackage::AUXILIARY_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::BuildComponent", StandardProfilePackage::BUILDCOMPONENT_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Call", StandardProfilePackage::CALL_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Create", StandardProfilePackage::CREATE_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Derive", StandardProfilePackage::DERIVE_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Destroy", StandardProfilePackage::DESTROY_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Document", StandardProfilePackage::DOCUMENT_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Entity", StandardProfilePackage::ENTITY_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Executable", StandardProfilePackage::EXECUTABLE_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::File", StandardProfilePackage::FILE_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Focus", StandardProfilePackage::FOCUS_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Framework", StandardProfilePackage::FRAMEWORK_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Implement", StandardProfilePackage::IMPLEMENT_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::ImplementationClass", StandardProfilePackage::IMPLEMENTATIONCLASS_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Instantiate", StandardProfilePackage::INSTANTIATE_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Library", StandardProfilePackage::LIBRARY_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Metaclass", StandardProfilePackage::METACLASS_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Metamodel", StandardProfilePackage::METAMODEL_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::ModelLibrary", StandardProfilePackage::MODELLIBRARY_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Process", StandardProfilePackage::PROCESS_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Realization", StandardProfilePackage::REALIZATION_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Refine", StandardProfilePackage::REFINE_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Responsibility", StandardProfilePackage::RESPONSIBILITY_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Script", StandardProfilePackage::SCRIPT_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Send", StandardProfilePackage::SEND_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Service", StandardProfilePackage::SERVICE_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Source", StandardProfilePackage::SOURCE_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Specification", StandardProfilePackage::SPECIFICATION_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Subsystem", StandardProfilePackage::SUBSYSTEM_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::SystemModel", StandardProfilePackage::SYSTEMMODEL_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Trace", StandardProfilePackage::TRACE_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Type", StandardProfilePackage::TYPE_CLASS));
	m_idMap.insert(std::make_pair("StandardProfile::Utility", StandardProfilePackage::UTILITY_CLASS));
}

StandardProfileFactoryImpl::~StandardProfileFactoryImpl()
{
}

StandardProfileFactory* StandardProfileFactoryImpl::create()
{
	return new StandardProfileFactoryImpl();
}

//*********************************
// creators
//*********************************
std::shared_ptr<uml::Element> StandardProfileFactoryImpl::create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(_metaClassId)
	{
		case StandardProfilePackage::AUXILIARY_CLASS:
		{
				return this->createAuxiliary(_metaClassId);
			
		}
		case StandardProfilePackage::BUILDCOMPONENT_CLASS:
		{
				return this->createBuildComponent(_metaClassId);
			
		}
		case StandardProfilePackage::CALL_CLASS:
		{
				return this->createCall(_metaClassId);
			
		}
		case StandardProfilePackage::CREATE_CLASS:
		{
				return this->createCreate(_metaClassId);
			
		}
		case StandardProfilePackage::DERIVE_CLASS:
		{
				return this->createDerive(_metaClassId);
			
		}
		case StandardProfilePackage::DESTROY_CLASS:
		{
				return this->createDestroy(_metaClassId);
			
		}
		case StandardProfilePackage::DOCUMENT_CLASS:
		{
				return this->createDocument(_metaClassId);
			
		}
		case StandardProfilePackage::ENTITY_CLASS:
		{
				return this->createEntity(_metaClassId);
			
		}
		case StandardProfilePackage::EXECUTABLE_CLASS:
		{
				return this->createExecutable(_metaClassId);
			
		}
		case StandardProfilePackage::FILE_CLASS:
		{
				return this->createFile(_metaClassId);
			
		}
		case StandardProfilePackage::FOCUS_CLASS:
		{
				return this->createFocus(_metaClassId);
			
		}
		case StandardProfilePackage::FRAMEWORK_CLASS:
		{
				return this->createFramework(_metaClassId);
			
		}
		case StandardProfilePackage::IMPLEMENT_CLASS:
		{
				return this->createImplement(_metaClassId);
			
		}
		case StandardProfilePackage::IMPLEMENTATIONCLASS_CLASS:
		{
				return this->createImplementationClass(_metaClassId);
			
		}
		case StandardProfilePackage::INSTANTIATE_CLASS:
		{
				return this->createInstantiate(_metaClassId);
			
		}
		case StandardProfilePackage::LIBRARY_CLASS:
		{
				return this->createLibrary(_metaClassId);
			
		}
		case StandardProfilePackage::METACLASS_CLASS:
		{
				return this->createMetaclass(_metaClassId);
			
		}
		case StandardProfilePackage::METAMODEL_CLASS:
		{
				return this->createMetamodel(_metaClassId);
			
		}
		case StandardProfilePackage::MODELLIBRARY_CLASS:
		{
				return this->createModelLibrary(_metaClassId);
			
		}
		case StandardProfilePackage::PROCESS_CLASS:
		{
				return this->createProcess(_metaClassId);
			
		}
		case StandardProfilePackage::REALIZATION_CLASS:
		{
				return this->createRealization(_metaClassId);
			
		}
		case StandardProfilePackage::REFINE_CLASS:
		{
				return this->createRefine(_metaClassId);
			
		}
		case StandardProfilePackage::RESPONSIBILITY_CLASS:
		{
				return this->createResponsibility(_metaClassId);
			
		}
		case StandardProfilePackage::SCRIPT_CLASS:
		{
				return this->createScript(_metaClassId);
			
		}
		case StandardProfilePackage::SEND_CLASS:
		{
				return this->createSend(_metaClassId);
			
		}
		case StandardProfilePackage::SERVICE_CLASS:
		{
				return this->createService(_metaClassId);
			
		}
		case StandardProfilePackage::SOURCE_CLASS:
		{
				return this->createSource(_metaClassId);
			
		}
		case StandardProfilePackage::SPECIFICATION_CLASS:
		{
				return this->createSpecification(_metaClassId);
			
		}
		case StandardProfilePackage::SUBSYSTEM_CLASS:
		{
				return this->createSubsystem(_metaClassId);
			
		}
		case StandardProfilePackage::SYSTEMMODEL_CLASS:
		{
				return this->createSystemModel(_metaClassId);
			
		}
		case StandardProfilePackage::TRACE_CLASS:
		{
				return this->createTrace(_metaClassId);
			
		}
		case StandardProfilePackage::TYPE_CLASS:
		{
				return this->createType(_metaClassId);
			
		}
		case StandardProfilePackage::UTILITY_CLASS:
		{
				return this->createUtility(_metaClassId);
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << _metaClassId <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<uml::Element> StandardProfileFactoryImpl::create(std::shared_ptr<uml::Class> _class, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	if(_class->getIsAbstract())
    {
    	return nullptr;
    }
	std::string typeName = _class->getQualifiedName();
	return create(typeName,container,referenceID);
}

std::shared_ptr<uml::Element> StandardProfileFactoryImpl::create(std::string _className, std::shared_ptr<uml::Element> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the getMetaElementId()
        unsigned int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}
std::shared_ptr<StandardProfile::Auxiliary> StandardProfileFactoryImpl::createAuxiliary(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::AuxiliaryImpl> element(new AuxiliaryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAuxiliaryPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::BuildComponent> StandardProfileFactoryImpl::createBuildComponent(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::BuildComponentImpl> element(new BuildComponentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisBuildComponentPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Call> StandardProfileFactoryImpl::createCall(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::CallImpl> element(new CallImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Create> StandardProfileFactoryImpl::createCreate(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::CreateImpl> element(new CreateImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCreatePtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Derive> StandardProfileFactoryImpl::createDerive(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::DeriveImpl> element(new DeriveImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDerivePtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Destroy> StandardProfileFactoryImpl::createDestroy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::DestroyImpl> element(new DestroyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDestroyPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Document> StandardProfileFactoryImpl::createDocument(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::DocumentImpl> element(new DocumentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDocumentPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Entity> StandardProfileFactoryImpl::createEntity(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::EntityImpl> element(new EntityImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEntityPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Executable> StandardProfileFactoryImpl::createExecutable(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::ExecutableImpl> element(new ExecutableImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExecutablePtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::File> StandardProfileFactoryImpl::createFile(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::FileImpl> element(new FileImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFilePtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Focus> StandardProfileFactoryImpl::createFocus(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::FocusImpl> element(new FocusImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFocusPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Framework> StandardProfileFactoryImpl::createFramework(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::FrameworkImpl> element(new FrameworkImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFrameworkPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Implement> StandardProfileFactoryImpl::createImplement(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::ImplementImpl> element(new ImplementImpl());
	element->setMetaElementID(metaElementID);
	element->setThisImplementPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::ImplementationClass> StandardProfileFactoryImpl::createImplementationClass(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::ImplementationClassImpl> element(new ImplementationClassImpl());
	element->setMetaElementID(metaElementID);
	element->setThisImplementationClassPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Instantiate> StandardProfileFactoryImpl::createInstantiate(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::InstantiateImpl> element(new InstantiateImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInstantiatePtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Library> StandardProfileFactoryImpl::createLibrary(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::LibraryImpl> element(new LibraryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLibraryPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Metaclass> StandardProfileFactoryImpl::createMetaclass(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::MetaclassImpl> element(new MetaclassImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMetaclassPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Metamodel> StandardProfileFactoryImpl::createMetamodel(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::MetamodelImpl> element(new MetamodelImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMetamodelPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::ModelLibrary> StandardProfileFactoryImpl::createModelLibrary(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::ModelLibraryImpl> element(new ModelLibraryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisModelLibraryPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Process> StandardProfileFactoryImpl::createProcess(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::ProcessImpl> element(new ProcessImpl());
	element->setMetaElementID(metaElementID);
	element->setThisProcessPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Realization> StandardProfileFactoryImpl::createRealization(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::RealizationImpl> element(new RealizationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRealizationPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Refine> StandardProfileFactoryImpl::createRefine(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::RefineImpl> element(new RefineImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRefinePtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Responsibility> StandardProfileFactoryImpl::createResponsibility(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::ResponsibilityImpl> element(new ResponsibilityImpl());
	element->setMetaElementID(metaElementID);
	element->setThisResponsibilityPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Script> StandardProfileFactoryImpl::createScript(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::ScriptImpl> element(new ScriptImpl());
	element->setMetaElementID(metaElementID);
	element->setThisScriptPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Send> StandardProfileFactoryImpl::createSend(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::SendImpl> element(new SendImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSendPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Service> StandardProfileFactoryImpl::createService(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::ServiceImpl> element(new ServiceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisServicePtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Source> StandardProfileFactoryImpl::createSource(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::SourceImpl> element(new SourceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSourcePtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Specification> StandardProfileFactoryImpl::createSpecification(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::SpecificationImpl> element(new SpecificationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSpecificationPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Subsystem> StandardProfileFactoryImpl::createSubsystem(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::SubsystemImpl> element(new SubsystemImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSubsystemPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::SystemModel> StandardProfileFactoryImpl::createSystemModel(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::SystemModelImpl> element(new SystemModelImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSystemModelPtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Trace> StandardProfileFactoryImpl::createTrace(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::TraceImpl> element(new TraceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTracePtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Type> StandardProfileFactoryImpl::createType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::TypeImpl> element(new TypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTypePtr(element);
	element->instantiate();
	return element;
}
std::shared_ptr<StandardProfile::Utility> StandardProfileFactoryImpl::createUtility(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StandardProfile::UtilityImpl> element(new UtilityImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUtilityPtr(element);
	element->instantiate();
	return element;
}



std::shared_ptr<StandardProfilePackage> StandardProfileFactoryImpl::getStandardProfilePackage()
{
	return StandardProfilePackage::eInstance();
}
