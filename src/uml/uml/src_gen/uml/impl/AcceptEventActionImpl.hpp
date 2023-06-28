//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACCEPTEVENTACTIONACCEPTEVENTACTIONIMPL_HPP
#define UML_ACCEPTEVENTACTIONACCEPTEVENTACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../AcceptEventAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API AcceptEventActionImpl : virtual public ActionImpl, virtual public AcceptEventAction 
	{
		public: 
			AcceptEventActionImpl(const AcceptEventActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AcceptEventActionImpl& operator=(AcceptEventActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			AcceptEventActionImpl();
			virtual std::shared_ptr<uml::AcceptEventAction> getThisAcceptEventActionPtr() const;
			virtual void setThisAcceptEventActionPtr(std::weak_ptr<uml::AcceptEventAction> thisAcceptEventActionPtr);

			//Additional constructors for the containments back reference
			AcceptEventActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			AcceptEventActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			AcceptEventActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			AcceptEventActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~AcceptEventActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates whether there is a single OutputPin for a SignalEvent occurrence, or multiple OutputPins for attribute values of the instance of the Signal associated with a SignalEvent occurrence.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsUnmarshall() const ;
			/*!
			Indicates whether there is a single OutputPin for a SignalEvent occurrence, or multiple OutputPins for attribute values of the instance of the Signal associated with a SignalEvent occurrence.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsUnmarshall (bool _isUnmarshall);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			OutputPins holding the values received from an Event occurrence.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>>& getResult() const ;
			/*!
			The Triggers specifying the Events of which the AcceptEventAction waits for occurrences.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Trigger, uml::Element>>& getTrigger() const ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
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
			std::weak_ptr<uml::AcceptEventAction> m_thisAcceptEventActionPtr;
	};
}
#endif /* end of include guard: UML_ACCEPTEVENTACTIONACCEPTEVENTACTIONIMPL_HPP */
