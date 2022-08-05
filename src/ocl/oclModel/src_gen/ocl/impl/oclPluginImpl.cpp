#include "ocl/impl/oclPluginImpl.hpp"

#include "ocl/oclFactory.hpp"
#include "ocl/oclPackage.hpp"
#include "ocl/impl/oclFactoryImpl.hpp"
#include "ocl/impl/oclPackageImpl.hpp"

using namespace ocl;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> oclPlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance;

	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new oclPluginImpl());
	}
	return instance;
}

OCL_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return oclPluginImpl::eInstance();
}

//*********************************
// Constructor / Destructor
//*********************************
oclPluginImpl::oclPluginImpl()
{
// plugin create factory and package during start()
	std::shared_ptr<oclPackage> eInstancePackagePtr=oclPackage::eInstance();
	if(nullptr==eInstancePackagePtr) // create package only ones
	{ 
		std::shared_ptr<oclPackage> uniquePackagePtr;
		uniquePackagePtr.reset(oclPackageImpl::create());//plugin is fried of package
		oclPackage::seteInstance(uniquePackagePtr);
	}
	std::shared_ptr<oclPackage> eInstanceFactoryPtr=oclPackage::eInstance();
	if(nullptr==eInstanceFactoryPtr) // create factory only ones
	{ 
		std::shared_ptr<oclFactory> uniqueFactroyPtr;
		uniqueFactroyPtr.reset(oclFactoryImpl::create());//plugin is fried of package
		oclFactory::seteInstance(uniqueFactroyPtr);
	}
}

oclPluginImpl::~oclPluginImpl()
{
}


std::shared_ptr<ecore::EObject> oclPluginImpl::create(const std::string& name) const
{
	return oclFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EObject> oclPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return oclFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<ecore::EFactory> oclPluginImpl::getEFactory()
{
	return oclFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> oclPluginImpl::getEPackage()
{
	return oclPackage::eInstance();
}

std::string oclPluginImpl::eclipseURI()
{
	return "";
}

std::string oclPluginImpl::eNAME()
{
	return "ocl";
}

std::string oclPluginImpl::eNS_URI()
{
	return "http://ocl4cpp/ocl";
}

std::string oclPluginImpl::eNS_PREFIX()
{
	return "ocl";
}
