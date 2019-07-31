//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_LOCI_CS_EXECUTIONFACTORY_HPP
#define PSCS_SEMANTICS_LOCI_CS_EXECUTIONFACTORY_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag;



//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Class;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class Package;
}

// base class includes

// enum includes

#include "ecore/EObject.hpp"

//*********************************
namespace PSCS::Semantics::Loci 
{
	/*!
	 */
	class CS_ExecutionFactory : virtual public ecore::EObject 

	{
		public:
 			CS_ExecutionFactory(const CS_ExecutionFactory &) {}
			CS_ExecutionFactory& operator=(CS_ExecutionFactory const&) = delete;

		protected:
			CS_ExecutionFactory(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_ExecutionFactory() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual Any getStereotypeApplication(std::shared_ptr<uml::Class>  stereotype,std::shared_ptr<uml::Element>  element) = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<uml::Class> getStereotypeClass(std::string profileName,std::string stereotypeName) = 0;
			
			/*!
			 */ 
			virtual Any instantiateVisitor(std::shared_ptr<uml::Element>  element) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<Bag<uml::Package>> getAppliedProfiles() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<Bag<uml::Package>> m_appliedProfiles;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: PSCS_SEMANTICS_LOCI_CS_EXECUTIONFACTORY_HPP */
