//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SLOTSLOTIMPL_HPP
#define UML_SLOTSLOTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Slot.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API SlotImpl : virtual public ElementImpl, virtual public Slot 
	{
		public: 
			SlotImpl(const SlotImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SlotImpl& operator=(SlotImpl const&); 

		protected:
			friend class umlFactoryImpl;
			SlotImpl();
			virtual std::shared_ptr<uml::Slot> getThisSlotPtr() const;
			virtual void setThisSlotPtr(std::weak_ptr<uml::Slot> thisSlotPtr);

			//Additional constructors for the containments back reference
			SlotImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			SlotImpl(std::weak_ptr<uml::InstanceSpecification> par_owningInstance);

		public:
			//destructor
			virtual ~SlotImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The StructuralFeature that specifies the values that may be held by the Slot.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<uml::StructuralFeature> getDefiningFeature() const ;
			/*!
			The StructuralFeature that specifies the values that may be held by the Slot.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setDefiningFeature(std::shared_ptr<uml::StructuralFeature>) ;
			/*!
			The InstanceSpecification that owns this Slot.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::InstanceSpecification> getOwningInstance() const ;
			/*!
			The InstanceSpecification that owns this Slot.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setOwningInstance(std::weak_ptr<uml::InstanceSpecification>) ;
			/*!
			The value or values held by the Slot.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> getValue() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
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
			std::weak_ptr<uml::Slot> m_thisSlotPtr;
	};
}
#endif /* end of include guard: UML_SLOTSLOTIMPL_HPP */
