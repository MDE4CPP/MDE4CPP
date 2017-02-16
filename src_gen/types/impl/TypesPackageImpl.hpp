//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef TYPESPACKAGEIMPL_HPP
#define TYPESPACKAGEIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#include <cassert>


#include "TypesPackage.hpp"
#include "EcorePackage.hpp"

#include "impl/EPackageImpl.hpp"

namespace types
{
	class TypesPackageImpl : public ecore::EPackageImpl ,virtual public TypesPackage
	{
		private:    
			TypesPackageImpl(TypesPackageImpl const&) = delete;
			TypesPackageImpl& operator=(TypesPackageImpl const&) = delete;

		protected:
			TypesPackageImpl();

		public:
			virtual ~TypesPackageImpl();


			virtual ecore::EDataType* getBoolean() const ;
			virtual ecore::EDataType* getInteger() const ;
			virtual ecore::EDataType* getReal() const ;
			virtual ecore::EDataType* getString() const ;
			virtual ecore::EDataType* getUnlimitedNatural() const ;
			

		private:
			
			ecore::EDataType* booleanEDataType = nullptr;
			ecore::EDataType* integerEDataType = nullptr;
			ecore::EDataType* realEDataType = nullptr;
			ecore::EDataType* stringEDataType = nullptr;
			ecore::EDataType* unlimitedNaturalEDataType = nullptr;
			

			friend class TypesPackage;

			static bool isInited;
			static TypesPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init();

		public:
			void initializePackageContents();
			void createPackageContents();
	};
}
#endif /* end of include guard: TYPESPACKAGEIMPL_HPP */

