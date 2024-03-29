//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_WRITEVARIABLEACTIONWRITEVARIABLEACTIONIMPL_HPP
#define UML_WRITEVARIABLEACTIONWRITEVARIABLEACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../WriteVariableAction.hpp"

#include "uml/impl/VariableActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API WriteVariableActionImpl : virtual public VariableActionImpl, virtual public WriteVariableAction 
	{
		public: 
			WriteVariableActionImpl(const WriteVariableActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			WriteVariableActionImpl& operator=(WriteVariableActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			WriteVariableActionImpl();
			virtual std::shared_ptr<uml::WriteVariableAction> getThisWriteVariableActionPtr() const;
			virtual void setThisWriteVariableActionPtr(std::weak_ptr<uml::WriteVariableAction> thisWriteVariableActionPtr);

			//Additional constructors for the containments back reference
			WriteVariableActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			WriteVariableActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			WriteVariableActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			WriteVariableActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~WriteVariableActionImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The multiplicity of the value InputPin is 1..1.
			value<>null implies value.is(1,1)
			*/
			 
			virtual bool multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The type of the value InputPin must conform to the type of the variable.
			value <> null implies value.type.conformsTo(variable.type)
			*/
			 
			virtual bool value_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The InputPin that gives the value to be added or removed from the Variable.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getValue() const ;
			/*!
			The InputPin that gives the value to be added or removed from the Variable.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(std::shared_ptr<uml::InputPin>) ;
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::WriteVariableAction> m_thisWriteVariableActionPtr;
	};
}
#endif /* end of include guard: UML_WRITEVARIABLEACTIONWRITEVARIABLEACTIONIMPL_HPP */
