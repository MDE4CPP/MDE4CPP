//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CLEARASSOCIATIONACTIONCLEARASSOCIATIONACTIONIMPL_HPP
#define UML_CLEARASSOCIATIONACTIONCLEARASSOCIATIONACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ClearAssociationAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ClearAssociationActionImpl : virtual public ActionImpl, virtual public ClearAssociationAction 
	{
		public: 
			ClearAssociationActionImpl(const ClearAssociationActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ClearAssociationActionImpl& operator=(ClearAssociationActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ClearAssociationActionImpl();
			virtual std::shared_ptr<uml::ClearAssociationAction> getThisClearAssociationActionPtr() const;
			virtual void setThisClearAssociationActionPtr(std::weak_ptr<uml::ClearAssociationAction> thisClearAssociationActionPtr);

			//Additional constructors for the containments back reference
			ClearAssociationActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ClearAssociationActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ClearAssociationActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ClearAssociationActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ClearAssociationActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The multiplicity of the object InputPin is 1..1.
			object.is(1,1)
			*/
			 
			virtual bool multiplicity(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) ;
			/*!
			The type of the InputPin must conform to the type of at least one of the memberEnds of the association.
			association.memberEnd->exists(self.object.type.conformsTo(type))
			*/
			 
			virtual bool same_type(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Association to be cleared.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Association> getAssociation() const ;
			/*!
			The Association to be cleared.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setAssociation(std::shared_ptr<uml::Association>) ;
			/*!
			The InputPin that gives the object whose participation in the Association is to be cleared.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getObject() const ;
			/*!
			The InputPin that gives the object whose participation in the Association is to be cleared.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(std::shared_ptr<uml::InputPin>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;
			/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::ClearAssociationAction> m_thisClearAssociationActionPtr;
	};
}
#endif /* end of include guard: UML_CLEARASSOCIATIONACTIONCLEARASSOCIATIONACTIONIMPL_HPP */
