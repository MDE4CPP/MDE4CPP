//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_BOOLEANFUNCTIONS_METAMODELPACKAGEIMPL_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_BOOLEANFUNCTIONS_METAMODELPACKAGEIMPL_HPP

#include "FoundationalModelLibrary/PrimitiveBehaviors/BooleanFunctions/BooleanFunctionsPackage.hpp"
#include "uml/impl/PackageImpl.hpp"

namespace uml
{
	class LiteralInteger;
	class umlFactory;
}


namespace FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions
{
	class BooleanFunctionsPackageImpl : virtual public uml::PackageImpl, virtual public BooleanFunctionsPackage
	{
			friend class BooleanFunctionsPackage;
			// Constructor
			BooleanFunctionsPackageImpl();

		public:
			// destructor
			virtual ~BooleanFunctionsPackageImpl();

			//getter for the ownedMember
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x();  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x();  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y();  
			
			
			

			//getter for subPackages

		private:
			//private variables for ownedMember of the metamodel package
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_y = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result = nullptr;
			std::shared_ptr<uml::LiteralInteger> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result_lowerValue_LiteralInteger_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_x = nullptr;
			std::shared_ptr<uml::FunctionBehavior> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_x = nullptr;
			std::shared_ptr<uml::Parameter> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_y = nullptr;
			
			
			

			static BooleanFunctionsPackage* create();
			static bool isInited;
			bool isInitialized = false;
			bool isCreated = false;

			void initMetaModel();
			virtual void init(std::shared_ptr<uml::Package> package);

		public:
 			void initializePackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);
			void createPackageContents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions);

		private:
			void createPackageActivities(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageClasses(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageDataTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageAssociations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageDependencies(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageEnumerationLiterals(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageEvents(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInstanceSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInterfaceRealizations(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInterfaces(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackagePrimitiveTypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageSignals(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageStereotypes(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);
			void createPackageValueSpecifications(std::shared_ptr<uml::Package> foundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions, std::shared_ptr<uml::umlFactory> factory);

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
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_BOOLEANFUNCTIONS_METAMODELPACKAGEIMPL_HPP */
