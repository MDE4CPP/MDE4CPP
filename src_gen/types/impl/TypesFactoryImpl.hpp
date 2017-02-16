//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef TYPESFACTORYIMPL_HPP
#define TYPESFACTORYIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#include "impl/EFactoryImpl.hpp"


#include "TypesFactory.hpp"

namespace types 
{
	class TypesFactoryImpl : virtual public ecore::EFactoryImpl , virtual public TypesFactory 
	{
		private:    
			TypesFactoryImpl(TypesFactoryImpl const&) = delete;
			TypesFactoryImpl& operator=(TypesFactoryImpl const&) = delete;

		protected:
			friend class TypesFactory;
			// Constructor
			TypesFactoryImpl();

		public:
			virtual ~TypesFactoryImpl();
			virtual ecore::EObject* create(ecore::EClass* _class) const;

			//Creator functions
			

			//Package
			virtual TypesPackage* getTypesPackage() const;

		private:
			static TypesFactory * create();
			virtual void init() {}

	};
}
#endif /* end of include guard: TYPESFACTORYIMPL_HPP */

