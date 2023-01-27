//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_VALUESPACKAGE_HPP
#define FUML_SEMANTICS_VALUESPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EReference;
	class EDataType;
	class EGenericType;
	class EStringToStringMapEntry;
	class EOperation;
	class EParameter;
	class EClass;
	class EAnnotation;
}

namespace fUML::Semantics::Values 
{

}
 
namespace fUML::Semantics::Values 
{
	/*!
	The Metamodel Package for the Values metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API ValuesPackage : virtual public ecore::EPackage 
	{
		private:    
			ValuesPackage(ValuesPackage const&) = delete;
			ValuesPackage& operator=(ValuesPackage const&) = delete;

		protected:
			ValuesPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<ValuesPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_VALUESPACKAGE_HPP */
