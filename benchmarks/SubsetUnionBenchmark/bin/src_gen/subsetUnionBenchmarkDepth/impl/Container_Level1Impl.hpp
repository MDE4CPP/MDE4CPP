//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef SUBSETUNIONBENCHMARKDEPTH_CONTAINER_LEVEL1CONTAINER_LEVEL1IMPL_HPP
#define SUBSETUNIONBENCHMARKDEPTH_CONTAINER_LEVEL1CONTAINER_LEVEL1IMPL_HPP

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
#include "../Container_Level1.hpp"

#include "impl/ContainerImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace subsetUnionBenchmarkDepth 
{
	class Container_Level1Impl :virtual public ContainerImpl, virtual public Container_Level1 
	{
		public: 
			Container_Level1Impl(const Container_Level1Impl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			Container_Level1Impl& operator=(Container_Level1Impl const&) = delete;

		protected:
			friend class SubsetUnionBenchmarkDepthFactoryImpl;
			Container_Level1Impl();



		public:
			//destructor
			virtual ~Container_Level1Impl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<SubsetUnion<subsetUnionBenchmarkDepth::Element_Level1, subsetUnionBenchmarkDepth::Element > > getSubset1() const ;/*!
			 */
			virtual std::shared_ptr<Union<subsetUnionBenchmarkDepth::Element> > getUnion() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: SUBSETUNIONBENCHMARKDEPTH_CONTAINER_LEVEL1CONTAINER_LEVEL1IMPL_HPP */

