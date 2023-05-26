//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXPANSIONREGIONEXPANSIONREGIONIMPL_HPP
#define UML_EXPANSIONREGIONEXPANSIONREGIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ExpansionRegion.hpp"

#include "uml/impl/StructuredActivityNodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ExpansionRegionImpl : virtual public StructuredActivityNodeImpl, virtual public ExpansionRegion 
	{
		public: 
			ExpansionRegionImpl(const ExpansionRegionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExpansionRegionImpl& operator=(ExpansionRegionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ExpansionRegionImpl();
			virtual std::shared_ptr<uml::ExpansionRegion> getThisExpansionRegionPtr() const;
			virtual void setThisExpansionRegionPtr(std::weak_ptr<uml::ExpansionRegion> thisExpansionRegionPtr);

			//Additional constructors for the containments back reference
			ExpansionRegionImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			ExpansionRegionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ExpansionRegionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ExpansionRegionImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ExpansionRegionImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup);

		public:
			//destructor
			virtual ~ExpansionRegionImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The mode in which the ExpansionRegion executes its contents. If parallel, executions are concurrent. If iterative, executions are sequential. If stream, a stream of values flows into a single execution.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual uml::ExpansionKind getMode() const ;
			/*!
			The mode in which the ExpansionRegion executes its contents. If parallel, executions are concurrent. If iterative, executions are sequential. If stream, a stream of values flows into a single execution.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setMode (uml::ExpansionKind _mode);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The ExpansionNodes that hold the input collections for the ExpansionRegion.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::ExpansionNode>>& getInputElement() const ;
			/*!
			The ExpansionNodes that form the output collections of the ExpansionRegion.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::ExpansionNode>>& getOutputElement() const ;
			
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
			std::weak_ptr<uml::ExpansionRegion> m_thisExpansionRegionPtr;
	};
}
#endif /* end of include guard: UML_EXPANSIONREGIONEXPANSIONREGIONIMPL_HPP */
