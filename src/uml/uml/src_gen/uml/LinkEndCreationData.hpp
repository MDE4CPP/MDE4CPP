//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKENDCREATIONDATA_HPP
#define UML_LINKENDCREATIONDATA_HPP


#include <memory>
#include <string>
// forward declarations


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
	LinkEndCreationData is LinkEndData used to provide values for one end of a link to be created by a CreateLinkAction.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API LinkEndCreationData : virtual public LinkEndData
	{
		public:
 			LinkEndCreationData(const LinkEndCreationData &) {}

		protected:
			LinkEndCreationData(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~LinkEndCreationData() {}

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
			 
			virtual bool getIsReplaceAll() const = 0;
			/*!
			Specifies whether the existing links emanating from the object on this end should be destroyed before creating a new link.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsReplaceAll (bool _isReplaceAll)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			For ordered Association ends, the InputPin that provides the position where the new link should be inserted or where an existing link should be moved to. The type of the insertAt InputPin is UnlimitedNatural, but the input cannot be zero. It is omitted for Association ends that are not ordered.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getInsertAt() const = 0;
			/*!
			For ordered Association ends, the InputPin that provides the position where the new link should be inserted or where an existing link should be moved to. The type of the insertAt InputPin is UnlimitedNatural, but the input cannot be zero. It is omitted for Association ends that are not ordered.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setInsertAt(const std::shared_ptr<uml::InputPin>&) = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Specifies whether the existing links emanating from the object on this end should be destroyed before creating a new link.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_isReplaceAll= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			For ordered Association ends, the InputPin that provides the position where the new link should be inserted or where an existing link should be moved to. The type of the insertAt InputPin is UnlimitedNatural, but the input cannot be zero. It is omitted for Association ends that are not ordered.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_insertAt;
	};
}
#endif /* end of include guard: UML_LINKENDCREATIONDATA_HPP */
