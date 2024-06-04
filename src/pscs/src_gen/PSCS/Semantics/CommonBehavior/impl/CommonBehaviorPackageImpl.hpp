//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP
#define PSCS_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "PSCS/Semantics/CommonBehavior/CommonBehaviorPackage.hpp" 


namespace PSCS::Semantics::CommonBehavior 
{
	class CS_EventOccurrence;}

namespace ecore
{
	class ecoreFactory;
}

namespace PSCS::Semantics::CommonBehavior
{
	class PSCS_API CommonBehaviorPackageImpl : public ecore::EPackageImpl ,virtual public CommonBehaviorPackage
	{
		private:    
			CommonBehaviorPackageImpl(CommonBehaviorPackageImpl const&) = delete;
			CommonBehaviorPackageImpl& operator=(CommonBehaviorPackageImpl const&) = delete;

		protected:
			CommonBehaviorPackageImpl();

		public:
			virtual ~CommonBehaviorPackageImpl();

			// Begin Class CS_EventOccurrence
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getCS_EventOccurrence_Class() const ;
			
			virtual const std::shared_ptr<ecore::EAttribute>& getCS_EventOccurrence_Attribute_propagationInward() const ;
			
			virtual const std::shared_ptr<ecore::EReference>& getCS_EventOccurrence_Attribute_onPort() const ;
			virtual const std::shared_ptr<ecore::EReference>& getCS_EventOccurrence_Attribute_wrappedEventOccurrence() const ;
			
			
			// End Class CS_EventOccurrence

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_cS_EventOccurrence_Class = nullptr;
			
			std::shared_ptr<ecore::EAttribute> m_cS_EventOccurrence_Attribute_propagationInward = nullptr;
			std::shared_ptr<ecore::EReference> m_cS_EventOccurrence_Attribute_onPort = nullptr;std::shared_ptr<ecore::EReference> m_cS_EventOccurrence_Attribute_wrappedEventOccurrence = nullptr;
			

			friend class CommonBehaviorPackage;

			static bool isInited;
			static CommonBehaviorPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createCS_EventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeCS_EventOccurrenceContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: PSCS_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP */
