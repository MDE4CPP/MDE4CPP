//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKENDDESTRUCTIONDATA_HPP
#define UML_LINKENDDESTRUCTIONDATA_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations

class Any;

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
	class Comment;
	class InputPin;
	class Property;
	class QualifierValue;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/LinkEndData.hpp"




//*********************************
namespace uml 
{
	/*!
	LinkEndDestructionData is LinkEndData used to provide values for one end of a link to be destroyed by a DestroyLinkAction.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API LinkEndDestructionData : virtual public LinkEndData
	{
		public:
 			LinkEndDestructionData(const LinkEndDestructionData &) {}

		protected:
			LinkEndDestructionData(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~LinkEndDestructionData() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			LinkEndDestructionData for ordered, nonunique Association ends must have a single destroyAt InputPin if isDestroyDuplicates is false, which must be of type UnlimitedNatural and have a multiplicity of 1..1. Otherwise, the action has no destroyAt input pin.
			if  not end.isOrdered or end.isUnique or isDestroyDuplicates
			then destroyAt = null
			else
				destroyAt <> null and 
				destroyAt->forAll(type=UnlimitedNatural and is(1,1))
			endif
			*/
			 
			virtual bool destroyAt_pin(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether to destroy duplicates of the value in nonunique Association ends.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsDestroyDuplicates() const = 0;
			/*!
			Specifies whether to destroy duplicates of the value in nonunique Association ends.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsDestroyDuplicates (bool _isDestroyDuplicates)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The InputPin that provides the position of an existing link to be destroyed in an ordered, nonunique Association end. The type of the destroyAt InputPin is UnlimitedNatural, but the value cannot be zero or unlimited.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getDestroyAt() const = 0;
			/*!
			The InputPin that provides the position of an existing link to be destroyed in an ordered, nonunique Association end. The type of the destroyAt InputPin is UnlimitedNatural, but the value cannot be zero or unlimited.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setDestroyAt(std::shared_ptr<uml::InputPin>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;

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
			Specifies whether to destroy duplicates of the value in nonunique Association ends.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_isDestroyDuplicates= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The InputPin that provides the position of an existing link to be destroyed in an ordered, nonunique Association end. The type of the destroyAt InputPin is UnlimitedNatural, but the value cannot be zero or unlimited.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_destroyAt;
	};
}
#endif /* end of include guard: UML_LINKENDDESTRUCTIONDATA_HPP */
