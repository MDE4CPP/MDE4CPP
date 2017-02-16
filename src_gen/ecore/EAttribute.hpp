//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EATTRIBUTE_HPP
#define ECORE_EATTRIBUTE_HPP

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
	class EClass;
}

namespace ecore 
{
	class EClassifier;
}

namespace ecore 
{
	class EDataType;
}

namespace ecore 
{
	class EGenericType;
}

namespace ecore 
{
	class EStructuralFeature;
}

// base class includes
#include "EStructuralFeature.hpp"

// enum includes


//*********************************
namespace ecore 
{
	/*!
	 */
	class EAttribute:virtual public EStructuralFeature	{
		public:
 			EAttribute(const EAttribute &) {}
			EAttribute& operator=(EAttribute const&) = delete;
	
		protected:
			EAttribute(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~EAttribute() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual bool isID() const = 0;
			
			/*!
			 */ 
			virtual void setID (bool _iD)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual ecore::EDataType *  getEAttributeType() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 */ 
			bool m_iD ;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			ecore::EDataType *  m_eAttributeType =  nullptr ;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: ECORE_EATTRIBUTE_HPP */

