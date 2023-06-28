//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TYPEDELEMENTTYPEDELEMENTIMPL_HPP
#define UML_TYPEDELEMENTTYPEDELEMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../TypedElement.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TypedElementImpl : virtual public NamedElementImpl, virtual public TypedElement 
	{
		public: 
			TypedElementImpl(const TypedElementImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			TypedElementImpl& operator=(TypedElementImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TypedElementImpl();
			virtual std::shared_ptr<uml::TypedElement> getThisTypedElementPtr() const;
			virtual void setThisTypedElementPtr(std::weak_ptr<uml::TypedElement> thisTypedElementPtr);

			//Additional constructors for the containments back reference
			TypedElementImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			TypedElementImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~TypedElementImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The type of the TypedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual const std::shared_ptr<uml::Type>& getType() const ;
			/*!
			The type of the TypedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setType(const std::shared_ptr<uml::Type>&) ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::TypedElement> m_thisTypedElementPtr;
	};
}
#endif /* end of include guard: UML_TYPEDELEMENTTYPEDELEMENTIMPL_HPP */
