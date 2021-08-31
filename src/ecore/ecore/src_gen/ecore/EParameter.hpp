//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EPARAMETER_HPP
#define ECORE_EPARAMETER_HPP


#include <memory>
#include <string>
// forward declarations


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
	class EClassifier;
	class EGenericType;
	class EOperation;
}

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/ETypedElement.hpp"

// enum includes



//*********************************
namespace ecore 
{
	
	class ECORE_API EParameter: virtual public ETypedElement
	{
		public:
 			EParameter(const EParameter &) {}

		protected:
			EParameter(){}
			//Additional constructors for the containments back reference
			EParameter(std::weak_ptr<ecore::EObject> par_eContainer);

			//Additional constructors for the containments back reference
			EParameter(std::weak_ptr<ecore::EOperation> par_eOperation);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EParameter() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			
			//*********************************
			// References Getter & Setter
			//*********************************
			
			virtual std::weak_ptr<ecore::EOperation> getEOperation() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::weak_ptr<ecore::EOperation> m_eOperation;

		public:
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<ecore::EObject>> getEContens() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: ECORE_EPARAMETER_HPP */
