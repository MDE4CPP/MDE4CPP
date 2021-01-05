//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKACTIONLINKACTIONIMPL_HPP
#define UML_LINKACTIONLINKACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../LinkAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class LinkActionImpl : virtual public ActionImpl, virtual public LinkAction 
	{
		public: 
			LinkActionImpl(const LinkActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			LinkActionImpl& operator=(LinkActionImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			LinkActionImpl();
			virtual std::shared_ptr<LinkAction> getThisLinkActionPtr() const;
			virtual void setThisLinkActionPtr(std::weak_ptr<LinkAction> thisLinkActionPtr);

			//Additional constructors for the containments back reference
			LinkActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			LinkActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			LinkActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			LinkActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~LinkActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Returns the Association acted on by this LinkAction.
			result = (endData->asSequence()->first().end.association)
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<uml::Association> association() ;
			
			/*!
			The ends of the endData must not be static.
			endData->forAll(not end.isStatic)
			*/
			 
			virtual bool not_static(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			The ends of the endData must all be from the same Association and include all and only the memberEnds of that association.
			endData.end = self.association().memberEnd->asBag()
			*/
			 
			virtual bool same_association(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			The inputValue InputPins is the same as the union of all the InputPins referenced by the endData.
			inputValue->asBag()=endData.allPins()
			*/
			 
			virtual bool same_pins(Any diagnostics,std::map <   Any, Any >  context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The LinkEndData identifying the values on the ends of the links acting on by this LinkAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::LinkEndData, uml::Element>> getEndData() const ;
			
			
			/*!
			InputPins used by the LinkEndData of the LinkAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> getInputValue() const ;
			
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ; 
			 
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
			std::weak_ptr<LinkAction> m_thisLinkActionPtr;
	};
}
#endif /* end of include guard: UML_LINKACTIONLINKACTIONIMPL_HPP */
