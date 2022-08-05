//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EANNOTATION_HPP
#define ECORE_EANNOTATION_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
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

namespace ecore
{
	class ecoreFactory;
}

//Forward Declaration for used types 

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/EModelElement.hpp"




//*********************************
namespace ecore 
{
	
	class ECORE_API EAnnotation: virtual public EModelElement
	{
		public:
 			EAnnotation(const EAnnotation &) {}

		protected:
			EAnnotation(){}
			//Additional constructors for the containments back reference
			EAnnotation(std::weak_ptr<ecore::EObject> par_eContainer);

			//Additional constructors for the containments back reference
			EAnnotation(std::weak_ptr<ecore::EModelElement> par_eModelElement);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EAnnotation() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::shared_ptr<std::map < std::string, std::string>> getDetails() const = 0;
			virtual void setDetails (std::shared_ptr<std::map < std::string, std::string>> _details)= 0;
			virtual std::string getSource() const = 0;
			virtual void setSource (std::string _source)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Subset<ecore::EObject, ecore::EObject>> getContents() const = 0;
			virtual std::weak_ptr<ecore::EModelElement> getEModelElement() const = 0;
			virtual void setEModelElement(std::weak_ptr<ecore::EModelElement>) = 0;
			virtual std::shared_ptr<Bag<ecore::EObject>> getReferences() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<ecore::EObject>> getEContentUnion() const = 0;

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			std::shared_ptr<std::map < std::string, std::string>> m_details= nullptr;
			std::string m_source= "";
			
			//*********************************
			// Reference Members
			//*********************************
			mutable std::shared_ptr<Subset<ecore::EObject, ecore::EObject>> m_contents;
			std::weak_ptr<ecore::EModelElement> m_eModelElement;
			mutable std::shared_ptr<Bag<ecore::EObject>> m_references;
	};
}
#endif /* end of include guard: ECORE_EANNOTATION_HPP */