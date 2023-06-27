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
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace ecore
{
	class ecoreFactory;
}

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
	
	class ECORE_API EOperation: virtual public ETypedElement
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
			
			virtual bool isOverrideOf(const std::shared_ptr<ecore::EOperation>& someOperation) const = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual int getOperationID() const = 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<ecore::EClass> getEContainingClass() const = 0;
			virtual const std::shared_ptr<Bag<ecore::EClassifier>>& getEExceptions() const = 0;
			virtual const std::shared_ptr<Bag<ecore::EGenericType>>& getEGenericExceptions() const = 0;
			virtual const std::shared_ptr<Subset<ecore::EParameter, ecore::EObject>>& getEParameters() const = 0;
			virtual const std::shared_ptr<Bag<ecore::ETypeParameter>>& getETypeParameters() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<ecore::EObject>> getEContentUnion() const = 0;

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

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
