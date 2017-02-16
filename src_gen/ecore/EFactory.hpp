//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EFACTORY_HPP
#define ECORE_EFACTORY_HPP

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
	class EDataType;
}

namespace ecore 
{
	class EModelElement;
}

namespace ecore 
{
	class EObject;
}

namespace ecore 
{
	class EPackage;
}

// base class includes
#include "EModelElement.hpp"

// enum includes


//*********************************
namespace ecore 
{
	/*!
	 */
	class EFactory:virtual public EModelElement	{
		public:
 			EFactory(const EFactory &) {}
			EFactory& operator=(EFactory const&) = delete;
	
		protected:
			EFactory(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~EFactory() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual ecore::EObject *  create(ecore::EClass *  eClass)  const  = 0;
			
			/*!
			 */ 
			virtual boost::any createFromString(ecore::EDataType *  eDataType,std::string literalValue)  const  = 0;
			
			/*!
			 */ 
			virtual std::string convertToString(ecore::EDataType *  eDataType,boost::any instanceValue)  const  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual ecore::EPackage *  getEPackage() const = 0;
			
			/*!
			 */
			virtual void setEPackage(ecore::EPackage *  _ePackage) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			ecore::EPackage *  m_ePackage =  nullptr ;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: ECORE_EFACTORY_HPP */

