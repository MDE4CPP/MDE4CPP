//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CHANGEEVENTCHANGEEVENTIMPL_HPP
#define UML_CHANGEEVENTCHANGEEVENTIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ChangeEvent.hpp"

#include "uml/impl/EventImpl.hpp"

//*********************************
namespace uml 
{
	class ChangeEventImpl :virtual public EventImpl, virtual public ChangeEvent 
	{
		public: 
			ChangeEventImpl(const ChangeEventImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ChangeEventImpl& operator=(ChangeEventImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ChangeEventImpl();
			virtual std::shared_ptr<ChangeEvent> getThisChangeEventPtr() const;
			virtual void setThisChangeEventPtr(std::weak_ptr<ChangeEvent> thisChangeEventPtr);

			//Additional constructors for the containments back reference
			ChangeEventImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			ChangeEventImpl(std::weak_ptr<uml::Element > par_owner);


			//Additional constructors for the containments back reference
			ChangeEventImpl(std::weak_ptr<uml::Package > par_owningPackage);


			//Additional constructors for the containments back reference
			ChangeEventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);




		public:
			//destructor
			virtual ~ChangeEventImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 A Boolean-valued ValueSpecification that will result in a ChangeEvent whenever its value changes from false to true.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<uml::ValueSpecification > getChangeExpression() const ;
			
			/*!
			 A Boolean-valued ValueSpecification that will result in a ChangeEvent whenever its value changes from false to true.
			<p>From package UML::CommonBehavior.</p> */
			virtual void setChangeExpression(std::shared_ptr<uml::ValueSpecification> _changeExpression_changeExpression) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ChangeEvent> m_thisChangeEventPtr;
	};
}
#endif /* end of include guard: UML_CHANGEEVENTCHANGEEVENTIMPL_HPP */
