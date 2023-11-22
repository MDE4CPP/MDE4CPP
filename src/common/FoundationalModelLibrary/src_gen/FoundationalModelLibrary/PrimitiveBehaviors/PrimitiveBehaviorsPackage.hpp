//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_METAMODELPACKAGE_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_METAMODELPACKAGE_HPP
#include "uml/Package.hpp"

namespace uml 
{
	class ConnectorEnd;
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions 
{
	class BooleanFunctionsPackage;
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions 
{
	class IntegerFunctionsPackage;
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions 
{
	class RealFunctionsPackage;
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions 
{
	class StringFunctionsPackage;
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions 
{
	class UnlimitedNaturalFunctionsPackage;
}

namespace FoundationalModelLibrary::PrimitiveBehaviors 
{
	/*!
	The Metamodel Package for the PrimitiveBehaviors metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	class PrimitiveBehaviorsPackage : virtual public uml::Package
	{
		//protected default construcotr
		protected:
			PrimitiveBehaviorsPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			//getter for the ownedMember
			
			

			//getter for subPackages
			virtual std::shared_ptr<BooleanFunctions::BooleanFunctionsPackage> getBooleanFunctions_Package() const  = 0;
			virtual std::shared_ptr<IntegerFunctions::IntegerFunctionsPackage> getIntegerFunctions_Package() const  = 0;
			virtual std::shared_ptr<RealFunctions::RealFunctionsPackage> getRealFunctions_Package() const  = 0;
			virtual std::shared_ptr<StringFunctions::StringFunctionsPackage> getStringFunctions_Package() const  = 0;
			virtual std::shared_ptr<UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage> getUnlimitedNaturalFunctions_Package() const  = 0;

			//Singleton Getter
			public:
				static std::shared_ptr<PrimitiveBehaviorsPackage> eInstance();

			//Static IDs
			
			
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_METAMODELPACKAGE_HPP */