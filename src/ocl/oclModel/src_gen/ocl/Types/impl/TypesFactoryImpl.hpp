//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPESFACTORYIMPL_HPP
#define OCL_TYPESFACTORYIMPL_HPP

// namespace macro header include
#include "ocl/ocl.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "ocl/Types/TypesFactory.hpp"

namespace Types 
{	class AnyType;
	class BagType;
	class CollectionType;
	class InvalidType;
	class MessageType;
	class NameTypeBinding;
	class OrderedSetType;
	class SequenceType;
	class SetType;
	class TemplateParameterType;
	class TupleType;
	class VoidType;
}

namespace ocl::Types 
{
	class OCL_API TypesFactoryImpl : virtual public ecore::EFactoryImpl , virtual public TypesFactory 
	{
		private:    
			TypesFactoryImpl(TypesFactoryImpl const&) = delete;
			TypesFactoryImpl& operator=(TypesFactoryImpl const&) = delete;

		protected:
			friend class TypesFactory;
			// Constructor
			TypesFactoryImpl();

		public:
			virtual ~TypesFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<ocl::Types::AnyType> createAnyType(const int metaElementID = TypesPackage::ANYTYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ocl::Types::AnyType> createAnyType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = TypesPackage::ANYTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::AnyType> createAnyType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID = TypesPackage::ANYTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::BagType> createBagType(const int metaElementID = TypesPackage::BAGTYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ocl::Types::BagType> createBagType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID = TypesPackage::BAGTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::CollectionType> createCollectionType(const int metaElementID = TypesPackage::COLLECTIONTYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ocl::Types::CollectionType> createCollectionType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = TypesPackage::COLLECTIONTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::CollectionType> createCollectionType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID = TypesPackage::COLLECTIONTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::InvalidType> createInvalidType(const int metaElementID = TypesPackage::INVALIDTYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ocl::Types::InvalidType> createInvalidType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = TypesPackage::INVALIDTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::InvalidType> createInvalidType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID = TypesPackage::INVALIDTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::MessageType> createMessageType(const int metaElementID = TypesPackage::MESSAGETYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ocl::Types::MessageType> createMessageType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = TypesPackage::MESSAGETYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::MessageType> createMessageType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID = TypesPackage::MESSAGETYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::NameTypeBinding> createNameTypeBinding(const int metaElementID = TypesPackage::NAMETYPEBINDING_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::OrderedSetType> createOrderedSetType(const int metaElementID = TypesPackage::ORDEREDSETTYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ocl::Types::OrderedSetType> createOrderedSetType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID = TypesPackage::ORDEREDSETTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::SequenceType> createSequenceType(const int metaElementID = TypesPackage::SEQUENCETYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ocl::Types::SequenceType> createSequenceType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID = TypesPackage::SEQUENCETYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::SetType> createSetType(const int metaElementID = TypesPackage::SETTYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ocl::Types::SetType> createSetType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID = TypesPackage::SETTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::TemplateParameterType> createTemplateParameterType(const int metaElementID = TypesPackage::TEMPLATEPARAMETERTYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ocl::Types::TemplateParameterType> createTemplateParameterType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = TypesPackage::TEMPLATEPARAMETERTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::TemplateParameterType> createTemplateParameterType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID = TypesPackage::TEMPLATEPARAMETERTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::TupleType> createTupleType(const int metaElementID = TypesPackage::TUPLETYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ocl::Types::TupleType> createTupleType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = TypesPackage::TUPLETYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::TupleType> createTupleType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID = TypesPackage::TUPLETYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::VoidType> createVoidType(const int metaElementID = TypesPackage::VOIDTYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ocl::Types::VoidType> createVoidType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = TypesPackage::VOIDTYPE_CLASS) const ;
			 virtual std::shared_ptr<ocl::Types::VoidType> createVoidType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID = TypesPackage::VOIDTYPE_CLASS) const ;
			 

		private:
			static TypesFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: OCL_TYPESFACTORYIMPL_HPP */
