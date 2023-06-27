//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ADDSTRUCTURALFEATUREVALUEACTIONADDSTRUCTURALFEATUREVALUEACTIONIMPL_HPP
#define UML_ADDSTRUCTURALFEATUREVALUEACTIONADDSTRUCTURALFEATUREVALUEACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../AddStructuralFeatureValueAction.hpp"

#include "uml/impl/WriteStructuralFeatureActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API AddStructuralFeatureValueActionImpl : virtual public WriteStructuralFeatureActionImpl, virtual public AddStructuralFeatureValueAction 
	{
		public: 
			AddStructuralFeatureValueActionImpl(const AddStructuralFeatureValueActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AddStructuralFeatureValueActionImpl& operator=(AddStructuralFeatureValueActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			AddStructuralFeatureValueActionImpl();
			virtual std::shared_ptr<uml::AddStructuralFeatureValueAction> getThisAddStructuralFeatureValueActionPtr() const;
			virtual void setThisAddStructuralFeatureValueActionPtr(std::weak_ptr<uml::AddStructuralFeatureValueAction> thisAddStructuralFeatureValueActionPtr);

			//Additional constructors for the containments back reference
			AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~AddStructuralFeatureValueActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether existing values of the StructuralFeature should be removed before adding the new value.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsReplaceAll() const ;
			/*!
			Specifies whether existing values of the StructuralFeature should be removed before adding the new value.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsReplaceAll (bool _isReplaceAll);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The InputPin that gives the position at which to insert the value in an ordered StructuralFeature. The type of the insertAt InputPin is UnlimitedNatural, but the value cannot be zero. It is omitted for unordered StructuralFeatures.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getInsertAt() const ;
			/*!
			The InputPin that gives the position at which to insert the value in an ordered StructuralFeature. The type of the insertAt InputPin is UnlimitedNatural, but the value cannot be zero. It is omitted for unordered StructuralFeatures.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setInsertAt(const std::shared_ptr<uml::InputPin>&) ;
			
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
			std::weak_ptr<uml::AddStructuralFeatureValueAction> m_thisAddStructuralFeatureValueActionPtr;
	};
}
#endif /* end of include guard: UML_ADDSTRUCTURALFEATUREVALUEACTIONADDSTRUCTURALFEATUREVALUEACTIONIMPL_HPP */
