//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_BOOLEANFUNCTIONS_METAMODELPACKAGE_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_BOOLEANFUNCTIONS_METAMODELPACKAGE_HPP
#include "uml/Package.hpp"

namespace uml 
{
	class FunctionBehavior;
	class Parameter;
	class ConnectorEnd;
}


namespace FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions 
{
	/*!
	The Metamodel Package for the BooleanFunctions metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	class BooleanFunctionsPackage : virtual public uml::Package
	{
		//protected default construcotr
		protected:
			BooleanFunctionsPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			//getter for the ownedMember
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y() = 0;  
			
			

			//getter for subPackages

			//Singleton Getter
			public:
				static std::shared_ptr<BooleanFunctionsPackage> eInstance();

			//Static IDs
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::And
			static const unsigned long BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_AND = 1043801031;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_AND_FEATURE_COUNT = 0;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_AND_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Implies
			static const unsigned long BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_IMPLIES = 1527099367;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_IMPLIES_FEATURE_COUNT = 0;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_IMPLIES_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Not
			static const unsigned long BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_NOT = 408850021;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_NOT_FEATURE_COUNT = 0;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_NOT_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Or
			static const unsigned long BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_OR = 1698755983;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_OR_FEATURE_COUNT = 0;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_OR_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::ToBoolean
			static const unsigned long BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOBOOLEAN = 470844518;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOBOOLEAN_FEATURE_COUNT = 0;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOBOOLEAN_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::ToString
			static const unsigned long BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING = 1723814946;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING_FEATURE_COUNT = 0;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Xor
			static const unsigned long BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_XOR = 2095353672;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_XOR_FEATURE_COUNT = 0;
			static const unsigned int BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_XOR_OPERATION_COUNT = 0;
			
			
			
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_BOOLEANFUNCTIONS_METAMODELPACKAGE_HPP */