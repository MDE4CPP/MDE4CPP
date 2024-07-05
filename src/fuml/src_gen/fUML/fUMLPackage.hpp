//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUMLPACKAGE_HPP
#define FUMLPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EReference;
	class EAnnotation;
	class EParameter;
	class EAttribute;
	class EClass;
	class EDataType;
	class EOperation;
	class EStringToStringMapEntry;
	class EPackage;
	class EGenericType;
}

namespace fUML 
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
 
namespace fUML 
{
	/*!
	The Metamodel Package for the fUML metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API fUMLPackage : virtual public ecore::EPackage 
	{
		private:    
			fUMLPackage(fUMLPackage const&) = delete;
			fUMLPackage& operator=(fUMLPackage const&) = delete;

		protected:
			fUMLPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			
			

			virtual std::shared_ptr<fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage> getMDE4CPP_Extensions_Package() const = 0;
			virtual std::shared_ptr<fUML::Semantics::SemanticsPackage> getSemantics_Package() const = 0;
			

			//Singleton Getter
			public:
				static std::shared_ptr<fUMLPackage> eInstance();
	};
}
#endif /* end of include guard: FUMLPACKAGE_HPP */
