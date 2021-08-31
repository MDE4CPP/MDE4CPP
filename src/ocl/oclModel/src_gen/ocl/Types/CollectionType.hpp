//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPES_COLLECTIONTYPE_HPP
#define OCL_TYPES_COLLECTIONTYPE_HPP


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
namespace ocl::Values 
{
	class CollectionValue;
}
namespace ecore 
{
	class EAnnotation;
	class EPackage;
	class ETypeParameter;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "ecore/EDataType.hpp"

// enum includes



//*********************************
namespace ocl::Types 
{
	
	class OCL_API CollectionType: virtual public ecore::EDataType
	{
		public:
 			CollectionType(const CollectionType &) {}

		protected:
			CollectionType(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CollectionType() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual bool kindOf(std::shared_ptr<ocl::Types::CollectionType> coll) = 0;
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			
			//*********************************
			// References Getter & Setter
			//*********************************
			
			virtual std::shared_ptr<ecore::EClassifier> getElementType() const = 0;
			
			virtual void setElementType(std::shared_ptr<ecore::EClassifier>) = 0;
			
			virtual std::shared_ptr<ocl::Values::CollectionValue> getInstance() const = 0;
			
			virtual void setInstance(std::shared_ptr<ocl::Values::CollectionValue>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<ecore::EClassifier> m_elementType;
			std::shared_ptr<ocl::Values::CollectionValue> m_instance;

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
#endif /* end of include guard: OCL_TYPES_COLLECTIONTYPE_HPP */
