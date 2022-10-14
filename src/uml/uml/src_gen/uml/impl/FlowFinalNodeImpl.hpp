//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_FLOWFINALNODEFLOWFINALNODEIMPL_HPP
#define UML_FLOWFINALNODEFLOWFINALNODEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../FlowFinalNode.hpp"

#include "uml/impl/FinalNodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API FlowFinalNodeImpl : virtual public FinalNodeImpl, virtual public FlowFinalNode 
	{
		public: 
			FlowFinalNodeImpl(const FlowFinalNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			FlowFinalNodeImpl& operator=(FlowFinalNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			FlowFinalNodeImpl();
			virtual std::shared_ptr<uml::FlowFinalNode> getThisFlowFinalNodePtr() const;
			virtual void setThisFlowFinalNodePtr(std::weak_ptr<uml::FlowFinalNode> thisFlowFinalNodePtr);

			//Additional constructors for the containments back reference
			FlowFinalNodeImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			FlowFinalNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			FlowFinalNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			FlowFinalNodeImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~FlowFinalNodeImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

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
			std::weak_ptr<uml::FlowFinalNode> m_thisFlowFinalNodePtr;
	};
}
#endif /* end of include guard: UML_FLOWFINALNODEFLOWFINALNODEIMPL_HPP */
