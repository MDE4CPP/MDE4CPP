#include "FoundationalModelLibrary/impl/FoundationalModelLibraryPluginImpl.hpp"

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

#include "FoundationalModelLibrary/FoundationalModelLibraryFactory.hpp"
#include "FoundationalModelLibrary/FoundationalModelLibraryPackage.hpp"

using namespace FoundationalModelLibrary;

//*********************************
// Constructor / Destructor
//*********************************
FoundationalModelLibraryPluginImpl::FoundationalModelLibraryPluginImpl()
{
}

FoundationalModelLibraryPluginImpl::~FoundationalModelLibraryPluginImpl()
{
}

std::shared_ptr<ecore::EObject> FoundationalModelLibraryPluginImpl::create(const std::string& name) const
{		
	return FoundationalModelLibraryFactory::eInstance()->create(name);
}

std::shared_ptr<ecore::EObject> FoundationalModelLibraryPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	std::cout << "WARNING: container based create function is not implemented for UML models!!!" << std::endl;
	return nullptr; //FoundationalModelLibraryFactory::eInstance()->create(name, container, referenceID);
}

std::shared_ptr<uml::Factory> FoundationalModelLibraryPluginImpl::getFactory()
{
	return FoundationalModelLibraryFactory::eInstance();
}

std::shared_ptr<uml::Package> FoundationalModelLibraryPluginImpl::getPackage()
{
	return FoundationalModelLibraryPackage::eInstance();
}

std::string FoundationalModelLibraryPluginImpl::eclipseURI()
{
	return "";
}

std::string FoundationalModelLibraryPluginImpl::eNAME()
{
	return "FoundationalModelLibrary";
}

std::string FoundationalModelLibraryPluginImpl::eNS_URI()
{
	return "https://www.omg.org/spec/FUML/20150801";
}

std::string FoundationalModelLibraryPluginImpl::eNS_PREFIX()
{
	return "";
}
