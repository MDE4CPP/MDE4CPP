//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PORTPORTIMPL_HPP
#define UML_PORTPORTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Port.hpp"

#include "uml/impl/PropertyImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API PortImpl : virtual public PropertyImpl, virtual public Port 
	{
		public: 
			PortImpl(const PortImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			PortImpl& operator=(PortImpl const&); 

		protected:
			friend class umlFactoryImpl;
			PortImpl();
			virtual std::shared_ptr<uml::Port> getThisPortPtr() const;
			virtual void setThisPortPtr(std::weak_ptr<uml::Port> thisPortPtr);

			//Additional constructors for the containments back reference
			PortImpl(std::weak_ptr<uml::Property> par_associationEnd);
			//Additional constructors for the containments back reference
			PortImpl(std::weak_ptr<uml::Class> par_class);
			//Additional constructors for the containments back reference
			PortImpl(std::weak_ptr<uml::DataType> par_datatype);
			//Additional constructors for the containments back reference
			PortImpl(std::weak_ptr<uml::Interface> par_interface);
			//Additional constructors for the containments back reference
			PortImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			PortImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			PortImpl(std::weak_ptr<uml::Association> par_owningAssociation);
			//Additional constructors for the containments back reference
			PortImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~PortImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The union of the sets of Interfaces realized by the type of the Port and its supertypes, or directly the type of the Port if the Port is typed by an Interface.
			result = (if type.oclIsKindOf(Interface) 
			then type.oclAsType(Interface)->asSet() 
			else type.oclAsType(Classifier).allRealizedInterfaces() 
			endif)
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Interface>> basicProvided() ;
			/*!
			The union of the sets of Interfaces used by the type of the Port and its supertypes.
			result = ( type.oclAsType(Classifier).allUsedInterfaces() )
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Interface>> basicRequired() ;
			/*!
			Derivation for Port::/provided
			result = (if isConjugated then basicRequired() else basicProvided() endif)
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Interface>> getProvideds() ;
			/*!
			Derivation for Port::/required
			result = (if isConjugated then basicProvided() else basicRequired() endif)
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Interface>> getRequireds() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether requests arriving at this Port are sent to the classifier behavior of this EncapsulatedClassifier. Such a Port is referred to as a behavior Port. Any invocation of a BehavioralFeature targeted at a behavior Port will be handled by the instance of the owning EncapsulatedClassifier itself, rather than by any instances that it may contain.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual bool getIsBehavior() const ;
			/*!
			Specifies whether requests arriving at this Port are sent to the classifier behavior of this EncapsulatedClassifier. Such a Port is referred to as a behavior Port. Any invocation of a BehavioralFeature targeted at a behavior Port will be handled by the instance of the owning EncapsulatedClassifier itself, rather than by any instances that it may contain.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual void setIsBehavior (bool _isBehavior);
			/*!
			Specifies the way that the provided and required Interfaces are derived from the Port’s Type.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual bool getIsConjugated() const ;
			/*!
			Specifies the way that the provided and required Interfaces are derived from the Port’s Type.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual void setIsConjugated (bool _isConjugated);
			/*!
			If true, indicates that this Port is used to provide the published functionality of an EncapsulatedClassifier.  If false, this Port is used to implement the EncapsulatedClassifier but is not part of the essential externally-visible functionality of the EncapsulatedClassifier and can, therefore, be altered or deleted along with the internal implementation of the EncapsulatedClassifier and other properties that are considered part of its implementation.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual bool getIsService() const ;
			/*!
			If true, indicates that this Port is used to provide the published functionality of an EncapsulatedClassifier.  If false, this Port is used to implement the EncapsulatedClassifier but is not part of the essential externally-visible functionality of the EncapsulatedClassifier and can, therefore, be altered or deleted along with the internal implementation of the EncapsulatedClassifier and other properties that are considered part of its implementation.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual void setIsService (bool _isService);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			An optional ProtocolStateMachine which describes valid interactions at this interaction point.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<uml::ProtocolStateMachine>& getProtocol() const ;
			/*!
			An optional ProtocolStateMachine which describes valid interactions at this interaction point.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual void setProtocol(const std::shared_ptr<uml::ProtocolStateMachine>&) ;
			/*!
			The Interfaces specifying the set of Operations and Receptions that the EncapsulatedCclassifier offers to its environment via this Port, and which it will handle either directly or by forwarding it to a part of its internal structure. This association is derived according to the value of isConjugated. If isConjugated is false, provided is derived as the union of the sets of Interfaces realized by the type of the port and its supertypes, or directly from the type of the Port if the Port is typed by an Interface. If isConjugated is true, it is derived as the union of the sets of Interfaces used by the type of the Port and its supertypes.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Interface>>& getProvided() const ;
			/*!
			A Port may be redefined when its containing EncapsulatedClassifier is specialized. The redefining Port may have additional Interfaces to those that are associated with the redefined Port or it may replace an Interface by one of its subtypes.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>>& getRedefinedPort() const ;
			/*!
			The Interfaces specifying the set of Operations and Receptions that the EncapsulatedCassifier expects its environment to handle via this port. This association is derived according to the value of isConjugated. If isConjugated is false, required is derived as the union of the sets of Interfaces used by the type of the Port and its supertypes. If isConjugated is true, it is derived as the union of the sets of Interfaces realized by the type of the Port and its supertypes, or directly from the type of the Port if the Port is typed by an Interface.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Interface>>& getRequired() const ;
			
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
			std::weak_ptr<uml::Port> m_thisPortPtr;
	};
}
#endif /* end of include guard: UML_PORTPORTIMPL_HPP */
