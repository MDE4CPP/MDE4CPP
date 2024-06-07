//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP
#define PSCS_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EClass;
	class EAnnotation;
	class EGenericType;
	class EAttribute;
	class EStringToStringMapEntry;
	class EOperation;
	class EReference;
	class EDataType;
	class EParameter;
}

namespace PSCS::Semantics::CommonBehavior 
{
	class CS_EventOccurrence;
}
 
namespace PSCS::Semantics::CommonBehavior 
{
	/*!
	The Metamodel Package for the CommonBehavior metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API CommonBehaviorPackage : virtual public ecore::EPackage 
	{
		private:    
			CommonBehaviorPackage(CommonBehaviorPackage const&) = delete;
			CommonBehaviorPackage& operator=(CommonBehaviorPackage const&) = delete;

		protected:
			CommonBehaviorPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class CS_EventOccurrence
			//Class and Feature IDs 
			static const unsigned long CS_EVENTOCCURRENCE_CLASS = 619124533;
			static const unsigned int CS_EVENTOCCURRENCE_CLASS_FEATURE_COUNT = 4;
			static const unsigned int CS_EVENTOCCURRENCE_CLASS_OPERATION_COUNT = 5;
			static const unsigned long CS_EVENTOCCURRENCE_ATTRIBUTE_PROPAGATIONINWARD = 2052308718;
			
			static const unsigned long CS_EVENTOCCURRENCE_ATTRIBUTE_ONPORT = 68297454;
			static const unsigned long CS_EVENTOCCURRENCE_ATTRIBUTE_WRAPPEDEVENTOCCURRENCE = 146096912;
			
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getCS_EventOccurrence_Class() const = 0;
			
			virtual const std::shared_ptr<ecore::EAttribute>& getCS_EventOccurrence_Attribute_propagationInward() const = 0;
			
			virtual const std::shared_ptr<ecore::EReference>& getCS_EventOccurrence_Attribute_onPort() const = 0;
			virtual const std::shared_ptr<ecore::EReference>& getCS_EventOccurrence_Attribute_wrappedEventOccurrence() const = 0;
			
			
			// End Class CS_EventOccurrence

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<CommonBehaviorPackage> eInstance();
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP */
