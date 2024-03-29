//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_READVARIABLEACTIONREADVARIABLEACTIONIMPL_HPP
#define UML_READVARIABLEACTIONREADVARIABLEACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ReadVariableAction.hpp"

#include "uml/impl/VariableActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ReadVariableActionImpl : virtual public VariableActionImpl, virtual public ReadVariableAction 
	{
		public: 
			ReadVariableActionImpl(const ReadVariableActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReadVariableActionImpl& operator=(ReadVariableActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ReadVariableActionImpl();
			virtual std::shared_ptr<uml::ReadVariableAction> getThisReadVariableActionPtr() const;
			virtual void setThisReadVariableActionPtr(std::weak_ptr<uml::ReadVariableAction> thisReadVariableActionPtr);

			//Additional constructors for the containments back reference
			ReadVariableActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ReadVariableActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ReadVariableActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ReadVariableActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ReadVariableActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The multiplicity of the variable must be compatible with the multiplicity of the output pin.
			variable.compatibleWith(result)
			*/
			 
			virtual bool compatible_multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The type and ordering of the result OutputPin are the same as the type and ordering of the variable.
			result.type =variable.type and 
			result.isOrdered = variable.isOrdered
			*/
			 
			virtual bool type_and_ordering(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The OutputPin on which the result values are placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getResult() const ;
			/*!
			The OutputPin on which the result values are placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;
			/*!
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;
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
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;
			
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
			std::weak_ptr<uml::ReadVariableAction> m_thisReadVariableActionPtr;
	};
}
#endif /* end of include guard: UML_READVARIABLEACTIONREADVARIABLEACTIONIMPL_HPP */
