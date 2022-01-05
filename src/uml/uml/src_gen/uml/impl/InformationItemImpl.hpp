//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INFORMATIONITEMINFORMATIONITEMIMPL_HPP
#define UML_INFORMATIONITEMINFORMATIONITEMIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InformationItem.hpp"

#include "uml/impl/ClassifierImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InformationItemImpl : virtual public ClassifierImpl, virtual public InformationItem 
	{
		public: 
			InformationItemImpl(const InformationItemImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InformationItemImpl& operator=(InformationItemImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InformationItemImpl();
			virtual std::shared_ptr<uml::InformationItem> getThisInformationItemPtr() const;
			virtual void setThisInformationItemPtr(std::weak_ptr<uml::InformationItem> thisInformationItemPtr);

			//Additional constructors for the containments back reference
			InformationItemImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InformationItemImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			InformationItemImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			InformationItemImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~InformationItemImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			An informationItem has no feature, no generalization, and no associations.
			self.generalization->isEmpty() and self.feature->isEmpty()
			*/
			 
			virtual bool has_no(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			It is not instantiable.
			isAbstract
			*/
			 
			virtual bool not_instantiable(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The sources and targets of an information item (its related information flows) must designate subsets of the sources and targets of the representation information item, if any. The Classifiers that can realize an information item can only be of the following kind: Class, Interface, InformationItem, Signal, Component.
			(self.represented->select(oclIsKindOf(InformationItem))->forAll(p |
			  p.conveyingFlow.source->forAll(q | self.conveyingFlow.source->includes(q)) and
			    p.conveyingFlow.target->forAll(q | self.conveyingFlow.target->includes(q)))) and
			      (self.represented->forAll(oclIsKindOf(Class) or oclIsKindOf(Interface) or
			        oclIsKindOf(InformationItem) or oclIsKindOf(Signal) or oclIsKindOf(Component)))
			*/
			 
			virtual bool sources_and_targets(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Determines the classifiers that will specify the structure and nature of the information. An information item represents all its represented classifiers.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getRepresented() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const ;
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const ;
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
			std::weak_ptr<uml::InformationItem> m_thisInformationItemPtr;
	};
}
#endif /* end of include guard: UML_INFORMATIONITEMINFORMATIONITEMIMPL_HPP */