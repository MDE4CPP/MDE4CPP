//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef TYPESPACKAGE_HPP
#define TYPESPACKAGE_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#include "EPackage.hpp"
#include "EcoreFactory.hpp"

namespace types 
{
	class TypesPackage;
}

namespace types 
{
	/*!
	The Metamodel Package for the types metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	/*!
	 */
	class TypesPackage : virtual public ecore::EPackage 
	{
		private:    
			TypesPackage(TypesPackage const&) = delete;
			TypesPackage& operator=(TypesPackage const&) = delete;

		protected:
			TypesPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			static const int BOOLEAN = 0;
			static const int INTEGER = 1;
			static const int REAL = 2;
			static const int STRING = 3;
			static const int UNLIMITEDNATURAL = 4;
			
			virtual std::shared_ptr<ecore::EDataType> getBoolean() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getInteger() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getReal() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getString() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getUnlimitedNatural() const = 0;
			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<TypesPackage> instance;
			public:
				static std::shared_ptr<TypesPackage> eInstance();
	};
}
#endif /* end of include guard: TYPESPACKAGE_HPP */

