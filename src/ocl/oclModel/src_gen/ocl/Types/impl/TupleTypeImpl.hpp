//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPES_TUPLETYPETUPLETYPEIMPL_HPP
#define OCL_TYPES_TUPLETYPETUPLETYPEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../TupleType.hpp"

#include "ocl/Types/impl/TypesFactoryImpl.hpp"
#include "ecore/impl/EDataTypeImpl.hpp"

//*********************************
namespace ocl::Types 
{
	class OCL_API TupleTypeImpl : virtual public ecore::EDataTypeImpl, virtual public TupleType 
	{
		public: 
			TupleTypeImpl(const TupleTypeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TupleTypeImpl& operator=(TupleTypeImpl const&); 

		protected:
			friend class ocl::Types::TypesFactoryImpl;
			TupleTypeImpl();
			virtual std::shared_ptr<ocl::Types::TupleType> getThisTupleTypePtr() const;
			virtual void setThisTupleTypePtr(std::weak_ptr<ocl::Types::TupleType> thisTupleTypePtr);

			//Additional constructors for the containments back reference
			TupleTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage);

		public:
			//destructor
			virtual ~TupleTypeImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ocl::Values::TupleValue>& getInstance() const ;
			virtual void setInstance(const std::shared_ptr<ocl::Values::TupleValue>&) ;
			virtual const std::shared_ptr<Bag<ocl::Types::NameTypeBinding>>& getParts() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
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

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const Any& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments) ;

		private:
			std::weak_ptr<ocl::Types::TupleType> m_thisTupleTypePtr;
	};
}
#endif /* end of include guard: OCL_TYPES_TUPLETYPETUPLETYPEIMPL_HPP */