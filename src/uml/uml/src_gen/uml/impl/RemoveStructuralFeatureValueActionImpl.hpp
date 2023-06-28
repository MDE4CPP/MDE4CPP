//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REMOVESTRUCTURALFEATUREVALUEACTIONREMOVESTRUCTURALFEATUREVALUEACTIONIMPL_HPP
#define UML_REMOVESTRUCTURALFEATUREVALUEACTIONREMOVESTRUCTURALFEATUREVALUEACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../RemoveStructuralFeatureValueAction.hpp"

#include "uml/impl/WriteStructuralFeatureActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API RemoveStructuralFeatureValueActionImpl : virtual public WriteStructuralFeatureActionImpl, virtual public RemoveStructuralFeatureValueAction 
	{
		public: 
			RemoveStructuralFeatureValueActionImpl(const RemoveStructuralFeatureValueActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			RemoveStructuralFeatureValueActionImpl& operator=(RemoveStructuralFeatureValueActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			RemoveStructuralFeatureValueActionImpl();
			virtual std::shared_ptr<uml::RemoveStructuralFeatureValueAction> getThisRemoveStructuralFeatureValueActionPtr() const;
			virtual void setThisRemoveStructuralFeatureValueActionPtr(std::weak_ptr<uml::RemoveStructuralFeatureValueAction> thisRemoveStructuralFeatureValueActionPtr);

			//Additional constructors for the containments back reference
			RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~RemoveStructuralFeatureValueActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether to remove duplicates of the value in nonunique StructuralFeatures.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsRemoveDuplicates() const ;
			/*!
			Specifies whether to remove duplicates of the value in nonunique StructuralFeatures.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsRemoveDuplicates (bool _isRemoveDuplicates);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			An InputPin that provides the position of an existing value to remove in ordered, nonunique structural features. The type of the removeAt InputPin is UnlimitedNatural, but the value cannot be zero or unlimited.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getRemoveAt() const ;
			/*!
			An InputPin that provides the position of an existing value to remove in ordered, nonunique structural features. The type of the removeAt InputPin is UnlimitedNatural, but the value cannot be zero or unlimited.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setRemoveAt(const std::shared_ptr<uml::InputPin>&) ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

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
			std::weak_ptr<uml::RemoveStructuralFeatureValueAction> m_thisRemoveStructuralFeatureValueActionPtr;
	};
}
#endif /* end of include guard: UML_REMOVESTRUCTURALFEATUREVALUEACTIONREMOVESTRUCTURALFEATUREVALUEACTIONIMPL_HPP */
