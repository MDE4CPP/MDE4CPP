//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITYPARAMETERNODEACTIVITYPARAMETERNODEIMPL_HPP
#define UML_ACTIVITYPARAMETERNODEACTIVITYPARAMETERNODEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ActivityParameterNode.hpp"

#include "uml/impl/ObjectNodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ActivityParameterNodeImpl : virtual public ObjectNodeImpl, virtual public ActivityParameterNode 
	{
		public: 
			ActivityParameterNodeImpl(const ActivityParameterNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ActivityParameterNodeImpl& operator=(ActivityParameterNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ActivityParameterNodeImpl();
			virtual std::shared_ptr<uml::ActivityParameterNode> getThisActivityParameterNodePtr() const;
			virtual void setThisActivityParameterNodePtr(std::weak_ptr<uml::ActivityParameterNode> thisActivityParameterNodePtr);

			//Additional constructors for the containments back reference
			ActivityParameterNodeImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ActivityParameterNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ActivityParameterNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ActivityParameterNodeImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ActivityParameterNodeImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The parameter of an ActivityParameterNode must be from the containing Activity.
			activity.ownedParameter->includes(parameter)
			*/
			 
			virtual bool has_parameters(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			An ActivityParameterNode may have all incoming ActivityEdges or all outgoing ActivityEdges, but it must not have both incoming and outgoing ActivityEdges.
			incoming->isEmpty() or outgoing->isEmpty()
			*/
			 
			virtual bool no_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			An ActivityParameterNode with no incoming ActivityEdges and one or more outgoing ActivityEdges must have a parameter with direction in or inout.
			(outgoing->notEmpty() and incoming->isEmpty()) implies 
				(parameter.direction = ParameterDirectionKind::_'in' or 
				 parameter.direction = ParameterDirectionKind::inout)
			*/
			 
			virtual bool no_incoming_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			An ActivityParameterNode with no outgoing ActivityEdges and one or more incoming ActivityEdges must have a parameter with direction out, inout, or return.
			(incoming->notEmpty() and outgoing->isEmpty()) implies 
				(parameter.direction = ParameterDirectionKind::out or 
				 parameter.direction = ParameterDirectionKind::inout or 
				 parameter.direction = ParameterDirectionKind::return)
			*/
			 
			virtual bool no_outgoing_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The type of an ActivityParameterNode is the same as the type of its parameter.
			type = parameter.type
			*/
			 
			virtual bool same_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Parameter for which the ActivityParameterNode will be accepting or providing values.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::Parameter> getParameter() const ;
			/*!
			The Parameter for which the ActivityParameterNode will be accepting or providing values.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setParameter(std::shared_ptr<uml::Parameter>) ;
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::ActivityParameterNode> m_thisActivityParameterNodePtr;
	};
}
#endif /* end of include guard: UML_ACTIVITYPARAMETERNODEACTIVITYPARAMETERNODEIMPL_HPP */
