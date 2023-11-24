#include "PSSM/impl/PSSMPluginImpl.hpp"

#include "PSSM/PSSMFactory.hpp"
#include "PSSM/PSSMPackage.hpp"

using namespace PSSM;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> PSSMPlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance = nullptr;

	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new PSSMPluginImpl());
	}
	return instance;
}

PSSM_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return PSSMPluginImpl::eInstance();
}

//*********************************
// Constructor / Destructor
//*********************************
PSSMPluginImpl::PSSMPluginImpl()
{
}

PSSMPluginImpl::~PSSMPluginImpl()
{
}


std::shared_ptr<ecore::EObject> PSSMPluginImpl::create(const std::string& name) const
{
	return PSSMFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EObject> PSSMPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return PSSMFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<ecore::EFactory> PSSMPluginImpl::getEFactory()
{
	return PSSMFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> PSSMPluginImpl::getEPackage()
{
	return PSSMPackage::eInstance();
}

std::string PSSMPluginImpl::eclipseURI()
{
	return "";
}

std::string PSSMPluginImpl::eNAME()
{
	return "PSSM";
}

std::string PSSMPluginImpl::eNS_URI()
{
	return "http://www.omg.org/spec/PSSM/20161101";
}

std::string PSSMPluginImpl::eNS_PREFIX()
{
	return "PSSM";
}
