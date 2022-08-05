#include "fUML/impl/fUMLPluginImpl.hpp"

#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/impl/fUMLFactoryImpl.hpp"
#include "fUML/impl/fUMLPackageImpl.hpp"

using namespace fUML;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> fUMLPlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance;

	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new fUMLPluginImpl());
	}
	return instance;
}

FUML_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return fUMLPluginImpl::eInstance();
}

//*********************************
// Constructor / Destructor
//*********************************
fUMLPluginImpl::fUMLPluginImpl()
{
// plugin create factory and package during start()
	std::shared_ptr<fUMLPackage> eInstancePackagePtr=fUMLPackage::eInstance();
	if(nullptr==eInstancePackagePtr) // create package only ones
	{ 
		std::shared_ptr<fUMLPackage> uniquePackagePtr;
		uniquePackagePtr.reset(fUMLPackageImpl::create());//plugin is fried of package
		fUMLPackage::seteInstance(uniquePackagePtr);
	}
	std::shared_ptr<fUMLPackage> eInstanceFactoryPtr=fUMLPackage::eInstance();
	if(nullptr==eInstanceFactoryPtr) // create factory only ones
	{ 
		std::shared_ptr<fUMLFactory> uniqueFactroyPtr;
		uniqueFactroyPtr.reset(fUMLFactoryImpl::create());//plugin is fried of package
		fUMLFactory::seteInstance(uniqueFactroyPtr);
	}
}

fUMLPluginImpl::~fUMLPluginImpl()
{
}


std::shared_ptr<ecore::EObject> fUMLPluginImpl::create(const std::string& name) const
{
	return fUMLFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EObject> fUMLPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return fUMLFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<ecore::EFactory> fUMLPluginImpl::getEFactory()
{
	return fUMLFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> fUMLPluginImpl::getEPackage()
{
	return fUMLPackage::eInstance();
}

std::string fUMLPluginImpl::eclipseURI()
{
	return "";
}

std::string fUMLPluginImpl::eNAME()
{
	return "fUML";
}

std::string fUMLPluginImpl::eNS_URI()
{
	return "http://www.omg.org/spec/FUML/20180501";
}

std::string fUMLPluginImpl::eNS_PREFIX()
{
	return "fUML_Semantics";
}
