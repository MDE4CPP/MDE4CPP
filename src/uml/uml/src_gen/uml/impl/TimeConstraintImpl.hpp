//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TIMECONSTRAINTTIMECONSTRAINTIMPL_HPP
#define UML_TIMECONSTRAINTTIMECONSTRAINTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../TimeConstraint.hpp"

#include "uml/impl/IntervalConstraintImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TimeConstraintImpl : virtual public IntervalConstraintImpl, virtual public TimeConstraint 
	{
		public: 
			TimeConstraintImpl(const TimeConstraintImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TimeConstraintImpl& operator=(TimeConstraintImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TimeConstraintImpl();
			virtual std::shared_ptr<uml::TimeConstraint> getThisTimeConstraintPtr() const;
			virtual void setThisTimeConstraintPtr(std::weak_ptr<uml::TimeConstraint> thisTimeConstraintPtr);

			//Additional constructors for the containments back reference
			TimeConstraintImpl(std::weak_ptr<uml::Namespace> par_Namespace, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			TimeConstraintImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			TimeConstraintImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			TimeConstraintImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~TimeConstraintImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			A TimeConstraint has one constrainedElement.
			constrainedElement->size() = 1
			*/
			 
			virtual bool has_one_constrainedElement(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The value of firstEvent is related to the constrainedElement. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters the constrainedElement. If firstEvent is false, then the corresponding observation event is the last time instant the execution is within the constrainedElement.
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool getFirstEvent() const ;
			/*!
			The value of firstEvent is related to the constrainedElement. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters the constrainedElement. If firstEvent is false, then the corresponding observation event is the last time instant the execution is within the constrainedElement.
			<p>From package UML::Values.</p>
			*/
			 
			virtual void setFirstEvent (bool _firstEvent);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
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
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			
			
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
			std::weak_ptr<uml::TimeConstraint> m_thisTimeConstraintPtr;
	};
}
#endif /* end of include guard: UML_TIMECONSTRAINTTIMECONSTRAINTIMPL_HPP */
