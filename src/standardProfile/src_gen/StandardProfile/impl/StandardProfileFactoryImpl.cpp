#include "StandardProfile/impl/StandardProfileFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"

#include "StandardProfile/StandardProfilePackage.hpp"
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
	m_idMap.insert(std::make_pair("Auxiliary", StandardProfilePackage::AUXILIARY_CLASS));
	m_idMap.insert(std::make_pair("BuildComponent", StandardProfilePackage::BUILDCOMPONENT_CLASS));
	m_idMap.insert(std::make_pair("Call", StandardProfilePackage::CALL_CLASS));
	m_idMap.insert(std::make_pair("Create", StandardProfilePackage::CREATE_CLASS));
	m_idMap.insert(std::make_pair("Derive", StandardProfilePackage::DERIVE_CLASS));
	m_idMap.insert(std::make_pair("Destroy", StandardProfilePackage::DESTROY_CLASS));
	m_idMap.insert(std::make_pair("Document", StandardProfilePackage::DOCUMENT_CLASS));
	m_idMap.insert(std::make_pair("Entity", StandardProfilePackage::ENTITY_CLASS));
	m_idMap.insert(std::make_pair("Executable", StandardProfilePackage::EXECUTABLE_CLASS));
	m_idMap.insert(std::make_pair("File", StandardProfilePackage::FILE_CLASS));
	m_idMap.insert(std::make_pair("Focus", StandardProfilePackage::FOCUS_CLASS));
	m_idMap.insert(std::make_pair("Framework", StandardProfilePackage::FRAMEWORK_CLASS));
	m_idMap.insert(std::make_pair("Implement", StandardProfilePackage::IMPLEMENT_CLASS));
	m_idMap.insert(std::make_pair("ImplementationClass", StandardProfilePackage::IMPLEMENTATIONCLASS_CLASS));
	m_idMap.insert(std::make_pair("Instantiate", StandardProfilePackage::INSTANTIATE_CLASS));
	m_idMap.insert(std::make_pair("Library", StandardProfilePackage::LIBRARY_CLASS));
	m_idMap.insert(std::make_pair("Metaclass", StandardProfilePackage::METACLASS_CLASS));
	m_idMap.insert(std::make_pair("Metamodel", StandardProfilePackage::METAMODEL_CLASS));
	m_idMap.insert(std::make_pair("ModelLibrary", StandardProfilePackage::MODELLIBRARY_CLASS));
	m_idMap.insert(std::make_pair("Process", StandardProfilePackage::PROCESS_CLASS));
	m_idMap.insert(std::make_pair("Realization", StandardProfilePackage::REALIZATION_CLASS));
	m_idMap.insert(std::make_pair("Refine", StandardProfilePackage::REFINE_CLASS));
	m_idMap.insert(std::make_pair("Responsibility", StandardProfilePackage::RESPONSIBILITY_CLASS));
	m_idMap.insert(std::make_pair("Script", StandardProfilePackage::SCRIPT_CLASS));
	m_idMap.insert(std::make_pair("Send", StandardProfilePackage::SEND_CLASS));
	m_idMap.insert(std::make_pair("Service", StandardProfilePackage::SERVICE_CLASS));
	m_idMap.insert(std::make_pair("Source", StandardProfilePackage::SOURCE_CLASS));
	m_idMap.insert(std::make_pair("Specification", StandardProfilePackage::SPECIFICATION_CLASS));
	m_idMap.insert(std::make_pair("Subsystem", StandardProfilePackage::SUBSYSTEM_CLASS));
	m_idMap.insert(std::make_pair("SystemModel", StandardProfilePackage::SYSTEMMODEL_CLASS));
	m_idMap.insert(std::make_pair("Trace", StandardProfilePackage::TRACE_CLASS));
	m_idMap.insert(std::make_pair("Type", StandardProfilePackage::TYPE_CLASS));
	m_idMap.insert(std::make_pair("Utility", StandardProfilePackage::UTILITY_CLASS));
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

std::shared_ptr<ecore::EObject> StandardProfileFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case StandardProfilePackage::AUXILIARY_CLASS:
		{
				return this->createAuxiliary(metaElementID);
			
		}
		case StandardProfilePackage::BUILDCOMPONENT_CLASS:
		{
				return this->createBuildComponent(metaElementID);
			
		}
		case StandardProfilePackage::CALL_CLASS:
		{
				return this->createCall(metaElementID);
			
		}
		case StandardProfilePackage::CREATE_CLASS:
		{
				return this->createCreate(metaElementID);
			
		}
		case StandardProfilePackage::DERIVE_CLASS:
		{
				return this->createDerive(metaElementID);
			
		}
		case StandardProfilePackage::DESTROY_CLASS:
		{
				return this->createDestroy(metaElementID);
			
		}
		case StandardProfilePackage::DOCUMENT_CLASS:
		{
				return this->createDocument(metaElementID);
			
		}
		case StandardProfilePackage::ENTITY_CLASS:
		{
				return this->createEntity(metaElementID);
			
		}
		case StandardProfilePackage::EXECUTABLE_CLASS:
		{
				return this->createExecutable(metaElementID);
			
		}
		case StandardProfilePackage::FILE_CLASS:
		{
				return this->createFile(metaElementID);
			
		}
		case StandardProfilePackage::FOCUS_CLASS:
		{
				return this->createFocus(metaElementID);
			
		}
		case StandardProfilePackage::FRAMEWORK_CLASS:
		{
				return this->createFramework(metaElementID);
			
		}
		case StandardProfilePackage::IMPLEMENT_CLASS:
		{
				return this->createImplement(metaElementID);
			
		}
		case StandardProfilePackage::IMPLEMENTATIONCLASS_CLASS:
		{
				return this->createImplementationClass(metaElementID);
			
		}
		case StandardProfilePackage::INSTANTIATE_CLASS:
		{
				return this->createInstantiate(metaElementID);
			
		}
		case StandardProfilePackage::LIBRARY_CLASS:
		{
				return this->createLibrary(metaElementID);
			
		}
		case StandardProfilePackage::METACLASS_CLASS:
		{
				return this->createMetaclass(metaElementID);
			
		}
		case StandardProfilePackage::METAMODEL_CLASS:
		{
				return this->createMetamodel(metaElementID);
			
		}
		case StandardProfilePackage::MODELLIBRARY_CLASS:
		{
				return this->createModelLibrary(metaElementID);
			
		}
		case StandardProfilePackage::PROCESS_CLASS:
		{
				return this->createProcess(metaElementID);
			
		}
		case StandardProfilePackage::REALIZATION_CLASS:
		{
				return this->createRealization(metaElementID);
			
		}
		case StandardProfilePackage::REFINE_CLASS:
		{
				return this->createRefine(metaElementID);
			
		}
		case StandardProfilePackage::RESPONSIBILITY_CLASS:
		{
				return this->createResponsibility(metaElementID);
			
		}
		case StandardProfilePackage::SCRIPT_CLASS:
		{
				return this->createScript(metaElementID);
			
		}
		case StandardProfilePackage::SEND_CLASS:
		{
				return this->createSend(metaElementID);
			
		}
		case StandardProfilePackage::SERVICE_CLASS:
		{
				return this->createService(metaElementID);
			
		}
		case StandardProfilePackage::SOURCE_CLASS:
		{
				return this->createSource(metaElementID);
			
		}
		case StandardProfilePackage::SPECIFICATION_CLASS:
		{
				return this->createSpecification(metaElementID);
			
		}
		case StandardProfilePackage::SUBSYSTEM_CLASS:
		{
				return this->createSubsystem(metaElementID);
			
		}
		case StandardProfilePackage::SYSTEMMODEL_CLASS:
		{
				return this->createSystemModel(metaElementID);
			
		}
		case StandardProfilePackage::TRACE_CLASS:
		{
				return this->createTrace(metaElementID);
			
		}
		case StandardProfilePackage::TYPE_CLASS:
		{
				return this->createType(metaElementID);
			
		}
		case StandardProfilePackage::UTILITY_CLASS:
		{
				return this->createUtility(metaElementID);
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> StandardProfileFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> StandardProfileFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<Auxiliary> StandardProfileFactoryImpl::createAuxiliary(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<AuxiliaryImpl> element(new AuxiliaryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAuxiliaryPtr(element);
	return element;
}
std::shared_ptr<BuildComponent> StandardProfileFactoryImpl::createBuildComponent(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<BuildComponentImpl> element(new BuildComponentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisBuildComponentPtr(element);
	return element;
}
std::shared_ptr<Call> StandardProfileFactoryImpl::createCall(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CallImpl> element(new CallImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallPtr(element);
	return element;
}
std::shared_ptr<Create> StandardProfileFactoryImpl::createCreate(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CreateImpl> element(new CreateImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCreatePtr(element);
	return element;
}
std::shared_ptr<Derive> StandardProfileFactoryImpl::createDerive(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DeriveImpl> element(new DeriveImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDerivePtr(element);
	return element;
}
std::shared_ptr<Destroy> StandardProfileFactoryImpl::createDestroy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DestroyImpl> element(new DestroyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDestroyPtr(element);
	return element;
}
std::shared_ptr<Document> StandardProfileFactoryImpl::createDocument(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DocumentImpl> element(new DocumentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDocumentPtr(element);
	return element;
}
std::shared_ptr<Entity> StandardProfileFactoryImpl::createEntity(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EntityImpl> element(new EntityImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEntityPtr(element);
	return element;
}
std::shared_ptr<Executable> StandardProfileFactoryImpl::createExecutable(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ExecutableImpl> element(new ExecutableImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExecutablePtr(element);
	return element;
}
std::shared_ptr<File> StandardProfileFactoryImpl::createFile(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<FileImpl> element(new FileImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFilePtr(element);
	return element;
}
std::shared_ptr<Focus> StandardProfileFactoryImpl::createFocus(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<FocusImpl> element(new FocusImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFocusPtr(element);
	return element;
}
std::shared_ptr<Framework> StandardProfileFactoryImpl::createFramework(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<FrameworkImpl> element(new FrameworkImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFrameworkPtr(element);
	return element;
}
std::shared_ptr<Implement> StandardProfileFactoryImpl::createImplement(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ImplementImpl> element(new ImplementImpl());
	element->setMetaElementID(metaElementID);
	element->setThisImplementPtr(element);
	return element;
}
std::shared_ptr<ImplementationClass> StandardProfileFactoryImpl::createImplementationClass(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ImplementationClassImpl> element(new ImplementationClassImpl());
	element->setMetaElementID(metaElementID);
	element->setThisImplementationClassPtr(element);
	return element;
}
std::shared_ptr<Instantiate> StandardProfileFactoryImpl::createInstantiate(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InstantiateImpl> element(new InstantiateImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInstantiatePtr(element);
	return element;
}
std::shared_ptr<Library> StandardProfileFactoryImpl::createLibrary(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LibraryImpl> element(new LibraryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLibraryPtr(element);
	return element;
}
std::shared_ptr<Metaclass> StandardProfileFactoryImpl::createMetaclass(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<MetaclassImpl> element(new MetaclassImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMetaclassPtr(element);
	return element;
}
std::shared_ptr<Metamodel> StandardProfileFactoryImpl::createMetamodel(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<MetamodelImpl> element(new MetamodelImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMetamodelPtr(element);
	return element;
}
std::shared_ptr<ModelLibrary> StandardProfileFactoryImpl::createModelLibrary(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ModelLibraryImpl> element(new ModelLibraryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisModelLibraryPtr(element);
	return element;
}
std::shared_ptr<Process> StandardProfileFactoryImpl::createProcess(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ProcessImpl> element(new ProcessImpl());
	element->setMetaElementID(metaElementID);
	element->setThisProcessPtr(element);
	return element;
}
std::shared_ptr<Realization> StandardProfileFactoryImpl::createRealization(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<RealizationImpl> element(new RealizationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRealizationPtr(element);
	return element;
}
std::shared_ptr<Refine> StandardProfileFactoryImpl::createRefine(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<RefineImpl> element(new RefineImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRefinePtr(element);
	return element;
}
std::shared_ptr<Responsibility> StandardProfileFactoryImpl::createResponsibility(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ResponsibilityImpl> element(new ResponsibilityImpl());
	element->setMetaElementID(metaElementID);
	element->setThisResponsibilityPtr(element);
	return element;
}
std::shared_ptr<Script> StandardProfileFactoryImpl::createScript(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ScriptImpl> element(new ScriptImpl());
	element->setMetaElementID(metaElementID);
	element->setThisScriptPtr(element);
	return element;
}
std::shared_ptr<Send> StandardProfileFactoryImpl::createSend(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SendImpl> element(new SendImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSendPtr(element);
	return element;
}
std::shared_ptr<Service> StandardProfileFactoryImpl::createService(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ServiceImpl> element(new ServiceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisServicePtr(element);
	return element;
}
std::shared_ptr<Source> StandardProfileFactoryImpl::createSource(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SourceImpl> element(new SourceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSourcePtr(element);
	return element;
}
std::shared_ptr<Specification> StandardProfileFactoryImpl::createSpecification(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SpecificationImpl> element(new SpecificationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSpecificationPtr(element);
	return element;
}
std::shared_ptr<Subsystem> StandardProfileFactoryImpl::createSubsystem(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SubsystemImpl> element(new SubsystemImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSubsystemPtr(element);
	return element;
}
std::shared_ptr<SystemModel> StandardProfileFactoryImpl::createSystemModel(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SystemModelImpl> element(new SystemModelImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSystemModelPtr(element);
	return element;
}
std::shared_ptr<Trace> StandardProfileFactoryImpl::createTrace(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TraceImpl> element(new TraceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTracePtr(element);
	return element;
}
std::shared_ptr<Type> StandardProfileFactoryImpl::createType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TypeImpl> element(new TypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTypePtr(element);
	return element;
}
std::shared_ptr<Utility> StandardProfileFactoryImpl::createUtility(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UtilityImpl> element(new UtilityImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUtilityPtr(element);
	return element;
}

std::shared_ptr<StandardProfilePackage> StandardProfileFactoryImpl::getStandardProfilePackage() const
{
	return StandardProfilePackage::eInstance();
}
