//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FORKNODETEST_PLUGIN_HPP
#define FORKNODETEST_PLUGIN_HPP

#include "pluginFramework/UMLModelPlugin.hpp"

namespace forkNodeTest
{
	class ForkNodeTestPlugin : virtual public UMLModelPlugin
	{
		public:
			static std::shared_ptr<MDE4CPPPlugin> eInstance();
	
			virtual std::string eclipseURI() = 0;
			virtual std::string eNAME() = 0;
			virtual std::string eNS_URI() = 0;
			virtual std::string eNS_PREFIX() = 0;
	
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name) = 0;
			virtual std::shared_ptr<uml::Factory> getFactory() = 0;
			virtual std::shared_ptr<uml::Package> getPackage() = 0;
	
		protected:
			ForkNodeTestPlugin(){};
			virtual ~ForkNodeTestPlugin(){};
	
		private:
			static std::shared_ptr<MDE4CPPPlugin> instance;
	};
}
#endif /* end of include guard: FORKNODETEST_PLUGIN_HPP */
