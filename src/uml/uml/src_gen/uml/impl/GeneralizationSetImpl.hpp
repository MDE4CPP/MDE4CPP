//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_GENERALIZATIONSETGENERALIZATIONSETIMPL_HPP
#define UML_GENERALIZATIONSETGENERALIZATIONSETIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../GeneralizationSet.hpp"

#include "uml/impl/PackageableElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API GeneralizationSetImpl : virtual public PackageableElementImpl, virtual public GeneralizationSet 
	{
		public: 
			GeneralizationSetImpl(const GeneralizationSetImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			GeneralizationSetImpl& operator=(GeneralizationSetImpl const&); 

		protected:
			friend class umlFactoryImpl;
			GeneralizationSetImpl();
			virtual std::shared_ptr<uml::GeneralizationSet> getThisGeneralizationSetPtr() const;
			virtual void setThisGeneralizationSetPtr(std::weak_ptr<uml::GeneralizationSet> thisGeneralizationSetPtr);

			//Additional constructors for the containments back reference
			GeneralizationSetImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			GeneralizationSetImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			GeneralizationSetImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			GeneralizationSetImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~GeneralizationSetImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates (via the associated Generalizations) whether or not the set of specific Classifiers are covering for a particular general classifier. When isCovering is true, every instance of a particular general Classifier is also an instance of at least one of its specific Classifiers for the GeneralizationSet. When isCovering is false, there are one or more instances of the particular general Classifier that are not instances of at least one of its specific Classifiers defined for the GeneralizationSet.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsCovering() const ;
			/*!
			Indicates (via the associated Generalizations) whether or not the set of specific Classifiers are covering for a particular general classifier. When isCovering is true, every instance of a particular general Classifier is also an instance of at least one of its specific Classifiers for the GeneralizationSet. When isCovering is false, there are one or more instances of the particular general Classifier that are not instances of at least one of its specific Classifiers defined for the GeneralizationSet.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsCovering (bool _isCovering);
			/*!
			Indicates whether or not the set of specific Classifiers in a Generalization relationship have instance in common. If isDisjoint is true, the specific Classifiers for a particular GeneralizationSet have no members in common; that is, their intersection is empty. If isDisjoint is false, the specific Classifiers in a particular GeneralizationSet have one or more members in common; that is, their intersection is not empty.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsDisjoint() const ;
			/*!
			Indicates whether or not the set of specific Classifiers in a Generalization relationship have instance in common. If isDisjoint is true, the specific Classifiers for a particular GeneralizationSet have no members in common; that is, their intersection is empty. If isDisjoint is false, the specific Classifiers in a particular GeneralizationSet have one or more members in common; that is, their intersection is not empty.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsDisjoint (bool _isDisjoint);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Designates the instances of Generalization that are members of this GeneralizationSet.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Generalization>>& getGeneralization() const ;
			/*!
			Designates the Classifier that is defined as the power type for the associated GeneralizationSet, if there is one.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<uml::Classifier>& getPowertype() const ;
			/*!
			Designates the Classifier that is defined as the power type for the associated GeneralizationSet, if there is one.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setPowertype(const std::shared_ptr<uml::Classifier>&) ;
			
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
			std::weak_ptr<uml::GeneralizationSet> m_thisGeneralizationSetPtr;
	};
}
#endif /* end of include guard: UML_GENERALIZATIONSETGENERALIZATIONSETIMPL_HPP */
