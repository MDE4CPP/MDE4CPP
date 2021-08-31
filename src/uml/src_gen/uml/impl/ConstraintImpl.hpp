//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONSTRAINTCONSTRAINTIMPL_HPP
#define UML_CONSTRAINTCONSTRAINTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Constraint.hpp"

#include "uml/impl/PackageableElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ConstraintImpl : virtual public PackageableElementImpl, virtual public Constraint 
	{
		public: 
			ConstraintImpl(const ConstraintImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ConstraintImpl& operator=(ConstraintImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ConstraintImpl();
			virtual std::shared_ptr<Constraint> getThisConstraintPtr() const;
			virtual void setThisConstraintPtr(std::weak_ptr<Constraint> thisConstraintPtr);

			//Additional constructors for the containments back reference
			ConstraintImpl(std::weak_ptr<uml::Namespace> par_Namespace, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			ConstraintImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ConstraintImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			ConstraintImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~ConstraintImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The ValueSpecification for a Constraint must evaluate to a Boolean value.
			*/
			 
			virtual bool boolean_value(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			Evaluating the ValueSpecification for a Constraint must not have side effects.
			*/
			 
			virtual bool no_side_effects(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			A Constraint cannot be applied to itself.
			not constrainedElement->includes(self)
			*/
			 
			virtual bool not_apply_to_self(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The ordered set of Elements referenced by this Constraint.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Element>> getConstrainedElement() const ;
			
			/*!
			Specifies the Namespace that owns the Constraint.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getContext() const ;
			/*!
			Specifies the Namespace that owns the Constraint.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setContext(std::weak_ptr<uml::Namespace>) ;
			/*!
			A condition that must be true when evaluated in order for the Constraint to be satisfied.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getSpecification() const ;
			/*!
			A condition that must be true when evaluated in order for the Constraint to be satisfied.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setSpecification(std::shared_ptr<uml::ValueSpecification>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			

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
			std::weak_ptr<Constraint> m_thisConstraintPtr;
	};
}
#endif /* end of include guard: UML_CONSTRAINTCONSTRAINTIMPL_HPP */
