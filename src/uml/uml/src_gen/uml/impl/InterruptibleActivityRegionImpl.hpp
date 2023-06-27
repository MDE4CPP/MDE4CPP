//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERRUPTIBLEACTIVITYREGIONINTERRUPTIBLEACTIVITYREGIONIMPL_HPP
#define UML_INTERRUPTIBLEACTIVITYREGIONINTERRUPTIBLEACTIVITYREGIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InterruptibleActivityRegion.hpp"

#include "uml/impl/ActivityGroupImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InterruptibleActivityRegionImpl : virtual public ActivityGroupImpl, virtual public InterruptibleActivityRegion 
	{
		public: 
			InterruptibleActivityRegionImpl(const InterruptibleActivityRegionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InterruptibleActivityRegionImpl& operator=(InterruptibleActivityRegionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InterruptibleActivityRegionImpl();
			virtual std::shared_ptr<uml::InterruptibleActivityRegion> getThisInterruptibleActivityRegionPtr() const;
			virtual void setThisInterruptibleActivityRegionPtr(std::weak_ptr<uml::InterruptibleActivityRegion> thisInterruptibleActivityRegionPtr);

			//Additional constructors for the containments back reference
			InterruptibleActivityRegionImpl(std::weak_ptr<uml::Activity> par_inActivity);
			//Additional constructors for the containments back reference
			InterruptibleActivityRegionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InterruptibleActivityRegionImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			InterruptibleActivityRegionImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup);

		public:
			//destructor
			virtual ~InterruptibleActivityRegionImpl();
			
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
			The ActivityEdges leaving the InterruptibleActivityRegion on which a traversing token will result in the termination of other tokens flowing in the InterruptibleActivityRegion.
			<p>From package UML::Activities.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::ActivityEdge>>& getInterruptingEdge() const ;
			/*!
			ActivityNodes immediately contained in the InterruptibleActivityRegion.
			<p>From package UML::Activities.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>>& getNode() const ;
			
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
			std::weak_ptr<uml::InterruptibleActivityRegion> m_thisInterruptibleActivityRegionPtr;
	};
}
#endif /* end of include guard: UML_INTERRUPTIBLEACTIVITYREGIONINTERRUPTIBLEACTIVITYREGIONIMPL_HPP */
