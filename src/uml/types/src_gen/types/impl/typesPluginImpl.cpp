#include "types/impl/typesPluginImpl.hpp"

#include "types/typesFactory.hpp"
#include "types/typesPackage.hpp"
#include "types/impl/typesFactoryImpl.hpp"
#include "types/impl/typesPackageImpl.hpp"

using namespace types;

//static initialisation
std::shared_ptr<typesPlugin> typesPlugin::eInstance()
{
	static std::shared_ptr<typesPlugin> instance;

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

std::shared_ptr<typesPackage> typesPluginImpl::gettypesPackage()
{
	if(nullptr==m_typesPackage) // create package only ones
	{
		m_typesPackage.reset(typesPackageImpl::create());//plugin is fried of package
	}
	return m_typesPackage;
}

std::shared_ptr<typesFactory> typesPluginImpl::gettypesFactory()
{
	if(nullptr==m_typesFactory) // create package only ones
	{
		m_typesFactory.reset(typesFactoryImpl::create());//plugin is fried of Factory
	}
	return m_typesFactory;
}


//*********************************
// Constructor / Destructor
//*********************************
typesPluginImpl::typesPluginImpl()
{
// plugin create factory and package during start()
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
