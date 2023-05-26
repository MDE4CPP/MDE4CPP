//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TIMEOBSERVATIONTIMEOBSERVATIONIMPL_HPP
#define UML_TIMEOBSERVATIONTIMEOBSERVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../TimeObservation.hpp"

#include "uml/impl/ObservationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TimeObservationImpl : virtual public ObservationImpl, virtual public TimeObservation 
	{
		public: 
			TimeObservationImpl(const TimeObservationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TimeObservationImpl& operator=(TimeObservationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TimeObservationImpl();
			virtual std::shared_ptr<uml::TimeObservation> getThisTimeObservationPtr() const;
			virtual void setThisTimeObservationPtr(std::weak_ptr<uml::TimeObservation> thisTimeObservationPtr);

			//Additional constructors for the containments back reference
			TimeObservationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			TimeObservationImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			TimeObservationImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			TimeObservationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~TimeObservationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The value of firstEvent is related to the event. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters the event Element. If firstEvent is false, then the corresponding observation event is the time instant the execution exits the event Element.
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool getFirstEvent() const ;
			/*!
			The value of firstEvent is related to the event. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters the event Element. If firstEvent is false, then the corresponding observation event is the time instant the execution exits the event Element.
			<p>From package UML::Values.</p>
			*/
			 
			virtual void setFirstEvent (bool _firstEvent);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The TimeObservation is determined by the entering or exiting of the event Element during execution.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::NamedElement> getEvent() const ;
			/*!
			The TimeObservation is determined by the entering or exiting of the event Element during execution.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setEvent(const std::shared_ptr<uml::NamedElement>&) ;
			
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
			std::weak_ptr<uml::TimeObservation> m_thisTimeObservationPtr;
	};
}
#endif /* end of include guard: UML_TIMEOBSERVATIONTIMEOBSERVATIONIMPL_HPP */
