//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EDATATYPE_HPP
#define ECORE_EDATATYPE_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace ecore 
{
	class EAnnotation;
	class EPackage;
	class ETypeParameter;
}

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/EClassifier.hpp"




//*********************************
namespace ecore 
{
	
	class ECORE_API EDataType : virtual public EClassifier
	{
		public:
 			EDataType(const EDataType &) {}

		protected:
			EDataType(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EDataType() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isSerializable() const = 0;
			virtual void setSerializable (bool _serializable)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			bool m_serializable= true;
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: ECORE_EDATATYPE_HPP */
