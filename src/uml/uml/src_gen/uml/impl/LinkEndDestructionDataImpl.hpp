//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKENDDESTRUCTIONDATALINKENDDESTRUCTIONDATAIMPL_HPP
#define UML_LINKENDDESTRUCTIONDATALINKENDDESTRUCTIONDATAIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../LinkEndDestructionData.hpp"

#include "uml/impl/LinkEndDataImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API LinkEndDestructionDataImpl : virtual public LinkEndDataImpl, virtual public LinkEndDestructionData 
	{
		public: 
			LinkEndDestructionDataImpl(const LinkEndDestructionDataImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LinkEndDestructionDataImpl& operator=(LinkEndDestructionDataImpl const&); 

		protected:
			friend class umlFactoryImpl;
			LinkEndDestructionDataImpl();
			virtual std::shared_ptr<uml::LinkEndDestructionData> getThisLinkEndDestructionDataPtr() const;
			virtual void setThisLinkEndDestructionDataPtr(std::weak_ptr<uml::LinkEndDestructionData> thisLinkEndDestructionDataPtr);

			//Additional constructors for the containments back reference
			LinkEndDestructionDataImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~LinkEndDestructionDataImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether to destroy duplicates of the value in nonunique Association ends.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsDestroyDuplicates() const ;
			/*!
			Specifies whether to destroy duplicates of the value in nonunique Association ends.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsDestroyDuplicates (bool _isDestroyDuplicates);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The InputPin that provides the position of an existing link to be destroyed in an ordered, nonunique Association end. The type of the destroyAt InputPin is UnlimitedNatural, but the value cannot be zero or unlimited.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getDestroyAt() const ;
			/*!
			The InputPin that provides the position of an existing link to be destroyed in an ordered, nonunique Association end. The type of the destroyAt InputPin is UnlimitedNatural, but the value cannot be zero or unlimited.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setDestroyAt(const std::shared_ptr<uml::InputPin>&) ;
			
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
			std::weak_ptr<uml::LinkEndDestructionData> m_thisLinkEndDestructionDataPtr;
	};
}
#endif /* end of include guard: UML_LINKENDDESTRUCTIONDATALINKENDDESTRUCTIONDATAIMPL_HPP */
