//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCSPACKAGEIMPL_HPP
#define PSCSPACKAGEIMPL_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "PSCS/PSCSPackage.hpp" 


namespace PSCS 
{
	namespace MDE4CPP_Extensions 
	{
		class MDE4CPP_ExtensionsPackage;
	}

	namespace Semantics 
	{
		class SemanticsPackage;
	}
}

namespace ecore
{
	class ecoreFactory;
}

namespace PSCS
{
	class PSCS_API PSCSPackageImpl : public ecore::EPackageImpl ,virtual public PSCSPackage
	{
		private:    
			PSCSPackageImpl(PSCSPackageImpl const&) = delete;
			PSCSPackageImpl& operator=(PSCSPackageImpl const&) = delete;

		protected:
			PSCSPackageImpl();

		public:
			virtual ~PSCSPackageImpl();


			
			// SubPackages Getters
			virtual std::shared_ptr<PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage> getMDE4CPP_Extensions_Package() const ;
			virtual std::shared_ptr<PSCS::Semantics::SemanticsPackage> getSemantics_Package() const ;
			

		private:
			
			
			
			
			

			friend class PSCSPackage;

			static bool isInited;
			static PSCSPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: PSCSPACKAGEIMPL_HPP */
