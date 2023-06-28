//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKENDDATA_HPP
#define UML_LINKENDDATA_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


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
#include "uml/Element.hpp"




//*********************************
namespace uml 
{
	/*!
	LinkEndData is an Element that identifies on end of a link to be read or written by a LinkAction. As a link (that is not a link object) cannot be passed as a runtime value to or from an Action, it is instead identified by its end objects and qualifier values, if any. A LinkEndData instance provides these values for a single Association end.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API LinkEndData : virtual public Element
	{
		public:
 			LinkEndData(const LinkEndData &) {}

		protected:
			LinkEndData(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~LinkEndData() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Returns all the InputPins referenced by this LinkEndData. By default this includes the value and qualifier InputPins, but subclasses may override the operation to add other InputPins.
			result = (value->asBag()->union(qualifier.value))
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::InputPin>> allPins() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Association end for which this LinkEndData specifies values.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::Property>& getEnd() const = 0;
			/*!
			The Association end for which this LinkEndData specifies values.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setEnd(const std::shared_ptr<uml::Property>&) = 0;
			/*!
			A set of QualifierValues used to provide values for the qualifiers of the end.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::QualifierValue, uml::Element>>& getQualifier() const = 0;
			/*!
			The InputPin that provides the specified value for the given end. This InputPin is omitted if the LinkEndData specifies the "open" end for a ReadLinkAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getValue() const = 0;
			/*!
			The InputPin that provides the specified value for the given end. This InputPin is omitted if the LinkEndData specifies the "open" end for a ReadLinkAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(const std::shared_ptr<uml::InputPin>&) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The Association end for which this LinkEndData specifies values.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::Property> m_end;
			/*!
			A set of QualifierValues used to provide values for the qualifiers of the end.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::QualifierValue, uml::Element>> m_qualifier;
			/*!
			The InputPin that provides the specified value for the given end. This InputPin is omitted if the LinkEndData specifies the "open" end for a ReadLinkAction.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_value;
	};
}
#endif /* end of include guard: UML_LINKENDDATA_HPP */
