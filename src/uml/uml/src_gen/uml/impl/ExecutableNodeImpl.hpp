//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXECUTABLENODEEXECUTABLENODEIMPL_HPP
#define UML_EXECUTABLENODEEXECUTABLENODEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ExecutableNode.hpp"

#include "uml/impl/ActivityNodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ExecutableNodeImpl : virtual public ActivityNodeImpl, virtual public ExecutableNode 
	{
		public: 
			ExecutableNodeImpl(const ExecutableNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			ExecutableNodeImpl& operator=(ExecutableNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ExecutableNodeImpl();
			virtual std::shared_ptr<uml::ExecutableNode> getThisExecutableNodePtr() const;
			virtual void setThisExecutableNodePtr(std::weak_ptr<uml::ExecutableNode> thisExecutableNodePtr);

			//Additional constructors for the containments back reference
			ExecutableNodeImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ExecutableNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ExecutableNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ExecutableNodeImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ExecutableNodeImpl() = 0;
			
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
			A set of ExceptionHandlers that are examined if an exception propagates out of the ExceptionNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ExceptionHandler, uml::Element>> getHandler() const ;
			
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
			std::weak_ptr<uml::ExecutableNode> m_thisExecutableNodePtr;
	};
}
#endif /* end of include guard: UML_EXECUTABLENODEEXECUTABLENODEIMPL_HPP */
