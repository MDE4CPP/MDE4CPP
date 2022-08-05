#include "PSCS/impl/PSCSPluginImpl.hpp"

#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/impl/PSCSFactoryImpl.hpp"
#include "PSCS/impl/PSCSPackageImpl.hpp"

using namespace PSCS;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> PSCSPlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance;

	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new PSCSPluginImpl());
	}
	return instance;
}

PSCS_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return PSCSPluginImpl::eInstance();
}

//*********************************
// Constructor / Destructor
//*********************************
PSCSPluginImpl::PSCSPluginImpl()
{
// plugin create factory and package during start()
	std::shared_ptr<PSCSPackage> eInstancePackagePtr=PSCSPackage::eInstance();
	if(nullptr==eInstancePackagePtr) // create package only ones
	{ 
		std::shared_ptr<PSCSPackage> uniquePackagePtr;
		uniquePackagePtr.reset(PSCSPackageImpl::create());//plugin is fried of package
		PSCSPackage::seteInstance(uniquePackagePtr);
	}
	std::shared_ptr<PSCSPackage> eInstanceFactoryPtr=PSCSPackage::eInstance();
	if(nullptr==eInstanceFactoryPtr) // create factory only ones
	{ 
		std::shared_ptr<PSCSFactory> uniqueFactroyPtr;
		uniqueFactroyPtr.reset(PSCSFactoryImpl::create());//plugin is fried of package
		PSCSFactory::seteInstance(uniqueFactroyPtr);
	}
}

PSCSPluginImpl::~PSCSPluginImpl()
{
}


std::shared_ptr<ecore::EObject> PSCSPluginImpl::create(const std::string& name) const
{
	return PSCSFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EObject> PSCSPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return PSCSFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<ecore::EFactory> PSCSPluginImpl::getEFactory()
{
	return PSCSFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> PSCSPluginImpl::getEPackage()
{
	return PSCSPackage::eInstance();
}

std::string PSCSPluginImpl::eclipseURI()
{
	return "";
}

std::string PSCSPluginImpl::eNAME()
{
	return "PSCS";
}

std::string PSCSPluginImpl::eNS_URI()
{
	return "http://www.omg.org/spec/PSCS/20180801";
}

std::string PSCSPluginImpl::eNS_PREFIX()
{
	return "PSCS_Semantics";
}
