//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INFORMATIONFLOWINFORMATIONFLOWIMPL_HPP
#define UML_INFORMATIONFLOWINFORMATIONFLOWIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InformationFlow.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"
#include "uml/impl/PackageableElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InformationFlowImpl : virtual public DirectedRelationshipImpl, virtual public PackageableElementImpl, virtual public InformationFlow 
	{
		public: 
			InformationFlowImpl(const InformationFlowImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InformationFlowImpl& operator=(InformationFlowImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InformationFlowImpl();
			virtual std::shared_ptr<uml::InformationFlow> getThisInformationFlowPtr() const;
			virtual void setThisInformationFlowPtr(std::weak_ptr<uml::InformationFlow> thisInformationFlowPtr);

			//Additional constructors for the containments back reference
			InformationFlowImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InformationFlowImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			InformationFlowImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			InformationFlowImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~InformationFlowImpl();
			
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
			Specifies the information items that may circulate on this information flow.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Classifier>>& getConveyed() const ;
			/*!
			Defines from which source the conveyed InformationItems are initiated.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::NamedElement, uml::Element>>& getInformationSource() const ;
			/*!
			Defines to which target the conveyed InformationItems are directed.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::NamedElement, uml::Element>>& getInformationTarget() const ;
			/*!
			Determines which Relationship will realize the specified flow.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Relationship>>& getRealization() const ;
			/*!
			Determines which ActivityEdges will realize the specified flow.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::ActivityEdge>>& getRealizingActivityEdge() const ;
			/*!
			Determines which Connectors will realize the specified flow.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Connector>>& getRealizingConnector() const ;
			/*!
			Determines which Messages will realize the specified flow.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Message>>& getRealizingMessage() const ;
			
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
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

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
			std::weak_ptr<uml::InformationFlow> m_thisInformationFlowPtr;
	};
}
#endif /* end of include guard: UML_INFORMATIONFLOWINFORMATIONFLOWIMPL_HPP */
