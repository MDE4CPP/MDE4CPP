//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_VARIABLEACTIONVARIABLEACTIONIMPL_HPP
#define UML_VARIABLEACTIONVARIABLEACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../VariableAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API VariableActionImpl : virtual public ActionImpl, virtual public VariableAction 
	{
		public: 
			VariableActionImpl(const VariableActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			VariableActionImpl& operator=(VariableActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			VariableActionImpl();
			virtual std::shared_ptr<uml::VariableAction> getThisVariableActionPtr() const;
			virtual void setThisVariableActionPtr(std::weak_ptr<uml::VariableAction> thisVariableActionPtr);

			//Additional constructors for the containments back reference
			VariableActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			VariableActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			VariableActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			VariableActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~VariableActionImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The VariableAction must be in the scope of the variable.
			variable.isAccessibleBy(self)
			*/
			 
			virtual bool scope_of_variable(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Variable to be read or written.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Variable> getVariable() const ;
			/*!
			The Variable to be read or written.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setVariable(std::shared_ptr<uml::Variable>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::VariableAction> m_thisVariableActionPtr;
	};
}
#endif /* end of include guard: UML_VARIABLEACTIONVARIABLEACTIONIMPL_HPP */
