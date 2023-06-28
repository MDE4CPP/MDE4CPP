//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SUBSTITUTIONSUBSTITUTIONIMPL_HPP
#define UML_SUBSTITUTIONSUBSTITUTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Substitution.hpp"

#include "uml/impl/RealizationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API SubstitutionImpl : virtual public RealizationImpl, virtual public Substitution 
	{
		public: 
			SubstitutionImpl(const SubstitutionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SubstitutionImpl& operator=(SubstitutionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			SubstitutionImpl();
			virtual std::shared_ptr<uml::Substitution> getThisSubstitutionPtr() const;
			virtual void setThisSubstitutionPtr(std::weak_ptr<uml::Substitution> thisSubstitutionPtr);

			//Additional constructors for the containments back reference
			SubstitutionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			SubstitutionImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			SubstitutionImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			SubstitutionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			SubstitutionImpl(std::weak_ptr<uml::Classifier> par_substitutingClassifier);

		public:
			//destructor
			virtual ~SubstitutionImpl();
			
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
			The contract with which the substituting classifier complies.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<uml::Classifier>& getContract() const ;
			/*!
			The contract with which the substituting classifier complies.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setContract(const std::shared_ptr<uml::Classifier>&) ;
			/*!
			Instances of the substituting classifier are runtime substitutable where instances of the contract classifier are expected.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Classifier> getSubstitutingClassifier() const ;
			/*!
			Instances of the substituting classifier are runtime substitutable where instances of the contract classifier are expected.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setSubstitutingClassifier(std::weak_ptr<uml::Classifier>) ;
			
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
			std::weak_ptr<uml::Substitution> m_thisSubstitutionPtr;
	};
}
#endif /* end of include guard: UML_SUBSTITUTIONSUBSTITUTIONIMPL_HPP */
