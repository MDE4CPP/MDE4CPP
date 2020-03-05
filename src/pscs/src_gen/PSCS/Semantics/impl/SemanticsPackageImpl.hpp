//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICSPACKAGEIMPL_HPP
#define PSCS_SEMANTICSPACKAGEIMPL_HPP

#include "ecore/EcorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "PSCS/Semantics/SemanticsPackage.hpp" 


namespace PSCS::Semantics 
{
	namespace Actions 
	{
		class ActionsPackage;
	}

	namespace Classification 
	{
		class ClassificationPackage;
	}

	namespace CommonBehavior 
	{
		class CommonBehaviorPackage;
	}

	namespace Loci 
	{
		class LociPackage;
	}

	namespace StructuredClassifiers 
	{
		class StructuredClassifiersPackage;
	}

	namespace Values 
	{
		class ValuesPackage;
	}
}

namespace ecore
{
	class EcoreFactory;
}

namespace PSCS::Semantics
{
	class SemanticsPackageImpl : public ecore::EPackageImpl ,virtual public SemanticsPackage
	{
		private:    
			SemanticsPackageImpl(SemanticsPackageImpl const&) = delete;
			SemanticsPackageImpl& operator=(SemanticsPackageImpl const&) = delete;

		protected:
			SemanticsPackageImpl();

		public:
			virtual ~SemanticsPackageImpl();


			
			// SubPackages Getters
			virtual std::shared_ptr<Actions::ActionsPackage> getActions_Package() const ;
			virtual std::shared_ptr<Classification::ClassificationPackage> getClassification_Package() const ;
			virtual std::shared_ptr<CommonBehavior::CommonBehaviorPackage> getCommonBehavior_Package() const ;
			virtual std::shared_ptr<Loci::LociPackage> getLoci_Package() const ;
			virtual std::shared_ptr<StructuredClassifiers::StructuredClassifiersPackage> getStructuredClassifiers_Package() const ;
			virtual std::shared_ptr<Values::ValuesPackage> getValues_Package() const ;
			

		private:
			
			
			
			
			

			friend class SemanticsPackage;

			static bool isInited;
			static SemanticsPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);

			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: PSCS_SEMANTICSPACKAGEIMPL_HPP */
