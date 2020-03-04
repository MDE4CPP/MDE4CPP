//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRUCTURALFEATUREACTIONSTRUCTURALFEATUREACTIONIMPL_HPP
#define UML_STRUCTURALFEATUREACTIONSTRUCTURALFEATUREACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../StructuralFeatureAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class StructuralFeatureActionImpl :virtual public ActionImpl, virtual public StructuralFeatureAction 
	{
		public: 
			StructuralFeatureActionImpl(const StructuralFeatureActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			StructuralFeatureActionImpl& operator=(StructuralFeatureActionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			StructuralFeatureActionImpl();
			virtual std::shared_ptr<StructuralFeatureAction> getThisStructuralFeatureActionPtr() const;
			virtual void setThisStructuralFeatureActionPtr(std::weak_ptr<StructuralFeatureAction> thisStructuralFeatureActionPtr);

			//Additional constructors for the containments back reference
			StructuralFeatureActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			StructuralFeatureActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			StructuralFeatureActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			StructuralFeatureActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~StructuralFeatureActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The multiplicity of the object InputPin must be 1..1.
			object.is(1,1) */ 
			virtual bool multiplicity(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The structuralFeature must not be static.
			not structuralFeature.isStatic */ 
			virtual bool not_static(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The structuralFeature must either be an owned or inherited feature of the type of the object InputPin, or it must be an owned end of a binary Association whose opposite end had as a type to which the type of the object InputPin conforms.
			object.type.oclAsType(Classifier).allFeatures()->includes(structuralFeature) or
				object.type.conformsTo(structuralFeature.oclAsType(Property).opposite.type) */ 
			virtual bool object_type(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The structuralFeature must have exactly one featuringClassifier.
			structuralFeature.featuringClassifier->size() = 1 */ 
			virtual bool one_featuring_classifier(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The visibility of the structuralFeature must allow access from the object performing the ReadStructuralFeatureAction.
			structuralFeature.visibility = VisibilityKind::public or
			_'context'.allFeatures()->includes(structuralFeature) or
			structuralFeature.visibility=VisibilityKind::protected and
			_'context'.conformsTo(structuralFeature.oclAsType(Property).opposite.type.oclAsType(Classifier)) */ 
			virtual bool visibility(Any diagnostics,std::map <   Any, Any >  context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The InputPin from which the object whose StructuralFeature is to be read or written is obtained.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::InputPin > getObject() const ;
			
			/*!
			 The InputPin from which the object whose StructuralFeature is to be read or written is obtained.
			<p>From package UML::Actions.</p> */
			virtual void setObject(std::shared_ptr<uml::InputPin> _object_object) ;
			/*!
			 The StructuralFeature to be read or written.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::StructuralFeature > getStructuralFeature() const ;
			
			/*!
			 The StructuralFeature to be read or written.
			<p>From package UML::Actions.</p> */
			virtual void setStructuralFeature(std::shared_ptr<uml::StructuralFeature> _structuralFeature_structuralFeature) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
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
			std::weak_ptr<StructuralFeatureAction> m_thisStructuralFeatureActionPtr;
	};
}
#endif /* end of include guard: UML_STRUCTURALFEATUREACTIONSTRUCTURALFEATUREACTIONIMPL_HPP */
