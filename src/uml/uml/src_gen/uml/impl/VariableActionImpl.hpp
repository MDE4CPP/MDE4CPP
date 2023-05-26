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
			
			virtual void setVariable(const std::shared_ptr<uml::Variable>&) ;
			
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
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::VariableAction> m_thisVariableActionPtr;
	};
}
#endif /* end of include guard: UML_VARIABLEACTIONVARIABLEACTIONIMPL_HPP */
