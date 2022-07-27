#include "uml/impl/umlPluginImpl.hpp"

#include "uml/umlFactory.hpp"
#include "uml/umlPackage.hpp"

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
