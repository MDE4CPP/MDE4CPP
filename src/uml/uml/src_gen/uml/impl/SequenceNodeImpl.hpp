//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SEQUENCENODESEQUENCENODEIMPL_HPP
#define UML_SEQUENCENODESEQUENCENODEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../SequenceNode.hpp"

#include "uml/impl/StructuredActivityNodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API SequenceNodeImpl : virtual public StructuredActivityNodeImpl, virtual public SequenceNode 
	{
		public: 
			SequenceNodeImpl(const SequenceNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SequenceNodeImpl& operator=(SequenceNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			SequenceNodeImpl();
			virtual std::shared_ptr<uml::SequenceNode> getThisSequenceNodePtr() const;
			virtual void setThisSequenceNodePtr(std::weak_ptr<uml::SequenceNode> thisSequenceNodePtr);

			//Additional constructors for the containments back reference
			SequenceNodeImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			SequenceNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			SequenceNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			SequenceNodeImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			SequenceNodeImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup);

		public:
			//destructor
			virtual ~SequenceNodeImpl();
			
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
			The ordered set of ExecutableNodes to be sequenced.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExecutableNode>> getExecutableNode() const ;
			
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
			std::weak_ptr<uml::SequenceNode> m_thisSequenceNodePtr;
	};
}
#endif /* end of include guard: UML_SEQUENCENODESEQUENCENODEIMPL_HPP */
