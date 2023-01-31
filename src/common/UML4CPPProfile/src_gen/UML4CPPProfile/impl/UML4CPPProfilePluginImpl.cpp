#include "UML4CPPProfile/impl/UML4CPPProfilePluginImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif
#include <iostream>

#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"
#include "UML4CPPProfile/UML4CPPProfilePackage.hpp"

using namespace UML4CPPProfile;

//static initialization
std::shared_ptr<MDE4CPPPlugin> UML4CPPProfilePlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance;

	if(instance==nullptr)
	{
		//create a new Singelton instance
		instance.reset(new UML4CPPProfilePluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return UML4CPPProfilePluginImpl::eInstance();
}

//*********************************
// Constructor / Destructor
//*********************************
UML4CPPProfilePluginImpl::UML4CPPProfilePluginImpl()
{
}

UML4CPPProfilePluginImpl::~UML4CPPProfilePluginImpl()
{
}

std::shared_ptr<ecore::EObject> UML4CPPProfilePluginImpl::create(const std::string& name) const
{		
	return UML4CPPProfileFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EObject> UML4CPPProfilePluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	std::cout << "WARNING: container based create function is not implemented for UML models!!!" << std::endl;
	return nullptr; //UML4CPPProfileFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<uml::Factory> UML4CPPProfilePluginImpl::getFactory()
{
	return UML4CPPProfileFactory::eInstance();
}

std::shared_ptr<uml::Package> UML4CPPProfilePluginImpl::getPackage()
{
	return UML4CPPProfilePackage::eInstance();
}

std::string UML4CPPProfilePluginImpl::eclipseURI()
{
	return "";
}

std::string UML4CPPProfilePluginImpl::eNAME()
{
	return "UML4CPPProfile";
}

std::string UML4CPPProfilePluginImpl::eNS_URI()
{
	return "http://www.tu-ilmenau.de/sse/UML4CPPProfile";
}

std::string UML4CPPProfilePluginImpl::eNS_PREFIX()
{
	return "";
}
