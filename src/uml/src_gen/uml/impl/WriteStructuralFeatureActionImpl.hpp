//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_WRITESTRUCTURALFEATUREACTIONWRITESTRUCTURALFEATUREACTIONIMPL_HPP
#define UML_WRITESTRUCTURALFEATUREACTIONWRITESTRUCTURALFEATUREACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../WriteStructuralFeatureAction.hpp"

#include "uml/impl/StructuralFeatureActionImpl.hpp"

//*********************************
namespace uml 
{
	class WriteStructuralFeatureActionImpl : virtual public StructuralFeatureActionImpl, virtual public WriteStructuralFeatureAction 
	{
		public: 
			WriteStructuralFeatureActionImpl(const WriteStructuralFeatureActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			WriteStructuralFeatureActionImpl& operator=(WriteStructuralFeatureActionImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			WriteStructuralFeatureActionImpl();
			virtual std::shared_ptr<WriteStructuralFeatureAction> getThisWriteStructuralFeatureActionPtr() const;
			virtual void setThisWriteStructuralFeatureActionPtr(std::weak_ptr<WriteStructuralFeatureAction> thisWriteStructuralFeatureActionPtr);

			//Additional constructors for the containments back reference
			WriteStructuralFeatureActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			WriteStructuralFeatureActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			WriteStructuralFeatureActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			WriteStructuralFeatureActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~WriteStructuralFeatureActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The multiplicity of the result OutputPin must be 1..1.
			result <> null implies result.is(1,1)
			*/
			 
			virtual bool multiplicity_of_result(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			The multiplicity of the value InputPin is 1..1.
			value<>null implies value.is(1,1)
			*/
			 
			virtual bool multiplicity_of_value(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			The type of the result OutputPin is the same as the type of the inherited object InputPin.
			result <> null implies result.type = object.type
			*/
			 
			virtual bool type_of_result(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			The type of the value InputPin must conform to the type of the structuralFeature.
			value <> null implies value.type.conformsTo(structuralFeature.type)
			*/
			 
			virtual bool type_of_value(Any diagnostics,std::map <   Any, Any >  context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The OutputPin on which is put the input object as modified by the WriteStructuralFeatureAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin > getResult() const ;
			
			/*!
			The OutputPin on which is put the input object as modified by the WriteStructuralFeatureAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin> _result) ;
			
			/*!
			The InputPin that provides the value to be added or removed from the StructuralFeature.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin > getValue() const ;
			
			/*!
			The InputPin that provides the value to be added or removed from the StructuralFeature.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(std::shared_ptr<uml::InputPin> _value) ;
			
							
			
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
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;/*!
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
			std::weak_ptr<WriteStructuralFeatureAction> m_thisWriteStructuralFeatureActionPtr;
	};
}
#endif /* end of include guard: UML_WRITESTRUCTURALFEATUREACTIONWRITESTRUCTURALFEATUREACTIONIMPL_HPP */
