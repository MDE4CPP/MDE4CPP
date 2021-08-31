//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPES_SEQUENCETYPESEQUENCETYPEIMPL_HPP
#define OCL_TYPES_SEQUENCETYPESEQUENCETYPEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../SequenceType.hpp"

#include "ocl/Types/impl/TypesFactoryImpl.hpp"
#include "ocl/Types/impl/CollectionTypeImpl.hpp"

//*********************************
namespace ocl::Types 
{
	class OCL_API SequenceTypeImpl : virtual public CollectionTypeImpl, virtual public SequenceType 
	{
		public: 
			SequenceTypeImpl(const SequenceTypeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SequenceTypeImpl& operator=(SequenceTypeImpl const&); 

		protected:
			friend class ocl::Types::TypesFactoryImpl;
			SequenceTypeImpl();
			virtual std::shared_ptr<SequenceType> getThisSequenceTypePtr() const;
			virtual void setThisSequenceTypePtr(std::weak_ptr<SequenceType> thisSequenceTypePtr);

			//Additional constructors for the containments back reference
			SequenceTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage);

		public:
			//destructor
			virtual ~SequenceTypeImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
			//*********************************
			
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<SequenceType> m_thisSequenceTypePtr;
	};
}
#endif /* end of include guard: OCL_TYPES_SEQUENCETYPESEQUENCETYPEIMPL_HPP */
