//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PARAMETERSETPARAMETERSETIMPL_HPP
#define UML_PARAMETERSETPARAMETERSETIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ParameterSet.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ParameterSetImpl : virtual public NamedElementImpl, virtual public ParameterSet 
	{
		public: 
			ParameterSetImpl(const ParameterSetImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ParameterSetImpl& operator=(ParameterSetImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ParameterSetImpl();
			virtual std::shared_ptr<uml::ParameterSet> getThisParameterSetPtr() const;
			virtual void setThisParameterSetPtr(std::weak_ptr<uml::ParameterSet> thisParameterSetPtr);

			//Additional constructors for the containments back reference
			ParameterSetImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ParameterSetImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ParameterSetImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			If a parameterized entity has input Parameters that are in a ParameterSet, then any inputs that are not in a ParameterSet must be streaming. Same for output Parameters.
			((parameter->exists(direction = ParameterDirectionKind::_'in')) implies 
			    behavioralFeature.ownedParameter->select(p | p.direction = ParameterDirectionKind::_'in' and p.parameterSet->isEmpty())->forAll(isStream))
			    and
			((parameter->exists(direction = ParameterDirectionKind::out)) implies 
			    behavioralFeature.ownedParameter->select(p | p.direction = ParameterDirectionKind::out and p.parameterSet->isEmpty())->forAll(isStream))
			*/
			 
			virtual bool input(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The Parameters in a ParameterSet must all be inputs or all be outputs of the same parameterized entity, and the ParameterSet is owned by that entity.
			parameter->forAll(p1, p2 | self.owner = p1.owner and self.owner = p2.owner and p1.direction = p2.direction)
			*/
			 
			virtual bool same_parameterized_entity(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			Two ParameterSets cannot have exactly the same set of Parameters.
			parameter->forAll(parameterSet->forAll(s1, s2 | s1->size() = s2->size() implies s1.parameter->exists(p | not s2.parameter->includes(p))))
			*/
			 
			virtual bool two_parameter_sets(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A constraint that should be satisfied for the owner of the Parameters in an input ParameterSet to start execution using the values provided for those Parameters, or the owner of the Parameters in an output ParameterSet to end execution providing the values for those Parameters, if all preconditions and conditions on input ParameterSets were satisfied.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Constraint, uml::Element>> getCondition() const ;
			/*!
			Parameters in the ParameterSet.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Parameter>> getParameter() const ;
			
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
			std::weak_ptr<uml::ParameterSet> m_thisParameterSetPtr;
	};
}
#endif /* end of include guard: UML_PARAMETERSETPARAMETERSETIMPL_HPP */
