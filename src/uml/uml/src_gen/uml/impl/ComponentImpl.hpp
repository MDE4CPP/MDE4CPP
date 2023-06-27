//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COMPONENTCOMPONENTIMPL_HPP
#define UML_COMPONENTCOMPONENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Component.hpp"

#include "uml/impl/ClassImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ComponentImpl : virtual public ClassImpl, virtual public Component 
	{
		public: 
			ComponentImpl(const ComponentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ComponentImpl& operator=(ComponentImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ComponentImpl();
			virtual std::shared_ptr<uml::Component> getThisComponentPtr() const;
			virtual void setThisComponentPtr(std::weak_ptr<uml::Component> thisComponentPtr);

			//Additional constructors for the containments back reference
			ComponentImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ComponentImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ComponentImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			ComponentImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~ComponentImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Creates a(n) (abstract) class with the specified name as a packaged element of this component.
			*/
			 
			virtual std::shared_ptr<uml::Class> createOwnedClass(std::string name, bool isAbstract) ;
			/*!
			Creates a enumeration with the specified name as a packaged element of this component.
			*/
			 
			virtual std::shared_ptr<uml::Enumeration> createOwnedEnumeration(std::string name) ;
			/*!
			Creates an interface with the specified name as a packaged element of this component.
			*/
			 
			virtual std::shared_ptr<uml::Interface> createOwnedInterface(std::string name) ;
			/*!
			Creates a primitive type with the specified name as a packaged element of this component.
			*/
			 
			virtual std::shared_ptr<uml::PrimitiveType> createOwnedPrimitiveType(std::string name) ;
			/*!
			Derivation for Component::/provided
			result = (let 	ris : Set(Interface) = allRealizedInterfaces(),
			        realizingClassifiers : Set(Classifier) =  self.realization.realizingClassifier->union(self.allParents()->collect(realization.realizingClassifier))->asSet(),
			        allRealizingClassifiers : Set(Classifier) = realizingClassifiers->union(realizingClassifiers.allParents())->asSet(),
			        realizingClassifierInterfaces : Set(Interface) = allRealizingClassifiers->iterate(c; rci : Set(Interface) = Set{} | rci->union(c.allRealizedInterfaces())),
			        ports : Set(Port) = self.ownedPort->union(allParents()->collect(ownedPort))->asSet(),
			        providedByPorts : Set(Interface) = ports.provided->asSet()
			in     ris->union(realizingClassifierInterfaces) ->union(providedByPorts)->asSet())
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Interface>> getProvideds() ;
			/*!
			Derivation for Component::/required
			result = (let 	uis : Set(Interface) = allUsedInterfaces(),
			        realizingClassifiers : Set(Classifier) = self.realization.realizingClassifier->union(self.allParents()->collect(realization.realizingClassifier))->asSet(),
			        allRealizingClassifiers : Set(Classifier) = realizingClassifiers->union(realizingClassifiers.allParents())->asSet(),
			        realizingClassifierInterfaces : Set(Interface) = allRealizingClassifiers->iterate(c; rci : Set(Interface) = Set{} | rci->union(c.allUsedInterfaces())),
			        ports : Set(Port) = self.ownedPort->union(allParents()->collect(ownedPort))->asSet(),
			        usedByPorts : Set(Interface) = ports.required->asSet()
			in	    uis->union(realizingClassifierInterfaces)->union(usedByPorts)->asSet()
			)
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Interface>> getRequireds() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			If true, the Component is defined at design-time, but at run-time (or execution-time) an object specified by the Component does not exist, that is, the Component is instantiated indirectly, through the instantiation of its realizing Classifiers or parts.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual bool getIsIndirectlyInstantiated() const ;
			/*!
			If true, the Component is defined at design-time, but at run-time (or execution-time) an object specified by the Component does not exist, that is, the Component is instantiated indirectly, through the instantiation of its realizing Classifiers or parts.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual void setIsIndirectlyInstantiated (bool _isIndirectlyInstantiated);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The set of PackageableElements that a Component owns. In the namespace of a Component, all model elements that are involved in or related to its definition may be owned or imported explicitly. These may include e.g., Classes, Interfaces, Components, Packages, UseCases, Dependencies (e.g., mappings), and Artifacts.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>>& getPackagedElement() const ;
			/*!
			The Interfaces that the Component exposes to its environment. These Interfaces may be Realized by the Component or any of its realizingClassifiers, or they may be the Interfaces that are provided by its public Ports.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Interface>>& getProvided() const ;
			/*!
			The set of Realizations owned by the Component. Realizations reference the Classifiers of which the Component is an abstraction; i.e., that realize its behavior.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::ComponentRealization, uml::Element>>& getRealization() const ;
			/*!
			The Interfaces that the Component requires from other Components in its environment in order to be able to offer its full set of provided functionality. These Interfaces may be used by the Component or any of its realizingClassifiers, or they may be the Interfaces that are required by its public Ports.
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
			std::weak_ptr<uml::Component> m_thisComponentPtr;
	};
}
#endif /* end of include guard: UML_COMPONENTCOMPONENTIMPL_HPP */
