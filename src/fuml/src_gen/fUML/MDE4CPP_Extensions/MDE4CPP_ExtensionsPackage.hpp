//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_MDE4CPP_EXTENSIONSPACKAGE_HPP
#define FUML_MDE4CPP_EXTENSIONSPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EStringToStringMapEntry;
	class EAnnotation;
	class EReference;
	class EGenericType;
	class EClass;
}

namespace fUML::MDE4CPP_Extensions 
{
	class FUML_Object;
}
 
namespace fUML::MDE4CPP_Extensions 
{
	/*!
	The Metamodel Package for the MDE4CPP_Extensions metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API MDE4CPP_ExtensionsPackage : virtual public ecore::EPackage 
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

			// Begin Class FUML_Object
			//Class and Feature IDs 
			static const unsigned long FUML_OBJECT_CLASS = 1012292556;
			static const unsigned int FUML_OBJECT_CLASS_FEATURE_COUNT = 5;
			static const unsigned int FUML_OBJECT_CLASS_OPERATION_COUNT = 37;
			
			static const unsigned long FUML_OBJECT_ATTRIBUTE_OBJECTACTIVATION = 1242096493;
			
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getFUML_Object_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getFUML_Object_Attribute_objectActivation() const = 0;
			
			
			// End Class FUML_Object

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<MDE4CPP_ExtensionsPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_MDE4CPP_EXTENSIONSPACKAGE_HPP */