//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ETYPEPARAMETER_HPP
#define ECORE_ETYPEPARAMETER_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#include <string>
#include <map>
#include <vector>
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace ecore 
{
	class EAnnotation;
}

namespace ecore 
{
	class EGenericType;
}

namespace ecore 
{
	class ENamedElement;
}

// base class includes
#include "ENamedElement.hpp"

// enum includes


//*********************************
namespace ecore 
{
	/*!
	 */
	class ETypeParameter:virtual public ENamedElement	{
		public:
 			ETypeParameter(const ETypeParameter &) {}
			ETypeParameter& operator=(ETypeParameter const&) = delete;
	
		protected:
			ETypeParameter(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ETypeParameter() {}

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
			virtual std::vector<ecore::EGenericType * > *  getEBounds() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::vector<ecore::EGenericType * > *  m_eBounds =  nullptr ;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: ECORE_ETYPEPARAMETER_HPP */

