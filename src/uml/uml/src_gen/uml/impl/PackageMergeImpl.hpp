//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PACKAGEMERGEPACKAGEMERGEIMPL_HPP
#define UML_PACKAGEMERGEPACKAGEMERGEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../PackageMerge.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API PackageMergeImpl : virtual public DirectedRelationshipImpl, virtual public PackageMerge 
	{
		public: 
			PackageMergeImpl(const PackageMergeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			PackageMergeImpl& operator=(PackageMergeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			PackageMergeImpl();
			virtual std::shared_ptr<uml::PackageMerge> getThisPackageMergePtr() const;
			virtual void setThisPackageMergePtr(std::weak_ptr<uml::PackageMerge> thisPackageMergePtr);

			//Additional constructors for the containments back reference
			PackageMergeImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			PackageMergeImpl(std::weak_ptr<uml::Package> par_receivingPackage);

		public:
			//destructor
			virtual ~PackageMergeImpl();
			
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
			References the Package that is to be merged with the receiving package of the PackageMerge.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<uml::Package> getMergedPackage() const ;
			/*!
			References the Package that is to be merged with the receiving package of the PackageMerge.
			<p>From package UML::Packages.</p>
			*/
			
			virtual void setMergedPackage(std::shared_ptr<uml::Package>) ;
			/*!
			References the Package that is being extended with the contents of the merged package of the PackageMerge.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::weak_ptr<uml::Package> getReceivingPackage() const ;
			/*!
			References the Package that is being extended with the contents of the merged package of the PackageMerge.
			<p>From package UML::Packages.</p>
			*/
			
			virtual void setReceivingPackage(std::weak_ptr<uml::Package>) ;
			
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
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::PackageMerge> m_thisPackageMergePtr;
	};
}
#endif /* end of include guard: UML_PACKAGEMERGEPACKAGEMERGEIMPL_HPP */
