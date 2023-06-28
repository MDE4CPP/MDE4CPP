//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKENDCREATIONDATALINKENDCREATIONDATAIMPL_HPP
#define UML_LINKENDCREATIONDATALINKENDCREATIONDATAIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../LinkEndCreationData.hpp"

#include "uml/impl/LinkEndDataImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API LinkEndCreationDataImpl : virtual public LinkEndDataImpl, virtual public LinkEndCreationData 
	{
		public: 
			LinkEndCreationDataImpl(const LinkEndCreationDataImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LinkEndCreationDataImpl& operator=(LinkEndCreationDataImpl const&); 

		protected:
			friend class umlFactoryImpl;
			LinkEndCreationDataImpl();
			virtual std::shared_ptr<uml::LinkEndCreationData> getThisLinkEndCreationDataPtr() const;
			virtual void setThisLinkEndCreationDataPtr(std::weak_ptr<uml::LinkEndCreationData> thisLinkEndCreationDataPtr);

			//Additional constructors for the containments back reference
			LinkEndCreationDataImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~LinkEndCreationDataImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether the existing links emanating from the object on this end should be destroyed before creating a new link.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsReplaceAll() const ;
			/*!
			Specifies whether the existing links emanating from the object on this end should be destroyed before creating a new link.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsReplaceAll (bool _isReplaceAll);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			For ordered Association ends, the InputPin that provides the position where the new link should be inserted or where an existing link should be moved to. The type of the insertAt InputPin is UnlimitedNatural, but the input cannot be zero. It is omitted for Association ends that are not ordered.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getInsertAt() const ;
			/*!
			For ordered Association ends, the InputPin that provides the position where the new link should be inserted or where an existing link should be moved to. The type of the insertAt InputPin is UnlimitedNatural, but the input cannot be zero. It is omitted for Association ends that are not ordered.
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
			std::weak_ptr<uml::LinkEndCreationData> m_thisLinkEndCreationDataPtr;
	};
}
#endif /* end of include guard: UML_LINKENDCREATIONDATALINKENDCREATIONDATAIMPL_HPP */
