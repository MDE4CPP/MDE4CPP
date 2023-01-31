#include "umlReflection/impl/UMLPluginImpl.hpp"

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


#include "umlReflection/UMLPackage.hpp"

using namespace UML;

//static initialization
std::shared_ptr<MDE4CPPPlugin> UMLPlugin::eInstance()
{
	static std::shared_ptr<MDE4CPPPlugin> instance;

	if(instance==nullptr)
	{
		//create a new Singelton instance
		instance.reset(new UMLPluginImpl());
	}
	return instance;
}

std::shared_ptr<MDE4CPPPlugin> start()
{
	return UMLPluginImpl::eInstance();
}

//*********************************
// Constructor / Destructor
//*********************************
UMLPluginImpl::UMLPluginImpl()
{
}

UMLPluginImpl::~UMLPluginImpl()
{
}

std::shared_ptr<ecore::EObject> UMLPluginImpl::create(const std::string& name) const
{		
	return nullptr;
}

std::shared_ptr<ecore::EObject> UMLPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return nullptr;
}

std::shared_ptr<uml::Factory> UMLPluginImpl::getFactory()
{
	return nullptr;
}

std::shared_ptr<uml::Package> UMLPluginImpl::getPackage()
{
	return UMLPackage::eInstance();
}

std::string UMLPluginImpl::eclipseURI()
{
	return "pathmap://UML_METAMODELS/UML.metamodel.uml";
}

std::string UMLPluginImpl::eNAME()
{
	return "UML";
}

std::string UMLPluginImpl::eNS_URI()
{
	return "http://www.omg.org/spec/UML/20131001";
}

std::string UMLPluginImpl::eNS_PREFIX()
{
	return "";
}
