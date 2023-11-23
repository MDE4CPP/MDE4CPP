//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_INTEGERFUNCTIONS_METAMODELPACKAGE_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_INTEGERFUNCTIONS_METAMODELPACKAGE_HPP
#include "uml/Package.hpp"

namespace uml 
{
	class FunctionBehavior;
	class Parameter;
}


namespace FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions 
{
	/*!
	The Metamodel Package for the IntegerFunctions metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	class IntegerFunctionsPackage : virtual public uml::Package
	{
		//protected default construcotr
		protected:
			IntegerFunctionsPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			//getter for the ownedMember
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Abs() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Abs_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Abs_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Div() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Div_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Div_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Div_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Max() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Max_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Max_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Max_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Min() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Min_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Min_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Min_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Mod() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Mod_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Mod_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Mod_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Neg() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Neg_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Neg_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToInteger() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToInteger_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToInteger_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToString() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToString_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToString_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToUnlimitedNatural() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToUnlimitedNatural_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToUnlimitedNatural_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_divide() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_divide_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_divide_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_divide_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_equals() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_equals_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_equals_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_equals_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_greaterOrEqual() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_greaterOrEqual_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_greaterOrEqual_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_greaterOrEqual_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_greaterThan() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_greaterThan_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_greaterThan_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_greaterThan_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_lessOrEqual() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_lessOrEqual_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_lessOrEqual_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_lessOrEqual_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_lessThan() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_lessThan_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_lessThan_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_lessThan_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_minus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_minus_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_minus_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_minus_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_plus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_plus_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_plus_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_plus_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_times() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_times_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_times_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_times_y() = 0;  
			
			

			//getter for subPackages

			//Singleton Getter
			public:
				static std::shared_ptr<IntegerFunctionsPackage> eInstance();

			//Static IDs
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Abs
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_ABS = 602374976;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_ABS_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_ABS_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Div
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_DIV = 543107567;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_DIV_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_DIV_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Max
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MAX = 1493115879;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MAX_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MAX_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Min
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MIN = 205392146;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MIN_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MIN_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Mod
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MOD = 673506638;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MOD_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MOD_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Neg
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_NEG = 1815942256;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_NEG_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_NEG_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToInteger
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER = 1382307485;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToString
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING = 424545115;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToUnlimitedNatural
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOUNLIMITEDNATURAL = 1678536007;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOUNLIMITEDNATURAL_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOUNLIMITEDNATURAL_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::divide
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_DIVIDE = 2130472306;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_DIVIDE_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_DIVIDE_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::equals
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_EQUALS = 322742276;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_EQUALS_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_EQUALS_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::greaterOrEqual
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL = 355417666;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::greaterThan
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN = 708916300;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::lessOrEqual
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL = 905957665;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::lessThan
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN = 426329346;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::minus
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MINUS = 1283873165;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MINUS_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MINUS_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::plus
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_PLUS = 1909619359;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_PLUS_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_PLUS_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::times
			static const unsigned long INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TIMES = 149723569;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TIMES_FEATURE_COUNT = 0;
			static const unsigned int INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TIMES_OPERATION_COUNT = 0;
			
			
			
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_INTEGERFUNCTIONS_METAMODELPACKAGE_HPP */
