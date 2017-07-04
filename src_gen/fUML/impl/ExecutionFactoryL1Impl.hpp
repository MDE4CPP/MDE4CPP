//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EXECUTIONFACTORYL1EXECUTIONFACTORYL1IMPL_HPP
#define FUML_EXECUTIONFACTORYL1EXECUTIONFACTORYL1IMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../ExecutionFactoryL1.hpp"

#include "impl/ExecutionFactoryImpl.hpp"

#include "SubsetUnion.hpp"

#include "LiteralBoolean.hpp"
#include "FUMLFactory.hpp"
#include "LiteralString.hpp"
#include "LiteralInteger.hpp"
#include "LiteralReal.hpp"
#include "LiteralNull.hpp"
#include "InstanceValue.hpp"
#include "LiteralUnlimitedNatural.hpp"


//*********************************
namespace fUML 
{
	class ExecutionFactoryL1Impl :virtual public ExecutionFactoryImpl, virtual public ExecutionFactoryL1 
	{
		public: 
			ExecutionFactoryL1Impl(const ExecutionFactoryL1Impl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ExecutionFactoryL1Impl& operator=(ExecutionFactoryL1Impl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ExecutionFactoryL1Impl();

		public:
			//destructor
			virtual ~ExecutionFactoryL1Impl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::SemanticVisitor> 
			 instantiateVisitor(std::shared_ptr<uml::Element>  element)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_EXECUTIONFACTORYL1EXECUTIONFACTORYL1IMPL_HPP */
