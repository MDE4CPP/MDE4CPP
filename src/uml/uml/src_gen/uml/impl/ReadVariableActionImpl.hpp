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
			std::weak_ptr<uml::ReadVariableAction> m_thisReadVariableActionPtr;
	};
}
#endif /* end of include guard: UML_READVARIABLEACTIONREADVARIABLEACTIONIMPL_HPP */
