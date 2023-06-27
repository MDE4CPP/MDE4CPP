//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_GENERALIZATIONSET_HPP
#define UML_GENERALIZATIONSET_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Classifier;
	class Comment;
	class Dependency;
	class Generalization;
	class Namespace;
	class Package;
	class StringExpression;
	class TemplateParameter;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/PackageableElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A GeneralizationSet is a PackageableElement whose instances represent sets of Generalization relationships.
	<p>From package UML::Classification.</p>
	*/
	
	class UML_API GeneralizationSet: virtual public PackageableElement
	{
		public:
 			GeneralizationSet(const GeneralizationSet &) {}

		protected:
			GeneralizationSet(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~GeneralizationSet() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Every Generalization associated with a particular GeneralizationSet must have the same general Classifier.
			generalization->collect(general)->asSet()->size() <= 1
			*/
			 
			virtual bool generalization_same_classifier(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The Classifier that maps to a GeneralizationSet may neither be a specific nor a general Classifier in any of the Generalization relationships defined for that GeneralizationSet. In other words, a power type may not be an instance of itself nor may its instances be its subclasses.
			powertype <> null implies generalization->forAll( gen | 
			    not (gen.general = powertype) and not gen.general.allParents()->includes(powertype) and not (gen.specific = powertype) and not powertype.allParents()->includes(gen.specific)
			  )
			*/
			 
			virtual bool maps_to_generalization_set(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates (via the associated Generalizations) whether or not the set of specific Classifiers are covering for a particular general classifier. When isCovering is true, every instance of a particular general Classifier is also an instance of at least one of its specific Classifiers for the GeneralizationSet. When isCovering is false, there are one or more instances of the particular general Classifier that are not instances of at least one of its specific Classifiers defined for the GeneralizationSet.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsCovering() const = 0;
			/*!
			Indicates (via the associated Generalizations) whether or not the set of specific Classifiers are covering for a particular general classifier. When isCovering is true, every instance of a particular general Classifier is also an instance of at least one of its specific Classifiers for the GeneralizationSet. When isCovering is false, there are one or more instances of the particular general Classifier that are not instances of at least one of its specific Classifiers defined for the GeneralizationSet.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsCovering (bool _isCovering)= 0;
			/*!
			Indicates whether or not the set of specific Classifiers in a Generalization relationship have instance in common. If isDisjoint is true, the specific Classifiers for a particular GeneralizationSet have no members in common; that is, their intersection is empty. If isDisjoint is false, the specific Classifiers in a particular GeneralizationSet have one or more members in common; that is, their intersection is not empty.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsDisjoint() const = 0;
			/*!
			Indicates whether or not the set of specific Classifiers in a Generalization relationship have instance in common. If isDisjoint is true, the specific Classifiers for a particular GeneralizationSet have no members in common; that is, their intersection is empty. If isDisjoint is false, the specific Classifiers in a particular GeneralizationSet have one or more members in common; that is, their intersection is not empty.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsDisjoint (bool _isDisjoint)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Designates the instances of Generalization that are members of this GeneralizationSet.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Generalization>>& getGeneralization() const = 0;
			/*!
			Designates the Classifier that is defined as the power type for the associated GeneralizationSet, if there is one.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<uml::Classifier>& getPowertype() const = 0;
			/*!
			Designates the Classifier that is defined as the power type for the associated GeneralizationSet, if there is one.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setPowertype(const std::shared_ptr<uml::Classifier>&) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;
			

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Indicates (via the associated Generalizations) whether or not the set of specific Classifiers are covering for a particular general classifier. When isCovering is true, every instance of a particular general Classifier is also an instance of at least one of its specific Classifiers for the GeneralizationSet. When isCovering is false, there are one or more instances of the particular general Classifier that are not instances of at least one of its specific Classifiers defined for the GeneralizationSet.
			<p>From package UML::Classification.</p>
			*/
			
			bool m_isCovering= false;
			/*!
			Indicates whether or not the set of specific Classifiers in a Generalization relationship have instance in common. If isDisjoint is true, the specific Classifiers for a particular GeneralizationSet have no members in common; that is, their intersection is empty. If isDisjoint is false, the specific Classifiers in a particular GeneralizationSet have one or more members in common; that is, their intersection is not empty.
			<p>From package UML::Classification.</p>
			*/
			
			bool m_isDisjoint= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			Designates the instances of Generalization that are members of this GeneralizationSet.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Generalization>> m_generalization;
			/*!
			Designates the Classifier that is defined as the power type for the associated GeneralizationSet, if there is one.
			<p>From package UML::Classification.</p>
			*/
			
			std::shared_ptr<uml::Classifier> m_powertype;
	};
}
#endif /* end of include guard: UML_GENERALIZATIONSET_HPP */
