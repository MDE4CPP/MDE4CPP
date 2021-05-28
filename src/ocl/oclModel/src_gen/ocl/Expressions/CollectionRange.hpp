//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_COLLECTIONRANGE_HPP
#define OCL_EXPRESSIONS_COLLECTIONRANGE_HPP


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

namespace ocl
{
	class oclFactory;
}

//Forward Declaration for used types 
namespace ocl::Expressions 
{
	class OclExpression;
}
namespace ecore 
{
	class EAnnotation;
	class EClassifier;
	class EGenericType;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "ocl/Expressions/CollectionLiteralPart.hpp"

// enum includes



//*********************************
namespace ocl::Expressions 
{
	
	class OCL_API CollectionRange: virtual public CollectionLiteralPart
	{
		public:
 			CollectionRange(const CollectionRange &) {}

		protected:
			CollectionRange(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CollectionRange() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getFirst() const = 0;
			
			virtual void setFirst(std::shared_ptr<ocl::Expressions::OclExpression>) = 0;
			
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getLast() const = 0;
			
			virtual void setLast(std::shared_ptr<ocl::Expressions::OclExpression>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<ocl::Expressions::OclExpression> m_first;
			std::shared_ptr<ocl::Expressions::OclExpression> m_last;

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: OCL_EXPRESSIONS_COLLECTIONRANGE_HPP */
