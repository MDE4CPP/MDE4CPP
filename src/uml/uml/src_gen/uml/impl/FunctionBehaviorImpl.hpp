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
			 
			virtual bool hasAllDataTypeAttributes(std::shared_ptr<uml::DataType> d) ;
			/*!
			A FunctionBehavior has at least one output Parameter.
			self.ownedParameter->
			  select(p | p.direction = ParameterDirectionKind::out or p.direction= ParameterDirectionKind::inout or p.direction= ParameterDirectionKind::return)->size() >= 1
			*/
			 
			virtual bool one_output_parameter(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The types of the ownedParameters are all DataTypes, which may not nest anything but other DataTypes.
			ownedParameter->forAll(p | p.type <> null and
			  p.type.oclIsTypeOf(DataType) and hasAllDataTypeAttributes(p.type.oclAsType(DataType)))
			*/
			 
			virtual bool types_of_parameters(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> getAttribute() const ;
			/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const ;
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;
			/*!
			The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const ;
			/*!
			The roles that instances may play in this StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> getRole() const ;
			
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::FunctionBehavior> m_thisFunctionBehaviorPtr;
	};
}
#endif /* end of include guard: UML_FUNCTIONBEHAVIORFUNCTIONBEHAVIORIMPL_HPP */
