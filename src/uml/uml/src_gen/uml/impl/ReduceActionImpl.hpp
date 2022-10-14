//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REDUCEACTIONREDUCEACTIONIMPL_HPP
#define UML_REDUCEACTIONREDUCEACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ReduceAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ReduceActionImpl : virtual public ActionImpl, virtual public ReduceAction 
	{
		public: 
			ReduceActionImpl(const ReduceActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReduceActionImpl& operator=(ReduceActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ReduceActionImpl();
			virtual std::shared_ptr<uml::ReduceAction> getThisReduceActionPtr() const;
			virtual void setThisReduceActionPtr(std::weak_ptr<uml::ReduceAction> thisReduceActionPtr);

			//Additional constructors for the containments back reference
			ReduceActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ReduceActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ReduceActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ReduceActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ReduceActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The type of the collection InputPin must be a collection.
			*/
			 
			virtual bool input_type_is_collection(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The type of the output of the reducer Behavior must conform to the type of the result OutputPin.
			reducer.outputParameters().type->forAll(conformsTo(result.type))
			*/
			 
			virtual bool output_types_are_compatible(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The reducer Behavior must have two input ownedParameters and one output ownedParameter, where the type of the output Parameter and the type of elements of the input collection conform to the types of the input Parameters.
			let inputs: OrderedSet(Parameter) = reducer.inputParameters() in
			let outputs: OrderedSet(Parameter) = reducer.outputParameters() in
			inputs->size()=2 and outputs->size()=1 and
			inputs.type->forAll(t | 
				outputs.type->forAll(conformsTo(t)) and 
				-- Note that the following only checks the case when the collection is via multiple tokens.
				collection.upperBound()>1 implies collection.type.conformsTo(t))
			*/
			 
			virtual bool reducer_inputs_output(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates whether the order of the input collection should determine the order in which the reducer Behavior is applied to its elements.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsOrdered() const ;
			/*!
			Indicates whether the order of the input collection should determine the order in which the reducer Behavior is applied to its elements.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsOrdered (bool _isOrdered);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The InputPin that provides the collection to be reduced.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getCollection() const ;
			/*!
			The InputPin that provides the collection to be reduced.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setCollection(std::shared_ptr<uml::InputPin>) ;
			/*!
			A Behavior that is repreatedly applied to two elements of the input collection to produce a value that is of the same type as elements of the collection.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getReducer() const ;
			/*!
			A Behavior that is repreatedly applied to two elements of the input collection to produce a value that is of the same type as elements of the collection.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setReducer(std::shared_ptr<uml::Behavior>) ;
			/*!
			The output pin on which the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getResult() const ;
			/*!
			The output pin on which the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin>) ;
			
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
			std::weak_ptr<uml::ReduceAction> m_thisReduceActionPtr;
	};
}
#endif /* end of include guard: UML_REDUCEACTIONREDUCEACTIONIMPL_HPP */
