//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_BEHAVIORBEHAVIORIMPL_HPP
#define UML_BEHAVIORBEHAVIORIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Behavior.hpp"

#include "uml/impl/ClassImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API BehaviorImpl : virtual public ClassImpl, virtual public Behavior 
	{
		public: 
			BehaviorImpl(const BehaviorImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			BehaviorImpl& operator=(BehaviorImpl const&); 

		protected:
			friend class umlFactoryImpl;
			BehaviorImpl();
			virtual std::shared_ptr<uml::Behavior> getThisBehaviorPtr() const;
			virtual void setThisBehaviorPtr(std::weak_ptr<uml::Behavior> thisBehaviorPtr);

			//Additional constructors for the containments back reference
			BehaviorImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier);
			//Additional constructors for the containments back reference
			BehaviorImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			BehaviorImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			BehaviorImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			BehaviorImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~BehaviorImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The first BehavioredClassifier reached by following the chain of owner relationships from the Behavior, if any.
			if from.oclIsKindOf(BehavioredClassifier) then
			    from.oclAsType(BehavioredClassifier)
			else if from.owner = null then
			    null
			else
			    self.behavioredClassifier(from.owner)
			endif
			endif
			<p>From package UML::CommonBehavior.</p>
			*/
			 
			virtual std::shared_ptr<uml::BehavioredClassifier> behavioredClassifier(const std::shared_ptr<uml::Element>& from) ;
			
			/*!
			The in and inout ownedParameters of the Behavior.
			result = (ownedParameter->select(direction=ParameterDirectionKind::_'in' or direction=ParameterDirectionKind::inout))
			<p>From package UML::CommonBehavior.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Parameter>> inputParameters() ;
			/*!
			The out, inout and return ownedParameters.
			result = (ownedParameter->select(direction=ParameterDirectionKind::out or direction=ParameterDirectionKind::inout or direction=ParameterDirectionKind::return))
			<p>From package UML::CommonBehavior.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Parameter>> outputParameters() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Tells whether the Behavior can be invoked while it is still executing from a previous invocation.
			<p>From package UML::CommonBehavior.</p>
			*/
			 
			virtual bool getIsReentrant() const ;
			/*!
			Tells whether the Behavior can be invoked while it is still executing from a previous invocation.
			<p>From package UML::CommonBehavior.</p>
			*/
			 
			virtual void setIsReentrant (bool _isReentrant);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<uml::BehavioredClassifier> getBehavioredClassifier() const ;
			virtual void setBehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier>) ;
			/*!
			The BehavioredClassifier that is the context for the execution of the Behavior. A Behavior that is directly owned as a nestedClassifier does not have a context. Otherwise, to determine the context of a Behavior, find the first BehavioredClassifier reached by following the chain of owner relationships from the Behavior, if any. If there is such a BehavioredClassifier, then it is the context, unless it is itself a Behavior with a non-empty context, in which case that is also the context for the original Behavior. For example, following this algorithm, the context of an entry Behavior in a StateMachine is the BehavioredClassifier that owns the StateMachine. The features of the context BehavioredClassifier as well as the Elements visible to the context Classifier are visible to the Behavior.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual const std::shared_ptr<uml::BehavioredClassifier>& getContext() const ;
			/*!
			The BehavioredClassifier that is the context for the execution of the Behavior. A Behavior that is directly owned as a nestedClassifier does not have a context. Otherwise, to determine the context of a Behavior, find the first BehavioredClassifier reached by following the chain of owner relationships from the Behavior, if any. If there is such a BehavioredClassifier, then it is the context, unless it is itself a Behavior with a non-empty context, in which case that is also the context for the original Behavior. For example, following this algorithm, the context of an entry Behavior in a StateMachine is the BehavioredClassifier that owns the StateMachine. The features of the context BehavioredClassifier as well as the Elements visible to the context Classifier are visible to the Behavior.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual void setContext(const std::shared_ptr<uml::BehavioredClassifier>&) ;
			/*!
			References a list of Parameters to the Behavior which describes the order and type of arguments that can be given when the Behavior is invoked and of the values which will be returned when the Behavior completes its execution.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>>& getOwnedParameter() const ;
			/*!
			The ParameterSets owned by this Behavior.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>>& getOwnedParameterSet() const ;
			/*!
			An optional set of Constraints specifying what is fulfilled after the execution of the Behavior is completed, if its precondition was fulfilled before its invocation.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>>& getPostcondition() const ;
			/*!
			An optional set of Constraints specifying what must be fulfilled before the Behavior is invoked.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>>& getPrecondition() const ;
			/*!
			References the Behavior that this Behavior redefines. A subtype of Behavior may redefine any other subtype of Behavior. If the Behavior implements a BehavioralFeature, it replaces the redefined Behavior. If the Behavior is a classifierBehavior, it extends the redefined Behavior.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/>>& getRedefinedBehavior() const ;
			/*!
			Designates a BehavioralFeature that the Behavior implements. The BehavioralFeature must be owned by the BehavioredClassifier that owns the Behavior or be inherited by it. The Parameters of the BehavioralFeature and the implementing Behavior must match. A Behavior does not need to have a specification, in which case it either is the classifierBehavior of a BehavioredClassifier or it can only be invoked by another Behavior of the Classifier.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual const std::shared_ptr<uml::BehavioralFeature>& getSpecification() const ;
			/*!
			Designates a BehavioralFeature that the Behavior implements. The BehavioralFeature must be owned by the BehavioredClassifier that owns the Behavior or be inherited by it. The Parameters of the BehavioralFeature and the implementing Behavior must match. A Behavior does not need to have a specification, in which case it either is the classifierBehavior of a BehavioredClassifier or it can only be invoked by another Behavior of the Classifier.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual void setSpecification(const std::shared_ptr<uml::BehavioralFeature>&) ;
			
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
			std::weak_ptr<uml::Behavior> m_thisBehaviorPtr;
	};
}
#endif /* end of include guard: UML_BEHAVIORBEHAVIORIMPL_HPP */
