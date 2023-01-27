#include "ecore/impl/ecorePluginImpl.hpp"

#include "ecore/ecoreFactory.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> ecorePlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance;

	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new ecorePluginImpl());
	}
	return instance;
}

ECORE_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return ecorePluginImpl::eInstance();
}

//*********************************
// Constructor / Destructor
//*********************************
ecorePluginImpl::ecorePluginImpl()
{
}

ecorePluginImpl::~ecorePluginImpl()
{
}


std::shared_ptr<ecore::EObject> ecorePluginImpl::create(const std::string& name) const
{
	return ecoreFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EObject> ecorePluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return ecoreFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<ecore::EFactory> ecorePluginImpl::getEFactory()
{
	return ecoreFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> ecorePluginImpl::getEPackage()
{
	return ecorePackage::eInstance();
}

std::string ecorePluginImpl::eclipseURI()
{
	return "";
}

std::string ecorePluginImpl::eNAME()
{
	return "ecore";
}

std::string ecorePluginImpl::eNS_URI()
{
	return "http://www.eclipse.org/emf/2002/Ecore";
}

std::string ecorePluginImpl::eNS_PREFIX()
{
	return "ecore";
}
