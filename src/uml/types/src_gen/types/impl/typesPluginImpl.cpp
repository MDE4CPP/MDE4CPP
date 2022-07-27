#include "types/impl/typesPluginImpl.hpp"

#include "types/typesFactory.hpp"
#include "types/typesPackage.hpp"

using namespace types;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> typesPlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance;

	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new typesPluginImpl());
	}
	return instance;
}

TYPES_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return typesPluginImpl::eInstance();
}

//*********************************
// Constructor / Destructor
//*********************************
typesPluginImpl::typesPluginImpl()
{
}

typesPluginImpl::~typesPluginImpl()
{
}


std::shared_ptr<ecore::EObject> typesPluginImpl::create(const std::string& name) const
{
	return typesFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EObject> typesPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return typesFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<ecore::EFactory> typesPluginImpl::getEFactory()
{
	return typesFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> typesPluginImpl::getEPackage()
{
	return typesPackage::eInstance();
}

std::string typesPluginImpl::eclipseURI()
{
	return "";
}

std::string typesPluginImpl::eNAME()
{
	return "types";
}

std::string typesPluginImpl::eNS_URI()
{
	return "http://www.eclipse.org/uml2/5.0.0/Types";
}

std::string typesPluginImpl::eNS_PREFIX()
{
	return "types";
}
