//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS_FACTORY_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS_FACTORY_HPP

#include "uml/Factory.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/RealFunctionsPackage.hpp"


namespace FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions 
{
	class RealFunctionsPackage;
	class RealFunctionsFactory;

	class RealFunctionsFactory : virtual public uml::Factory 
	{ 
		protected:
			//protected default construcotr
			RealFunctionsFactory(){}

			//Singleton Instance and Getter
			
			private:
				static std::shared_ptr<RealFunctionsFactory> instance;
			public:
				static std::shared_ptr<RealFunctionsFactory> eInstance();

			//Creator functions
			virtual std::shared_ptr<uml::Element> create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const = 0;
			virtual std::shared_ptr<uml::Element> create(const std::shared_ptr<uml::Class> _class,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const = 0;
			virtual std::shared_ptr<uml::Element> create(const std::string _className,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const = 0;

			
			//Package
			virtual std::shared_ptr<RealFunctionsPackage> getRealFunctionsPackage() = 0;
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS_FACTORY_HPP */
