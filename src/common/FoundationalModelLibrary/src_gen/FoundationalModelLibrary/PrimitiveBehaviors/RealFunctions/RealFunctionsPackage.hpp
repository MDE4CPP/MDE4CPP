//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS_METAMODELPACKAGE_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS_METAMODELPACKAGE_HPP
#include "uml/Package.hpp"

namespace uml 
{
	class FunctionBehavior;
	class Parameter;
	class ConnectorEnd;
}


namespace FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions 
{
	/*!
	The Metamodel Package for the RealFunctions metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	class RealFunctionsPackage : virtual public uml::Package
	{
		//protected default construcotr
		protected:
			RealFunctionsPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			//getter for the ownedMember
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_x() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_y() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_x() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_y() = 0;  
			
			

			//getter for subPackages

			//Singleton Getter
			public:
				static std::shared_ptr<RealFunctionsPackage> eInstance();

			//Static IDs
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Abs
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_ABS = 799786523;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_ABS_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_ABS_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Floor
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_FLOOR = 665379182;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_FLOOR_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_FLOOR_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Inv
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_INV = 1533637696;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_INV_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_INV_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Max
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_MAX = 1972493951;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_MAX_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_MAX_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Min
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_MIN = 831589988;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_MIN_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_MIN_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Neg
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_NEG = 987256119;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_NEG_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_NEG_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Round
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_ROUND = 190599376;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_ROUND_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_ROUND_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToInteger
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER = 1959741905;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToReal
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_TOREAL = 1017578801;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_TOREAL_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_TOREAL_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToString
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING = 263235363;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::divide
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_DIVIDE = 747233729;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_DIVIDE_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_DIVIDE_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::greaterOrEqual
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL = 831966034;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::greaterThan
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN = 352337715;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::lessOrEqual
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL = 19146371;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::lessThan
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN = 820643239;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::minus
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_MINUS = 782842255;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_MINUS_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_MINUS_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::plus
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_PLUS = 643938047;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_PLUS_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_PLUS_OPERATION_COUNT = 0;
			
			//FunctionBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::times
			static const unsigned long REALFUNCTIONS_FUNCTIONBEHAVIOR_TIMES = 937912968;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_TIMES_FEATURE_COUNT = 0;
			static const unsigned int REALFUNCTIONS_FUNCTIONBEHAVIOR_TIMES_OPERATION_COUNT = 0;
			
			
			
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS_METAMODELPACKAGE_HPP */
