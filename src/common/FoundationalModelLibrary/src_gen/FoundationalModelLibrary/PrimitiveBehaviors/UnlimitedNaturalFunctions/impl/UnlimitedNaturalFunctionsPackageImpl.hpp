//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_UNLIMITEDNATURALFUNCTIONS_METAMODELPACKAGEIMPL_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_UNLIMITEDNATURALFUNCTIONS_METAMODELPACKAGEIMPL_HPP

#include "FoundationalModelLibrary/PrimitiveBehaviors/UnlimitedNaturalFunctions/UnlimitedNaturalFunctionsPackage.hpp"
#include "uml/impl/PackageImpl.hpp"

namespace uml
{
	class LiteralInteger;
	class umlFactory;
}


namespace FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions
{
	class UnlimitedNaturalFunctionsPackageImpl : virtual public uml::PackageImpl, virtual public UnlimitedNaturalFunctionsPackage
	{
			friend class UnlimitedNaturalFunctionsPackage;
			// Constructor
			UnlimitedNaturalFunctionsPackageImpl();

		public:
			// destructor
			virtual ~UnlimitedNaturalFunctionsPackageImpl();

			//getter for the ownedMember
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Max();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Max_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Max_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Max_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Min();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Min_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Min_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Min_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToInteger();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToInteger_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToInteger_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToString();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToString_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToString_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToUnlimitedNatural();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToUnlimitedNatural_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToUnlimitedNatural_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterOrEqual();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterOrEqual_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterOrEqual_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterOrEqual_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterThan();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterThan_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterThan_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterThan_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessOrEqual();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessOrEqual_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessOrEqual_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessOrEqual_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessThan();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessThan_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessThan_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessThan_y();  
			
			

			//getter for subPackages

		private:
			//private variables for ownedMember of the metamodel package
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Max = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Max_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Max_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Max_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Min = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Min_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Min_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Min_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToInteger = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToInteger_result = nullptr;
			std::shared_ptr<uml::LiteralInteger> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToInteger_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToInteger_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToInteger_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToString = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToString_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToString_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToUnlimitedNatural = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToUnlimitedNatural_result = nullptr;
			std::shared_ptr<uml::LiteralInteger> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToUnlimitedNatural_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToUnlimitedNatural_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToUnlimitedNatural_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterOrEqual = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterOrEqual_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterOrEqual_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterOrEqual_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterThan = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterThan_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterThan_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterThan_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessOrEqual = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessOrEqual_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessOrEqual_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessOrEqual_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessThan = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessThan_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessThan_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessThan_y = nullptr;
			
			

			static UnlimitedNaturalFunctionsPackage* create();
			static bool isInited;
			bool isInitialized = false;
			bool isCreated = false;

			void initMetaModel();
			virtual void init(std::shared_ptr<uml::Package> package);

		public:
 			void initializePackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions);
			void createPackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions);

		private:
			void createPackageActivities(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageClasses(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageDataTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageAssociations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageDependencies(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageEnumerationLiterals(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageEvents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInstanceSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInterfaceRealizations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInterfaces(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackagePrimitiveTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageSignals(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageStereotypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageValueSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions, std::shared_ptr<uml::umlFactory> factory);

			void initializePackageActivities();
			void initializePackageClasses();
			void initializePackageDataTypes();
			void initializePackageAssociations();
			void initializePackageDependencies();
			void initializePackageEvents();
			void initializePackageInstanceSpecifications();
			void initializePackageInterfaceRealizations();
			void initializePackageInterfaces();
			void initializePackageNestedPackages();
			void initializePackageSignals();
			void initializePackageStereotypes();
			void initializePackageValueSpecifications();
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_UNLIMITEDNATURALFUNCTIONS_METAMODELPACKAGEIMPL_HPP */
