//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_FUNCTIONBEHAVIORFUNCTIONBEHAVIORIMPL_HPP
#define UML_FUNCTIONBEHAVIORFUNCTIONBEHAVIORIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../FunctionBehavior.hpp"

#include "uml/impl/OpaqueBehaviorImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API FunctionBehaviorImpl : virtual public OpaqueBehaviorImpl, virtual public FunctionBehavior 
	{
		public: 
			FunctionBehaviorImpl(const FunctionBehaviorImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			FunctionBehaviorImpl& operator=(FunctionBehaviorImpl const&); 

		protected:
			friend class umlFactoryImpl;
			FunctionBehaviorImpl();
			virtual std::shared_ptr<uml::FunctionBehavior> getThisFunctionBehaviorPtr() const;
			virtual void setThisFunctionBehaviorPtr(std::weak_ptr<uml::FunctionBehavior> thisFunctionBehaviorPtr);

			//Additional constructors for the containments back reference
			FunctionBehaviorImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier);
			//Additional constructors for the containments back reference
			FunctionBehaviorImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			FunctionBehaviorImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			FunctionBehaviorImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			FunctionBehaviorImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~FunctionBehaviorImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The hasAllDataTypeAttributes query tests whether the types of the attributes of the given DataType are all DataTypes, and similarly for all those DataTypes.
			result = (d.ownedAttribute->forAll(a |
			    a.type.oclIsKindOf(DataType) and
			      hasAllDataTypeAttributes(a.type.oclAsType(DataType))))
			<p>From package UML::CommonBehavior.</p>
			*/
			 
			virtual bool hasAllDataTypeAttributes(const std::shared_ptr<uml::DataType>& d) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
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
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::FunctionBehavior> m_thisFunctionBehaviorPtr;
	};
}
#endif /* end of include guard: UML_FUNCTIONBEHAVIORFUNCTIONBEHAVIORIMPL_HPP */
