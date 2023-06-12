//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef PRIMITIVETYPES_METAMODELPACKAGE_HPP
#define PRIMITIVETYPES_METAMODELPACKAGE_HPP
#include "uml/Model.hpp"

namespace uml 
{
	class PrimitiveType;
	class ConnectorEnd;
}


namespace PrimitiveTypes 
{
	/*!
	The Metamodel Package for the PrimitiveTypes metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	class PrimitiveTypesPackage : virtual public uml::Model
	{
		//protected default construcotr
		protected:
			PrimitiveTypesPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			//getter for the ownedMember
			virtual const std::shared_ptr<uml::PrimitiveType>& get_PrimitiveTypes_Boolean() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_PrimitiveTypes_Integer() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_PrimitiveTypes_Real() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_PrimitiveTypes_String() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_PrimitiveTypes_UnlimitedNatural() = 0;  
			
			

			//getter for subPackages

			//Singleton Getter
			public:
				static std::shared_ptr<PrimitiveTypesPackage> eInstance();

	};
}
#endif /* end of include guard: PRIMITIVETYPES_METAMODELPACKAGE_HPP */
