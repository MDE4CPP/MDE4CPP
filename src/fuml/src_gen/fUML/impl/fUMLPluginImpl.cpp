#include "fUML/impl/fUMLPluginImpl.hpp"

#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"

using namespace fUML;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> fUMLPlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance = nullptr;

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
