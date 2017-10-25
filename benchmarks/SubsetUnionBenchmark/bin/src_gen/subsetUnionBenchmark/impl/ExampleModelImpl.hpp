//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef SUBSETUNIONBENCHMARK_EXAMPLEMODELEXAMPLEMODELIMPL_HPP
#define SUBSETUNIONBENCHMARK_EXAMPLEMODELEXAMPLEMODELIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//*********************************
// generated Includes

//Model includes
#include "../ExampleModel.hpp"


#include "impl/EObjectImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace subsetUnionBenchmark 
{
	class ExampleModelImpl :virtual public ecore::EObjectImpl,
virtual public ExampleModel 
	{
		public: 
			ExampleModelImpl(const ExampleModelImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ExampleModelImpl& operator=(ExampleModelImpl const&) = delete;

		protected:
			friend class SubsetUnionBenchmarkFactoryImpl;
			ExampleModelImpl();



		public:
			//destructor
			virtual ~ExampleModelImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr< Bag<subsetUnionBenchmark::Container> > getContainer() const ;
			
							
			
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
#endif /* end of include guard: SUBSETUNIONBENCHMARK_EXAMPLEMODELEXAMPLEMODELIMPL_HPP */

