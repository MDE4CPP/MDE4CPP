#include "ecoreReflection/impl/EcorePluginImpl.hpp"

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


#include "ecoreReflection/EcorePackage.hpp"

using namespace Ecore;

//static initialization
std::shared_ptr<MDE4CPPPlugin> EcorePlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance;

	if(instance==nullptr)
	{
		//create a new Singelton instance
		instance.reset(new EcorePluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return EcorePluginImpl::eInstance();
}

//*********************************
// Constructor / Destructor
//*********************************
EcorePluginImpl::EcorePluginImpl()
{
}

EcorePluginImpl::~EcorePluginImpl()
{
}

std::shared_ptr<ecore::EObject> EcorePluginImpl::create(const std::string& name) const
{		
	return nullptr;
}

std::shared_ptr<ecore::EObject> EcorePluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return nullptr;
}

std::shared_ptr<uml::Factory> EcorePluginImpl::getFactory()
{
	return nullptr;
}

std::shared_ptr<uml::Package> EcorePluginImpl::getPackage()
{
	return EcorePackage::eInstance();
}

std::string EcorePluginImpl::eclipseURI()
{
	return "pathmap://UML_METAMODELS/Ecore.metamodel.uml";
}

std::string EcorePluginImpl::eNAME()
{
	return "Ecore";
}

std::string EcorePluginImpl::eNS_URI()
{
	return "http://www.eclipse.org/emf/2002/Ecore";
}

std::string EcorePluginImpl::eNS_PREFIX()
{
	return "";
}
