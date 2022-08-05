#include "ecore/impl/ecorePluginImpl.hpp"

#include "ecore/ecoreFactory.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/impl/ecoreFactoryImpl.hpp"
#include "ecore/impl/ecorePackageImpl.hpp"

#include "ecore/impl/ecoreFactoryImpl.hpp"
#include "ecore/impl/ecorePackageImpl.hpp"


using namespace ecore;

//static initialisation
std::shared_ptr<ecorePlugin> ecorePlugin::init()
{
	std::shared_ptr<ecorePlugin>* staticPtr= getecorePluginStaticPtr();
	if(staticPtr==nullptr)
	{
		//create a new Singelton Instance
		seteInstance(new ecorePluginImpl());
	}      
	return *getecorePluginStaticPtr();
}

ECORE_API std::shared_ptr<MDE4CPPPlugin> start()
{
	return ecorePluginImpl::eInstance();
}

std::shared_ptr<ecore::ecorePackage> ecorePluginImpl::getecorePackage()
{
	if(nullptr==m_ecorePackage) // create package only ones
	{
		m_ecorePackage.reset(ecore::ecorePackageImpl::create());//plugin is fried of package
	}
	return m_ecorePackage;
}

std::shared_ptr<ecore::ecoreFactory> ecorePluginImpl::getecoreFactory()
{
	if(nullptr==m_ecoreFactory) // create package only ones
	{
		m_ecoreFactory.reset(ecore::ecoreFactoryImpl::create());//plugin is fried of Factory
	}
	return m_ecoreFactory;
}


//*********************************
// Constructor / Destructor
//*********************************
ecorePluginImpl::ecorePluginImpl()
{
// plugin create factory and package during start()
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
