//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITYNODEACTIVITYNODEIMPL_HPP
#define UML_ACTIVITYNODEACTIVITYNODEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ActivityNode.hpp"

#include "uml/impl/RedefinableElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ActivityNodeImpl : virtual public RedefinableElementImpl, virtual public ActivityNode 
	{
		public: 
			ActivityNodeImpl(const ActivityNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			ActivityNodeImpl& operator=(ActivityNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ActivityNodeImpl();
			virtual std::shared_ptr<uml::ActivityNode> getThisActivityNodePtr() const;
			virtual void setThisActivityNodePtr(std::weak_ptr<uml::ActivityNode> thisActivityNodePtr);

			//Additional constructors for the containments back reference
			ActivityNodeImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ActivityNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ActivityNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ActivityNodeImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ActivityNodeImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The Activity that directly or indirectly contains this ActivityNode.
			result = (if inStructuredNode<>null then inStructuredNode.containingActivity()
			else activity
			endif)
			<p>From package UML::Activities.</p>
			*/
			 
			virtual std::shared_ptr<uml::Activity> containingActivity() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Activity containing the ActivityNode, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::Activity> getActivity() const ;
			/*!
			The Activity containing the ActivityNode, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setActivity(std::weak_ptr<uml::Activity>) ;
			
			/*!
			InterruptibleActivityRegions containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup>> getInInterruptibleRegion() const ;
			/*!
			ActivityPartitions containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> getInPartition() const ;
			/*!
			The StructuredActivityNode containing the ActvityNode, if it is directly owned by a StructuredActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::StructuredActivityNode> getInStructuredNode() const ;
			/*!
			The StructuredActivityNode containing the ActvityNode, if it is directly owned by a StructuredActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setInStructuredNode(std::weak_ptr<uml::StructuredActivityNode>) ;
			/*!
			ActivityEdges that have the ActivityNode as their target.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ActivityEdge>> getIncoming() const ;
			/*!
			ActivityEdges that have the ActivityNode as their source.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ActivityEdge>> getOutgoing() const ;
			/*!
			ActivityNodes from a generalization of the Activity containining this ActivityNode that are redefined by this ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement>> getRedefinedNode() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;
			
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
			std::weak_ptr<uml::ActivityNode> m_thisActivityNodePtr;
	};
}
#endif /* end of include guard: UML_ACTIVITYNODEACTIVITYNODEIMPL_HPP */
