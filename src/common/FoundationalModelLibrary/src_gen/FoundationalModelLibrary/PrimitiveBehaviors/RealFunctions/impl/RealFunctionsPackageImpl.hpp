//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS_METAMODELPACKAGEIMPL_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS_METAMODELPACKAGEIMPL_HPP

#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/RealFunctionsPackage.hpp"
#include "uml/impl/PackageImpl.hpp"

namespace uml
{
	class LiteralInteger;
	class umlFactory;
}


namespace FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions
{
	class RealFunctionsPackageImpl : virtual public uml::PackageImpl, virtual public RealFunctionsPackage
	{
			friend class RealFunctionsPackage;
			// Constructor
			RealFunctionsPackageImpl();

		public:
			// destructor
			virtual ~RealFunctionsPackageImpl();

			//getter for the ownedMember
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_y();  
			
			

			//getter for subPackages

		private:
			//private variables for ownedMember of the metamodel package
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result = nullptr;
			std::shared_ptr<uml::LiteralInteger> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result = nullptr;
			std::shared_ptr<uml::LiteralInteger> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_y = nullptr;
			
			

			static RealFunctionsPackage* create();
			static bool isInited;
			bool isInitialized = false;
			bool isCreated = false;

			void initMetaModel();
			virtual void init(std::shared_ptr<uml::Package> package);

		public:
 			void initializePackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);
			void createPackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions);

		private:
			void createPackageActivities(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageClasses(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageDataTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageAssociations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageDependencies(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageEnumerationLiterals(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInstanceSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInterfaceRealizations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInterfaces(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackagePrimitiveTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageStereotypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageValueSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_RealFunctions, std::shared_ptr<uml::umlFactory> factory);

			void initializePackageActivities();
			void initializePackageClasses();
			void initializePackageDataTypes();
			void initializePackageAssociations();
			void initializePackageDependencies();
			void initializePackageInstanceSpecifications();
			void initializePackageInterfaceRealizations();
			void initializePackageInterfaces();
			void initializePackageNestedPackages();
			void initializePackageStereotypes();
			void initializePackageValueSpecifications();
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS_METAMODELPACKAGEIMPL_HPP */
