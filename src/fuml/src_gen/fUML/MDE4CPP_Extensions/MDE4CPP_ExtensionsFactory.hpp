//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_MDE4CPP_EXTENSIONSFACTORY_HPP
#define FUML_MDE4CPP_EXTENSIONSFACTORY_HPP
// namespace macro header include
#include "fUML/fUML.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"

namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace uml
{
	class DirectedRelationship;
}



namespace fUML::MDE4CPP_Extensions 
{
	class FUML_API MDE4CPP_ExtensionsFactory : virtual public ecore::EFactory 
	{
		private:    
			MDE4CPP_ExtensionsFactory(MDE4CPP_ExtensionsFactory const&) = delete;
			MDE4CPP_ExtensionsFactory& operator=(MDE4CPP_ExtensionsFactory const&) = delete;
		protected:
			MDE4CPP_ExtensionsFactory(){}
		
			//Singleton Getter
			public:
				static std::shared_ptr<MDE4CPP_ExtensionsFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> createFUML_SignalInstance(const int metaElementID = MDE4CPP_ExtensionsPackage::FUML_SIGNALINSTANCE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> createFUML_SignalInstance_as_source_in_DirectedRelationship(std::shared_ptr<uml::DirectedRelationship> par_DirectedRelationship, const int metaElementID = MDE4CPP_ExtensionsPackage::FUML_SIGNALINSTANCE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> createFUML_SignalInstance_as_target_in_DirectedRelationship(std::shared_ptr<uml::DirectedRelationship> par_DirectedRelationship, const int metaElementID = MDE4CPP_ExtensionsPackage::FUML_SIGNALINSTANCE_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: FUML_MDE4CPP_EXTENSIONSFACTORY_HPP */
