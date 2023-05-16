#include "ocl/impl/oclPluginImpl.hpp"

#include "ocl/oclFactory.hpp"
#include "ocl/oclPackage.hpp"

using namespace ocl;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> oclPlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance = nullptr;

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
