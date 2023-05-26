//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OCCURRENCESPECIFICATIONOCCURRENCESPECIFICATIONIMPL_HPP
#define UML_OCCURRENCESPECIFICATIONOCCURRENCESPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../OccurrenceSpecification.hpp"

#include "uml/impl/InteractionFragmentImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API OccurrenceSpecificationImpl : virtual public InteractionFragmentImpl, virtual public OccurrenceSpecification 
	{
		public: 
			OccurrenceSpecificationImpl(const OccurrenceSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OccurrenceSpecificationImpl& operator=(OccurrenceSpecificationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			OccurrenceSpecificationImpl();
			virtual std::shared_ptr<uml::OccurrenceSpecification> getThisOccurrenceSpecificationPtr() const;
			virtual void setThisOccurrenceSpecificationPtr(std::weak_ptr<uml::OccurrenceSpecification> thisOccurrenceSpecificationPtr);

			//Additional constructors for the containments back reference
			OccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			OccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			OccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			OccurrenceSpecificationImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~OccurrenceSpecificationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			/*!
			Sets the Lifeline on which the OccurrenceSpecification appears.
			*/
			 
			virtual void setCovered(const std::shared_ptr<uml::Lifeline>& value) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			References the GeneralOrderings that specify EventOcurrences that must occur after this OccurrenceSpecification.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::GeneralOrdering>>& getToAfter() const ;
			/*!
			References the GeneralOrderings that specify EventOcurrences that must occur before this OccurrenceSpecification.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::GeneralOrdering>>& getToBefore() const ;
			
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
			std::weak_ptr<uml::OccurrenceSpecification> m_thisOccurrenceSpecificationPtr;
	};
}
#endif /* end of include guard: UML_OCCURRENCESPECIFICATIONOCCURRENCESPECIFICATIONIMPL_HPP */
