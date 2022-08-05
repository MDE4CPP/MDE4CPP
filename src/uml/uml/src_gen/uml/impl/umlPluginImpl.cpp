#include "uml/impl/umlPluginImpl.hpp"

#include "uml/umlFactory.hpp"
#include "uml/umlPackage.hpp"
#include "uml/impl/umlFactoryImpl.hpp"
#include "uml/impl/umlPackageImpl.hpp"

using namespace uml;

//static initialisation
std::shared_ptr<MDE4CPPPlugin> umlPlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance;

	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(new umlPluginImpl());
	}
	return instance;
}

UML_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return umlPluginImpl::eInstance();
}

//*********************************
// Constructor / Destructor
//*********************************
umlPluginImpl::umlPluginImpl()
{
// plugin create factory and package during start()
	std::shared_ptr<umlPackage> eInstancePackagePtr=umlPackage::eInstance();
	if(nullptr==eInstancePackagePtr) // create package only ones
	{ 
		std::shared_ptr<umlPackage> uniquePackagePtr;
		uniquePackagePtr.reset(umlPackageImpl::create());//plugin is fried of package
		umlPackage::seteInstance(uniquePackagePtr);
	}
	std::shared_ptr<umlPackage> eInstanceFactoryPtr=umlPackage::eInstance();
	if(nullptr==eInstanceFactoryPtr) // create factory only ones
	{ 
		std::shared_ptr<umlFactory> uniqueFactroyPtr;
		uniqueFactroyPtr.reset(umlFactoryImpl::create());//plugin is fried of package
		umlFactory::seteInstance(uniqueFactroyPtr);
	}
}

umlPluginImpl::~umlPluginImpl()
{
}


std::shared_ptr<ecore::EObject> umlPluginImpl::create(const std::string& name) const
{
	return umlFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EObject> umlPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return umlFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<ecore::EFactory> umlPluginImpl::getEFactory()
{
	return umlFactory::eInstance();
}

std::shared_ptr<ecore::EPackage> umlPluginImpl::getEPackage()
{
	return umlPackage::eInstance();
}

std::string umlPluginImpl::eclipseURI()
{
	return "pathmap://UML_METAMODELS/UML.metamodel.uml";
}

std::string umlPluginImpl::eNAME()
{
	return "uml";
}

std::string umlPluginImpl::eNS_URI()
{
	return "http://www.eclipse.org/uml2/5.0.0/UML";
}

std::string umlPluginImpl::eNS_PREFIX()
{
	return "uml";
}
