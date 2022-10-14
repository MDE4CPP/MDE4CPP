//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EOPERATION_HPP
#define ECORE_EOPERATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace ecore 
{
	class EAnnotation;
	class EClass;
	class EClassifier;
	class EGenericType;
	class EParameter;
	class ETypeParameter;
}

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/ETypedElement.hpp"




//*********************************
namespace ecore 
{
	
	class ECORE_API EOperation : virtual public ETypedElement
	{
		public:
 			EOperation(const EOperation &) {}

		protected:
			EOperation(){}
			//Additional constructors for the containments back reference
			EOperation(std::weak_ptr<ecore::EObject> par_eContainer);

			//Additional constructors for the containments back reference
			EOperation(std::weak_ptr<ecore::EClass> par_eContainingClass);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EOperation() {}

			//*********************************
			// Operations
			//*********************************
			
			virtual bool isOverrideOf(std::shared_ptr<ecore::EOperation> someOperation) const = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual int getOperationID() const = 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<ecore::EClass> getEContainingClass() const = 0;
			virtual std::shared_ptr<Bag<ecore::EClassifier>> getEExceptions() const = 0;
			virtual std::shared_ptr<Bag<ecore::EGenericType>> getEGenericExceptions() const = 0;
			virtual std::shared_ptr<Subset<ecore::EParameter, ecore::EObject>> getEParameters() const = 0;
			virtual std::shared_ptr<Bag<ecore::ETypeParameter>> getETypeParameters() const = 0;

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
			int m_operationID= -1;
			
			//*********************************
			// Reference Members
			//*********************************
			std::weak_ptr<ecore::EClass> m_eContainingClass;
			mutable std::shared_ptr<Bag<ecore::EClassifier>> m_eExceptions;
			mutable std::shared_ptr<Bag<ecore::EGenericType>> m_eGenericExceptions;
			mutable std::shared_ptr<Subset<ecore::EParameter, ecore::EObject>> m_eParameters;
			mutable std::shared_ptr<Bag<ecore::ETypeParameter>> m_eTypeParameters;
	};
}
#endif /* end of include guard: ECORE_EOPERATION_HPP */
