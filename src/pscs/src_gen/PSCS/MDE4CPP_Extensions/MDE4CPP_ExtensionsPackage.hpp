//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_MDE4CPP_EXTENSIONSPACKAGE_HPP
#define PSCS_MDE4CPP_EXTENSIONSPACKAGE_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EClass;
	class EAnnotation;
	class EGenericType;
	class EStringToStringMapEntry;
	class EOperation;
	class EReference;
	class EDataType;
}

namespace PSCS::MDE4CPP_Extensions 
{
	class PSCS_Object;
}
 
namespace PSCS::MDE4CPP_Extensions 
{
	/*!
	The Metamodel Package for the MDE4CPP_Extensions metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API MDE4CPP_ExtensionsPackage : virtual public ecore::EPackage 
	{
		private:    
			MDE4CPP_ExtensionsPackage(MDE4CPP_ExtensionsPackage const&) = delete;
			MDE4CPP_ExtensionsPackage& operator=(MDE4CPP_ExtensionsPackage const&) = delete;

		protected:
			MDE4CPP_ExtensionsPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class PSCS_Object
			//Class and Feature IDs 
			static const unsigned long PSCS_OBJECT_CLASS = 1088313541;
			static const unsigned int PSCS_OBJECT_CLASS_FEATURE_COUNT = 8;
			static const unsigned int PSCS_OBJECT_CLASS_OPERATION_COUNT = 50;
			
			static const unsigned long PSCS_OBJECT_ATTRIBUTE_DEFININGPORT = 1420013449;
			
			static const unsigned long PSCS_OBJECT_OPERATION_ISINTERACTIONPOINT = 4059681913;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getPSCS_Object_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getPSCS_Object_Attribute_definingPort() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getPSCS_Object_Operation_isInteractionPoint() const = 0;
			
			// End Class PSCS_Object

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<MDE4CPP_ExtensionsPackage> eInstance();
	};
}
#endif /* end of include guard: PSCS_MDE4CPP_EXTENSIONSPACKAGE_HPP */
