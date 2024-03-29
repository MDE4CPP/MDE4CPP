//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_PLUGINIMPL_HPP
#define UML4CPPPROFILE_PLUGINIMPL_HPP

#include "UML4CPPProfile/UML4CPPProfilePlugin.hpp"

namespace UML4CPPProfile 
{
	class UML4CPPProfilePluginImpl : virtual public UML4CPPProfilePlugin 
	{
		public:
			UML4CPPProfilePluginImpl();
			virtual ~UML4CPPProfilePluginImpl();
		
			virtual std::string eclipseURI();
			virtual std::string eNAME();
			virtual std::string eNS_URI();
			virtual std::string eNS_PREFIX();
	
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name) const;
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID = -1) const;
			virtual std::shared_ptr<uml::Factory> getFactory();
			virtual std::shared_ptr<uml::Package> getPackage();
	};
}
#endif /* end of include guard: UML4CPPPROFILE_PLUGINIMPL_HPP */
