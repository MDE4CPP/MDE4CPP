//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EPARAMETER_HPP
#define ECORE_EPARAMETER_HPP

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
	class EClassifier;
}

namespace ecore 
{
	class EGenericType;
}

namespace ecore 
{
	class EOperation;
}

namespace ecore 
{
	class ETypedElement;
}

// base class includes
#include "ETypedElement.hpp"

// enum includes


//*********************************
namespace ecore 
{
	/*!
	 */
	class EParameter:virtual public ETypedElement	{
		public:
 			EParameter(const EParameter &) {}
			EParameter& operator=(EParameter const&) = delete;
	
		protected:
			EParameter(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~EParameter() {}

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
			virtual ecore::EOperation *  getEOperation() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			ecore::EOperation *  m_eOperation =  nullptr ;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: ECORE_EPARAMETER_HPP */

